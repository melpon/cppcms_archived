
#ifndef CPPCMS_BOOST_MPL_AUX_CONFIG_INTEGRAL_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_CONFIG_INTEGRAL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: integral.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#if    !defined(CPPCMS_BOOST_MPL_CFG_BCC_INTEGRAL_CONSTANTS) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE) \
    && CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610))

#   define CPPCMS_BOOST_MPL_CFG_BCC_INTEGRAL_CONSTANTS

#endif

#if    !defined(CPPCMS_BOOST_MPL_CFG_NO_NESTED_VALUE_ARITHMETIC) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE) \
    && ( CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300) \
        || CPPCMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 238) \
        )

#   define CPPCMS_BOOST_MPL_CFG_NO_NESTED_VALUE_ARITHMETIC

#endif

#endif // BOOST_MPL_AUX_CONFIG_INTEGRAL_HPP_INCLUDED
