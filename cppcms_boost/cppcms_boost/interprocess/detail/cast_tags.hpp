//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTERPROCESS_CAST_TAGS_HPP
#define CPPCMS_BOOST_INTERPROCESS_CAST_TAGS_HPP

#include <cppcms_boost/interprocess/detail/config_begin.hpp>
#include <cppcms_boost/interprocess/detail/workaround.hpp>

namespace cppcms_boost { namespace interprocess { namespace detail {

struct static_cast_tag {};
struct const_cast_tag {};
struct dynamic_cast_tag {};
struct reinterpret_cast_tag {};

}}}  //namespace boost { namespace interprocess { namespace detail {

#include <cppcms_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef BOOST_INTERPROCESS_CAST_TAGS_HPP

