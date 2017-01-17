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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_FIRST_N_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_FIRST_N_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/control/if.hpp>
# include <cppcms_boost/preprocessor/seq/detail/split.hpp>
# include <cppcms_boost/preprocessor/tuple/eat.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_SEQ_FIRST_N */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_FIRST_N(n, seq) CPPCMS_BOOST_PP_IF(n, CPPCMS_BOOST_PP_TUPLE_ELEM, CPPCMS_BOOST_PP_TUPLE_EAT_3)(2, 0, CPPCMS_BOOST_PP_SEQ_SPLIT(n, seq (nil)))
# else
#    define CPPCMS_BOOST_PP_SEQ_FIRST_N(n, seq) CPPCMS_BOOST_PP_SEQ_FIRST_N_I(n, seq)
#    define CPPCMS_BOOST_PP_SEQ_FIRST_N_I(n, seq) CPPCMS_BOOST_PP_IF(n, CPPCMS_BOOST_PP_TUPLE_ELEM, CPPCMS_BOOST_PP_TUPLE_EAT_3)(2, 0, CPPCMS_BOOST_PP_SEQ_SPLIT(n, seq (nil)))
# endif
#
# endif
