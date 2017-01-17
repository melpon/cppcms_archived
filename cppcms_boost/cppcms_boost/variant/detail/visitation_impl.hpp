//-----------------------------------------------------------------------------
// boost variant/detail/visitation_impl.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_VARIANT_DETAIL_VISITATION_IMPL_HPP
#define CPPCMS_BOOST_VARIANT_DETAIL_VISITATION_IMPL_HPP

#include "cppcms_boost/config.hpp"

#include "cppcms_boost/variant/detail/backup_holder.hpp"
#include "cppcms_boost/variant/detail/cast_storage.hpp"
#include "cppcms_boost/variant/detail/forced_return.hpp"
#include "cppcms_boost/variant/detail/generic_result_type.hpp"

#include "cppcms_boost/assert.hpp"
#include "cppcms_boost/mpl/eval_if.hpp"
#include "cppcms_boost/mpl/bool.hpp"
#include "cppcms_boost/mpl/identity.hpp"
#include "cppcms_boost/mpl/int.hpp"
#include "cppcms_boost/mpl/next.hpp"
#include "cppcms_boost/mpl/deref.hpp"
#include "cppcms_boost/mpl/or.hpp"
#include "cppcms_boost/preprocessor/cat.hpp"
#include "cppcms_boost/preprocessor/inc.hpp"
#include "cppcms_boost/preprocessor/repeat.hpp"
#include "cppcms_boost/type_traits/is_same.hpp"
#include "cppcms_boost/type_traits/has_nothrow_copy.hpp"
#include "cppcms_boost/variant/detail/has_nothrow_move.hpp"


///////////////////////////////////////////////////////////////////////////////
// BOOST_VARIANT_VISITATION_UNROLLING_LIMIT
//
// Unrolls variant's visitation mechanism to reduce template instantiation
// and potentially increase runtime performance. (TODO: Investigate further.)
//
#if !defined(CPPCMS_BOOST_VARIANT_VISITATION_UNROLLING_LIMIT)
#   define CPPCMS_BOOST_VARIANT_VISITATION_UNROLLING_LIMIT   \
        CPPCMS_BOOST_VARIANT_LIMIT_TYPES
#endif

namespace cppcms_boost {
namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) class apply_visitor_unrolled
//
// Tag type indicates when visitation_impl is unrolled.
//
struct apply_visitor_unrolled {};

///////////////////////////////////////////////////////////////////////////////
// (detail) class template visitation_impl_step
//
// "Never ending" iterator range facilitates visitation_impl unrolling.
//

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template <typename Iter, typename LastIter>
struct visitation_impl_step
{
    typedef typename mpl::deref<Iter>::type type;

    typedef typename mpl::next<Iter>::type next_iter;
    typedef visitation_impl_step<
          next_iter, LastIter
        > next;
};

template <typename LastIter>
struct visitation_impl_step< LastIter,LastIter >
{
    typedef apply_visitor_unrolled type;
    typedef visitation_impl_step next;
};

#else // defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template <typename Iter, typename LastIter>
struct visitation_impl_step
{
    typedef typename mpl::eval_if<
          is_same<Iter, LastIter>
        , mpl::identity<apply_visitor_unrolled>
        , Iter
        >::type type;

    typedef typename mpl::eval_if<
          is_same<type, apply_visitor_unrolled> //is_same<Iter, LastIter>
        , mpl::identity<LastIter>
        , mpl::next<Iter>
        >::type next_iter;

