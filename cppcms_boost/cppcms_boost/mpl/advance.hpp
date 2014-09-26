
#ifndef CPPCMS_BOOST_MPL_ADVANCE_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_ADVANCE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: advance.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/advance_fwd.hpp>
#include <cppcms_boost/mpl/less.hpp>
#include <cppcms_boost/mpl/negate.hpp>
#include <cppcms_boost/mpl/long.hpp>
#include <cppcms_boost/mpl/if.hpp>
#include <cppcms_boost/mpl/tag.hpp>
#include <cppcms_boost/mpl/apply_wrap.hpp>
#include <cppcms_boost/mpl/aux_/advance_forward.hpp>
#include <cppcms_boost/mpl/aux_/advance_backward.hpp>
#include <cppcms_boost/mpl/aux_/value_wknd.hpp>
#include <cppcms_boost/mpl/aux_/na_spec.hpp>
#include <cppcms_boost/mpl/aux_/nttp_decl.hpp>

namespace cppcms_boost { namespace mpl {

// default implementation for forward/bidirectional iterators
template< typename Tag >
struct advance_impl
{
    template< typename Iterator, typename N > struct apply
    {
        typedef typename less< N,long_<0> >::type backward_;
        typedef typename if_< backward_, negate<N>, N >::type offset_;

        typedef typename if_<
              backward_
            , aux::advance_backward< CPPCMS_BOOST_MPL_AUX_VALUE_WKND(offset_)::value >
            , aux::advance_forward< CPPCMS_BOOST_MPL_AUX_VALUE_WKND(offset_)::value >
            >::type f_;

        typedef typename apply_wrap1<f_,Iterator>::type type;
    };
};


template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(Iterator)
    , typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(N)
    >
struct advance
    : advance_impl< typename tag<Iterator>::type >
        ::template apply<Iterator,N>
{
};

template<
      typename Iterator
    , CPPCMS_BOOST_MPL_AUX_NTTP_DECL(long, N)
    >
struct advance_c
    : advance_impl< typename tag<Iterator>::type >
        ::template apply<Iterator,long_<N> >
{
};

CPPCMS_BOOST_MPL_AUX_NA_SPEC(2, advance)

}}

#endif // BOOST_MPL_ADVANCE_HPP_INCLUDED
