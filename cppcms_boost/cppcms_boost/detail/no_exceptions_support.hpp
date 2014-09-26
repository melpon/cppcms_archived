#ifndef CPPCMS_BOOST_DETAIL_NO_EXCEPTIONS_SUPPORT_HPP_
#define CPPCMS_BOOST_DETAIL_NO_EXCEPTIONS_SUPPORT_HPP_

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

//----------------------------------------------------------------------
// (C) Copyright 2004 Pavel Vozenilek.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//
// This file contains helper macros used when exception support may be
// disabled (as indicated by macro BOOST_NO_EXCEPTIONS).
//
// Before picking up these macros you may consider using RAII techniques
// to deal with exceptions - their syntax can be always the same with 
// or without exception support enabled.
//

/* Example of use:

void foo() {
  BOOST_TRY {
    ...
  } BOOST_CATCH(const std::bad_alloc&) {
      ...
      BOOST_RETHROW
  } BOOST_CATCH(const std::exception& e) {
      ...
  }
  BOOST_CATCH_END
}

With exception support enabled it will expand into:

void foo() {
  { try {
    ...
  } catch (const std::bad_alloc&) {
      ...
      throw;
  } catch (const std::exception& e) {
      ...
  }
  }
}

With exception support disabled it will expand into:

void foo() {
  { if(true) {
    ...
  } else if (false) {
      ...
  } else if (false)  {
      ...
  }
  }
}
*/
//----------------------------------------------------------------------

#include <cppcms_boost/config.hpp>
#include <cppcms_boost/detail/workaround.hpp>

#if !(defined CPPCMS_BOOST_NO_EXCEPTIONS)
#    define CPPCMS_BOOST_TRY { try
#    define CPPCMS_BOOST_CATCH(x) catch(x)
#    define CPPCMS_BOOST_RETHROW throw;
#    define CPPCMS_BOOST_CATCH_END }
#else
#    if CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x564))
#        define CPPCMS_BOOST_TRY { if ("")
#        define CPPCMS_BOOST_CATCH(x) else if (!"")
#    else
#        define CPPCMS_BOOST_TRY { if (true)
#        define CPPCMS_BOOST_CATCH(x) else if (false)
#    endif
#    define CPPCMS_BOOST_RETHROW
#    define CPPCMS_BOOST_CATCH_END }
#endif


#endif 
