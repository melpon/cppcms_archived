// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef CPPCMS_BOOST_RANGE_DETAIL_END_HPP
#define CPPCMS_BOOST_RANGE_DETAIL_END_HPP

#include <cppcms_boost/config.hpp> // BOOST_MSVC
#include <cppcms_boost/detail/workaround.hpp>

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
# include <cppcms_boost/range/detail/vc6/end.hpp>
#else
# include <cppcms_boost/range/detail/implementation_help.hpp>
# include <cppcms_boost/range/iterator.hpp>
# include <cppcms_boost/range/detail/common.hpp>
# if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1310)
#  include <cppcms_boost/range/detail/remove_extent.hpp>
# endif

namespace cppcms_boost 
{
    namespace range_detail
    {
        template< typename T >
        struct range_end;

        //////////////////////////////////////////////////////////////////////
        // default
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_end<std_container_>
        {
            template< typename C >
            static CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type 
            fun( C& c )
            {
                return c.end();
            };
        };
                    
        //////////////////////////////////////////////////////////////////////
        // pair
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_end<std_pair_>
        {
            template< typename P >
            static CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<P>::type 
            fun( const P& p )
            {
                return p.second;
            }
        };
 
        //////////////////////////////////////////////////////////////////////
        // array
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_end<array_>  
        {
        #if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1310)
            template< typename T, std::size_t sz >
            static T* fun( T CPPCMS_BOOST_RANGE_ARRAY_REF()[sz] )
            {
                return cppcms_boost::range_detail::array_end( cppcms_boost_range_array );
            }
        #else
            template<typename T>
            static CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME remove_extent<T>::type* fun(T& t)
            {
                return t + remove_extent<T>::size;
            }
        #endif
        };
        
    } // namespace 'range_detail'
    
    template< typename C >
    inline CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type 
    end( C& c )
    {
        return range_detail::range_end< CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME range_detail::range<C>::type >::fun( c );
    }
    
} // namespace 'boost'

# endif // VC6
#endif
