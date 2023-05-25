//
// Created by Justin on 2023/5/16.
//

#ifndef APNGDRAWABLE_IHDRCHUNK_H
#define APNGDRAWABLE_IHDRCHUNK_H

#include "Chunk.h"

/**
 * The IHDR chunk shall be the first chunk in the PNG datastream. It contains:
 * Width	4 bytes
 * Height	4 bytes
 * Bit depth	1 byte
 * Colour type	1 byte
 * Compression method	1 byte
 * Filter method	1 byte
 * Interlace method	1 byte
 */
namespace apng {
    class IHDRChunk: public Chunk{
         public:
            static const size_t  ID = fourCCToInt('I','H','D','R');

            void setWidth(size_t w){
                this->width = w ;
            }
            size_t getWidth(){
                return this->width;
            }

            void setHeight(size_t h){
                this->height = h ;
            }
            size_t getHeight(){
                return this->height;
            }

            uint8_t * getIHDRData(){
                return data;
            }

         public:
             IHDRChunk(){};

         protected:
            virtual void innerParse(UApngReader reader);

         private:
             IHDRChunk(IHDRChunk & chunk) = delete;
             size_t width ;
             size_t height;
             uint8_t data[5];
    };
}


#endif //APNGDRAWABLE_IHDRCHUNK_H
