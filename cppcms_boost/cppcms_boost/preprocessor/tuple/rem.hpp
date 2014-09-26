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
# ifndef CPPCMS_BOOST_PREPROCESSOR_TUPLE_REM_HPP
# define CPPCMS_BOOST_PREPROCESSOR_TUPLE_REM_HPP
#
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_TUPLE_REM */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_TUPLE_REM(size) CPPCMS_BOOST_PP_TUPLE_REM_I(size)
# else
#    define CPPCMS_BOOST_PP_TUPLE_REM(size) CPPCMS_BOOST_PP_TUPLE_REM_OO((size))
#    define CPPCMS_BOOST_PP_TUPLE_REM_OO(par) CPPCMS_BOOST_PP_TUPLE_REM_I ## par
# endif
#
# define CPPCMS_BOOST_PP_TUPLE_REM_I(size) CPPCMS_BOOST_PP_TUPLE_REM_ ## size
#
# define CPPCMS_BOOST_PP_TUPLE_REM_0()
# define CPPCMS_BOOST_PP_TUPLE_REM_1(a) a
# define CPPCMS_BOOST_PP_TUPLE_REM_2(a, b) a, b
# define CPPCMS_BOOST_PP_TUPLE_REM_3(a, b, c) a, b, c
# define CPPCMS_BOOST_PP_TUPLE_REM_4(a, b, c, d) a, b, c, d
# define CPPCMS_BOOST_PP_TUPLE_REM_5(a, b, c, d, e) a, b, c, d, e
# define CPPCMS_BOOST_PP_TUPLE_REM_6(a, b, c, d, e, f) a, b, c, d, e, f
# define CPPCMS_BOOST_PP_TUPLE_REM_7(a, b, c, d, e, f, g) a, b, c, d, e, f, g
# define CPPCMS_BOOST_PP_TUPLE_REM_8(a, b, c, d, e, f, g, h) a, b, c, d, e, f, g, h
# define CPPCMS_BOOST_PP_TUPLE_REM_9(a, b, c, d, e, f, g, h, i) a, b, c, d, e, f, g, h, i
# define CPPCMS_BOOST_PP_TUPLE_REM_10(a, b, c, d, e, f, g, h, i, j) a, b, c, d, e, f, g, h, i, j
# define CPPCMS_BOOST_PP_TUPLE_REM_11(a, b, c, d, e, f, g, h, i, j, k) a, b, c, d, e, f, g, h, i, j, k
# define CPPCMS_BOOST_PP_TUPLE_REM_12(a, b, c, d, e, f, g, h, i, j, k, l) a, b, c, d, e, f, g, h, i, j, k, l
# define CPPCMS_BOOST_PP_TUPLE_REM_13(a, b, c, d, e, f, g, h, i, j, k, l, m) a, b, c, d, e, f, g, h, i, j, k, l, m
# define CPPCMS_BOOST_PP_TUPLE_REM_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) a, b, c, d, e, f, g, h, i, j, k, l, m, n
# define CPPCMS_BOOST_PP_TUPLE_REM_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
# define CPPCMS_BOOST_PP_TUPLE_REM_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
# define CPPCMS_BOOST_PP_TUPLE_REM_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q
# define CPPCMS_BOOST_PP_TUPLE_REM_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r
# define CPPCMS_BOOST_PP_TUPLE_REM_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s
# define CPPCMS_BOOST_PP_TUPLE_REM_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t
# define CPPCMS_BOOST_PP_TUPLE_REM_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u
# define CPPCMS_BOOST_PP_TUPLE_REM_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v
# define CPPCMS_BOOST_PP_TUPLE_REM_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w
# define CPPCMS_BOOST_PP_TUPLE_REM_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x
# define CPPCMS_BOOST_PP_TUPLE_REM_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y
#
# /* BOOST_PP_TUPLE_REM_CTOR */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_EDG()
#    define CPPCMS_BOOST_PP_TUPLE_REM_CTOR(size, tuple) CPPCMS_BOOST_PP_TUPLE_REM_CTOR_I(CPPCMS_BOOST_PP_TUPLE_REM(size), tuple)
# else
#    define CPPCMS_BOOST_PP_TUPLE_REM_CTOR(size, tuple) CPPCMS_BOOST_PP_TUPLE_REM_CTOR_D(size, tuple)
#    define CPPCMS_BOOST_PP_TUPLE_REM_CTOR_D(size, tuple) CPPCMS_BOOST_PP_TUPLE_REM_CTOR_I(CPPCMS_BOOST_PP_TUPLE_REM(size), tuple)
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_TUPLE_REM_CTOR_I(ext, tuple) ext tuple
# else
#    define CPPCMS_BOOST_PP_TUPLE_REM_CTOR_I(ext, tuple) CPPCMS_BOOST_PP_TUPLE_REM_CTOR_OO((ext, tuple))
#    define CPPCMS_BOOST_PP_TUPLE_REM_CTOR_OO(par) CPPCMS_BOOST_PP_TUPLE_REM_CTOR_II ## par
#    define CPPCMS_BOOST_PP_TUPLE_REM_CTOR_II(ext, tuple) ext ## tuple
# endif
#
# endif
