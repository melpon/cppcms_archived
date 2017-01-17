
#ifndef CPPCMS_BOOST_MPL_AUX_CONFIG_FORWARDING_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_CONFIG_FORWARDING_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: forwarding.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#if    !defined(CPPCMS_BOOST_MPL_CFG_NO_NESTED_FORWARDING) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE) \
    && CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610))

#   define CPPCMS_BOOST_MPL_CFG_NO_NESTED_FORWARDING

#endif

#endif // BOOST_MPL_AUX_CONFIG_FORWARDING_HPP_INCLUDED
