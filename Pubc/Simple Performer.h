/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <vector>

#include "BlackRoot/Pubc/Number Types.h"

#include "Aglaea/Pubc/Create Sluice.h"
#include "Aglaea/Pubc/Base Sluice.h"

namespace Aglaea {
namespace Util {

    class SimplePerformer : BaseKeeper {
        AG_DECLARE_KEEPER(SimplePerformer, SimplePerformer, BaseKeeper);

    public:
            // Sluice seq

        class SluiceSeq : public BaseSluiceSeq {
            AG_DECLARE_SLUICE_SEQ(SluiceSeq, SimplePerformerSluiceSeq, BaseSluiceSeq);
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

            template<typename f>
            ret & perform(f);

            template<typename f>
            ret & upon_fail_perform(f);
        };
    };

}
}