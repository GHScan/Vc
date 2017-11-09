/*  This file is part of the Vc library. {{{
Copyright © 2017 Matthias Kretz <kretz@kde.org>

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the names of contributing organizations nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

}}}*/

//#define UNITTEST_ONLY_XTEST 1
#include <vir/test.h>
#include <Vc/simd>
#include "metahelpers.h"

#define TESTTYPES                                                                        \
    long double, double, float, unsigned long long, long long, unsigned long, long,      \
        unsigned int, int, unsigned short, short, unsigned char, signed char, char
template <class... Ts> using base_template = Vc::simd<Ts...>;
#include "testtypes.h"

using vir::Typelist;
using vir::Template;
using vir::Template1;
using vir::expand_list;
using vir::filter_list;
using vir::concat;
using Vc::simd;
using Vc::simd_mask;

// type lists {{{1
using all_valid_scalars = expand_list<Typelist<Template<simd, Vc::simd_abi::scalar>,
                                               Template<simd_mask, Vc::simd_abi::scalar>>,
                                      testtypes>;

using all_valid_fixed_size =
    expand_list<Typelist<Template<simd, Vc::simd_abi::fixed_size<1>>,
                         Template<simd, Vc::simd_abi::fixed_size<2>>,
                         Template<simd, Vc::simd_abi::fixed_size<3>>,
                         Template<simd, Vc::simd_abi::fixed_size<4>>,
                         Template<simd, Vc::simd_abi::fixed_size<5>>,
                         Template<simd, Vc::simd_abi::fixed_size<6>>,
                         Template<simd, Vc::simd_abi::fixed_size<7>>,
                         Template<simd, Vc::simd_abi::fixed_size<8>>,
                         Template<simd, Vc::simd_abi::fixed_size<9>>,
                         Template<simd, Vc::simd_abi::fixed_size<10>>,
                         Template<simd, Vc::simd_abi::fixed_size<11>>,
                         Template<simd, Vc::simd_abi::fixed_size<12>>,
                         Template<simd, Vc::simd_abi::fixed_size<13>>,
                         Template<simd, Vc::simd_abi::fixed_size<14>>,
                         Template<simd, Vc::simd_abi::fixed_size<15>>,
                         Template<simd, Vc::simd_abi::fixed_size<16>>,
                         Template<simd, Vc::simd_abi::fixed_size<17>>,
                         Template<simd, Vc::simd_abi::fixed_size<18>>,
                         Template<simd, Vc::simd_abi::fixed_size<19>>,
                         Template<simd, Vc::simd_abi::fixed_size<20>>,
                         Template<simd, Vc::simd_abi::fixed_size<21>>,
                         Template<simd, Vc::simd_abi::fixed_size<22>>,
                         Template<simd, Vc::simd_abi::fixed_size<23>>,
                         Template<simd, Vc::simd_abi::fixed_size<24>>,
                         Template<simd, Vc::simd_abi::fixed_size<25>>,
                         Template<simd, Vc::simd_abi::fixed_size<26>>,
                         Template<simd, Vc::simd_abi::fixed_size<27>>,
                         Template<simd, Vc::simd_abi::fixed_size<28>>,
                         Template<simd, Vc::simd_abi::fixed_size<29>>,
                         Template<simd, Vc::simd_abi::fixed_size<30>>,
                         Template<simd, Vc::simd_abi::fixed_size<31>>,
                         Template<simd, Vc::simd_abi::fixed_size<32>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<1>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<2>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<3>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<4>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<5>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<6>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<7>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<8>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<9>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<10>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<11>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<12>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<13>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<14>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<15>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<16>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<17>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<18>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<19>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<20>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<21>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<22>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<23>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<24>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<25>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<26>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<27>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<28>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<29>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<30>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<31>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<32>>>,
                testtypes>;

using all_valid_simd = concat<
#if defined Vc_HAVE_FULL_SSE_ABI
    expand_list<Typelist<Template<simd, Vc::simd_abi::sse>,
                         Template<simd_mask, Vc::simd_abi::sse>>,
                testtypes_wo_ldouble>,
#elif defined Vc_HAVE_SSE_ABI
    expand_list<Typelist<Template<simd, Vc::simd_abi::sse>,
                         Template<simd_mask, Vc::simd_abi::sse>>,
                testtypes_float>,
#endif
#if defined Vc_HAVE_FULL_AVX_ABI
    expand_list<Typelist<Template<simd, Vc::simd_abi::avx>,
                         Template<simd_mask, Vc::simd_abi::avx>>,
                testtypes_wo_ldouble>,
#elif defined Vc_HAVE_AVX_ABI
    expand_list<Typelist<Template<simd, Vc::simd_abi::avx>,
                         Template<simd_mask, Vc::simd_abi::avx>>,
                testtypes_fp>,
