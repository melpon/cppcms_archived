
#if !defined(CPPCMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef CPPCMS_BOOST_MPL_QUOTE_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_QUOTE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: quote.hpp 49272 2008-10-11 06:50:46Z agurtovoy $
// $Date: 2008-10-11 02:50:46 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49272 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/void.hpp>
#   include <cppcms_boost/mpl/aux_/has_type.hpp>
#endif

#include <cppcms_boost/mpl/aux_/config/bcc.hpp>
#include <cppcms_boost/mpl/aux_/config/ttp.hpp>

#if defined(CPPCMS_BOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS) \
    && !defined(CPPCMS_BOOST_MPL_CFG_BCC590_WORKAROUNDS)
#   define CPPCMS_BOOST_MPL_CFG_NO_QUOTE_TEMPLATE
#endif

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS) \
    && defined(CPPCMS_BOOST_MPL_CFG_NO_HAS_XXX)
#   define CPPCMS_BOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS
#endif

#include <cppcms_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
 && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)

#   define CPPCMS_BOOST_MPL_PREPROCESSED_HEADER quote.hpp
#   include <cppcms_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <cppcms_boost/mpl/limits/arity.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#   include <cppcms_boost/mpl/aux_/config/ctps.hpp>
#   include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#   include <cppcms_boost/preprocessor/iterate.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_QUOTE_TEMPLATE)

namespace cppcms_boost { namespace mpl {

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename T, bool has_type_ >
struct quote_impl
// GCC has a problem with metafunction forwarding when T is a
// specialization of a template called 'type'.
# if CPPCMS_BOOST_WORKAROUND(__GNUC__, CPPCMS_BOOST_TESTED_AT(4)) \
    && CPPCMS_BOOST_WORKAROUND(__GNUC_MINOR__, CPPCMS_BOOST_TESTED_AT(0)) \
    && CPPCMS_BOOST_WORKAROUND(__GNUC_PATCHLEVEL__, CPPCMS_BOOST_TESTED_AT(2))
{
    typedef typename T::type type;
};
# else 
    : T
{
};
# endif 

template< typename T >
struct quote_impl<T,false>
{
    typedef T type;
};

#else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template< bool > struct quote_impl
{
    template< typename T > struct result_
        : T
    {
    };
};

template<> struct quote_impl<false>
{
    template< typename T > struct result_
    {
        typedef T type;
    };
};

#endif 

#define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(1, CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, <cppcms_boost/mpl/quote.hpp>))
#include CPPCMS_BOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_NO_QUOTE_TEMPLATE

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_QUOTE_HPP_INCLUDED

///// iteration

#else
#define i_ CPPCMS_BOOST_PP_FRAME_ITERATION(1)

template<
      template< CPPCMS_BOOST_MPL_PP_PARAMS(i_, typename P) > class F
    , typename Tag = void_
    >
struct CPPCMS_BOOST_PP_CAT(quote,i_)
{
    template< CPPCMS_BOOST_MPL_PP_PARAMS(i_, typename U) > struct apply
#if defined(CPPCMS_BOOST_MPL_CFG_BCC590_WORKAROUNDS)
    {
        typedef typename quote_impl<
              F< CPPCMS_BOOST_MPL_PP_PARAMS(i_, U) >
            , aux::has_type< F< CPPCMS_BOOST_MPL_PP_PARAMS(i_, U) > >::value
            >::type type;
    };
#elif !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
        : quote_impl<
              F< CPPCMS_BOOST_MPL_PP_PARAMS(i_, U) >
            , aux::has_type< F< CPPCMS_BOOST_MPL_PP_PARAMS(i_, U) > >::value
            >
    {
    };
#else
        : quote_impl< aux::has_type< F< CPPCMS_BOOST_MPL_PP_PARAMS(i_, U) > >::value >
            ::template result_< F< CPPCMS_BOOST_MPL_PP_PARAMS(i_, U) > >
    {
    };
#endif
};

#undef i_
#endif // BOOST_PP_IS_ITERATING
