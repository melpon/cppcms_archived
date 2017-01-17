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
# ifndef CPPCMS_BOOST_PREPROCESSOR_TUPLE_REVERSE_HPP
# define CPPCMS_BOOST_PREPROCESSOR_TUPLE_REVERSE_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_TUPLE_REVERSE */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_TUPLE_REVERSE(size, tuple) CPPCMS_BOOST_PP_TUPLE_REVERSE_I(size, tuple)
#    if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#        define CPPCMS_BOOST_PP_TUPLE_REVERSE_I(s, t) CPPCMS_BOOST_PP_TUPLE_REVERSE_ ## s t
#    else
#        define CPPCMS_BOOST_PP_TUPLE_REVERSE_I(s, t) CPPCMS_BOOST_PP_TUPLE_REVERSE_II(CPPCMS_BOOST_PP_TUPLE_REVERSE_ ## s t)
#        define CPPCMS_BOOST_PP_TUPLE_REVERSE_II(res) res
#    endif
# else
#    define CPPCMS_BOOST_PP_TUPLE_REVERSE(size, tuple) CPPCMS_BOOST_PP_TUPLE_REVERSE_OO((size, tuple))
#    define CPPCMS_BOOST_PP_TUPLE_REVERSE_OO(par) CPPCMS_BOOST_PP_TUPLE_REVERSE_I ## par
#    define CPPCMS_BOOST_PP_TUPLE_REVERSE_I(s, t) CPPCMS_BOOST_PP_TUPLE_REVERSE_ ## s ## t
# endif
#
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_0() ()
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_1(a) (a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_2(a, b) (b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_3(a, b, c) (c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_4(a, b, c, d) (d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_5(a, b, c, d, e) (e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_6(a, b, c, d, e, f) (f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_7(a, b, c, d, e, f, g) (g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_8(a, b, c, d, e, f, g, h) (h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_9(a, b, c, d, e, f, g, h, i) (i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_10(a, b, c, d, e, f, g, h, i, j) (j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_11(a, b, c, d, e, f, g, h, i, j, k) (k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_12(a, b, c, d, e, f, g, h, i, j, k, l) (l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_13(a, b, c, d, e, f, g, h, i, j, k, l, m) (m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) (n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CPPCMS_BOOST_PP_TUPLE_REVERSE_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (y, x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
#
# endif
