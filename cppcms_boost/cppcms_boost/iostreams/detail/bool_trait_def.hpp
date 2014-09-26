// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef CPPCMS_BOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED
#define CPPCMS_BOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED     

#include <cppcms_boost/config.hpp> // BOOST_STATIC_CONSTANT.
#include <cppcms_boost/iostreams/detail/template_params.hpp>
#include <cppcms_boost/mpl/aux_/lambda_support.hpp>
#include <cppcms_boost/mpl/bool.hpp>
#include <cppcms_boost/preprocessor/cat.hpp>
#include <cppcms_boost/preprocessor/repetition/enum_params.hpp>
#include <cppcms_boost/type_traits/detail/yes_no_type.hpp>
 
// 
// Macro name: BOOST_IOSTREAMS_BOOL_TRAIT_DEF
// Description: Used to generate the traits classes is_istream, is_ostream,
//      etc.
//
#if CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x582))
# define CPPCMS_BOOST_IOSTREAMS_TRAIT_NAMESPACE(trait)
#else
# define CPPCMS_BOOST_IOSTREAMS_TRAIT_NAMESPACE(trait) CPPCMS_BOOST_PP_CAT(trait, _impl_):: 
#endif
#define CPPCMS_BOOST_IOSTREAMS_BOOL_TRAIT_DEF(trait, type, arity) \
    namespace CPPCMS_BOOST_PP_CAT(trait, _impl_) { \
      CPPCMS_BOOST_IOSTREAMS_TEMPLATE_PARAMS(arity, T) \
      type_traits::yes_type helper \
          (const volatile type CPPCMS_BOOST_IOSTREAMS_TEMPLATE_ARGS(arity, T)*); \
      type_traits::no_type helper(...); \
      template<typename T> \
      struct impl { \
           CPPCMS_BOOST_STATIC_CONSTANT(bool, value = \
           (sizeof(CPPCMS_BOOST_IOSTREAMS_TRAIT_NAMESPACE(trait) \
              helper(static_cast<T*>(0))) == \
                sizeof(type_traits::yes_type))); \
      }; \
    } \
    template<typename T> \
    struct trait \
        : mpl::bool_<CPPCMS_BOOST_PP_CAT(trait, _impl_)::impl<T>::value> \
    { CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1, trait, (T)) }; \
    /**/

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED
