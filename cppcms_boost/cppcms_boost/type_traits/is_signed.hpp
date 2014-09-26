
//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef CPPCMS_BOOST_TT_IS_SIGNED_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_SIGNED_HPP_INCLUDED

#include <cppcms_boost/type_traits/is_integral.hpp>
#include <cppcms_boost/type_traits/remove_cv.hpp>
#include <cppcms_boost/type_traits/is_enum.hpp>
#include <cppcms_boost/type_traits/detail/ice_or.hpp>

// should be the last #include
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

#if !defined( __CODEGEARC__ )

namespace detail{

#if !(defined(__EDG_VERSION__) && __EDG_VERSION__ <= 238)

template <class T>
struct is_signed_helper
{
   typedef typename remove_cv<T>::type no_cv_t;
   CPPCMS_BOOST_STATIC_CONSTANT(bool, value = (!(static_cast<no_cv_t>(-1) > 0)));
};

template <bool integral_type>
struct is_signed_select_helper
{
   template <class T>
   struct rebind
   {
      typedef is_signed_helper<T> type;
   };
};

template <>
struct is_signed_select_helper<false>
{
   template <class T>
   struct rebind
   {
      typedef false_type type;
   };
};

template <class T>
struct is_signed_imp
{
   typedef is_signed_select_helper< 
      ::cppcms_boost::type_traits::ice_or<
         ::cppcms_boost::is_integral<T>::value,
         ::cppcms_boost::is_enum<T>::value>::value 
   > selector;
   typedef typename selector::template rebind<T> binder;
   typedef typename binder::type type;
#if defined(CPPCMS_BOOST_MSVC) && (CPPCMS_BOOST_MSVC < 1300)
   CPPCMS_BOOST_STATIC_CONSTANT(bool, value = is_signed_imp<T>::type::value);
#else
   CPPCMS_BOOST_STATIC_CONSTANT(bool, value = type::value);
#endif
};

#else

template <class T> struct is_signed_imp : public false_type{};
template <> struct is_signed_imp<signed char> : public true_type{};
template <> struct is_signed_imp<const signed char> : public true_type{};
template <> struct is_signed_imp<volatile signed char> : public true_type{};
template <> struct is_signed_imp<const volatile signed char> : public true_type{};
template <> struct is_signed_imp<short> : public true_type{};
template <> struct is_signed_imp<const short> : public true_type{};
template <> struct is_signed_imp<volatile short> : public true_type{};
template <> struct is_signed_imp<const volatile short> : public true_type{};
template <> struct is_signed_imp<int> : public true_type{};
template <> struct is_signed_imp<const int> : public true_type{};
template <> struct is_signed_imp<volatile int> : public true_type{};
template <> struct is_signed_imp<const volatile int> : public true_type{};
template <> struct is_signed_imp<long> : public true_type{};
template <> struct is_signed_imp<const long> : public true_type{};
template <> struct is_signed_imp<volatile long> : public true_type{};
template <> struct is_signed_imp<const volatile long> : public true_type{};
#ifdef CPPCMS_BOOST_HAS_LONG_LONG
template <> struct is_signed_imp<long long> : public true_type{};
template <> struct is_signed_imp<const long long> : public true_type{};
template <> struct is_signed_imp<volatile long long> : public true_type{};
template <> struct is_signed_imp<const volatile long long> : public true_type{};
#endif
#if defined(CHAR_MIN) && (CHAR_MIN != 0)
template <> struct is_signed_imp<char> : public true_type{};
template <> struct is_signed_imp<const char> : public true_type{};
template <> struct is_signed_imp<volatile char> : public true_type{};
template <> struct is_signed_imp<const volatile char> : public true_type{};
#endif
#if defined(WCHAR_MIN) && (WCHAR_MIN != 0)
template <> struct is_signed_imp<wchar_t> : public true_type{};
template <> struct is_signed_imp<const wchar_t> : public true_type{};
template <> struct is_signed_imp<volatile wchar_t> : public true_type{};
template <> struct is_signed_imp<const volatile wchar_t> : public true_type{};
#endif

#endif

}

#endif // !defined( __CODEGEARC__ )

#if defined( __CODEGEARC__ )
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_signed,T,__is_signed(T))
#else
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_signed,T,::cppcms_boost::detail::is_signed_imp<T>::value)
#endif

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
