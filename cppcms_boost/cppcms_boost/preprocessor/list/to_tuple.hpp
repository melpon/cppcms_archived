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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_TO_TUPLE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_TO_TUPLE_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/enum.hpp>
#
# /* BOOST_PP_LIST_TO_TUPLE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_TO_TUPLE(list) (CPPCMS_BOOST_PP_LIST_ENUM(list))
# else
#    define CPPCMS_BOOST_PP_LIST_TO_TUPLE(list) CPPCMS_BOOST_PP_LIST_TO_TUPLE_I(list)
#    define CPPCMS_BOOST_PP_LIST_TO_TUPLE_I(list) (CPPCMS_BOOST_PP_LIST_ENUM(list))
# endif
#
# /* BOOST_PP_LIST_TO_TUPLE_R */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_TO_TUPLE_R(r, list) (CPPCMS_BOOST_PP_LIST_ENUM_R(r, list))
# else
#    define CPPCMS_BOOST_PP_LIST_TO_TUPLE_R(r, list) CPPCMS_BOOST_PP_LIST_TO_TUPLE_R_I(r, list)
#    define CPPCMS_BOOST_PP_LIST_TO_TUPLE_R_I(r, list) (CPPCMS_BOOST_PP_LIST_ENUM_R(r, list))
# endif
#
# endif
