
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


// Some fixes for is_array are based on a newgroup posting by Jonathan Lundquist.


#ifndef CPPCMS_BOOST_TT_IS_ARRAY_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_ARRAY_HPP_INCLUDED

#include <cppcms_boost/type_traits/config.hpp>

#ifdef CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   include <cppcms_boost/type_traits/detail/yes_no_type.hpp>
#   include <cppcms_boost/type_traits/detail/wrap.hpp>
#endif

#include <cstddef>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

#if defined( __CODEGEARC__ )
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_array,T,__is_array(T))
#elif !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_array,T,false)
#if !defined(CPPCMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,is_array,T[N],true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,is_array,T const[N],true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,is_array,T volatile[N],true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(typename T,std::size_t N,is_array,T const volatile[N],true)
#if !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600) && !defined(__IBMCPP__) &&  !CPPCMS_BOOST_WORKAROUND(__DMC__, CPPCMS_BOOST_TESTED_AT(0x840))
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_array,T[],true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_array,T const[],true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_array,T volatile[],true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(typename T,is_array,T const volatile[],true)
#endif
#endif

#else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

namespace detail {

using ::cppcms_boost::type_traits::yes_type;
using ::cppcms_boost::type_traits::no_type;
using ::cppcms_boost::type_traits::wrap;

template< typename T > T(* is_array_tester1(wrap<T>) )(wrap<T>);
char CPPCMS_BOOST_TT_DECL is_array_tester1(...);

template< typename T> no_type is_array_tester2(T(*)(wrap<T>));
yes_type CPPCMS_BOOST_TT_DECL is_array_tester2(...);

template< typename T >
struct is_array_impl
{ 
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = 
        sizeof(::cppcms_boost::detail::is_array_tester2(
            ::cppcms_boost::detail::is_array_tester1(
                ::cppcms_boost::type_traits::wrap<T>()
                )
        )) == 1
    );
};

#ifndef CPPCMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_array,void,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_array,void const,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_array,void volatile,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_array,void const volatile,false)
#endif

} // namespace detail

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_array,T,::cppcms_boost::detail::is_array_impl<T>::value)

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_ARRAY_HPP_INCLUDED
