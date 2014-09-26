
// Copyright 2005-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  Based on Peter Dimov's proposal
//  http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2005/n1756.pdf
//  issue 6.18. 

#if !defined(CPPCMS_BOOST_FUNCTIONAL_HASH_HASH_HPP)
#define CPPCMS_BOOST_FUNCTIONAL_HASH_HASH_HPP

#include <cppcms_boost/functional/hash/hash_fwd.hpp>
#include <functional>
#include <cppcms_boost/functional/hash/detail/hash_float.hpp>
#include <string>
#include <cppcms_boost/limits.hpp>

#if defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#include <cppcms_boost/type_traits/is_pointer.hpp>
#endif

#if CPPCMS_BOOST_WORKAROUND(__GNUC__, < 3) && !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
#define CPPCMS_BOOST_HASH_CHAR_TRAITS string_char_traits
#else
#define CPPCMS_BOOST_HASH_CHAR_TRAITS char_traits
#endif

namespace cppcms_boost
{
    std::size_t hash_value(bool);
    std::size_t hash_value(char);
    std::size_t hash_value(unsigned char);
    std::size_t hash_value(signed char);
    std::size_t hash_value(short);
    std::size_t hash_value(unsigned short);
    std::size_t hash_value(int);
    std::size_t hash_value(unsigned int);
    std::size_t hash_value(long);
    std::size_t hash_value(unsigned long);

#if !defined(CPPCMS_BOOST_NO_INTRINSIC_WCHAR_T)
    std::size_t hash_value(wchar_t);
#endif
    
#if defined(CPPCMS_BOOST_HAS_LONG_LONG)
    std::size_t hash_value(cppcms_boost::long_long_type);
    std::size_t hash_value(cppcms_boost::ulong_long_type);
#endif

#if !CPPCMS_BOOST_WORKAROUND(__DMC__, <= 0x848)
    template <class T> std::size_t hash_value(T* const&);
#else
    template <class T> std::size_t hash_value(T*);
#endif

#if !defined(CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
    template< class T, unsigned N >
    std::size_t hash_value(const T (&x)[N]);

    template< class T, unsigned N >
    std::size_t hash_value(T (&x)[N]);
#endif

    std::size_t hash_value(float v);
    std::size_t hash_value(double v);
    std::size_t hash_value(long double v);

    template <class Ch, class A>
    std::size_t hash_value(std::basic_string<Ch, std::CPPCMS_BOOST_HASH_CHAR_TRAITS<Ch>, A> const&);

    // Implementation

    namespace hash_detail
    {
        template <class T>
        inline std::size_t hash_value_signed(T val)
        {
             const int size_t_bits = std::numeric_limits<std::size_t>::digits;
             // ceiling(std::numeric_limits<T>::digits / size_t_bits) - 1
             const int length = (std::numeric_limits<T>::digits - 1)
                 / size_t_bits;

             std::size_t seed = 0;
             T positive = val < 0 ? -1 - val : val;

             // Hopefully, this loop can be unrolled.
             for(unsigned int i = length * size_t_bits; i > 0; i -= size_t_bits)
             {
                 seed ^= (std::size_t) (positive >> i) + (seed<<6) + (seed>>2);
             }
             seed ^= (std::size_t) val + (seed<<6) + (seed>>2);

             return seed;
        }

        template <class T>
        inline std::size_t hash_value_unsigned(T val)
        {
             const int size_t_bits = std::numeric_limits<std::size_t>::digits;
             // ceiling(std::numeric_limits<T>::digits / size_t_bits) - 1
             const int length = (std::numeric_limits<T>::digits - 1)
                 / size_t_bits;

             std::size_t seed = 0;

             // Hopefully, this loop can be unrolled.
             for(unsigned int i = length * size_t_bits; i > 0; i -= size_t_bits)
             {
                 seed ^= (std::size_t) (val >> i) + (seed<<6) + (seed>>2);
             }
             seed ^= (std::size_t) val + (seed<<6) + (seed>>2);

             return seed;
        }
    }

