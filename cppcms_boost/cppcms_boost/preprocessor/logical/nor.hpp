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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LOGICAL_NOR_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LOGICAL_NOR_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/logical/bool.hpp>
# include <cppcms_boost/preprocessor/logical/bitnor.hpp>
#
# /* BOOST_PP_NOR */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_NOR(p, q) CPPCMS_BOOST_PP_BITNOR(CPPCMS_BOOST_PP_BOOL(p), CPPCMS_BOOST_PP_BOOL(q))
# else
#    define CPPCMS_BOOST_PP_NOR(p, q) CPPCMS_BOOST_PP_NOR_I(p, q)
#    define CPPCMS_BOOST_PP_NOR_I(p, q) CPPCMS_BOOST_PP_BITNOR(CPPCMS_BOOST_PP_BOOL(p), CPPCMS_BOOST_PP_BOOL(q))
# endif
#
# endif
