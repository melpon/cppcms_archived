# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_FILTER_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_FILTER_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/expr_if.hpp>
# include <cppcms_boost/preprocessor/facilities/empty.hpp>
# include <cppcms_boost/preprocessor/seq/fold_left.hpp>
# include <cppcms_boost/preprocessor/seq/seq.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_SEQ_FILTER */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_FILTER(pred, data, seq) CPPCMS_BOOST_PP_SEQ_TAIL(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_SEQ_FOLD_LEFT(CPPCMS_BOOST_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# else
#    define CPPCMS_BOOST_PP_SEQ_FILTER(pred, data, seq) CPPCMS_BOOST_PP_SEQ_FILTER_I(pred, data, seq)
#    define CPPCMS_BOOST_PP_SEQ_FILTER_I(pred, data, seq) CPPCMS_BOOST_PP_SEQ_TAIL(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_SEQ_FOLD_LEFT(CPPCMS_BOOST_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# endif
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_SEQ_FILTER_O(s, st, elem) CPPCMS_BOOST_PP_SEQ_FILTER_O_IM(s, CPPCMS_BOOST_PP_TUPLE_REM_3 st, elem)
#    define CPPCMS_BOOST_PP_SEQ_FILTER_O_IM(s, im, elem) CPPCMS_BOOST_PP_SEQ_FILTER_O_I(s, im, elem)
# else
#    define CPPCMS_BOOST_PP_SEQ_FILTER_O(s, st, elem) CPPCMS_BOOST_PP_SEQ_FILTER_O_I(s, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, st), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, st), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, st), elem)
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_DMC()
#   define CPPCMS_BOOST_PP_SEQ_FILTER_O_I(s, pred, data, res, elem) (pred, data, res CPPCMS_BOOST_PP_EXPR_IF(pred(s, data, elem), (elem)))
# else
#   define CPPCMS_BOOST_PP_SEQ_FILTER_O_I(s, pred, data, res, elem) (pred, data, res CPPCMS_BOOST_PP_EXPR_IF(pred##(s, data, elem), (elem)))
# endif
#
# /* BOOST_PP_SEQ_FILTER_S */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_FILTER_S(s, pred, data, seq) CPPCMS_BOOST_PP_SEQ_TAIL(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(CPPCMS_BOOST_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# else
#    define CPPCMS_BOOST_PP_SEQ_FILTER_S(s, pred, data, seq) CPPCMS_BOOST_PP_SEQ_FILTER_S_I(s, pred, data, seq)
#    define CPPCMS_BOOST_PP_SEQ_FILTER_S_I(s, pred, data, seq) CPPCMS_BOOST_PP_SEQ_TAIL(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(CPPCMS_BOOST_PP_SEQ_FILTER_O, (pred, data, (nil)), seq)))
# endif
#
# endif
