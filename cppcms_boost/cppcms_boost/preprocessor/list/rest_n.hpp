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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_REST_N_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_REST_N_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/list/adt.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_LIST_REST_N */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_REST_N(count, list) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_LIST_REST_N_P, CPPCMS_BOOST_PP_LIST_REST_N_O, (list, count)))
# else
#    define CPPCMS_BOOST_PP_LIST_REST_N(count, list) CPPCMS_BOOST_PP_LIST_REST_N_I(count, list)
#    define CPPCMS_BOOST_PP_LIST_REST_N_I(count, list) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_LIST_REST_N_P, CPPCMS_BOOST_PP_LIST_REST_N_O, (list, count)))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_REST_N_P(d, lc) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, lc)
# else
#    define CPPCMS_BOOST_PP_LIST_REST_N_P(d, lc) CPPCMS_BOOST_PP_LIST_REST_N_P_I lc
#    define CPPCMS_BOOST_PP_LIST_REST_N_P_I(list, count) count
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_REST_N_O(d, lc) (CPPCMS_BOOST_PP_LIST_REST(CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, lc)), CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, lc)))
# else
#    define CPPCMS_BOOST_PP_LIST_REST_N_O(d, lc) CPPCMS_BOOST_PP_LIST_REST_N_O_I lc
#    define CPPCMS_BOOST_PP_LIST_REST_N_O_I(list, count) (CPPCMS_BOOST_PP_LIST_REST(list), CPPCMS_BOOST_PP_DEC(count))
# endif
#
# /* BOOST_PP_LIST_REST_N_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_REST_N_D(d, count, list) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_LIST_REST_N_P, CPPCMS_BOOST_PP_LIST_REST_N_O, (list, count)))
# else
#    define CPPCMS_BOOST_PP_LIST_REST_N_D(d, count, list) CPPCMS_BOOST_PP_LIST_REST_N_D_I(d, count, list)
#    define CPPCMS_BOOST_PP_LIST_REST_N_D_I(d, count, list) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_LIST_REST_N_P, CPPCMS_BOOST_PP_LIST_REST_N_O, (list, count)))
# endif
#
# endif
