
#if !defined(CPPCMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef CPPCMS_BOOST_MPL_APPLY_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_APPLY_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: apply.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/apply_fwd.hpp>
#   include <cppcms_boost/mpl/apply_wrap.hpp>
#   include <cppcms_boost/mpl/placeholders.hpp>
#   include <cppcms_boost/mpl/lambda.hpp>
#   include <cppcms_boost/mpl/aux_/na.hpp>
#   include <cppcms_boost/mpl/aux_/lambda_support.hpp>
#endif

#include <cppcms_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)

#   define CPPCMS_BOOST_MPL_PREPROCESSED_HEADER apply.hpp
#   include <cppcms_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <cppcms_boost/mpl/limits/arity.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/default_params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/partial_spec_params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/enum.hpp>
#   include <cppcms_boost/mpl/aux_/config/lambda.hpp>
#   include <cppcms_boost/mpl/aux_/config/dtp.hpp>
#   include <cppcms_boost/mpl/aux_/nttp_decl.hpp>
#   include <cppcms_boost/mpl/aux_/config/eti.hpp>
#   include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#   include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#   include <cppcms_boost/preprocessor/comma_if.hpp>
#   include <cppcms_boost/preprocessor/inc.hpp>
#   include <cppcms_boost/preprocessor/iterate.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>

namespace cppcms_boost { namespace mpl {

// local macros, #undef-ined at the end of the header
#   define AUX778076_APPLY_PARAMS(param) \
    CPPCMS_BOOST_MPL_PP_PARAMS( \
          CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        ) \
    /**/

#   define AUX778076_APPLY_DEF_PARAMS(param, value) \
    CPPCMS_BOOST_MPL_PP_DEFAULT_PARAMS( \
          CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        , value \
        ) \
    /**/

#   define AUX778076_APPLY_N_PARAMS(n, param) \
    CPPCMS_BOOST_MPL_PP_PARAMS(n, param) \
    /**/

#   define AUX778076_APPLY_N_COMMA_PARAMS(n, param) \
    CPPCMS_BOOST_PP_COMMA_IF(n) \
    CPPCMS_BOOST_MPL_PP_PARAMS(n, param) \
    /**/

#   define AUX778076_APPLY_N_PARTIAL_SPEC_PARAMS(n, param, def) \
    CPPCMS_BOOST_PP_COMMA_IF(n) \
    CPPCMS_BOOST_MPL_PP_PARTIAL_SPEC_PARAMS(n, param, def) \
    /**/
    
#   define AUX778076_APPLY_N_SPEC_PARAMS(n, param) \
    CPPCMS_BOOST_MPL_PP_ENUM(CPPCMS_BOOST_PP_INC(n), param) \
    /**/


#define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, <cppcms_boost/mpl/apply.hpp>))
#include CPPCMS_BOOST_PP_ITERATE()

#   if !defined(CPPCMS_BOOST_MPL_CFG_NO_APPLY_TEMPLATE)
// real C++ version is already taken care of
#   if defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

namespace aux {
// apply_count_args
#define AUX778076_COUNT_ARGS_PREFIX apply
#define AUX778076_COUNT_ARGS_DEFAULT na
#define AUX778076_COUNT_ARGS_ARITY CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
#include <cppcms_boost/mpl/aux_/count_args.hpp>
}


template<
      typename F, AUX778076_APPLY_DEF_PARAMS(typename T, na)
    >
struct apply
    : aux::apply_chooser< 
          aux::apply_count_args< AUX778076_APPLY_PARAMS(T) >::value
        >::template result_< F, AUX778076_APPLY_PARAMS(T) >::type
{
};

#   endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   endif // BOOST_MPL_CFG_NO_APPLY_TEMPLATE

#   undef AUX778076_APPLY_N_SPEC_PARAMS
#   undef AUX778076_APPLY_N_PARTIAL_SPEC_PARAMS
#   undef AUX778076_APPLY_N_COMMA_PARAMS
#   undef AUX778076_APPLY_N_PARAMS
#   undef AUX778076_APPLY_DEF_PARAMS
#   undef AUX778076_APPLY_PARAMS

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_APPLY_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // BOOST_PP_IS_ITERATING
#if CPPCMS_BOOST_PP_ITERATION_DEPTH() == 1

#   define i_ CPPCMS_BOOST_PP_FRAME_ITERATION(1)

template<
      typename F AUX778076_APPLY_N_COMMA_PARAMS(i_, typename T)
    >
struct CPPCMS_BOOST_PP_CAT(apply,i_)
#if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
    : CPPCMS_BOOST_PP_CAT(apply_wrap,i_)< 
          typename lambda<F>::type
        AUX778076_APPLY_N_COMMA_PARAMS(i_, T)
        >
{
#else
{
    typedef typename CPPCMS_BOOST_PP_CAT(apply_wrap,i_)< 
          typename lambda<F>::type
        AUX778076_APPLY_N_COMMA_PARAMS(i_, T)
        >::type type;
#endif
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(
          CPPCMS_BOOST_PP_INC(i_)
        , CPPCMS_BOOST_PP_CAT(apply,i_)
        , (F AUX778076_APPLY_N_COMMA_PARAMS(i_,T))
        )
};


#if defined(CPPCMS_BOOST_MPL_CFG_MSVC_ETI_BUG)
/// workaround for ETI bug
template<>
struct CPPCMS_BOOST_PP_CAT(apply,i_)<AUX778076_APPLY_N_SPEC_PARAMS(i_, int)>
{
    typedef int type;
};
#endif

#   if !defined(CPPCMS_BOOST_MPL_CFG_NO_APPLY_TEMPLATE)
#   if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

#if i_ == CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
/// primary template (not a specialization!)
template<
      typename F AUX778076_APPLY_N_COMMA_PARAMS(i_, typename T)
    >
struct apply
    : CPPCMS_BOOST_PP_CAT(apply,i_)< F AUX778076_APPLY_N_COMMA_PARAMS(i_, T) >
{
};
#else
template<
      typename F AUX778076_APPLY_N_COMMA_PARAMS(i_, typename T)
    >
struct apply< F AUX778076_APPLY_N_PARTIAL_SPEC_PARAMS(i_, T, na) >
    : CPPCMS_BOOST_PP_CAT(apply,i_)< F AUX778076_APPLY_N_COMMA_PARAMS(i_, T) >
{
};
#endif

#   else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_APPLY_TEMPLATE)
namespace aux {

template<>
struct apply_chooser<i_>
{
    template<
          typename F, AUX778076_APPLY_PARAMS(typename T)
        >
    struct result_
    {
        typedef CPPCMS_BOOST_PP_CAT(apply,i_)<
              F AUX778076_APPLY_N_COMMA_PARAMS(i_, T)
            > type;
    };
};

} // namespace aux
#endif

#   endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   endif // BOOST_MPL_CFG_NO_APPLY_TEMPLATE

#   undef i_

#endif // BOOST_PP_ITERATION_DEPTH()
#endif // BOOST_PP_IS_ITERATING
