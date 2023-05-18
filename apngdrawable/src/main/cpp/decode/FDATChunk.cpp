//
// Created by admin on 2023/5/16.
//

#include "decode/FDATChunk.h"

namespace  apng{
    void FDATChunk::innerParse(ApngReader *reader) {
        setSequenceNumber(reader->readInt());
    }
}