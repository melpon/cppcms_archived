
#if !defined(CPPCMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef CPPCMS_BOOST_MPL_AUX_ADVANCE_FORWARD_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_ADVANCE_FORWARD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: advance_forward.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/next.hpp>
#   include <cppcms_boost/mpl/apply_wrap.hpp>
#endif

#include <cppcms_boost/mpl/aux_/config/use_preprocessed.hpp>

#if    !defined(CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)

#   define CPPCMS_BOOST_MPL_PREPROCESSED_HEADER advance_forward.hpp
#   include <cppcms_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <cppcms_boost/mpl/limits/unrolling.hpp>
#   include <cppcms_boost/mpl/aux_/nttp_decl.hpp>
#   include <cppcms_boost/mpl/aux_/config/eti.hpp>

#   include <cppcms_boost/preprocessor/iterate.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>
#   include <cppcms_boost/preprocessor/inc.hpp>

namespace cppcms_boost { namespace mpl { namespace aux {

// forward declaration
template< CPPCMS_BOOST_MPL_AUX_NTTP_DECL(long, N) > struct advance_forward;

#   define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, CPPCMS_BOOST_MPL_LIMIT_UNROLLING, <cppcms_boost/mpl/aux_/advance_forward.hpp>))
#   include CPPCMS_BOOST_PP_ITERATE()

// implementation for N that exceeds BOOST_MPL_LIMIT_UNROLLING
template< CPPCMS_BOOST_MPL_AUX_NTTP_DECL(long, N) > 
struct advance_forward
{
    template< typename Iterator > struct apply
    {
        typedef typename apply_wrap1<
              advance_forward<CPPCMS_BOOST_MPL_LIMIT_UNROLLING>
            , Iterator
            >::type chunk_result_;

        typedef typename apply_wrap1<
              advance_forward<(
                (N - CPPCMS_BOOST_MPL_LIMIT_UNROLLING) < 0
                    ? 0
                    : N - CPPCMS_BOOST_MPL_LIMIT_UNROLLING
                    )>
            , chunk_result_
            >::type type;
    };
};

}}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_AUX_ADVANCE_FORWARD_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // BOOST_PP_IS_ITERATING
#if CPPCMS_BOOST_PP_ITERATION_DEPTH() == 1
#define i_ CPPCMS_BOOST_PP_FRAME_ITERATION(1)

template<>
struct advance_forward< CPPCMS_BOOST_PP_FRAME_ITERATION(1) >
{
    template< typename Iterator > struct apply
    {
        typedef Iterator iter0;

#if i_ > 0
#   define CPPCMS_BOOST_PP_ITERATION_PARAMS_2 \
    (3,(1, i_, <cppcms_boost/mpl/aux_/advance_forward.hpp>))
#   include CPPCMS_BOOST_PP_ITERATE()
#endif
        typedef CPPCMS_BOOST_PP_CAT(iter,i_) type;
    };

#if defined(CPPCMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct apply<int>
    {
        typedef int type;
    };
#endif
};

#undef i_

///// iteration, depth == 2

#elif CPPCMS_BOOST_PP_ITERATION_DEPTH() == 2

#   define AUX778076_ITER_0 CPPCMS_BOOST_PP_CAT(iter,CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_FRAME_ITERATION(2)))
#   define AUX778076_ITER_1 CPPCMS_BOOST_PP_CAT(iter,CPPCMS_BOOST_PP_FRAME_ITERATION(2))

        typedef typename next<AUX778076_ITER_0>::type AUX778076_ITER_1;
        
#   undef AUX778076_ITER_1
#   undef AUX778076_ITER_0

#endif // BOOST_PP_ITERATION_DEPTH()
#endif // BOOST_PP_IS_ITERATING
