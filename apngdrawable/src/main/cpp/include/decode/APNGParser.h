//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_APNGPARSER_H
#define APNGDRAWABLE_APNGPARSER_H

#include <vector>
#include <memory>
#include "Chunk.h"
#include "ACTLChunk.h"
#include "FCTLChunk.h"
#include "FDATChunk.h"
#include "IDATChunk.h"
#include "IENDChunk.h"
#include "IHDRChunk.h"
#include "io/ApngReader.h"

namespace apng {

    class APNGParser {
        public:
             static  VChunk parse(UApngReader reader);
        private:
            static UChunk parseChunk(UApngReader reader);
    };
}


#endif //APNGDRAWABLE_APNGPARSER_H
