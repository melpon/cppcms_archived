
#if !defined(CPPCMS_BOOST_PP_IS_ITERATING)

///// header body

// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION!

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: numeric_op.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/numeric_cast.hpp>
#   include <cppcms_boost/mpl/apply_wrap.hpp>
#   include <cppcms_boost/mpl/if.hpp>
#   include <cppcms_boost/mpl/tag.hpp>
#   include <cppcms_boost/mpl/aux_/numeric_cast_utils.hpp>
#   include <cppcms_boost/mpl/aux_/na.hpp>
#   include <cppcms_boost/mpl/aux_/na_spec.hpp>
#   include <cppcms_boost/mpl/aux_/lambda_support.hpp>
#   include <cppcms_boost/mpl/aux_/msvc_eti_base.hpp>
#   include <cppcms_boost/mpl/aux_/value_wknd.hpp>
#   include <cppcms_boost/mpl/aux_/config/eti.hpp>
#   include <cppcms_boost/mpl/aux_/nttp_decl.hpp>
#endif

#include <cppcms_boost/mpl/aux_/config/static_constant.hpp>

#if defined(CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    || defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)

#   include <cppcms_boost/mpl/limits/arity.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/partial_spec_params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/def_params_tail.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/repeat.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/ext_params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/enum.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/add.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/sub.hpp>
#   include <cppcms_boost/mpl/aux_/config/ctps.hpp>
#   include <cppcms_boost/mpl/aux_/config/eti.hpp>
#   include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#   include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#   include <cppcms_boost/preprocessor/dec.hpp>
#   include <cppcms_boost/preprocessor/inc.hpp>
#   include <cppcms_boost/preprocessor/iterate.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>


#if !defined(AUX778076_OP_ARITY)
#   define AUX778076_OP_ARITY CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
#endif

#if !defined(AUX778076_OP_IMPL_NAME)
#   define AUX778076_OP_IMPL_NAME CPPCMS_BOOST_PP_CAT(AUX778076_OP_PREFIX,_impl)
#endif

#if !defined(AUX778076_OP_TAG_NAME)
#   define AUX778076_OP_TAG_NAME CPPCMS_BOOST_PP_CAT(AUX778076_OP_PREFIX,_tag)
#endif

namespace cppcms_boost { namespace mpl {

template< 
      typename Tag1
    , typename Tag2
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300)
    , CPPCMS_BOOST_MPL_AUX_NTTP_DECL(int, tag1_) = CPPCMS_BOOST_MPL_AUX_MSVC_VALUE_WKND(Tag1)::value 
    , CPPCMS_BOOST_MPL_AUX_NTTP_DECL(int, tag2_) = CPPCMS_BOOST_MPL_AUX_MSVC_VALUE_WKND(Tag2)::value 
    >
struct AUX778076_OP_IMPL_NAME
    : if_c<
          ( tag1_ > tag2_ )
#else
    >
struct AUX778076_OP_IMPL_NAME
    : if_c<
          ( CPPCMS_BOOST_MPL_AUX_NESTED_VALUE_WKND(int, Tag1)
              > CPPCMS_BOOST_MPL_AUX_NESTED_VALUE_WKND(int, Tag2)
            )
#endif
        , aux::cast2nd_impl< AUX778076_OP_IMPL_NAME<Tag1,Tag1>,Tag1,Tag2 >
        , aux::cast1st_impl< AUX778076_OP_IMPL_NAME<Tag2,Tag2>,Tag1,Tag2 >
        >::type
{
};

/// for Digital Mars C++/compilers with no CTPS/TTP support
template<> struct AUX778076_OP_IMPL_NAME<na,na>
{
    template< typename U1, typename U2 > struct apply 
    {
        typedef apply type;
        CPPCMS_BOOST_STATIC_CONSTANT(int, value = 0);
    };
};

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
template< typename Tag > struct AUX778076_OP_IMPL_NAME<na,Tag>
{
    template< typename U1, typename U2 > struct apply 
    {
        typedef apply type;
        CPPCMS_BOOST_STATIC_CONSTANT(int, value = 0);
    };
};

template< typename Tag > struct AUX778076_OP_IMPL_NAME<Tag,na>
{
    template< typename U1, typename U2 > struct apply 
    {
        typedef apply type;
        CPPCMS_BOOST_STATIC_CONSTANT(int, value = 0);
    };
};
#else
template<> struct AUX778076_OP_IMPL_NAME<na,integral_c_tag>
{
    template< typename U1, typename U2 > struct apply 
    {
        typedef apply type;
        CPPCMS_BOOST_STATIC_CONSTANT(int, value = 0);
    };
};

template<> struct AUX778076_OP_IMPL_NAME<integral_c_tag,na>
{
    template< typename U1, typename U2 > struct apply 
    {
        typedef apply type;
        CPPCMS_BOOST_STATIC_CONSTANT(int, value = 0);
    };
};
#endif


#if defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    && CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, >= 1300)
template< typename T > struct AUX778076_OP_TAG_NAME
    : tag<T,na>
{
};
#else
template< typename T > struct AUX778076_OP_TAG_NAME
{
    typedef typename T::tag type;
};
#endif


#if AUX778076_OP_ARITY != 2

#   if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

#   define AUX778076_OP_RIGHT_OPERAND(unused, i, N) , CPPCMS_BOOST_PP_CAT(N, CPPCMS_BOOST_MPL_PP_ADD(i, 2))>
#   define AUX778076_OP_N_CALLS(i, N) \
    CPPCMS_BOOST_MPL_PP_REPEAT( CPPCMS_BOOST_PP_DEC(i), CPPCMS_BOOST_MPL_PP_REPEAT_IDENTITY_FUNC, AUX778076_OP_NAME< ) \
    N1 CPPCMS_BOOST_MPL_PP_REPEAT( CPPCMS_BOOST_MPL_PP_SUB(i, 1), AUX778076_OP_RIGHT_OPERAND, N ) \
/**/

template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N1)
    , typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N2)
    CPPCMS_BOOST_MPL_PP_DEF_PARAMS_TAIL(2, typename N, na)
    >
