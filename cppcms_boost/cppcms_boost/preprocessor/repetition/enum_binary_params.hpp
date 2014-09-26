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
# ifndef CPPCMS_BOOST_PREPROCESSOR_REPETITION_ENUM_BINARY_PARAMS_HPP
# define CPPCMS_BOOST_PREPROCESSOR_REPETITION_ENUM_BINARY_PARAMS_HPP
#
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/punctuation/comma_if.hpp>
# include <cppcms_boost/preprocessor/repetition/repeat.hpp>
# include <cppcms_boost/preprocessor/tuple/elem.hpp>
# include <cppcms_boost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_ENUM_BINARY_PARAMS */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS(count, p1, p2) CPPCMS_BOOST_PP_REPEAT(count, CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# else
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS(count, p1, p2) CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_I(count, p1, p2)
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_I(count, p1, p2) CPPCMS_BOOST_PP_REPEAT(count, CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# endif
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_STRICT()
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M(z, n, pp) CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M_IM(z, n, CPPCMS_BOOST_PP_TUPLE_REM_2 pp)
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M_IM(z, n, im) CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M_I(z, n, im)
# else
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M(z, n, pp) CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M_I(z, n, CPPCMS_BOOST_PP_TUPLE_ELEM(2, 0, pp), CPPCMS_BOOST_PP_TUPLE_ELEM(2, 1, pp))
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M_I(z, n, p1, p2) CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M_II(z, n, p1, p2)
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M_II(z, n, p1, p2) CPPCMS_BOOST_PP_COMMA_IF(n) p1 ## n p2 ## n
# else
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M_I(z, n, p1, p2) CPPCMS_BOOST_PP_COMMA_IF(n) CPPCMS_BOOST_PP_CAT(p1, n) CPPCMS_BOOST_PP_CAT(p2, n)
# endif
#
# /* BOOST_PP_ENUM_BINARY_PARAMS_Z */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, count, p1, p2) CPPCMS_BOOST_PP_REPEAT_ ## z(count, CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# else
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, count, p1, p2) CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_Z_I(z, count, p1, p2)
#    define CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_Z_I(z, count, p1, p2) CPPCMS_BOOST_PP_REPEAT_ ## z(count, CPPCMS_BOOST_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# endif
#
# endif
