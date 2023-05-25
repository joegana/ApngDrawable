//
// Created by Justin on 2023/5/16.
//

#ifndef APNGDRAWABLE_APNGFRAME_H
#define APNGDRAWABLE_APNGFRAME_H
#include <stdint.h>
#include <vector>
#include <android/bitmap.h>
#include "Chunk.h"
#include "FCTLChunk.h"
#include "IDATChunk.h"
#include "ACTLChunk.h"
#include "FDATChunk.h"
#include "IENDChunk.h"
#include "IHDRChunk.h"
#include "Crc32.h"

namespace apng {
    class APNGFrame;
    using UApngFrame  = std::unique_ptr<APNGFrame>;
    using VUApngFrame = std::vector<UApngFrame> ;
    using UVApngFrame = std::unique_ptr<VUApngFrame> ;
    class APNGFrame {
    public:
        explicit APNGFrame(UApngReader reader);
        explicit APNGFrame(UApngReader reader,UFCTLChunk fctlChunk);

        size_t getFrameWidth(){
            return frameWidth;
        }
        void setFrameWidth(size_t frameWidth){
            this->frameWidth = frameWidth;
        }

        size_t getFrameHeight(){
            return this->frameHeight;
        }
        void setFrameHeight(size_t frameHeight){
            this->frameHeight = frameHeight;
        }

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
                this->imageChunks.push_back(std::move(chunk));
            }
        }

        void addPrefixChunk(std::unique_ptr<Chunk> chunk){
            if(chunk){
                this->prefixChunks.push_back(std::move(chunk));
            }
        }

    private:
        size_t encode(UApngWriter  reader);

    protected:
        UReader reader ;
        size_t frameWidth;
        size_t frameHeight;
    private:
        APNGFrame(APNGFrame & frame) = delete ;
        APNGFrame & operator=(APNGFrame & frame) = delete;
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
