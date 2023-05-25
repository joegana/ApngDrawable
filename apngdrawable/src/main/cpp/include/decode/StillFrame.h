//
// Created by Justin on 2023/5/23.
//

#ifndef APNGDRAWABLE_STILLFRAME_H
#define APNGDRAWABLE_STILLFRAME_H

#include "APNGFrame.h"

namespace apng{
    class StillFrame:public APNGFrame{
    public:
        StillFrame(UApngReader rd);

    private:
        StillFrame(StillFrame & frame) = delete ;
        StillFrame & operator=(StillFrame & frame) = delete;
    };
}

#endif //APNGDRAWABLE_STILLFRAME_H
