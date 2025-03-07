// bslmf_matchanytype.h                                               -*-C++-*-
#ifndef INCLUDED_BSLMF_MATCHANYTYPE
#define INCLUDED_BSLMF_MATCHANYTYPE

#include <bsls_ident.h>
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide a generic type to which any type can be converted.
//
//@CLASSES:
//  bslmf::MatchAnyType: generic type to which any type can be converted
//  bslmf::TypeRep: meta-function for providing a reference to 't_TYPE'
//
//@DESCRIPTION: 'bslmf::MatchAnyType' is a type to which any type can be
// implicitly converted.  This is useful for creating an overloaded function
// that is a catch-all for all types not explicitly provided for in other
// overloaded functions with the same name.
//
// 'bslmf::TypeRep' allows one to create a reference to a type.  In complex
// template programming, one is often dealing with unknown types, about the
// constructors of which one knows nothing.  One often needs an object of the
// given type, but since nothing is known about the constructors, one can't
// just construct and object of the type.  'bslmf::TypeRep' allows one to
// create a reference to the type.  Note that the 'rep' function in
// 'bslmf::TypeRep' is not implemented, it must never be called at run time.
//
///Usage
///-----
// This section illustrates intended use of this component.
//
///Example 1: 'bslmf::MatchAnyType'
/// - - - - - - - - - - - - - - - -
//..
//  struct X { };
//  struct Y { };
//  struct Z : public Y { };
//
//  inline bool isY(const bslmf::MatchAnyType&) { return false; }
//  inline bool isY(const Y&)              { return true;  }
//
//  assert(! isY(X()));
//  assert(  isY(Y()));
//  assert(  isY(Z()));
//  assert(! isY(int()));
//  assert(! isY(4));
//  assert(! isY(4.0));
//  assert(! isY("The king is a fink!"));
//
//  X x;
//  Y y;
//  Z z;
//  assert(! isY(x));
//  assert(  isY(y));
//  assert(  isY(z));
//..
//
///Example 2: 'bslmf::TypeRep'
///- - - - - - - - - - - - - -
//..
//  struct X {};
//  struct Y {};
//
//  struct HasHorridCtorX : public X {
//      HasHorridCtorX(int, double, X, char, char *, void *) {}
//          // It's inconvenient to actually create an object of this type
//          // because the constructor takes so many arguments.  It's also
//          // impossible because the c'tor is undefined.
//  };
//  struct HasHorridCtorY : public Y {
//      HasHorridCtorY(int, double, X, char, char *, void *) {}
//          // It's inconvenient to actually create an object of this type
//          // because the constructor takes so many arguments.  It's also
//          // impossible because the c'tor is undefined.
//  };
//
//  template <int i>
//  struct MetaInt { char d_array[i + 1]; };
//
//  #define METAINT_TO_UINT(metaint)   (sizeof(metaint) - 1)
//
//  MetaInt<1> isX(const X&);
//  MetaInt<0> isX(const bslmf::MatchAnyType&);
//
//  assert(1 == METAINT_TO_UINT(isX(X())));
//  assert(0 == METAINT_TO_UINT(isX(Y())));
//  assert(1 == METAINT_TO_UINT(isX(bslmf::TypeRep<HasHorridCtorX>::rep())));
//  assert(0 == METAINT_TO_UINT(isX(bslmf::TypeRep<HasHorridCtorY>::rep())));
//  assert(0 == METAINT_TO_UINT(isX(3)));
//  assert(0 == METAINT_TO_UINT(isX(3.0)));
//  assert(0 == METAINT_TO_UINT(isX("The king is a fink!")));
//..

#include <bslscm_version.h>

#include <bslmf_addrvaluereference.h>

#include <bsls_compilerfeatures.h>
#include <bsls_platform.h>

namespace BloombergLP {
namespace bslmf {

                        // ==================
                        // class MatchAnyType
                        // ==================

struct MatchAnyType {
    // Any type can be converted into this type.

    template <class t_TYPE>
    MatchAnyType(const t_TYPE&)
    {
    }                                                               // IMPLICIT
    // This constructor will match any rvalue or any non-volatile lvalue.  A
    // non-'const' version of this constructor is not necessary and will cause
    // some compilers to complain of ambiguities.

    template <class t_TYPE>
    MatchAnyType(const volatile t_TYPE&)
    {
    }                                                               // IMPLICIT
        // This constructor will match any volatile lvalue.  According to the
        // standard, it should NOT match an rvalue.  A non-'const' version of
        // this constructor is not necessary and will cause some compilers to
        // complain of ambiguities.
};

                        // =============
                        // class TypeRep
                        // =============

#if defined(BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES)
template <class t_TYPE>
struct TypeRep {
    // Generate a reference to 't_TYPE' for use in meta-functions.

    //    static t_TYPE&& rep();
    static typename bsl::add_rvalue_reference<t_TYPE>::type rep();
        // Provide a reference to a 't_TYPE' object.  This function has no body
        // and must never be called at run time.  Thus, it does not matter if
        // 't_TYPE' has a default constructor or not.
};
#else
template <class t_TYPE>
struct TypeRep {
    // Generate a reference to 't_TYPE' for use in meta-functions.

    static t_TYPE& rep();
        // Provide a reference to a 't_TYPE' object.  This function has no body
        // and must never be called at run time.  Thus, it does not matter if
        // 't_TYPE' has a default constructor or not.
};

template <class t_TYPE>
struct TypeRep<t_TYPE&> {
    // Generate a reference to 't_TYPE' for use in meta-functions.  This is a
    // partial specialization of 'TypeRep' instantiated with a reference.

    static t_TYPE& rep();
        // Provide a reference to a 't_TYPE' object.  This function has no body
        // and must never be called at run time.  Thus, it does not matter if
        // 't_TYPE' has a default constructor or not.
};
#endif

}  // close package namespace

#ifndef BDE_OPENSOURCE_PUBLICATION  // BACKWARD_COMPATIBILITY
// ============================================================================
//                           BACKWARD COMPATIBILITY
// ============================================================================

#ifdef bslmf_TypeRep
#undef bslmf_TypeRep
#endif
#define bslmf_TypeRep bslmf::TypeRep
    // This alias is defined for backward compatibility.

typedef bslmf::MatchAnyType bslmf_AnyType;
    // This alias is defined for backward compatibility.
#endif  // BDE_OPENSOURCE_PUBLICATION -- BACKWARD_COMPATIBILITY

}  // close enterprise namespace

#endif

// ----------------------------------------------------------------------------
// Copyright 2013 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
