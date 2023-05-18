//
// Created by admin on 2023/5/16.
//

#include "decode/APNGFrame.h"
namespace apng{
    APNGFrame::APNGFrame(ApngReader *reader, FCTLChunk *fctlChunk) {
        assert(reader);
        assert(fctlChunk);
        this->reader = reader;
        this->blend_op = fctlChunk->getBlendOp();
        this->dispose_op = fctlChunk->getDisposeOp();
        auto delayDen = fctlChunk->getDelayDen();
        size_t during = fctlChunk->getDelayNum() * 1000 / (delayDen?delayDen:100);
        if(during < 10){
            during = 100 ;
        }
        this->frameDuring = during;
        this->frameWidth = fctlChunk->getWidth();
        this->frameHeight = fctlChunk->getHeight();
        this->frameX = fctlChunk->getXOffset();
        this->frameY = fctlChunk->getYOffset();
    }
    int APNGFrame::encode(ApngWriter *writer) {
        assert(writer);
        size_t fSize = 8 + 13 + 12 ;

        for(auto & chunk:prefixChunks){
            fSize += chunk->getLength() + 12 ;
        }
        IDATChunk* idat ;
        FDATChunk* fdat ;
        for(auto & chunk:imageChunks){
            idat = dynamic_cast<IDATChunk*>(chunk.get());
            fdat = dynamic_cast<FDATChunk*>(chunk.get());
            if(idat){
                fSize += idat->getLength() + 12 ;
            }
            if(fdat){
                fSize += fdat->getLength() + 8 ;
            }
        }
        fSize += sizeof(sPNGEndChunk);
        writer->reset(fSize);
        writer->putBytes(sPNGSignatures,sizeof(sPNGSignatures));
        //IHDR Chunk
        writer->putInt(13);
        size_t start = writer->position();
        writer->putFourCC(IHDRChunk::ID);
        writer->putInt(frameWidth);
        writer->putInt(frameHeight);
        writer->putBytes(ihdrData,sizeof(ihdrData));
        // 计算CRC
        size_t crc = 0 ;
        writer->putInt(crc);

        assert(reader);
        //prefix Chunk
        for(auto & chunk: prefixChunks){
            if(dynamic_cast<IENDChunk*>(chunk.get()) != NULL){
                continue;
            }
            reader->reset();
            reader->skip(chunk->getOffset());
            reader->read(writer->toByteArray(),writer->position(),chunk->getLength() + 12);
            writer->skip(chunk->getLength() + 12);
        }

        //image Chunks
        for(auto & chunk:imageChunks){
            if(dynamic_cast<IDATChunk*>(chunk.get()) != NULL) {
                reader->reset();
                reader->skip(chunk->getOffset());
                reader->read(writer->toByteArray(), writer->position(),
                             chunk->getLength() + 12);
                writer->skip(chunk->getLength() + 12);
            }else if(dynamic_cast<FDATChunk*>(chunk.get()) != NULL){
                writer->putInt(chunk->getLength() + 12);
                start = writer->position();
                writer->putFourCC(IDATChunk::ID);

                reader->reset();
                //skip to fdat data position
                reader->skip(chunk->getOffset() + 4 + 4 + 4 );
                reader->read(writer->toByteArray(),writer->position(),chunk->getLength() - 4);

                writer->skip(chunk->getLength() - 4);
                // 计算CRC
                crc = 0 ;
                writer->putInt(crc);
            }
        }
        writer->putBytes(sPNGEndChunk,sizeof(sPNGEndChunk));
        return fSize;
    }
}