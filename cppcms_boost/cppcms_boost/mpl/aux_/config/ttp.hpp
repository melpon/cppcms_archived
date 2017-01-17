
#ifndef CPPCMS_BOOST_MPL_AUX_CONFIG_TTP_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_CONFIG_TTP_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: ttp.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#include <cppcms_boost/mpl/aux_/config/gcc.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS) \
    && ( defined(CPPCMS_BOOST_NO_TEMPLATE_TEMPLATES) \
      || CPPCMS_BOOST_WORKAROUND( __BORLANDC__, CPPCMS_BOOST_TESTED_AT( 0x590) ) \
       )

#   define CPPCMS_BOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS

#endif


#if    !defined(CPPCMS_BOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE) \
    && (   CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MPL_CFG_GCC, CPPCMS_BOOST_TESTED_AT(0x0302)) \
        || CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610)) \
        )

#   define CPPCMS_BOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING

#endif

#endif // BOOST_MPL_AUX_CONFIG_TTP_HPP_INCLUDED