struct AUX778076_OP_NAME
    : AUX778076_OP_N_CALLS(AUX778076_OP_ARITY, N)
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(
          AUX778076_OP_ARITY
        , AUX778076_OP_NAME
        , ( CPPCMS_BOOST_MPL_PP_PARAMS(AUX778076_OP_ARITY, N) )
        )
};

#define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,( CPPCMS_BOOST_PP_DEC(AUX778076_OP_ARITY), 2, <cppcms_boost/mpl/aux_/numeric_op.hpp> ))
#include CPPCMS_BOOST_PP_ITERATE()

#   undef AUX778076_OP_N_CALLS
#   undef AUX778076_OP_RIGHT_OPERAND

#   else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

/// forward declaration
template< 
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N1)
    , typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N2)
    >
struct CPPCMS_BOOST_PP_CAT(AUX778076_OP_NAME,2);

template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N1)
    , typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N2)
    CPPCMS_BOOST_MPL_PP_DEF_PARAMS_TAIL(2, typename N, na)
    >
struct AUX778076_OP_NAME
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1300)
    : aux::msvc_eti_base< typename if_<
#else
    : if_<
#endif
          is_na<N3>
        , CPPCMS_BOOST_PP_CAT(AUX778076_OP_NAME,2)<N1,N2>
        , AUX778076_OP_NAME<
              CPPCMS_BOOST_PP_CAT(AUX778076_OP_NAME,2)<N1,N2>
            , CPPCMS_BOOST_MPL_PP_EXT_PARAMS(3, CPPCMS_BOOST_PP_INC(AUX778076_OP_ARITY), N)
            >
        >::type
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1300)
    >
#endif
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(
          AUX778076_OP_ARITY
        , AUX778076_OP_NAME
        , ( CPPCMS_BOOST_MPL_PP_PARAMS(AUX778076_OP_ARITY, N) )
        )
};

template< 
      typename N1
    , typename N2
    >
struct CPPCMS_BOOST_PP_CAT(AUX778076_OP_NAME,2)

#endif

#else // AUX778076_OP_ARITY == 2

template< 
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N1)
    , typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N2)
    >
struct AUX778076_OP_NAME

#endif

#if !defined(CPPCMS_BOOST_MPL_CFG_MSVC_ETI_BUG)
    : AUX778076_OP_IMPL_NAME<
          typename AUX778076_OP_TAG_NAME<N1>::type
        , typename AUX778076_OP_TAG_NAME<N2>::type
        >::template apply<N1,N2>::type
#else
    : aux::msvc_eti_base< typename apply_wrap2<
          AUX778076_OP_IMPL_NAME<
              typename AUX778076_OP_TAG_NAME<N1>::type
            , typename AUX778076_OP_TAG_NAME<N2>::type
            >
        , N1
        , N2
        >::type >::type
#endif
{
#if AUX778076_OP_ARITY != 2

#   if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(
          AUX778076_OP_ARITY
        , AUX778076_OP_NAME
        , ( CPPCMS_BOOST_MPL_PP_PARTIAL_SPEC_PARAMS(2, N, na) )
        )
#   else
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2, CPPCMS_BOOST_PP_CAT(AUX778076_OP_NAME,2), (N1, N2))
#   endif

#else
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2, AUX778076_OP_NAME, (N1, N2))
#endif
};

CPPCMS_BOOST_MPL_AUX_NA_SPEC2(2, AUX778076_OP_ARITY, AUX778076_OP_NAME)

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // BOOST_PP_IS_ITERATING
#if CPPCMS_BOOST_PP_ITERATION_DEPTH() == 1

#   define i_ CPPCMS_BOOST_PP_FRAME_ITERATION(1)

template<
      CPPCMS_BOOST_MPL_PP_PARAMS(i_, typename N)
    >
struct AUX778076_OP_NAME<CPPCMS_BOOST_MPL_PP_PARTIAL_SPEC_PARAMS(i_, N, na)>
#if i_ != 2
    : AUX778076_OP_N_CALLS(i_, N)
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(
          AUX778076_OP_ARITY
        , AUX778076_OP_NAME
        , ( CPPCMS_BOOST_MPL_PP_PARTIAL_SPEC_PARAMS(i_, N, na) )
        )
};
#endif

#   undef i_

#endif // BOOST_PP_ITERATION_DEPTH()
#endif // BOOST_PP_IS_ITERATING
