// Copyright David Abrahams 2004. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef IS_INCREMENTABLE_DWA200415_HPP
# define IS_INCREMENTABLE_DWA200415_HPP

# include <cppcms_boost/type_traits/detail/template_arity_spec.hpp>
# include <cppcms_boost/type_traits/remove_cv.hpp>
# include <cppcms_boost/mpl/aux_/lambda_support.hpp>
# include <cppcms_boost/mpl/bool.hpp>
# include <cppcms_boost/detail/workaround.hpp>

// Must be the last include
# include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost { namespace detail { 

// is_incrementable<T> metafunction
//
// Requires: Given x of type T&, if the expression ++x is well-formed
// it must have complete type; otherwise, it must neither be ambiguous
// nor violate access.

// This namespace ensures that ADL doesn't mess things up.
namespace is_incrementable_
{
  // a type returned from operator++ when no increment is found in the
  // type's own namespace
  struct tag {};
  
  // any soaks up implicit conversions and makes the following
  // operator++ less-preferred than any other such operator that
  // might be found via ADL.
  struct any { template <class T> any(T const&); };

  // This is a last-resort operator++ for when none other is found
# if CPPCMS_BOOST_WORKAROUND(__GNUC__, == 4) && __GNUC_MINOR__ == 0 && __GNUC_PATCHLEVEL__ == 2
  
}

namespace is_incrementable_2
{
  is_incrementable_::tag operator++(is_incrementable_::any const&);
  is_incrementable_::tag operator++(is_incrementable_::any const&,int);
}
using namespace is_incrementable_2;

namespace is_incrementable_
{
  
# else
  
  tag operator++(any const&);
  tag operator++(any const&,int);
  
# endif 

# if CPPCMS_BOOST_WORKAROUND(__MWERKS__, CPPCMS_BOOST_TESTED_AT(0x3202)) \
    || CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300)
#  define CPPCMS_BOOST_comma(a,b) (a)
# else 
  // In case an operator++ is found that returns void, we'll use ++x,0
  tag operator,(tag,int);  
#  define CPPCMS_BOOST_comma(a,b) (a,b)
# endif 

# if defined(CPPCMS_BOOST_MSVC)
#  pragma warning(push)
#  pragma warning(disable:4913) // Warning about operator,
# endif 

  // two check overloads help us identify which operator++ was picked
  char (& check(tag) )[2];
  
  template <class T>
  char check(T const&);
  

  template <class T>
  struct impl
  {
      static typename cppcms_boost::remove_cv<T>::type& x;

      CPPCMS_BOOST_STATIC_CONSTANT(
          bool
        , value = sizeof(is_incrementable_::check(CPPCMS_BOOST_comma(++x,0))) == 1
      );
  };

  template <class T>
  struct postfix_impl
  {
      static typename cppcms_boost::remove_cv<T>::type& x;

      CPPCMS_BOOST_STATIC_CONSTANT(
          bool
        , value = sizeof(is_incrementable_::check(CPPCMS_BOOST_comma(x++,0))) == 1
      );
  };

# if defined(CPPCMS_BOOST_MSVC)
#  pragma warning(pop)
# endif 

}

# undef CPPCMS_BOOST_comma

template<typename T> 
struct is_incrementable 
CPPCMS_BOOST_TT_AUX_BOOL_C_BASE(::cppcms_boost::detail::is_incrementable_::impl<T>::value)
{ 
    CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(::cppcms_boost::detail::is_incrementable_::impl<T>::value)
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,is_incrementable,(T))
};

template<typename T> 
struct is_postfix_incrementable 
CPPCMS_BOOST_TT_AUX_BOOL_C_BASE(::cppcms_boost::detail::is_incrementable_::impl<T>::value)
{ 
    CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(::cppcms_boost::detail::is_incrementable_::postfix_impl<T>::value)
    CPPCMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,is_postfix_incrementable,(T))
};

} // namespace detail

CPPCMS_BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(1, ::cppcms_boost::detail::is_incrementable)
CPPCMS_BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(1, ::cppcms_boost::detail::is_postfix_incrementable)

} // namespace boost

# include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // IS_INCREMENTABLE_DWA200415_HPP
