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
# ifndef CPPCMS_BOOST_PREPROCESSOR_DEBUG_ERROR_HPP
# define CPPCMS_BOOST_PREPROCESSOR_DEBUG_ERROR_HPP
#
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_ERROR */
#
# if CPPCMS_BOOST_PP_CONFIG_ERRORS
#    define CPPCMS_BOOST_PP_ERROR(code) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ERROR_, code)
# endif
#
# define CPPCMS_BOOST_PP_ERROR_0x0000 CPPCMS_BOOST_PP_ERROR(0x0000, CPPCMS_BOOST_PP_INDEX_OUT_OF_BOUNDS)
# define CPPCMS_BOOST_PP_ERROR_0x0001 CPPCMS_BOOST_PP_ERROR(0x0001, CPPCMS_BOOST_PP_WHILE_OVERFLOW)
# define CPPCMS_BOOST_PP_ERROR_0x0002 CPPCMS_BOOST_PP_ERROR(0x0002, CPPCMS_BOOST_PP_FOR_OVERFLOW)
# define CPPCMS_BOOST_PP_ERROR_0x0003 CPPCMS_BOOST_PP_ERROR(0x0003, CPPCMS_BOOST_PP_REPEAT_OVERFLOW)
# define CPPCMS_BOOST_PP_ERROR_0x0004 CPPCMS_BOOST_PP_ERROR(0x0004, CPPCMS_BOOST_PP_LIST_FOLD_OVERFLOW)
# define CPPCMS_BOOST_PP_ERROR_0x0005 CPPCMS_BOOST_PP_ERROR(0x0005, CPPCMS_BOOST_PP_SEQ_FOLD_OVERFLOW)
# define CPPCMS_BOOST_PP_ERROR_0x0006 CPPCMS_BOOST_PP_ERROR(0x0006, CPPCMS_BOOST_PP_ARITHMETIC_OVERFLOW)
# define CPPCMS_BOOST_PP_ERROR_0x0007 CPPCMS_BOOST_PP_ERROR(0x0007, CPPCMS_BOOST_PP_DIVISION_BY_ZERO)
#
# endif
