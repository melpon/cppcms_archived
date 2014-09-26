
// Copyright (C) 2003-2004 Jeremy B. Maitin-Shepard.
// Copyright (C) 2005-2009 Daniel James
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPPCMS_BOOST_UNORDERED_DETAIL_UTIL_HPP_INCLUDED
#define CPPCMS_BOOST_UNORDERED_DETAIL_UTIL_HPP_INCLUDED

#include <cstddef>
#include <utility>
#include <algorithm>
#include <cppcms_boost/limits.hpp>
#include <cppcms_boost/iterator/iterator_categories.hpp>
#include <cppcms_boost/preprocessor/seq/size.hpp>
#include <cppcms_boost/preprocessor/seq/enum.hpp>
#include <cppcms_boost/unordered/detail/fwd.hpp>

namespace cppcms_boost { namespace unordered_detail {

    ////////////////////////////////////////////////////////////////////////////
    // convert double to std::size_t

    inline std::size_t double_to_size_t(double f)
    {
        return f >= static_cast<double>(
            (std::numeric_limits<std::size_t>::max)()) ?
            (std::numeric_limits<std::size_t>::max)() :
            static_cast<std::size_t>(f);
    }

    ////////////////////////////////////////////////////////////////////////////
    // primes

#define CPPCMS_BOOST_UNORDERED_PRIMES \
    (5ul)(11ul)(17ul)(29ul)(37ul)(53ul)(67ul)(79ul) \
    (97ul)(131ul)(193ul)(257ul)(389ul)(521ul)(769ul) \
    (1031ul)(1543ul)(2053ul)(3079ul)(6151ul)(12289ul)(24593ul) \
    (49157ul)(98317ul)(196613ul)(393241ul)(786433ul) \
    (1572869ul)(3145739ul)(6291469ul)(12582917ul)(25165843ul) \
    (50331653ul)(100663319ul)(201326611ul)(402653189ul)(805306457ul) \
    (1610612741ul)(3221225473ul)(4294967291ul)

    template<class T> struct prime_list_template
    {
        static std::size_t const value[];

#if !defined(SUNPRO_CC)
        static std::ptrdiff_t const length;
#else
        static std::ptrdiff_t const length
            = CPPCMS_BOOST_PP_SEQ_SIZE(CPPCMS_BOOST_UNORDERED_PRIMES);
#endif
    };

    template<class T>
    std::size_t const prime_list_template<T>::value[] = {
        CPPCMS_BOOST_PP_SEQ_ENUM(CPPCMS_BOOST_UNORDERED_PRIMES)
    };

#if !defined(SUNPRO_CC)
    template<class T>
    std::ptrdiff_t const prime_list_template<T>::length
        = CPPCMS_BOOST_PP_SEQ_SIZE(CPPCMS_BOOST_UNORDERED_PRIMES);
#endif

#undef CPPCMS_BOOST_UNORDERED_PRIMES

    typedef prime_list_template<std::size_t> prime_list;

    // no throw
    inline std::size_t next_prime(std::size_t num) {
        std::size_t const* const prime_list_begin = prime_list::value;
        std::size_t const* const prime_list_end = prime_list_begin +
            prime_list::length;
        std::size_t const* bound =
            std::lower_bound(prime_list_begin, prime_list_end, num);
        if(bound == prime_list_end)
            bound--;
        return *bound;
    }

    // no throw
    inline std::size_t prev_prime(std::size_t num) {
        std::size_t const* const prime_list_begin = prime_list::value;
        std::size_t const* const prime_list_end = prime_list_begin +
            prime_list::length;
        std::size_t const* bound =
            std::upper_bound(prime_list_begin,prime_list_end, num);
        if(bound != prime_list_begin)
            bound--;
        return *bound;
    }

    ////////////////////////////////////////////////////////////////////////////
    // pair_cast - because some libraries don't have the full pair constructors.

    template <class Dst1, class Dst2, class Src1, class Src2>
    inline std::pair<Dst1, Dst2> pair_cast(std::pair<Src1, Src2> const& x)
    {
        return std::pair<Dst1, Dst2>(Dst1(x.first), Dst2(x.second));
    }

