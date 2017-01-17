
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_ADD_REFERENCE_HPP_INCLUDED
#define CPPCMS_BOOST_TT_ADD_REFERENCE_HPP_INCLUDED

#include <cppcms_boost/type_traits/is_reference.hpp>
#include <cppcms_boost/detail/workaround.hpp>
#include <cppcms_boost/config.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/type_trait_def.hpp>

namespace cppcms_boost {

namespace detail {

#if defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && defined(CPPCMS_BOOST_MSVC6_MEMBER_TEMPLATES)

template <bool x>
struct reference_adder
{
    template <typename T> struct result_
    {
        typedef T& type;
    };
};

template <>
struct reference_adder<true>
{
    template <typename T> struct result_
    {
        typedef T type;
    };
};

template <typename T>
struct add_reference_impl
{
    typedef typename reference_adder<
          ::cppcms_boost::is_reference<T>::value
        >::template result_<T> result;

    typedef typename result::type type;
};

#else

template <typename T>
struct add_reference_impl
{
    typedef T& type;
};

#ifndef CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_PARTIAL_SPEC1_1(typename T,add_reference,T&,T&)
#endif

#endif

// these full specialisations are always required:
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void,void)
#ifndef CPPCMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void const,void const)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void volatile,void volatile)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_IMPL_SPEC1(add_reference,void const volatile,void const volatile)
#endif

} // namespace detail

CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(add_reference,T,typename cppcms_boost::detail::add_reference_impl<T>::type)

// agurt, 07/mar/03: workaround Borland's ill-formed sensitivity to an additional
// level of indirection, here
#if CPPCMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)
CPPCMS_BOOST_TT_AUX_TYPE_TRAIT_PARTIAL_SPEC1_1(typename T,add_reference,T&,T&)
#endif

} // namespace boost

#include <cppcms_boost/type_traits/detail/type_trait_undef.hpp>

#endif // BOOST_TT_ADD_REFERENCE_HPP_INCLUDED
