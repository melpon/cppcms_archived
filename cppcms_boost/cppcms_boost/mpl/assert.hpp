
#ifndef CPPCMS_BOOST_MPL_ASSERT_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_ASSERT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: assert.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/not.hpp>
#include <cppcms_boost/mpl/aux_/value_wknd.hpp>
#include <cppcms_boost/mpl/aux_/nested_type_wknd.hpp>
#include <cppcms_boost/mpl/aux_/yes_no.hpp>
#include <cppcms_boost/mpl/aux_/na.hpp>
#include <cppcms_boost/mpl/aux_/adl_barrier.hpp>

#include <cppcms_boost/mpl/aux_/config/nttp.hpp>
#include <cppcms_boost/mpl/aux_/config/dtp.hpp>
#include <cppcms_boost/mpl/aux_/config/gcc.hpp>
#include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#include <cppcms_boost/mpl/aux_/config/static_constant.hpp>
#include <cppcms_boost/mpl/aux_/config/pp_counter.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#include <cppcms_boost/preprocessor/cat.hpp>

#include <cppcms_boost/config.hpp> // make sure 'size_t' is placed into 'std'
#include <cstddef>


#if CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610)) \
    || (CPPCMS_BOOST_MPL_CFG_GCC != 0) \
    || CPPCMS_BOOST_WORKAROUND(__IBMCPP__, <= 600)
#   define CPPCMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES
#endif

#if CPPCMS_BOOST_WORKAROUND(__MWERKS__, < 0x3202) \
    || CPPCMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 238) \
    || CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610)) \
    || CPPCMS_BOOST_WORKAROUND(__DMC__, CPPCMS_BOOST_TESTED_AT(0x840))
#   define CPPCMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER
#endif

// agurt, 10/nov/06: use enums for Borland (which cannot cope with static constants) 
// and GCC (which issues "unused variable" warnings when static constants are used 
// at a function scope)
#if CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610)) \
    || (CPPCMS_BOOST_MPL_CFG_GCC != 0)
#   define CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT(T, expr) enum { expr }
#else
#   define CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT(T, expr) CPPCMS_BOOST_STATIC_CONSTANT(T, expr)
#endif


CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

struct failed {};

// agurt, 24/aug/04: MSVC 7.1 workaround here and below: return/accept 
// 'assert<false>' by reference; can't apply it unconditionally -- apparently it
// degrades the quality of GCC diagnostics
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1310)
#   define AUX778076_ASSERT_ARG(x) x&
#else
#   define AUX778076_ASSERT_ARG(x) x
#endif

template< bool C >  struct assert        { typedef void* type; };
template<>          struct assert<false> { typedef AUX778076_ASSERT_ARG(assert) type; };

template< bool C >
int assertion_failed( typename assert<C>::type );

template< bool C >
struct assertion
{
    static int failed( assert<false> );
};

template<>
struct assertion<true>
{
    static int failed( void* );
};

struct assert_
{
#if !defined(CPPCMS_BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
    template< typename T1, typename T2 = na, typename T3 = na, typename T4 = na > struct types {};
#endif
    static assert_ const arg;
    enum relations { equal = 1, not_equal, greater, greater_equal, less, less_equal };
};


#if !defined(CPPCMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)

bool operator==( failed, failed );
bool operator!=( failed, failed );
bool operator>( failed, failed );
bool operator>=( failed, failed );
bool operator<( failed, failed );
bool operator<=( failed, failed );

#if defined(__EDG_VERSION__)
template< bool (*)(failed, failed), long x, long y > struct assert_relation {};
#   define CPPCMS_BOOST_MPL_AUX_ASSERT_RELATION(x, y, r) assert_relation<r,x,y>
#else
template< CPPCMS_BOOST_MPL_AUX_NTTP_DECL(long, x), CPPCMS_BOOST_MPL_AUX_NTTP_DECL(long, y), bool (*)(failed, failed) > 
struct assert_relation {};
#   define CPPCMS_BOOST_MPL_AUX_ASSERT_RELATION(x, y, r) assert_relation<x,y,r>
#endif

#else // BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES

cppcms_boost::mpl::aux::weighted_tag<1>::type operator==( assert_, assert_ );
cppcms_boost::mpl::aux::weighted_tag<2>::type operator!=( assert_, assert_ );
cppcms_boost::mpl::aux::weighted_tag<3>::type operator>(  assert_, assert_ );
cppcms_boost::mpl::aux::weighted_tag<4>::type operator>=( assert_, assert_ );
cppcms_boost::mpl::aux::weighted_tag<5>::type operator<( assert_, assert_ );
cppcms_boost::mpl::aux::weighted_tag<6>::type operator<=( assert_, assert_ );

