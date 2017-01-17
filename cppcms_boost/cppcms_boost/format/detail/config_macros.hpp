// -*- C++ -*-
// ----------------------------------------------------------------------------
// config_macros.hpp : configuration macros for the format library
// only BOOST_IO_STD is absolutely needed (it should be 'std::' in general)
// others are compiler-specific workaround macros used in #ifdef switches
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// see http://www.boost.org/libs/format for library home page


// ----------------------------------------------------------------------------

#ifndef CPPCMS_BOOST_FORMAT_CONFIG_MACROS_HPP
#define CPPCMS_BOOST_FORMAT_CONFIG_MACROS_HPP

#include <cppcms_boost/config.hpp>
#include <cppcms_boost/detail/workaround.hpp>

// make sure our local macros wont override something :
#if defined(CPPCMS_BOOST_NO_LOCALE_ISDIGIT) || defined(CPPCMS_BOOST_OVERLOAD_FOR_NON_CONST) \
  || defined(CPPCMS_BOOST_IO_STD) || defined( CPPCMS_BOOST_IO_NEEDS_USING_DECLARATION ) \
    || defined(CPPCMS_BOOST_NO_TEMPLATE_STD_STREAM) \
    || defined(CPPCMS_BOOST_FORMAT_STREAMBUF_DEFINED) || defined(CPPCMS_BOOST_FORMAT_OSTREAM_DEFINED)
#error "boost::format uses a local macro that is already defined."
#endif

// specific workarounds. each header can define BOOS_IO_STD if it 
// needs. (e.g. because of IO_NEEDS_USING_DECLARATION)
#include <cppcms_boost/format/detail/workarounds_gcc-2_95.hpp>
#include <cppcms_boost/format/detail/workarounds_stlport.hpp>

#ifndef CPPCMS_BOOST_IO_STD
#  define CPPCMS_BOOST_IO_STD ::std::
#endif

#if defined(CPPCMS_BOOST_NO_STD_LOCALE) || \
 ( CPPCMS_BOOST_WORKAROUND(__BORLANDC__, <= 0x564) \
   || CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT( 0x570 ) )  )
// some future __BORLANDC__ >0x564  versions might not need this
// 0x570 is Borland's kylix branch
#define CPPCMS_BOOST_NO_LOCALE_ISDIGIT
#endif

#if  CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x570) ) || CPPCMS_BOOST_WORKAROUND( CPPCMS_BOOST_MSVC, CPPCMS_BOOST_TESTED_AT(1300))
#define CPPCMS_BOOST_NO_OVERLOAD_FOR_NON_CONST
#endif

// gcc-2.95's native stringstream is not usable
#if CPPCMS_BOOST_WORKAROUND(__GNUC__, < 3) && !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
#define CPPCMS_BOOST_FORMAT_IGNORE_STRINGSTREAM  
#endif


// **** Workaround for io streams, stlport and msvc.
#ifdef CPPCMS_BOOST_IO_NEEDS_USING_DECLARATION
namespace cppcms_boost {
  using std::char_traits;
  using std::basic_ostream;
  namespace io {
    using std::basic_ostream;
    namespace detail {
      using std::basic_ios;
      using std::basic_ostream;
    }
  }
#if ! defined(CPPCMS_BOOST_NO_STD_LOCALE)
    using std::locale;
    namespace io {
        using std::locale;
        namespace detail {
            using std::locale;
        }
    }
#endif // locale
}
  // -end N.S. boost
#endif // needs_using_declaration


// ***  hide std::locale if it doesnt exist. 
// this typedef is either std::locale or int, avoids placing ifdefs everywhere
namespace cppcms_boost { namespace io { namespace detail {
#if ! defined(CPPCMS_BOOST_NO_STD_LOCALE)
    typedef CPPCMS_BOOST_IO_STD locale locale_t;
#else 
    typedef int          locale_t;
#endif
} } }


// ----------------------------------------------------------------------------

#endif // BOOST_FORMAT_MACROS_DEFAULT_HPP
