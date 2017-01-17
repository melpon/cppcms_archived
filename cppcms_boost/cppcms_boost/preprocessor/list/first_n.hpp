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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_FIRST_N_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_FIRST_N_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/list/adt.hpp>
# include <cppcms_boost/preprocessor/list/reverse.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_LIST_FIRST_N */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FIRST_N(count, list) CPPCMS_BOOST_PP_LIST_REVERSE(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_LIST_FIRST_N_P, CPPCMS_BOOST_PP_LIST_FIRST_N_O, (count, list, CPPCMS_BOOST_PP_NIL))))
# else
#    define CPPCMS_BOOST_PP_LIST_FIRST_N(count, list) CPPCMS_BOOST_PP_LIST_FIRST_N_I(count, list)
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_I(count, list) CPPCMS_BOOST_PP_LIST_REVERSE(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_WHILE(CPPCMS_BOOST_PP_LIST_FIRST_N_P, CPPCMS_BOOST_PP_LIST_FIRST_N_O, (count, list, CPPCMS_BOOST_PP_NIL))))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_P(d, data) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, data)
# else
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_P(d, data) CPPCMS_BOOST_PP_LIST_FIRST_N_P_I data
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_P_I(c, l, nl) c
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_O(d, data) CPPCMS_BOOST_PP_LIST_FIRST_N_O_D data
# else
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_O(d, data) CPPCMS_BOOST_PP_LIST_FIRST_N_O_D(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, data), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, data), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, data))
# endif
#
# define CPPCMS_BOOST_PP_LIST_FIRST_N_O_D(c, l, nl) (CPPCMS_BOOST_PP_DEC(c), CPPCMS_BOOST_PP_LIST_REST(l), (CPPCMS_BOOST_PP_LIST_FIRST(l), nl))
#
# /* BOOST_PP_LIST_FIRST_N_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_D(d, count, list) CPPCMS_BOOST_PP_LIST_REVERSE_D(d, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_LIST_FIRST_N_P, CPPCMS_BOOST_PP_LIST_FIRST_N_O, (count, list, CPPCMS_BOOST_PP_NIL))))
# else
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_D(d, count, list) CPPCMS_BOOST_PP_LIST_FIRST_N_D_I(d, count, list)
#    define CPPCMS_BOOST_PP_LIST_FIRST_N_D_I(d, count, list) CPPCMS_BOOST_PP_LIST_REVERSE_D(d, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_LIST_FIRST_N_P, CPPCMS_BOOST_PP_LIST_FIRST_N_O, (count, list, CPPCMS_BOOST_PP_NIL))))
# endif
#
# endif
