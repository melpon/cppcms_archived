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
# ifndef CPPCMS_BOOST_PREPROCESSOR_STRINGIZE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_STRINGIZE_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_STRINGIZE */
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_STRINGIZE(text) CPPCMS_BOOST_PP_STRINGIZE_A((text))
#    define CPPCMS_BOOST_PP_STRINGIZE_A(arg) CPPCMS_BOOST_PP_STRINGIZE_I arg
# elif CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_STRINGIZE(text) CPPCMS_BOOST_PP_STRINGIZE_OO((text))
#    define CPPCMS_BOOST_PP_STRINGIZE_OO(par) CPPCMS_BOOST_PP_STRINGIZE_I ## par
# else
#    define CPPCMS_BOOST_PP_STRINGIZE(text) CPPCMS_BOOST_PP_STRINGIZE_I(text)
# endif
#
# define CPPCMS_BOOST_PP_STRINGIZE_I(text) #text
#
# endif
