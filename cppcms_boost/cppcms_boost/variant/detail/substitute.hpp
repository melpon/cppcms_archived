
#if !defined(CPPCMS_BOOST_PP_IS_ITERATING)

///// header body

//-----------------------------------------------------------------------------
// boost variant/detail/substitute.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_VARIANT_DETAIL_SUBSTITUTE_HPP
#define CPPCMS_BOOST_VARIANT_DETAIL_SUBSTITUTE_HPP

#include "cppcms_boost/mpl/aux_/config/ctps.hpp"

#include "cppcms_boost/variant/detail/substitute_fwd.hpp"
#include "cppcms_boost/mpl/aux_/lambda_arity_param.hpp"
#include "cppcms_boost/mpl/aux_/preprocessor/params.hpp"
#include "cppcms_boost/mpl/aux_/preprocessor/repeat.hpp"
#include "cppcms_boost/mpl/int_fwd.hpp"
#include "cppcms_boost/mpl/limits/arity.hpp"
#include "cppcms_boost/preprocessor/cat.hpp"
#include "cppcms_boost/preprocessor/empty.hpp"
#include "cppcms_boost/preprocessor/arithmetic/inc.hpp"
#include "cppcms_boost/preprocessor/iterate.hpp"

namespace cppcms_boost {
namespace detail { namespace variant {

#if !defined(CPPCMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction substitute
//
// Substitutes one type for another in the given type expression.
//

//
// primary template
//
template <
      typename T, typename Dest, typename Source
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(
          typename Arity /* = ... (see substitute_fwd.hpp) */
        )
    >
struct substitute
{
    typedef T type;
};

//
// tag substitution specializations
//

#define CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(CV_) \
    template <typename Dest, typename Source> \
    struct substitute< \
          CV_ Source \
        , Dest \
        , Source \
          CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>) \
        > \
    { \
        typedef CV_ Dest type; \
    }; \
    /**/

CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG( CPPCMS_BOOST_PP_EMPTY() )
CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(const)
CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(volatile)
CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(const volatile)

#undef CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG

//
// pointer specializations
//
#define CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(CV_) \
    template <typename T, typename Dest, typename Source> \
    struct substitute< \
          T * CV_ \
        , Dest \
        , Source \
          CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>) \
        > \
    { \
        typedef typename substitute< \
              T, Dest, Source \
            >::type * CV_ type; \
    }; \
    /**/

CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER( CPPCMS_BOOST_PP_EMPTY() )
CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(const)
CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(volatile)
CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(const volatile)

#undef CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER

//
// reference specializations
//
template <typename T, typename Dest, typename Source>
struct substitute<
      T&
    , Dest
    , Source
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
    typedef typename substitute<
          T, Dest, Source
        >::type & type;
};

//
// template expression (i.e., F<...>) specializations
//

#define CPPCMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL(N) \
    typedef typename substitute< \
          CPPCMS_BOOST_PP_CAT(U,N), Dest, Source \
        >::type CPPCMS_BOOST_PP_CAT(u,N); \
    /**/

#define CPPCMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF(z, N, _) \
    CPPCMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL( CPPCMS_BOOST_PP_INC(N) ) \
    /**/

#define CPPCMS_BOOST_PP_ITERATION_LIMITS (0,CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY)
#define CPPCMS_BOOST_PP_FILENAME_1 "cppcms_boost/variant/detail/substitute.hpp"
#include CPPCMS_BOOST_PP_ITERATE()

#undef CPPCMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL
#undef CPPCMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF

#endif // !defined(BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

}} // namespace detail::variant
} // namespace boost

#endif // BOOST_VARIANT_DETAIL_SUBSTITUTE_HPP

///// iteration, depth == 1

#elif CPPCMS_BOOST_PP_ITERATION_DEPTH() == 1
#define i CPPCMS_BOOST_PP_FRAME_ITERATION(1)

#if i > 0

//
// template specializations
//
template <
      template < CPPCMS_BOOST_MPL_PP_PARAMS(i,typename P) > class T
    , CPPCMS_BOOST_MPL_PP_PARAMS(i,typename U)
    , typename Dest
    , typename Source
    >
struct substitute<
      T< CPPCMS_BOOST_MPL_PP_PARAMS(i,U) >
    , Dest
    , Source
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<( i )>)
    >
{
private:
    CPPCMS_BOOST_MPL_PP_REPEAT(i, CPPCMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF, _)

public:
    typedef T< CPPCMS_BOOST_MPL_PP_PARAMS(i,u) > type;
};

//
// function specializations
//
template <
      typename R
    , CPPCMS_BOOST_MPL_PP_PARAMS(i,typename U)
    , typename Dest
    , typename Source
    >
struct substitute<
      R (*)( CPPCMS_BOOST_MPL_PP_PARAMS(i,U) )
    , Dest
    , Source
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
private:
    typedef typename substitute< R, Dest, Source >::type r;
    CPPCMS_BOOST_MPL_PP_REPEAT(i, CPPCMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF, _)

public:
    typedef r (*type)( CPPCMS_BOOST_MPL_PP_PARAMS(i,u) );
};

#elif i == 0

//
// zero-arg function specialization
//
template <
      typename R, typename Dest, typename Source
    >
struct substitute<
      R (*)( void )
    , Dest
    , Source
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
private:
    typedef typename substitute< R, Dest, Source >::type r;

public:
    typedef r (*type)( void );
};

#endif // i

#undef i
#endif // BOOST_PP_IS_ITERATING
