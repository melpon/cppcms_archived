// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef CPPCMS_BOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED
#define CPPCMS_BOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED   

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif                  
 
#include <cppcms_boost/config.hpp> // BOOST_MSVC, BOOST_NO_SFINAE
#include <cppcms_boost/detail/workaround.hpp>
#include <cppcms_boost/iostreams/detail/config/limits.hpp>
#include <cppcms_boost/iostreams/detail/push_params.hpp>
#include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
#include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
#include <cppcms_boost/preprocessor/punctuation/comma_if.hpp>
#include <cppcms_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <cppcms_boost/preprocessor/repetition/enum_params.hpp>
#include <cppcms_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <cppcms_boost/preprocessor/tuple/elem.hpp>
#include <cppcms_boost/type_traits/is_same.hpp>

//------Macros for defining forwarding constructors and open overloads--------//
    
//
// Macro: BOOST_IOSTREAMS_FORWARD(class, impl, device, params, args)
// Description: Defines constructors and overloads of 'open' which construct
//      a device using the specified argument list and pass it to the specified
//      helper function
//   class - The class name
//   impl - The helper function
//   device - The device type
//   params - The list of formal parameters trailing the device parameter in
//     the helper function's signature
//   params - The list of arguments passed to the helper function, following the
//     device argument
//
#define CPPCMS_BOOST_IOSTREAMS_FORWARD(class, impl, device, params, args) \
    class(const device& t params()) \
    { this->impl(::cppcms_boost::iostreams::detail::wrap(t) args()); } \
    class(device& t params()) \
    { this->impl(::cppcms_boost::iostreams::detail::wrap(t) args()); } \
    class(const ::cppcms_boost::reference_wrapper<device>& ref params()) \
    { this->impl(ref args()); } \
    void open(const device& t params()) \
    { this->impl(::cppcms_boost::iostreams::detail::wrap(t) args()); } \
    void open(device& t params()) \
    { this->impl(::cppcms_boost::iostreams::detail::wrap(t) args()); } \
    void open(const ::cppcms_boost::reference_wrapper<device>& ref params()) \
    { this->impl(ref args()); } \
    CPPCMS_BOOST_PP_REPEAT_FROM_TO( \
        1, CPPCMS_BOOST_PP_INC(CPPCMS_BOOST_IOSTREAMS_MAX_FORWARDING_ARITY), \
        CPPCMS_BOOST_IOSTREAMS_FORWARDING_CTOR, (class, impl, device) \
    ) \
    CPPCMS_BOOST_PP_REPEAT_FROM_TO( \
        1, CPPCMS_BOOST_PP_INC(CPPCMS_BOOST_IOSTREAMS_MAX_FORWARDING_ARITY), \
        CPPCMS_BOOST_IOSTREAMS_FORWARDING_FN, (class, impl, device) \
    ) \
    /**/
#if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
# define CPPCMS_BOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple) \
    template< typename U100 CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_DEC(n)) \
              CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, CPPCMS_BOOST_PP_DEC(n), typename U) > \
    CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, tuple) \
    ( U100& u100 CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_DEC(n)) \
      CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, CPPCMS_BOOST_PP_DEC(n), const U, &u) \
      CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(U100, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        ( u100 CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_DEC(n)) \
          CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, CPPCMS_BOOST_PP_DEC(n), u)) ); } \
    /**/
# define CPPCMS_BOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple) \
    template< typename U100 CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_DEC(n)) \
              CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, CPPCMS_BOOST_PP_DEC(n), typename U) > \
    void open \
    ( U100& u100 CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_DEC(n)) \
      CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, CPPCMS_BOOST_PP_DEC(n), const U, &u) \
      CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(U100, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( u100 CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_DEC(n)) \
        CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, CPPCMS_BOOST_PP_DEC(n), u) ); } \
    /**/
#else
# define CPPCMS_BOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple)
# define CPPCMS_BOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple)
#endif
#define CPPCMS_BOOST_IOSTREAMS_FORWARDING_CTOR(z, n, tuple) \
    template<CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, n, typename U)> \
    CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, tuple) \
    (CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, n, const U, &u) \
      CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(U0, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        (CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, n, u)) ); } \
    CPPCMS_BOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple) \
    /**/
#define CPPCMS_BOOST_IOSTREAMS_FORWARDING_FN(z, n, tuple) \
    template<CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, n, typename U)> \
    void open(CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, n, const U, &u) \
      CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(U0, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        (CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, n, u)) ); } \
    CPPCMS_BOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple) \
    /**/

// Disable forwarding constructors if first parameter type is the same
// as the device type
#if !defined(CPPCMS_BOOST_NO_SFINAE) && \
    !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x592))
# define CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(device, param) \
    , typename cppcms_boost::disable_if< cppcms_boost::is_same<device, param> >::type* = 0 \
    /**/
#else 
# define CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(device, param)
#endif

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED
