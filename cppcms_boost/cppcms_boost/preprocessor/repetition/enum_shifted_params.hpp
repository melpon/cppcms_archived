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
# ifndef CPPCMS_BOOST_PREPROCESSOR_REPETITION_ENUM_SHIFTED_PARAMS_HPP
# define CPPCMS_BOOST_PREPROCESSOR_REPETITION_ENUM_SHIFTED_PARAMS_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/punctuation/comma_if.hpp>
# include <cppcms_boost/preprocessor/repetition/repeat.hpp>
#
# /* BOOST_PP_ENUM_SHIFTED_PARAMS */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS(count, param) CPPCMS_BOOST_PP_REPEAT(CPPCMS_BOOST_PP_DEC(count), CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_M, param)
# else
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS(count, param) CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_I(count, param)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_I(count, param) CPPCMS_BOOST_PP_REPEAT(CPPCMS_BOOST_PP_DEC(count), CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_M, param)
# endif
#
# define CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_M(z, n, param) CPPCMS_BOOST_PP_COMMA_IF(n) CPPCMS_BOOST_PP_CAT(param, CPPCMS_BOOST_PP_INC(n))
#
# /* BOOST_PP_ENUM_SHIFTED_PARAMS_Z */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, count, param) CPPCMS_BOOST_PP_REPEAT_ ## z(CPPCMS_BOOST_PP_DEC(count), CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_M, param)
# else
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, count, param) CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_Z_I(z, count, param)
#    define CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_Z_I(z, count, param) CPPCMS_BOOST_PP_REPEAT_ ## z(CPPCMS_BOOST_PP_DEC(count), CPPCMS_BOOST_PP_ENUM_SHIFTED_PARAMS_M, param)
# endif
#
# endif
