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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_TRANSFORM_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_TRANSFORM_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/seq/fold_left.hpp>
# include <cppcms_boost/preprocessor/seq/seq.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_SEQ_TRANSFORM */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM(op, data, seq) CPPCMS_BOOST_PP_SEQ_TAIL(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_SEQ_FOLD_LEFT(CPPCMS_BOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# else
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM(op, data, seq) CPPCMS_BOOST_PP_SEQ_TRANSFORM_I(op, data, seq)
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM_I(op, data, seq) CPPCMS_BOOST_PP_SEQ_TAIL(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_SEQ_FOLD_LEFT(CPPCMS_BOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# endif
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM_O(s, state, elem) CPPCMS_BOOST_PP_SEQ_TRANSFORM_O_IM(s, CPPCMS_BOOST_PP_TUPLE_REM_3 state, elem)
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM_O_IM(s, im, elem) CPPCMS_BOOST_PP_SEQ_TRANSFORM_O_I(s, im, elem)
# else
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM_O(s, state, elem) CPPCMS_BOOST_PP_SEQ_TRANSFORM_O_I(s, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, state), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, state), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, state), elem)
# endif
#
# define CPPCMS_BOOST_PP_SEQ_TRANSFORM_O_I(s, op, data, res, elem) (op, data, res (op(s, data, elem)))
#
# /* BOOST_PP_SEQ_TRANSFORM_S */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM_S(s, op, data, seq) CPPCMS_BOOST_PP_SEQ_TAIL(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(CPPCMS_BOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# else
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM_S(s, op, data, seq) CPPCMS_BOOST_PP_SEQ_TRANSFORM_S_I(s, op, data, seq)
#    define CPPCMS_BOOST_PP_SEQ_TRANSFORM_S_I(s, op, data, seq) CPPCMS_BOOST_PP_SEQ_TAIL(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, CPPCMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(CPPCMS_BOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# endif
#
# endif
