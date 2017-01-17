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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARRAY_PUSH_FRONT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARRAY_PUSH_FRONT_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/array/data.hpp>
# include <cppcms_boost/preprocessor/array/size.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/punctuation/comma_if.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_ARRAY_PUSH_FRONT */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ARRAY_PUSH_FRONT(array, elem) CPPCMS_BOOST_PP_ARRAY_PUSH_FRONT_I(CPPCMS_BOOST_PP_ARRAY_SIZE(array), CPPCMS_BOOST_PP_ARRAY_DATA(array), elem)
# else
#    define CPPCMS_BOOST_PP_ARRAY_PUSH_FRONT(array, elem) CPPCMS_BOOST_PP_ARRAY_PUSH_FRONT_D(array, elem)
#    define CPPCMS_BOOST_PP_ARRAY_PUSH_FRONT_D(array, elem) CPPCMS_BOOST_PP_ARRAY_PUSH_FRONT_I(CPPCMS_BOOST_PP_ARRAY_SIZE(array), CPPCMS_BOOST_PP_ARRAY_DATA(array), elem)
# endif
#
# define CPPCMS_BOOST_PP_ARRAY_PUSH_FRONT_I(size, data, elem) (CPPCMS_BOOST_PP_INC(size), (elem CPPCMS_BOOST_PP_COMMA_IF(size) CPPCMS_BOOST_PP_TUPLE_REM(size) data))
#
# endif
