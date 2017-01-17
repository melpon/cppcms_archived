// (C) Copyright David Abrahams 2002.
// (C) Copyright Jeremy Siek    2002.
// (C) Copyright Thomas Witt    2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef CPPCMS_BOOST_INTEROPERABLE_23022003THW_HPP
# define CPPCMS_BOOST_INTEROPERABLE_23022003THW_HPP

# include <cppcms_boost/mpl/bool.hpp>
# include <cppcms_boost/mpl/or.hpp>

# include <cppcms_boost/type_traits/is_convertible.hpp>

# include <cppcms_boost/iterator/detail/config_def.hpp> // must appear last

namespace cppcms_boost
{

  //
  // Meta function that determines whether two
  // iterator types are considered interoperable.
  //
  // Two iterator types A,B are considered interoperable if either
  // A is convertible to B or vice versa.
  // This interoperability definition is in sync with the
  // standards requirements on constant/mutable container
  // iterators (23.1 [lib.container.requirements]).
  //
  // For compilers that don't support is_convertible 
  // is_interoperable gives false positives. See comments
  // on operator implementation for consequences.
  //
  template <typename A, typename B>
  struct is_interoperable
# ifdef CPPCMS_BOOST_NO_STRICT_ITERATOR_INTEROPERABILITY
    : mpl::true_
# else
    : mpl::or_<
          is_convertible< A, B >
        , is_convertible< B, A > >
# endif
  { 
  };

} // namespace boost

# include <cppcms_boost/iterator/detail/config_undef.hpp>

#endif // BOOST_INTEROPERABLE_23022003THW_HPP
