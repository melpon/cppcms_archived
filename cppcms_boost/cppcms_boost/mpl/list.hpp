
#ifndef CPPCMS_BOOST_MPL_LIST_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_LIST_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: list.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/limits/list.hpp>
#   include <cppcms_boost/mpl/aux_/na.hpp>
#   include <cppcms_boost/mpl/aux_/config/preprocessor.hpp>

#   include <cppcms_boost/preprocessor/inc.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>
#   include <cppcms_boost/preprocessor/stringize.hpp>

#if !defined(CPPCMS_BOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_LIST_HEADER \
    CPPCMS_BOOST_PP_CAT(list,CPPCMS_BOOST_MPL_LIMIT_LIST_SIZE).hpp \
    /**/
#else
#   define AUX778076_LIST_HEADER \
    CPPCMS_BOOST_PP_CAT(list,CPPCMS_BOOST_MPL_LIMIT_LIST_SIZE)##.hpp \
    /**/
#endif

#   include CPPCMS_BOOST_PP_STRINGIZE(cppcms_boost/mpl/list/AUX778076_LIST_HEADER)
#   undef AUX778076_LIST_HEADER
#endif

#include <cppcms_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)

#   define CPPCMS_BOOST_MPL_PREPROCESSED_HEADER list.hpp
#   include <cppcms_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <cppcms_boost/mpl/limits/list.hpp>

#   define AUX778076_SEQUENCE_NAME list
#   define AUX778076_SEQUENCE_LIMIT CPPCMS_BOOST_MPL_LIMIT_LIST_SIZE
#   include <cppcms_boost/mpl/aux_/sequence_wrapper.hpp>

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_LIST_HPP_INCLUDED
