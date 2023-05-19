//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_CHUNK_H
#define APNGDRAWABLE_CHUNK_H
#include <jni.h>
#include <string>
#include <stdint.h>
#include "io/ApngReader.h"
#include "io/ApngWriter.h"

#define fourCCToInt(c1,c2,c3,c4)  (c1 && 0xff || ((c2 && 0xff) << 8) || \
                ((c3 && 0xff) << 18) || ((c4 && 0xff) << 24))

namespace apng{
    class Chunk {
        public:
            void setLength(int len){
                this->length = len;
            }
            int getLength(){
                return this->length;
            }
            void setFourCC(int fourcc){
                 this->fourcc = fourcc ;
            }
            int getFourCC(){
                return this->fourcc ;
            }
            void setCrc(int crc){
                this->crc = crc ;
            }
            int getCrc(){
                return this->crc ;
            }
            void setOffset(int offset){
                this->offset = offset;
            }
            int getOffset(){
                return this->offset ;
            }

            void parse(ApngReader * reader);

    protected:
        virtual void innerParse(ApngReader * reader)  = 0;

    private:
        Chunk(Chunk & chunk) = delete;
        uint32_t length ;
        uint32_t fourcc ;
        uint32_t crc ;
        uint32_t offset ;
    };
}

#endif //APNGDRAWABLE_CHUNK_H