    ////////////////////////////////////////////////////////////////////////////
    // insert_size/initial_size

#if !defined(CPPCMS_BOOST_NO_STD_DISTANCE)
    using ::std::distance;
#else
    template <class ForwardIterator>
    inline std::size_t distance(ForwardIterator i, ForwardIterator j) {
        std::size_t x;
        std::distance(i, j, x);
        return x;
    }
#endif

    template <class I>
    inline std::size_t insert_size(I i, I j, cppcms_boost::forward_traversal_tag)
    {
        return std::distance(i, j);
    }

    template <class I>
    inline std::size_t insert_size(I, I, cppcms_boost::incrementable_traversal_tag)
    {
        return 1;
    }

    template <class I>
    inline std::size_t insert_size(I i, I j)
    {
        CPPCMS_BOOST_DEDUCED_TYPENAME cppcms_boost::iterator_traversal<I>::type
            iterator_traversal_tag;
        return insert_size(i, j, iterator_traversal_tag);
    }
    
    template <class I>
    inline std::size_t initial_size(I i, I j,
        std::size_t num_buckets = cppcms_boost::unordered_detail::default_bucket_count)
    {
        return (std::max)(static_cast<std::size_t>(insert_size(i, j)) + 1,
            num_buckets);
    }

    ////////////////////////////////////////////////////////////////////////////
    // Node Constructors

#if defined(CPPCMS_BOOST_UNORDERED_STD_FORWARD)

