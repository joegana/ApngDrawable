//
// Created by Justin on 2023/5/23.
//

#include "decode/StillFrame.h"
namespace apng{
    StillFrame::StillFrame(UApngReader rd): APNGFrame(std::move(rd)) {
    }
}