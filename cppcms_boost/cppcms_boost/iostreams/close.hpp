// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef CPPCMS_BOOST_IOSTREAMS_CLOSE_HPP_INCLUDED
#define CPPCMS_BOOST_IOSTREAMS_CLOSE_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <cppcms_boost/config.hpp>  // DEDUCED_TYPENAME, MSVC.
#include <cppcms_boost/detail/workaround.hpp>
#include <cppcms_boost/iostreams/categories.hpp>
#include <cppcms_boost/iostreams/flush.hpp>
#include <cppcms_boost/iostreams/detail/adapter/non_blocking_adapter.hpp>
#include <cppcms_boost/iostreams/detail/ios.hpp> // BOOST_IOS
#include <cppcms_boost/iostreams/detail/select.hpp>
#include <cppcms_boost/iostreams/detail/wrap_unwrap.hpp>
#include <cppcms_boost/iostreams/operations_fwd.hpp>
#include <cppcms_boost/iostreams/traits.hpp>
#include <cppcms_boost/mpl/identity.hpp>
#include <cppcms_boost/mpl/if.hpp>
#include <cppcms_boost/type_traits/is_convertible.hpp>
#include <cppcms_boost/type_traits/is_integral.hpp>
#include <cppcms_boost/type_traits/remove_cv.hpp>
#include <cppcms_boost/type_traits/remove_reference.hpp>

// Must come last.
#include <cppcms_boost/iostreams/detail/config/disable_warnings.hpp>

namespace cppcms_boost { namespace iostreams {

template<typename T>
void close(T& t);

template<typename T>
void close(T& t, CPPCMS_BOOST_IOS::openmode which);

template<typename T, typename Sink>
void close(T& t, Sink& snk, CPPCMS_BOOST_IOS::openmode which);
    
namespace detail {

template<typename T>
void close_all(T& t)
{ 
    try {
        cppcms_boost::iostreams::close(t, CPPCMS_BOOST_IOS::in);
    } catch (...) {
        try {
            cppcms_boost::iostreams::close(t, CPPCMS_BOOST_IOS::out);
        } catch (...) { }
        throw;
    }
    cppcms_boost::iostreams::close(t, CPPCMS_BOOST_IOS::out);
}

template<typename T, typename Sink>
void close_all(T& t, Sink& snk)
{ 
    try {
        cppcms_boost::iostreams::close(t, snk, CPPCMS_BOOST_IOS::in);
    } catch (...) {
        try {
            cppcms_boost::iostreams::close(t, snk, CPPCMS_BOOST_IOS::out);
        } catch (...) { }
        throw;
    }
    cppcms_boost::iostreams::close(t, snk, CPPCMS_BOOST_IOS::out);
}

} // End namespaces detail. 

} } // End namespaces iostreams, boost.

#if CPPCMS_BOOST_WORKAROUND(CPPCMS_BOOST_MSVC, < 1300) //-----------------------------------//
# include <cppcms_boost/iostreams/detail/vc6/close.hpp>
#else // #if BOOST_WORKAROUND(BOOST_MSVC, < 1300) //--------------------------//

