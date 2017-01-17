//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTERPROCESS_DETAIL_MIN_MAX_HPP
#define CPPCMS_BOOST_INTERPROCESS_DETAIL_MIN_MAX_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <cppcms_boost/interprocess/detail/config_begin.hpp>
#include <cppcms_boost/interprocess/detail/workaround.hpp>

namespace cppcms_boost {
namespace interprocess { 

template<class T>
const T &max_value(const T &a, const T &b)
{  return a > b ? a : b;   }

template<class T>
const T &min_value(const T &a, const T &b)
{  return a < b ? a : b;   }

}  //namespace interprocess { 
}  //namespace boost {

#include <cppcms_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef BOOST_INTERPROCESS_DETAIL_MIN_MAX_HPP

