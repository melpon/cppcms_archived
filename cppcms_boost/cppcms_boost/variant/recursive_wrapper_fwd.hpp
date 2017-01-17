//-----------------------------------------------------------------------------
// boost variant/recursive_wrapper_fwd.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002
// Eric Friedman, Itay Maman
//
// Portions Copyright (C) 2002 David Abrahams
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_VARIANT_RECURSIVE_WRAPPER_FWD_HPP
#define CPPCMS_BOOST_VARIANT_RECURSIVE_WRAPPER_FWD_HPP

#include "cppcms_boost/mpl/aux_/config/ctps.hpp"
#if defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#   include "cppcms_boost/mpl/eval_if.hpp"
#   include "cppcms_boost/mpl/bool.hpp"
#   include "cppcms_boost/mpl/identity.hpp"
#   include "cppcms_boost/type.hpp"
#endif

#include "cppcms_boost/mpl/aux_/lambda_support.hpp"

// should be the last #include
#include "cppcms_boost/type_traits/detail/bool_trait_def.hpp"

namespace cppcms_boost {

//////////////////////////////////////////////////////////////////////////
// class template recursive_wrapper
//
// Enables recursive types in templates by breaking cyclic dependencies.
//
// For example:
//
//   class my;
//
//   typedef variant< int, recursive_wrapper<my> > var;
//
//   class my {
//     var var_;
//     ...
//   };
//
template <typename T> class recursive_wrapper;

///////////////////////////////////////////////////////////////////////////////
// metafunction is_recursive_wrapper (modeled on code by David Abrahams)
//
// True iff specified type matches recursive_wrapper<T>.
//

namespace detail {

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template <typename T>
struct is_recursive_wrapper_impl
    : mpl::false_
{
};

template <typename T>
struct is_recursive_wrapper_impl< recursive_wrapper<T> >
    : mpl::true_
{
};

#else // defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

typedef char (&yes_recursive_wrapper_t)[1];
typedef char (&no_recursive_wrapper_t)[2];

no_recursive_wrapper_t is_recursive_wrapper_test(...);

template<typename T>
yes_recursive_wrapper_t is_recursive_wrapper_test(
      type< ::cppcms_boost::recursive_wrapper<T> >
    );

template<typename T>
struct is_recursive_wrapper_impl
{
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = (
          sizeof(is_recursive_wrapper_test(type<T>()))
          == sizeof(yes_recursive_wrapper_t)
        ));
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION workaround

} // namespace detail

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(
      is_recursive_wrapper
    , T
    , (::cppcms_boost::detail::is_recursive_wrapper_impl<T>::value)
    )

///////////////////////////////////////////////////////////////////////////////
// metafunction unwrap_recursive
//
// If specified type T matches recursive_wrapper<U>, then U; else T.
//

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template <typename T>
struct unwrap_recursive
{
    typedef T type;

    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,unwrap_recursive,(T))
};

template <typename T>
struct unwrap_recursive< recursive_wrapper<T> >
{
    typedef T type;

    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(1,unwrap_recursive,(T))
};

#else // defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template <typename T>
struct unwrap_recursive
    : mpl::eval_if<
          is_recursive_wrapper<T>
        , T
        , mpl::identity< T >
        >
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,unwrap_recursive,(T))
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION workaround

} // namespace boost

#include "cppcms_boost/type_traits/detail/bool_trait_undef.hpp"

#endif // BOOST_VARIANT_RECURSIVE_WRAPPER_FWD_HPP
