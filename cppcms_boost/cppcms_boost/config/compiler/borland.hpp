//  (C) Copyright John Maddock 2001 - 2003.
//  (C) Copyright David Abrahams 2002 - 2003.
//  (C) Copyright Aleksey Gurtovoy 2002.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Borland C++ compiler setup:

//
// versions check:
// we don't support Borland prior to version 5.4:
#if __BORLANDC__ < 0x540
#  error "Compiler not supported or configured - please reconfigure"
#endif

// last known compiler version:
#if (__BORLANDC__ > 0x613)
//#  if defined(BOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
//#  else
//#     pragma message( "Unknown compiler version - please run the configure tests and report the results")
//#  endif
#elif (__BORLANDC__ == 0x600)
#  error "CBuilderX preview compiler is no longer supported"
#endif

//
// Support macros to help with standard library detection
#if (__BORLANDC__ < 0x560) || defined(_USE_OLD_RW_STL)
#  define CPPCMS_BOOST_BCB_WITH_ROGUE_WAVE
#elif __BORLANDC__ < 0x570
#  define CPPCMS_BOOST_BCB_WITH_STLPORT
#else
#  define CPPCMS_BOOST_BCB_WITH_DINKUMWARE
#endif

//
// Version 5.0 and below:
#   if __BORLANDC__ <= 0x0550
// Borland C++Builder 4 and 5:
#     define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#     if __BORLANDC__ == 0x0550
// Borland C++Builder 5, command-line compiler 5.5:
#       define CPPCMS_BOOST_NO_OPERATORS_IN_NAMESPACE
#     endif
#   endif

// Version 5.51 and below:
#if (__BORLANDC__ <= 0x551)
#  define CPPCMS_BOOST_NO_CV_SPECIALIZATIONS
#  define CPPCMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
#  define CPPCMS_BOOST_NO_DEDUCED_TYPENAME
// workaround for missing WCHAR_MAX/WCHAR_MIN:
#include <climits>
#include <cwchar>
#ifndef WCHAR_MAX
#  define WCHAR_MAX 0xffff
#endif
#ifndef WCHAR_MIN
#  define WCHAR_MIN 0
#endif
#endif

// Borland C++ Builder 6 and below:
#if (__BORLANDC__ <= 0x564)
#  define CPPCMS_BOOST_NO_INTEGRAL_INT64_T

#  ifdef NDEBUG
      // fix broken <cstring> so that Boost.test works:
#     include <cstring>
#     undef strcmp
#  endif
   // fix broken errno declaration:
#  include <errno.h>
#  ifndef errno
#     define errno errno
#  endif

#endif

//
// new bug in 5.61:
#if (__BORLANDC__ >= 0x561) && (__BORLANDC__ <= 0x580)
   // this seems to be needed by the command line compiler, but not the IDE:
#  define CPPCMS_BOOST_NO_MEMBER_FUNCTION_SPECIALIZATIONS
#endif

// Borland C++ Builder 2006 Update 2 and below:
#if (__BORLANDC__ <= 0x582)
#  define CPPCMS_BOOST_NO_SFINAE
#  define CPPCMS_BOOST_BCB_PARTIAL_SPECIALIZATION_BUG
#  define CPPCMS_BOOST_NO_TEMPLATE_TEMPLATES

#  define CPPCMS_BOOST_NO_PRIVATE_IN_AGGREGATE

#  ifdef _WIN32
#     define CPPCMS_BOOST_NO_SWPRINTF
#  elif defined(linux) || defined(__linux__) || defined(__linux)
      // we should really be able to do without this
      // but the wcs* functions aren't imported into std::
#     define CPPCMS_BOOST_NO_STDC_NAMESPACE
      // _CPPUNWIND doesn't get automatically set for some reason:
#     pragma defineonoption CPPCMS_BOOST_CPPUNWIND -x
#  endif
#endif

#if (__BORLANDC__ <= 0x613)  // Beman has asked Alisdair for more info
   // we shouldn't really need this - but too many things choke
   // without it, this needs more investigation:
#  define CPPCMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
#  define CPPCMS_BOOST_NO_IS_ABSTRACT
#  define CPPCMS_BOOST_NO_FUNCTION_TYPE_SPECIALIZATIONS
#  define CPPCMS_BOOST_NO_USING_TEMPLATE
#  define CPPCMS_BOOST_SP_NO_SP_CONVERTIBLE

// Temporary workaround
#define CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif

// Borland C++ Builder 2008 and below:
#  define CPPCMS_BOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#  define CPPCMS_BOOST_NO_DEPENDENT_NESTED_DERIVATIONS
#  define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#  define CPPCMS_BOOST_NO_TWO_PHASE_NAME_LOOKUP
#  define CPPCMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE
#  define CPPCMS_BOOST_NO_NESTED_FRIENDSHIP
#  define CPPCMS_BOOST_NO_TYPENAME_WITH_CTOR
#if (__BORLANDC__ < 0x600)
#  define CPPCMS_BOOST_ILLEGAL_CV_REFERENCES
#endif

