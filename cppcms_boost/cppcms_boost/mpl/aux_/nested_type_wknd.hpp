
#ifndef CPPCMS_BOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: nested_type_wknd.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/gcc.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MPL_CFG_GCC, CPPCMS_BOOST_TESTED_AT(0x0302)) \
    || CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x561)) \
    || CPPCMS_BOOST_WORKAROUND(__SUNPRO_CC, CPPCMS_BOOST_TESTED_AT(0x530)) \
    || CPPCMS_BOOST_WORKAROUND(__DMC__, CPPCMS_BOOST_TESTED_AT(0x840))

namespace cppcms_boost { namespace mpl { namespace aux {
template< typename T > struct nested_type_wknd
    : T::type
{
};
}}}

#if CPPCMS_BOOST_WORKAROUND(__DMC__, CPPCMS_BOOST_TESTED_AT(0x840))
#   define CPPCMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T) \
    aux::nested_type_wknd<T> \
/**/
#else
#   define CPPCMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T) \
    ::cppcms_boost::mpl::aux::nested_type_wknd<T> \
/**/
#endif

#else // !BOOST_MPL_CFG_GCC et al.

#   define CPPCMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T) T::type

#endif 

#endif // BOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED
