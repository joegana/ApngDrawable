//
// Created by admin on 2023/5/16.
//

#include "decode/FDATChunk.h"

namespace  apng{
    void FDATChunk::innerParse(UApngReader reader) {
        setSequenceNumber(reader->readInt());
    }
}