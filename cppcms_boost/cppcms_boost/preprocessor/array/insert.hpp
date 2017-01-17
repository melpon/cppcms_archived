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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARRAY_INSERT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARRAY_INSERT_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/array/elem.hpp>
# include <cppcms_boost/preprocessor/array/push_back.hpp>
# include <cppcms_boost/preprocessor/array/size.hpp>
# include <cppcms_boost/preprocessor/comparison/not_equal.hpp>
# include <cppcms_boost/preprocessor/control/deduce_d.hpp>
# include <cppcms_boost/preprocessor/control/iif.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ARRAY_INSERT */
#
# define CPPCMS_BOOST_PP_ARRAY_INSERT(array, i, elem) CPPCMS_BOOST_PP_ARRAY_INSERT_I(CPPCMS_BOOST_PP_DEDUCE_D(), array, i, elem)
# define CPPCMS_BOOST_PP_ARRAY_INSERT_I(d, array, i, elem) CPPCMS_BOOST_PP_ARRAY_INSERT_D(d, array, i, elem)
#
# /* BOOST_PP_ARRAY_INSERT_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ARRAY_INSERT_D(d, array, i, elem) CPPCMS_BOOST_PP_TUPLE_ELEM(5, 3, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_ARRAY_INSERT_P, CPPCMS_BOOST_PP_ARRAY_INSERT_O, (0, i, elem, (0, ()), array)))
# else
#    define CPPCMS_BOOST_PP_ARRAY_INSERT_D(d, array, i, elem) CPPCMS_BOOST_PP_ARRAY_INSERT_D_I(d, array, i, elem)
#    define CPPCMS_BOOST_PP_ARRAY_INSERT_D_I(d, array, i, elem) CPPCMS_BOOST_PP_TUPLE_ELEM(5, 3, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_ARRAY_INSERT_P, CPPCMS_BOOST_PP_ARRAY_INSERT_O, (0, i, elem, (0, ()), array)))
# endif
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_ARRAY_INSERT_P(d, state) CPPCMS_BOOST_PP_ARRAY_INSERT_P_I state
# else
#    define CPPCMS_BOOST_PP_ARRAY_INSERT_P(d, state) CPPCMS_BOOST_PP_ARRAY_INSERT_P_I(nil, nil, nil, CPPCMS_BOOST_PP_TUPLE_ELEM(5, 3, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 4, state))
# endif
#
# define CPPCMS_BOOST_PP_ARRAY_INSERT_P_I(_i, _ii, _iii, res, arr) CPPCMS_BOOST_PP_NOT_EQUAL(CPPCMS_BOOST_PP_ARRAY_SIZE(res), CPPCMS_BOOST_PP_INC(CPPCMS_BOOST_PP_ARRAY_SIZE(arr)))
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_ARRAY_INSERT_O(d, state) CPPCMS_BOOST_PP_ARRAY_INSERT_O_I state
# else
#    define CPPCMS_BOOST_PP_ARRAY_INSERT_O(d, state) CPPCMS_BOOST_PP_ARRAY_INSERT_O_I(CPPCMS_BOOST_PP_TUPLE_ELEM(5, 0, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 1, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 2, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 3, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 4, state))
# endif
#
# define CPPCMS_BOOST_PP_ARRAY_INSERT_O_I(n, i, elem, res, arr) (CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(CPPCMS_BOOST_PP_ARRAY_SIZE(res), i), CPPCMS_BOOST_PP_INC(n), n), i, elem, CPPCMS_BOOST_PP_ARRAY_PUSH_BACK(res, CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(CPPCMS_BOOST_PP_ARRAY_SIZE(res), i), CPPCMS_BOOST_PP_ARRAY_ELEM(n, arr), elem)), arr)
#
# endif
