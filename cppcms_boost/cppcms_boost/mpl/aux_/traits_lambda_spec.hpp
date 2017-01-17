
#ifndef CPPCMS_BOOST_MPL_AUX_TRAITS_LAMBDA_SPEC_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_TRAITS_LAMBDA_SPEC_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: traits_lambda_spec.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/sequence_tag_fwd.hpp>
#include <cppcms_boost/mpl/void.hpp>
#include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#include <cppcms_boost/mpl/aux_/config/lambda.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)

#   define CPPCMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC_IMPL(i, trait) /**/

#elif !defined(CPPCMS_BOOST_MPL_CFG_MSVC_ETI_BUG)

#   define CPPCMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC_IMPL(i, trait) \
template<> struct trait<void_> \
{ \
    template< CPPCMS_BOOST_MPL_PP_PARAMS(i, typename T) > struct apply \
    { \
    }; \
}; \
/**/

#else

#   define CPPCMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC_IMPL(i, trait) \
template<> struct trait<void_> \
{ \
    template< CPPCMS_BOOST_MPL_PP_PARAMS(i, typename T) > struct apply \
    { \
    }; \
}; \
template<> struct trait<int> \
{ \
    template< CPPCMS_BOOST_MPL_PP_PARAMS(i, typename T) > struct apply \
    { \
        typedef int type; \
    }; \
}; \
/**/

#endif // BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT


#define CPPCMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(i, trait) \
    CPPCMS_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC_IMPL(i, trait) \
    template<> struct trait<non_sequence_tag> {}; \
/**/

#endif // BOOST_MPL_AUX_TRAITS_LAMBDA_SPEC_HPP_INCLUDED
