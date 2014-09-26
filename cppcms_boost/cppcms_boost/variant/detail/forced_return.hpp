//-----------------------------------------------------------------------------
// boost variant/detail/forced_return.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_VARIANT_DETAIL_FORCED_RETURN_HPP
#define CPPCMS_BOOST_VARIANT_DETAIL_FORCED_RETURN_HPP

#include "cppcms_boost/config.hpp"
#include "cppcms_boost/variant/detail/generic_result_type.hpp"
#include "cppcms_boost/assert.hpp"

#if !defined(CPPCMS_BOOST_MSVC) && !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#   include "cppcms_boost/type_traits/remove_reference.hpp"
#endif

namespace cppcms_boost {
namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) function template forced_return
//
// Logical error to permit invocation at runtime, but (artificially) satisfies
// compile-time requirement of returning a result value.
//

#if !defined(CPPCMS_BOOST_MSVC)                                \
 && !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)  \
 && !defined(CPPCMS_BOOST_NO_VOID_RETURNS)

// "standard" implementation:

template <typename T>
inline T forced_return( CPPCMS_BOOST_EXPLICIT_TEMPLATE_TYPE(T) )
{
    // logical error: should never be here! (see above)
    CPPCMS_BOOST_ASSERT(false);

    typedef typename cppcms_boost::remove_reference<T>::type basic_type;
    basic_type* dummy = 0;
    return *static_cast< basic_type* >(dummy);
}

template <>
inline void forced_return<void>( CPPCMS_BOOST_EXPLICIT_TEMPLATE_TYPE_SPEC(void) )
{
    // logical error: should never be here! (see above)
    CPPCMS_BOOST_ASSERT(false);
}

#elif !defined(CPPCMS_BOOST_MSVC)

// workaround implementation
//
// TODO: Determine the most efficient way to handle this -- as below? by
// throwing? by recursive call to forced_return itself? etc.
//

template <typename T>
inline
    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(T)
forced_return( CPPCMS_BOOST_EXPLICIT_TEMPLATE_TYPE(T) )
{
    // logical error: should never be here! (see above)
    CPPCMS_BOOST_ASSERT(false);

    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(T) (*dummy)() = 0;
    return dummy();
}

#else // defined(BOOST_MSVC)

// msvc-specific implementation
//
// Leverages __declspec(noreturn) for optimized implementation.
//

__declspec(noreturn)
inline void forced_return_no_return() {};

template <typename T>
inline
    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(T)
forced_return( CPPCMS_BOOST_EXPLICIT_TEMPLATE_TYPE(T) )
{
    // logical error: should never be here! (see above)
    CPPCMS_BOOST_ASSERT(false);

    forced_return_no_return();
}

#endif // BOOST_MSVC optimization

}} // namespace detail::variant
} // namespace boost

#endif // BOOST_VARIANT_DETAIL_FORCED_RETURN_HPP
