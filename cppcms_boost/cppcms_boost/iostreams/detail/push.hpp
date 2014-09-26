// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef CPPCMS_BOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED
#define CPPCMS_BOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED 

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif                    
 
#include <cppcms_boost/config.hpp> // BOOST_MSVC.
#include <cppcms_boost/detail/workaround.hpp>
#include <cppcms_boost/iostreams/categories.hpp>
#include <cppcms_boost/iostreams/categories.hpp>
#include <cppcms_boost/iostreams/detail/adapter/range_adapter.hpp>
#include <cppcms_boost/iostreams/detail/config/wide_streams.hpp>
#include <cppcms_boost/iostreams/detail/enable_if_stream.hpp>   
#include <cppcms_boost/iostreams/pipeline.hpp>   
#include <cppcms_boost/iostreams/detail/push_params.hpp>   
#include <cppcms_boost/iostreams/detail/resolve.hpp>
#include <cppcms_boost/mpl/bool.hpp>   
#include <cppcms_boost/preprocessor/cat.hpp> 
#include <cppcms_boost/preprocessor/control/iif.hpp>
#include <cppcms_boost/static_assert.hpp>
#include <cppcms_boost/type_traits/is_convertible.hpp>

//
// Macro: BOOST_IOSTREAMS_DEFINE_PUSH_CONSTRUCTOR(name, mode, ch, helper).
// Description: Defines overloads with name 'name' which forward to a function
//      'helper' which takes a filter or devide by const reference.
//
#define CPPCMS_BOOST_IOSTREAMS_DEFINE_PUSH_CONSTRUCTOR(name, mode, ch, helper) \
    CPPCMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, 0, ?) \
    /**/

//
// Macro: BOOST_IOSTREAMS_DEFINE_PUSH(name, mode, ch, helper).
// Description: Defines constructors which forward to a function
//      'helper' which takes a filter or device by const reference.
//
#define CPPCMS_BOOST_IOSTREAMS_DEFINE_PUSH(name, mode, ch, helper) \
    CPPCMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, 1, void) \
    /**/

//--------------------Definition of BOOST_IOSTREAMS_DEFINE_PUSH_IMPL----------//
          
#define CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, arg, helper, has_return) \
    this->helper( ::cppcms_boost::iostreams::detail::resolve<mode, ch>(arg) \
                  CPPCMS_BOOST_IOSTREAMS_PUSH_ARGS() ); \
    /**/

#if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300) && \
    !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600) \
    /**/
# ifndef CPPCMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#  define CPPCMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    template<typename CharType, typename TraitsType> \
    CPPCMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_streambuf<CharType, TraitsType>& sb CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, sb, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    CPPCMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_istream<CharType, TraitsType>& is CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_STATIC_ASSERT((!is_convertible<mode, output>::value)); \
      CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, is, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    CPPCMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_ostream<CharType, TraitsType>& os CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_STATIC_ASSERT((!is_convertible<mode, input>::value)); \
      CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, os, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    CPPCMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_iostream<CharType, TraitsType>& io CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, io, helper, has_return); } \
    template<typename Iter> \
    CPPCMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(const iterator_range<Iter>& rng CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_PP_EXPR_IF(has_return, return) \
    this->helper( ::cppcms_boost::iostreams::detail::range_adapter< \
                      mode, iterator_range<Iter> \
                  >(rng) \
                  CPPCMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename Pipeline, typename Concept> \
    CPPCMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(const ::cppcms_boost::iostreams::pipeline<Pipeline, Concept>& p) \
    { p.push(*this); } \
    template<typename T> \
    CPPCMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(const T& t CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS() CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_STREAM(T)) \
    { this->helper( ::cppcms_boost::iostreams::detail::resolve<mode, ch>(t) \
                    CPPCMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    /**/
# else // # ifndef BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#  define CPPCMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    CPPCMS_BOOST_PP_IF(has_return, result, explicit) \
    name(::std::streambuf& sb CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, sb, helper, has_return); } \
    CPPCMS_BOOST_PP_IF(has_return, result, explicit) \
    name(::std::istream& is CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_STATIC_ASSERT((!is_convertible<mode, output>::value)); \
      CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, is, helper, has_return); } \
    CPPCMS_BOOST_PP_IF(has_return, result, explicit) \
    name(::std::ostream& os CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_STATIC_ASSERT((!is_convertible<mode, input>::value)); \
      CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, os, helper, has_return); } \
    CPPCMS_BOOST_PP_IF(has_return, result, explicit) \
    name(::std::iostream& io CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, io, helper, has_return); } \
    template<typename Iter> \
    CPPCMS_BOOST_PP_IF(has_return, result, explicit) \
    name(const iterator_range<Iter>& rng CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { CPPCMS_BOOST_PP_EXPR_IF(has_return, return) \
    this->helper( ::cppcms_boost::iostreams::detail::range_adapter< \
                      mode, iterator_range<Iter> \
                  >(rng) \
                  CPPCMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename Pipeline, typename Concept> \
    CPPCMS_BOOST_PP_IF(has_return, result, explicit) \
    name(const ::cppcms_boost::iostreams::pipeline<Pipeline, Concept>& p) \
    { p.push(*this); } \
    template<typename T> \
    CPPCMS_BOOST_PP_EXPR_IF(has_return, result) \
    name(const T& t CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS() CPPCMS_BOOST_IOSTREAMS_DISABLE_IF_STREAM(T)) \
    { this->helper( ::cppcms_boost::iostreams::detail::resolve<mode, ch>(t) \
                    CPPCMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    /**/
# endif // # ifndef BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#else // #if VC6, VC7.0, Borland 5.x
# define CPPCMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    template<typename T> \
    void CPPCMS_BOOST_PP_CAT(name, _msvc_impl) \
    ( ::cppcms_boost::mpl::true_, const T& t CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS() ) \
    { t.push(*this); } \
    template<typename T> \
    void CPPCMS_BOOST_PP_CAT(name, _msvc_impl) \
    ( ::cppcms_boost::mpl::false_, const T& t CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS() ) \
    { this->helper( ::cppcms_boost::iostreams::detail::resolve<mode, ch>(t) \
                    CPPCMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename T> \
    CPPCMS_BOOST_PP_IF(has_return, result, explicit) \
    name(const T& t CPPCMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { \
        this->CPPCMS_BOOST_PP_CAT(name, _msvc_impl) \
              ( ::cppcms_boost::iostreams::detail::is_pipeline<T>(), \
                t CPPCMS_BOOST_IOSTREAMS_PUSH_ARGS() ); \
    } \
    /**/
#endif // #if VC6, VC7.0, Borland 5.x

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED
