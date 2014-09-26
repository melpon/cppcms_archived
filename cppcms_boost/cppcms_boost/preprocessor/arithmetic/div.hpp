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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARITHMETIC_DIV_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARITHMETIC_DIV_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/detail/div_base.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_DIV */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_DIV(x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, CPPCMS_BOOST_PP_DIV_BASE(x, y))
# else
#    define CPPCMS_BOOST_PP_DIV(x, y) CPPCMS_BOOST_PP_DIV_I(x, y)
#    define CPPCMS_BOOST_PP_DIV_I(x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, CPPCMS_BOOST_PP_DIV_BASE(x, y))
# endif
#
# /* BOOST_PP_DIV_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_DIV_D(d, x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, CPPCMS_BOOST_PP_DIV_BASE_D(d, x, y))
# else
#    define CPPCMS_BOOST_PP_DIV_D(d, x, y) CPPCMS_BOOST_PP_DIV_D_I(d, x, y)
#    define CPPCMS_BOOST_PP_DIV_D_I(d, x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, CPPCMS_BOOST_PP_DIV_BASE_D(d, x, y))
# endif
#
# endif