template< assert_::relations r, long x, long y > struct assert_relation {};

#endif 


#if !defined(CPPCMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)

template< bool > struct assert_arg_pred_impl { typedef int type; };
template<> struct assert_arg_pred_impl<true> { typedef void* type; };

template< typename P > struct assert_arg_pred
{
    typedef typename P::type p_type;
    typedef typename assert_arg_pred_impl< p_type::value >::type type;
};

template< typename P > struct assert_arg_pred_not
{
    typedef typename P::type p_type;
    CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( bool, p = !p_type::value );
    typedef typename assert_arg_pred_impl<p>::type type;
};

template< typename Pred >
failed ************ (Pred::************ 
      assert_arg( void (*)(Pred), typename assert_arg_pred<Pred>::type )
    );

template< typename Pred >
failed ************ (cppcms_boost::mpl::not_<Pred>::************ 
      assert_not_arg( void (*)(Pred), typename assert_arg_pred_not<Pred>::type )
    );

template< typename Pred >
AUX778076_ASSERT_ARG(assert<false>)
assert_arg( void (*)(Pred), typename assert_arg_pred_not<Pred>::type );

template< typename Pred >
AUX778076_ASSERT_ARG(assert<false>)
assert_not_arg( void (*)(Pred), typename assert_arg_pred<Pred>::type );


#else // BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER
        
template< bool c, typename Pred > struct assert_arg_type_impl
{
    typedef failed      ************ Pred::* mwcw83_wknd;
    typedef mwcw83_wknd ************* type;
};

template< typename Pred > struct assert_arg_type_impl<true,Pred>
{
    typedef AUX778076_ASSERT_ARG(assert<false>) type;
};

template< typename Pred > struct assert_arg_type
    : assert_arg_type_impl< CPPCMS_BOOST_MPL_AUX_VALUE_WKND(CPPCMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(Pred))::value, Pred >
{
};

template< typename Pred >
typename assert_arg_type<Pred>::type 
assert_arg(void (*)(Pred), int);

template< typename Pred >
typename assert_arg_type< cppcms_boost::mpl::not_<Pred> >::type 
assert_not_arg(void (*)(Pred), int);

#   if !defined(CPPCMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)
template< long x, long y, bool (*r)(failed, failed) >
typename assert_arg_type_impl< false,CPPCMS_BOOST_MPL_AUX_ASSERT_RELATION(x,y,r) >::type
assert_rel_arg( CPPCMS_BOOST_MPL_AUX_ASSERT_RELATION(x,y,r) );
#   else
template< assert_::relations r, long x, long y >
typename assert_arg_type_impl< false,assert_relation<r,x,y> >::type
assert_rel_arg( assert_relation<r,x,y> );
#   endif

#endif // BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER

#undef AUX778076_ASSERT_ARG

CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE


// BOOST_MPL_ASSERT((pred<x,...>))

#define CPPCMS_BOOST_MPL_ASSERT(pred) \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,CPPCMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          cppcms_boost::mpl::assertion_failed<false>( \
              cppcms_boost::mpl::assert_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
    ) \
/**/

// BOOST_MPL_ASSERT_NOT((pred<x,...>))

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300)
#   define CPPCMS_BOOST_MPL_ASSERT_NOT(pred) \
enum { \
      CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,CPPCMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          cppcms_boost::mpl::assertion<false>::failed( \
              cppcms_boost::mpl::assert_not_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
}\
/**/
#else
#   define CPPCMS_BOOST_MPL_ASSERT_NOT(pred) \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,CPPCMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          cppcms_boost::mpl::assertion_failed<false>( \
              cppcms_boost::mpl::assert_not_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
   ) \
/**/
#endif

// BOOST_MPL_ASSERT_RELATION(x, ==|!=|<=|<|>=|>, y)

#if defined(CPPCMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)

#   if !defined(CPPCMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)
// agurt, 9/nov/06: 'enum' below is a workaround for gcc 4.0.4/4.1.1 bugs #29522 and #29518
#   define CPPCMS_BOOST_MPL_ASSERT_RELATION_IMPL(counter, x, rel, y)      \
enum { CPPCMS_BOOST_PP_CAT(mpl_assert_rel_value,counter) = (x rel y) }; \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        cppcms_boost::mpl::assertion_failed<CPPCMS_BOOST_PP_CAT(mpl_assert_rel_value,counter)>( \
            (cppcms_boost::mpl::failed ************ ( cppcms_boost::mpl::assert_relation< \
                  cppcms_boost::mpl::assert_::relations( sizeof( \
                      cppcms_boost::mpl::assert_::arg rel cppcms_boost::mpl::assert_::arg \
                    ) ) \
                , x \
                , y \
                >::************)) 0 ) \
        ) \
    ) \
