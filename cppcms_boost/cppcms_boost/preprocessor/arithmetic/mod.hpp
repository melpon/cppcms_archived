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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARITHMETIC_MOD_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARITHMETIC_MOD_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/detail/div_base.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_MOD */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_MOD(x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, CPPCMS_BOOST_PP_DIV_BASE(x, y))
# else
#    define CPPCMS_BOOST_PP_MOD(x, y) CPPCMS_BOOST_PP_MOD_I(x, y)
#    define CPPCMS_BOOST_PP_MOD_I(x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, CPPCMS_BOOST_PP_DIV_BASE(x, y))
# endif
#
# /* BOOST_PP_MOD_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_MOD_D(d, x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, CPPCMS_BOOST_PP_DIV_BASE_D(d, x, y))
# else
#    define CPPCMS_BOOST_PP_MOD_D(d, x, y) CPPCMS_BOOST_PP_MOD_D_I(d, x, y)
#    define CPPCMS_BOOST_PP_MOD_D_I(d, x, y) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, CPPCMS_BOOST_PP_DIV_BASE_D(d, x, y))
# endif
#
# endif
