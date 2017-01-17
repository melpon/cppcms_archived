
#ifndef CPPCMS_BOOST_MPL_AUX_LAMBDA_SPEC_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_LAMBDA_SPEC_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2007
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: lambda_spec.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/void.hpp>
#include <cppcms_boost/mpl/lambda_fwd.hpp>
#include <cppcms_boost/mpl/int_fwd.hpp>
#include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#include <cppcms_boost/mpl/aux_/lambda_arity_param.hpp>
#include <cppcms_boost/mpl/aux_/config/lambda.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)

#   define CPPCMS_BOOST_MPL_AUX_PASS_THROUGH_LAMBDA_SPEC(i, name) \
template< \
      CPPCMS_BOOST_MPL_PP_PARAMS(i, typename T) \
    , typename Tag \
    > \
struct lambda< \
      name< CPPCMS_BOOST_MPL_PP_PARAMS(i, T) > \
    , Tag \
    CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(int_<i>) \
    > \
{ \
    typedef false_ is_le; \
    typedef name< CPPCMS_BOOST_MPL_PP_PARAMS(i, T) > result_; \
    typedef result_ type; \
}; \
/**/

#else

#   define CPPCMS_BOOST_MPL_AUX_PASS_THROUGH_LAMBDA_SPEC(i, name) /**/

#endif

#endif // BOOST_MPL_AUX_LAMBDA_SPEC_HPP_INCLUDED
