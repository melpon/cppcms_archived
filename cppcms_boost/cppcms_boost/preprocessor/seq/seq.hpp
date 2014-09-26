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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_SEQ_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_SEQ_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/seq/elem.hpp>
#
# /* BOOST_PP_SEQ_HEAD */
#
# define CPPCMS_BOOST_PP_SEQ_HEAD(seq) CPPCMS_BOOST_PP_SEQ_ELEM(0, seq)
#
# /* BOOST_PP_SEQ_TAIL */
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_SEQ_TAIL(seq) CPPCMS_BOOST_PP_SEQ_TAIL_1((seq))
#    define CPPCMS_BOOST_PP_SEQ_TAIL_1(par) CPPCMS_BOOST_PP_SEQ_TAIL_2 ## par
#    define CPPCMS_BOOST_PP_SEQ_TAIL_2(seq) CPPCMS_BOOST_PP_SEQ_TAIL_I ## seq
# elif CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_SEQ_TAIL(seq) CPPCMS_BOOST_PP_SEQ_TAIL_ID(CPPCMS_BOOST_PP_SEQ_TAIL_I seq)
#    define CPPCMS_BOOST_PP_SEQ_TAIL_ID(id) id
# elif CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_TAIL(seq) CPPCMS_BOOST_PP_SEQ_TAIL_D(seq)
#    define CPPCMS_BOOST_PP_SEQ_TAIL_D(seq) CPPCMS_BOOST_PP_SEQ_TAIL_I seq
# else
#    define CPPCMS_BOOST_PP_SEQ_TAIL(seq) CPPCMS_BOOST_PP_SEQ_TAIL_I seq
# endif
#
# define CPPCMS_BOOST_PP_SEQ_TAIL_I(x)
#
# /* BOOST_PP_SEQ_NIL */
#
# define CPPCMS_BOOST_PP_SEQ_NIL(x) (x)
#
# endif
