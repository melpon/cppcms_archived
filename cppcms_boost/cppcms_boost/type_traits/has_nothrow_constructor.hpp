
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED
#define CPPCMS_BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED

#include <cppcms_boost/type_traits/has_trivial_constructor.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

namespace detail{

template <class T>
struct has_nothrow_constructor_imp{
   CPPCMS_BOOST_STATIC_CONSTANT(bool, value = 
      (::cppcms_boost::type_traits::ice_or<
         ::cppcms_boost::has_trivial_constructor<T>::value,
         CPPCMS_BOOST_HAS_NOTHROW_CONSTRUCTOR(T)
      >::value));
};

}

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_nothrow_constructor,T,::cppcms_boost::detail::has_nothrow_constructor_imp<T>::value)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_nothrow_default_constructor,T,::cppcms_boost::detail::has_nothrow_constructor_imp<T>::value)

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED
