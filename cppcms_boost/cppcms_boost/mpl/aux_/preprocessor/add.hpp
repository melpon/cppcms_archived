
#ifndef CPPCMS_BOOST_MPL_AUX_PREPROCESSOR_ADD_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_PREPROCESSOR_ADD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: add.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/preprocessor.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)

#   include <cppcms_boost/mpl/aux_/preprocessor/tuple.hpp>

#if defined(CPPCMS_BOOST_MPL_CFG_BROKEN_PP_MACRO_EXPANSION)
#   include <cppcms_boost/preprocessor/cat.hpp>

#   define CPPCMS_BOOST_MPL_PP_ADD(i,j) \
    CPPCMS_BOOST_MPL_PP_ADD_DELAY(i,j) \
    /**/

#   define CPPCMS_BOOST_MPL_PP_ADD_DELAY(i,j) \
    CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_MPL_PP_TUPLE_11_ELEM_##i,CPPCMS_BOOST_MPL_PP_ADD_##j) \
    /**/
#else
#   define CPPCMS_BOOST_MPL_PP_ADD(i,j) \
    CPPCMS_BOOST_MPL_PP_ADD_DELAY(i,j) \
    /**/

#   define CPPCMS_BOOST_MPL_PP_ADD_DELAY(i,j) \
    CPPCMS_BOOST_MPL_PP_TUPLE_11_ELEM_##i CPPCMS_BOOST_MPL_PP_ADD_##j \
    /**/
#endif

#   define CPPCMS_BOOST_MPL_PP_ADD_0 (0,1,2,3,4,5,6,7,8,9,10)
#   define CPPCMS_BOOST_MPL_PP_ADD_1 (1,2,3,4,5,6,7,8,9,10,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_2 (2,3,4,5,6,7,8,9,10,0,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_3 (3,4,5,6,7,8,9,10,0,0,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_4 (4,5,6,7,8,9,10,0,0,0,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_5 (5,6,7,8,9,10,0,0,0,0,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_6 (6,7,8,9,10,0,0,0,0,0,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_7 (7,8,9,10,0,0,0,0,0,0,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_8 (8,9,10,0,0,0,0,0,0,0,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_9 (9,10,0,0,0,0,0,0,0,0,0)
#   define CPPCMS_BOOST_MPL_PP_ADD_10 (10,0,0,0,0,0,0,0,0,0,0)

#else

#   include <cppcms_boost/preprocessor/arithmetic/add.hpp>

#   define CPPCMS_BOOST_MPL_PP_ADD(i,j) \
    CPPCMS_BOOST_PP_ADD(i,j) \
    /**/
    
#endif 

#endif // BOOST_MPL_AUX_PREPROCESSOR_ADD_HPP_INCLUDED
