
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_REMOVE_BOUNDS_HPP_INCLUDED
#define CPPCMS_BOOST_TT_REMOVE_BOUNDS_HPP_INCLUDED

#include <cppcms_boost/config.hpp>
#include <cstddef>
#include <cppcms_boost/detail/workaround.hpp>

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC,<=1300)
#include <cppcms_boost/type_traits/msvc/remove_bounds.hpp>
#endif

// should be the last #include
#include <cppcms_boost/type_traits/detail/type_trait_def.hpp>

#if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC,<=1300)

namespace cppcms_boost {

CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(remove_bounds,T,T)

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(CPPCMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_bounds,T[N],T type)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_bounds,T const[N],T const type)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_bounds,T volatile[N],T volatile type)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,remove_bounds,T const volatile[N],T const volatile type)
#if !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610)) && !defined(__IBMCPP__) &&  !CPPCMS_BOOST_WORKAROUND(__DMC__, CPPCMS_BOOST_TESTED_AT(0x840))
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_bounds,T[],T)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_bounds,T const[],T const)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_bounds,T volatile[],T volatile)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,remove_bounds,T const volatile[],T const volatile)
#endif
#endif

} // namespace boost

#endif

#include <cppcms_boost/type_traits/detail/type_trait_undef.hpp>

#endif // BOOST_TT_REMOVE_BOUNDS_HPP_INCLUDED
