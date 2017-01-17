// Boost result_of library

//  Copyright Douglas Gregor 2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org/libs/utility
#if !defined(CPPCMS_BOOST_PP_IS_ITERATING)
# error Boost result_of - do not include this file!
#endif

// CWPro8 requires an argument in a function type specialization
#if CPPCMS_BOOST_WORKAROUND(__MWERKS__, CPPCMS_BOOST_TESTED_AT(0x3002)) && CPPCMS_BOOST_PP_ITERATION() == 0
# define CPPCMS_BOOST_RESULT_OF_ARGS void
#else
# define CPPCMS_BOOST_RESULT_OF_ARGS CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),T)
#endif

#if !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x551))
template<typename F CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_ITERATION())
         CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),typename T)>
struct result_of<F(CPPCMS_BOOST_RESULT_OF_ARGS)>
    : cppcms_boost::detail::result_of_impl<F, F(CPPCMS_BOOST_RESULT_OF_ARGS), (cppcms_boost::detail::has_result_type<F>::value)> {};
#endif

#undef CPPCMS_BOOST_RESULT_OF_ARGS

#if CPPCMS_BOOST_PP_ITERATION() >= 1 

namespace detail {

template<typename R,  typename FArgs CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_ITERATION())
         CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (*)(CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),T)), FArgs, false>
{
  typedef R type;
};

template<typename R,  typename FArgs CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_ITERATION())
         CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (&)(CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),T)), FArgs, false>
{
  typedef R type;
};

#if !CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x551))
template<typename R, typename FArgs CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_ITERATION())
         CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (T0::*)
                     (CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS(CPPCMS_BOOST_PP_ITERATION(),T)),
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_ITERATION())
         CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (T0::*)
                     (CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS(CPPCMS_BOOST_PP_ITERATION(),T))
                     const,
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_ITERATION())
         CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (T0::*)
                     (CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS(CPPCMS_BOOST_PP_ITERATION(),T))
                     volatile,
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs CPPCMS_BOOST_PP_COMMA_IF(CPPCMS_BOOST_PP_ITERATION())
         CPPCMS_BOOST_PP_ENUM_PARAMS(CPPCMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (T0::*)
                     (CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS(CPPCMS_BOOST_PP_ITERATION(),T))
                     const volatile,
                 FArgs, false>
{
  typedef R type;
};
#endif

}
#endif
