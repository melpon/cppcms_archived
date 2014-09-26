// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef CPPCMS_BOOST_RANGE_RBEGIN_HPP
#define CPPCMS_BOOST_RANGE_RBEGIN_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <cppcms_boost/range/end.hpp>
#include <cppcms_boost/range/reverse_iterator.hpp>

namespace cppcms_boost
{

#ifdef CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING

template< class C >
inline CPPCMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
rbegin( C& c )
{
    return CPPCMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type( cppcms_boost::end( c ) );
}

#else

template< class C >
inline CPPCMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
rbegin( C& c )
{
    typedef CPPCMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
        iter_type;
    return iter_type( cppcms_boost::end( c ) );
}

template< class C >
inline CPPCMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<const C>::type
rbegin( const C& c )
{
    typedef CPPCMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<const C>::type
        iter_type;
    return iter_type( cppcms_boost::end( c ) );
}

#endif // BOOST_NO_FUNCTION_TEMPLATE_ORDERING

template< class T >
inline CPPCMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<const T>::type
const_rbegin( const T& r )
{
    return cppcms_boost::rbegin( r );
}

} // namespace 'boost'

#endif

