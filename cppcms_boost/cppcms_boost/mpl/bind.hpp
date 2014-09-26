
#if !defined(CPPCMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef CPPCMS_BOOST_MPL_BIND_HPP_INCLUDED
#define CPPCMS_BOOST_MPL_BIND_HPP_INCLUDED

// Copyright Peter Dimov 2001
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: bind.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <cppcms_boost/mpl/bind_fwd.hpp>
#   include <cppcms_boost/mpl/placeholders.hpp>
#   include <cppcms_boost/mpl/next.hpp>
#   include <cppcms_boost/mpl/protect.hpp>
#   include <cppcms_boost/mpl/apply_wrap.hpp>
#   include <cppcms_boost/mpl/limits/arity.hpp>
#   include <cppcms_boost/mpl/aux_/na.hpp>
#   include <cppcms_boost/mpl/aux_/arity_spec.hpp>
#   include <cppcms_boost/mpl/aux_/type_wrapper.hpp>
#   include <cppcms_boost/mpl/aux_/yes_no.hpp>
#   if defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#       include <cppcms_boost/type_traits/is_reference.hpp>
#   endif 
#endif

#include <cppcms_boost/mpl/aux_/config/bind.hpp>
#include <cppcms_boost/mpl/aux_/config/static_constant.hpp>
#include <cppcms_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(CPPCMS_BOOST_MPL_PREPROCESSING_MODE)

#   if defined(CPPCMS_BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT)
#       define CPPCMS_BOOST_MPL_PREPROCESSED_HEADER basic_bind.hpp
#   else
#       define CPPCMS_BOOST_MPL_PREPROCESSED_HEADER bind.hpp
#   endif
#   include <cppcms_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <cppcms_boost/mpl/aux_/preprocessor/params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/default_params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/def_params_tail.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/partial_spec_params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/ext_params.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/repeat.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/enum.hpp>
#   include <cppcms_boost/mpl/aux_/preprocessor/add.hpp>
#   include <cppcms_boost/mpl/aux_/config/dmc_ambiguous_ctps.hpp>
#   include <cppcms_boost/mpl/aux_/config/ctps.hpp>
#   include <cppcms_boost/mpl/aux_/config/ttp.hpp>
#   include <cppcms_boost/mpl/aux_/config/dtp.hpp>
#   include <cppcms_boost/mpl/aux_/nttp_decl.hpp>

#   include <cppcms_boost/preprocessor/iterate.hpp>
#   include <cppcms_boost/preprocessor/comma_if.hpp>
#   include <cppcms_boost/preprocessor/cat.hpp>
#   include <cppcms_boost/preprocessor/inc.hpp>

