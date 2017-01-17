//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTERPROCESS_MUTEX_FAMILY_HPP
#define CPPCMS_BOOST_INTERPROCESS_MUTEX_FAMILY_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <cppcms_boost/interprocess/detail/config_begin.hpp>
#include <cppcms_boost/interprocess/detail/workaround.hpp>

#include <cppcms_boost/interprocess/sync/interprocess_mutex.hpp>
#include <cppcms_boost/interprocess/sync/interprocess_recursive_mutex.hpp>
#include <cppcms_boost/interprocess/sync/null_mutex.hpp>

//!\file
//!Describes a shared interprocess_mutex family fit algorithm used to allocate objects in shared memory.

namespace cppcms_boost {

namespace interprocess {

//!Describes interprocess_mutex family to use with Interprocess framework 
//!based on boost::interprocess synchronization objects.
struct mutex_family
{
   typedef cppcms_boost::interprocess::interprocess_mutex                 mutex_type;
   typedef cppcms_boost::interprocess::interprocess_recursive_mutex       recursive_mutex_type;
};

//!Describes interprocess_mutex family to use with Interprocess frameworks 
//!based on null operation synchronization objects.
struct null_mutex_family
{
   typedef cppcms_boost::interprocess::null_mutex                   mutex_type;
   typedef cppcms_boost::interprocess::null_mutex                   recursive_mutex_type;
};

}  //namespace interprocess {

}  //namespace boost {

#include <cppcms_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef BOOST_INTERPROCESS_MUTEX_FAMILY_HPP


