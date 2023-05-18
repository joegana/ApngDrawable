//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_APNGFRAME_H
#define APNGDRAWABLE_APNGFRAME_H
#include <stdint.h>
#include <vector>
#include <android/bitmap.h>
#include "decode/Chunk.h"
#include "decode/FCTLChunk.h"
#include "decode/IDATChunk.h"
#include "decode/ACTLChunk.h"
#include "decode/FDATChunk.h"
#include "decode/IENDChunk.h"
#include "decode/IHDRChunk.h"

namespace apng {
    class APNGFrame {
    public:
        APNGFrame(ApngReader * reader,FCTLChunk * fctlChunk);

        void setBlendOp(uint8_t blendOp){
            this->blend_op = blendOp;
        }
        uint8_t getBlendOp(){
            return this->blend_op;
        }

        void setDisposeOp(uint8_t disposeOp){
            this->dispose_op = disposeOp;
        }
        uint8_t getDisposeOp(){
            return this->dispose_op;
        }

        void setIHDRData(uint8_t* data,size_t len){
            if(data){
                if(len > sizeof(ihdrData)){
                    len = sizeof(ihdrData);
                }
                memcpy(ihdrData,data,len);
            }
        }

        void addImageChunk(std::unique_ptr<Chunk> chunk){
            if(chunk){
                this->imageChunks.push_back(chunk);
            }
        }

        void addPrefixChunk(std::unique_ptr<Chunk> chunk){
            if(chunk){
                this->prefixChunks.push_back(chunk);
            }
        }


    private:
        size_t encode(ApngWriter * reader);

    private:
        Reader * reader ;
        size_t frameWidth;
        size_t frameHeight;
        size_t frameX;
        size_t frameY;
        size_t frameDuring ;
        uint8_t blend_op ;
        uint8_t dispose_op;
        uint8_t ihdrData[5];
        std::vector<std::unique_ptr<Chunk>> imageChunks;
        std::vector<std::unique_ptr<Chunk>> prefixChunks;
        constexpr static const uint8_t sPNGSignatures[] =
                {137,80,78,71,13,10,26,10};
        constexpr static const uint8_t sPNGEndChunk[] =
                {0, 0, 0, 0, 0x49, 0x45, 0x4E,
                 0x44, 0xAE, 0x42, 0x60,  0x82};
    };
}



#endif //APNGDRAWABLE_APNGFRAME_H
