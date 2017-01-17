//  (C) Copyright John Maddock 2001. 
//  (C) Copyright Darin Adler 2001. 
//  (C) Copyright Peter Dimov 2001. 
//  (C) Copyright David Abrahams 2001 - 2002. 
//  (C) Copyright Beman Dawes 2001 - 2003. 
//  (C) Copyright Stefan Slapeta 2004. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Metrowerks C++ compiler setup:

// locale support is disabled when linking with the dynamic runtime
#   ifdef _MSL_NO_LOCALE
#     define CPPCMS_BOOST_NO_STD_LOCALE
#   endif 

#   if __MWERKS__ <= 0x2301  // 5.3
#     define CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING
#     define CPPCMS_BOOST_NO_POINTER_TO_MEMBER_CONST
#     define CPPCMS_BOOST_NO_DEPENDENT_TYPES_IN_TEMPLATE_VALUE_PARAMETERS
#     define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_KEYWORD
#   endif

#   if __MWERKS__ <= 0x2401  // 6.2
//#     define BOOST_NO_FUNCTION_TEMPLATE_ORDERING
#   endif

#   if(__MWERKS__ <= 0x2407)  // 7.x
#     define CPPCMS_BOOST_NO_MEMBER_FUNCTION_SPECIALIZATIONS
#     define CPPCMS_BOOST_NO_UNREACHABLE_RETURN_DETECTION
#   endif

#   if(__MWERKS__ <= 0x3003)  // 8.x
#     define CPPCMS_BOOST_NO_SFINAE
#    endif

// the "|| !defined(BOOST_STRICT_CONFIG)" part should apply to the last
// tested version *only*:
#   if(__MWERKS__ <= 0x3207) || !defined(CPPCMS_BOOST_STRICT_CONFIG) // 9.6
#     define CPPCMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
#     define CPPCMS_BOOST_NO_IS_ABSTRACT
#    endif

#if !__option(wchar_type)
#   define CPPCMS_BOOST_NO_INTRINSIC_WCHAR_T
#endif

#if !__option(exceptions)
#   define CPPCMS_BOOST_NO_EXCEPTIONS
#endif

#if (__INTEL__ && _WIN32) || (__POWERPC__ && macintosh)
#   if __MWERKS__ == 0x3000
#     define CPPCMS_BOOST_COMPILER_VERSION 8.0
#   elif __MWERKS__ == 0x3001
#     define CPPCMS_BOOST_COMPILER_VERSION 8.1
#   elif __MWERKS__ == 0x3002
#     define CPPCMS_BOOST_COMPILER_VERSION 8.2
#   elif __MWERKS__ == 0x3003
#     define CPPCMS_BOOST_COMPILER_VERSION 8.3
#   elif __MWERKS__ == 0x3200
#     define CPPCMS_BOOST_COMPILER_VERSION 9.0
#   elif __MWERKS__ == 0x3201
#     define CPPCMS_BOOST_COMPILER_VERSION 9.1
#   elif __MWERKS__ == 0x3202
#     define CPPCMS_BOOST_COMPILER_VERSION 9.2
#   elif __MWERKS__ == 0x3204
#     define CPPCMS_BOOST_COMPILER_VERSION 9.3
#   elif __MWERKS__ == 0x3205
#     define CPPCMS_BOOST_COMPILER_VERSION 9.4
#   elif __MWERKS__ == 0x3206
#     define CPPCMS_BOOST_COMPILER_VERSION 9.5
#   elif __MWERKS__ == 0x3207
#     define CPPCMS_BOOST_COMPILER_VERSION 9.6
#   else
#     define CPPCMS_BOOST_COMPILER_VERSION __MWERKS__
#   endif
#else
#  define CPPCMS_BOOST_COMPILER_VERSION __MWERKS__
#endif

//
// C++0x features
//
//   See boost\config\suffix.hpp for BOOST_NO_LONG_LONG
//
#if __MWERKS__ > 0x3206 && __option(rvalue_refs)
#  define CPPCMS_BOOST_HAS_RVALUE_REFS
#else
#  define CPPCMS_BOOST_NO_RVALUE_REFERENCES              
#endif
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
#define CPPCMS_BOOST_NO_INITIALIZER_LISTS
#define CPPCMS_BOOST_NO_LAMBDAS
#define CPPCMS_BOOST_NO_NULLPTR
#define CPPCMS_BOOST_NO_RAW_LITERALS
#define CPPCMS_BOOST_NO_SCOPED_ENUMS
#define CPPCMS_BOOST_NO_SFINAE_EXPR
#define CPPCMS_BOOST_NO_STATIC_ASSERT
#define CPPCMS_BOOST_NO_TEMPLATE_ALIASES
#define CPPCMS_BOOST_NO_UNICODE_LITERALS
#define CPPCMS_BOOST_NO_VARIADIC_TEMPLATES

#define CPPCMS_BOOST_COMPILER "Metrowerks CodeWarrior C++ version " CPPCMS_BOOST_STRINGIZE(CPPCMS_BOOST_COMPILER_VERSION)

//
// versions check:
// we don't support Metrowerks prior to version 5.3:
#if __MWERKS__ < 0x2301
#  error "Compiler not supported or configured - please reconfigure"
#endif
//
// last known and checked version:
#if (__MWERKS__ > 0x3205)
#  if defined(CPPCMS_BOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
#  endif
#endif







