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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_REVERSE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_REVERSE_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/facilities/empty.hpp>
# include <cppcms_boost/preprocessor/seq/fold_left.hpp>
#
# /* BOOST_PP_SEQ_REVERSE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_REVERSE(seq) CPPCMS_BOOST_PP_SEQ_FOLD_LEFT(CPPCMS_BOOST_PP_SEQ_REVERSE_O, CPPCMS_BOOST_PP_EMPTY, seq)()
# else
#    define CPPCMS_BOOST_PP_SEQ_REVERSE(seq) CPPCMS_BOOST_PP_SEQ_REVERSE_I(seq)
#    define CPPCMS_BOOST_PP_SEQ_REVERSE_I(seq) CPPCMS_BOOST_PP_SEQ_FOLD_LEFT(CPPCMS_BOOST_PP_SEQ_REVERSE_O, CPPCMS_BOOST_PP_EMPTY, seq)()
# endif
#
# define CPPCMS_BOOST_PP_SEQ_REVERSE_O(s, state, elem) (elem) state
#
# /* BOOST_PP_SEQ_REVERSE_S */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_REVERSE_S(s, seq) CPPCMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(CPPCMS_BOOST_PP_SEQ_REVERSE_O, CPPCMS_BOOST_PP_EMPTY, seq)()
# else
#    define CPPCMS_BOOST_PP_SEQ_REVERSE_S(s, seq) CPPCMS_BOOST_PP_SEQ_REVERSE_S_I(s, seq)
#    define CPPCMS_BOOST_PP_SEQ_REVERSE_S_I(s, seq) CPPCMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(CPPCMS_BOOST_PP_SEQ_REVERSE_O, CPPCMS_BOOST_PP_EMPTY, seq)()
# endif
#
# endif
