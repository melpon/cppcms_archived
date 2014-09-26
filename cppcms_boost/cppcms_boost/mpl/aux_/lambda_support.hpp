
#ifndef CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: lambda_support.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/lambda.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)

#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) /**/
#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i,name,params) /**/

#else

#   include <cppcms_boost/mpl/int_fwd.hpp>
#   include <cppcms_boost/mpl/aux_/yes_no.hpp>
#   include <cppcms_boost/mpl/aux_/na_fwd.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/enum.hpp>
#   include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#   include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#   include <cppcms_boost/preprocessor/tuple/to_list.hpp>
#   include <cppcms_boost/preprocessor/list/for_each_i.hpp>
#   include <cppcms_boost/preprocessor/inc.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>

#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC(R,typedef_,i,param) \
    typedef_ param CPPCMS_BOOST_PP_CAT(arg,CPPCMS_BOOST_PP_INC(i)); \
    /**/

// agurt, 07/mar/03: restore an old revision for the sake of SGI MIPSpro C++
#if CPPCMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 238) 

#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    typedef CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , CPPCMS_BOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    struct rebind \
    { \
        template< CPPCMS_BOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
            : name< CPPCMS_BOOST_MPL_PP_PARAMS(i,U) > \
        { \
        }; \
    }; \
    /**/

#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    /**/

#elif CPPCMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(CPPCMS_BOOST_INTEL_CXX_VERSION)
// agurt, 18/jan/03: old EDG-based compilers actually enforce 11.4 para 9
// (in strict mode), so we have to provide an alternative to the 
// MSVC-optimized implementation

#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    typedef CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , CPPCMS_BOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    struct rebind; \
/**/

#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
template< CPPCMS_BOOST_MPL_PP_PARAMS(i,typename T) > \
struct name<CPPCMS_BOOST_MPL_PP_PARAMS(i,T)>::rebind \
{ \
    template< CPPCMS_BOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
        : name< CPPCMS_BOOST_MPL_PP_PARAMS(i,U) > \
    { \
    }; \
/**/

#else // __EDG_VERSION__

namespace cppcms_boost { namespace mpl { namespace aux {
template< typename T > struct has_rebind_tag;
}}}

#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    typedef CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , CPPCMS_BOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    friend class CPPCMS_BOOST_PP_CAT(name,_rebind); \
    typedef CPPCMS_BOOST_PP_CAT(name,_rebind) rebind; \
/**/

#if CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610))
#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
template< CPPCMS_BOOST_MPL_PP_PARAMS(i,typename T) > \
::cppcms_boost::mpl::aux::yes_tag operator|( \
      ::cppcms_boost::mpl::aux::has_rebind_tag<int> \
    , name<CPPCMS_BOOST_MPL_PP_PARAMS(i,T)>* \
    ); \
::cppcms_boost::mpl::aux::no_tag operator|( \
      ::cppcms_boost::mpl::aux::has_rebind_tag<int> \
    , name< CPPCMS_BOOST_MPL_PP_ENUM(i,::cppcms_boost::mpl::na) >* \
    ); \
/**/
#elif !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
template< CPPCMS_BOOST_MPL_PP_PARAMS(i,typename T) > \
::cppcms_boost::mpl::aux::yes_tag operator|( \
      ::cppcms_boost::mpl::aux::has_rebind_tag<int> \
    , ::cppcms_boost::mpl::aux::has_rebind_tag< name<CPPCMS_BOOST_MPL_PP_PARAMS(i,T)> >* \
    ); \
/**/
#else
#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) /**/
#endif

#   if !defined(__BORLANDC__)
#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
class CPPCMS_BOOST_PP_CAT(name,_rebind) \
{ \
 public: \
    template< CPPCMS_BOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
        : name< CPPCMS_BOOST_MPL_PP_PARAMS(i,U) > \
    { \
    }; \
/**/
#   else
#   define CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
class CPPCMS_BOOST_PP_CAT(name,_rebind) \
{ \
 public: \
    template< CPPCMS_BOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
    { \
        typedef typename name< CPPCMS_BOOST_MPL_PP_PARAMS(i,U) >::type type; \
    }; \
/**/
#   endif // __BORLANDC__

#endif // __EDG_VERSION__

#endif // BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT

#endif // BOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED
