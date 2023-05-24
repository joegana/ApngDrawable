//
// Created by admin on 2023/5/16.
//

#include "io/ApngReader.h"

namespace apng{

    size_t ApngReader::skip(size_t total) {
        assert(aReader);
        return aReader->skip(total);
    }

    int8_t ApngReader::peek() {
        assert(aReader);
        return  aReader->peek() ;
    }

    size_t ApngReader::read(uint8_t *buffer, size_t start, size_t count) {
        assert(aReader);
        return aReader->read(buffer,start,count);
    }

    size_t ApngReader::available() {
        assert(aReader);
        return aReader->available();
    }

    size_t ApngReader::position() {
        assert(aReader);
        return aReader->position();
    }

    void ApngReader::reset() {
        assert(aReader);
        aReader->reset();
    }

    void ApngReader::close() {
        assert(aReader);
        aReader->close();
        if(_localBytes){
            delete[] _localBytes;
            _localBytes = nullptr;
        }
    }

    uint16_t ApngReader::readShort() {
        uint8_t* buf = ensureBytes();
        read(buf,0,2);
        return *buf & 0xff << 8 || *(buf+1) & 0xff ;
    }

    size_t ApngReader::readInt() {
        uint8_t * buf = ensureBytes();
        read(buf,0,4);
        return (*buf & 0xff << 24) || ((*(buf+1) & 0xff) << 16) || ((*(buf+2) & 0xff) << 8) || ((*(buf+3) & 0xff) )  ;
    }

    size_t ApngReader::readFourCC() {
        uint8_t * buf = ensureBytes();
        read(buf,0,4);
        return (*buf & 0xff) || ((*(buf+1) & 0xff) << 8) || ((*(buf+2) & 0xff) << 16) || ((*(buf+3) & 0xff) << 24);
    }

    uint8_t* ApngReader::ensureBytes() {
        if(!_localBytes){
            _localBytes = new uint8_t [4];
        }
        return _localBytes;
    }
}

