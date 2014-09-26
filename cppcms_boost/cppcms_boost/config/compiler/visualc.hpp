//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Darin Adler 2001 - 2002. 
//  (C) Copyright Peter Dimov 2001. 
//  (C) Copyright Aleksey Gurtovoy 2002. 
//  (C) Copyright David Abrahams 2002 - 2003. 
//  (C) Copyright Beman Dawes 2002 - 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Microsoft Visual C++ compiler setup:

#define CPPCMS_BOOST_MSVC _MSC_VER

#if _MSC_FULL_VER > 100000000
#  define CPPCMS_BOOST_MSVC_FULL_VER _MSC_FULL_VER
#else
#  define CPPCMS_BOOST_MSVC_FULL_VER (_MSC_FULL_VER * 10)
#endif

// turn off the warnings before we #include anything
#pragma warning( disable : 4503 ) // warning: decorated name length exceeded

#if _MSC_VER < 1300  // 1200 == VC++ 6.0, 1200-1202 == eVC++4
#  pragma warning( disable : 4786 ) // ident trunc to '255' chars in debug info
#  define CPPCMS_BOOST_NO_DEPENDENT_TYPES_IN_TEMPLATE_VALUE_PARAMETERS
#  define CPPCMS_BOOST_NO_VOID_RETURNS
#  define CPPCMS_BOOST_NO_EXCEPTION_STD_NAMESPACE

#  if CPPCMS_BOOST_MSVC == 1202
#    define CPPCMS_BOOST_NO_STD_TYPEINFO
#  endif

   // disable min/max macro defines on vc6:
   //
#endif

#if (_MSC_VER <= 1300)  // 1300 == VC++ 7.0

#  if !defined(_MSC_EXTENSIONS) && !defined(CPPCMS_BOOST_NO_DEPENDENT_TYPES_IN_TEMPLATE_VALUE_PARAMETERS)      // VC7 bug with /Za
#    define CPPCMS_BOOST_NO_DEPENDENT_TYPES_IN_TEMPLATE_VALUE_PARAMETERS
#  endif

#  define CPPCMS_BOOST_NO_EXPLICIT_FUNCTION_TEMPLATE_ARGUMENTS
#  define CPPCMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
#  define CPPCMS_BOOST_NO_PRIVATE_IN_AGGREGATE
#  define CPPCMS_BOOST_NO_ARGUMENT_DEPENDENT_LOOKUP
#  define CPPCMS_BOOST_NO_INTEGRAL_INT64_T
#  define CPPCMS_BOOST_NO_DEDUCED_TYPENAME
#  define CPPCMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE

//    VC++ 6/7 has member templates but they have numerous problems including
//    cases of silent failure, so for safety we define:
#  define CPPCMS_BOOST_NO_MEMBER_TEMPLATES
//    For VC++ experts wishing to attempt workarounds, we define:
#  define CPPCMS_BOOST_MSVC6_MEMBER_TEMPLATES

#  define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#  define CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#  define CPPCMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
#  define CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING
#  define CPPCMS_BOOST_NO_USING_TEMPLATE
#  define CPPCMS_BOOST_NO_SWPRINTF
#  define CPPCMS_BOOST_NO_TEMPLATE_TEMPLATES
#  define CPPCMS_BOOST_NO_SFINAE
#  define CPPCMS_BOOST_NO_POINTER_TO_MEMBER_TEMPLATE_PARAMETERS
#  define CPPCMS_BOOST_NO_IS_ABSTRACT
#  define CPPCMS_BOOST_NO_FUNCTION_TYPE_SPECIALIZATIONS
// TODO: what version is meant here? Have there really been any fixes in cl 12.01 (as e.g. shipped with eVC4)?
#  if (_MSC_VER > 1200)
#     define CPPCMS_BOOST_NO_MEMBER_FUNCTION_SPECIALIZATIONS
#  endif

#endif

