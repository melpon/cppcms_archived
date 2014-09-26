//  (C) Copyright John Maddock 2001 - 2003.
//  (C) Copyright Jens Maurer 2001.
//  (C) Copyright Peter Dimov 2001.
//  (C) Copyright David Abrahams 2002.
//  (C) Copyright Guillaume Melquiond 2003.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Dinkumware standard library config:

#if !defined(_YVALS) && !defined(_CPPLIB_VER)
#include <cppcms_boost/config/no_tr1/utility.hpp>
#if !defined(_YVALS) && !defined(_CPPLIB_VER)
#error This is not the Dinkumware lib!
#endif
#endif


#if defined(_CPPLIB_VER) && (_CPPLIB_VER >= 306)
   // full dinkumware 3.06 and above
   // fully conforming provided the compiler supports it:
#  if !(defined(_GLOBAL_USING) && (_GLOBAL_USING+0 > 0)) && !defined(__BORLANDC__) && !defined(_STD) && !(defined(__ICC) && (__ICC >= 700))   // can be defined in yvals.h
#     define CPPCMS_BOOST_NO_STDC_NAMESPACE
#  endif
#  if !(defined(_HAS_MEMBER_TEMPLATES_REBIND) && (_HAS_MEMBER_TEMPLATES_REBIND+0 > 0)) && !(defined(_MSC_VER) && (_MSC_VER > 1300)) && defined(CPPCMS_BOOST_MSVC)
#     define CPPCMS_BOOST_NO_STD_ALLOCATOR
#  endif
#  define CPPCMS_BOOST_HAS_PARTIAL_STD_ALLOCATOR
#  if defined(CPPCMS_BOOST_MSVC) && (CPPCMS_BOOST_MSVC < 1300)
      // if this lib version is set up for vc6 then there is no std::use_facet:
#     define CPPCMS_BOOST_NO_STD_USE_FACET
#     define CPPCMS_BOOST_HAS_TWO_ARG_USE_FACET
      // C lib functions aren't in namespace std either:
#     define CPPCMS_BOOST_NO_STDC_NAMESPACE
      // and nor is <exception>
#     define CPPCMS_BOOST_NO_EXCEPTION_STD_NAMESPACE
#  endif
// There's no numeric_limits<long long> support unless _LONGLONG is defined:
#  if !defined(_LONGLONG) && (_CPPLIB_VER <= 310)
#     define CPPCMS_BOOST_NO_MS_INT64_NUMERIC_LIMITS
#  endif
// 3.06 appears to have (non-sgi versions of) <hash_set> & <hash_map>,
// and no <slist> at all
#else
#  define CPPCMS_BOOST_MSVC_STD_ITERATOR 1
#  define CPPCMS_BOOST_NO_STD_ITERATOR
#  define CPPCMS_BOOST_NO_TEMPLATED_ITERATOR_CONSTRUCTORS
#  define CPPCMS_BOOST_NO_STD_ALLOCATOR
#  define CPPCMS_BOOST_NO_STDC_NAMESPACE
#  define CPPCMS_BOOST_NO_STD_USE_FACET
#  define CPPCMS_BOOST_NO_STD_OUTPUT_ITERATOR_ASSIGN
#  define CPPCMS_BOOST_HAS_MACRO_USE_FACET
#  ifndef _CPPLIB_VER
      // Updated Dinkum library defines this, and provides
      // its own min and max definitions, as does MTA version.
#     ifndef __MTA__ 
#        define CPPCMS_BOOST_NO_STD_MIN_MAX
#     endif
#     define CPPCMS_BOOST_NO_MS_INT64_NUMERIC_LIMITS
#  endif
#endif

//
// std extension namespace is stdext for vc7.1 and later, 
// the same applies to other compilers that sit on top
// of vc7.1 (Intel and Comeau):
//
#if defined(_MSC_VER) && (_MSC_VER >= 1310) && !defined(__BORLANDC__)
#  define CPPCMS_BOOST_STD_EXTENSION_NAMESPACE stdext
#endif


#if (defined(_MSC_VER) && (_MSC_VER <= 1300) && !defined(__BORLANDC__)) || !defined(_CPPLIB_VER) || (_CPPLIB_VER < 306)
   // if we're using a dinkum lib that's
   // been configured for VC6/7 then there is
   // no iterator traits (true even for icl)
#  define CPPCMS_BOOST_NO_STD_ITERATOR_TRAITS
#endif

#if defined(__ICL) && (__ICL < 800) && defined(_CPPLIB_VER) && (_CPPLIB_VER <= 310)
// Intel C++ chokes over any non-trivial use of <locale>
// this may be an overly restrictive define, but regex fails without it:
#  define CPPCMS_BOOST_NO_STD_LOCALE
#endif

//  C++0x headers implemented in 520 (as shipped by Microsoft)
//
#if !defined(_CPPLIB_VER) || _CPPLIB_VER < 520
#  define CPPCMS_BOOST_NO_0X_HDR_ARRAY
#  define CPPCMS_BOOST_NO_0X_HDR_CODECVT
#  define CPPCMS_BOOST_NO_0X_HDR_FORWARD_LIST
#  define CPPCMS_BOOST_NO_0X_HDR_INITIALIZER_LIST
#  define CPPCMS_BOOST_NO_0X_HDR_RANDOM
#  define CPPCMS_BOOST_NO_0X_HDR_REGEX
#  define CPPCMS_BOOST_NO_0X_HDR_SYSTEM_ERROR
#  define CPPCMS_BOOST_NO_0X_HDR_TYPE_TRAITS
#  define CPPCMS_BOOST_NO_STD_UNORDERED        // deprecated; see following
#  define CPPCMS_BOOST_NO_0X_HDR_UNORDERED_MAP
#  define CPPCMS_BOOST_NO_0X_HDR_UNORDERED_SET
#endif

//  C++0x headers not yet implemented
//
#  define CPPCMS_BOOST_NO_0X_HDR_CHRONO
#  define CPPCMS_BOOST_NO_0X_HDR_CONCEPTS
#  define CPPCMS_BOOST_NO_0X_HDR_CONDITION_VARIABLE
#  define CPPCMS_BOOST_NO_0X_HDR_CONTAINER_CONCEPTS
#  define CPPCMS_BOOST_NO_0X_HDR_FUTURE
#  define CPPCMS_BOOST_NO_0X_HDR_ITERATOR_CONCEPTS
#  define CPPCMS_BOOST_NO_0X_HDR_MEMORY_CONCEPTS
#  define CPPCMS_BOOST_NO_0X_HDR_MUTEX
#  define CPPCMS_BOOST_NO_0X_HDR_RATIO
#  define CPPCMS_BOOST_NO_0X_HDR_THREAD
#  define CPPCMS_BOOST_NO_0X_HDR_TUPLE
#  define CPPCMS_BOOST_NO_0X_HDR_INITIALIZER_LIST

#ifdef _CPPLIB_VER
#  define CPPCMS_BOOST_DINKUMWARE_STDLIB _CPPLIB_VER
#else
#  define CPPCMS_BOOST_DINKUMWARE_STDLIB 1
#endif

#ifdef _CPPLIB_VER
#  define CPPCMS_BOOST_STDLIB "Dinkumware standard library version " CPPCMS_BOOST_STRINGIZE(_CPPLIB_VER)
#else
#  define CPPCMS_BOOST_STDLIB "Dinkumware standard library version 1.x"
#endif









