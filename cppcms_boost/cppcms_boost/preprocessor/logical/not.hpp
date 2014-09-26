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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LOGICAL_NOT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LOGICAL_NOT_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/logical/bool.hpp>
# include <cppcms_boost/preprocessor/logical/compl.hpp>
#
# /* BOOST_PP_NOT */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_NOT(x) CPPCMS_BOOST_PP_COMPL(CPPCMS_BOOST_PP_BOOL(x))
# else
#    define CPPCMS_BOOST_PP_NOT(x) CPPCMS_BOOST_PP_NOT_I(x)
#    define CPPCMS_BOOST_PP_NOT_I(x) CPPCMS_BOOST_PP_COMPL(CPPCMS_BOOST_PP_BOOL(x))
# endif
#
# endif
