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
# ifndef CPPCMS_BOOST_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_HPP
# define CPPCMS_BOOST_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/add.hpp>
# include <cppcms_boost/preprocessor/arithmetic/sub.hpp>
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/debug/error.hpp>
# include <cppcms_boost/preprocessor/detail/auto_rec.hpp>
# include <cppcms_boost/preprocessor/repetition/repeat.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_REPEAT_FROM_TO */
#
# if 0
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO(first, last, macro, data)
# endif
#
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_REPEAT_FROM_TO_, CPPCMS_BOOST_PP_AUTO_REC(CPPCMS_BOOST_PP_REPEAT_P, 4))
#
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_1(f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_1(CPPCMS_BOOST_PP_AUTO_REC(CPPCMS_BOOST_PP_WHILE_P, 256), f, l, m, dt)
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_2(f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_2(CPPCMS_BOOST_PP_AUTO_REC(CPPCMS_BOOST_PP_WHILE_P, 256), f, l, m, dt)
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_3(f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_3(CPPCMS_BOOST_PP_AUTO_REC(CPPCMS_BOOST_PP_WHILE_P, 256), f, l, m, dt)
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_4(f, l, m, dt) CPPCMS_BOOST_PP_ERROR(0x0003)
#
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_1ST CPPCMS_BOOST_PP_REPEAT_FROM_TO_1
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_2ND CPPCMS_BOOST_PP_REPEAT_FROM_TO_2
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_3RD CPPCMS_BOOST_PP_REPEAT_FROM_TO_3
#
# /* BOOST_PP_REPEAT_FROM_TO_D */
#
# if 0
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D(d, first, last, macro, data)
# endif
#
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_, CPPCMS_BOOST_PP_AUTO_REC(CPPCMS_BOOST_PP_REPEAT_P, 4))
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_1(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_1(CPPCMS_BOOST_PP_SUB_D(d, l, f), CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1, (d, f, m, dt))
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_2(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_2(CPPCMS_BOOST_PP_SUB_D(d, l, f), CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2, (d, f, m, dt))
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_3(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_3(CPPCMS_BOOST_PP_SUB_D(d, l, f), CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3, (d, f, m, dt))
# else
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_1(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_1_I(d, f, l, m, dt)
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_2(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_2_I(d, f, l, m, dt)
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_3(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_3_I(d, f, l, m, dt)
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_1_I(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_1(CPPCMS_BOOST_PP_SUB_D(d, l, f), CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1, (d, f, m, dt))
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_2_I(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_2(CPPCMS_BOOST_PP_SUB_D(d, l, f), CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2, (d, f, m, dt))
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_D_3_I(d, f, l, m, dt) CPPCMS_BOOST_PP_REPEAT_3(CPPCMS_BOOST_PP_SUB_D(d, l, f), CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3, (d, f, m, dt))
# endif
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1(z, n, dfmd) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1_IM(z, n, CPPCMS_BOOST_PP_TUPLE_REM_4 dfmd)
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2(z, n, dfmd) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2_IM(z, n, CPPCMS_BOOST_PP_TUPLE_REM_4 dfmd)
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3(z, n, dfmd) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3_IM(z, n, CPPCMS_BOOST_PP_TUPLE_REM_4 dfmd)
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1_IM(z, n, im) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, im)
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2_IM(z, n, im) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, im)
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3_IM(z, n, im) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, im)
# else
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1(z, n, dfmd) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 1, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, dfmd))
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2(z, n, dfmd) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 1, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, dfmd))
#    define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3(z, n, dfmd) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 1, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, dfmd), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, dfmd))
# endif
#
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, d, f, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1_II(z, CPPCMS_BOOST_PP_ADD_D(d, n, f), m, dt)
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, d, f, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2_II(z, CPPCMS_BOOST_PP_ADD_D(d, n, f), m, dt)
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, d, f, m, dt) CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3_II(z, CPPCMS_BOOST_PP_ADD_D(d, n, f), m, dt)
#
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_1_II(z, n, m, dt) m(z, n, dt)
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_2_II(z, n, m, dt) m(z, n, dt)
# define CPPCMS_BOOST_PP_REPEAT_FROM_TO_M_3_II(z, n, m, dt) m(z, n, dt)
#
# endif
