# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  *
#  * See http://www.boost.org for most recent version.
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# ifndef CPPCMS_BOOST_PREPROCESSOR_LIST_ADT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_LIST_ADT_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
# include <cppcms_boost/preprocessor/detail/is_binary.hpp>
# include <cppcms_boost/preprocessor/logical/compl.hpp>
# include <cppcms_boost/preprocessor/tuple/eat.hpp>
#
# /* BOOST_PP_LIST_CONS */
#
# define CPPCMS_BOOST_PP_LIST_CONS(head, tail) (head, tail)
#
# /* BOOST_PP_LIST_NIL */
#
# define CPPCMS_BOOST_PP_LIST_NIL CPPCMS_BOOST_PP_NIL
#
# /* BOOST_PP_LIST_FIRST */
#
# define CPPCMS_BOOST_PP_LIST_FIRST(list) CPPCMS_BOOST_PP_LIST_FIRST_D(list)
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_LIST_FIRST_D(list) CPPCMS_BOOST_PP_LIST_FIRST_I list
# else
#    define CPPCMS_BOOST_PP_LIST_FIRST_D(list) CPPCMS_BOOST_PP_LIST_FIRST_I ## list
# endif
#
# define CPPCMS_BOOST_PP_LIST_FIRST_I(head, tail) head
#
# /* BOOST_PP_LIST_REST */
#
# define CPPCMS_BOOST_PP_LIST_REST(list) CPPCMS_BOOST_PP_LIST_REST_D(list)
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_LIST_REST_D(list) CPPCMS_BOOST_PP_LIST_REST_I list
# else
#    define CPPCMS_BOOST_PP_LIST_REST_D(list) CPPCMS_BOOST_PP_LIST_REST_I ## list
# endif
#
# define CPPCMS_BOOST_PP_LIST_REST_I(head, tail) tail
#
# /* BOOST_PP_LIST_IS_CONS */
#
# if CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_BCC()
#    define CPPCMS_BOOST_PP_LIST_IS_CONS(list) CPPCMS_BOOST_PP_LIST_IS_CONS_D(list)
#    define CPPCMS_BOOST_PP_LIST_IS_CONS_D(list) CPPCMS_BOOST_PP_LIST_IS_CONS_ ## list
#    define CPPCMS_BOOST_PP_LIST_IS_CONS_(head, tail) 1
#    define CPPCMS_BOOST_PP_LIST_IS_CONS_CPPCMS_BOOST_PP_NIL 0
# else
#    define CPPCMS_BOOST_PP_LIST_IS_CONS(list) CPPCMS_BOOST_PP_IS_BINARY(list)
# endif
#
# /* BOOST_PP_LIST_IS_NIL */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_BCC()
#    define CPPCMS_BOOST_PP_LIST_IS_NIL(list) CPPCMS_BOOST_PP_COMPL(CPPCMS_BOOST_PP_IS_BINARY(list))
# else
#    define CPPCMS_BOOST_PP_LIST_IS_NIL(list) CPPCMS_BOOST_PP_COMPL(CPPCMS_BOOST_PP_LIST_IS_CONS(list))
# endif
#
# endif
