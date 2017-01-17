//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Toon Knapen 2001 - 2003. 
//  (C) Copyright Lie-Quan Lee 2001. 
//  (C) Copyright Markus Schoepflin 2002 - 2003. 
//  (C) Copyright Beman Dawes 2002 - 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Visual Age (IBM) C++ compiler setup:

#if __IBMCPP__ <= 501
#  define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#  define CPPCMS_BOOST_NO_MEMBER_FUNCTION_SPECIALIZATIONS
#endif

#if (__IBMCPP__ <= 502) 
// Actually the compiler supports inclass member initialization but it
// requires a definition for the class member and it doesn't recognize
// it as an integral constant expression when used as a template argument.
#  define CPPCMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
#  define CPPCMS_BOOST_NO_INTEGRAL_INT64_T
#  define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_KEYWORD
#endif

#if (__IBMCPP__ <= 600) || !defined(CPPCMS_BOOST_STRICT_CONFIG)
#  define CPPCMS_BOOST_NO_POINTER_TO_MEMBER_TEMPLATE_PARAMETERS
#  define CPPCMS_BOOST_NO_INITIALIZER_LISTS
#endif

//
// On AIX thread support seems to be indicated by _THREAD_SAFE:
//
#ifdef _THREAD_SAFE
#  define CPPCMS_BOOST_HAS_THREADS
#endif

#define CPPCMS_BOOST_COMPILER "IBM Visual Age version " CPPCMS_BOOST_STRINGIZE(__IBMCPP__)

//
// versions check:
// we don't support Visual age prior to version 5:
#if __IBMCPP__ < 500
#error "Compiler not supported or configured - please reconfigure"
#endif
//
// last known and checked version is 600:
#if (__IBMCPP__ > 1010)
#  if defined(CPPCMS_BOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
#  endif
#endif

// Some versions of the compiler have issues with default arguments on partial specializations
#define CPPCMS_BOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS

//
// C++0x features
//
//   See boost\config\suffix.hpp for BOOST_NO_LONG_LONG
//
#define CPPCMS_BOOST_NO_AUTO_DECLARATIONS
#define CPPCMS_BOOST_NO_AUTO_MULTIDECLARATIONS
#define CPPCMS_BOOST_NO_CHAR16_T
#define CPPCMS_BOOST_NO_CHAR32_T
#define CPPCMS_BOOST_NO_CONCEPTS
#define CPPCMS_BOOST_NO_CONSTEXPR
#define CPPCMS_BOOST_NO_DECLTYPE
#define CPPCMS_BOOST_NO_DEFAULTED_FUNCTIONS
#define CPPCMS_BOOST_NO_DELETED_FUNCTIONS
#define CPPCMS_BOOST_NO_EXPLICIT_CONVERSION_OPERATORS
#define CPPCMS_BOOST_NO_EXTERN_TEMPLATE
#define CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define CPPCMS_BOOST_NO_LAMBDAS
#define CPPCMS_BOOST_NO_NULLPTR
#define CPPCMS_BOOST_NO_RAW_LITERALS
#define CPPCMS_BOOST_NO_RVALUE_REFERENCES
#define CPPCMS_BOOST_NO_SCOPED_ENUMS
#define CPPCMS_BOOST_NO_SFINAE_EXPR
#define CPPCMS_BOOST_NO_STATIC_ASSERT
#define CPPCMS_BOOST_NO_TEMPLATE_ALIASES
#define CPPCMS_BOOST_NO_UNICODE_LITERALS
#define CPPCMS_BOOST_NO_VARIADIC_TEMPLATES



