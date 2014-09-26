
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_IS_VOID_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_VOID_HPP_INCLUDED

#include <cppcms_boost/config.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

//* is a type T void - is_void<T>
#if defined( __CODEGEARC__ )
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_void,T,__is_void(T))
#else
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_void,T,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_SPEC1(is_void,void,true)

#ifndef CPPCMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_SPEC1(is_void,void const,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_SPEC1(is_void,void volatile,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_SPEC1(is_void,void const volatile,true)
#endif

#endif  // non-CodeGear implementation

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_VOID_HPP_INCLUDED
