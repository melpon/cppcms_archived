
#if !defined(CPPCMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef CPPCMS_BOOST_MPL_APPLY_FWD_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_APPLY_FWD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: apply_fwd.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/aux_/na.hpp>
#endif

#include <cppcms_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)

#   define CPPCMS_BOOST_MPL_PREPROCESSED_HEADER apply_fwd.hpp
#   include <cppcms_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <cppcms_boost/mpl/limits/arity.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/default_params.hpp>
#   include <cppcms_boost/mpl/aux_/config/ctps.hpp>
#   include <cppcms_boost/mpl/aux_/nttp_decl.hpp>

#   include <cppcms_boost/preprocessor/comma_if.hpp>
#   include <cppcms_boost/preprocessor/iterate.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>

// agurt, 15/jan/02: top-level 'apply' template gives an ICE on MSVC
// (for known reasons)
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
#   define CPPCMS_BOOST_MPL_CFG_NO_APPLY_TEMPLATE
#endif

namespace cppcms_boost { namespace mpl {

// local macro, #undef-ined at the end of the header
#   define AUX778076_APPLY_DEF_PARAMS(param, value) \
    CPPCMS_BOOST_MPL_PP_DEFAULT_PARAMS( \
          CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        , value \
        ) \
    /**/

#   define AUX778076_APPLY_N_COMMA_PARAMS(n, param) \
    CPPCMS_BOOST_PP_COMMA_IF(n) \
    CPPCMS_BOOST_MPL_PP_PARAMS(n, param) \
    /**/

#   if !defined(CPPCMS_BOOST_MPL_CFG_NO_APPLY_TEMPLATE)

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
// forward declaration
template<
      typename F, AUX778076_APPLY_DEF_PARAMS(typename T, na)
    >
struct apply;
#else
namespace aux {
template< CPPCMS_BOOST_AUX_NTTP_DECL(int, arity_) > struct apply_chooser;
}
#endif

#   endif // BOOST_MPL_CFG_NO_APPLY_TEMPLATE

#define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, <cppcms_boost/mpl/apply_fwd.hpp>))
#include CPPCMS_BOOST_PP_ITERATE()


#   undef AUX778076_APPLY_N_COMMA_PARAMS
#   undef AUX778076_APPLY_DEF_PARAMS

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_APPLY_FWD_HPP_INCLUDED

///// iteration

#else
#define i_ CPPCMS_BOOST_PP_FRAME_ITERATION(1)

template<
      typename F AUX778076_APPLY_N_COMMA_PARAMS(i_, typename T)
    >
struct CPPCMS_BOOST_PP_CAT(apply,i_);

#undef i_
#endif // BOOST_PP_IS_ITERATING
