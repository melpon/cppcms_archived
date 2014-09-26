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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_ENUM_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_ENUM_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/for_each_i.hpp>
# include <cppcms_boost/preprocessor/punctuation/comma_if.hpp>
#
# /* BOOST_PP_LIST_ENUM */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_ENUM(list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I(CPPCMS_BOOST_PP_LIST_ENUM_O, CPPCMS_BOOST_PP_NIL, list)
# else
#    define CPPCMS_BOOST_PP_LIST_ENUM(list) CPPCMS_BOOST_PP_LIST_ENUM_I(list)
#    define CPPCMS_BOOST_PP_LIST_ENUM_I(list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I(CPPCMS_BOOST_PP_LIST_ENUM_O, CPPCMS_BOOST_PP_NIL, list)
# endif
#
# define CPPCMS_BOOST_PP_LIST_ENUM_O(r, _, i, elem) CPPCMS_BOOST_PP_COMMA_IF(i) elem
#
# /* BOOST_PP_LIST_ENUM_R */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_ENUM_R(r, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R(r, CPPCMS_BOOST_PP_LIST_ENUM_O, CPPCMS_BOOST_PP_NIL, list)
# else
#    define CPPCMS_BOOST_PP_LIST_ENUM_R(r, list) CPPCMS_BOOST_PP_LIST_ENUM_R_I(r, list)
#    define CPPCMS_BOOST_PP_LIST_ENUM_R_I(r, list) CPPCMS_BOOST_PP_LIST_FOR_EACH_I_R(r, CPPCMS_BOOST_PP_LIST_ENUM_O, CPPCMS_BOOST_PP_NIL, list)
# endif
#
# endif
