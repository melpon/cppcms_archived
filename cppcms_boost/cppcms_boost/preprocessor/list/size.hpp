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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_SIZE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_SIZE_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/list/adt.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_LIST_SIZE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_SIZE(list) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_LIST_SIZE_P, CPPCMS_BOOST_PP_LIST_SIZE_O, (0, list)))
# else
#    define CPPCMS_BOOST_PP_LIST_SIZE(list) CPPCMS_BOOST_PP_LIST_SIZE_I(list)
#    define CPPCMS_BOOST_PP_LIST_SIZE_I(list) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_LIST_SIZE_P, CPPCMS_BOOST_PP_LIST_SIZE_O, (0, list)))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_SIZE_P(d, rl) CPPCMS_BOOST_PP_LIST_IS_CONS(CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, rl))
# else
#    define CPPCMS_BOOST_PP_LIST_SIZE_P(d, rl) CPPCMS_BOOST_PP_LIST_SIZE_P_I(CPPCMS_BOOST_PP_TUPLE_REM_2 rl)
#    define CPPCMS_BOOST_PP_LIST_SIZE_P_I(im) CPPCMS_BOOST_PP_LIST_SIZE_P_II(im)
#    define CPPCMS_BOOST_PP_LIST_SIZE_P_II(r, l) CPPCMS_BOOST_PP_LIST_IS_CONS(l)
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_SIZE_O(d, rl) (CPPCMS_BOOST_PP_INC(CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, rl)), CPPCMS_BOOST_PP_LIST_REST(CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, rl)))
# else
#    define CPPCMS_BOOST_PP_LIST_SIZE_O(d, rl) CPPCMS_BOOST_PP_LIST_SIZE_O_I(CPPCMS_BOOST_PP_TUPLE_REM_2 rl)
#    define CPPCMS_BOOST_PP_LIST_SIZE_O_I(im) CPPCMS_BOOST_PP_LIST_SIZE_O_II(im)
#    define CPPCMS_BOOST_PP_LIST_SIZE_O_II(r, l) (CPPCMS_BOOST_PP_INC(r), CPPCMS_BOOST_PP_LIST_REST(l))
# endif
#
# /* BOOST_PP_LIST_SIZE_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_SIZE_D(d, list) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_LIST_SIZE_P, CPPCMS_BOOST_PP_LIST_SIZE_O, (0, list)))
# else
#    define CPPCMS_BOOST_PP_LIST_SIZE_D(d, list) CPPCMS_BOOST_PP_LIST_SIZE_D_I(d, list)
#    define CPPCMS_BOOST_PP_LIST_SIZE_D_I(d, list) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_LIST_SIZE_P, CPPCMS_BOOST_PP_LIST_SIZE_O, (0, list)))
# endif
#
# endif
