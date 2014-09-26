
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_IS_POD_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_POD_HPP_INCLUDED

#include <cppcms_boost/type_traits/config.hpp>
#include <cppcms_boost/type_traits/is_void.hpp>
#include <cppcms_boost/type_traits/is_scalar.hpp>
#include <cppcms_boost/type_traits/detail/ice_or.hpp>
#include <cppcms_boost/type_traits/intrinsics.hpp>

#include <cstddef>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

// forward declaration, needed by 'is_pod_array_helper' template below
template< typename T > struct is_POD;

namespace detail {

#ifndef CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template <typename T> struct is_pod_impl
{ 
    CPPCMS_BOOST_STATIC_CONSTANT(
        bool, value =
        (::cppcms_boost::type_traits::ice_or<
            ::cppcms_boost::is_scalar<T>::value,
            ::cppcms_boost::is_void<T>::value,
            CPPCMS_BOOST_IS_POD(T)
         >::value));
};

#if !defined(CPPCMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
template <typename T, std::size_t sz>
struct is_pod_impl<T[sz]>
    : is_pod_impl<T>
{
};
#endif

#else

template <bool is_array = false>
struct is_pod_helper
{
    template <typename T> struct result_
    {
        CPPCMS_BOOST_STATIC_CONSTANT(
            bool, value =
            (::cppcms_boost::type_traits::ice_or<
                ::cppcms_boost::is_scalar<T>::value,
                ::cppcms_boost::is_void<T>::value,
                CPPCMS_BOOST_IS_POD(T)
            >::value));
    };
};

template <bool b>
struct bool_to_yes_no_type
{
    typedef ::cppcms_boost::type_traits::no_type type;
};

template <>
struct bool_to_yes_no_type<true>
{
    typedef ::cppcms_boost::type_traits::yes_type type;
};

template <typename ArrayType>
struct is_pod_array_helper
{
    enum { is_pod = ::cppcms_boost::is_POD<ArrayType>::value }; // MSVC workaround
    typedef typename bool_to_yes_no_type<is_pod>::type type;
    type instance() const;
};

template <typename T>
is_pod_array_helper<T> is_POD_array(T*);

template <>
struct is_pod_helper<true>
{
    template <typename T> struct result_
    {
        static T& help();
        CPPCMS_BOOST_STATIC_CONSTANT(bool, value =
            sizeof(is_POD_array(help()).instance()) == sizeof(::cppcms_boost::type_traits::yes_type)
            );
    };
};


template <typename T> struct is_pod_impl
{ 
   CPPCMS_BOOST_STATIC_CONSTANT(
       bool, value = (
           ::cppcms_boost::detail::is_pod_helper<
              ::cppcms_boost::is_array<T>::value
           >::template result_<T>::value
           )
       );
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

// the following help compilers without partial specialization support:
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,void,true)

#ifndef CPPCMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,void const,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,void volatile,true)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_pod,void const volatile,true)
#endif

} // namespace detail

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_POD,T,::cppcms_boost::detail::is_pod_impl<T>::value)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_pod,T,::cppcms_boost::detail::is_pod_impl<T>::value)

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_POD_HPP_INCLUDED
