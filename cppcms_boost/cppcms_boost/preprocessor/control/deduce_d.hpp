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
# ifndef CPPCMS_BOOST_PREPROCESSOR_CONTROL_DEDUCE_D_HPP
# define CPPCMS_BOOST_PREPROCESSOR_CONTROL_DEDUCE_D_HPP
#
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/detail/auto_rec.hpp>
#
# /* BOOST_PP_DEDUCE_D */
#
# define CPPCMS_BOOST_PP_DEDUCE_D() CPPCMS_BOOST_PP_AUTO_REC(CPPCMS_BOOST_PP_WHILE_P, 256)
#
# endif
