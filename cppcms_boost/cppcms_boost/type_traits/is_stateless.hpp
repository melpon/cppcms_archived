
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_IS_STATELESS_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_STATELESS_HPP_INCLUDED

#include <cppcms_boost/type_traits/has_trivial_constructor.hpp>
#include <cppcms_boost/type_traits/has_trivial_copy.hpp>
#include <cppcms_boost/type_traits/has_trivial_destructor.hpp>
#include <cppcms_boost/type_traits/is_class.hpp>
#include <cppcms_boost/type_traits/is_empty.hpp>
#include <cppcms_boost/type_traits/detail/ice_and.hpp>
#include <cppcms_boost/config.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

namespace detail {

template <typename T>
struct is_stateless_impl
{
  CPPCMS_BOOST_STATIC_CONSTANT(bool, value = 
    (::cppcms_boost::type_traits::ice_and<
       ::cppcms_boost::has_trivial_constructor<T>::value,
       ::cppcms_boost::has_trivial_copy<T>::value,
       ::cppcms_boost::has_trivial_destructor<T>::value,
       ::cppcms_boost::is_class<T>::value,
       ::cppcms_boost::is_empty<T>::value
     >::value));
};

} // namespace detail

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_stateless,T,::cppcms_boost::detail::is_stateless_impl<T>::value)

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_STATELESS_HPP_INCLUDED
