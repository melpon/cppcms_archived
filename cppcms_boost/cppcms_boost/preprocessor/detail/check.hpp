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
# ifndef CPPCMS_BOOST_PREPROCESSOR_DETAIL_CHECK_HPP
# define CPPCMS_BOOST_PREPROCESSOR_DETAIL_CHECK_HPP
#
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_CHECK */
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MWCC()
#    define CPPCMS_BOOST_PP_CHECK(x, type) CPPCMS_BOOST_PP_CHECK_D(x, type)
# else
#    define CPPCMS_BOOST_PP_CHECK(x, type) CPPCMS_BOOST_PP_CHECK_OO((x, type))
#    define CPPCMS_BOOST_PP_CHECK_OO(par) CPPCMS_BOOST_PP_CHECK_D ## par
# endif
#
# if ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC() && ~CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_DMC()
#    define CPPCMS_BOOST_PP_CHECK_D(x, type) CPPCMS_BOOST_PP_CHECK_1(CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_CHECK_RESULT_, type x))
#    define CPPCMS_BOOST_PP_CHECK_1(chk) CPPCMS_BOOST_PP_CHECK_2(chk)
#    define CPPCMS_BOOST_PP_CHECK_2(res, _) res
# elif CPPCMS_BOOST_PP_CONFIG_FLAGS() & CPPCMS_BOOST_PP_CONFIG_MSVC()
#    define CPPCMS_BOOST_PP_CHECK_D(x, type) CPPCMS_BOOST_PP_CHECK_1(type x)
#    define CPPCMS_BOOST_PP_CHECK_1(chk) CPPCMS_BOOST_PP_CHECK_2(chk)
#    define CPPCMS_BOOST_PP_CHECK_2(chk) CPPCMS_BOOST_PP_CHECK_3((CPPCMS_BOOST_PP_CHECK_RESULT_ ## chk))
#    define CPPCMS_BOOST_PP_CHECK_3(im) CPPCMS_BOOST_PP_CHECK_5(CPPCMS_BOOST_PP_CHECK_4 im)
#    define CPPCMS_BOOST_PP_CHECK_4(res, _) res
#    define CPPCMS_BOOST_PP_CHECK_5(res) res
# else /* DMC */
#    define CPPCMS_BOOST_PP_CHECK_D(x, type) CPPCMS_BOOST_PP_CHECK_OO((type x))
#    define CPPCMS_BOOST_PP_CHECK_OO(par) CPPCMS_BOOST_PP_CHECK_0 ## par
#    define CPPCMS_BOOST_PP_CHECK_0(chk) CPPCMS_BOOST_PP_CHECK_1(CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_CHECK_RESULT_, chk))
#    define CPPCMS_BOOST_PP_CHECK_1(chk) CPPCMS_BOOST_PP_CHECK_2(chk)
#    define CPPCMS_BOOST_PP_CHECK_2(res, _) res
# endif
#
# define CPPCMS_BOOST_PP_CHECK_RESULT_1 1, CPPCMS_BOOST_PP_NIL
#
# endif
