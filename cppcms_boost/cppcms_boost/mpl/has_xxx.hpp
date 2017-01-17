
#ifndef CPPCMS_BOOST_MPL_HAS_XXX_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_HAS_XXX_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2006
// Copyright David Abrahams 2002-2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: has_xxx.hpp 49273 2008-10-11 06:54:06Z agurtovoy $
// $Date: 2008-10-11 02:54:06 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49273 $

#include <cppcms_boost/mpl/bool.hpp>
#include <cppcms_boost/mpl/aux_/type_wrapper.hpp>
#include <cppcms_boost/mpl/aux_/yes_no.hpp>
#include <cppcms_boost/mpl/aux_/config/has_xxx.hpp>
#include <cppcms_boost/mpl/aux_/config/msvc_typename.hpp>
#include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#include <cppcms_boost/mpl/aux_/config/static_constant.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#include <cppcms_boost/preprocessor/cat.hpp>

#if CPPCMS_BOOST_WORKAROUND( __BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x590) )
# include <cppcms_boost/type_traits/is_class.hpp>
#endif

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_HAS_XXX)

#   if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300)

// agurt, 11/sep/02: MSVC-specific version (< 7.1), based on a USENET 
// newsgroup's posting by John Madsen (comp.lang.c++.moderated, 
// 1999-11-12 19:17:06 GMT); the code is _not_ standard-conforming, but 
// it works way more reliably than the SFINAE-based implementation

// Modified dwa 8/Oct/02 to handle reference types.

#   include <cppcms_boost/mpl/if.hpp>
#   include <cppcms_boost/mpl/bool.hpp>

namespace cppcms_boost { namespace mpl { namespace aux {

struct has_xxx_tag;

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1300)
template< typename U > struct msvc_incomplete_array
{
    typedef char (&type)[sizeof(U) + 1];
};
#endif

template< typename T >
struct msvc_is_incomplete
{
    // MSVC is capable of some kinds of SFINAE.  If U is an incomplete
    // type, it won't pick the second overload
    static char tester(...);

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1300)
    template< typename U >
    static typename msvc_incomplete_array<U>::type tester(type_wrapper<U>);
#else
    template< typename U >
    static char (& tester(type_wrapper<U>) )[sizeof(U)+1];
#endif 
    
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = 
          sizeof(tester(type_wrapper<T>())) == 1
        );
};

template<>
struct msvc_is_incomplete<int>
{
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

}}}

#   define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, default_) \
template< typename T, typename name = ::cppcms_boost::mpl::aux::has_xxx_tag > \
struct CPPCMS_BOOST_PP_CAT(trait,_impl) : T \
{ \
    static cppcms_boost::mpl::aux::no_tag \
    test(void(*)(::cppcms_boost::mpl::aux::has_xxx_tag)); \
    \
    static cppcms_boost::mpl::aux::yes_tag test(...); \
    \
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = \
          sizeof(test(static_cast<void(*)(name)>(0))) \
            != sizeof(cppcms_boost::mpl::aux::no_tag) \
        ); \
    typedef cppcms_boost::mpl::bool_<value> type; \
}; \
\
template< typename T, typename fallback_ = cppcms_boost::mpl::bool_<default_> > \
struct trait \
    : cppcms_boost::mpl::if_c< \
          cppcms_boost::mpl::aux::msvc_is_incomplete<T>::value \
        , cppcms_boost::mpl::bool_<false> \
        , CPPCMS_BOOST_PP_CAT(trait,_impl)<T> \
        >::type \
{ \
}; \
\
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, void) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, bool) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, char) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed char) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned char) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed short) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned short) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed int) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned int) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed long) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned long) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, float) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, double) \
CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, long double) \
/**/

#   define CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, T) \
template<> struct trait<T> \
{ \
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false); \
    typedef cppcms_boost::mpl::bool_<false> type; \
}; \
/**/

#if !defined(CPPCMS_BOOST_NO_INTRINSIC_WCHAR_T)
#   define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, unused) \
    CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, unused) \
    CPPCMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, wchar_t) \
/**/
#else
#   define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, unused) \
    CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, unused) \
/**/
#endif


// SFINAE-based implementations below are derived from a USENET newsgroup's 
// posting by Rani Sharoni (comp.lang.c++.moderated, 2002-03-17 07:45:09 PST)

#   elif CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, CPPCMS_BOOST_TESTED_AT(1400)) \
      || CPPCMS_BOOST_WORKAROUND(__IBMCPP__, <= 700)