#endif
#if defined Vc_HAVE_FULL_AVX512_ABI
    expand_list<Typelist<Template<simd, Vc::simd_abi::avx512>,
                         Template<simd_mask, Vc::simd_abi::avx512>>,
                testtypes_wo_ldouble>,
#elif defined Vc_HAVE_AVX512_ABI
    expand_list<Typelist<Template<simd, Vc::simd_abi::avx512>,
                         Template<simd_mask, Vc::simd_abi::avx512>>,
                testtypes_64_32>,
#endif
#if defined Vc_HAVE_FULL_NEON_ABI
    expand_list<Typelist<Template<simd, Vc::simd_abi::neon>,
                         Template<simd_mask, Vc::simd_abi::neon>>,
                testtypes_wo_ldouble>,
#endif
    Typelist<>>;

TEST_TYPES(V, is_usable,  //{{{1
           concat<all_valid_scalars, all_valid_simd, all_valid_fixed_size>)
{
    VERIFY(std::is_destructible<V>::value);
    VERIFY(std::is_copy_constructible<V>::value);
    VERIFY(std::is_copy_assignable<V>::value);
}

struct dummy {};
template <class A> using dummy_simd = simd<dummy, A>;
template <class A> using dummy_mask = simd_mask<dummy, A>;
template <class A> using bool_simd = simd<bool, A>;
template <class A> using bool_mask = simd_mask<bool, A>;

using unusable_abis = Typelist<
#if !defined Vc_HAVE_SSE_ABI
    Template<simd, Vc::simd_abi::sse>, Template<simd_mask, Vc::simd_abi::sse>,
#endif
#if !defined Vc_HAVE_AVX_ABI
    Template<simd, Vc::simd_abi::avx>, Template<simd_mask, Vc::simd_abi::avx>,
#endif
#if !defined Vc_HAVE_AVX512_ABI
    Template<simd, Vc::simd_abi::avx512>, Template<simd_mask, Vc::simd_abi::avx512>,
#endif
#if !defined Vc_HAVE_NEON_ABI
    Template<simd, Vc::simd_abi::neon>, Template<simd_mask, Vc::simd_abi::neon>,
#endif
    Template<simd, int>, Template<simd_mask, int>>;

using unusable_fixed_size =
    expand_list<Typelist<Template<simd, Vc::simd_abi::fixed_size<33>>,
                         Template<simd_mask, Vc::simd_abi::fixed_size<33>>>,
                testtypes>;

using unusable_simd_types =
    concat<expand_list<Typelist<Template<simd, Vc::simd_abi::sse>,
                                Template<simd_mask, Vc::simd_abi::sse>>,
#if defined Vc_HAVE_SSE_ABI && !defined Vc_HAVE_FULL_SSE_ABI
                       typename filter_list<float, testtypes>::type
#else
                       Typelist<long double>
#endif
                       >,
           expand_list<Typelist<Template<simd, Vc::simd_abi::avx>,
                                Template<simd_mask, Vc::simd_abi::avx>>,
#if defined Vc_HAVE_AVX_ABI && !defined Vc_HAVE_FULL_AVX_ABI
                       typename filter_list<Typelist<float, double>, testtypes>::type
#else
                       Typelist<long double>
#endif
                       >,
           expand_list<Typelist<Template<simd, Vc::simd_abi::neon>,
                                Template<simd_mask, Vc::simd_abi::neon>>,
                       Typelist<long double>>,
           expand_list<Typelist<Template<simd, Vc::simd_abi::avx512>,
                                Template<simd_mask, Vc::simd_abi::avx512>>,
#if defined Vc_HAVE_AVX512_ABI && !defined Vc_HAVE_FULL_AVX512_ABI
                       typename filter_list<
                           Typelist<float, double, ullong, llong, ulong, long, uint, int>,
                           testtypes>::type
#else
                       Typelist<long double>
#endif
                       >>;

TEST_TYPES(V, is_unusable,  //{{{1
           concat<expand_list<unusable_abis, testtypes_wo_ldouble>, unusable_simd_types,
                  unusable_fixed_size,
                  expand_list<Typelist<Template1<dummy_simd>, Template1<dummy_mask>,
                                       Template1<bool_simd>, Template1<bool_mask>>,
                              all_native_abis>>)
{
    VERIFY(!std::is_destructible<V>::value);
    VERIFY(!std::is_copy_constructible<V>::value);
    VERIFY(!std::is_copy_assignable<V>::value);
}

