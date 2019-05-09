/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
 
 #include "Aglaea/Pubc/Simple Disk IO.h"

 using namespace Aglaea::Util;

 AG_REG_SLUICE_SEQ(SimpleDiskIO::SluiceSeq, __PROJECTSTR__, SimpleDiskIOSluiceSeq, "v0.0.1");

 AG_REG_KEEPER(SimpleDiskIO, SimpleDiskIO);
 AG_REG_KEEPER_SUPPORTS_SEQ_VERSION(SimpleDiskIO, __PROJECTSTR__, SimpleDiskIOSluiceSeq, "v0.0.1");