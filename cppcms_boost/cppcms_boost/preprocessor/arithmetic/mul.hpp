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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARITHMETIC_MUL_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARITHMETIC_MUL_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/add.hpp>
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_MUL */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_MUL(x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_MUL_P, CPPCMS_BOOST_PP_MUL_O, (0, x, y)))
# else
#    define CPPCMS_BOOST_PP_MUL(x, y) CPPCMS_BOOST_PP_MUL_I(x, y)
#    define CPPCMS_BOOST_PP_MUL_I(x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_MUL_P, CPPCMS_BOOST_PP_MUL_O, (0, x, y)))
# endif
#
# define CPPCMS_BOOST_PP_MUL_P(d, rxy) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, rxy)
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_MUL_O(d, rxy) CPPCMS_BOOST_PP_MUL_O_IM(d, CPPCMS_BOOST_PP_TUPLE_REM_3 rxy)
#    define CPPCMS_BOOST_PP_MUL_O_IM(d, im) CPPCMS_BOOST_PP_MUL_O_I(d, im)
# else
#    define CPPCMS_BOOST_PP_MUL_O(d, rxy) CPPCMS_BOOST_PP_MUL_O_I(d, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, rxy), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, rxy), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define CPPCMS_BOOST_PP_MUL_O_I(d, r, x, y) (CPPCMS_BOOST_PP_ADD_D(d, r, x), x, CPPCMS_BOOST_PP_DEC(y))
#
# /* BOOST_PP_MUL_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_MUL_D(d, x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_MUL_P, CPPCMS_BOOST_PP_MUL_O, (0, x, y)))
# else
#    define CPPCMS_BOOST_PP_MUL_D(d, x, y) CPPCMS_BOOST_PP_MUL_D_I(d, x, y)
#    define CPPCMS_BOOST_PP_MUL_D_I(d, x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_MUL_P, CPPCMS_BOOST_PP_MUL_O, (0, x, y)))
# endif
#
# endif
