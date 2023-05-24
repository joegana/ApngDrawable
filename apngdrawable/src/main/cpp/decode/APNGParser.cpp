//
// Created by admin on 2023/5/16.
//

#include "decode/APNGParser.h"
namespace apng{
    VChunk APNGParser::parse(UApngReader reader) {
        assert(reader && reader.get());
        VChunk ret = std::make_unique<VVector>();
        while(reader->available() > 0 )
        {
            ret->push_back(parseChunk(std::move(reader)));
        }
        return ret;
    }

    UChunk APNGParser::parseChunk(UApngReader reader) {
        size_t offset = reader->position();
        size_t size  = reader->readInt();
        size_t fourCC = reader->readFourCC();
        UChunk chunk ;
        if(fourCC == ACTLChunk::ID){
            chunk = std::make_unique<ACTLChunk>();
        }else if(fourCC == FCTLChunk::ID){
            chunk = std::make_unique<FCTLChunk>();
        }else if(fourCC == FDATChunk::ID){
            chunk = std::make_unique<FDATChunk>();
        }else if(fourCC == IDATChunk::ID){
            chunk = std::make_unique<IDATChunk>();
        }else if(fourCC == IENDChunk::ID){
            chunk = std::make_unique<IENDChunk>();
        }else if(fourCC == IHDRChunk::ID){
            chunk = std::make_unique<IHDRChunk>();
        }else {
            chunk = std::make_unique<Chunk>();
        }
        chunk->setOffset(offset);
        chunk->setFourCC(fourCC);
        chunk->setLength(size);
        chunk->parse(std::move(reader));
        chunk->setCrc(reader->readInt());
        return chunk;
    }

}