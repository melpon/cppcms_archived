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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_APPEND_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_APPEND_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/fold_right.hpp>
#
# /* BOOST_PP_LIST_APPEND */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_APPEND(a, b) CPPCMS_BOOST_PP_LIST_FOLD_RIGHT(CPPCMS_BOOST_PP_LIST_APPEND_O, b, a)
# else
#    define CPPCMS_BOOST_PP_LIST_APPEND(a, b) CPPCMS_BOOST_PP_LIST_APPEND_I(a, b)
#    define CPPCMS_BOOST_PP_LIST_APPEND_I(a, b) CPPCMS_BOOST_PP_LIST_FOLD_RIGHT(CPPCMS_BOOST_PP_LIST_APPEND_O, b, a)
# endif
#
# define CPPCMS_BOOST_PP_LIST_APPEND_O(d, s, x) (x, s)
#
# /* BOOST_PP_LIST_APPEND_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_APPEND_D(d, a, b) CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(CPPCMS_BOOST_PP_LIST_APPEND_O, b, a)
# else
#    define CPPCMS_BOOST_PP_LIST_APPEND_D(d, a, b) CPPCMS_BOOST_PP_LIST_APPEND_D_I(d, a, b)
#    define CPPCMS_BOOST_PP_LIST_APPEND_D_I(d, a, b) CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(CPPCMS_BOOST_PP_LIST_APPEND_O, b, a)
# endif
#
# endif
