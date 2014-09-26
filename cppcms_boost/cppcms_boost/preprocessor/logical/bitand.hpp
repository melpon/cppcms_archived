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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LOGICAL_BITAND_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LOGICAL_BITAND_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_BITAND */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_BITAND(x, y) CPPCMS_BOOST_PP_BITAND_I(x, y)
# else
#    define CPPCMS_BOOST_PP_BITAND(x, y) CPPCMS_BOOST_PP_BITAND_OO((x, y))
#    define CPPCMS_BOOST_PP_BITAND_OO(par) CPPCMS_BOOST_PP_BITAND_I ## par
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_BITAND_I(x, y) CPPCMS_BOOST_PP_BITAND_ ## x ## y
# else
#    define CPPCMS_BOOST_PP_BITAND_I(x, y) CPPCMS_BOOST_PP_BITAND_ID(CPPCMS_BOOST_PP_BITAND_ ## x ## y)
#    define CPPCMS_BOOST_PP_BITAND_ID(res) res
# endif
#
# define CPPCMS_BOOST_PP_BITAND_00 0
# define CPPCMS_BOOST_PP_BITAND_01 0
# define CPPCMS_BOOST_PP_BITAND_10 0
# define CPPCMS_BOOST_PP_BITAND_11 1
#
# endif
