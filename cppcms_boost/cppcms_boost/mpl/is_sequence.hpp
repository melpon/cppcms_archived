
#ifndef CPPCMS_BOOST_MPL_IS_SEQUENCE_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_IS_SEQUENCE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: is_sequence.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/not.hpp>
#include <cppcms_boost/mpl/and.hpp>
#include <cppcms_boost/mpl/begin_end.hpp>
#include <cppcms_boost/mpl/if.hpp>
#include <cppcms_boost/mpl/bool.hpp>
#include <cppcms_boost/mpl/sequence_tag_fwd.hpp>
#include <cppcms_boost/mpl/identity.hpp>
#include <cppcms_boost/mpl/void.hpp>
#include <cppcms_boost/mpl/aux_/has_tag.hpp>
#include <cppcms_boost/mpl/aux_/has_begin.hpp>
#include <cppcms_boost/mpl/aux_/na_spec.hpp>
#include <cppcms_boost/mpl/aux_/lambda_support.hpp>
#include <cppcms_boost/mpl/aux_/config/eti.hpp>
#include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
#   include <cppcms_boost/mpl/aux_/msvc_is_class.hpp>
#elif CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1300)
#   include <cppcms_boost/type_traits/is_class.hpp>
#endif

#include <cppcms_boost/type_traits/is_same.hpp>

namespace cppcms_boost { namespace mpl {

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300)

namespace aux {

// agurt, 11/jun/03: 
// MSVC 6.5/7.0 fails if 'has_begin' is instantiated on a class type that has a
// 'begin' member that doesn't name a type; e.g. 'has_begin< std::vector<int> >'
// would fail; requiring 'T' to have _both_ 'tag' and 'begin' members workarounds
// the issue for most real-world cases
template< typename T > struct is_sequence_impl
    : and_<
          identity< aux::has_tag<T> >
        , identity< aux::has_begin<T> >
        >
{
};

} // namespace aux
        
template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(T)
    >
struct is_sequence
    : if_<
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
          aux::msvc_is_class<T> 
#else
          cppcms_boost::is_class<T> 
#endif
        , aux::is_sequence_impl<T>
        , bool_<false>
        >::type
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1, is_sequence, (T))
};

#elif defined(CPPCMS_BOOST_MPL_CFG_NO_HAS_XXX)

template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(T)
    >
struct is_sequence
    : bool_<false>
{
};

#else

template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(T)
    >
struct is_sequence
    : not_< is_same< typename begin<T>::type, void_ > >
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1, is_sequence, (T))
};

#endif // BOOST_MSVC

#if defined(CPPCMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG)
template<> struct is_sequence<int>
    : bool_<false>
{
};
#endif

CPPCMS_BOOST_MPL_AUX_NA_SPEC_NO_ETI(1, is_sequence)

}}

#endif // BOOST_MPL_IS_SEQUENCE_HPP_INCLUDED
