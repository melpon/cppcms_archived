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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ITERATION_LOCAL_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ITERATION_LOCAL_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/slot/slot.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_LOCAL_ITERATE */
#
# define CPPCMS_BOOST_PP_LOCAL_ITERATE() <cppcms_boost/preprocessor/iteration/detail/local.hpp>
#
# define CPPCMS_BOOST_PP_LOCAL_C(n) (CPPCMS_BOOST_PP_LOCAL_S) <= n && (CPPCMS_BOOST_PP_LOCAL_F) >= n
# define CPPCMS_BOOST_PP_LOCAL_R(n) (CPPCMS_BOOST_PP_LOCAL_F) <= n && (CPPCMS_BOOST_PP_LOCAL_S) >= n
#
# endif
