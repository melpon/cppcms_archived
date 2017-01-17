# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef CPPCMS_BOOST_PREPROCESSOR_TUPLE_EAT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_TUPLE_EAT_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_TUPLE_EAT */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_TUPLE_EAT(size) CPPCMS_BOOST_PP_TUPLE_EAT_I(size)
# else
#    define CPPCMS_BOOST_PP_TUPLE_EAT(size) CPPCMS_BOOST_PP_TUPLE_EAT_OO((size))
#    define CPPCMS_BOOST_PP_TUPLE_EAT_OO(par) CPPCMS_BOOST_PP_TUPLE_EAT_I ## par
# endif
#
# define CPPCMS_BOOST_PP_TUPLE_EAT_I(size) CPPCMS_BOOST_PP_TUPLE_EAT_ ## size
#
# define CPPCMS_BOOST_PP_TUPLE_EAT_0()
# define CPPCMS_BOOST_PP_TUPLE_EAT_1(a)
# define CPPCMS_BOOST_PP_TUPLE_EAT_2(a, b)
# define CPPCMS_BOOST_PP_TUPLE_EAT_3(a, b, c)
# define CPPCMS_BOOST_PP_TUPLE_EAT_4(a, b, c, d)
# define CPPCMS_BOOST_PP_TUPLE_EAT_5(a, b, c, d, e)
# define CPPCMS_BOOST_PP_TUPLE_EAT_6(a, b, c, d, e, f)
# define CPPCMS_BOOST_PP_TUPLE_EAT_7(a, b, c, d, e, f, g)
# define CPPCMS_BOOST_PP_TUPLE_EAT_8(a, b, c, d, e, f, g, h)
# define CPPCMS_BOOST_PP_TUPLE_EAT_9(a, b, c, d, e, f, g, h, i)
# define CPPCMS_BOOST_PP_TUPLE_EAT_10(a, b, c, d, e, f, g, h, i, j)
# define CPPCMS_BOOST_PP_TUPLE_EAT_11(a, b, c, d, e, f, g, h, i, j, k)
# define CPPCMS_BOOST_PP_TUPLE_EAT_12(a, b, c, d, e, f, g, h, i, j, k, l)
# define CPPCMS_BOOST_PP_TUPLE_EAT_13(a, b, c, d, e, f, g, h, i, j, k, l, m)
# define CPPCMS_BOOST_PP_TUPLE_EAT_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n)
# define CPPCMS_BOOST_PP_TUPLE_EAT_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)
# define CPPCMS_BOOST_PP_TUPLE_EAT_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)
# define CPPCMS_BOOST_PP_TUPLE_EAT_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q)
# define CPPCMS_BOOST_PP_TUPLE_EAT_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r)
# define CPPCMS_BOOST_PP_TUPLE_EAT_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s)
# define CPPCMS_BOOST_PP_TUPLE_EAT_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t)
# define CPPCMS_BOOST_PP_TUPLE_EAT_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u)
# define CPPCMS_BOOST_PP_TUPLE_EAT_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v)
# define CPPCMS_BOOST_PP_TUPLE_EAT_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w)
# define CPPCMS_BOOST_PP_TUPLE_EAT_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x)
# define CPPCMS_BOOST_PP_TUPLE_EAT_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y)
#
# endif