// MSVC 7.1+ & VACPP

// agurt, 15/jun/05: replace overload-based SFINAE implementation with SFINAE
// applied to partial specialization to fix some apparently random failures 
// (thanks to Daniel Wallin for researching this!)

#   define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T > \
struct CPPCMS_BOOST_PP_CAT(trait, _msvc_sfinae_helper) \
{ \
    typedef void type; \
};\
\
template< typename T, typename U = void > \
struct CPPCMS_BOOST_PP_CAT(trait,_impl_) \
{ \
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false); \
    typedef cppcms_boost::mpl::bool_<value> type; \
}; \
\
template< typename T > \
struct CPPCMS_BOOST_PP_CAT(trait,_impl_)< \
      T \
    , typename CPPCMS_BOOST_PP_CAT(trait, _msvc_sfinae_helper)< typename T::name >::type \
    > \
{ \
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = true); \
    typedef cppcms_boost::mpl::bool_<value> type; \
}; \
\
template< typename T, typename fallback_ = cppcms_boost::mpl::bool_<default_> > \
struct trait \
    : CPPCMS_BOOST_PP_CAT(trait,_impl_)<T> \
{ \
}; \
/**/

#   elif CPPCMS_BOOST_WORKAROUND( __BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x590) )

#   define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_BCB_DEF(trait, trait_tester, name, default_) \
template< typename T, bool IS_CLASS > \
struct trait_tester \
{ \
    CPPCMS_BOOST_STATIC_CONSTANT( bool,  value = false ); \
}; \
template< typename T > \
struct trait_tester< T, true > \
{ \
    struct trait_tester_impl \
    { \
        template < class U > \
        static int  resolve( cppcms_boost::mpl::aux::type_wrapper<U> const volatile * \
                           , cppcms_boost::mpl::aux::type_wrapper<typename U::name >* = 0 ); \
        static char resolve( ... ); \
    }; \
    typedef cppcms_boost::mpl::aux::type_wrapper<T> t_; \
    CPPCMS_BOOST_STATIC_CONSTANT( bool, value = ( sizeof( trait_tester_impl::resolve( static_cast< t_ * >(0) ) ) == sizeof(int) ) ); \
}; \
template< typename T, typename fallback_ = cppcms_boost::mpl::bool_<default_> > \
struct trait           \
{                      \
    CPPCMS_BOOST_STATIC_CONSTANT( bool, value = (trait_tester< T, cppcms_boost::is_class< T >::value >::value) );     \
    typedef cppcms_boost::mpl::bool_< trait< T, fallback_ >::value > type; \
};

#   define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
    CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_BCB_DEF( trait \
                                         , CPPCMS_BOOST_PP_CAT(trait,_tester)      \
                                         , name       \
                                         , default_ ) \
/**/

#   else // other SFINAE-capable compilers

#   define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T, typename fallback_ = cppcms_boost::mpl::bool_<default_> > \
struct trait \
{ \
    struct gcc_3_2_wknd \
    { \
        template< typename U > \
        static cppcms_boost::mpl::aux::yes_tag test( \
              cppcms_boost::mpl::aux::type_wrapper<U> const volatile* \
            , cppcms_boost::mpl::aux::type_wrapper<CPPCMS_BOOST_MSVC_TYPENAME U::name>* = 0 \
            ); \
    \
        static cppcms_boost::mpl::aux::no_tag test(...); \
    }; \
    \
    typedef cppcms_boost::mpl::aux::type_wrapper<T> t_; \
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = \
          sizeof(gcc_3_2_wknd::test(static_cast<t_*>(0))) \
            == sizeof(cppcms_boost::mpl::aux::yes_tag) \
        ); \
    typedef cppcms_boost::mpl::bool_<value> type; \
}; \
/**/

#   endif // BOOST_WORKAROUND(BOOST_MSVC, <= 1300)


#else // BOOST_MPL_CFG_NO_HAS_XXX

// placeholder implementation

#   define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T, typename fallback_ = cppcms_boost::mpl::bool_<default_> > \
struct trait \
{ \
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = fallback_::value); \
    typedef fallback_ type; \
}; \
/**/

#endif

#define CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_DEF(name) \
    CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(CPPCMS_BOOST_PP_CAT(has_,name), name, false) \
/**/

#endif // BOOST_MPL_HAS_XXX_HPP_INCLUDED