/**/
#   else
#   define CPPCMS_BOOST_MPL_ASSERT_RELATION_IMPL(counter, x, rel, y)    \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assert_rel,counter) = sizeof( \
          cppcms_boost::mpl::assert_::arg rel cppcms_boost::mpl::assert_::arg \
        ) \
    ); \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( bool, CPPCMS_BOOST_PP_CAT(mpl_assert_rel_value,counter) = (x rel y) ); \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        cppcms_boost::mpl::assertion_failed<CPPCMS_BOOST_PP_CAT(mpl_assert_rel_value,counter)>( \
              cppcms_boost::mpl::assert_rel_arg( cppcms_boost::mpl::assert_relation< \
                  cppcms_boost::mpl::assert_::relations(CPPCMS_BOOST_PP_CAT(mpl_assert_rel,counter)) \
                , x \
                , y \
                >() ) \
            ) \
        ) \
    ) \
/**/
#   endif

#   define CPPCMS_BOOST_MPL_ASSERT_RELATION(x, rel, y) \
CPPCMS_BOOST_MPL_ASSERT_RELATION_IMPL(CPPCMS_BOOST_MPL_AUX_PP_COUNTER(), x, rel, y) \
/**/

#else // !BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES

#   if defined(CPPCMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)
#   define CPPCMS_BOOST_MPL_ASSERT_RELATION(x, rel, y) \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,CPPCMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
        cppcms_boost::mpl::assertion_failed<(x rel y)>( cppcms_boost::mpl::assert_rel_arg( \
              cppcms_boost::mpl::CPPCMS_BOOST_MPL_AUX_ASSERT_RELATION(x,y,(&cppcms_boost::mpl::operator rel))() \
            ) ) \
        ) \
    ) \
/**/
#   else
#   define CPPCMS_BOOST_MPL_ASSERT_RELATION(x, rel, y) \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,CPPCMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
        cppcms_boost::mpl::assertion_failed<(x rel y)>( (cppcms_boost::mpl::failed ************ ( \
            cppcms_boost::mpl::CPPCMS_BOOST_MPL_AUX_ASSERT_RELATION(x,y,(&cppcms_boost::mpl::operator rel))::************))0 ) \
        ) \
    ) \
/**/
#   endif

#endif


// BOOST_MPL_ASSERT_MSG( (pred<x,...>::value), USER_PROVIDED_MESSAGE, (types<x,...>) ) 

#if CPPCMS_BOOST_WORKAROUND(__MWERKS__, CPPCMS_BOOST_TESTED_AT(0x3202))
#   define CPPCMS_BOOST_MPL_ASSERT_MSG_IMPL( counter, c, msg, types_ ) \
struct msg; \
typedef struct CPPCMS_BOOST_PP_CAT(msg,counter) : cppcms_boost::mpl::assert_ \
{ \
    using cppcms_boost::mpl::assert_::types; \
    static cppcms_boost::mpl::failed ************ (msg::************ assert_arg()) types_ \
    { return 0; } \
} CPPCMS_BOOST_PP_CAT(mpl_assert_arg,counter); \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        cppcms_boost::mpl::assertion<(c)>::failed( CPPCMS_BOOST_PP_CAT(mpl_assert_arg,counter)::assert_arg() ) \
        ) \
    ) \
/**/
#else
#   define CPPCMS_BOOST_MPL_ASSERT_MSG_IMPL( counter, c, msg, types_ )  \
struct msg; \
typedef struct CPPCMS_BOOST_PP_CAT(msg,counter) : cppcms_boost::mpl::assert_ \
{ \
    static cppcms_boost::mpl::failed ************ (msg::************ assert_arg()) types_ \
    { return 0; } \
} CPPCMS_BOOST_PP_CAT(mpl_assert_arg,counter); \
CPPCMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , CPPCMS_BOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        cppcms_boost::mpl::assertion_failed<(c)>( CPPCMS_BOOST_PP_CAT(mpl_assert_arg,counter)::assert_arg() ) \
        ) \
    ) \
/**/
#endif

#define CPPCMS_BOOST_MPL_ASSERT_MSG( c, msg, types_ ) \
CPPCMS_BOOST_MPL_ASSERT_MSG_IMPL( CPPCMS_BOOST_MPL_AUX_PP_COUNTER(), c, msg, types_ ) \
/**/

#endif // BOOST_MPL_ASSERT_HPP_INCLUDED
