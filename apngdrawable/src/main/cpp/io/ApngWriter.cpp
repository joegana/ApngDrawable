//
// Created by Justin on 2023/5/16.
//

#include "io/ApngWriter.h"

namespace apng{
    void ApngWriter::reset(size_t size) {
        if(this->size < size){
            if(fbuf){
                free(fbuf);
                fbuf = nullptr ;
            }
            this->size = size;
            fbuf = static_cast<uint8_t *>(malloc(size));
        }
    }
    void ApngWriter::close() {
        if(this->fbuf){
            free(this->fbuf);
            this->fbuf = nullptr;
        }
    }

    void ApngWriter::putByte(uint8_t b) {
        putBytes(&b,sizeof(b));
    }

    void ApngWriter::putBytes(const uint8_t *bytes, size_t count) {
        assert(fbuf);
        if(bytes == nullptr || count <= 0 ){
            LOGW("putBytes,the bytes is null ptr or count is less than 0 ");
            return;
        }
        memcpy(fbuf,bytes,count);
    }

    size_t ApngWriter::position() {
        return this->pos ;
    }

    void ApngWriter::skip(size_t length) {
         if(length <= 0){
             LOGW("skip,the length is less than 0 ");
         }
         this->pos += length;
    }

    void ApngWriter::putInt(size_t val) {
        putByte((val >> 24) & 0xff);
        putByte((val >> 16) & 0xff);
        putByte((val >> 8) & 0xff);
        putByte((val ) & 0xff);
    }

    void ApngWriter::putFourCC(size_t val) {
        putByte((val ) & 0xff);
        putByte((val >> 8) & 0xff);
        putByte((val >> 16) & 0xff);
        putByte((val >> 24) & 0xff);
    }

    uint8_t *ApngWriter::toByteArray() {
        return fbuf;
    }
}