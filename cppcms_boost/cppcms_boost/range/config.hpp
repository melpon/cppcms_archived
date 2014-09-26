// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef CPPCMS_BOOST_RANGE_CONFIG_HPP
#define CPPCMS_BOOST_RANGE_CONFIG_HPP

#include <cppcms_boost/detail/workaround.hpp>

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <cppcms_boost/config.hpp>

#ifdef CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME
#error "macro already defined!"
#endif

#if CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x564))
# define CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME typename
#else
# if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1300) && !defined(_MSC_EXTENSIONS)
#  define CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME typename
# else
#  define CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME CPPCMS_BOOST_DEDUCED_TYPENAME
# endif
#endif

#ifdef CPPCMS_BOOST_RANGE_NO_ARRAY_SUPPORT
#error "macro already defined!"
#endif

#if CPPCMS_BOOST_WORKAROUND( CPPCMS_BOOST_MSVC, < 1300 ) || CPPCMS_BOOST_WORKAROUND( __MWERKS__, <= 0x3003 )
#define CPPCMS_BOOST_RANGE_NO_ARRAY_SUPPORT 1
#endif

#ifdef CPPCMS_BOOST_RANGE_NO_ARRAY_SUPPORT
#define CPPCMS_BOOST_RANGE_ARRAY_REF() (cppcms_boost_range_array)
#define CPPCMS_BOOST_RANGE_NO_STATIC_ASSERT
#else
#define CPPCMS_BOOST_RANGE_ARRAY_REF() (&cppcms_boost_range_array)
#endif



#endif

