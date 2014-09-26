
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED
#define CPPCMS_BOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED

#include <cppcms_boost/type_traits/config.hpp>
#include <cppcms_boost/type_traits/intrinsics.hpp>
#include <cppcms_boost/type_traits/is_volatile.hpp>
#include <cppcms_boost/type_traits/is_pod.hpp>
#include <cppcms_boost/type_traits/detail/ice_and.hpp>
#include <cppcms_boost/type_traits/detail/ice_or.hpp>
#include <cppcms_boost/type_traits/detail/ice_not.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

namespace detail {

template <typename T>
struct has_trivial_copy_impl
{
   CPPCMS_BOOST_STATIC_CONSTANT(bool, value =
      (::cppcms_boost::type_traits::ice_and<
         ::cppcms_boost::type_traits::ice_or<
            ::cppcms_boost::is_pod<T>::value,
            CPPCMS_BOOST_HAS_TRIVIAL_COPY(T)
         >::value,
      ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_volatile<T>::value >::value
      >::value));
};

} // namespace detail

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_trivial_copy,T,::cppcms_boost::detail::has_trivial_copy_impl<T>::value)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_trivial_copy_constructor,T,::cppcms_boost::detail::has_trivial_copy_impl<T>::value)

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED
