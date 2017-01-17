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
# ifndef CPPCMS_BOOST_PREPROCESSOR_DETAIL_IS_UNARY_HPP
# define CPPCMS_BOOST_PREPROCESSOR_DETAIL_IS_UNARY_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/detail/check.hpp>
#
# /* BOOST_PP_IS_UNARY */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_IS_UNARY(x) CPPCMS_BOOST_PP_CHECK(x, CPPCMS_BOOST_PP_IS_UNARY_CHECK)
# else
#    define CPPCMS_BOOST_PP_IS_UNARY(x) CPPCMS_BOOST_PP_IS_UNARY_I(x)
#    define CPPCMS_BOOST_PP_IS_UNARY_I(x) CPPCMS_BOOST_PP_CHECK(x, CPPCMS_BOOST_PP_IS_UNARY_CHECK)
# endif
#
# define CPPCMS_BOOST_PP_IS_UNARY_CHECK(a) 1
# define CPPCMS_BOOST_PP_CHECK_RESULT_CPPCMS_BOOST_PP_IS_UNARY_CHECK 0, CPPCMS_BOOST_PP_NIL
#
# endif
