//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTERPROCESS_DETAIL_PTIME_TO_TIMESPEC_HPP
#define CPPCMS_BOOST_INTERPROCESS_DETAIL_PTIME_TO_TIMESPEC_HPP

#include <cppcms_boost/interprocess/detail/posix_time_types_wrk.hpp>

namespace cppcms_boost {

namespace interprocess {

namespace detail {

inline timespec ptime_to_timespec (const cppcms_boost::posix_time::ptime &tm)
{
   const cppcms_boost::posix_time::ptime epoch(cppcms_boost::gregorian::date(1970,1,1));
   cppcms_boost::posix_time::time_duration duration (tm - epoch);
   timespec ts;
   ts.tv_sec  = duration.total_seconds();
   ts.tv_nsec = duration.total_nanoseconds() % 1000000000;
   return ts;
}

}  //namespace detail {

}  //namespace interprocess {

}  //namespace boost {

#endif   //ifndef BOOST_INTERPROCESS_DETAIL_PTIME_TO_TIMESPEC_HPP
