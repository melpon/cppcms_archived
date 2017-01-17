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
# ifndef CPPCMS_BOOST_PREPROCESSOR_CAT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_CAT_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_CAT */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_CAT(a, b) CPPCMS_BOOST_PP_CAT_I(a, b)
# else
#    define CPPCMS_BOOST_PP_CAT(a, b) CPPCMS_BOOST_PP_CAT_OO((a, b))
#    define CPPCMS_BOOST_PP_CAT_OO(par) CPPCMS_BOOST_PP_CAT_I ## par
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_CAT_I(a, b) a ## b
# else
#    define CPPCMS_BOOST_PP_CAT_I(a, b) CPPCMS_BOOST_PP_CAT_II(a ## b)
#    define CPPCMS_BOOST_PP_CAT_II(res) res
# endif
#
# endif
