/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <string>

namespace Aglaea {
namespace Util {

    struct RAMDesc {
        void * data;
        size_t length;

        RAMDesc& operator <= (const std::string);
    };

    class IRAM {
    public:
        RAMDesc desc;

        virtual void release() = 0;
    };

}
}