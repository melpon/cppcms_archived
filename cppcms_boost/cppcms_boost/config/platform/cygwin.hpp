//  (C) Copyright John Maddock 2001 - 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  cygwin specific config options:

#define CPPCMS_BOOST_PLATFORM "Cygwin"
#define CPPCMS_BOOST_NO_CWCTYPE
#define CPPCMS_BOOST_NO_CWCHAR
#define CPPCMS_BOOST_NO_SWPRINTF
#define CPPCMS_BOOST_HAS_DIRENT_H
#define CPPCMS_BOOST_HAS_LOG1P
#define CPPCMS_BOOST_HAS_EXPM1

//
// Threading API:
// See if we have POSIX threads, if we do use them, otherwise
// revert to native Win threads.
#define CPPCMS_BOOST_HAS_UNISTD_H
#include <unistd.h>
#if defined(_POSIX_THREADS) && (_POSIX_THREADS+0 >= 0) && !defined(CPPCMS_BOOST_HAS_WINTHREADS)
#  define CPPCMS_BOOST_HAS_PTHREADS
#  define CPPCMS_BOOST_HAS_SCHED_YIELD
#  define CPPCMS_BOOST_HAS_GETTIMEOFDAY
#  define CPPCMS_BOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE
#  define CPPCMS_BOOST_HAS_SIGACTION
#else
#  if !defined(CPPCMS_BOOST_HAS_WINTHREADS)
#     define CPPCMS_BOOST_HAS_WINTHREADS
#  endif
#  define CPPCMS_BOOST_HAS_FTIME
#endif

//
// find out if we have a stdint.h, there should be a better way to do this:
//
#include <sys/types.h>
#ifdef _STDINT_H
#define CPPCMS_BOOST_HAS_STDINT_H
#endif

// boilerplate code:
#include <cppcms_boost/config/posix_features.hpp>
 




