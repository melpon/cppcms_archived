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
# ifndef CPPCMS_BOOST_PREPROCESSOR_FACILITIES_EXPAND_HPP
# define CPPCMS_BOOST_PREPROCESSOR_FACILITIES_EXPAND_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC() && ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_DMC()
#    define CPPCMS_BOOST_PP_EXPAND(x) CPPCMS_BOOST_PP_EXPAND_I(x)
# else
#    define CPPCMS_BOOST_PP_EXPAND(x) CPPCMS_BOOST_PP_EXPAND_OO((x))
#    define CPPCMS_BOOST_PP_EXPAND_OO(par) CPPCMS_BOOST_PP_EXPAND_I ## par
# endif
#
# define CPPCMS_BOOST_PP_EXPAND_I(x) x
#
# endif
