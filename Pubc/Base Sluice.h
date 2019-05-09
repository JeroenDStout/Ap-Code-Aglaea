/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <set>

#include "BlackRoot/Pubc/Hash.h"

#include "Aglaea/Pubc/Raw Sluice.h"

namespace Aglaea {

    class BaseKeeper : public Raw::IKeeper {
    public:
        struct SupportedSluiceSeq {
            std::set<Raw::TypeUUID>  UUIDs;
            std::vector<std::string> Names;
        };
    };

    class BaseSluiceSeq : public Raw::ISluiceSeq {
    public:
    };

    namespace Helper {
    
        struct BaseKeeperSupportsSeqVersionReg {
            BaseKeeperSupportsSeqVersionReg(BaseKeeper::SupportedSluiceSeq * support, const char * name) {
                support->UUIDs.insert(BlackRoot::Identify::fnv1a_128(name, strlen(name)));
                support->Names.push_back(name);
            }
        };

        struct BaseSluiceSeqVersionReg {
            BaseSluiceSeqVersionReg(Aglaea::Raw::TypeUUID * set_uuid, std::string * set_name, const char * name) {
                *set_uuid = BlackRoot::Identify::fnv1a_128(name, strlen(name));
                *set_name = name;
            }
        };

    }

#define AG_DECLARE_KEEPER(type, name, base) \
    public: \
    using BaseType = base; \
    \
    static BaseType::SupportedSluiceSeq __SupportedSluiceSeq##name; \
    \
    bool supports_seq_type(Raw::TypeUUID id) override { \
        auto fi = __SupportedSluiceSeq##name.UUIDs.find(id); \
        return fi != __SupportedSluiceSeq##name.UUIDs.end(); \
    }
    
#define AG_DECLARE_SLUICE_SEQ(type, name, base) \
    public: \
    using BaseType = base; \
    \
    static Aglaea::Raw::TypeUUID _SluiceSeqVersionUUID_##name; \
    static std::string           _SluiceSeqVersionName_##name; \
    \
    const Aglaea::Raw::TypeUUID & get_seq_type() override { \
        return _SluiceSeqVersionUUID_##name; \
    } \
    \
    const char * get_seq_name() override { \
        return _SluiceSeqVersionName_##name.c_str(); \
    }

#define AG_REG_NAME_GEN(nspace, name, version) (nspace " " #name " " version)

#define CONCAT_IMPL(x, y) x##y
#define MACRO_CONCAT(x, y) CONCAT_IMPL(x, y)

#define AG_REG_SLUICE_SEQ(type, nspace, name, version) \
    static Aglaea::Helper::BaseSluiceSeqVersionReg _BaseSluiceSeqVersionReg##name( \
        &(type::_SluiceSeqVersionUUID_##name), &(type::_SluiceSeqVersionName_##name), AG_REG_NAME_GEN(nspace, name, version));
    
#define AG_REG_KEEPER(type, name) \


#define AG_REG_KEEPER_SUPPORTS_SEQ_VERSION(keeper, nspace, name, version) \
    static Aglaea::Helper::BaseKeeperSupportsSeqVersionReg _BaseKeeperSupportsSeqVersionReg##name( \
        &(keeper::__SupportedSluiceSeq##keeper), AG_REG_NAME_GEN(nspace, name, version));



}


