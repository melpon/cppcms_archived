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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/repetition/for.hpp>
# include <cppcms_boost/preprocessor/seq/seq.hpp>
# include <cppcms_boost/preprocessor/seq/size.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_SEQ_FOR_EACH_I */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I(macro, data, seq) CPPCMS_BOOST_PP_FOR((macro, data, seq (nil), 0), CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_P, CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O, CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M)
# else
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I(macro, data, seq) CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_I(macro, data, seq)
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_I(macro, data, seq) CPPCMS_BOOST_PP_FOR((macro, data, seq (nil), 0), CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_P, CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O, CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M)
# endif
#
# define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_P(r, x) CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_SEQ_SIZE(CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, x)))
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O(r, x) CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O_I x
# else
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O(r, x) CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O_I(CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 1, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O_I(macro, data, seq, i) (macro, data, CPPCMS_BOOST_PP_SEQ_TAIL(seq), CPPCMS_BOOST_PP_INC(i))
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M(r, x) CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M_IM(r, CPPCMS_BOOST_PP_TUPLE_REM_4 x)
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M_IM(r, im) CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M_I(r, im)
# else
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M(r, x) CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M_I(r, CPPCMS_BOOST_PP_TUPLE_ELEM(4, 0, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 1, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 2, x), CPPCMS_BOOST_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M_I(r, macro, data, seq, i) macro(r, data, i, CPPCMS_BOOST_PP_SEQ_HEAD(seq))
#
# /* BOOST_PP_SEQ_FOR_EACH_I_R */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) CPPCMS_BOOST_PP_FOR_ ## r((macro, data, seq (nil), 0), CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_P, CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O, CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M)
# else
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq)
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq) CPPCMS_BOOST_PP_FOR_ ## r((macro, data, seq (nil), 0), CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_P, CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_O, CPPCMS_BOOST_PP_SEQ_FOR_EACH_I_M)
# endif
#
# endif
