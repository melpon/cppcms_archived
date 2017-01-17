//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTERPROCESS_CONTAINERS_VERSION_TYPE_HPP
#define CPPCMS_BOOST_INTERPROCESS_CONTAINERS_VERSION_TYPE_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <cppcms_boost/interprocess/detail/config_begin.hpp>
#include <cppcms_boost/interprocess/containers/container/detail/version_type.hpp>

namespace cppcms_boost {
namespace interprocess {

using cppcms_boost::container::containers_detail::version_type;
using cppcms_boost::container::containers_detail::version;

}  //namespace interprocess {
}  //namespace boost {

#include <cppcms_boost/interprocess/detail/config_end.hpp>

#endif //   #ifndef  BOOST_INTERPROCESS_CONTAINERS_VERSION_TYPE_HPP

