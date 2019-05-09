/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
 
 #include "Aglaea/Pubc/Simple Performer.h"

 using namespace Aglaea::Util;

 AG_REG_SLUICE_SEQ(SimplePerformer::SluiceSeq, __PROJECTSTR__, SimplePerformerSluiceSeq, "v0.0.1");

 AG_REG_KEEPER(SimplePerformer, SimplePerformer);
 AG_REG_KEEPER_SUPPORTS_SEQ_VERSION(SimplePerformer, __PROJECTSTR__, SimplePerformerSluiceSeq, "v0.0.1");