
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_IS_FUNDAMENTAL_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_FUNDAMENTAL_HPP_INCLUDED

#include <cppcms_boost/type_traits/is_arithmetic.hpp>
#include <cppcms_boost/type_traits/is_void.hpp>
#include <cppcms_boost/type_traits/detail/ice_or.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

namespace detail {

template <typename T> 
struct is_fundamental_impl
    : ::cppcms_boost::type_traits::ice_or< 
          ::cppcms_boost::is_arithmetic<T>::value
        , ::cppcms_boost::is_void<T>::value
        >
{ 
};

} // namespace detail

//* is a type T a fundamental type described in the standard (3.9.1)
#if defined( __CODEGEARC__ )
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_fundamental,T,__is_fundamental(T))
#else
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_fundamental,T,::cppcms_boost::detail::is_fundamental_impl<T>::value)
#endif

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_FUNDAMENTAL_HPP_INCLUDED
