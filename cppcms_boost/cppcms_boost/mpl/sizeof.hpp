
#ifndef CPPCMS_BOOST_MPL_SIZEOF_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_SIZEOF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: sizeof.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/size_t.hpp>
#include <cppcms_boost/mpl/aux_/na_spec.hpp>
#include <cppcms_boost/mpl/aux_/lambda_support.hpp>

namespace cppcms_boost { namespace mpl {

template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(T)
    >
struct sizeof_
    : mpl::size_t< sizeof(T) >
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,sizeof_,(T))
};

CPPCMS_BOOST_MPL_AUX_NA_SPEC_NO_ETI(1, sizeof_)

}}

#endif // BOOST_MPL_SIZEOF_HPP_INCLUDED
