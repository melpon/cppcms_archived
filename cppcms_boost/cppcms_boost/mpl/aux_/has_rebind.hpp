
#ifndef CPPCMS_BOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: has_rebind.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#include <cppcms_boost/mpl/aux_/config/intel.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#if CPPCMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(CPPCMS_BOOST_INTEL_CXX_VERSION)
#   include <cppcms_boost/mpl/has_xxx.hpp>
#elif CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
#   include <cppcms_boost/mpl/has_xxx.hpp>
#   include <cppcms_boost/mpl/if.hpp>
#   include <cppcms_boost/mpl/bool.hpp>
#   include <cppcms_boost/mpl/aux_/msvc_is_class.hpp>
#elif CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610))
#   include <cppcms_boost/mpl/if.hpp>
#   include <cppcms_boost/mpl/bool.hpp>
#   include <cppcms_boost/mpl/aux_/yes_no.hpp>
#   include <cppcms_boost/mpl/aux_/config/static_constant.hpp>
#   include <cppcms_boost/type_traits/is_class.hpp>
#else
#   include <cppcms_boost/mpl/aux_/type_wrapper.hpp>
#   include <cppcms_boost/mpl/aux_/yes_no.hpp>
#   include <cppcms_boost/mpl/aux_/config/static_constant.hpp>
#endif

namespace cppcms_boost { namespace mpl { namespace aux {

#if CPPCMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(CPPCMS_BOOST_INTEL_CXX_VERSION)

CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_rebind, rebind, false)

#elif CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)

CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_rebind_impl, rebind, false)

template< typename T >
struct has_rebind
    : if_< 
          msvc_is_class<T>
        , has_rebind_impl<T>
        , bool_<false>
        >::type
{
};

#else // the rest

template< typename T > struct has_rebind_tag {};
no_tag operator|(has_rebind_tag<int>, void const volatile*);

#   if !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610))
template< typename T >
struct has_rebind
{
    static has_rebind_tag<T>* get();
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = 
          sizeof(has_rebind_tag<int>() | get()) == sizeof(yes_tag)
        );
};
#   else // __BORLANDC__
template< typename T >
struct has_rebind_impl
{
    static T* get();
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = 
          sizeof(has_rebind_tag<int>() | get()) == sizeof(yes_tag)
        );
};

template< typename T >
struct has_rebind
    : if_< 
          is_class<T>
        , has_rebind_impl<T>
        , bool_<false>
        >::type
{
};
#   endif // __BORLANDC__

#endif

}}}

#endif // BOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED
