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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_CAT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_CAT_HPP
#
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/adt.hpp>
# include <cppcms_boost/preprocessor/list/fold_left.hpp>
#
# /* BOOST_PP_LIST_CAT */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_CAT(list) CPPCMS_BOOST_PP_LIST_FOLD_LEFT(CPPCMS_BOOST_PP_LIST_CAT_O, CPPCMS_BOOST_PP_LIST_FIRST(list), CPPCMS_BOOST_PP_LIST_REST(list))
# else
#    define CPPCMS_BOOST_PP_LIST_CAT(list) CPPCMS_BOOST_PP_LIST_CAT_I(list)
#    define CPPCMS_BOOST_PP_LIST_CAT_I(list) CPPCMS_BOOST_PP_LIST_FOLD_LEFT(CPPCMS_BOOST_PP_LIST_CAT_O, CPPCMS_BOOST_PP_LIST_FIRST(list), CPPCMS_BOOST_PP_LIST_REST(list))
# endif
#
# define CPPCMS_BOOST_PP_LIST_CAT_O(d, s, x) CPPCMS_BOOST_PP_CAT(s, x)
#
# /* BOOST_PP_LIST_CAT_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_CAT_D(d, list) CPPCMS_BOOST_PP_LIST_FOLD_LEFT_ ## d(CPPCMS_BOOST_PP_LIST_CAT_O, CPPCMS_BOOST_PP_LIST_FIRST(list), CPPCMS_BOOST_PP_LIST_REST(list))
# else
#    define CPPCMS_BOOST_PP_LIST_CAT_D(d, list) CPPCMS_BOOST_PP_LIST_CAT_D_I(d, list)
#    define CPPCMS_BOOST_PP_LIST_CAT_D_I(d, list) CPPCMS_BOOST_PP_LIST_FOLD_LEFT_ ## d(CPPCMS_BOOST_PP_LIST_CAT_O, CPPCMS_BOOST_PP_LIST_FIRST(list), CPPCMS_BOOST_PP_LIST_REST(list))
# endif
#
# endif
