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
# ifndef CPPCMS_BOOST_PREPROCESSOR_REPETITION_ENUM_SHIFTED_HPP
# define CPPCMS_BOOST_PREPROCESSOR_REPETITION_ENUM_SHIFTED_HPP
#
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/debug/error.hpp>
# include <cppcms_boost/preprocessor/detail/auto_rec.hpp>
# include <cppcms_boost/preprocessor/punctuation/comma_if.hpp>
# include <cppcms_boost/preprocessor/repetition/repeat.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_ENUM_SHIFTED */
#
# if 0
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED(count, macro, data)
# endif
#
# define CPPCMS_BOOST_PP_ENUM_SHIFTED CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ENUM_SHIFTED_, CPPCMS_BOOST_PP_AUTO_REC(CPPCMS_BOOST_PP_REPEAT_P, 4))
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_1(c, m, d) CPPCMS_BOOST_PP_REPEAT_1(CPPCMS_BOOST_PP_DEC(c), CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1, (m, d))
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_2(c, m, d) CPPCMS_BOOST_PP_REPEAT_2(CPPCMS_BOOST_PP_DEC(c), CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2, (m, d))
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_3(c, m, d) CPPCMS_BOOST_PP_REPEAT_3(CPPCMS_BOOST_PP_DEC(c), CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3, (m, d))
# else
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_1(c, m, d) CPPCMS_BOOST_PP_ENUM_SHIFTED_1_I(c, m, d)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_2(c, m, d) CPPCMS_BOOST_PP_ENUM_SHIFTED_1_2(c, m, d)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_3(c, m, d) CPPCMS_BOOST_PP_ENUM_SHIFTED_1_3(c, m, d)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_1_I(c, m, d) CPPCMS_BOOST_PP_REPEAT_1(CPPCMS_BOOST_PP_DEC(c), CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1, (m, d))
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_2_I(c, m, d) CPPCMS_BOOST_PP_REPEAT_2(CPPCMS_BOOST_PP_DEC(c), CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2, (m, d))
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_3_I(c, m, d) CPPCMS_BOOST_PP_REPEAT_3(CPPCMS_BOOST_PP_DEC(c), CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3, (m, d))
# endif
#
# define CPPCMS_BOOST_PP_ENUM_SHIFTED_4(c, m, d) CPPCMS_BOOST_PP_ERROR(0x0003)
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1(z, n, md) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1_IM(z, n, CPPCMS_BOOST_PP_TUPLE_REM_2 md)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2(z, n, md) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2_IM(z, n, CPPCMS_BOOST_PP_TUPLE_REM_2 md)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3(z, n, md) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3_IM(z, n, CPPCMS_BOOST_PP_TUPLE_REM_2 md)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1_IM(z, n, im) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1_I(z, n, im)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2_IM(z, n, im) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2_I(z, n, im)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3_IM(z, n, im) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3_I(z, n, im)
# else
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1(z, n, md) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1_I(z, n, CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, md), CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, md))
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2(z, n, md) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2_I(z, n, CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, md), CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, md))
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3(z, n, md) CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3_I(z, n, CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, md), CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, md))
# endif
#
# define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_1_I(z, n, m, d) CPPCMS_BOOST_PP_COMMA_IF(n) m(z, CPPCMS_BOOST_PP_INC(n), d)
# define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_2_I(z, n, m, d) CPPCMS_BOOST_PP_COMMA_IF(n) m(z, CPPCMS_BOOST_PP_INC(n), d)
# define CPPCMS_BOOST_PP_ENUM_SHIFTED_M_3_I(z, n, m, d) CPPCMS_BOOST_PP_COMMA_IF(n) m(z, CPPCMS_BOOST_PP_INC(n), d)
#
# endif
