//-----------------------------------------------------------------------------
// boost variant/detail/cast_storage.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_VARIANT_DETAIL_CAST_STORAGE_HPP
#define CPPCMS_BOOST_VARIANT_DETAIL_CAST_STORAGE_HPP

#include "cppcms_boost/config.hpp"

namespace cppcms_boost {
namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) function template cast_storage
//
// Casts the given storage to the specified type, but with qualification.
//

template <typename T>
inline T& cast_storage(
      void* storage
      CPPCMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(T)
    )
{
    return *static_cast<T*>(storage);
}

template <typename T>
inline const T& cast_storage(
      const void* storage
      CPPCMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(T)
    )
{
    return *static_cast<const T*>(storage);
}

}} // namespace detail::variant
} // namespace boost

#endif // BOOST_VARIANT_DETAIL_CAST_STORAGE_HPP