    typedef visitation_impl_step<
          next_iter, LastIter
        > next;
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION workaround

///////////////////////////////////////////////////////////////////////////////
// (detail) function template visitation_impl_invoke
//
// Invokes the given visitor on the specified type in the given storage.
//

template <typename Visitor, typename VoidPtrCV, typename T>
inline
    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
visitation_impl_invoke_impl(
      int, Visitor& visitor, VoidPtrCV storage, T*
    , mpl::true_// never_uses_backup
    )
{
    return visitor.internal_visit(
          cast_storage<T>(storage), 1L
        );
}

template <typename Visitor, typename VoidPtrCV, typename T>
inline
    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
visitation_impl_invoke_impl(
      int internal_which, Visitor& visitor, VoidPtrCV storage, T*
    , mpl::false_// never_uses_backup
    )
{
    if (internal_which >= 0)
    {
        return visitor.internal_visit(
              cast_storage<T>(storage), 1L
            );
    }
    else
    {
        return visitor.internal_visit(
              cast_storage< backup_holder<T> >(storage), 1L
            );
    }
}

template <typename Visitor, typename VoidPtrCV, typename T, typename NoBackupFlag>
inline
    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
visitation_impl_invoke(
      int internal_which, Visitor& visitor, VoidPtrCV storage, T* t
    , NoBackupFlag
    , int
    )
{
    typedef typename mpl::or_<
          NoBackupFlag
        , has_nothrow_move_constructor<T>
        , has_nothrow_copy<T>
        >::type never_uses_backup;

    return visitation_impl_invoke_impl(
          internal_which, visitor, storage, t
        , never_uses_backup()
        );
}

template <typename Visitor, typename VoidPtrCV, typename NBF>
inline
    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
visitation_impl_invoke(int, Visitor&, VoidPtrCV, apply_visitor_unrolled*, NBF, long)
{
    // should never be here at runtime:
    CPPCMS_BOOST_ASSERT(false);
    typedef typename Visitor::result_type result_type;
    return ::cppcms_boost::detail::variant::forced_return< result_type >();
}

///////////////////////////////////////////////////////////////////////////////
// (detail) function template visitation_impl
//
// Invokes the given visitor on the type in the given variant storage.
//

template <
      typename W, typename S
    , typename Visitor, typename VPCV
    , typename NBF
    >
inline
    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
visitation_impl(
      int, int, Visitor&, VPCV
    , mpl::true_ // is_apply_visitor_unrolled
    , NBF, W* = 0, S* = 0
    )
{
    // should never be here at runtime:
    CPPCMS_BOOST_ASSERT(false);
    typedef typename Visitor::result_type result_type;
    return ::cppcms_boost::detail::variant::forced_return< result_type >();
}

template <
      typename Which, typename step0
    , typename Visitor, typename VoidPtrCV
    , typename NoBackupFlag
    >
inline
    CPPCMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
visitation_impl(
      const int internal_which, const int logical_which
    , Visitor& visitor, VoidPtrCV storage
    , mpl::false_ // is_apply_visitor_unrolled
    , NoBackupFlag no_backup_flag
    , Which* = 0, step0* = 0
    )
{
    // Typedef apply_visitor_unrolled steps and associated types...
#   define CPPCMS_BOOST_VARIANT_AUX_APPLY_VISITOR_STEP_TYPEDEF(z, N, _) \
    typedef typename CPPCMS_BOOST_PP_CAT(step,N)::type CPPCMS_BOOST_PP_CAT(T,N); \
    typedef typename CPPCMS_BOOST_PP_CAT(step,N)::next \
        CPPCMS_BOOST_PP_CAT(step, CPPCMS_BOOST_PP_INC(N)); \
    /**/

    CPPCMS_BOOST_PP_REPEAT(
          CPPCMS_BOOST_VARIANT_VISITATION_UNROLLING_LIMIT
        , CPPCMS_BOOST_VARIANT_AUX_APPLY_VISITOR_STEP_TYPEDEF
        , _
        )

#   undef CPPCMS_BOOST_VARIANT_AUX_APPLY_VISITOR_STEP_TYPEDEF

    // ...switch on the target which-index value...
    switch (logical_which)
    {

    // ...applying the appropriate case:
#   define CPPCMS_BOOST_VARIANT_AUX_APPLY_VISITOR_STEP_CASE(z, N, _) \
    case (Which::value + (N)): \
        return visitation_impl_invoke( \
              internal_which, visitor, storage \
            , static_cast<CPPCMS_BOOST_PP_CAT(T,N)*>(0) \
            , no_backup_flag, 1L \
            ); \
    /**/

    CPPCMS_BOOST_PP_REPEAT(
          CPPCMS_BOOST_VARIANT_VISITATION_UNROLLING_LIMIT
        , CPPCMS_BOOST_VARIANT_AUX_APPLY_VISITOR_STEP_CASE
        , _
        )

#   undef CPPCMS_BOOST_VARIANT_AUX_APPLY_VISITOR_STEP_CASE

    }

    // If not handled in this iteration, continue unrolling:
    typedef mpl::int_<
          Which::value + (CPPCMS_BOOST_VARIANT_VISITATION_UNROLLING_LIMIT)
        > next_which;

    typedef CPPCMS_BOOST_PP_CAT(step, CPPCMS_BOOST_VARIANT_VISITATION_UNROLLING_LIMIT)
        next_step;

    typedef typename next_step::type next_type;
    typedef typename is_same< next_type,apply_visitor_unrolled >::type
        is_apply_visitor_unrolled;

    return visitation_impl(
          internal_which, logical_which
        , visitor, storage
        , is_apply_visitor_unrolled()
        , no_backup_flag
        , static_cast<next_which*>(0), static_cast<next_step*>(0)
        );
}

}} // namespace detail::variant
} // namespace boost

#endif // BOOST_VARIANT_DETAIL_VISITATION_IMPL_HPP
