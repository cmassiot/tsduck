//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2023, Thierry Lelegard
// BSD-2-Clause license, see LICENSE.txt file or https://tsduck.io/license
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Forward declarations for MPEG PSI/SI types.
//!  Useful to avoid interdependencies of header files.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsSafePtr.h"
#include "tsPSI.h"

namespace ts {

    class AbstractDescriptor;
    class AbstractTable;
    class BinaryTable;
    class Descriptor;
    class DescriptorList;
    class PSIBuffer;
    class Section;
    class TablesDisplay;

    //!
    //! Safe pointer for AbstractDescriptor (not thread-safe).
    //!
    using AbstractDescriptorPtr = SafePtr<AbstractDescriptor, ts::null_mutex>;

    //!
    //! Vector of AbstractDescriptor pointers
    //!
    using AbstractDescriptorPtrVector = std::vector<AbstractDescriptorPtr>;

    //!
    //! Safe pointer for AbstractTable (not thread-safe)
    //!
    using AbstractTablePtr = SafePtr<AbstractTable, ts::null_mutex>;

    //!
    //! Safe pointer for Section (not thread-safe).
    //!
    using SectionPtr = SafePtr<Section, ts::null_mutex>;

    //!
    //! Vector of Section pointers.
    //!
    using SectionPtrVector = std::vector<SectionPtr>;

    //!
    //! Vector of BinaryTable pointers
    //!
    using AbstractTablePtrVector = std::vector<AbstractTablePtr>;

    //!
    //! Safe pointer for BinaryTable (not thread-safe)
    //!
    using BinaryTablePtr = SafePtr<BinaryTable, ts::null_mutex>;

    //!
    //! Vector of BinaryTable pointers
    //!
    using BinaryTablePtrVector = std::vector<BinaryTablePtr>;

    //!
    //! Safe pointer for Descriptor (not thread-safe)
    //!
    using DescriptorPtr = SafePtr<Descriptor, ts::null_mutex>;

    //!
    //! Vector of Descriptor pointers
    //! Use class DescriptorList for advanced features.
    //! @see DescriptorList
    //!
    using DescriptorPtrVector = std::vector<DescriptorPtr>;

    //!
    //! Profile of a function to display a section.
    //! Each subclass of AbstractTable should provide a static function named
    //! @e DisplaySection which displays a section of its table-id.
    //!
    //! @param [in,out] display Display engine.
    //! @param [in] section The section to display.
    //! @param [in,out] payload A read-only PSIBuffer over the section payload.
    //! Everything that was not read from the buffer will be displayed by the
    //! caller as "extraneous data". Consequently, the table subclasses do
    //! not have to worry about those extraneous data.
    //! @param [in] margin Left margin content.
    //!
    using DisplaySectionFunction = void (*)(TablesDisplay& display, const Section& section, PSIBuffer& payload, const UString& margin);

    //!
    //! Profile of a function to display a brief overview ("log") of a section on one line.
    //! A subclass of AbstractTable may provide a static function for this.
    //!
    //! @param [in] section The section to log.
    //! @param [in] max_bytes Maximum number of bytes to log from the section. 0 means unlimited.
    //! @return A one-line brief summary of the table.
    //!
    using LogSectionFunction = UString (*)(const Section& section, size_t max_bytes);

    //!
    //! Profile of a function to display a descriptor.
    //! Each subclass of AbstractDescriptor should provide a static function named
    //! @e DisplayDescriptor which displays a descriptor of its type.
    //!
    //! @param [in,out] display Display engine.
    //! @param [in,out] payload A read-only PSIBuffer over the descriptor payload.
    //! For "extended descriptors", the buffer starts after the "extension tag".
    //! Everything that was not read from the buffer will be displayed by the
    //! caller as "extraneous data". Consequently, the descriptor subclasses do
    //! not have to worry about those extraneous data.
    //! @param [in] margin Left margin content.
    //! @param [in] did Descriptor id.
    //! @param [in] tid Table id of table containing the descriptors.
    //! This is optional. Used by some descriptors the interpretation of which may
    //! vary depending on the table that they are in.
    //! @param [in] pds Private Data Specifier. Used to interpret private descriptors.
    //!
    using DisplayDescriptorFunction = void (*)(TablesDisplay& display, PSIBuffer& payload, const UString& margin, DID did, TID tid, PDS pds);

    //!
    //! Profile of a function to display the private part of a CA_descriptor.
    //!
    //! @param [in,out] display Display engine.
    //! @param [in,out] private_part A read-only PSIBuffer over the private part of a CA_descriptor.
    //! @param [in] margin Left margin content.
    //! @param [in] tid Table id of table containing the descriptors (typically CAT or PMT).
    //!
    using DisplayCADescriptorFunction = void (*)(TablesDisplay& display, PSIBuffer& private_part, const UString& margin, TID tid);
}

//!
//! @hideinitializer
//! Define a DisplaySection static function.
//!
#define DeclareDisplaySection()                                  \
    /** A static method to display a section.                 */ \
    /** @param [in,out] display Display engine.               */ \
    /** @param [in] section The section to display.           */ \
    /** @param [in,out] payload A PSIBuffer over the payload. */ \
    /** @param [in] margin Left margin content.               */ \
    static void DisplaySection(ts::TablesDisplay& display, const ts::Section& section, ts::PSIBuffer& payload, const ts::UString& margin)

//!
//! @hideinitializer
//! Define a LogSection static function.
//!
#define DeclareLogSection()                                      \
    /** A static method to log a section.                     */ \
    /** @param [in] section The section to log.               */ \
    /** @param [in] max_bytes Maximum number of bytes to log. */ \
    static ts::UString LogSection(const ts::Section& section, size_t max_bytes)

//!
//! @hideinitializer
//! Define a DisplayDescriptor static function.
//!
#define DeclareDisplayDescriptor()                                       \
    /** Static method to display a descriptor.                        */ \
    /** @param [in,out] display Display engine.                       */ \
    /** @param [in,out] payload A PSIBuffer over the payload.         */ \
    /** @param [in] margin Left margin content.                       */ \
    /** @param [in] did Descriptor id.                                */ \
    /** @param [in] tid Table id of table containing the descriptors. */ \
    /** @param [in] pds Private Data Specifier.                       */ \
    static void DisplayDescriptor(ts::TablesDisplay& display, ts::PSIBuffer& payload, const ts::UString& margin, ts::DID did, ts::TID tid, ts::PDS pds)
