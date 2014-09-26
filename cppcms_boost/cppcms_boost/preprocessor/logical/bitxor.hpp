# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef CPPCMS_BOOST_PREPROCESSOR_LOGICAL_BITXOR_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LOGICAL_BITXOR_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_BITXOR */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_BITXOR(x, y) CPPCMS_BOOST_PP_BITXOR_I(x, y)
# else
#    define CPPCMS_BOOST_PP_BITXOR(x, y) CPPCMS_BOOST_PP_BITXOR_OO((x, y))
#    define CPPCMS_BOOST_PP_BITXOR_OO(par) CPPCMS_BOOST_PP_BITXOR_I ## par
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_BITXOR_I(x, y) CPPCMS_BOOST_PP_BITXOR_ ## x ## y
# else
#    define CPPCMS_BOOST_PP_BITXOR_I(x, y) CPPCMS_BOOST_PP_BITXOR_ID(CPPCMS_BOOST_PP_BITXOR_ ## x ## y)
#    define CPPCMS_BOOST_PP_BITXOR_ID(id) id
# endif
#
# define CPPCMS_BOOST_PP_BITXOR_00 0
# define CPPCMS_BOOST_PP_BITXOR_01 1
# define CPPCMS_BOOST_PP_BITXOR_10 1
# define CPPCMS_BOOST_PP_BITXOR_11 0
#
# endif
