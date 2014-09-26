
//  Copyright 2001-2003 Aleksey Gurtovoy.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC_HPP_INCLUDED
#define CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC_HPP_INCLUDED

#include <cppcms_boost/mpl/aux_/lambda_support.hpp>
#include <cppcms_boost/config.hpp>

// these are needed regardless of BOOST_TT_NO_BROKEN_COMPILER_SPEC 
#if defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
namespace cppcms_boost { namespace detail {
template< typename T > struct remove_const_impl     { typedef T type; };
template< typename T > struct remove_volatile_impl  { typedef T type; };
template< typename T > struct remove_pointer_impl   { typedef T type; };
template< typename T > struct remove_reference_impl { typedef T type; };
typedef int invoke_CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC_outside_all_namespaces;
}}
#endif

// agurt, 27/jun/03: disable the workaround if user defined 
// BOOST_TT_NO_BROKEN_COMPILER_SPEC
#if    !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    || defined(CPPCMS_BOOST_TT_NO_BROKEN_COMPILER_SPEC)

#   define CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(T) /**/

#else

// same as BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1 macro, except that it
// never gets #undef-ined
#   define CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(trait,spec,result) \
template<> struct trait##_impl<spec> \
{ \
    typedef result type; \
}; \
/**/

#   define CPPCMS_BOOST_TT_AUX_REMOVE_CONST_VOLATILE_RANK1_SPEC(T)                         \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_const,T const,T)                    \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_const,T const volatile,T volatile)  \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_volatile,T volatile,T)              \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_volatile,T const volatile,T const)  \
    /**/

#   define CPPCMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T)                               \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_pointer,T*,T)                       \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_pointer,T*const,T)                  \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_pointer,T*volatile,T)               \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_pointer,T*const volatile,T)         \
    CPPCMS_BOOST_TT_AUX_BROKEN_TYPE_TRAIT_SPEC1(remove_reference,T&,T)                     \
    /**/

#   define CPPCMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_2_SPEC(T)                               \
    CPPCMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T)                                      \
    CPPCMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T const)                                \
    CPPCMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T volatile)                             \
    CPPCMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_1_SPEC(T const volatile)                       \
    /**/

#   define CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T)                                   \
    CPPCMS_BOOST_TT_AUX_REMOVE_PTR_REF_RANK_2_SPEC(T)                                      \
    CPPCMS_BOOST_TT_AUX_REMOVE_CONST_VOLATILE_RANK1_SPEC(T)                                \
    /**/

#   define CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T)                                   \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T*)                                         \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T const*)                                   \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T volatile*)                                \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T const volatile*)                          \
    /**/

#   define CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(T)                                         \
    namespace cppcms_boost { namespace detail {                                            \
    typedef invoke_CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC_outside_all_namespaces             \
      please_invoke_CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC_outside_all_namespaces;           \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_1_SPEC(T)                                          \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T)                                          \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T*)                                         \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T const*)                                   \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T volatile*)                                \
    CPPCMS_BOOST_TT_AUX_REMOVE_ALL_RANK_2_SPEC(T const volatile*)                          \
    }}                                                                              \
    /**/

#   include <cppcms_boost/type_traits/detail/type_trait_undef.hpp>

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(bool)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(char)
#ifndef CPPCMS_BOOST_NO_INTRINSIC_WCHAR_T
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(wchar_t)
#endif
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(signed char)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(unsigned char)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(signed short)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(unsigned short)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(signed int)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(unsigned int)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(signed long)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(unsigned long)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(float)
CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(double)
//BOOST_TT_BROKEN_COMPILER_SPEC(long double)

// for backward compatibility
#define CPPCMS_BOOST_BROKEN_COMPILER_TYPE_TRAITS_SPECIALIZATION(T) \
    CPPCMS_BOOST_TT_BROKEN_COMPILER_SPEC(T) \
/**/

#endif // BOOST_TT_BROKEN_COMPILER_SPEC_HPP_INCLUDED