// loadstore_pointer_types {{{1
struct call_memload {
    template <class V, class T>
    auto operator()(V &&v, const T *mem)
        -> decltype(v.copy_from(mem, Vc::element_aligned));
};
struct call_masked_memload {
    template <class M, class V, class T>
    auto operator()(const M &k, V &&v, const T *mem)
        -> decltype(Vc::where(k, v).copy_from(mem, Vc::element_aligned));
};
struct call_memstore {
    template <class V, class T>
    auto operator()(V &&v, T *mem)
        -> decltype(v.copy_to(mem, Vc::element_aligned));
};
struct call_masked_memstore {
    template <class M, class V, class T>
    auto operator()(const M &k, V &&v, T *mem)
        -> decltype(Vc::where(k, v).copy_to(mem, Vc::element_aligned));
};
TEST_TYPES(V, loadstore_pointer_types, all_test_types)
{
    using vir::test::sfinae_is_callable;
    using M = typename V::mask_type;
    struct Foo {
    };
    VERIFY( (sfinae_is_callable<V &, const int *>(call_memload())));
    VERIFY( (sfinae_is_callable<V &, const float *>(call_memload())));
    VERIFY(!(sfinae_is_callable<V &, const bool *>(call_memload())));
    VERIFY(!(sfinae_is_callable<V &, const Foo *>(call_memload())));
    VERIFY( (sfinae_is_callable<const V &, int *>(call_memstore())));
    VERIFY( (sfinae_is_callable<const V &, float *>(call_memstore())));
    VERIFY(!(sfinae_is_callable<const V &, bool *>(call_memstore())));
    VERIFY(!(sfinae_is_callable<const V &, Foo *>(call_memstore())));

    VERIFY( (sfinae_is_callable<M, const V &, const int *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<M, const V &, const float *>(call_masked_memload())));
    VERIFY(!(sfinae_is_callable<M, const V &, const Foo *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<M, const V &, int *>(call_masked_memstore())));
    VERIFY( (sfinae_is_callable<M, const V &, float *>(call_masked_memstore())));
    VERIFY(!(sfinae_is_callable<M, const V &, Foo *>(call_masked_memstore())));

    VERIFY( (sfinae_is_callable<M, V &, const int *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<M, V &, const float *>(call_masked_memload())));
    VERIFY(!(sfinae_is_callable<M, V &, const Foo *>(call_masked_memload())));

    VERIFY( (sfinae_is_callable<M &, const bool *>(call_memload())));
    VERIFY(!(sfinae_is_callable<M &, const int *>(call_memload())));
    VERIFY(!(sfinae_is_callable<M &, const Foo *>(call_memload())));
    VERIFY( (sfinae_is_callable<M &, bool *>(call_memstore())));
    VERIFY(!(sfinae_is_callable<M &, int *>(call_memstore())));
    VERIFY(!(sfinae_is_callable<M &, Foo *>(call_memstore())));

    VERIFY( (sfinae_is_callable<M, M &, const bool *>(call_masked_memload())));
    VERIFY(!(sfinae_is_callable<M, M &, const int *>(call_masked_memload())));
    VERIFY(!(sfinae_is_callable<M, M &, const Foo *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<M, M &, bool *>(call_masked_memstore())));
    VERIFY(!(sfinae_is_callable<M, M &, int *>(call_masked_memstore())));
    VERIFY(!(sfinae_is_callable<M, M &, Foo *>(call_masked_memstore())));

    VERIFY( (sfinae_is_callable<M, const M &, const bool *>(call_masked_memload())));
    VERIFY(!(sfinae_is_callable<M, const M &, const int *>(call_masked_memload())));
    VERIFY(!(sfinae_is_callable<M, const M &, const Foo *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<M, const M &, bool *>(call_masked_memstore())));
    VERIFY(!(sfinae_is_callable<M, const M &, int *>(call_masked_memstore())));
    VERIFY(!(sfinae_is_callable<M, const M &, Foo *>(call_masked_memstore())));
}

TEST(masked_loadstore_builtin) {
    VERIFY( (sfinae_is_callable<bool, const int &, const int *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<bool, const int &, const float *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<bool, const bool &, const bool *>(call_masked_memload())));
    VERIFY(!(sfinae_is_callable<bool, const bool &, const int *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<bool, const int &, int *>(call_masked_memstore())));
    VERIFY( (sfinae_is_callable<bool, const int &, float *>(call_masked_memstore())));
    VERIFY( (sfinae_is_callable<bool, const bool &, bool *>(call_masked_memstore())));
    VERIFY(!(sfinae_is_callable<bool, const bool &, int *>(call_masked_memstore())));

    VERIFY( (sfinae_is_callable<bool, int &, const int *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<bool, int &, const float *>(call_masked_memload())));
    VERIFY( (sfinae_is_callable<bool, bool &, const bool *>(call_masked_memload())));
    VERIFY(!(sfinae_is_callable<bool, bool &, const int *>(call_masked_memload())));
}

// vim: foldmethod=marker
