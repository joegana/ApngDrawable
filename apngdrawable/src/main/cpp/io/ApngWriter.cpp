//
// Created by admin on 2023/5/16.
//

#include "io/ApngWriter.h"

namespace apng{
    void ApngWriter::reset(size_t size) {

    }
    void ApngWriter::close() {

    }

    void ApngWriter::putByte(uint8_t b) {

    }

    void ApngWriter::putBytes(const uint8_t *bytes, size_t count) {

    }

    size_t ApngWriter::position() {

    }

    void ApngWriter::skip(size_t length) {

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


}