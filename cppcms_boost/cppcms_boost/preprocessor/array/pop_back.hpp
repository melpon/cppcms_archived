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
# ifndef CPPCMS_BOOST_PREPROCESSOR_ARRAY_POP_BACK_HPP
# define CPPCMS_BOOST_PREPROCESSOR_ARRAY_POP_BACK_HPP
#
# include <cppcms_boost/preprocessor/arithmetic/dec.hpp>
# include <cppcms_boost/preprocessor/array/elem.hpp>
# include <cppcms_boost/preprocessor/array/size.hpp>
# include <cppcms_boost/preprocessor/repetition/enum.hpp>
# include <cppcms_boost/preprocessor/repetition/deduce_z.hpp>
#
# /* BOOST_PP_ARRAY_POP_BACK */
#
# define CPPCMS_BOOST_PP_ARRAY_POP_BACK(array) CPPCMS_BOOST_PP_ARRAY_POP_BACK_Z(CPPCMS_BOOST_PP_DEDUCE_Z(), array)
#
# /* BOOST_PP_ARRAY_POP_BACK_Z */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_ARRAY_POP_BACK_Z(z, array) CPPCMS_BOOST_PP_ARRAY_POP_BACK_I(z, CPPCMS_BOOST_PP_ARRAY_SIZE(array), array)
# else
#    define CPPCMS_BOOST_PP_ARRAY_POP_BACK_Z(z, array) CPPCMS_BOOST_PP_ARRAY_POP_BACK_Z_D(z, array)
#    define CPPCMS_BOOST_PP_ARRAY_POP_BACK_Z_D(z, array) CPPCMS_BOOST_PP_ARRAY_POP_BACK_I(z, CPPCMS_BOOST_PP_ARRAY_SIZE(array), array)
# endif
#
# define CPPCMS_BOOST_PP_ARRAY_POP_BACK_I(z, size, array) (CPPCMS_BOOST_PP_DEC(size), (CPPCMS_BOOST_PP_ENUM_ ## z(CPPCMS_BOOST_PP_DEC(size), CPPCMS_BOOST_PP_ARRAY_POP_BACK_M, array)))
# define CPPCMS_BOOST_PP_ARRAY_POP_BACK_M(z, n, data) CPPCMS_BOOST_PP_ARRAY_ELEM(n, data)
#
# endif
