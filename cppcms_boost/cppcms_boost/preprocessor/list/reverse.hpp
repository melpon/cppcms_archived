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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_REVERSE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_REVERSE_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/fold_left.hpp>
#
# /* BOOST_PP_LIST_REVERSE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_REVERSE(list) CPPCMS_BOOST_PP_LIST_FOLD_LEFT(CPPCMS_BOOST_PP_LIST_REVERSE_O, CPPCMS_BOOST_PP_NIL, list)
# else
#    define CPPCMS_BOOST_PP_LIST_REVERSE(list) CPPCMS_BOOST_PP_LIST_REVERSE_I(list)
#    define CPPCMS_BOOST_PP_LIST_REVERSE_I(list) CPPCMS_BOOST_PP_LIST_FOLD_LEFT(CPPCMS_BOOST_PP_LIST_REVERSE_O, CPPCMS_BOOST_PP_NIL, list)
# endif
#
# define CPPCMS_BOOST_PP_LIST_REVERSE_O(d, s, x) (x, s)
#
# /* BOOST_PP_LIST_REVERSE_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_REVERSE_D(d, list) CPPCMS_BOOST_PP_LIST_FOLD_LEFT_ ## d(CPPCMS_BOOST_PP_LIST_REVERSE_O, CPPCMS_BOOST_PP_NIL, list)
# else
#    define CPPCMS_BOOST_PP_LIST_REVERSE_D(d, list) CPPCMS_BOOST_PP_LIST_REVERSE_D_I(d, list)
#    define CPPCMS_BOOST_PP_LIST_REVERSE_D_I(d, list) CPPCMS_BOOST_PP_LIST_FOLD_LEFT_ ## d(CPPCMS_BOOST_PP_LIST_REVERSE_O, CPPCMS_BOOST_PP_NIL, list)
# endif
#
# endif
