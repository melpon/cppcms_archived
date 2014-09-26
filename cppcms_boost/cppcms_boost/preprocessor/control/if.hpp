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
# ifndef CPPCMS_BOOST_PREPROCESSOR_CONTROL_IF_HPP
# define CPPCMS_BOOST_PREPROCESSOR_CONTROL_IF_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/iif.hpp>
# include <cppcms_boost/preprocessor/logical/bool.hpp>
#
# /* BOOST_PP_IF */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_IF(cond, t, f) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_BOOL(cond), t, f)
# else
#    define CPPCMS_BOOST_PP_IF(cond, t, f) CPPCMS_BOOST_PP_IF_I(cond, t, f)
#    define CPPCMS_BOOST_PP_IF_I(cond, t, f) CPPCMS_BOOST_PP_IIF(CPPCMS_BOOST_PP_BOOL(cond), t, f)
# endif
#
# endif
