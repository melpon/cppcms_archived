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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_AT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_AT_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/list/adt.hpp>
# include <cppcms_boost/preprocessor/list/rest_n.hpp>
#
# /* BOOST_PP_LIST_AT */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_AT(list, index) CPPCMS_BOOST_PP_LIST_FIRST(CPPCMS_BOOST_PP_LIST_REST_N(index, list))
# else
#    define CPPCMS_BOOST_PP_LIST_AT(list, index) CPPCMS_BOOST_PP_LIST_AT_I(list, index)
#    define CPPCMS_BOOST_PP_LIST_AT_I(list, index) CPPCMS_BOOST_PP_LIST_FIRST(CPPCMS_BOOST_PP_LIST_REST_N(index, list))
# endif
#
# /* BOOST_PP_LIST_AT_D */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_LIST_AT_D(d, list, index) CPPCMS_BOOST_PP_LIST_FIRST(CPPCMS_BOOST_PP_LIST_REST_N_D(d, index, list))
# else
#    define CPPCMS_BOOST_PP_LIST_AT_D(d, list, index) CPPCMS_BOOST_PP_LIST_AT_D_I(d, list, index)
#    define CPPCMS_BOOST_PP_LIST_AT_D_I(d, list, index) CPPCMS_BOOST_PP_LIST_FIRST(CPPCMS_BOOST_PP_LIST_REST_N_D(d, index, list))
# endif
#
# endif
