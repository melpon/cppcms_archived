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
# ifndef CPPCMS_BOOST_PREPROCESSOR_REPETITION_ENUM_PARAMS_HPP
# define CPPCMS_BOOST_PREPROCESSOR_REPETITION_ENUM_PARAMS_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/punctuation/comma_if.hpp>
# include <cppcms_boost/preprocessor/repetition/repeat.hpp>
#
# /* BOOST_PP_ENUM_PARAMS */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ENUM_PARAMS(count, param) CPPCMS_BOOST_PP_REPEAT(count, CPPCMS_BOOST_PP_ENUM_PARAMS_M, param)
# else
#    define CPPCMS_BOOST_PP_ENUM_PARAMS(count, param) CPPCMS_BOOST_PP_ENUM_PARAMS_I(count, param)
#    define CPPCMS_BOOST_PP_ENUM_PARAMS_I(count, param) CPPCMS_BOOST_PP_REPEAT(count, CPPCMS_BOOST_PP_ENUM_PARAMS_M, param)
# endif
#
# define CPPCMS_BOOST_PP_ENUM_PARAMS_M(z, n, param) CPPCMS_BOOST_PP_COMMA_IF(n) param ## n
#
# /* BOOST_PP_ENUM_PARAMS_Z */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, count, param) CPPCMS_BOOST_PP_REPEAT_ ## z(count, CPPCMS_BOOST_PP_ENUM_PARAMS_M, param)
# else
#    define CPPCMS_BOOST_PP_ENUM_PARAMS_Z(z, count, param) CPPCMS_BOOST_PP_ENUM_PARAMS_Z_I(z, count, param)
#    define CPPCMS_BOOST_PP_ENUM_PARAMS_Z_I(z, count, param) CPPCMS_BOOST_PP_REPEAT_ ## z(count, CPPCMS_BOOST_PP_ENUM_PARAMS_M, param)
# endif
#
# endif
