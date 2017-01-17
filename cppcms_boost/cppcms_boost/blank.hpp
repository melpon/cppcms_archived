//-----------------------------------------------------------------------------
// boost blank.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_BLANK_HPP
#define CPPCMS_BOOST_BLANK_HPP

#include "cppcms_boost/blank_fwd.hpp"

#if !defined(CPPCMS_BOOST_NO_IOSTREAM)
#include <iosfwd> // for std::basic_ostream forward declare
#include "cppcms_boost/detail/templated_streams.hpp"
#endif // BOOST_NO_IOSTREAM

#include "cppcms_boost/mpl/bool.hpp"
#include "cppcms_boost/type_traits/is_empty.hpp"
#include "cppcms_boost/type_traits/is_pod.hpp"
#include "cppcms_boost/type_traits/is_stateless.hpp"

namespace cppcms_boost {

struct blank
{
};

// type traits specializations
//

template <>
struct is_pod< blank >
    : mpl::true_
{
};

template <>
struct is_empty< blank >
    : mpl::true_
{
};

template <>
struct is_stateless< blank >
    : mpl::true_
{
};

// relational operators
//

inline bool operator==(const blank&, const blank&)
{
    return true;
}

inline bool operator<=(const blank&, const blank&)
{
    return true;
}

inline bool operator>=(const blank&, const blank&)
{
    return true;
}

inline bool operator!=(const blank&, const blank&)
{
    return false;
}

inline bool operator<(const blank&, const blank&)
{
    return false;
}

inline bool operator>(const blank&, const blank&)
{
    return false;
}

// streaming support
//
#if !defined(CPPCMS_BOOST_NO_IOSTREAM)

CPPCMS_BOOST_TEMPLATED_STREAM_TEMPLATE(E,T)
inline CPPCMS_BOOST_TEMPLATED_STREAM(ostream, E,T)& operator<<(
      CPPCMS_BOOST_TEMPLATED_STREAM(ostream, E,T)& out
    , const blank&
    )
{
    // (output nothing)
    return out;
}

#endif // BOOST_NO_IOSTREAM

} // namespace boost

#endif // BOOST_BLANK_HPP
