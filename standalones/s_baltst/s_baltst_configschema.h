// s_baltst_configschema.h          *DO NOT EDIT*          @generated -*-C++-*-
#ifndef INCLUDED_S_BALTST_CONFIGSCHEMA
#define INCLUDED_S_BALTST_CONFIGSCHEMA

#include <bsls_ident.h>
BSLS_IDENT_RCSID(s_baltst_configschema_h, "$Id$ $CSID$")
BSLS_IDENT_PRAGMA_ONCE

//@PURPOSE: Provide the  service configuration schema
//
//@CLASSES:
// s_baltst::ConfigSchema: the  configuration schema
//
//@DESCRIPTION: This component provides a namespace for the 
// service configuration schema.  This in-core representation of the schema
// is used to validate XML configuration data used to initialize the service.

#include <bsl_ostream.h>

namespace BloombergLP {
namespace s_baltst {

struct ConfigSchema {
    // Provide a namespace for the  service configuration schema.

    static const char TEXT[];    // service configuration schema
};

// FREE OPERATORS
bsl::ostream& operator<<(bsl::ostream& stream, const ConfigSchema& schema);
    // Write the specified 'schema' to the specified 'stream', and return
    // a modifiable reference to 'stream'.

}  // close namespace s_baltst

// FREE OPERATORS
inline
bsl::ostream& s_baltst::operator<<(
    bsl::ostream& stream,
    const s_baltst::ConfigSchema& schema)
{
    return stream << schema.TEXT;
}

}  // close namespace BloombergLP
#endif

// GENERATED BY @BLP_BAS_CODEGEN_VERSION@
// USING bas_codegen.pl --mode cfg --includeDir . --configSchema y s_baltst_configschema.xsd
// ----------------------------------------------------------------------------
// NOTICE:
//      Copyright 2022 Bloomberg Finance L.P. All rights reserved.
//      Property of Bloomberg Finance L.P. (BFLP)
//      This software is made available solely pursuant to the
//      terms of a BFLP license agreement which governs its use.
// ------------------------------- END-OF-FILE --------------------------------
