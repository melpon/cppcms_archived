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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/adt.hpp>
# include <cppcms_boost/preprocessor/repetition/for.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_LIST_FOR_EACH_I */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG() && ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I(macro, data, list) CPPCMS_BOOST_PP_FOR((macro, data, list, 0), CPPCMS_BOOST_PP_LIST_FOR_EACH_I_P, CPPCMS_BOOST_PP_LIST_FOR_EACH_I_O, CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M)
# else
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I(macro, data, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_I(macro, data, list)
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_I(macro, data, list) CPPCMS_BOOST_PP_FOR((macro, data, list, 0), CPPCMS_BOOST_PP_LIST_FOR_EACH_I_P, CPPCMS_BOOST_PP_LIST_FOR_EACH_I_O, CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M)
# endif
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_P(r, x) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_P_D x
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_P_D(m, d, l, i) CPPCMS_BOOST_PP_LIST_IS_CONS(l)
# else
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_P(r, x) CPPCMS_BOOST_PP_LIST_IS_CONS(CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, x))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_O(r, x) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_O_D x
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_O_D(m, d, l, i) (m, d, CPPCMS_BOOST_PP_LIST_REST(l), CPPCMS_BOOST_PP_INC(i))
# else
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_O(r, x) (CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 1, x), CPPCMS_BOOST_PP_LIST_REST(CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, x)), CPPCMS_BOOST_PP_INC(CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, x)))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M(r, x) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M_D(r, CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 1, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, x))
# else
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M(r, x) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M_I(r, CPPCMS_BOOST_PP_TUPLE_REM_4 x)
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M_I(r, x_e) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M_D(r, x_e)
# endif
#
# define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M_D(r, m, d, l, i) m(r, d, i, CPPCMS_BOOST_PP_LIST_FIRST(l))
#
# /* BOOST_PP_LIST_FOR_EACH_I_R */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R(r, macro, data, list) CPPCMS_BOOST_PP_FOR_ ## r((macro, data, list, 0), CPPCMS_BOOST_PP_LIST_FOR_EACH_I_P, CPPCMS_BOOST_PP_LIST_FOR_EACH_I_O, CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M)
# else
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R(r, macro, data, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list)
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list) CPPCMS_BOOST_PP_FOR_ ## r((macro, data, list, 0), CPPCMS_BOOST_PP_LIST_FOR_EACH_I_P, CPPCMS_BOOST_PP_LIST_FOR_EACH_I_O, CPPCMS_BOOST_PP_LIST_FOR_EACH_I_M)
# endif
#
# endif