#if _MSC_VER < 1400 
// although a conforming signature for swprint exists in VC7.1
// it appears not to actually work:
#  define CPPCMS_BOOST_NO_SWPRINTF
#endif

#if defined(UNDER_CE)
// Windows CE does not have a conforming signature for swprintf
#  define CPPCMS_BOOST_NO_SWPRINTF
#endif

#if _MSC_VER <= 1400  // 1400 == VC++ 8.0
#  define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#endif

#if _MSC_VER <= 1600  // 1600 == VC++ 10.0
#  define CPPCMS_BOOST_NO_TWO_PHASE_NAME_LOOKUP
#endif

#if _MSC_VER == 1500  // 1500 == VC++ 9.0
   // A bug in VC9:
#  define CPPCMS_BOOST_NO_ADL_BARRIER
#endif

#  define CPPCMS_BOOST_NO_INITIALIZER_LISTS

#ifndef _NATIVE_WCHAR_T_DEFINED
#  define CPPCMS_BOOST_NO_INTRINSIC_WCHAR_T
#endif

#if defined(_WIN32_WCE) || defined(UNDER_CE)
#  define CPPCMS_BOOST_NO_THREADEX
#  define CPPCMS_BOOST_NO_GETSYSTEMTIMEASFILETIME
#  define CPPCMS_BOOST_NO_SWPRINTF
#endif

//   
// check for exception handling support:   
#ifndef _CPPUNWIND 
#  define CPPCMS_BOOST_NO_EXCEPTIONS   
#endif 

//
// __int64 support:
//
#if (_MSC_VER >= 1200)
#   define CPPCMS_BOOST_HAS_MS_INT64
#endif
#if (_MSC_VER >= 1310) && defined(_MSC_EXTENSIONS)
#   define CPPCMS_BOOST_HAS_LONG_LONG
#else
#   define CPPCMS_BOOST_NO_LONG_LONG
#endif
#if (_MSC_VER >= 1400) && !defined(_DEBUG)
#   define CPPCMS_BOOST_HAS_NRVO
#endif
//
// disable Win32 API's if compiler extentions are
// turned off:
//
#if !defined(_MSC_EXTENSIONS) && !defined(CPPCMS_BOOST_DISABLE_WIN32)
#  define CPPCMS_BOOST_DISABLE_WIN32
#endif
#if !defined(_CPPRTTI) && !defined(CPPCMS_BOOST_NO_RTTI)
#  define CPPCMS_BOOST_NO_RTTI
#endif

//
// all versions support __declspec:
//
#define CPPCMS_BOOST_HAS_DECLSPEC

//
// C++0x features
//
//   See above for BOOST_NO_LONG_LONG

// C++ features supported by VC++ 10 (aka 2010)
//
#if _MSC_VER < 1600
#define CPPCMS_BOOST_NO_AUTO_DECLARATIONS
#define CPPCMS_BOOST_NO_AUTO_MULTIDECLARATIONS
#define CPPCMS_BOOST_NO_DECLTYPE
#define CPPCMS_BOOST_NO_LAMBDAS
#define CPPCMS_BOOST_NO_RVALUE_REFERENCES
#define CPPCMS_BOOST_NO_STATIC_ASSERT
#endif // _MSC_VER < 1600

// C++0x features not supported by any versions
#define CPPCMS_BOOST_NO_CHAR16_T
#define CPPCMS_BOOST_NO_CHAR32_T
#define CPPCMS_BOOST_NO_CONCEPTS
#define CPPCMS_BOOST_NO_CONSTEXPR
#define CPPCMS_BOOST_NO_DEFAULTED_FUNCTIONS
#define CPPCMS_BOOST_NO_DELETED_FUNCTIONS
#define CPPCMS_BOOST_NO_EXPLICIT_CONVERSION_OPERATORS
#define CPPCMS_BOOST_NO_EXTERN_TEMPLATE
#define CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define CPPCMS_BOOST_NO_INITIALIZER_LISTS
#define CPPCMS_BOOST_NO_NULLPTR
#define CPPCMS_BOOST_NO_RAW_LITERALS
#define CPPCMS_BOOST_NO_SCOPED_ENUMS
#define CPPCMS_BOOST_NO_SFINAE_EXPR
#define CPPCMS_BOOST_NO_TEMPLATE_ALIASES
#define CPPCMS_BOOST_NO_UNICODE_LITERALS
#define CPPCMS_BOOST_NO_VARIADIC_TEMPLATES

