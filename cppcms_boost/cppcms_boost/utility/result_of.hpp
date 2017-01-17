// Boost result_of library

//  Copyright Douglas Gregor 2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org/libs/utility
#ifndef CPPCMS_BOOST_RESULT_OF_HPP
#define CPPCMS_BOOST_RESULT_OF_HPP

#include <cppcms_boost/config.hpp>
#include <cppcms_boost/type_traits/ice.hpp>
#include <cppcms_boost/type.hpp>
#include <cppcms_boost/preprocessor.hpp>
#include <cppcms_boost/detail/workaround.hpp>
#include <cppcms_boost/mpl/has_xxx.hpp>
#include <cppcms_boost/mpl/if.hpp>
#include <cppcms_boost/mpl/bool.hpp>

#ifndef CPPCMS_BOOST_RESULT_OF_NUM_ARGS
#  define CPPCMS_BOOST_RESULT_OF_NUM_ARGS 10
#endif

namespace cppcms_boost {

template<typename F> struct result_of;

#if !defined(CPPCMS_BOOST_NO_SFINAE) && !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
namespace detail {

CPPCMS_BOOST_MPL_HAS_XXX_TRAIT_DEF(result_type)

template<typename F, typename FArgs, bool HasResultType> struct result_of_impl;

template<typename F>
struct result_of_void_impl
{
  typedef void type;
};

template<typename R>
struct result_of_void_impl<R (*)(void)>
{
  typedef R type;
};

template<typename R>
struct result_of_void_impl<R (&)(void)>
{
  typedef R type;
};

template<typename F, typename FArgs>
struct result_of_impl<F, FArgs, true>
{
  typedef typename F::result_type type;
};

template<typename FArgs>
struct is_function_with_no_args : mpl::false_ {};

template<typename F>
struct is_function_with_no_args<F(void)> : mpl::true_ {};

template<typename F, typename FArgs>
struct result_of_nested_result : F::template result<FArgs>
{};

template<typename F, typename FArgs>
struct result_of_impl<F, FArgs, false>
  : mpl::if_<is_function_with_no_args<FArgs>,
             result_of_void_impl<F>,
             result_of_nested_result<F, FArgs> >::type
{};

} // end namespace detail

#define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 (3,(0,CPPCMS_BOOST_RESULT_OF_NUM_ARGS,<cppcms_boost/utility/detail/result_of_iterate.hpp>))
#include CPPCMS_BOOST_PP_ITERATE()

#else
#  define CPPCMS_BOOST_NO_RESULT_OF 1
#endif

}

#endif // BOOST_RESULT_OF_HPP
