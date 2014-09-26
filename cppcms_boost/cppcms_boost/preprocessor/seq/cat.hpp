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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_CAT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_CAT_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/if.hpp>
# include <cppcms_boost/preprocessor/seq/fold_left.hpp>
# include <cppcms_boost/preprocessor/seq/seq.hpp>
# include <cppcms_boost/preprocessor/seq/size.hpp>
# include <cppcms_boost/preprocessor/tuple/eat.hpp>
#
# /* BOOST_PP_SEQ_CAT */
#
# define CPPCMS_BOOST_PP_SEQ_CAT(seq) \
    CPPCMS_BOOST_PP_IF( \
        CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_SEQ_SIZE(seq)), \
        CPPCMS_BOOST_PP_SEQ_CAT_I, \
        CPPCMS_BOOST_PP_SEQ_HEAD(seq) CPPCMS_BOOST_PP_TUPLE_EAT_1 \
    )(seq) \
    /**/
# define CPPCMS_BOOST_PP_SEQ_CAT_I(seq) CPPCMS_BOOST_PP_SEQ_FOLD_LEFT(CPPCMS_BOOST_PP_SEQ_CAT_O, CPPCMS_BOOST_PP_SEQ_HEAD(seq), CPPCMS_BOOST_PP_SEQ_TAIL(seq))
#
# define CPPCMS_BOOST_PP_SEQ_CAT_O(s, st, elem) CPPCMS_BOOST_PP_SEQ_CAT_O_I(st, elem)
# define CPPCMS_BOOST_PP_SEQ_CAT_O_I(a, b) a ## b
#
# /* BOOST_PP_SEQ_CAT_S */
#
# define CPPCMS_BOOST_PP_SEQ_CAT_S(s, seq) \
    CPPCMS_BOOST_PP_IF( \
        CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_SEQ_SIZE(seq)), \
        CPPCMS_BOOST_PP_SEQ_CAT_S_I, \
        CPPCMS_BOOST_PP_SEQ_HEAD(seq) CPPCMS_BOOST_PP_TUPLE_EAT_2 \
    )(s, seq) \
    /**/
# define CPPCMS_BOOST_PP_SEQ_CAT_S_I(s, seq) CPPCMS_BOOST_PP_SEQ_FOLD_LEFT_ ## s(CPPCMS_BOOST_PP_SEQ_CAT_O, CPPCMS_BOOST_PP_SEQ_HEAD(seq), CPPCMS_BOOST_PP_SEQ_TAIL(seq))
#
# endif
