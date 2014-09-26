//-----------------------------------------------------------------------------
// boost variant/recursive_variant.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_VARIANT_RECURSIVE_VARIANT_HPP
#define CPPCMS_BOOST_VARIANT_RECURSIVE_VARIANT_HPP

#include "cppcms_boost/variant/variant_fwd.hpp"
#include "cppcms_boost/variant/detail/enable_recursive.hpp"
#include "cppcms_boost/variant/detail/substitute_fwd.hpp"
#include "cppcms_boost/variant/detail/make_variant_list.hpp"
#include "cppcms_boost/variant/detail/over_sequence.hpp"

#include "cppcms_boost/mpl/aux_/lambda_arity_param.hpp"

#if !defined(CPPCMS_BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT)
#   include "cppcms_boost/mpl/eval_if.hpp"
#   include "cppcms_boost/mpl/identity.hpp"
#   include "cppcms_boost/mpl/protect.hpp"
#   include "cppcms_boost/mpl/transform.hpp"
#else
#   include "cppcms_boost/preprocessor/cat.hpp"
#   include "cppcms_boost/preprocessor/repeat.hpp"
#endif

#include "cppcms_boost/mpl/bool.hpp"
#include "cppcms_boost/mpl/is_sequence.hpp"
#include "cppcms_boost/variant/variant.hpp"

namespace cppcms_boost {

namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction specialization substitute
//
// Handles embedded variant types when substituting for recursive_variant_.
//

#if !defined(CPPCMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

template <
      CPPCMS_BOOST_VARIANT_ENUM_PARAMS(typename T)
    , typename RecursiveVariant
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(typename Arity)
    >
struct substitute<
      ::cppcms_boost::variant<
          recursive_flag< T0 >
        , CPPCMS_BOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        >
    , RecursiveVariant
    , ::cppcms_boost::recursive_variant_
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(Arity)
    >
{
    typedef ::cppcms_boost::variant<
          recursive_flag< T0 >
        , CPPCMS_BOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        > type;
};

template <
      CPPCMS_BOOST_VARIANT_ENUM_PARAMS(typename T)
    , typename RecursiveVariant
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(typename Arity)
    >
struct substitute<
      ::cppcms_boost::variant< CPPCMS_BOOST_VARIANT_ENUM_PARAMS(T) >
    , RecursiveVariant
    , ::cppcms_boost::recursive_variant_
      CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(Arity)
    >
{

#if !defined(CPPCMS_BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT)

private: // helpers, for metafunction result (below)

    typedef typename mpl::eval_if<
          ::cppcms_boost::detail::variant::is_over_sequence<T0>
        , mpl::identity< T0 >
        , make_variant_list< CPPCMS_BOOST_VARIANT_ENUM_PARAMS(T) >
        >::type initial_types;

    typedef typename mpl::transform<
          initial_types
        , mpl::protect< quoted_enable_recursive<RecursiveVariant,mpl::true_> >
        >::type types;

public: // metafunction result

    typedef ::cppcms_boost::variant< types > type;

#else // defined(BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT)

private: // helpers, for metafunction result (below)

    #define CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS(z,N,_)  \
        typedef typename enable_recursive<   \
              CPPCMS_BOOST_PP_CAT(T,N)              \
            , RecursiveVariant               \
            , mpl::true_                     \
            >::type CPPCMS_BOOST_PP_CAT(wknd_T,N);  \
        /**/

    CPPCMS_BOOST_PP_REPEAT(
          CPPCMS_BOOST_VARIANT_LIMIT_TYPES
        , CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS
        , _
        )

    #undef CPPCMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS

public: // metafunction result

    typedef ::cppcms_boost::variant< CPPCMS_BOOST_VARIANT_ENUM_PARAMS(wknd_T) > type;

#endif // BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT workaround

};

#else // defined(BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

//
// no specializations: embedded variants unsupported on these compilers!
//

#endif // !defined(BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

}} // namespace detail::variant

///////////////////////////////////////////////////////////////////////////////
// metafunction make_recursive_variant
//
// See docs and boost/variant/variant_fwd.hpp for more information.
//
template < CPPCMS_BOOST_VARIANT_ENUM_PARAMS(typename T) >
struct make_recursive_variant
{
public: // metafunction result

    typedef cppcms_boost::variant<
          detail::variant::recursive_flag< T0 >
        , CPPCMS_BOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        > type;

};

///////////////////////////////////////////////////////////////////////////////
// metafunction make_recursive_variant_over
//
// See docs and boost/variant/variant_fwd.hpp for more information.
//
template <typename Types>
struct make_recursive_variant_over
{
private: // precondition assertions

#if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300)
    CPPCMS_BOOST_STATIC_ASSERT(( ::cppcms_boost::mpl::is_sequence<Types>::value ));
#endif

public: // metafunction result

    typedef typename make_recursive_variant<
          detail::variant::over_sequence< Types >
        >::type type;

};

} // namespace boost

#endif // BOOST_VARIANT_RECURSIVE_VARIANT_HPP
