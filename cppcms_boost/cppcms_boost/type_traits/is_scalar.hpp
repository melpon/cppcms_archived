
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_IS_SCALAR_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_SCALAR_HPP_INCLUDED

#include <cppcms_boost/type_traits/is_arithmetic.hpp>
#include <cppcms_boost/type_traits/is_enum.hpp>
#include <cppcms_boost/type_traits/is_pointer.hpp>
#include <cppcms_boost/type_traits/is_member_pointer.hpp>
#include <cppcms_boost/type_traits/detail/ice_or.hpp>
#include <cppcms_boost/config.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

namespace detail {

template <typename T>
struct is_scalar_impl
{ 
   CPPCMS_BOOST_STATIC_CONSTANT(bool, value =
      (::cppcms_boost::type_traits::ice_or<
         ::cppcms_boost::is_arithmetic<T>::value,
         ::cppcms_boost::is_enum<T>::value,
         ::cppcms_boost::is_pointer<T>::value,
         ::cppcms_boost::is_member_pointer<T>::value
      >::value));
};

// these specializations are only really needed for compilers 
// without partial specialization support:
template <> struct is_scalar_impl<void>{ CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false ); };
#ifndef CPPCMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct is_scalar_impl<void const>{ CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false ); };
template <> struct is_scalar_impl<void volatile>{ CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false ); };
template <> struct is_scalar_impl<void const volatile>{ CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false ); };
#endif

} // namespace detail

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_scalar,T,::cppcms_boost::detail::is_scalar_impl<T>::value)

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_SCALAR_HPP_INCLUDED
