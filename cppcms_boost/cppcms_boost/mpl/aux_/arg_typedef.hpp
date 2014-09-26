
#ifndef CPPCMS_BOOST_MPL_AUX_ARG_TYPEDEF_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_ARG_TYPEDEF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: arg_typedef.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/lambda.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#if defined(CPPCMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT) \
    || CPPCMS_BOOST_WORKAROUND(__DMC__, CPPCMS_BOOST_TESTED_AT(0x840))
    
#   define CPPCMS_BOOST_MPL_AUX_ARG_TYPEDEF(T, name) typedef T name;

#else

#   define CPPCMS_BOOST_MPL_AUX_ARG_TYPEDEF(T, name) /**/

#endif

#endif // BOOST_MPL_AUX_ARG_TYPEDEF_HPP_INCLUDED
