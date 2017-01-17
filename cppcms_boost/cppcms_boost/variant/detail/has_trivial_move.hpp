
// (C) Copyright Eric Friedman 2002-2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org for most recent version including documentation.

#ifndef CPPCMS_BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED
#define CPPCMS_BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED

#include "cppcms_boost/config.hpp" // for STATIC_CONSTANT
#include "cppcms_boost/type_traits/has_trivial_copy.hpp"
#include "cppcms_boost/type_traits/has_trivial_assign.hpp"

#include "cppcms_boost/mpl/and.hpp"
#include "cppcms_boost/mpl/or.hpp"

// should be the last #include
#include "cppcms_boost/variant/detail/bool_trait_def.hpp"

namespace cppcms_boost {
namespace detail { namespace variant {

// TRAIT: has_trivial_move

template <typename T>
struct has_trivial_move_impl
{
    CPPCMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            ::cppcms_boost::mpl::and_<
              has_trivial_copy<T>
            , has_trivial_assign<T>
            >::type::value
            )
        );
};

CPPCMS_BOOST_VARIANT_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move
    , T
    , (::cppcms_boost::detail::variant::has_trivial_move_impl<T>::value)
    )


// TRAIT: has_trivial_move_constructor

template <typename T>
struct has_trivial_move_constructor_impl
{
    CPPCMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            ::cppcms_boost::mpl::or_<
              has_trivial_move<T>
            , has_trivial_copy<T>
            >::type::value
            )
        );
};

CPPCMS_BOOST_VARIANT_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move_constructor
    , T
    , (::cppcms_boost::detail::variant::has_trivial_move_constructor_impl<T>::value)
    )


// TRAIT: has_trivial_move_assign

template <typename T>
struct has_trivial_move_assign_impl
{
    CPPCMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            ::cppcms_boost::mpl::or_<
              has_trivial_move<T>
            , has_trivial_assign<T>
            >::type::value
            )
        );
};

CPPCMS_BOOST_VARIANT_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move_assign
    , T
    , (::cppcms_boost::detail::variant::has_trivial_move_assign_impl<T>::value)
    )

}} // namespace detail::variant

CPPCMS_BOOST_VARIANT_TT_AUX_TRAIT_SUFFIX(1,::cppcms_boost::detail::variant::has_trivial_move)
CPPCMS_BOOST_VARIANT_TT_AUX_TRAIT_SUFFIX(1,::cppcms_boost::detail::variant::has_trivial_move_constructor)
CPPCMS_BOOST_VARIANT_TT_AUX_TRAIT_SUFFIX(1,::cppcms_boost::detail::variant::has_trivial_move_assign)

} // namespace boost

#include "cppcms_boost/variant/detail/bool_trait_undef.hpp"

#endif // BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED
