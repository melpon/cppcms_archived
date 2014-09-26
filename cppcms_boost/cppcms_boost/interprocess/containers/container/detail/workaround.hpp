//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_CONTAINERS_DETAIL_WORKAROUND_HPP
#define CPPCMS_BOOST_CONTAINERS_DETAIL_WORKAROUND_HPP

#include <cppcms_boost/interprocess/containers/container/detail/config_begin.hpp>

#if     defined(CPPCMS_BOOST_HAS_RVALUE_REFS) && defined(CPPCMS_BOOST_HAS_VARIADIC_TMPL)\
    && !defined(CPPCMS_BOOST_INTERPROCESS_DISABLE_VARIADIC_TMPL)
#define CPPCMS_BOOST_CONTAINERS_PERFECT_FORWARDING

#endif

#include <cppcms_boost/interprocess/containers/container/detail/config_end.hpp>

#endif   //#ifndef BOOST_CONTAINERS_DETAIL_WORKAROUND_HPP
