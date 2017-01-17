//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTERPROCESS_DETAIL_PREPROCESSOR_HPP
#define CPPCMS_BOOST_INTERPROCESS_DETAIL_PREPROCESSOR_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <cppcms_boost/interprocess/detail/config_begin.hpp>
#include <cppcms_boost/interprocess/detail/workaround.hpp>

#ifdef CPPCMS_BOOST_INTERPROCESS_PERFECT_FORWARDING
#error "This file is not needed when perfect forwarding is available"
#endif

#include <cppcms_boost/preprocessor/iteration/local.hpp> 
#include <cppcms_boost/preprocessor/repetition/enum_params.hpp>
#include <cppcms_boost/preprocessor/cat.hpp>
#include <cppcms_boost/preprocessor/repetition/enum.hpp>
#include <cppcms_boost/preprocessor/repetition/repeat.hpp>

#define CPPCMS_BOOST_INTERPROCESS_MAX_CONSTRUCTOR_PARAMETERS 10

//Note:
//We define template parameters as const references to
//be able to bind temporaries. After that we will un-const them.
//This cast is ugly but it is necessary until "perfect forwarding"
//is achieved in C++0x. Meanwhile, if we want to be able to
//bind rvalues with non-const references, we have to be ugly
#ifdef CPPCMS_BOOST_HAS_RVALUE_REFS
   #define CPPCMS_BOOST_INTERPROCESS_PP_PARAM_LIST(z, n, data) \
   CPPCMS_BOOST_PP_CAT(P, n) && CPPCMS_BOOST_PP_CAT(p, n) \
   //!
#else
   #define CPPCMS_BOOST_INTERPROCESS_PP_PARAM_LIST(z, n, data) \
   const CPPCMS_BOOST_PP_CAT(P, n) & CPPCMS_BOOST_PP_CAT(p, n) \
   //!
#endif

#ifdef CPPCMS_BOOST_HAS_RVALUE_REFS
   #define CPPCMS_BOOST_INTERPROCESS_PARAM(U, u) \
   U && u \
   //!
#else
   #define CPPCMS_BOOST_INTERPROCESS_PARAM(U, u) \
   const U & u \
   //!
#endif

#ifdef CPPCMS_BOOST_HAS_RVALUE_REFS
#define CPPCMS_BOOST_INTERPROCESS_AUX_PARAM_INIT(z, n, data) \
  CPPCMS_BOOST_PP_CAT(m_p, n) (CPPCMS_BOOST_PP_CAT(p, n))           \
//!
#else
#define CPPCMS_BOOST_INTERPROCESS_AUX_PARAM_INIT(z, n, data) \
  CPPCMS_BOOST_PP_CAT(m_p, n) (const_cast<CPPCMS_BOOST_PP_CAT(P, n) &>(CPPCMS_BOOST_PP_CAT(p, n))) \
//!
#endif

#define CPPCMS_BOOST_INTERPROCESS_AUX_PARAM_INC(z, n, data)   \
  CPPCMS_BOOST_PP_CAT(++m_p, n)                        \
//!

#ifdef CPPCMS_BOOST_HAS_RVALUE_REFS
#define CPPCMS_BOOST_INTERPROCESS_AUX_PARAM_DEFINE(z, n, data)  \
  CPPCMS_BOOST_PP_CAT(P, n) && CPPCMS_BOOST_PP_CAT(m_p, n);            \
//!
#else
#define CPPCMS_BOOST_INTERPROCESS_AUX_PARAM_DEFINE(z, n, data)  \
  CPPCMS_BOOST_PP_CAT(P, n) & CPPCMS_BOOST_PP_CAT(m_p, n);             \
//!
#endif

#define CPPCMS_BOOST_INTERPROCESS_PP_PARAM_FORWARD(z, n, data) \
cppcms_boost::interprocess::forward< CPPCMS_BOOST_PP_CAT(P, n) >( CPPCMS_BOOST_PP_CAT(p, n) ) \
//!

#define CPPCMS_BOOST_INTERPROCESS_PP_MEMBER_FORWARD(z, n, data) \
cppcms_boost::interprocess::forward< CPPCMS_BOOST_PP_CAT(P, n) >( CPPCMS_BOOST_PP_CAT(m_p, n) ) \
//!

#define CPPCMS_BOOST_INTERPROCESS_PP_MEMBER_IT_FORWARD(z, n, data) \
CPPCMS_BOOST_PP_CAT(*m_p, n) \
//!

#include <cppcms_boost/interprocess/detail/config_end.hpp>

#else
#ifdef CPPCMS_BOOST_INTERPROCESS_PERFECT_FORWARDING
#error "This file is not needed when perfect forwarding is available"
#endif
#endif //#ifndef BOOST_INTERPROCESS_DETAIL_PREPROCESSOR_HPP
