// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef CPPCMS_BOOST_RANGE_DETAIL_BEGIN_HPP
#define CPPCMS_BOOST_RANGE_DETAIL_BEGIN_HPP

#include <cppcms_boost/config.hpp> // BOOST_MSVC
#include <cppcms_boost/detail/workaround.hpp>
#include <cppcms_boost/range/iterator.hpp>
#include <cppcms_boost/range/detail/common.hpp>
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1310)
# include <cppcms_boost/range/value_type.hpp>
#endif

namespace cppcms_boost 
{
    
    namespace range_detail
    {
        template< typename T >
        struct range_begin;

        //////////////////////////////////////////////////////////////////////
        // default
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_begin<std_container_>
        {
            template< typename C >
            static CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type fun( C& c )
            {
                return c.begin();
            };
        };
                    
        //////////////////////////////////////////////////////////////////////
        // pair
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_begin<std_pair_>
        {
            template< typename P >
            static CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<P>::type fun( const P& p )
            {
                return p.first;
            }
        };
 
        //////////////////////////////////////////////////////////////////////
        // array
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_begin<array_>
        {
        #if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1310)
            template< typename T, std::size_t sz >
            static T* fun( T CPPCMS_BOOST_RANGE_ARRAY_REF()[sz] )
            {
                return cppcms_boost_range_array;
            }
        #else
            template<typename T>
            static CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_value<T>::type* fun(T& t)
            {
                return t;
            }
        #endif
        };

    } // namespace 'range_detail'
    
    template< typename C >
    inline CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type 
    begin( C& c )
    {
        return range_detail::range_begin< CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_detail::range<C>::type >::fun( c );
    }
    
} // namespace 'boost'


#endif
