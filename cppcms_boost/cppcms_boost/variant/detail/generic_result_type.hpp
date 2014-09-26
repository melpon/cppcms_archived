//-----------------------------------------------------------------------------
// boost variant/detail/generic_result_type.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_VARIANT_DETAIL_GENERIC_RESULT_TYPE_HPP
#define CPPCMS_BOOST_VARIANT_DETAIL_GENERIC_RESULT_TYPE_HPP

#include "cppcms_boost/config.hpp"

//////////////////////////////////////////////////////////////////////////
// (workaround) macro BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE
//
// On compilers with BOOST_NO_VOID_RETURNS, this macro provides a route
// to a single syntax for dealing with template functions that may (but
// not necessarily) return nothing (i.e. void).
//
// BOOST_VARIANT_AUX_RETURN_VOID provided for compilers w/ (erroneous?)
// warnings about non-void functions not returning a value.
//

#if !defined(CPPCMS_BOOST_NO_VOID_RETURNS)

#define CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(T) \
    T   \
    /**/

#define CPPCMS_BOOST_VARIANT_AUX_RETURN_VOID  \
    /**/

#define CPPCMS_BOOST_VARIANT_AUX_RETURN_VOID_TYPE \
    void    \
    /**/

#else // defined(BOOST_NO_VOID_RETURNS)

namespace cppcms_boost {
namespace detail { namespace variant {

struct fake_return_void
{
    fake_return_void()
    {
    }

    template <typename T>
    fake_return_void(const T&)
    {
    }
};

template <typename T>
struct no_void_returns_helper
{
    typedef T type;
};

template <>
struct no_void_returns_helper<void>
{
    typedef fake_return_void type;
};

}} // namespace detail::variant
} // namespace boost

#define CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(T) \
    CPPCMS_BOOST_DEDUCED_TYPENAME                                           \
        ::cppcms_boost::detail::variant::no_void_returns_helper< T >::type  \
    /**/

#define CPPCMS_BOOST_VARIANT_AUX_RETURN_VOID  \
    return ::cppcms_boost::detail::variant::fake_return_void()     \
    /**/

#define CPPCMS_BOOST_VARIANT_AUX_RETURN_VOID_TYPE  \
    ::cppcms_boost::detail::variant::fake_return_void

#endif // BOOST_NO_VOID_RETURNS workaround

#endif // BOOST_VARIANT_DETAIL_GENERIC_RESULT_TYPE_HPP
