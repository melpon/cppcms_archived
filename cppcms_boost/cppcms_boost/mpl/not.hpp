
#ifndef CPPCMS_BOOST_MPL_NOT_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_NOT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: not.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/bool.hpp>
#include <cppcms_boost/mpl/aux_/nttp_decl.hpp>
#include <cppcms_boost/mpl/aux_/nested_type_wknd.hpp>
#include <cppcms_boost/mpl/aux_/na_spec.hpp>
#include <cppcms_boost/mpl/aux_/lambda_support.hpp>

namespace cppcms_boost { namespace mpl {

namespace aux {

template< CPPCMS_BOOST_MPL_AUX_NTTP_DECL(long, C_) > // 'long' is intentional here
struct not_impl
    : bool_<!C_>
{
};

} // namespace aux


template<
      typename CPPCMS_BOOST_MPL_AUX_NA_PARAM(T)
    >
struct not_
    : aux::not_impl<
          CPPCMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T)::value
        >
{
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,not_,(T))
};

CPPCMS_BOOST_MPL_AUX_NA_SPEC(1,not_)

}}

#endif // BOOST_MPL_NOT_HPP_INCLUDED
