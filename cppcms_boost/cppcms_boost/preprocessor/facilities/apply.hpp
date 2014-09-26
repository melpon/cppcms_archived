# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef CPPCMS_BOOST_PREPROCESSOR_FACILITIES_APPLY_HPP
# define CPPCMS_BOOST_PREPROCESSOR_FACILITIES_APPLY_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/expr_iif.hpp>
# include <cppcms_boost/preprocessor/detail/is_unary.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_APPLY */
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_APPLY(x) CPPCMS_BOOST_PP_APPLY_I(x)
#    define CPPCMS_BOOST_PP_APPLY_I(x) CPPCMS_BOOST_PP_EXPR_IIF(CPPCMS_BOOST_PP_IS_UNARY(x), CPPCMS_BOOST_PP_TUPLE_REM_1 x)
# elif CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_BCC()
#    define CPPCMS_BOOST_PP_APPLY(x) CPPCMS_BOOST_PP_APPLY_I(x)
#    define CPPCMS_BOOST_PP_APPLY_I(x) CPPCMS_BOOST_PP_APPLY_ ## x
#    define CPPCMS_BOOST_PP_APPLY_(x) x
#    define CPPCMS_BOOST_PP_APPLY_CPPCMS_BOOST_PP_NIL
# else
#    define CPPCMS_BOOST_PP_APPLY(x) CPPCMS_BOOST_PP_EXPR_IIF(CPPCMS_BOOST_PP_IS_UNARY(x), CPPCMS_BOOST_PP_TUPLE_REM_1 x)
# endif
#
# endif
