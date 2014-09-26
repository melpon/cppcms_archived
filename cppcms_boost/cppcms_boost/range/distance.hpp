// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef CPPCMS_BOOST_RANGE_DISTANCE_HPP
#define CPPCMS_BOOST_RANGE_DISTANCE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <cppcms_boost/range/begin.hpp>
#include <cppcms_boost/range/end.hpp>
#include <cppcms_boost/range/difference_type.hpp>

namespace cppcms_boost 
{

    template< class T >
    inline CPPCMS_BOOST_DEDUCED_TYPENAME range_difference<T>::type 
    distance( const T& r )
    {
        return std::distance( cppcms_boost::begin( r ), cppcms_boost::end( r ) );
    }

} // namespace 'boost'

#endif
