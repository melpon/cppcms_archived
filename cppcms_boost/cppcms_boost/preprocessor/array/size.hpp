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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARRAY_SIZE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARRAY_SIZE_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ARRAY_SIZE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ARRAY_SIZE(array) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, array)
# else
#    define CPPCMS_BOOST_PP_ARRAY_SIZE(array) CPPCMS_BOOST_PP_ARRAY_SIZE_I(array)
#    define CPPCMS_BOOST_PP_ARRAY_SIZE_I(array) CPPCMS_BOOST_PP_ARRAY_SIZE_II array
#    define CPPCMS_BOOST_PP_ARRAY_SIZE_II(size, data) size
# endif
#
# endif
