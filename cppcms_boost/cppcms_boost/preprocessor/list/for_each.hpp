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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_FOR_EACH_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_FOR_EACH_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/for_each_i.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_LIST_FOR_EACH */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH(macro, data, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I(CPPCMS_BOOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# else
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH(macro, data, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_X(macro, data, list)
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_X(macro, data, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I(CPPCMS_BOOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_O(r, md, i, elem) CPPCMS_BOOST_PP_LIST_FOR_EACH_O_D(r, CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, md), CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, md), elem)
# else
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_O(r, md, i, elem) CPPCMS_BOOST_PP_LIST_FOR_EACH_O_I(r, CPPCMS_BOOST_PP_TUPLE_REM_2 md, elem)
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_O_I(r, im, elem) CPPCMS_BOOST_PP_LIST_FOR_EACH_O_D(r, im, elem)
# endif
#
# define CPPCMS_BOOST_PP_LIST_FOR_EACH_O_D(r, m, d, elem) m(r, d, elem)
#
# /* BOOST_PP_LIST_FOR_EACH_R */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_R(r, macro, data, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R(r, CPPCMS_BOOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# else
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_R(r, macro, data, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_R_X(r, macro, data, list)
#    define CPPCMS_BOOST_PP_LIST_FOR_EACH_R_X(r, macro, data, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R(r, CPPCMS_BOOST_PP_LIST_FOR_EACH_O, (macro, data), list)
# endif
#
# endif
