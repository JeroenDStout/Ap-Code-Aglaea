/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include "BlackRoot/Pubc/Number Types.h"

namespace Aglaea {
namespace Raw {

    using TypeUUID = uint128;

    class ISluiceSeq;

    class IKeeper {
    public:
        virtual bool supports_seq_type(TypeUUID) = 0;
    };

    class ISluice {
    public:

    };

    class ISluiceSeq {
    public:
        virtual const TypeUUID & get_seq_type() = 0;
        virtual const char *     get_seq_name() = 0;
    };

    class ISluiceSeqWriter {
    public:
    };

}
}