
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_IS_OBJECT_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_OBJECT_HPP_INCLUDED

#include <cppcms_boost/type_traits/is_reference.hpp>
#include <cppcms_boost/type_traits/is_void.hpp>
#include <cppcms_boost/type_traits/is_function.hpp>
#include <cppcms_boost/type_traits/detail/ice_and.hpp>
#include <cppcms_boost/type_traits/detail/ice_not.hpp>
#include <cppcms_boost/config.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

namespace detail {

template <typename T>
struct is_object_impl
{
#ifndef CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
   CPPCMS_BOOST_STATIC_CONSTANT(bool, value =
      (::cppcms_boost::type_traits::ice_and<
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_reference<T>::value>::value,
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_void<T>::value>::value,
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_function<T>::value>::value
      >::value));
#else
   CPPCMS_BOOST_STATIC_CONSTANT(bool, value =
      (::cppcms_boost::type_traits::ice_and<
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_reference<T>::value>::value,
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_void<T>::value>::value
      >::value));
#endif
};

} // namespace detail

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_object,T,::cppcms_boost::detail::is_object_impl<T>::value)

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_OBJECT_HPP_INCLUDED
