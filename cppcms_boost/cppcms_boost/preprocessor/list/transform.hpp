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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_TRANSFORM_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_TRANSFORM_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/fold_right.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_LIST_TRANSFORM */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM(op, data, list) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_LIST_FOLD_RIGHT(CPPCMS_BOOST_PP_LIST_TRANSFORM_O, (op, data, CPPCMS_BOOST_PP_NIL), list))
# else
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM(op, data, list) CPPCMS_BOOST_PP_LIST_TRANSFORM_I(op, data, list)
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM_I(op, data, list) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_LIST_FOLD_RIGHT(CPPCMS_BOOST_PP_LIST_TRANSFORM_O, (op, data, CPPCMS_BOOST_PP_NIL), list))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM_O(d, odr, elem) CPPCMS_BOOST_PP_LIST_TRANSFORM_O_D(d, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, odr), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, odr), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, odr), elem)
# else
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM_O(d, odr, elem) CPPCMS_BOOST_PP_LIST_TRANSFORM_O_I(d, CPPCMS_BOOST_PP_TUPLE_REM_3 odr, elem)
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM_O_I(d, im, elem) CPPCMS_BOOST_PP_LIST_TRANSFORM_O_D(d, im, elem)
# endif
#
# define CPPCMS_BOOST_PP_LIST_TRANSFORM_O_D(d, op, data, res, elem) (op, data, (op(d, data, elem), res))
#
# /* BOOST_PP_LIST_TRANSFORM_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM_D(d, op, data, list) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(CPPCMS_BOOST_PP_LIST_TRANSFORM_O, (op, data, CPPCMS_BOOST_PP_NIL), list))
# else
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM_D(d, op, data, list) CPPCMS_BOOST_PP_LIST_TRANSFORM_D_I(d, op, data, list)
#    define CPPCMS_BOOST_PP_LIST_TRANSFORM_D_I(d, op, data, list) CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(CPPCMS_BOOST_PP_LIST_TRANSFORM_O, (op, data, CPPCMS_BOOST_PP_NIL), list))
# endif
#
# endif
