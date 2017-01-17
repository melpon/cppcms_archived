
#ifndef CPPCMS_BOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: compiler.hpp 53189 2009-05-22 20:07:55Z hkaiser $
// $Date: 2009-05-22 16:07:55 -0400 (Fri, 22 May 2009) $
// $Revision: 53189 $

#if !defined(CPPCMS_BOOST_MPL_CFG_COMPILER_DIR)

#   include <cppcms_boost/mpl/aux_/config/dtp.hpp>
#   include <cppcms_boost/mpl/aux_/config/ttp.hpp>
#   include <cppcms_boost/mpl/aux_/config/ctps.hpp>
#   include <cppcms_boost/mpl/aux_/config/msvc.hpp>
#   include <cppcms_boost/mpl/aux_/config/gcc.hpp>
#   include <cppcms_boost/mpl/aux_/config/workaround.hpp>

#   if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
#       define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR msvc60

#   elif CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1300)
#       define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR msvc70

#   elif CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MPL_CFG_GCC, CPPCMS_BOOST_TESTED_AT(0x0304))
#       define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR gcc

#   elif CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x610))
#       if !defined(CPPCMS_BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#           define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR bcc551
#       elif CPPCMS_BOOST_WORKAROUND(__BORLANDC__, >= 0x590)
#           define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR bcc
#       else
#           define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR bcc_pre590
#       endif

#   elif CPPCMS_BOOST_WORKAROUND(__DMC__, CPPCMS_BOOST_TESTED_AT(0x840))
#       define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR dmc

#   elif defined(__MWERKS__)
#       if defined(CPPCMS_BOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#           define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR mwcw
#       else
#           define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR plain
#       endif

#   elif defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#       define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR no_ctps

#   elif defined(CPPCMS_BOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS)
#       define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR no_ttp

#   else
#       define CPPCMS_BOOST_MPL_CFG_COMPILER_DIR plain
#   endif

#endif // BOOST_MPL_CFG_COMPILER_DIR

#endif // BOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED
