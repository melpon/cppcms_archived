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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARRAY_REMOVE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARRAY_REMOVE_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/array/elem.hpp>
# include <cppcms_boost/preprocessor/array/push_back.hpp>
# include <cppcms_boost/preprocessor/array/size.hpp>
# include <cppcms_boost/preprocessor/comparison/not_equal.hpp>
# include <cppcms_boost/preprocessor/control/deduce_d.hpp>
# include <cppcms_boost/preprocessor/control/iif.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/tuple/eat.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ARRAY_REMOVE */
#
# define CPPCMS_BOOST_PP_ARRAY_REMOVE(array, i) CPPCMS_BOOST_PP_ARRAY_REMOVE_I(CPPCMS_BOOST_PP_DEDUCE_D(), array, i)
# define CPPCMS_BOOST_PP_ARRAY_REMOVE_I(d, array, i) CPPCMS_BOOST_PP_ARRAY_REMOVE_D(d, array, i)
#
# /* BOOST_PP_ARRAY_REMOVE_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ARRAY_REMOVE_D(d, array, i) CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_ARRAY_REMOVE_P, CPPCMS_BOOST_PP_ARRAY_REMOVE_O, (0, i, (0, ()), array)))
# else
#    define CPPCMS_BOOST_PP_ARRAY_REMOVE_D(d, array, i) CPPCMS_BOOST_PP_ARRAY_REMOVE_D_I(d, array, i)
#    define CPPCMS_BOOST_PP_ARRAY_REMOVE_D_I(d, array, i) CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, CPPCMS_BOOST_PP_WHILE_ ## d(CPPCMS_BOOST_PP_ARRAY_REMOVE_P, CPPCMS_BOOST_PP_ARRAY_REMOVE_O, (0, i, (0, ()), array)))
# endif
#
# define CPPCMS_BOOST_PP_ARRAY_REMOVE_P(d, st) CPPCMS_BOOST_PP_NOT_EQUAL(CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, st), CPPCMS_BOOST_PP_ARRAY_SIZE(CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, st)))
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_ARRAY_REMOVE_O(d, st) CPPCMS_BOOST_PP_ARRAY_REMOVE_O_I st
# else
#    define CPPCMS_BOOST_PP_ARRAY_REMOVE_O(d, st) CPPCMS_BOOST_PP_ARRAY_REMOVE_O_I(CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, st), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 1, st), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, st), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, st))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_DMC()
#    define CPPCMS_BOOST_PP_ARRAY_REMOVE_O_I(n, i, res, arr) (CPPCMS_BOOST_PP_INC(n), i, CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(n, i), CPPCMS_BOOST_PP_ARRAY_PUSH_BACK, res CPPCMS_BOOST_PP_TUPLE_EAT_2)(res, CPPCMS_BOOST_PP_ARRAY_ELEM(n, arr)), arr)
# else
#    define CPPCMS_BOOST_PP_ARRAY_REMOVE_O_I(n, i, res, arr) (CPPCMS_BOOST_PP_INC(n), i, CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT_EQUAL(n, i), CPPCMS_BOOST_PP_ARRAY_PUSH_BACK, CPPCMS_BOOST_PP_TUPLE_ELEM_2_0)(res, CPPCMS_BOOST_PP_ARRAY_ELEM(n, arr)), arr)
# endif
#
# endif
