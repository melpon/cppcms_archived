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
# ifndef CPPCMS_BOOST_PREPROCESSOR_COMPARISON_LESS_EQUAL_HPP
# define CPPCMS_BOOST_PREPROCESSOR_COMPARISON_LESS_EQUAL_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/sub.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/logical/not.hpp>
#
# /* BOOST_PP_LESS_EQUAL */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LESS_EQUAL(x, y) CPPCMS_BOOST_PP_NOT(CPPCMS_BOOST_PP_SUB(x, y))
# else
#    define CPPCMS_BOOST_PP_LESS_EQUAL(x, y) CPPCMS_BOOST_PP_LESS_EQUAL_I(x, y)
#    define CPPCMS_BOOST_PP_LESS_EQUAL_I(x, y) CPPCMS_BOOST_PP_NOT(CPPCMS_BOOST_PP_SUB(x, y))
# endif
#
# /* BOOST_PP_LESS_EQUAL_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LESS_EQUAL_D(d, x, y) CPPCMS_BOOST_PP_NOT(CPPCMS_BOOST_PP_SUB_D(d, x, y))
# else
#    define CPPCMS_BOOST_PP_LESS_EQUAL_D(d, x, y) CPPCMS_BOOST_PP_LESS_EQUAL_D_I(d, x, y)
#    define CPPCMS_BOOST_PP_LESS_EQUAL_D_I(d, x, y) CPPCMS_BOOST_PP_NOT(CPPCMS_BOOST_PP_SUB_D(d, x, y))
# endif
#
# endif
