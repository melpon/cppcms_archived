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
# ifndef CPPCMS_BOOST_PREPROCESSOR_CONTROL_IIF_HPP
# define CPPCMS_BOOST_PREPROCESSOR_CONTROL_IIF_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_IIF(bit, t, f) CPPCMS_BOOST_PP_IIF_I(bit, t, f)
# else
#    define CPPCMS_BOOST_PP_IIF(bit, t, f) CPPCMS_BOOST_PP_IIF_OO((bit, t, f))
#    define CPPCMS_BOOST_PP_IIF_OO(par) CPPCMS_BOOST_PP_IIF_I ## par
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_IIF_I(bit, t, f) CPPCMS_BOOST_PP_IIF_ ## bit(t, f)
# else
#    define CPPCMS_BOOST_PP_IIF_I(bit, t, f) CPPCMS_BOOST_PP_IIF_II(CPPCMS_BOOST_PP_IIF_ ## bit(t, f))
#    define CPPCMS_BOOST_PP_IIF_II(id) id
# endif
#
# define CPPCMS_BOOST_PP_IIF_0(t, f) f
# define CPPCMS_BOOST_PP_IIF_1(t, f) t
#
# endif
