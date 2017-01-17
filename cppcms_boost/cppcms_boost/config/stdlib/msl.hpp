//  (C) Copyright John Maddock 2001. 
//  (C) Copyright Darin Adler 2001. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Metrowerks standard library:

#ifndef __MSL_CPP__
#  include <cppcms_boost/config/no_tr1/utility.hpp>
#  ifndef __MSL_CPP__
#     error This is not the MSL standard library!
#  endif
#endif

#if __MSL_CPP__ >= 0x6000  // Pro 6
#  define CPPCMS_BOOST_HAS_HASH
#  define CPPCMS_BOOST_STD_EXTENSION_NAMESPACE Metrowerks
#endif
#define CPPCMS_BOOST_HAS_SLIST

#if __MSL_CPP__ < 0x6209
#  define CPPCMS_BOOST_NO_STD_MESSAGES
#endif

// check C lib version for <stdint.h>
#include <cstddef>

#if defined(__MSL__) && (__MSL__ >= 0x5000)
#  define CPPCMS_BOOST_HAS_STDINT_H
#  if !defined(__PALMOS_TRAPS__)
#    define CPPCMS_BOOST_HAS_UNISTD_H
#  endif
   // boilerplate code:
#  include <cppcms_boost/config/posix_features.hpp>
#endif

#if defined(_MWMT) || _MSL_THREADSAFE
#  define CPPCMS_BOOST_HAS_THREADS
#endif

#ifdef _MSL_NO_EXPLICIT_FUNC_TEMPLATE_ARG
#  define CPPCMS_BOOST_NO_STD_USE_FACET
#  define CPPCMS_BOOST_HAS_TWO_ARG_USE_FACET
#endif

//  C++0x headers not yet implemented
//
#  define CPPCMS_BOOST_NO_0X_HDR_ARRAY
#  define CPPCMS_BOOST_NO_0X_HDR_CHRONO
#  define CPPCMS_BOOST_NO_0X_HDR_CODECVT
#  define CPPCMS_BOOST_NO_0X_HDR_CONCEPTS
#  define CPPCMS_BOOST_NO_0X_HDR_CONDITION_VARIABLE
#  define CPPCMS_BOOST_NO_0X_HDR_CONTAINER_CONCEPTS
#  define CPPCMS_BOOST_NO_0X_HDR_FORWARD_LIST
#  define CPPCMS_BOOST_NO_0X_HDR_FUTURE
#  define CPPCMS_BOOST_NO_0X_HDR_INITIALIZER_LIST
#  define CPPCMS_BOOST_NO_0X_HDR_ITERATOR_CONCEPTS
#  define CPPCMS_BOOST_NO_0X_HDR_MEMORY_CONCEPTS
#  define CPPCMS_BOOST_NO_0X_HDR_MUTEX
#  define CPPCMS_BOOST_NO_0X_HDR_RANDOM
#  define CPPCMS_BOOST_NO_0X_HDR_RATIO
#  define CPPCMS_BOOST_NO_0X_HDR_REGEX
#  define CPPCMS_BOOST_NO_0X_HDR_SYSTEM_ERROR
#  define CPPCMS_BOOST_NO_0X_HDR_THREAD
#  define CPPCMS_BOOST_NO_0X_HDR_TUPLE
#  define CPPCMS_BOOST_NO_0X_HDR_TYPE_TRAITS
#  define CPPCMS_BOOST_NO_STD_UNORDERED        // deprecated; see following
#  define CPPCMS_BOOST_NO_0X_HDR_UNORDERED_MAP
#  define CPPCMS_BOOST_NO_0X_HDR_UNORDERED_SET

#define CPPCMS_BOOST_STDLIB "Metrowerks Standard Library version " CPPCMS_BOOST_STRINGIZE(__MSL_CPP__)









