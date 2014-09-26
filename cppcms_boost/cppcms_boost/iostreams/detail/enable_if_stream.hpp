// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef CPPCMS_BOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED
#define CPPCMS_BOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <cppcms_boost/config.hpp>                // BOOST_NO_SFINAE.
#include <cppcms_boost/utility/enable_if.hpp>                  
#include <cppcms_boost/iostreams/traits_fwd.hpp>  // is_std_io.

#if !defined(CPPCMS_BOOST_NO_SFINAE) && \
    !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x592))
# define CPPCMS_BOOST_IOSTREAMS_ENABLE_IF_STREAM(T) \
    , typename cppcms_boost::enable_if< cppcms_boost::iostreams::is_std_io<T> >::type* = 0 \
    /**/
# define CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_STREAM(T) \
    , typename cppcms_boost::disable_if< cppcms_boost::iostreams::is_std_io<T> >::type* = 0 \
    /**/
#else 
# define CPPCMS_BOOST_IOSTREAMS_ENABLE_IF_STREAM(T)
# define CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_STREAM(T)
#endif

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED
