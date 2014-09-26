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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_FILTER_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_FILTER_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/if.hpp>
# include <cppcms_boost/preprocessor/list/fold_right.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_LIST_FILTER */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FILTER(pred, data, list) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_LIST_FOLD_RIGHT(CPPCMS_BOOST_PP_LIST_FILTER_O, (pred, data, CPPCMS_BOOST_PP_NIL), list))
# else
#    define CPPCMS_BOOST_PP_LIST_FILTER(pred, data, list) CPPCMS_BOOST_PP_LIST_FILTER_I(pred, data, list)
#    define CPPCMS_BOOST_PP_LIST_FILTER_I(pred, data, list) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_LIST_FOLD_RIGHT(CPPCMS_BOOST_PP_LIST_FILTER_O, (pred, data, CPPCMS_BOOST_PP_NIL), list))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FILTER_O(d, pdr, elem) CPPCMS_BOOST_PP_LIST_FILTER_O_D(d, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, pdr), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, pdr), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, pdr), elem)
# else
#    define CPPCMS_BOOST_PP_LIST_FILTER_O(d, pdr, elem) CPPCMS_BOOST_PP_LIST_FILTER_O_I(d, CPPCMS_BOOST_PP_TUPLE_REM_3 pdr, elem)
#    define CPPCMS_BOOST_PP_LIST_FILTER_O_I(d, im, elem) CPPCMS_BOOST_PP_LIST_FILTER_O_D(d, im, elem)
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_DMC()
#    define CPPCMS_BOOST_PP_LIST_FILTER_O_D(d, pred, data, res, elem) (pred, data, CPPCMS_BOOST_PP_IF(pred(d, data, elem), (elem, res), res))
# else
#    define CPPCMS_BOOST_PP_LIST_FILTER_O_D(d, pred, data, res, elem) (pred, data, CPPCMS_BOOST_PP_IF(pred##(d, data, elem), (elem, res), res))
# endif
#
# /* BOOST_PP_LIST_FILTER_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_FILTER_D(d, pred, data, list) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(CPPCMS_BOOST_PP_LIST_FILTER_O, (pred, data, CPPCMS_BOOST_PP_NIL), list))
# else
#    define CPPCMS_BOOST_PP_LIST_FILTER_D(d, pred, data, list) CPPCMS_BOOST_PP_LIST_FILTER_D_I(d, pred, data, list)
#    define CPPCMS_BOOST_PP_LIST_FILTER_D_I(d, pred, data, list) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(CPPCMS_BOOST_PP_LIST_FILTER_O, (pred, data, CPPCMS_BOOST_PP_NIL), list))
# endif
#
# endif
