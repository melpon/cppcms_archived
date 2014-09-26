
#ifndef CPPCMS_BOOST_MPL_REVERSE_FOLD_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_REVERSE_FOLD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
// Copyright David Abrahams 2001-2002
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: reverse_fold.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/begin_end.hpp>
#include <cppcms_boost/mpl/O1_size.hpp>
#include <cppcms_boost/mpl/arg.hpp>
#include <cppcms_boost/mpl/aux_/reverse_fold_impl.hpp>
#include <cppcms_boost/mpl/aux_/na_spec.hpp>

namespace cppcms_boost { namespace mpl {

template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(State)
    , typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(BackwardOp)
    , typename ForwardOp = arg<1>
    >
struct reverse_fold
{
    typedef typename aux::reverse_fold_impl<
          ::cppcms_boost::mpl::O1_size<Sequence>::value
        , typename begin<Sequence>::type
        , typename end<Sequence>::type
        , State
        , BackwardOp
        , ForwardOp
        >::state type;

    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(3,reverse_fold,(Sequence,State,BackwardOp))
};

CPPCMS_BOOST_MPL_AUX_NA_SPEC(3, reverse_fold)

}}

#endif // BOOST_MPL_REVERSE_FOLD_HPP_INCLUDED
