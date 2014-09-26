
#ifndef CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: adl_barrier.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <cppcms_boost/mpl/aux_/config/adl.hpp>
#include <cppcms_boost/mpl/aux_/config/gcc.hpp>
#include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE)

#   define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE mpl_
#   define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN namespace mpl_ {
#   define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE }
#   define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_DECL(type) \
    namespace cppcms_boost { namespace mpl { \
    using ::CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::type; \
    } } \
/**/

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
namespace CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE { namespace aux {} }
namespace cppcms_boost { namespace mpl { using namespace CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE; 
namespace aux { using namespace CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::aux; }
}}
#endif

#else // BOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE

#   define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE cppcms_boost::mpl
#   define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN namespace cppcms_boost { namespace mpl {
#   define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE }}
#   define CPPCMS_BOOST_MPL_AUX_ADL_BARRIER_DECL(type) /**/

#endif

#endif // BOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED
