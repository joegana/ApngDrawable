//
// Created by admin on 2023/5/16.
//

#include "decode/IHDRChunk.h"
namespace apng{
    void IHDRChunk::innerParse(ApngReader *reader) {
        setWidth(reader->readInt());
        setHeight(reader->readInt());
        reader->read(getIHDRData(),0,5);
    }
}