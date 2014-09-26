// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef CPPCMS_BOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED
#define CPPCMS_BOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED       
 
#include <cppcms_boost/config.hpp>
#include <cppcms_boost/detail/workaround.hpp>
#include <cppcms_boost/iostreams/detail/bool_trait_def.hpp>

// Must come last.
#include <cppcms_boost/iostreams/detail/config/disable_warnings.hpp>

namespace cppcms_boost { 

# if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, <= 1300) //---------------------------------//

// We avoid dependence on Boost.Range by using a forward declaration.
template<typename Iterator>
class iterator_range;
    
namespace iostreams {

CPPCMS_BOOST_IOSTREAMS_BOOL_TRAIT_DEF(is_iterator_range, cppcms_boost::iterator_range, 1)

} // End namespace iostreams.

# else // # if !BOOST_WORKAROUND(BOOST_MSVC, <= 1300) //-----------------------//

namespace iostreams {    

    template<typename T>
    struct is_iterator_range {
        CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false);
    };

} // End namespace iostreams.

# endif // # if !BOOST_WORKAROUND(BOOST_MSVC, < 1300) //----------------------//

} // End namespace boost.

#include <cppcms_boost/iostreams/detail/config/enable_warnings.hpp>

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED
