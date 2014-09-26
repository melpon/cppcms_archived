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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARRAY_REPLACE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARRAY_REPLACE_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/array/elem.hpp>
# include <cppcms_boost/preprocessor/array/push_back.hpp>
# include <cppcms_boost/preprocessor/comparison/not_equal.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/deduce_d.hpp>
# include <cppcms_boost/preprocessor/control/iif.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ARRAY_REPLACE */
#
# define CPPCMS_BOOST_PP_ARRAY_REPLACE(array, i, elem) CPPCMS_BOOST_PP_ARRAY_REPLACE_I(CPPCMS_BOOST_PP_DEDUCE_D(), array, i, elem)
# define CPPCMS_BOOST_PP_ARRAY_REPLACE_I(d, array, i, elem) CPPCMS_BOOST_PP_ARRAY_REPLACE_D(d, array, i, elem)
#
# /* BOOST_PP_ARRAY_REPLACE_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ARRAY_REPLACE_D(d, array, i, elem) CPPCMS_BOOST_PP_TUPLE_ELEM(5, 3, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_ARRAY_REPLACE_P, CPPCMS_BOOST_PP_ARRAY_REPLACE_O, (0, i, elem, (0, ()), array)))
# else
#    define CPPCMS_BOOST_PP_ARRAY_REPLACE_D(d, array, i, elem) CPPCMS_BOOST_PP_ARRAY_REPLACE_D_I(d, array, i, elem)
#    define CPPCMS_BOOST_PP_ARRAY_REPLACE_D_I(d, array, i, elem) CPPCMS_BOOST_PP_TUPLE_ELEM(5, 3, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_ARRAY_REPLACE_P, CPPCMS_BOOST_PP_ARRAY_REPLACE_O, (0, i, elem, (0, ()), array)))
# endif
#
# define CPPCMS_BOOST_PP_ARRAY_REPLACE_P(d, state) CPPCMS_BOOST_PP_NOT_EQUAL(CPPCMS_BOOST_PP_TUPLE_ELEM(5, 0, state), CPPCMS_BOOST_PP_ARRAY_SIZE(CPPCMS_BOOST_PP_TUPLE_ELEM(5, 4, state)))
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_ARRAY_REPLACE_O(d, state) CPPCMS_BOOST_PP_ARRAY_REPLACE_O_I state
# else
#    define CPPCMS_BOOST_PP_ARRAY_REPLACE_O(d, state) CPPCMS_BOOST_PP_ARRAY_REPLACE_O_I(CPPCMS_BOOST_PP_TUPLE_ELEM(5, 0, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 1, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 2, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 3, state), CPPCMS_BOOST_PP_TUPLE_ELEM(5, 4, state))
# endif
#
# define CPPCMS_BOOST_PP_ARRAY_REPLACE_O_I(n, i, elem, res, arr) (CPPCMS_BOOST_PP_INC(n), i, elem, CPPCMS_BOOST_PP_ARRAY_PUSH_BACK(res, CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(n, i), CPPCMS_BOOST_PP_ARRAY_ELEM(n, arr), elem)), arr)
#
# endif