    inline std::size_t hash_value(bool v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(char v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(unsigned char v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(signed char v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(short v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(unsigned short v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(int v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(unsigned int v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(long v)
    {
        return static_cast<std::size_t>(v);
    }

    inline std::size_t hash_value(unsigned long v)
    {
        return static_cast<std::size_t>(v);
    }

#if !defined(CPPCMS_BOOST_NO_INTRINSIC_WCHAR_T)
    inline std::size_t hash_value(wchar_t v)
    {
        return static_cast<std::size_t>(v);
    }
#endif

#if defined(CPPCMS_BOOST_HAS_LONG_LONG)
    inline std::size_t hash_value(cppcms_boost::long_long_type v)
    {
        return hash_detail::hash_value_signed(v);
    }

    inline std::size_t hash_value(cppcms_boost::ulong_long_type v)
    {
        return hash_detail::hash_value_unsigned(v);
    }
#endif

    // Implementation by Alberto Barbati and Dave Harris.
#if !CPPCMS_BOOST_WORKAROUND(__DMC__, <= 0x848)
    template <class T> std::size_t hash_value(T* const& v)
#else
    template <class T> std::size_t hash_value(T* v)
#endif
    {
        std::size_t x = static_cast<std::size_t>(
           reinterpret_cast<std::ptrdiff_t>(v));

        return x + (x >> 3);
    }

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
    template <class T>
    inline void hash_combine(std::size_t& seed, T& v)
#else
    template <class T>
    inline void hash_combine(std::size_t& seed, T const& v)
#endif
    {
        cppcms_boost::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    template <class It>
    inline std::size_t hash_range(It first, It last)
    {
        std::size_t seed = 0;

        for(; first != last; ++first)
        {
            hash_combine(seed, *first);
        }

        return seed;
    }

    template <class It>
    inline void hash_range(std::size_t& seed, It first, It last)
    {
        for(; first != last; ++first)
        {
            hash_combine(seed, *first);
        }
    }

#if CPPCMS_BOOST_WORKAROUND(__BORLANDC__, CPPCMS_BOOST_TESTED_AT(0x551))
    template <class T>
    inline std::size_t hash_range(T* first, T* last)
    {
        std::size_t seed = 0;

        for(; first != last; ++first)
        {
            cppcms_boost::hash<T> hasher;
            seed ^= hasher(*first) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }

        return seed;
    }

    template <class T>
    inline void hash_range(std::size_t& seed, T* first, T* last)
    {
        for(; first != last; ++first)
        {
            cppcms_boost::hash<T> hasher;
            seed ^= hasher(*first) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
    }
#endif

#if !defined(CPPCMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
    template< class T, unsigned N >
    inline std::size_t hash_value(const T (&x)[N])
    {
        return hash_range(x, x + N);
    }

    template< class T, unsigned N >
    inline std::size_t hash_value(T (&x)[N])
    {
        return hash_range(x, x + N);
    }
#endif

    template <class Ch, class A>
    inline std::size_t hash_value(std::basic_string<Ch, std::CPPCMS_BOOST_HASH_CHAR_TRAITS<Ch>, A> const& v)
    {
        return hash_range(v.begin(), v.end());
    }

    inline std::size_t hash_value(float v)
    {
        return cppcms_boost::hash_detail::float_hash_value(v);
    }

    inline std::size_t hash_value(double v)
    {
        return cppcms_boost::hash_detail::float_hash_value(v);
    }

    inline std::size_t hash_value(long double v)
    {
        return cppcms_boost::hash_detail::float_hash_value(v);
    }

    //
    // boost::hash
    //
    
    // Define the specializations required by the standard. The general purpose
    // boost::hash is defined later in extensions.hpp if BOOST_HASH_NO_EXTENSIONS
    // is not defined.
    
    // BOOST_HASH_SPECIALIZE - define a specialization for a type which is
    // passed by copy.
    //
    // BOOST_HASH_SPECIALIZE_REF - define a specialization for a type which is
    // passed by copy.
    //
    // These are undefined later.

#if !CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300)
#define CPPCMS_BOOST_HASH_SPECIALIZE(type) \
    template <> struct hash<type> \
         : public std::unary_function<type, std::size_t> \
    { \
        std::size_t operator()(type v) const \
        { \
            return cppcms_boost::hash_value(v); \
        } \
    };

#define CPPCMS_BOOST_HASH_SPECIALIZE_REF(type) \
    template <> struct hash<type> \
         : public std::unary_function<type, std::size_t> \
    { \
        std::size_t operator()(type const& v) const \
        { \
            return cppcms_boost::hash_value(v); \
        } \
    };
#else
#define CPPCMS_BOOST_HASH_SPECIALIZE(type) \
    template <> struct hash<type> \
         : public std::unary_function<type, std::size_t> \
    { \
        std::size_t operator()(type v) const \
        { \
            return cppcms_boost::hash_value(v); \
        } \
    }; \
    \
    template <> struct hash<const type> \
         : public std::unary_function<const type, std::size_t> \
    { \
        std::size_t operator()(const type v) const \
        { \
            return cppcms_boost::hash_value(v); \
        } \
    };

#define CPPCMS_BOOST_HASH_SPECIALIZE_REF(type) \
    template <> struct hash<type> \
         : public std::unary_function<type, std::size_t> \
    { \
        std::size_t operator()(type const& v) const \
        { \
            return cppcms_boost::hash_value(v); \
        } \
    }; \
    \
    template <> struct hash<const type> \
         : public std::unary_function<const type, std::size_t> \
    { \
        std::size_t operator()(type const& v) const \
        { \
            return cppcms_boost::hash_value(v); \
        } \
    };
#endif

    CPPCMS_BOOST_HASH_SPECIALIZE(bool)
    CPPCMS_BOOST_HASH_SPECIALIZE(char)
    CPPCMS_BOOST_HASH_SPECIALIZE(signed char)
    CPPCMS_BOOST_HASH_SPECIALIZE(unsigned char)
#if !defined(CPPCMS_BOOST_NO_INTRINSIC_WCHAR_T)
    CPPCMS_BOOST_HASH_SPECIALIZE(wchar_t)
#endif
    CPPCMS_BOOST_HASH_SPECIALIZE(short)
    CPPCMS_BOOST_HASH_SPECIALIZE(unsigned short)
    CPPCMS_BOOST_HASH_SPECIALIZE(int)
    CPPCMS_BOOST_HASH_SPECIALIZE(unsigned int)
    CPPCMS_BOOST_HASH_SPECIALIZE(long)
    CPPCMS_BOOST_HASH_SPECIALIZE(unsigned long)

    CPPCMS_BOOST_HASH_SPECIALIZE(float)
    CPPCMS_BOOST_HASH_SPECIALIZE(double)
    CPPCMS_BOOST_HASH_SPECIALIZE(long double)

    CPPCMS_BOOST_HASH_SPECIALIZE_REF(std::string)
#if !defined(CPPCMS_BOOST_NO_STD_WSTRING)
    CPPCMS_BOOST_HASH_SPECIALIZE_REF(std::wstring)
#endif

#if defined(CPPCMS_BOOST_HAS_LONG_LONG)
    CPPCMS_BOOST_HASH_SPECIALIZE(cppcms_boost::long_long_type)
    CPPCMS_BOOST_HASH_SPECIALIZE(cppcms_boost::ulong_long_type)
#endif

#undef CPPCMS_BOOST_HASH_SPECIALIZE
#undef CPPCMS_BOOST_HASH_SPECIALIZE_REF

// Specializing boost::hash for pointers.

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

    template <class T>
    struct hash<T*>
        : public std::unary_function<T*, std::size_t>
    {
        std::size_t operator()(T* v) const
        {
#if !CPPCMS_BOOST_WORKAROUND(__SUNPRO_CC, <= 0x590)
            return cppcms_boost::hash_value(v);
#else
            std::size_t x = static_cast<std::size_t>(
                reinterpret_cast<std::ptrdiff_t>(v));

            return x + (x >> 3);
#endif
        }
    };

#else

    // For compilers without partial specialization, we define a
    // boost::hash for all remaining types. But hash_impl is only defined
    // for pointers in 'extensions.hpp' - so when BOOST_HASH_NO_EXTENSIONS
    // is defined there will still be a compile error for types not supported
    // in the standard.

    namespace hash_detail
    {
        template <bool IsPointer>
        struct hash_impl;

        template <>
        struct hash_impl<true>
        {
            template <class T>
            struct inner
                : public std::unary_function<T, std::size_t>
            {
                std::size_t operator()(T val) const
                {
#if !CPPCMS_BOOST_WORKAROUND(__SUNPRO_CC, <= 590)
                    return cppcms_boost::hash_value(val);
#else
                    std::size_t x = static_cast<std::size_t>(
                        reinterpret_cast<std::ptrdiff_t>(val));

                    return x + (x >> 3);
#endif
                }
            };
        };
    }

    template <class T> struct hash
        : public cppcms_boost::hash_detail::hash_impl<cppcms_boost::is_pointer<T>::value>
            ::CPPCMS_BOOST_NESTED_TEMPLATE inner<T>
    {
    };

#endif
}

#undef CPPCMS_BOOST_HASH_CHAR_TRAITS

#endif // BOOST_FUNCTIONAL_HASH_HASH_HPP

// Include this outside of the include guards in case the file is included
// twice - once with BOOST_HASH_NO_EXTENSIONS defined, and then with it
// undefined.

#if !defined(CPPCMS_BOOST_HASH_NO_EXTENSIONS) \
    && !defined(CPPCMS_BOOST_FUNCTIONAL_HASH_EXTENSIONS_HPP)
#include <cppcms_boost/functional/hash/extensions.hpp>
#endif
