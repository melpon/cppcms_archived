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
# ifndef CPPCMS_BOOST_PREPROCESSOR_SLOT_SLOT_HPP
# define CPPCMS_BOOST_PREPROCESSOR_SLOT_SLOT_HPP
#
# include <cppcms_boost/preprocessor/cat.hpp>
# include <cppcms_boost/preprocessor/slot/detail/def.hpp>
#
# /* BOOST_PP_ASSIGN_SLOT */
#
# define CPPCMS_BOOST_PP_ASSIGN_SLOT(i) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_ASSIGN_SLOT_, i)
#
# define CPPCMS_BOOST_PP_ASSIGN_SLOT_1 <cppcms_boost/preprocessor/slot/detail/slot1.hpp>
# define CPPCMS_BOOST_PP_ASSIGN_SLOT_2 <cppcms_boost/preprocessor/slot/detail/slot2.hpp>
# define CPPCMS_BOOST_PP_ASSIGN_SLOT_3 <cppcms_boost/preprocessor/slot/detail/slot3.hpp>
# define CPPCMS_BOOST_PP_ASSIGN_SLOT_4 <cppcms_boost/preprocessor/slot/detail/slot4.hpp>
# define CPPCMS_BOOST_PP_ASSIGN_SLOT_5 <cppcms_boost/preprocessor/slot/detail/slot5.hpp>
#
# /* BOOST_PP_SLOT */
#
# define CPPCMS_BOOST_PP_SLOT(i) CPPCMS_BOOST_PP_CAT(CPPCMS_BOOST_PP_SLOT_, i)()
#
# endif
