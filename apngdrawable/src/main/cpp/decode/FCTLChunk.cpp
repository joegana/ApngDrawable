//
// Created by Justin on 2023/5/16.
//

#include "decode/FCTLChunk.h"
namespace apng{

    void FCTLChunk::innerParse(UApngReader reader)  {
        setSequenceNumber(reader->readInt());
        setWidth(reader->readInt());
        setHeight(reader->readInt());
        setXOffset(reader->readInt());
        setYOffset(reader->readInt());
        setDelayNum(reader->readShort());
        setDelayDen(reader->readShort());
        setDisposeOp(reader->peek());
        setBlendOp(reader->peek());
    }
}
