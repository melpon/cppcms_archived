
#ifndef CPPCMS_BOOST_MPL_LIST_LIST20_C_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_LIST_LIST20_C_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: list20_c.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/list/list10_c.hpp>
#endif

#include <cppcms_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
 && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)

#   define CPPCMS_BOOST_MPL_PREPROCESSED_HEADER list20_c.hpp
#   include <cppcms_boost/mpl/list/aux_/include_preprocessed.hpp>

#else

#   include <cppcms_boost/preprocessor/iterate.hpp>

namespace cppcms_boost { namespace mpl {

#   define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(11, 20, <cppcms_boost/mpl/list/aux_/numbered_c.hpp>))
#   include CPPCMS_BOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#endif // BOOST_MPL_LIST_LIST20_C_HPP_INCLUDED
