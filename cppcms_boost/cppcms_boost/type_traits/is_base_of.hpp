
//  (C) Copyright Rani Sharoni 2003-2005.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.
 
#ifndef CPPCMS_BOOST_TT_IS_BASE_OF_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_BASE_OF_HPP_INCLUDED

#include <cppcms_boost/type_traits/is_base_and_derived.hpp>
#include <cppcms_boost/type_traits/is_same.hpp>
#include <cppcms_boost/type_traits/is_class.hpp>
#include <cppcms_boost/type_traits/detail/ice_or.hpp>
#include <cppcms_boost/type_traits/detail/ice_and.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

   namespace detail{
      template <class B, class D>
      struct is_base_of_imp
      {
          typedef typename remove_cv<B>::type ncvB;
          typedef typename remove_cv<D>::type ncvD;
          CPPCMS_BOOST_STATIC_CONSTANT(bool, value = (::cppcms_boost::type_traits::ice_or<      
            (::cppcms_boost::detail::is_base_and_derived_impl<ncvB,ncvD>::value),
            (::cppcms_boost::type_traits::ice_and< ::cppcms_boost::is_same<ncvB,ncvD>::value, ::cppcms_boost::is_class<ncvB>::value>::value)>::value));
      };
   }

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF2(
      is_base_of
    , Base
    , Derived
    , (::cppcms_boost::detail::is_base_of_imp<Base, Derived>::value))

#ifndef CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_base_of,Base&,Derived,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_base_of,Base,Derived&,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_base_of,Base&,Derived&,false)
#endif

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_BASE_AND_DERIVED_HPP_INCLUDED
