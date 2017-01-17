
#ifndef CPPCMS_BOOST_MPL_AUX_NA_SPEC_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_NA_SPEC_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: na_spec.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/lambda_fwd.hpp>
#   include <cppcms_boost/mpl/int.hpp>
#   include <cppcms_boost/mpl/bool.hpp>
#   include <cppcms_boost/mpl/aux_/na.hpp>
#   include <cppcms_boost/mpl/aux_/arity.hpp>
#   include <cppcms_boost/mpl/aux_/template_arity_fwd.hpp>
#endif

#include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#include <cppcms_boost/mpl/aux_/preprocessor/enum.hpp>
#include <cppcms_boost/mpl/aux_/preprocessor/def_params_tail.hpp>
#include <cppcms_boost/mpl/aux_/lambda_arity_param.hpp>
#include <cppcms_boost/mpl/aux_/config/dtp.hpp>
#include <cppcms_boost/mpl/aux_/config/eti.hpp>
#include <cppcms_boost/mpl/aux_/nttp_decl.hpp>
#include <cppcms_boost/mpl/aux_/config/ttp.hpp>
#include <cppcms_boost/mpl/aux_/config/lambda.hpp>
#include <cppcms_boost/mpl/aux_/config/overload_resolution.hpp>


#define CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) \
    CPPCMS_BOOST_MPL_PP_ENUM(i, na) \
/**/

#if defined(CPPCMS_BOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define CPPCMS_BOOST_MPL_AUX_NA_SPEC_ARITY(i, name) \
namespace aux { \
template< CPPCMS_BOOST_MPL_AUX_NTTP_DECL(int, N) > \
struct arity< \
          name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > \
        , N \
        > \
    : int_< CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY > \
{ \
}; \
} \
/**/
#else
#   define CPPCMS_BOOST_MPL_AUX_NA_SPEC_ARITY(i, name) /**/
#endif

#define CPPCMS_BOOST_MPL_AUX_NA_SPEC_MAIN(i, name) \
template<> \
struct name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > \
{ \
    template< \
          CPPCMS_BOOST_MPL_PP_PARAMS(i, typename T) \
        CPPCMS_BOOST_MPL_PP_NESTED_DEF_PARAMS_TAIL(i, typename T, na) \
        > \
    struct apply \
        : name< CPPCMS_BOOST_MPL_PP_PARAMS(i, T) > \
    { \
    }; \
}; \
/**/

#if defined(CPPCMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)
#   define CPPCMS_BOOST_MPL_AUX_NA_SPEC_LAMBDA(i, name) \
template<> \
struct lambda< \
      name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > \
    , void_ \
    , true_ \
    > \
{ \
    typedef false_ is_le; \
    typedef name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > type; \
}; \
template<> \
struct lambda< \
      name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > \
    , void_ \
    , false_ \
    > \
{ \
    typedef false_ is_le; \
    typedef name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > type; \
}; \
/**/
#else
#   define CPPCMS_BOOST_MPL_AUX_NA_SPEC_LAMBDA(i, name) \
template< typename Tag > \
struct lambda< \
      name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > \
    , Tag \
    CPPCMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(int_<-1>) \
    > \
{ \
    typedef false_ is_le; \
    typedef name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > result_; \
    typedef name< CPPCMS_BOOST_MPL_AUX_NA_PARAMS(i) > type; \
}; \
/**/
#endif

#if defined(CPPCMS_BOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING) \
    || defined(CPPCMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT) \
        && defined(CPPCMS_BOOST_MPL_CFG_BROKEN_OVERLOAD_RESOLUTION)
#   define CPPCMS_BOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(i, j, name) \
namespace aux { \
template< CPPCMS_BOOST_MPL_PP_PARAMS(j, typename T) > \
struct template_arity< \
          name< CPPCMS_BOOST_MPL_PP_PARAMS(j, T) > \
        > \
    : int_<j> \
{ \
}; \
\
template<> \
struct template_arity< \
          name< CPPCMS_BOOST_MPL_PP_ENUM(i, na) > \
        > \
    : int_<-1> \
{ \
}; \
} \
/**/
#else
#   define CPPCMS_BOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(i, j, name) /**/
#endif

#if defined(CPPCMS_BOOST_MPL_CFG_MSVC_ETI_BUG)
#   define CPPCMS_BOOST_MPL_AUX_NA_SPEC_ETI(i, name) \
template<> \
struct name< CPPCMS_BOOST_MPL_PP_ENUM(i, int) > \
{ \
    typedef int type; \
    enum { value = 0 }; \
}; \
/**/
#else
#   define CPPCMS_BOOST_MPL_AUX_NA_SPEC_ETI(i, name) /**/
#endif

#define CPPCMS_BOOST_MPL_AUX_NA_PARAM(param) param = na

#define CPPCMS_BOOST_MPL_AUX_NA_SPEC_NO_ETI(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_MAIN(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_LAMBDA(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_ARITY(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(i, i, name) \
/**/

#define CPPCMS_BOOST_MPL_AUX_NA_SPEC(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_NO_ETI(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_ETI(i, name) \
/**/

#define CPPCMS_BOOST_MPL_AUX_NA_SPEC2(i, j, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_MAIN(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_ETI(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_LAMBDA(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_ARITY(i, name) \
CPPCMS_BOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(i, j, name) \
/**/


#endif // BOOST_MPL_AUX_NA_SPEC_HPP_INCLUDED
