
#ifndef CPPCMS_BOOST_MPL_AUX_PREPROCESSOR_PARTIAL_SPEC_PARAMS_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_PREPROCESSOR_PARTIAL_SPEC_PARAMS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: partial_spec_params.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/limits/arity.hpp>
#include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#include <cppcms_boost/mpl/aux_/preprocessor/enum.hpp>
#include <cppcms_boost/mpl/aux_/preprocessor/sub.hpp>
#include <cppcms_boost/preprocessor/comma_if.hpp>

#define CPPCMS_BOOST_MPL_PP_PARTIAL_SPEC_PARAMS(n, param, def) \
CPPCMS_BOOST_MPL_PP_PARAMS(n, param) \
CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_MPL_PP_SUB(CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY,n)) \
CPPCMS_BOOST_MPL_PP_ENUM( \
      CPPCMS_BOOST_MPL_PP_SUB(CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY,n) \
    , def \
    ) \
/**/

#endif // BOOST_MPL_AUX_PREPROCESSOR_PARTIAL_SPEC_PARAMS_HPP_INCLUDED
