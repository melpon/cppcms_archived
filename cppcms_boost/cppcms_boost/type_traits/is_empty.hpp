
// (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef CPPCMS_BOOST_TT_IS_EMPTY_HPP_INCLUDED
#define CPPCMS_BOOST_TT_IS_EMPTY_HPP_INCLUDED

#include <cppcms_boost/type_traits/is_convertible.hpp>
#include <cppcms_boost/type_traits/detail/ice_or.hpp>
#include <cppcms_boost/type_traits/config.hpp>
#include <cppcms_boost/type_traits/intrinsics.hpp>

#ifndef CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   include <cppcms_boost/type_traits/remove_cv.hpp>
#   include <cppcms_boost/type_traits/is_class.hpp>
#   include <cppcms_boost/type_traits/add_reference.hpp>
#else
#   include <cppcms_boost/type_traits/is_reference.hpp>
#   include <cppcms_boost/type_traits/is_pointer.hpp>
#   include <cppcms_boost/type_traits/is_member_pointer.hpp>
#   include <cppcms_boost/type_traits/is_array.hpp>
#   include <cppcms_boost/type_traits/is_void.hpp>
#   include <cppcms_boost/type_traits/detail/ice_and.hpp>
#   include <cppcms_boost/type_traits/detail/ice_not.hpp>
#endif

// should be always the last #include directive
#include <cppcms_boost/type_traits/detail/bool_trait_def.hpp>

namespace cppcms_boost {

namespace detail {

#ifndef CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template <typename T>
struct empty_helper_t1 : public T
{
    empty_helper_t1();  // hh compiler bug workaround
    int i[256];
private:
   // suppress compiler warnings:
   empty_helper_t1(const empty_helper_t1&);
   empty_helper_t1& operator=(const empty_helper_t1&);
};

struct empty_helper_t2 { int i[256]; };

#if !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600)

template <typename T, bool is_a_class = false>
struct empty_helper
{
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

template <typename T>
struct empty_helper<T, true>
{
    CPPCMS_BOOST_STATIC_CONSTANT(
        bool, value = (sizeof(empty_helper_t1<T>) == sizeof(empty_helper_t2))
        );
};

template <typename T>
struct is_empty_impl
{
    typedef typename remove_cv<T>::type cvt;
    CPPCMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            ::cppcms_boost::type_traits::ice_or<
              ::cppcms_boost::detail::empty_helper<cvt,::cppcms_boost::is_class<T>::value>::value
              , CPPCMS_BOOST_IS_EMPTY(cvt)
            >::value
            ));
};

#else // __BORLANDC__

template <typename T, bool is_a_class, bool convertible_to_int>
struct empty_helper
{
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

template <typename T>
struct empty_helper<T, true, false>
{
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = (
        sizeof(empty_helper_t1<T>) == sizeof(empty_helper_t2)
        ));
};

template <typename T>
struct is_empty_impl
{
   typedef typename remove_cv<T>::type cvt;
   typedef typename add_reference<T>::type r_type;

   CPPCMS_BOOST_STATIC_CONSTANT(
       bool, value = (
           ::cppcms_boost::type_traits::ice_or<
              ::cppcms_boost::detail::empty_helper<
                  cvt
                , ::cppcms_boost::is_class<T>::value
                , ::cppcms_boost::is_convertible< r_type,int>::value
              >::value
              , CPPCMS_BOOST_IS_EMPTY(cvt)
           >::value));
};

#endif // __BORLANDC__

#else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#ifdef CPPCMS_BOOST_MSVC6_MEMBER_TEMPLATES

template <typename T>
struct empty_helper_t1 : public T
{
   empty_helper_t1();
   int i[256];
};

struct empty_helper_t2 { int i[256]; };

template <typename T>
struct empty_helper_base
{
   enum { value = (sizeof(empty_helper_t1<T>) == sizeof(empty_helper_t2)) };
};

template <typename T>
struct empty_helper_nonbase
{
   enum { value = false };
};

template <bool base>
struct empty_helper_chooser
{
   template <typename T> struct result_
   {
      typedef empty_helper_nonbase<T> type;
   };
};

template <>
struct empty_helper_chooser<true>
{
   template <typename T> struct result_
   {
      typedef empty_helper_base<T> type;
   };
};

template <typename T>
struct is_empty_impl
{
   typedef ::cppcms_boost::detail::empty_helper_chooser<
      ::cppcms_boost::type_traits::ice_and<
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_reference<T>::value >::value,
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_convertible<T,double>::value >::value,
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_pointer<T>::value >::value,
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_member_pointer<T>::value >::value,
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_array<T>::value >::value,
         ::cppcms_boost::type_traits::ice_not< ::cppcms_boost::is_void<T>::value >::value,
         ::cppcms_boost::type_traits::ice_not<
            ::cppcms_boost::is_convertible<T,void const volatile*>::value
            >::value
      >::value > chooser;

   typedef typename chooser::template result_<T> result;
   typedef typename result::type eh_type;

   CPPCMS_BOOST_STATIC_CONSTANT(bool, value =
      (::cppcms_boost::type_traits::ice_or<eh_type::value, CPPCMS_BOOST_IS_EMPTY(T)>::value));
};

#else

template <typename T> struct is_empty_impl
{
    CPPCMS_BOOST_STATIC_CONSTANT(bool, value = CPPCMS_BOOST_IS_EMPTY(T));
};

#endif  // BOOST_MSVC6_MEMBER_TEMPLATES

#endif  // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

// these help when the compiler has no partial specialization support:
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_empty,void,false)
#ifndef CPPCMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_empty,void const,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_empty,void volatile,false)
CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(is_empty,void const volatile,false)
#endif

} // namespace detail

CPPCMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_empty,T,::cppcms_boost::detail::is_empty_impl<T>::value)

} // namespace boost

#include <cppcms_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_IS_EMPTY_HPP_INCLUDED

