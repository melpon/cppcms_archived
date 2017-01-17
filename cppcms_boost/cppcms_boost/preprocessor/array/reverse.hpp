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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARRAY_REVERSE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARRAY_REVERSE_HPP
#
# include <cppcms_boost/preprocessor/array/data.hpp>
# include <cppcms_boost/preprocessor/array/size.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/tuple/reverse.hpp>
#
# /* BOOST_PP_ARRAY_REVERSE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ARRAY_REVERSE(array) (CPPCMS_BOOST_PP_ARRAY_SIZE(array), CPPCMS_BOOST_PP_TUPLE_REVERSE(CPPCMS_BOOST_PP_ARRAY_SIZE(array), CPPCMS_BOOST_PP_ARRAY_DATA(array)))
# else
#    define CPPCMS_BOOST_PP_ARRAY_REVERSE(array) CPPCMS_BOOST_PP_ARRAY_REVERSE_I(array)
#    define CPPCMS_BOOST_PP_ARRAY_REVERSE_I(array) (CPPCMS_BOOST_PP_ARRAY_SIZE(array), CPPCMS_BOOST_PP_TUPLE_REVERSE(CPPCMS_BOOST_PP_ARRAY_SIZE(array), CPPCMS_BOOST_PP_ARRAY_DATA(array)))
# endif
#
# endif
