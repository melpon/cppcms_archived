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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SEQ_REST_N_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SEQ_REST_N_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/inc.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/facilities/empty.hpp>
# include <cppcms_boost/preprocessor/seq/detail/split.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_SEQ_REST_N */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_SEQ_REST_N(n, seq) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, CPPCMS_BOOST_PP_SEQ_SPLIT(CPPCMS_BOOST_PP_INC(n), (nil) seq CPPCMS_BOOST_PP_EMPTY))()
# else
#    define CPPCMS_BOOST_PP_SEQ_REST_N(n, seq) CPPCMS_BOOST_PP_SEQ_REST_N_I(n, seq)
#    define CPPCMS_BOOST_PP_SEQ_REST_N_I(n, seq) CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, CPPCMS_BOOST_PP_SEQ_SPLIT(CPPCMS_BOOST_PP_INC(n), (nil) seq CPPCMS_BOOST_PP_EMPTY))()
# endif
#
# endif
