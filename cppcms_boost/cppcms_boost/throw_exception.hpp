#ifndef CPPCMS_BOOST_THROW_EXCEPTION_HPP_INCLUDED
#define CPPCMS_BOOST_THROW_EXCEPTION_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  boost/throw_exception.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  http://www.boost.org/libs/utility/throw_exception.html
//

#include <cppcms_boost/exception/detail/attribute_noreturn.hpp>
#include <cppcms_boost/detail/workaround.hpp>
#include <exception>

#if !defined( CPPCMS_BOOST_EXCEPTION_DISABLE ) && defined( __BORLANDC__ ) && CPPCMS_BOOST_WORKAROUND( __BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x593) )
# define CPPCMS_BOOST_EXCEPTION_DISABLE
#endif

#if !defined( CPPCMS_BOOST_EXCEPTION_DISABLE ) && defined( CPPCMS_BOOST_MSVC ) && CPPCMS_BOOST_WORKAROUND( CPPCMS_BOOST_MSVC, < 1310 )
# define CPPCMS_BOOST_EXCEPTION_DISABLE
#endif

#if !defined( CPPCMS_BOOST_EXCEPTION_DISABLE )
# include <cppcms_boost/exception/exception.hpp>
# include <cppcms_boost/current_function.hpp>
# define CPPCMS_BOOST_THROW_EXCEPTION(x) ::cppcms_boost::throw_exception(::cppcms_boost::enable_error_info(x) <<\
    ::cppcms_boost::throw_function(CPPCMS_BOOST_CURRENT_FUNCTION) <<\
    ::cppcms_boost::throw_file(__FILE__) <<\
    ::cppcms_boost::throw_line((int)__LINE__))
#else
# define CPPCMS_BOOST_THROW_EXCEPTION(x) ::cppcms_boost::throw_exception(x)
#endif

namespace cppcms_boost
{

#ifdef CPPCMS_BOOST_NO_EXCEPTIONS

void throw_exception( std::exception const & e ); // user defined

#else

inline void throw_exception_assert_compatibility( std::exception const & ) { }

template<class E> CPPCMS_BOOST_ATTRIBUTE_NORETURN inline void throw_exception( E const & e )
{
    //All boost exceptions are required to derive from std::exception,
    //to ensure compatibility with BOOST_NO_EXCEPTIONS.
    throw_exception_assert_compatibility(e);

#ifndef CPPCMS_BOOST_EXCEPTION_DISABLE
    throw enable_current_exception(enable_error_info(e));
#else
    throw e;
#endif
}

#endif

} // namespace boost

#endif // #ifndef BOOST_THROW_EXCEPTION_HPP_INCLUDED
