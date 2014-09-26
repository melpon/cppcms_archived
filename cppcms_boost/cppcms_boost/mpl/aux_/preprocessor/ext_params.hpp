
#ifndef CPPCMS_BOOST_MPL_AUX_PREPROCESSOR_EXT_PARAMS_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_PREPROCESSOR_EXT_PARAMS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: ext_params.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/preprocessor.hpp>

// BOOST_MPL_PP_EXT_PARAMS(2,2,T): <nothing>
// BOOST_MPL_PP_EXT_PARAMS(2,3,T): T2
// BOOST_MPL_PP_EXT_PARAMS(2,4,T): T2, T3
// BOOST_MPL_PP_EXT_PARAMS(2,n,T): T2, T3, .., Tn-1

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)

#   include <cppcms_boost/mpl/aux_/preprocessor/filter_params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/sub.hpp>

#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS(i,j,p) \
    CPPCMS_BOOST_MPL_PP_EXT_PARAMS_DELAY_1(i,CPPCMS_BOOST_MPL_PP_SUB(j,i),p) \
    /**/

#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_DELAY_1(i,n,p) \
    CPPCMS_BOOST_MPL_PP_EXT_PARAMS_DELAY_2(i,n,p) \
    /**/

#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_DELAY_2(i,n,p) \
    CPPCMS_BOOST_MPL_PP_EXT_PARAMS_##i(n,p) \
    /**/

#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_1(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##1,p##2,p##3,p##4,p##5,p##6,p##7,p##8,p##9)
#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_2(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##2,p##3,p##4,p##5,p##6,p##7,p##8,p##9,p1)
#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_3(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##3,p##4,p##5,p##6,p##7,p##8,p##9,p1,p2)
#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_4(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##4,p##5,p##6,p##7,p##8,p##9,p1,p2,p3)
#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_5(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##5,p##6,p##7,p##8,p##9,p1,p2,p3,p4)
#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_6(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##6,p##7,p##8,p##9,p1,p2,p3,p4,p5)
#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_7(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##7,p##8,p##9,p1,p2,p3,p4,p5,p6)
#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_8(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##8,p##9,p1,p2,p3,p4,p5,p6,p7)
#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS_9(i,p) CPPCMS_BOOST_MPL_PP_FILTER_PARAMS_##i(p##9,p1,p2,p3,p4,p5,p6,p7,p8)

#else

#   include <cppcms_boost/preprocessor/arithmetic/add.hpp>
#   include <cppcms_boost/preprocessor/arithmetic/sub.hpp>
#   include <cppcms_boost/preprocessor/comma_if.hpp>
#   include <cppcms_boost/preprocessor/repeat.hpp>
#   include <cppcms_boost/preprocessor/tuple/elem.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>

#   define CPPCMS_BOOST_MPL_PP_AUX_EXT_PARAM_FUNC(unused, i, op) \
    CPPCMS_BOOST_PP_COMMA_IF(i) \
    CPPCMS_BOOST_PP_CAT( \
          CPPCMS_BOOST_PP_TUPLE_ELEM(2,1,op) \
        , CPPCMS_BOOST_PP_ADD_D(1, i, CPPCMS_BOOST_PP_TUPLE_ELEM(2,0,op)) \
        ) \
    /**/

#   define CPPCMS_BOOST_MPL_PP_EXT_PARAMS(i, j, param) \
    CPPCMS_BOOST_PP_REPEAT( \
          CPPCMS_BOOST_PP_SUB_D(1,j,i) \
        , CPPCMS_BOOST_MPL_PP_AUX_EXT_PARAM_FUNC \
        , (i,param) \
        ) \
    /**/

#endif

#endif // BOOST_MPL_AUX_PREPROCESSOR_EXT_PARAMS_HPP_INCLUDED
