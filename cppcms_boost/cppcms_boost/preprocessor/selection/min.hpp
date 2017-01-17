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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SELECTION_MIN_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SELECTION_MIN_HPP
#
# include <cppcms_boost/preprocessor/comparison/less_equal.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/iif.hpp>
#
# /* BOOST_PP_MIN */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_MIN(x, y) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_LESS_EQUAL(y, x), y, x)
# else
#    define CPPCMS_BOOST_PP_MIN(x, y) CPPCMS_BOOST_PP_MIN_I(x, y)
#    define CPPCMS_BOOST_PP_MIN_I(x, y) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_LESS_EQUAL(y, x), y, x)
# endif
#
# /* BOOST_PP_MIN_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_MIN_D(d, x, y) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_LESS_EQUAL_D(d, y, x), y, x)
# else
#    define CPPCMS_BOOST_PP_MIN_D(d, x, y) CPPCMS_BOOST_PP_MIN_D_I(d, x, y)
#    define CPPCMS_BOOST_PP_MIN_D_I(d, x, y) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_LESS_EQUAL_D(d, y, x), y, x)
# endif
#
# endif
