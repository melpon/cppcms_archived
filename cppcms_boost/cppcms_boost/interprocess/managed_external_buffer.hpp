//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CPPCMS_BOOST_INTERPROCESS_MANAGED_EXTERNAL_BUFFER_HPP
#define CPPCMS_BOOST_INTERPROCESS_MANAGED_EXTERNAL_BUFFER_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <cppcms_boost/interprocess/detail/config_begin.hpp>
#include <cppcms_boost/interprocess/detail/workaround.hpp>
#include <cppcms_boost/interprocess/creation_tags.hpp>
#include <cppcms_boost/interprocess/detail/managed_memory_impl.hpp>
#include <cppcms_boost/interprocess/detail/move.hpp>
#include <cassert>

//!\file
//!Describes a named user memory allocation user class. 

namespace cppcms_boost {
namespace interprocess {

//!A basic user memory named object creation class. Inherits all 
//!basic functionality from 
//!basic_managed_memory_impl<CharType, AllocationAlgorithm, IndexType>*/
template
      <
         class CharType, 
         class AllocationAlgorithm, 
         template<class IndexConfig> class IndexType
      >
class basic_managed_external_buffer 
   : public detail::basic_managed_memory_impl <CharType, AllocationAlgorithm, IndexType>
{
   /// @cond
   typedef detail::basic_managed_memory_impl 
      <CharType, AllocationAlgorithm, IndexType>    base_t;
   CPPCMS_BOOST_INTERPROCESS_MOVABLE_BUT_NOT_COPYABLE(basic_managed_external_buffer)
   /// @endcond
   
   public:

   //!Default constructor. Does nothing.
   //!Useful in combination with move semantics
   basic_managed_external_buffer()
   {}

   //!Creates and places the segment manager. This can throw
   basic_managed_external_buffer
      (create_only_t, void *addr, std::size_t size)
   {
      //Check if alignment is correct
      assert((0 == (((std::size_t)addr) & (AllocationAlgorithm::Alignment - std::size_t(1u)))));
      if(!base_t::create_impl(addr, size)){
         throw interprocess_exception();
      }
   }

   //!Creates and places the segment manager. This can throw
   basic_managed_external_buffer
      (open_only_t, void *addr, std::size_t size)
   {
      //Check if alignment is correct
      assert((0 == (((std::size_t)addr) & (AllocationAlgorithm::Alignment - std::size_t(1u)))));
      if(!base_t::open_impl(addr, size)){
         throw interprocess_exception();
      }
   }

   //!Moves the ownership of "moved"'s managed memory to *this. Does not throw
   basic_managed_external_buffer(CPPCMS_BOOST_INTERPROCESS_RV_REF(basic_managed_external_buffer) moved)
   {
      this->swap(moved);
   }

   //!Moves the ownership of "moved"'s managed memory to *this. Does not throw
   basic_managed_external_buffer &operator=(CPPCMS_BOOST_INTERPROCESS_RV_REF(basic_managed_external_buffer) moved)
   {
      basic_managed_external_buffer tmp(cppcms_boost::interprocess::move(moved));
      this->swap(tmp);
      return *this;
   }

   void grow(std::size_t extra_bytes)
   {  base_t::grow(extra_bytes);   }

   //!Swaps the ownership of the managed heap memories managed by *this and other.
   //!Never throws.
   void swap(basic_managed_external_buffer &other)
   {  base_t::swap(other); }
};

}  //namespace interprocess {
}  //namespace boost {

#include <cppcms_boost/interprocess/detail/config_end.hpp>

#endif   //BOOST_INTERPROCESS_MANAGED_EXTERNAL_BUFFER_HPP

