
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_IS_INTEGRAL_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_INTEGRAL_HPP_INCLUDED

#include <cppcms_boost/config.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

//* is a type T an [cv-qualified-] integral type described in the standard (3.9.1p3)
// as an extention we include long long, as this is likely to be added to the
// standard at a later date
#if defined( __CODEGEARC__ )
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_integral,T,__is_integral(T))
#else
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_integral,T,false)

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned char,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned short,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned int,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned long,true)

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed char,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed short,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed int,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed long,true)

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,bool,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,char,true)

#ifndef CPPCMS_BOOST_NO_INTRINSIC_WCHAR_T
// If the following line fails to compile and you're using the Intel
// compiler, see http://lists.boost.org/MailArchives/boost-users/msg06567.php,
// and define BOOST_NO_INTRINSIC_WCHAR_T on the command line.
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,wchar_t,true)
#endif

// Same set of integral types as in boost/type_traits/integral_promotion.hpp.
// Please, keep in sync. -- Alexander Nasonov
#if (defined(CPPCMS_BOOST_MSVC) && (CPPCMS_BOOST_MSVC < 1300)) \
    || (defined(CPPCMS_BOOST_INTEL_CXX_VERSION) && defined(_MSC_VER) && (CPPCMS_BOOST_INTEL_CXX_VERSION <= 600)) \
    || (defined(__BORLANDC__) && (__BORLANDC__ == 0x600) && (_MSC_VER < 1300))
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int8,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int8,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int16,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int16,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int32,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int32,true)
#ifdef __BORLANDC__
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int64,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int64,true)
#endif
#endif

# if defined(CPPCMS_BOOST_HAS_LONG_LONG)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral, ::cppcms_boost::ulong_long_type,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral, ::cppcms_boost::long_long_type,true)
#elif defined(CPPCMS_BOOST_HAS_MS_INT64)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int64,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int64,true)
#endif

#endif  // non-CodeGear implementation

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_INTEGRAL_HPP_INCLUDED
