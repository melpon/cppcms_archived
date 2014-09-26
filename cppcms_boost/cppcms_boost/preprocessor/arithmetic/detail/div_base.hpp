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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARITHMETIC_DETAIL_DIV_BASE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARITHMETIC_DETAIL_DIV_BASE_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/arithmetic/sub.hpp>
# include <cppcms_boost/preprocessor/comparison/less_equal.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_DIV_BASE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_DIV_BASE(x, y) CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_DIV_BASE_P, CPPCMS_BOOST_PP_DIV_BASE_O, (0, x, y))
# else
#    define CPPCMS_BOOST_PP_DIV_BASE(x, y) CPPCMS_BOOST_PP_DIV_BASE_I(x, y)
#    define CPPCMS_BOOST_PP_DIV_BASE_I(x, y) CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_DIV_BASE_P, CPPCMS_BOOST_PP_DIV_BASE_O, (0, x, y))
# endif
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_DIV_BASE_P(d, rxy) CPPCMS_BOOST_PP_DIV_BASE_P_IM(d, CPPCMS_BOOST_PP_TUPLE_REM_3 rxy)
#    define CPPCMS_BOOST_PP_DIV_BASE_P_IM(d, im) CPPCMS_BOOST_PP_DIV_BASE_P_I(d, im)
# else
#    define CPPCMS_BOOST_PP_DIV_BASE_P(d, rxy) CPPCMS_BOOST_PP_DIV_BASE_P_I(d, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, rxy), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, rxy), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define CPPCMS_BOOST_PP_DIV_BASE_P_I(d, r, x, y) CPPCMS_BOOST_PP_LESS_EQUAL_D(d, y, x)
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_DIV_BASE_O(d, rxy) CPPCMS_BOOST_PP_DIV_BASE_O_IM(d, CPPCMS_BOOST_PP_TUPLE_REM_3 rxy)
#    define CPPCMS_BOOST_PP_DIV_BASE_O_IM(d, im) CPPCMS_BOOST_PP_DIV_BASE_O_I(d, im)
# else
#    define CPPCMS_BOOST_PP_DIV_BASE_O(d, rxy) CPPCMS_BOOST_PP_DIV_BASE_O_I(d, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, rxy), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, rxy), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define CPPCMS_BOOST_PP_DIV_BASE_O_I(d, r, x, y) (CPPCMS_BOOST_PP_INC(r), CPPCMS_BOOST_PP_SUB_D(d, x, y), y)
#
# /* BOOST_PP_DIV_BASE_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_DIV_BASE_D(d, x, y) CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_DIV_BASE_P, CPPCMS_BOOST_PP_DIV_BASE_O, (0, x, y))
# else
#    define CPPCMS_BOOST_PP_DIV_BASE_D(d, x, y) CPPCMS_BOOST_PP_DIV_BASE_D_I(d, x, y)
#    define CPPCMS_BOOST_PP_DIV_BASE_D_I(d, x, y) CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_DIV_BASE_P, CPPCMS_BOOST_PP_DIV_BASE_O, (0, x, y))
# endif
#
# endif
