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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ITERATION_ITERATE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ITERATION_ITERATE_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/array/elem.hpp>
# include <cppcms_boost/preprocessor/array/size.hpp>
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/slot/slot.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ITERATION_DEPTH */
#
# define CPPCMS_BOOST_PP_ITERATION_DEPTH() 0
#
# /* BOOST_PP_ITERATION */
#
# define CPPCMS_BOOST_PP_ITERATION() CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATION_, CPPCMS_BOOST_PP_ITERATION_DEPTH())
#
# /* BOOST_PP_ITERATION_START && BOOST_PP_ITERATION_FINISH */
#
# define CPPCMS_BOOST_PP_ITERATION_START() CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATION_START_, CPPCMS_BOOST_PP_ITERATION_DEPTH())
# define CPPCMS_BOOST_PP_ITERATION_FINISH() CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATION_FINISH_, CPPCMS_BOOST_PP_ITERATION_DEPTH())
#
# /* BOOST_PP_ITERATION_FLAGS */
#
# define CPPCMS_BOOST_PP_ITERATION_FLAGS() (CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATION_FLAGS_, CPPCMS_BOOST_PP_ITERATION_DEPTH()))
#
# /* BOOST_PP_FRAME_ITERATION */
#
# define CPPCMS_BOOST_PP_FRAME_ITERATION(i) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATION_, i)
#
# /* BOOST_PP_FRAME_START && BOOST_PP_FRAME_FINISH */
#
# define CPPCMS_BOOST_PP_FRAME_START(i) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATION_START_, i)
# define CPPCMS_BOOST_PP_FRAME_FINISH(i) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATION_FINISH_, i)
#
# /* BOOST_PP_FRAME_FLAGS */
#
# define CPPCMS_BOOST_PP_FRAME_FLAGS(i) (CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATION_FLAGS_, i))
#
# /* BOOST_PP_RELATIVE_ITERATION */
#
# define CPPCMS_BOOST_PP_RELATIVE_ITERATION(i) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_RELATIVE_, i)(CPPCMS_BOOST_PP_ITERATION_)
#
# define CPPCMS_BOOST_PP_RELATIVE_0(m) CPPCMS_BOOST_PP_CAT(m, CPPCMS_BOOST_PP_ITERATION_DEPTH())
# define CPPCMS_BOOST_PP_RELATIVE_1(m) CPPCMS_BOOST_PP_CAT(m, CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_ITERATION_DEPTH()))
# define CPPCMS_BOOST_PP_RELATIVE_2(m) CPPCMS_BOOST_PP_CAT(m, CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_ITERATION_DEPTH())))
# define CPPCMS_BOOST_PP_RELATIVE_3(m) CPPCMS_BOOST_PP_CAT(m, CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_ITERATION_DEPTH()))))
# define CPPCMS_BOOST_PP_RELATIVE_4(m) CPPCMS_BOOST_PP_CAT(m, CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_ITERATION_DEPTH())))))
#
# /* BOOST_PP_RELATIVE_START && BOOST_PP_RELATIVE_FINISH */
#
# define CPPCMS_BOOST_PP_RELATIVE_START(i) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_RELATIVE_, i)(CPPCMS_BOOST_PP_ITERATION_START_)
# define CPPCMS_BOOST_PP_RELATIVE_FINISH(i) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_RELATIVE_, i)(CPPCMS_BOOST_PP_ITERATION_FINISH_)
#
# /* BOOST_PP_RELATIVE_FLAGS */
#
# define CPPCMS_BOOST_PP_RELATIVE_FLAGS(i) (CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_RELATIVE_, i)(CPPCMS_BOOST_PP_ITERATION_FLAGS_))
#
# /* BOOST_PP_ITERATE */
#
# define CPPCMS_BOOST_PP_ITERATE() CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ITERATE_, CPPCMS_BOOST_PP_INC(CPPCMS_BOOST_PP_ITERATION_DEPTH()))
#
# define CPPCMS_BOOST_PP_ITERATE_1 <cppcms_boost/preprocessor/iteration/detail/iter/forward1.hpp>
# define CPPCMS_BOOST_PP_ITERATE_2 <cppcms_boost/preprocessor/iteration/detail/iter/forward2.hpp>
# define CPPCMS_BOOST_PP_ITERATE_3 <cppcms_boost/preprocessor/iteration/detail/iter/forward3.hpp>
# define CPPCMS_BOOST_PP_ITERATE_4 <cppcms_boost/preprocessor/iteration/detail/iter/forward4.hpp>
# define CPPCMS_BOOST_PP_ITERATE_5 <cppcms_boost/preprocessor/iteration/detail/iter/forward5.hpp>
#
# endif
