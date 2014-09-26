
// Copyright 2005-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CPPCMS_BOOST_FUNCTIONAL_HASH_DETAIL_HASH_FLOAT_HEADER)
#define CPPCMS_BOOST_FUNCTIONAL_HASH_DETAIL_HASH_FLOAT_HEADER

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <cppcms_boost/config.hpp>
#include <cppcms_boost/functional/hash/detail/float_functions.hpp>
#include <cppcms_boost/functional/hash/detail/limits.hpp>
#include <cppcms_boost/integer/static_log2.hpp>
#include <cppcms_boost/cstdint.hpp>
#include <cppcms_boost/assert.hpp>

// Include hash implementation for the current platform.

// Cygwn
#if defined(__CYGWIN__)
#  if defined(__i386__) || defined(_M_IX86)
#    include <cppcms_boost/functional/hash/detail/hash_float_x86.hpp>
#  else
#    include <cppcms_boost/functional/hash/detail/hash_float_generic.hpp>
#  endif
#else
#  include <cppcms_boost/functional/hash/detail/hash_float_generic.hpp>
#endif

// Can we use fpclassify?

// STLport
#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)
#define CPPCMS_BOOST_HASH_USE_FPCLASSIFY 0

// GNU libstdc++ 3
#elif defined(__GLIBCPP__) || defined(__GLIBCXX__)
#  if (defined(__USE_ISOC99) || defined(_GLIBCXX_USE_C99_MATH)) && \
      !(defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__))
#    define CPPCMS_BOOST_HASH_USE_FPCLASSIFY 1
#  else
#    define CPPCMS_BOOST_HASH_USE_FPCLASSIFY 0
#  endif

// Everything else
#else
#  define CPPCMS_BOOST_HASH_USE_FPCLASSIFY 0
#endif

#if CPPCMS_BOOST_HASH_USE_FPCLASSIFY

#include <cppcms_boost/config/no_tr1/cmath.hpp>

namespace cppcms_boost
{
    namespace hash_detail
    {
        template <class T>
        inline std::size_t float_hash_value(T v)
        {
            using namespace std;
            switch (fpclassify(v)) {
            case FP_ZERO:
                return 0;
            case FP_INFINITE:
                return (std::size_t)(v > 0 ? -1 : -2);
            case FP_NAN:
                return (std::size_t)(-3);
            case FP_NORMAL:
            case FP_SUBNORMAL:
                return float_hash_impl(v);
            default:
                CPPCMS_BOOST_ASSERT(0);
                return 0;
            }
        }
    }
}

#else // !BOOST_HASH_USE_FPCLASSIFY

namespace cppcms_boost
{
    namespace hash_detail
    {
        template <class T>
        inline std::size_t float_hash_value(T v)
        {
            return v == 0 ? 0 : float_hash_impl(v);
        }
    }
}

#endif // BOOST_HASH_USE_FPCLASSIFY

#undef CPPCMS_BOOST_HASH_USE_FPCLASSIFY

#endif