//
// prefix and suffix headers:
//
#ifndef CPPCMS_BOOST_ABI_PREFIX
#  define CPPCMS_BOOST_ABI_PREFIX "cppcms_boost/config/abi/msvc_prefix.hpp"
#endif
#ifndef CPPCMS_BOOST_ABI_SUFFIX
#  define CPPCMS_BOOST_ABI_SUFFIX "cppcms_boost/config/abi/msvc_suffix.hpp"
#endif

// TODO:
// these things are mostly bogus. 1200 means version 12.0 of the compiler. The 
// artificial versions assigned to them only refer to the versions of some IDE
// these compilers have been shipped with, and even that is not all of it. Some
// were shipped with freely downloadable SDKs, others as crosscompilers in eVC.
// IOW, you can't use these 'versions' in any sensible way. Sorry.
# if defined(UNDER_CE)
#   if _MSC_VER < 1200
      // Note: these are so far off, they are not really supported
#   elif _MSC_VER < 1300 // eVC++ 4 comes with 1200-1202
#     define CPPCMS_BOOST_COMPILER_VERSION evc4.0
#   elif _MSC_VER == 1400
#     define CPPCMS_BOOST_COMPILER_VERSION evc8
#   elif _MSC_VER == 1500
#     define CPPCMS_BOOST_COMPILER_VERSION evc9
#   elif _MSC_VER == 1600
#     define CPPCMS_BOOST_COMPILER_VERSION evc10
#   else
#      if defined(CPPCMS_BOOST_ASSERT_CONFIG)
#         error "Unknown EVC++ compiler version - please run the configure tests and report the results"
#      else
#         pragma message("Unknown EVC++ compiler version - please run the configure tests and report the results")
#      endif
#   endif
# else
#   if _MSC_VER < 1200
      // Note: these are so far off, they are not really supported
#     define CPPCMS_BOOST_COMPILER_VERSION 5.0
#   elif _MSC_VER < 1300
#       define CPPCMS_BOOST_COMPILER_VERSION 6.0
#   elif _MSC_VER == 1300
#     define CPPCMS_BOOST_COMPILER_VERSION 7.0
#   elif _MSC_VER == 1310
#     define CPPCMS_BOOST_COMPILER_VERSION 7.1
#   elif _MSC_VER == 1400
#     define CPPCMS_BOOST_COMPILER_VERSION 8.0
#   elif _MSC_VER == 1500
#     define CPPCMS_BOOST_COMPILER_VERSION 9.0
#   elif _MSC_VER == 1600
#     define CPPCMS_BOOST_COMPILER_VERSION 10.0
#   else
#     define CPPCMS_BOOST_COMPILER_VERSION _MSC_VER
#   endif
# endif

#define CPPCMS_BOOST_COMPILER "Microsoft Visual C++ version " CPPCMS_BOOST_STRINGIZE(CPPCMS_BOOST_COMPILER_VERSION)

//
// versions check:
// we don't support Visual C++ prior to version 6:
#if _MSC_VER < 1200
#error "Compiler not supported or configured - please reconfigure"
#endif
//
// last known and checked version is 1600 (VC10, aka 2010):
#if (_MSC_VER > 1600)
#  if defined(CPPCMS_BOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
#  else
#     pragma message("Unknown compiler version - please run the configure tests and report the results")
#  endif
#endif
