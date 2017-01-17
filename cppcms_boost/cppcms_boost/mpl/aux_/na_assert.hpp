
#ifndef CPPCMS_BOOST_MPL_AUX_NA_ASSERT_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_NA_ASSERT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: na_assert.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/na.hpp>
#include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#if !CPPCMS_BOOST_WORKAROUND(_MSC_FULL_VER, <= 140050601)    \
    && !CPPCMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 243)
#   include <cppcms_boost/mpl/assert.hpp>
#   define CPPCMS_BOOST_MPL_AUX_ASSERT_NOT_NA(x) \
    CPPCMS_BOOST_MPL_ASSERT_NOT((cppcms_boost::mpl::is_na<type>)) \
/**/
#else
#   include <cppcms_boost/static_assert.hpp>
#   define CPPCMS_BOOST_MPL_AUX_ASSERT_NOT_NA(x) \
    CPPCMS_BOOST_STATIC_ASSERT(!cppcms_boost::mpl::is_na<x>::value) \
/**/
#endif

#endif // BOOST_MPL_AUX_NA_ASSERT_HPP_INCLUDED