//
//  Positive Feature detection
//
// Borland C++ Builder 2008 and below:
#if (__BORLANDC__ >= 0x599)
#  pragma defineonoption CPPCMS_BOOST_CODEGEAR_0X_SUPPORT -Ax
#endif
//
// C++0x Macros:
//
#if !defined( CPPCMS_BOOST_CODEGEAR_0X_SUPPORT ) || (__BORLANDC__ < 0x610)
#  define CPPCMS_BOOST_NO_CHAR16_T
#  define CPPCMS_BOOST_NO_CHAR32_T
#  define CPPCMS_BOOST_NO_DECLTYPE
#  define CPPCMS_BOOST_NO_EXPLICIT_CONVERSION_OPERATORS
#  define CPPCMS_BOOST_NO_EXTERN_TEMPLATE
#  define CPPCMS_BOOST_NO_RVALUE_REFERENCES 
#  define CPPCMS_BOOST_NO_SCOPED_ENUMS
#  define CPPCMS_BOOST_NO_STATIC_ASSERT
#else
#  define CPPCMS_BOOST_HAS_ALIGNOF
#  define CPPCMS_BOOST_HAS_CHAR16_T
#  define CPPCMS_BOOST_HAS_CHAR32_T
#  define CPPCMS_BOOST_HAS_DECLTYPE
#  define CPPCMS_BOOST_HAS_EXPLICIT_CONVERSION_OPS
#  define CPPCMS_BOOST_HAS_REF_QUALIFIER
#  define CPPCMS_BOOST_HAS_RVALUE_REFS
#  define CPPCMS_BOOST_HAS_STATIC_ASSERT
#endif

#define CPPCMS_BOOST_NO_AUTO_DECLARATIONS
#define CPPCMS_BOOST_NO_AUTO_MULTIDECLARATIONS
#define CPPCMS_BOOST_NO_CONCEPTS
#define CPPCMS_BOOST_NO_CONSTEXPR
#define CPPCMS_BOOST_NO_DEFAULTED_FUNCTIONS
#define CPPCMS_BOOST_NO_DELETED_FUNCTIONS
#define CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define CPPCMS_BOOST_NO_INITIALIZER_LISTS
#define CPPCMS_BOOST_NO_LAMBDAS
#define CPPCMS_BOOST_NO_NULLPTR
#define CPPCMS_BOOST_NO_RAW_LITERALS
#define CPPCMS_BOOST_NO_RVALUE_REFERENCES
#define CPPCMS_BOOST_NO_SCOPED_ENUMS
#define CPPCMS_BOOST_NO_SFINAE_EXPR
#define CPPCMS_BOOST_NO_TEMPLATE_ALIASES
#define CPPCMS_BOOST_NO_UNICODE_LITERALS    // UTF-8 still not supported
#define CPPCMS_BOOST_NO_VARIADIC_TEMPLATES

#if __BORLANDC__ >= 0x590
#  define CPPCMS_BOOST_HAS_TR1_HASH

#  define CPPCMS_BOOST_HAS_MACRO_USE_FACET
#endif

//
// Post 0x561 we have long long and stdint.h:
#if __BORLANDC__ >= 0x561
#  ifndef __NO_LONG_LONG
#     define CPPCMS_BOOST_HAS_LONG_LONG
#  else
#     define CPPCMS_BOOST_NO_LONG_LONG
#  endif
   // On non-Win32 platforms let the platform config figure this out:
#  ifdef _WIN32
#      define CPPCMS_BOOST_HAS_STDINT_H
#  endif
#endif

// Borland C++Builder 6 defaults to using STLPort.  If _USE_OLD_RW_STL is
// defined, then we have 0x560 or greater with the Rogue Wave implementation
// which presumably has the std::DBL_MAX bug.
#if defined( CPPCMS_BOOST_BCB_WITH_ROGUE_WAVE )
// <climits> is partly broken, some macros define symbols that are really in
// namespace std, so you end up having to use illegal constructs like
// std::DBL_MAX, as a fix we'll just include float.h and have done with:
#include <float.h>
#endif
//
// __int64:
//
#if (__BORLANDC__ >= 0x530) && !defined(__STRICT_ANSI__)
#  define CPPCMS_BOOST_HAS_MS_INT64
#endif
//
// check for exception handling support:
//
#if !defined(_CPPUNWIND) && !defined(CPPCMS_BOOST_CPPUNWIND) && !defined(__EXCEPTIONS)
#  define CPPCMS_BOOST_NO_EXCEPTIONS
#endif
//
// all versions have a <dirent.h>:
//
#ifndef __STRICT_ANSI__
#  define CPPCMS_BOOST_HAS_DIRENT_H
#endif
//
// all versions support __declspec:
//
#ifndef __STRICT_ANSI__
#  define CPPCMS_BOOST_HAS_DECLSPEC
#endif
//
// ABI fixing headers:
//
#if __BORLANDC__ != 0x600 // not implemented for version 6 compiler yet
#ifndef CPPCMS_BOOST_ABI_PREFIX
#  define CPPCMS_BOOST_ABI_PREFIX "cppcms_boost/config/abi/borland_prefix.hpp"
#endif
#ifndef CPPCMS_BOOST_ABI_SUFFIX
#  define CPPCMS_BOOST_ABI_SUFFIX "cppcms_boost/config/abi/borland_suffix.hpp"
#endif
#endif
//
// Disable Win32 support in ANSI mode:
//
#if __BORLANDC__ < 0x600
#  pragma defineonoption CPPCMS_BOOST_DISABLE_WIN32 -A
#elif defined(__STRICT_ANSI__)
#  define CPPCMS_BOOST_DISABLE_WIN32
#endif
//
// MSVC compatibility mode does some nasty things:
// TODO: look up if this doesn't apply to the whole 12xx range
//
#if defined(_MSC_VER) && (_MSC_VER <= 1200)
#  define CPPCMS_BOOST_NO_ARGUMENT_DEPENDENT_LOOKUP
#  define CPPCMS_BOOST_NO_VOID_RETURNS
#endif

#define CPPCMS_BOOST_COMPILER "Borland C++ version " CPPCMS_BOOST_STRINGIZE(__BORLANDC__)



