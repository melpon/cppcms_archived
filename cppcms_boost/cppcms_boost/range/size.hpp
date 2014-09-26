// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef CPPCMS_BOOST_RANGE_SIZE_HPP
#define CPPCMS_BOOST_RANGE_SIZE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <cppcms_boost/range/begin.hpp>
#include <cppcms_boost/range/end.hpp>
#include <cppcms_boost/range/difference_type.hpp>
#include <cppcms_boost/assert.hpp>

namespace cppcms_boost 
{

    template< class T >
    inline CPPCMS_BOOST_DEDUCED_TYPENAME range_difference<T>::type size( const T& r )
    {
        CPPCMS_BOOST_ASSERT( (cppcms_boost::end( r ) - cppcms_boost::begin( r )) >= 0 &&
                      "reachability invariant broken!" );
        return cppcms_boost::end( r ) - cppcms_boost::begin( r );
    }

} // namespace 'boost'

#endif
