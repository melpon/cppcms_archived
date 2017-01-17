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
# ifndef CPPCMS_BOOST_PREPROCESSOR_DEBUG_LINE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_DEBUG_LINE_HPP
#
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/iteration/iterate.hpp>
# include <cppcms_boost/preprocessor/stringize.hpp>
#
# /* BOOST_PP_LINE */
#
# if CPPCMS_BOOST_PP_CONFIG_EXTENDED_LINE_INFO
#    define CPPCMS_BOOST_PP_LINE(line, file) line CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_LINE_, CPPCMS_BOOST_PP_IS_ITERATING)(file)
#    define CPPCMS_BOOST_PP_LINE_CPPCMS_BOOST_PP_IS_ITERATING(file) #file
#    define CPPCMS_BOOST_PP_LINE_1(file) CPPCMS_BOOST_PP_STRINGIZE(file CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_LINE_I_, CPPCMS_BOOST_PP_ITERATION_DEPTH())())
#    define CPPCMS_BOOST_PP_LINE_I_1() [CPPCMS_BOOST_PP_FRAME_ITERATION(1)]
#    define CPPCMS_BOOST_PP_LINE_I_2() CPPCMS_BOOST_PP_LINE_I_1()[CPPCMS_BOOST_PP_FRAME_ITERATION(2)]
#    define CPPCMS_BOOST_PP_LINE_I_3() CPPCMS_BOOST_PP_LINE_I_2()[CPPCMS_BOOST_PP_FRAME_ITERATION(3)]
#    define CPPCMS_BOOST_PP_LINE_I_4() CPPCMS_BOOST_PP_LINE_I_3()[CPPCMS_BOOST_PP_FRAME_ITERATION(4)]
#    define CPPCMS_BOOST_PP_LINE_I_5() CPPCMS_BOOST_PP_LINE_I_4()[CPPCMS_BOOST_PP_FRAME_ITERATION(5)]
# else
#    define CPPCMS_BOOST_PP_LINE(line, file) line __FILE__
# endif
#
# endif
