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
# ifndef CPPCMS_BOOST_PREPROCESSOR_DEBUG_ASSERT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_DEBUG_ASSERT_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/expr_iif.hpp>
# include <cppcms_boost/preprocessor/control/iif.hpp>
# include <cppcms_boost/preprocessor/logical/not.hpp>
# include <cppcms_boost/preprocessor/tuple/eat.hpp>
#
# /* BOOST_PP_ASSERT */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ASSERT CPPCMS_BOOST_PP_ASSERT_D
# else
#    define CPPCMS_BOOST_PP_ASSERT(cond) CPPCMS_BOOST_PP_ASSERT_D(cond)
# endif
#
# define CPPCMS_BOOST_PP_ASSERT_D(cond) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_NOT(cond), CPPCMS_BOOST_PP_ASSERT_ERROR, CPPCMS_BOOST_PP_TUPLE_EAT_1)(...)
# define CPPCMS_BOOST_PP_ASSERT_ERROR(x, y, z)
#
# /* BOOST_PP_ASSERT_MSG */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ASSERT_MSG CPPCMS_BOOST_PP_ASSERT_MSG_D
# else
#    define CPPCMS_BOOST_PP_ASSERT_MSG(cond, msg) CPPCMS_BOOST_PP_ASSERT_MSG_D(cond, msg)
# endif
#
# define CPPCMS_BOOST_PP_ASSERT_MSG_D(cond, msg) CPPCMS_BOOST_PP_EXPR_IIF(CPPCMS_BOOST_PP_NOT(cond), msg)
#
# endif