    template <class T, class... Args>
    inline void construct_impl(T*, void* address, Args&&... args)
    {
        new(address) T(std::forward<Args>(args)...);
    }

#if defined(CPPCMS_BOOST_UNORDERED_CPP0X_PAIR)
    template <class First, class Second, class Key, class Arg0, class... Args>
    inline void construct_impl(std::pair<First, Second>*, void* address,
        Key&& k, Arg0&& arg0, Args&&... args)
    )
    {
        new(address) std::pair<First, Second>(k,
            Second(arg0, std::forward<Args>(args)...);
    }
#endif

#else

#define CPPCMS_BOOST_UNORDERED_CONSTRUCT_IMPL(z, num_params, _)                       \
    template <                                                                 \
        class T,                                                               \
        CPPCMS_BOOST_UNORDERED_TEMPLATE_ARGS(z, num_params)                           \
    >                                                                          \
    inline void construct_impl(                                                \
        T*, void* address,                                                     \
        CPPCMS_BOOST_UNORDERED_FUNCTION_PARAMS(z, num_params)                         \
    )                                                                          \
    {                                                                          \
        new(address) T(                                                        \
            CPPCMS_BOOST_UNORDERED_CALL_PARAMS(z, num_params));                       \
    }                                                                          \
                                                                               \
    template <class First, class Second, class Key,                            \
        CPPCMS_BOOST_UNORDERED_TEMPLATE_ARGS(z, num_params)                           \
    >                                                                          \
    inline void construct_impl(                                                \
        std::pair<First, Second>*, void* address,                              \
        Key const& k, CPPCMS_BOOST_UNORDERED_FUNCTION_PARAMS(z, num_params))          \
    {                                                                          \
        new(address) std::pair<First, Second>(k,                               \
            Second(CPPCMS_BOOST_UNORDERED_CALL_PARAMS(z, num_params)));               \
    }

    CPPCMS_BOOST_PP_REPEAT_FROM_TO(1, CPPCMS_BOOST_UNORDERED_EMPLACE_LIMIT,
        CPPCMS_BOOST_UNORDERED_CONSTRUCT_IMPL, _)

#undef CPPCMS_BOOST_UNORDERED_CONSTRUCT_IMPL
#endif

    // hash_node_constructor
    //
    // Used to construct nodes in an exception safe manner.

    template <class Alloc, class Grouped>
    class hash_node_constructor
    {
        typedef hash_buckets<Alloc, Grouped> buckets;
        typedef CPPCMS_BOOST_DEDUCED_TYPENAME buckets::node node;
        typedef CPPCMS_BOOST_DEDUCED_TYPENAME buckets::real_node_ptr real_node_ptr;
        typedef CPPCMS_BOOST_DEDUCED_TYPENAME buckets::value_type value_type;

        buckets& buckets_;
        real_node_ptr node_;
        bool node_constructed_;
        bool value_constructed_;

    public:

        hash_node_constructor(buckets& m) :
            buckets_(m),
            node_(),
            node_constructed_(false),
            value_constructed_(false)
        {
        }

        ~hash_node_constructor();
        void construct_preamble();

#if defined(CPPCMS_BOOST_UNORDERED_STD_FORWARD)
        template <class... Args>
        void construct(Args&&... args)
        {
            construct_preamble();
            construct_impl((value_type*) 0, node_->address(),
                std::forward<Args>(args)...);
            value_constructed_ = true;
        }
#else

#define CPPCMS_BOOST_UNORDERED_CONSTRUCT(z, num_params, _)                            \
        template <                                                             \
            CPPCMS_BOOST_UNORDERED_TEMPLATE_ARGS(z, num_params)                       \
        >                                                                      \
        void construct(                                                        \
            CPPCMS_BOOST_UNORDERED_FUNCTION_PARAMS(z, num_params)                     \
        )                                                                      \
        {                                                                      \
            construct_preamble();                                              \
            construct_impl(                                                    \
                (value_type*) 0, node_->address(),                             \
                CPPCMS_BOOST_UNORDERED_CALL_PARAMS(z, num_params)                     \
            );                                                                 \
            value_constructed_ = true;                                         \
        }

        CPPCMS_BOOST_PP_REPEAT_FROM_TO(1, CPPCMS_BOOST_UNORDERED_EMPLACE_LIMIT,
            CPPCMS_BOOST_UNORDERED_CONSTRUCT, _)

#undef CPPCMS_BOOST_UNORDERED_CONSTRUCT

#endif
        template <class K, class M>
        void construct_pair(K const& k, M*)
        {
            construct_preamble();
            new(node_->address()) value_type(k, M());                    
            value_constructed_ = true;
        }

        value_type& value() const
        {
            CPPCMS_BOOST_ASSERT(node_);
            return node_->value();
        }

        // no throw
        CPPCMS_BOOST_DEDUCED_TYPENAME buckets::node_ptr release()
        {
            real_node_ptr p = node_;
            node_ = real_node_ptr();
            // node_ptr cast
            return buckets_.bucket_alloc().address(*p);
        }

    private:
        hash_node_constructor(hash_node_constructor const&);
        hash_node_constructor& operator=(hash_node_constructor const&);
    };
    
    // hash_node_constructor

    template <class Alloc, class Grouped>
    inline hash_node_constructor<Alloc, Grouped>::~hash_node_constructor()
    {
        if (node_) {
            if (value_constructed_) {
#if CPPCMS_BOOST_WORKAROUND(__CODEGEARC__, CPPCMS_BOOST_TESTED_AT(0x0613))
                struct dummy { hash_node<Alloc, Grouped> x; };
#endif
                cppcms_boost::unordered_detail::destroy(node_->value_ptr());
            }

            if (node_constructed_)
                buckets_.node_alloc().destroy(node_);

            buckets_.node_alloc().deallocate(node_, 1);
        }
    }

    template <class Alloc, class Grouped>
    inline void hash_node_constructor<Alloc, Grouped>::construct_preamble()
    {
        if(!node_) {
            node_constructed_ = false;
            value_constructed_ = false;

            node_ = buckets_.node_alloc().allocate(1);
            buckets_.node_alloc().construct(node_, node());
            node_constructed_ = true;
        }
        else {
            CPPCMS_BOOST_ASSERT(node_constructed_ && value_constructed_);
            cppcms_boost::unordered_detail::destroy(node_->value_ptr());
            value_constructed_ = false;
        }
    }
}}

#endif