namespace cppcms_boost { namespace mpl {

// local macros, #undef-ined at the end of the header
#   define AUX778076_APPLY \
    CPPCMS_BOOST_PP_CAT(apply_wrap,CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY) \
    /**/

#   if defined(CPPCMS_BOOST_MPL_CFG_DMC_AMBIGUOUS_CTPS)
#       define AUX778076_DMC_PARAM() , int dummy_
#   else
#       define AUX778076_DMC_PARAM()
#   endif

#   define AUX778076_BIND_PARAMS(param) \
    CPPCMS_BOOST_MPL_PP_PARAMS( \
          CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        ) \
    /**/

#   define AUX778076_BIND_DEFAULT_PARAMS(param, value) \
    CPPCMS_BOOST_MPL_PP_DEFAULT_PARAMS( \
          CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        , value \
        ) \
    /**/

#   define AUX778076_BIND_N_PARAMS(n, param) \
    CPPCMS_BOOST_PP_COMMA_IF(n) CPPCMS_BOOST_MPL_PP_PARAMS(n, param) \
    /**/

#   define AUX778076_BIND_N_SPEC_PARAMS(n, param, def) \
    CPPCMS_BOOST_PP_COMMA_IF(n) \
    CPPCMS_BOOST_MPL_PP_PARTIAL_SPEC_PARAMS(n, param, def) \
    /**/

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define AUX778076_BIND_NESTED_DEFAULT_PARAMS(param, value) \
    AUX778076_BIND_DEFAULT_PARAMS(param, value) \
    /**/
#else
#   define AUX778076_BIND_NESTED_DEFAULT_PARAMS(param, value) \
    AUX778076_BIND_PARAMS(param) \
    /**/
#endif

namespace aux {

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template<
      typename T, AUX778076_BIND_PARAMS(typename U)
    >
struct resolve_bind_arg
{
    typedef T type;
};

#   if !defined(CPPCMS_BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT)

template<
      typename T
    , typename Arg
    >
struct replace_unnamed_arg
{
    typedef Arg next;
    typedef T type;
};

template<
      typename Arg
    >
struct replace_unnamed_arg< arg<-1>,Arg >
{
    typedef typename Arg::next next;
    typedef Arg type;
};

#   endif // BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT

template<
      CPPCMS_BOOST_MPL_AUX_NTTP_DECL(int, N), AUX778076_BIND_PARAMS(typename U)
    >
struct resolve_bind_arg< arg<N>,AUX778076_BIND_PARAMS(U) >
{
    typedef typename AUX778076_APPLY<mpl::arg<N>, AUX778076_BIND_PARAMS(U)>::type type;
};

#if !defined(CPPCMS_BOOST_MPL_CFG_NO_BIND_TEMPLATE)
template<
      typename F, AUX778076_BIND_PARAMS(typename T), AUX778076_BIND_PARAMS(typename U)
    >
struct resolve_bind_arg< bind<F,AUX778076_BIND_PARAMS(T)>,AUX778076_BIND_PARAMS(U) >
{
    typedef bind<F,AUX778076_BIND_PARAMS(T)> f_;
    typedef typename AUX778076_APPLY<f_, AUX778076_BIND_PARAMS(U)>::type type;
};
#endif

#else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

// agurt, 15/jan/02: it's not a intended to be used as a function class, and 
// MSVC6.5 has problems with 'apply' name here (the code compiles, but doesn't
// work), so I went with the 'result_' here, and in all other similar cases
template< bool >
struct resolve_arg_impl
{
    template< typename T, AUX778076_BIND_PARAMS(typename U) > struct result_
    {
        typedef T type;
    };
};

template<> 
struct resolve_arg_impl<true>
{
    template< typename T, AUX778076_BIND_PARAMS(typename U) > struct result_
    {
        typedef typename AUX778076_APPLY<
              T
            , AUX778076_BIND_PARAMS(U)
            >::type type;
    };
};

// for 'resolve_bind_arg'
template< typename T > struct is_bind_template;

template< 
      typename T, AUX778076_BIND_PARAMS(typename U)
    >
struct resolve_bind_arg
    : resolve_arg_impl< is_bind_template<T>::value >
            ::template result_< T,AUX778076_BIND_PARAMS(U) >
{
};

#   if !defined(CPPCMS_BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT)

template< typename T > 
struct replace_unnamed_arg_impl
{
    template< typename Arg > struct result_
    {
        typedef Arg next;
        typedef T type;
    };
};

template<> 
struct replace_unnamed_arg_impl< arg<-1> >
{
    template< typename Arg > struct result_
    {
        typedef typename next<Arg>::type next;
        typedef Arg type;
    };
};

template< typename T, typename Arg > 
struct replace_unnamed_arg
    : replace_unnamed_arg_impl<T>::template result_<Arg>
{
};

#   endif // BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT

// agurt, 10/mar/02: the forward declaration has to appear before any of
// 'is_bind_helper' overloads, otherwise MSVC6.5 issues an ICE on it
template< CPPCMS_BOOST_MPL_AUX_NTTP_DECL(int, arity_) > struct bind_chooser;

aux::no_tag is_bind_helper(...);
template< typename T > aux::no_tag is_bind_helper(protect<T>*);

// overload for "main" form
// agurt, 15/mar/02: MSVC 6.5 fails to properly resolve the overload 
// in case if we use 'aux::type_wrapper< bind<...> >' here, and all 
// 'bind' instantiations form a complete type anyway
#if !defined(CPPCMS_BOOST_MPL_CFG_NO_BIND_TEMPLATE)
template<
      typename F, AUX778076_BIND_PARAMS(typename T)
    >
aux::yes_tag is_bind_helper(bind<F,AUX778076_BIND_PARAMS(T)>*);
#endif

template< CPPCMS_BOOST_MPL_AUX_NTTP_DECL(int, N) >
aux::yes_tag is_bind_helper(arg<N>*);

template< bool is_ref_ = true >
struct is_bind_template_impl
{
    template< typename T > struct result_
    {
        CPPCMS_BOOST_STATIC_CONSTANT(bool, value = false);
    };
};

template<>
struct is_bind_template_impl<false>
{
    template< typename T > struct result_
    {
        CPPCMS_BOOST_STATIC_CONSTANT(bool, value = 
              sizeof(aux::is_bind_helper(static_cast<T*>(0))) 
                == sizeof(aux::yes_tag)
            );
    };
};

template< typename T > struct is_bind_template
    : is_bind_template_impl< ::cppcms_boost::detail::is_reference_impl<T>::value >
        ::template result_<T>
{
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace aux


#define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, <cppcms_boost/mpl/bind.hpp>))
#include CPPCMS_BOOST_PP_ITERATE()

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    && !defined(CPPCMS_BOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS)
/// if_/eval_if specializations
#   define AUX778076_SPEC_NAME if_
#   define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 (3,(3, 3, <cppcms_boost/mpl/bind.hpp>))
#   include CPPCMS_BOOST_PP_ITERATE()

#if !defined(CPPCMS_BOOST_MPL_CFG_DMC_AMBIGUOUS_CTPS)
#   define AUX778076_SPEC_NAME eval_if
#   define CPPCMS_BOOST_PP_ITERATION_PARAMS_1 (3,(3, 3, <cppcms_boost/mpl/bind.hpp>))
#   include CPPCMS_BOOST_PP_ITERATE()
#endif
#endif

// real C++ version is already taken care of
#if defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    && !defined(CPPCMS_BOOST_MPL_CFG_NO_BIND_TEMPLATE)

namespace aux {
// apply_count_args
#define AUX778076_COUNT_ARGS_PREFIX bind
#define AUX778076_COUNT_ARGS_DEFAULT na
#define AUX778076_COUNT_ARGS_ARITY CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
#include <cppcms_boost/mpl/aux_/count_args.hpp>
}

// bind
template<
      typename F, AUX778076_BIND_PARAMS(typename T) AUX778076_DMC_PARAM()
    >
struct bind
    : aux::bind_chooser<
          aux::bind_count_args<AUX778076_BIND_PARAMS(T)>::value
        >::template result_< F,AUX778076_BIND_PARAMS(T) >::type
{
};

CPPCMS_BOOST_MPL_AUX_ARITY_SPEC(
      CPPCMS_BOOST_PP_INC(CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY)
    , bind
    )

CPPCMS_BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(
      CPPCMS_BOOST_PP_INC(CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY)
    , bind
    )


#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#   undef AUX778076_BIND_NESTED_DEFAULT_PARAMS
#   undef AUX778076_BIND_N_SPEC_PARAMS
#   undef AUX778076_BIND_N_PARAMS
#   undef AUX778076_BIND_DEFAULT_PARAMS
#   undef AUX778076_BIND_PARAMS
#   undef AUX778076_DMC_PARAM
#   undef AUX778076_APPLY

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_BIND_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // BOOST_PP_IS_ITERATING
#if CPPCMS_BOOST_PP_ITERATION_DEPTH() == 1

#   define i_ CPPCMS_BOOST_PP_FRAME_ITERATION(1)

#if defined(AUX778076_SPEC_NAME)

// lazy metafunction specialization
template< template< CPPCMS_BOOST_MPL_PP_PARAMS(i_, typename T) > class F, typename Tag >
struct CPPCMS_BOOST_PP_CAT(quote,i_);

template< CPPCMS_BOOST_MPL_PP_PARAMS(i_, typename T) > struct AUX778076_SPEC_NAME;

template<
      typename Tag AUX778076_BIND_N_PARAMS(i_, typename T)
    >
struct CPPCMS_BOOST_PP_CAT(bind,i_)< 
      CPPCMS_BOOST_PP_CAT(quote,i_)<AUX778076_SPEC_NAME,Tag>
    AUX778076_BIND_N_PARAMS(i_,T)
    >
{
    template<
          AUX778076_BIND_NESTED_DEFAULT_PARAMS(typename U, na)
        >
    struct apply
    {
     private:
        typedef mpl::arg<1> n1;
#       define CPPCMS_BOOST_PP_ITERATION_PARAMS_2 (3,(1, i_, <cppcms_boost/mpl/bind.hpp>))
#       include CPPCMS_BOOST_PP_ITERATE()

        typedef typename AUX778076_SPEC_NAME<
              typename t1::type
            , CPPCMS_BOOST_MPL_PP_EXT_PARAMS(2, CPPCMS_BOOST_PP_INC(i_), t)
            >::type f_;

     public:
        typedef typename f_::type type;
    };
};

#undef AUX778076_SPEC_NAME

#else // AUX778076_SPEC_NAME

template<
      typename F AUX778076_BIND_N_PARAMS(i_, typename T) AUX778076_DMC_PARAM()
    >
struct CPPCMS_BOOST_PP_CAT(bind,i_)
{
    template<
          AUX778076_BIND_NESTED_DEFAULT_PARAMS(typename U, na)
        >
    struct apply
    {
     private:
#   if !defined(CPPCMS_BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT)

        typedef aux::replace_unnamed_arg< F,mpl::arg<1> > r0;
        typedef typename r0::type a0;
        typedef typename r0::next n1;
        typedef typename aux::resolve_bind_arg<a0,AUX778076_BIND_PARAMS(U)>::type f_;
        ///
#   else
        typedef typename aux::resolve_bind_arg<F,AUX778076_BIND_PARAMS(U)>::type f_;

#   endif // BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT

#   if i_ > 0
#       define CPPCMS_BOOST_PP_ITERATION_PARAMS_2 (3,(1, i_, <cppcms_boost/mpl/bind.hpp>))
#       include CPPCMS_BOOST_PP_ITERATE()
#   endif

     public:

#   define AUX778076_ARG(unused, i_, t) \
    CPPCMS_BOOST_PP_COMMA_IF(i_) \
    typename CPPCMS_BOOST_PP_CAT(t,CPPCMS_BOOST_PP_INC(i_))::type \
/**/

        typedef typename CPPCMS_BOOST_PP_CAT(apply_wrap,i_)<
              f_ 
            CPPCMS_BOOST_PP_COMMA_IF(i_) CPPCMS_BOOST_MPL_PP_REPEAT(i_, AUX778076_ARG, t)
            >::type type;

#   undef AUX778076_ARG
    };
};

namespace aux {

#if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template<
      typename F AUX778076_BIND_N_PARAMS(i_, typename T), AUX778076_BIND_PARAMS(typename U)
    >
struct resolve_bind_arg<
      CPPCMS_BOOST_PP_CAT(bind,i_)<F AUX778076_BIND_N_PARAMS(i_,T)>,AUX778076_BIND_PARAMS(U)
    >
{
    typedef CPPCMS_BOOST_PP_CAT(bind,i_)<F AUX778076_BIND_N_PARAMS(i_,T)> f_;
    typedef typename AUX778076_APPLY<f_, AUX778076_BIND_PARAMS(U)>::type type;
};

#else

template<
      typename F AUX778076_BIND_N_PARAMS(i_, typename T)
    >
aux::yes_tag
is_bind_helper(CPPCMS_BOOST_PP_CAT(bind,i_)<F AUX778076_BIND_N_PARAMS(i_,T)>*);

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace aux

CPPCMS_BOOST_MPL_AUX_ARITY_SPEC(CPPCMS_BOOST_PP_INC(i_), CPPCMS_BOOST_PP_CAT(bind,i_))
CPPCMS_BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(CPPCMS_BOOST_PP_INC(i_), CPPCMS_BOOST_PP_CAT(bind,i_))

#   if !defined(CPPCMS_BOOST_MPL_CFG_NO_BIND_TEMPLATE)
#   if !defined(CPPCMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    
#if i_ == CPPCMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
/// primary template (not a specialization!)
template<
      typename F AUX778076_BIND_N_PARAMS(i_, typename T) AUX778076_DMC_PARAM()
    >
struct bind
    : CPPCMS_BOOST_PP_CAT(bind,i_)<F AUX778076_BIND_N_PARAMS(i_,T) >
{
};
#else
template<
      typename F AUX778076_BIND_N_PARAMS(i_, typename T) AUX778076_DMC_PARAM()
    >
struct bind< F AUX778076_BIND_N_SPEC_PARAMS(i_, T, na) >
    : CPPCMS_BOOST_PP_CAT(bind,i_)<F AUX778076_BIND_N_PARAMS(i_,T) >
{
};
#endif

#   else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

namespace aux {

template<>
struct bind_chooser<i_>
{
    template<
          typename F, AUX778076_BIND_PARAMS(typename T)
        >
    struct result_
    {
        typedef CPPCMS_BOOST_PP_CAT(bind,i_)< F AUX778076_BIND_N_PARAMS(i_,T) > type;
    };
};

} // namespace aux

#   endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   endif // BOOST_MPL_CFG_NO_BIND_TEMPLATE

#endif // AUX778076_SPEC_NAME

#   undef i_

///// iteration, depth == 2

#elif CPPCMS_BOOST_PP_ITERATION_DEPTH() == 2

#   define j_ CPPCMS_BOOST_PP_FRAME_ITERATION(2)
#   if !defined(CPPCMS_BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT)

        typedef aux::replace_unnamed_arg< CPPCMS_BOOST_PP_CAT(T,j_),CPPCMS_BOOST_PP_CAT(n,j_) > CPPCMS_BOOST_PP_CAT(r,j_);
        typedef typename CPPCMS_BOOST_PP_CAT(r,j_)::type CPPCMS_BOOST_PP_CAT(a,j_);
        typedef typename CPPCMS_BOOST_PP_CAT(r,j_)::next CPPCMS_BOOST_PP_CAT(n,CPPCMS_BOOST_PP_INC(j_));
        typedef aux::resolve_bind_arg<CPPCMS_BOOST_PP_CAT(a,j_), AUX778076_BIND_PARAMS(U)> CPPCMS_BOOST_PP_CAT(t,j_);
        ///
#   else
        typedef aux::resolve_bind_arg< CPPCMS_BOOST_PP_CAT(T,j_),AUX778076_BIND_PARAMS(U)> CPPCMS_BOOST_PP_CAT(t,j_);

#   endif
#   undef j_

#endif // BOOST_PP_ITERATION_DEPTH()
#endif // BOOST_PP_IS_ITERATING
