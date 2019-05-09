/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <vector>

#include "Aglaea/Pubc/Raw Sluice.h"

namespace Aglaea {

    template<typename memory_type>
    class CreateSluiceCore {
    public:
        using CS = CreateSluiceCore<memory_type>;

        memory_type * memory_reference;

        struct InnerContext {
            memory_type data;
        };
        InnerContext Context;

        void internal_push_seq(Raw::ISluiceSeq *);
        Raw::ISluice * internal_finalise();

    public:
        CreateSluiceCore();

        template<typename t>
        auto with(t*) {
            return t::ImplCreateSluiceSeq<CS>(this);
        }

        CS & done_after_success();
    };

    template<typename memory_type>
    class CreateSluice : public CreateSluiceCore<memory_type> {
    public:
        CreateSluice();

        using CS = typename CreateSluice<memory_type>::CS;

        CS & using_memory_ref(memory_type * data) {
            this->memory_reference = data;
        }
    };

    template<typename base>
    class CreateSluiceSeq {
    protected:
        base * ref_create_sluice;

        virtual Raw::ISluiceSeq * internal_render_final_seq() = 0;

    public:
        CreateSluiceSeq(base * cs)
        : ref_create_sluice(cs) { ; }

        template<typename t>
        auto with(t * ptr) {
            ref_create_sluice->internal_push_seq(this->internal_render_final_seq());
            return ref_create_sluice->with(ptr);
        }

        auto done_after_success() {
            ref_create_sluice->internal_push_seq(this->internal_render_final_seq());
            return ref_create_sluice->internal_finalise();
        }
    };

    namespace Helper {
        
    }

#define AG_CS_DECLARE_CREATE_SLUICE(type, base) \
    public: \
    using BaseType = base; \
    using ret = type<base>; \
    using SluiceType = typename base::CS;

}