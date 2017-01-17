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
# ifndef CPPCMS_BOOST_PREPROCESSOR_PUNCTUATION_PAREN_IF_HPP
# define CPPCMS_BOOST_PREPROCESSOR_PUNCTUATION_PAREN_IF_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/if.hpp>
# include <cppcms_boost/preprocessor/facilities/empty.hpp>
# include <cppcms_boost/preprocessor/punctuation/paren.hpp>
#
# /* BOOST_PP_LPAREN_IF */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LPAREN_IF(cond) CPPCMS_BOOST_PP_IF(cond, CPPCMS_BOOST_PP_LPAREN, CPPCMS_BOOST_PP_EMPTY)()
# else
#    define CPPCMS_BOOST_PP_LPAREN_IF(cond) CPPCMS_BOOST_PP_LPAREN_IF_I(cond)
#    define CPPCMS_BOOST_PP_LPAREN_IF_I(cond) CPPCMS_BOOST_PP_IF(cond, CPPCMS_BOOST_PP_LPAREN, CPPCMS_BOOST_PP_EMPTY)()
# endif
#
# /* BOOST_PP_RPAREN_IF */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_RPAREN_IF(cond) CPPCMS_BOOST_PP_IF(cond, CPPCMS_BOOST_PP_RPAREN, CPPCMS_BOOST_PP_EMPTY)()
# else
#    define CPPCMS_BOOST_PP_RPAREN_IF(cond) CPPCMS_BOOST_PP_RPAREN_IF_I(cond)
#    define CPPCMS_BOOST_PP_RPAREN_IF_I(cond) CPPCMS_BOOST_PP_IF(cond, CPPCMS_BOOST_PP_RPAREN, CPPCMS_BOOST_PP_EMPTY)()
# endif
#
# endif
