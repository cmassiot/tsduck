//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2019, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Representation of an ATSC dcc_arriving_request_descriptor.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsAbstractDescriptor.h"
#include "tsATSCMultipleString.h"

namespace ts {
    //!
    //! Representation of an ATSC dcc_arriving_request_descriptor.
    //! @see ATSC A/65, section 6.9.11.
    //! @ingroup descriptor
    //!
    class TSDUCKDLL DCCArrivingRequestDescriptor : public AbstractDescriptor
    {
    public:
        // Public members:
        uint8_t            dcc_arriving_request_type;  //!< Request type.
        ATSCMultipleString dcc_arriving_request_text;  //!< Request name.

        //!
        //! Default constructor.
        //!
        DCCArrivingRequestDescriptor();

        //!
        //! Constructor from a binary descriptor
        //! @param [in,out] duck TSDuck execution context.
        //! @param [in] bin A binary descriptor to deserialize.
        //!
        DCCArrivingRequestDescriptor(DuckContext& duck, const Descriptor& bin);

        // Inherited methods
        virtual void serialize(DuckContext&, Descriptor&) const override;
        virtual void deserialize(DuckContext&, const Descriptor&) override;
        virtual void fromXML(DuckContext&, const xml::Element*) override;
        DeclareDisplayDescriptor();

    protected:
        // Inherited methods
        virtual void buildXML(DuckContext&, xml::Element*) const override;
    };
}
