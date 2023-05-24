//
// Created by admin on 2023/5/16.
//

#include "decode/Chunk.h"
namespace apng{
    void Chunk::parse(UApngReader reader) {
        size_t available = reader->available();
        innerParse(std::move(reader));
        size_t offset = available - reader->available() ;
        if(offset > length){
            throw "Out of chunk area";
        }else if(offset < length){
            reader->skip(length - offset);
        }
    }
}