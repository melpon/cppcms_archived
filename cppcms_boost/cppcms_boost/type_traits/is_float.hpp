
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TYPE_TRAITS_IS_FLOAT_HPP_INCLUDED
#define CPPCMS_BOOST_TYPE_TRAITS_IS_FLOAT_HPP_INCLUDED

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

//* is a type T a floating-point type described in the standard (3.9.1p8)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_float,T,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_float,float,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_float,double,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_float,long double,true)

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TYPE_TRAITS_IS_FLOAT_HPP_INCLUDED
