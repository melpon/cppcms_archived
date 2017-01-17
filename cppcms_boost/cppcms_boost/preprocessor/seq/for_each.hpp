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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_FOR_EACH_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_FOR_EACH_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/repetition/for.hpp>
# include <cppcms_boost/preprocessor/seq/seq.hpp>
# include <cppcms_boost/preprocessor/seq/size.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_SEQ_FOR_EACH */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH(macro, data, seq) CPPCMS_BOOST_PP_FOR((macro, data, seq (nil)), CPPCMS_BOOST_PP_SEQ_FOR_EACH_P, CPPCMS_BOOST_PP_SEQ_FOR_EACH_O, CPPCMS_BOOST_PP_SEQ_FOR_EACH_M)
# else
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH(macro, data, seq) CPPCMS_BOOST_PP_SEQ_FOR_EACH_D(macro, data, seq)
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_D(macro, data, seq) CPPCMS_BOOST_PP_FOR((macro, data, seq (nil)), CPPCMS_BOOST_PP_SEQ_FOR_EACH_P, CPPCMS_BOOST_PP_SEQ_FOR_EACH_O, CPPCMS_BOOST_PP_SEQ_FOR_EACH_M)
# endif
#
# define CPPCMS_BOOST_PP_SEQ_FOR_EACH_P(r, x) CPPCMS_BOOST_PP_DEC(CPPCMS_BOOST_PP_SEQ_SIZE(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, x)))
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_O(r, x) CPPCMS_BOOST_PP_SEQ_FOR_EACH_O_I x
# else
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_O(r, x) CPPCMS_BOOST_PP_SEQ_FOR_EACH_O_I(CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, x), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, x), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, x))
# endif
#
# define CPPCMS_BOOST_PP_SEQ_FOR_EACH_O_I(macro, data, seq) (macro, data, CPPCMS_BOOST_PP_SEQ_TAIL(seq))
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_M(r, x) CPPCMS_BOOST_PP_SEQ_FOR_EACH_M_IM(r, CPPCMS_BOOST_PP_TUPLE_REM_3 x)
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_M_IM(r, im) CPPCMS_BOOST_PP_SEQ_FOR_EACH_M_I(r, im)
# else
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_M(r, x) CPPCMS_BOOST_PP_SEQ_FOR_EACH_M_I(r, CPPCMS_BOOST_PP_TUPLE_ELEM(3, 0, x), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 1, x), CPPCMS_BOOST_PP_TUPLE_ELEM(3, 2, x))
# endif
#
# define CPPCMS_BOOST_PP_SEQ_FOR_EACH_M_I(r, macro, data, seq) macro(r, data, CPPCMS_BOOST_PP_SEQ_HEAD(seq))
#
# /* BOOST_PP_SEQ_FOR_EACH_R */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_R(r, macro, data, seq) CPPCMS_BOOST_PP_FOR_ ## r((macro, data, seq (nil)), CPPCMS_BOOST_PP_SEQ_FOR_EACH_P, CPPCMS_BOOST_PP_SEQ_FOR_EACH_O, CPPCMS_BOOST_PP_SEQ_FOR_EACH_M)
# else
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_R(r, macro, data, seq) CPPCMS_BOOST_PP_SEQ_FOR_EACH_R_I(r, macro, data, seq)
#    define CPPCMS_BOOST_PP_SEQ_FOR_EACH_R_I(r, macro, data, seq) CPPCMS_BOOST_PP_FOR_ ## r((macro, data, seq (nil)), CPPCMS_BOOST_PP_SEQ_FOR_EACH_P, CPPCMS_BOOST_PP_SEQ_FOR_EACH_O, CPPCMS_BOOST_PP_SEQ_FOR_EACH_M)
# endif
#
# endif
