// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

// Adapted from <boost/config/auto_link.hpp> and from
// http://www.boost.org/more/separate_compilation.html, by John Maddock.

#ifndef CPPCMS_BOOST_IOSTREAMS_DETAIL_CONFIG_ZLIB_HPP_INCLUDED
#define CPPCMS_BOOST_IOSTREAMS_DETAIL_CONFIG_ZLIB_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <cppcms_boost/config.hpp> // BOOST_STRINGIZE.

#if defined(CPPCMS_BOOST_ZLIB_BINARY)
# if defined(CPPCMS_BOOST_MSVC) || \
     defined(__BORLANDC__) || \
     (defined(__MWERKS__) && defined(_WIN32) && (__MWERKS__ >= 0x3000)) || \
     (defined(__ICL) && defined(_MSC_EXTENSIONS) && (_MSC_VER >= 1200)) \
     /**/

// Specify the name of the .lib file.
#  pragma comment(lib, CPPCMS_BOOST_STRINGIZE(CPPCMS_BOOST_ZLIB_BINARY))
# endif
#else 
# if !defined(CPPCMS_BOOST_IOSTREAMS_SOURCE) && \
     !defined(CPPCMS_BOOST_ALL_NO_LIB) && \
     !defined(CPPCMS_BOOST_IOSTREAMS_NO_LIB) \
     /**/

// Set the name of our library, this will get undef'ed by auto_link.hpp
// once it's done with it.
#  define CPPCMS_BOOST_LIB_NAME cppcms_boost_zlib

// If we're importing code from a dll, then tell auto_link.hpp about it.
#  if defined(CPPCMS_BOOST_ALL_DYN_LINK) || defined(CPPCMS_BOOST_IOSTREAMS_DYN_LINK)
#   define CPPCMS_BOOST_DYN_LINK
#  endif

// And include the header that does the work.
#  include <cppcms_boost/config/auto_link.hpp>
# endif
#endif

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_CONFIG_ZLIB_HPP_INCLUDED
