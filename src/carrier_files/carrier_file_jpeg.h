//
//  CarrierFileJPEG.h
//  StegoFS
//
//  Created by Martin Kosdy on 1/9/13.
//  Copyright (c) 2013 Martin Kosdy. All rights reserved.
//

#ifndef STEGODISK_CARRIERFILES_CARRIERFILEJPEG_H_
#define STEGODISK_CARRIERFILES_CARRIERFILEJPEG_H_

#include <iostream>
#include <string>
#include <stdint.h>

#include "carrier_file.h"
#include "logging/logger.h"


// jpeglib must be includes AFTER all precedense files
// because in VS2010 is included BaseTsd.h, which defines INT32 type
// which one conflicts with definition in jpeglib.h
#include <jpeglib.h>
#include <jerror.h>

using namespace std;

namespace stego_disk {

class CarrierFileJPEG : public CarrierFile {

private:
  int ComputeCapacity();

public:
  CarrierFileJPEG(File file, std::shared_ptr<Encoder> encoder);

  int LoadFile();
  int SaveFile();

  int GetHistogram();

};

} // stego_disk

#endif // STEGODISK_CARRIERFILES_CARRIERFILEJPEG_H_