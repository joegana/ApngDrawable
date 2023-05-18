//
// Created by admin on 2023/5/16.
//

#include "decode/ACTLChunk.h"
namespace apng{

    void ACTLChunk::innerParse(ApngReader *reader)  {
        size_t n = reader->readInt();
        setNumFrames(n);
        n = reader->readInt();
        setNumPlays(n);
    }
}