//
//  boost/assert.hpp - BOOST_ASSERT(expr)
//
//  Copyright (c) 2001, 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2007 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//  Note: There are no include guards. This is intentional.
//
//  See http://www.boost.org/libs/utility/assert.html for documentation.
//

#undef CPPCMS_BOOST_ASSERT

#if defined(CPPCMS_BOOST_DISABLE_ASSERTS)

# define CPPCMS_BOOST_ASSERT(expr) ((void)0)

#elif defined(CPPCMS_BOOST_ENABLE_ASSERT_HANDLER)

#include <cppcms_boost/current_function.hpp>

namespace cppcms_boost
{

void assertion_failed(char const * expr, char const * function, char const * file, long line); // user defined

} // namespace boost

#define CPPCMS_BOOST_ASSERT(expr) ((expr)? ((void)0): ::cppcms_boost::assertion_failed(#expr, CPPCMS_BOOST_CURRENT_FUNCTION, __FILE__, __LINE__))

#else
# include <assert.h> // .h to support old libraries w/o <cassert> - effect is the same
# define CPPCMS_BOOST_ASSERT(expr) assert(expr)
#endif

#undef CPPCMS_BOOST_VERIFY

#if defined(CPPCMS_BOOST_DISABLE_ASSERTS) || ( !defined(CPPCMS_BOOST_ENABLE_ASSERT_HANDLER) && defined(NDEBUG) )

# define CPPCMS_BOOST_VERIFY(expr) ((void)(expr))

#else

# define CPPCMS_BOOST_VERIFY(expr) CPPCMS_BOOST_ASSERT(expr)

#endif
