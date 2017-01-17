// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef CPPCMS_BOOST_RANGE_ITERATOR_HPP
#define CPPCMS_BOOST_RANGE_ITERATOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <cppcms_boost/range/config.hpp>
#include <cppcms_boost/range/mutable_iterator.hpp>
#include <cppcms_boost/range/const_iterator.hpp>
#include <cppcms_boost/type_traits/is_const.hpp>
#include <cppcms_boost/type_traits/remove_const.hpp>
#include <cppcms_boost/mpl/eval_if.hpp>

namespace cppcms_boost
{

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1310)  

    namespace range_detail_vc7_1  
    {  
       template< typename C, typename Sig = void(C) >  
       struct range_iterator  
       {  
           typedef CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME   
               mpl::eval_if_c< is_const<C>::value,   
                               range_const_iterator< typename remove_const<C>::type >,  
                               range_mutable_iterator<C> >::type type;  
       };  
    
       template< typename C, typename T >  
       struct range_iterator< C, void(T[]) >  
       {  
           typedef T* type;  
       };       
    }  
    
#endif  

    template< typename C >
    struct range_iterator
    {
#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, == 1310)
  
        typedef CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME  
               range_detail_vc7_1::range_iterator<C>::type type;  
           
#else  

        typedef CPPCMS_BOOST_RANGE_DEDUCED_TYPENAME 
            mpl::eval_if_c< is_const<C>::value, 
                            range_const_iterator< typename remove_const<C>::type >,
                            range_mutable_iterator<C> >::type type;
        
#endif         
    };
    
} // namespace boost

//#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif
