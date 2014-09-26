//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTERPROCESS_CONTAINERS_ALLOCATION_TYPE_HPP
#define CPPCMS_BOOST_INTERPROCESS_CONTAINERS_ALLOCATION_TYPE_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <cppcms_boost/interprocess/detail/config_begin.hpp>
#include <cppcms_boost/interprocess/containers/container/detail/allocation_type.hpp>

namespace cppcms_boost {
namespace interprocess {

/// @cond
typedef int allocation_type;
/// @endcond
static const allocation_type allocate_new       = cppcms_boost::container::allocate_new;
static const allocation_type expand_fwd         = cppcms_boost::container::expand_fwd;
static const allocation_type expand_bwd         = cppcms_boost::container::expand_bwd;
static const allocation_type shrink_in_place    = cppcms_boost::container::shrink_in_place;
static const allocation_type try_shrink_in_place= cppcms_boost::container::try_shrink_in_place;
static const allocation_type nothrow_allocation = cppcms_boost::container::nothrow_allocation;
static const allocation_type zero_memory        = cppcms_boost::container::zero_memory;

}  //namespace interprocess {
}  //namespace boost {

#include <cppcms_boost/interprocess/detail/config_end.hpp>

#endif //   #ifndef  BOOST_INTERPROCESS_CONTAINERS_VERSION_TYPE_HPP
