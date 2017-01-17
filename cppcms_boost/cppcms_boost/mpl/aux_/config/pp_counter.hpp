
#ifndef CPPCMS_BOOST_MPL_AUX_CONFIG_PP_COUNTER_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_CONFIG_PP_COUNTER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: pp_counter.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_AUX_PP_COUNTER)
#   include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#   if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, >= 1300)
#       define CPPCMS_BOOST_MPL_AUX_PP_COUNTER() __COUNTER__
#   else
#       define CPPCMS_BOOST_MPL_AUX_PP_COUNTER() __LINE__
#   endif
#endif

#endif // BOOST_MPL_AUX_CONFIG_PP_COUNTER_HPP_INCLUDED
