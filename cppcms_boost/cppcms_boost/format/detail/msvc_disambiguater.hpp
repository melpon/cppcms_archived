// ----------------------------------------------------------------------------
// msvc_disambiguater.hpp : msvc workarounds. (for put_{head|last} overloads)
//               the trick was described in boost's list  by Aleksey Gurtovoy
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// see http://www.boost.org/libs/format for library home page

// ----------------------------------------------------------------------------

#ifndef CPPCMS_BOOST_MSVC_DISAMBIGUATER_HPP
#define CPPCMS_BOOST_MSVC_DISAMBIGUATER_HPP

#if CPPCMS_BOOST_WORKAROUND( CPPCMS_BOOST_MSVC, <= 1300) || \
    CPPCMS_BOOST_WORKAROUND(__DECCXX_VER, CPPCMS_BOOST_TESTED_AT(60590042))
   // this whole header is specifically for msvc up to 7.0

#include <cppcms_boost/format/group.hpp>
#include <ostream>

namespace cppcms_boost {
namespace io {
namespace detail {

template< class Ch, class Tr, class T >
struct disambiguater
{
   template< typename U >
   static void put_head(CPPCMS_BOOST_IO_STD basic_ostream<Ch, Tr>& os, group1<U> const& x, long)
   {
       os << group_head(x.a1_); 
   }
   static void put_head(CPPCMS_BOOST_IO_STD basic_ostream<Ch, Tr>& os, T const& x, int)
   {
   }
   template< typename U >
   static void put_last(CPPCMS_BOOST_IO_STD basic_ostream<Ch, Tr>& os, group1<U> const& x, long)
   {
       os << group_last(x.a1_); 
   }
   static void put_last(CPPCMS_BOOST_IO_STD basic_ostream<Ch, Tr>& os, T const& x, int)
   {
     os << x;
   }
};

} // namespace detail
} // namespace io
} // namespace boost

#endif // -BOOST_MSVC

#endif // -BOOST_MSVC_DISAMBIGUATER_HPP
