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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LOGICAL_COMPL_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LOGICAL_COMPL_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_COMPL */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_COMPL(x) CPPCMS_BOOST_PP_COMPL_I(x)
# else
#    define CPPCMS_BOOST_PP_COMPL(x) CPPCMS_BOOST_PP_COMPL_OO((x))
#    define CPPCMS_BOOST_PP_COMPL_OO(par) CPPCMS_BOOST_PP_COMPL_I ## par
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_COMPL_I(x) CPPCMS_BOOST_PP_COMPL_ ## x
# else
#    define CPPCMS_BOOST_PP_COMPL_I(x) CPPCMS_BOOST_PP_COMPL_ID(CPPCMS_BOOST_PP_COMPL_ ## x)
#    define CPPCMS_BOOST_PP_COMPL_ID(id) id
# endif
#
# define CPPCMS_BOOST_PP_COMPL_0 1
# define CPPCMS_BOOST_PP_COMPL_1 0
#
# endif
