// bsl_typeindex.h                                                    -*-C++-*-
#ifndef INCLUDED_BSL_TYPEINDEX
#define INCLUDED_BSL_TYPEINDEX

#include <bsls_ident.h>
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide functionality of the corresponding C++ Standard header.
//
//@SEE_ALSO: package bos+stdhdrs in the bos package group
//
//@DESCRIPTION: Provide types, in the 'bsl' namespace, equivalent to those
// defined in the corresponding C++ standard header.  Include the native
// compiler-provided standard header, and also directly include Bloomberg's
// implementation of the C++ standard type (if one exists).  Finally, place the
// included symbols from the 'std' namespace (if any) into the 'bsl' namespace.

#include <bsls_compilerfeatures.h>
#include <bsls_libraryfeatures.h>

#ifndef BDE_DONT_ALLOW_TRANSITIVE_INCLUDES
#include <bsls_nativestd.h>
#endif // BDE_DONT_ALLOW_TRANSITIVE_INCLUDES

#if defined(BSLS_LIBRARYFEATURES_HAS_CPP11_BASELINE_LIBRARY)
# if defined(BSLS_COMPILERFEATURES_SUPPORT_HAS_INCLUDE)
// The unordered containers are a feature of the C++11 library, rather than
// C++03, so might not be present in all native libraries on the platforms we
// support.  Detect the native header using '__has_include' where available.
#   if __has_include(<typeindex>)
#     include <typeindex>
#   endif
# else
#   include <typeindex>
# endif
#endif

// Include Bloomberg's implementation.
#include <bslstl_typeindex.h>

#endif  // INCLUDED_BSL_TYPEINDEX

// ----------------------------------------------------------------------------
// Copyright 2019 Bloomberg Finance L.P.
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
