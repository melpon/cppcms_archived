# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef CPPCMS_BOOST_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
# define CPPCMS_BOOST_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/if.hpp>
# include <cppcms_boost/preprocessor/facilities/empty.hpp>
# include <cppcms_boost/preprocessor/punctuation/comma.hpp>
#
# /* BOOST_PP_COMMA_IF */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_COMMA_IF(cond) CPPCMS_BOOST_PP_IF(cond, CPPCMS_BOOST_PP_COMMA, CPPCMS_BOOST_PP_EMPTY)()
# else
#    define CPPCMS_BOOST_PP_COMMA_IF(cond) CPPCMS_BOOST_PP_COMMA_IF_I(cond)
#    define CPPCMS_BOOST_PP_COMMA_IF_I(cond) CPPCMS_BOOST_PP_IF(cond, CPPCMS_BOOST_PP_COMMA, CPPCMS_BOOST_PP_EMPTY)()
# endif
#
# endif
