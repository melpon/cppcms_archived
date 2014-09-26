// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef CPPCMS_BOOST_RANGE_REVERSE_ITERATOR_HPP
#define CPPCMS_BOOST_RANGE_REVERSE_ITERATOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <cppcms_boost/range/config.hpp>
#include <cppcms_boost/range/iterator.hpp>
#include <cppcms_boost/iterator/reverse_iterator.hpp>


namespace cppcms_boost
{
    //////////////////////////////////////////////////////////////////////////
    // default
    //////////////////////////////////////////////////////////////////////////
    
    template< typename C >
    struct range_reverse_iterator
    {
        typedef reverse_iterator< 
            CPPCMS_BOOST_DEDUCED_TYPENAME range_iterator<C>::type > type;
    };
    

} // namespace boost


#endif
