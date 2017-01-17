#ifndef CPPCMS_BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#define CPPCMS_BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  bind/placeholders.hpp - _N definitions
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/bind/bind.html for documentation.
//

#include <cppcms_boost/bind/arg.hpp>
#include <cppcms_boost/config.hpp>

namespace
{

#if defined(__BORLANDC__) || defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ < 400)

static inline cppcms_boost::arg<1> _1() { return cppcms_boost::arg<1>(); }
static inline cppcms_boost::arg<2> _2() { return cppcms_boost::arg<2>(); }
static inline cppcms_boost::arg<3> _3() { return cppcms_boost::arg<3>(); }
static inline cppcms_boost::arg<4> _4() { return cppcms_boost::arg<4>(); }
static inline cppcms_boost::arg<5> _5() { return cppcms_boost::arg<5>(); }
static inline cppcms_boost::arg<6> _6() { return cppcms_boost::arg<6>(); }
static inline cppcms_boost::arg<7> _7() { return cppcms_boost::arg<7>(); }
static inline cppcms_boost::arg<8> _8() { return cppcms_boost::arg<8>(); }
static inline cppcms_boost::arg<9> _9() { return cppcms_boost::arg<9>(); }

#elif defined(CPPCMS_BOOST_MSVC) || (defined(__DECCXX_VER) && __DECCXX_VER <= 60590031) || defined(__MWERKS__) || \
    defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ == 400)  

static cppcms_boost::arg<1> _1;
static cppcms_boost::arg<2> _2;
static cppcms_boost::arg<3> _3;
static cppcms_boost::arg<4> _4;
static cppcms_boost::arg<5> _5;
static cppcms_boost::arg<6> _6;
static cppcms_boost::arg<7> _7;
static cppcms_boost::arg<8> _8;
static cppcms_boost::arg<9> _9;

#else

cppcms_boost::arg<1> _1;
cppcms_boost::arg<2> _2;
cppcms_boost::arg<3> _3;
cppcms_boost::arg<4> _4;
cppcms_boost::arg<5> _5;
cppcms_boost::arg<6> _6;
cppcms_boost::arg<7> _7;
cppcms_boost::arg<8> _8;
cppcms_boost::arg<9> _9;

#endif

} // unnamed namespace

#endif // #ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
