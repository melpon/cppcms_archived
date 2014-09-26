
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_REMOVE_POINTER_HPP_INCLUDED
#define CPPCMS_BOOST_TT_REMOVE_POINTER_HPP_INCLUDED

#include <cppcms_boost/type_traits/broken_compiler_spec.hpp>
#include <cppcms_boost/config.hpp>
#include <cppcms_boost/detail/workaround.hpp>

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC,<=1300)
#include <cppcms_boost/type_traits/msvc/remove_pointer.hpp>
#endif

// should be the last #include
#include <cppcms_boost/type_traits/detail/type_trait_def.hpp>

namespace cppcms_boost {

#ifndef CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(remove_pointer,T,T)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_pointer,T*,T)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_pointer,T* const,T)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_pointer,T* volatile,T)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_pointer,T* const volatile,T)

#elif !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC,<=1300)

CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(remove_pointer,T,typename cppcms_boost::detail::remove_pointer_impl<T>::type)

#endif

} // namespace boost

#include <cppcms_boost/type_traits/detail/type_trait_undef.hpp>

#endif // BOOST_TT_REMOVE_POINTER_HPP_INCLUDED
