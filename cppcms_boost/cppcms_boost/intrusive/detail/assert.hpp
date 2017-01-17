/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2006-2009
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTRUSIVE_DETAIL_ASSERT_HPP
#define CPPCMS_BOOST_INTRUSIVE_DETAIL_ASSERT_HPP 

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#if !defined(CPPCMS_BOOST_INTRUSIVE_INVARIANT_ASSERT)
   #include <cppcms_boost/assert.hpp>
   #define CPPCMS_BOOST_INTRUSIVE_INVARIANT_ASSERT CPPCMS_BOOST_ASSERT
#elif defined(CPPCMS_BOOST_INTRUSIVE_INVARIANT_ASSERT_INCLUDE)
   #include CPPCMS_BOOST_INTRUSIVE_INVARIANT_ASSERT_INCLUDE
#endif

#if !defined(CPPCMS_BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT)
   #include <cppcms_boost/assert.hpp>
   #define CPPCMS_BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT CPPCMS_BOOST_ASSERT
#elif defined(CPPCMS_BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT_INCLUDE)
   #include CPPCMS_BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT_INCLUDE
#endif

#if !defined(CPPCMS_BOOST_INTRUSIVE_SAFE_HOOK_DESTRUCTOR_ASSERT)
   #include <cppcms_boost/assert.hpp>
   #define CPPCMS_BOOST_INTRUSIVE_SAFE_HOOK_DESTRUCTOR_ASSERT CPPCMS_BOOST_ASSERT
#elif defined(CPPCMS_BOOST_INTRUSIVE_SAFE_HOOK_DESTRUCTOR_ASSERT_INCLUDE)
   #include CPPCMS_BOOST_INTRUSIVE_SAFE_HOOK_DESTRUCTOR_ASSERT_INCLUDE
#endif

#endif //BOOST_INTRUSIVE_DETAIL_ASSERT_HPP
