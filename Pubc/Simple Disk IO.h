/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include "BlackRoot/Pubc/Files.h"

#include "Aglaea/Pubc/Abstract Memory.h"
#include "Aglaea/Pubc/Create Sluice.h"
#include "Aglaea/Pubc/Base Sluice.h"

namespace Aglaea {
namespace Util {

    class SimpleDiskIO : BaseKeeper {
        AG_DECLARE_KEEPER(SimpleDiskIO, SimpleDiskIO, BaseKeeper);

    public:
            // Sluice seq

        class SluiceSeq : public BaseSluiceSeq {
            AG_DECLARE_SLUICE_SEQ(SluiceSeq, SimpleDiskIOSluiceSeq, BaseSluiceSeq);
        };

            // Create sluice seq

        template<typename base>
        class ImplCreateSluiceSeq : public CreateSluiceSeq<base>
        {
            AG_CS_DECLARE_CREATE_SLUICE(ImplCreateSluiceSeq, base);

        protected:
            Raw::ISluiceSeq * internal_render_final_seq() override;

        public:
            ImplCreateSluiceSeq(base * cs)
            : CreateSluiceSeq(cs) { ; }
            
            ret & disk_path_to_ram(BlackRoot::IO::FilePath, Util::IRAM **);
            ret & ram_to_disk(BlackRoot::IO::FilePath, const Util::RAMDesc *);
        };
    };

}
}