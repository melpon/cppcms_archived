# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef CPPCMS_BOOST_PREPROCESSOR_COMPARISON_LESS_HPP
# define CPPCMS_BOOST_PREPROCESSOR_COMPARISON_LESS_HPP
#
# include <cppcms_boost/preprocessor/comparison/less_equal.hpp>
# include <cppcms_boost/preprocessor/comparison/not_equal.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/iif.hpp>
# include <cppcms_boost/preprocessor/logical/bitand.hpp>
# include <cppcms_boost/preprocessor/tuple/eat.hpp>
#
# /* BOOST_PP_LESS */
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & (CPPCMS_BOOST_PP_CONFIG_MWCC() | CPPCMS_BOOST_PP_CONFIG_DMC())
#    define CPPCMS_BOOST_PP_LESS(x, y) CPPCMS_BOOST_PP_BITAND(CPPCMS_BOOST_PP_NOT_EQUAL(x, y), CPPCMS_BOOST_PP_LESS_EQUAL(x, y))
# elif ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LESS(x, y) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(x, y), CPPCMS_BOOST_PP_LESS_EQUAL, 0 CPPCMS_BOOST_PP_TUPLE_EAT_2)(x, y)
# else
#    define CPPCMS_BOOST_PP_LESS(x, y) CPPCMS_BOOST_PP_LESS_I(x, y)
#    define CPPCMS_BOOST_PP_LESS_I(x, y) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(x, y), CPPCMS_BOOST_PP_LESS_EQUAL, 0 CPPCMS_BOOST_PP_TUPLE_EAT_2)(x, y)
# endif
#
# /* BOOST_PP_LESS_D */
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & (CPPCMS_BOOST_PP_CONFIG_MWCC() | CPPCMS_BOOST_PP_CONFIG_DMC())
#    define CPPCMS_BOOST_PP_LESS_D(d, x, y) CPPCMS_BOOST_PP_BITAND(CPPCMS_BOOST_PP_NOT_EQUAL(x, y), CPPCMS_BOOST_PP_LESS_EQUAL_D(d, x, y))
# elif ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LESS_D(d, x, y) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(x, y), CPPCMS_BOOST_PP_LESS_EQUAL_D, 0 CPPCMS_BOOST_PP_TUPLE_EAT_3)(d, x, y)
# else
#    define CPPCMS_BOOST_PP_LESS_D(d, x, y) CPPCMS_BOOST_PP_LESS_D_I(d, x, y)
#    define CPPCMS_BOOST_PP_LESS_D_I(d, x, y) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(x, y), CPPCMS_BOOST_PP_LESS_EQUAL_D, 0 CPPCMS_BOOST_PP_TUPLE_EAT_3)(d, x, y)
# endif
#
# endif
