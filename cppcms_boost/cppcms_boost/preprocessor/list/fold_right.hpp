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
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
#
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/control/while.hpp>
# include <cppcms_boost/preprocessor/debug/error.hpp>
# include <cppcms_boost/preprocessor/detail/auto_rec.hpp>
#
# if 0
#    define CPPCMS_BOOST_PP_LIST_FOLD_RIGHT(op, state, list)
# endif
#
# define CPPCMS_BOOST_PP_LIST_FOLD_RIGHT CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_, CPPCMS_BOOST_PP_AUTO_REC(CPPCMS_BOOST_PP_WHILE_P, 256))
#
# define CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_257(o, s, l) CPPCMS_BOOST_PP_ERROR(0x0004)
#
# define CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_D(d, o, s, l) CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_ ## d(o, s, l)
# define CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_2ND CPPCMS_BOOST_PP_LIST_FOLD_RIGHT
# define CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_2ND_D CPPCMS_BOOST_PP_LIST_FOLD_RIGHT_D
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    include <cppcms_boost/preprocessor/list/detail/edg/fold_right.hpp>
# else
#    include <cppcms_boost/preprocessor/list/detail/fold_right.hpp>
# endif
#
# endif