namespace cppcms_boost { namespace iostreams {

namespace detail {

template<typename T>
struct close_impl;

} // End namespace detail.

template<typename T>
void close(T& t) { detail::close_all(t); }

template<typename T>
void close(T& t, CPPCMS_BOOST_IOS::openmode which)
{ 
#ifdef CPPCMS_BOOST_IOSTREAMS_STRICT
    assert(which == CPPCMS_BOOST_IOS::in || which == CPPCMS_BOOST_IOS::out);
#else
    if (which == (CPPCMS_BOOST_IOS::in | CPPCMS_BOOST_IOS::out)) {
        detail::close_all(t);
        return;
    }
#endif
    detail::close_impl<T>::close(detail::unwrap(t), which); 
}

template<typename T, typename Sink>
void close(T& t, Sink& snk, CPPCMS_BOOST_IOS::openmode which)
{ 
#ifdef CPPCMS_BOOST_IOSTREAMS_STRICT
    assert(which == CPPCMS_BOOST_IOS::in || which == CPPCMS_BOOST_IOS::out);
#else
    if (which == (CPPCMS_BOOST_IOS::in | CPPCMS_BOOST_IOS::out)) {
        detail::close_all(t, snk);
        return;
    }
#endif
    detail::close_impl<T>::close(detail::unwrap(t), snk, which); 
}

namespace detail {

//------------------Definition of close_impl----------------------------------//

struct close_cppcms_boost_stream { };
struct close_filtering_stream { };

template<typename T>
struct close_tag {
    typedef typename category_of<T>::type             category;
    typedef typename detail::unwrapped_type<T>::type  unwrapped;
    typedef typename
            iostreams::select<
                mpl::not_< is_convertible<category, closable_tag> >,
                any_tag,
                mpl::or_<
                    is_cppcms_boost_stream<unwrapped>,
                    is_cppcms_boost_stream_buffer<unwrapped>
                >,
                close_cppcms_boost_stream,
                mpl::or_<
                    is_filtering_stream<unwrapped>,
                    is_filtering_streambuf<unwrapped>
                >,
                close_filtering_stream,
                mpl::or_<
                    is_convertible<category, two_sequence>,
                    is_convertible<category, dual_use>
                >,
                two_sequence,
                else_,
                closable_tag
            >::type type;
};

template<typename T>
struct close_impl
    : mpl::if_<
          is_custom<T>,
          operations<T>,
          close_impl<CPPCMS_BOOST_DEDUCED_TYPENAME close_tag<T>::type>
      >::type
    { };

template<>
struct close_impl<any_tag> {
    template<typename T>
    static void close(T& t, CPPCMS_BOOST_IOS::openmode which)
    {
        if (which == CPPCMS_BOOST_IOS::out)
            iostreams::flush(t);
    }

    template<typename T, typename Sink>
    static void close(T& t, Sink& snk, CPPCMS_BOOST_IOS::openmode which)
    {
        if (which == CPPCMS_BOOST_IOS::out) {
            non_blocking_adapter<Sink> nb(snk);
            iostreams::flush(t, nb);
        }
    }
};

template<>
struct close_impl<close_cppcms_boost_stream> {
    template<typename T>
    static void close(T& t)
    {
        t.close();
    }
    template<typename T>
    static void close(T& t, CPPCMS_BOOST_IOS::openmode which)
    {
        if (which == CPPCMS_BOOST_IOS::out)
            t.close();
    }
};

template<>
struct close_impl<close_filtering_stream> {
    template<typename T>
    static void close(T& t, CPPCMS_BOOST_IOS::openmode which)
    {
        typedef typename category_of<T>::type category;
        const bool in =  is_convertible<category, input>::value &&
                        !is_convertible<category, output>::value;
        if (in == (which == CPPCMS_BOOST_IOS::in) && t.is_complete())
            t.pop();
    }
};

template<>
struct close_impl<closable_tag> {
    template<typename T>
    static void close(T& t, CPPCMS_BOOST_IOS::openmode which)
    {
        typedef typename category_of<T>::type category;
        const bool in =  is_convertible<category, input>::value &&
                        !is_convertible<category, output>::value;
        if (in == (which == CPPCMS_BOOST_IOS::in))
            t.close();
    }
    template<typename T, typename Sink>
    static void close(T& t, Sink& snk, CPPCMS_BOOST_IOS::openmode which)
    {
        typedef typename category_of<T>::type category;
        const bool in =  is_convertible<category, input>::value &&
                        !is_convertible<category, output>::value;
        if (in == (which == CPPCMS_BOOST_IOS::in)) {
            non_blocking_adapter<Sink> nb(snk);
            t.close(nb);
        }
    }
};

template<>
struct close_impl<two_sequence> {
    template<typename T>
    static void close(T& t, CPPCMS_BOOST_IOS::openmode which) { t.close(which); }
    template<typename T, typename Sink>
    static void close(T& t, Sink& snk, CPPCMS_BOOST_IOS::openmode which)
    {
        non_blocking_adapter<Sink> nb(snk);
        t.close(nb, which);
    }
};

} // End namespace detail.

} } // End namespaces iostreams, boost.

#endif // #if BOOST_WORKAROUND(BOOST_MSVC, < 1300) //-------------------------//

#include <cppcms_boost/iostreams/detail/config/enable_warnings.hpp>

#endif // #ifndef BOOST_IOSTREAMS_CLOSE_HPP_INCLUDED
