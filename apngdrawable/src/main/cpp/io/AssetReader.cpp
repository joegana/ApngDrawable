//
// Created by Justin on 2023/5/17.
//

#include "io/AssetReader.h"

namespace apng{

    size_t AssetReader::skip(size_t total) {
        assert(aAsset);
        if(total <= 0){
            return 0 ;
        }
        size_t  remain = total ;
        size_t bufSize = std::min((size_t)2000,total);
        uint8_t buf[bufSize];
        size_t c ;
        do {
            c = read(buf,0,bufSize);
            if(c < 0)
                break;
            remain -= c ;
        }while(remain > 0);
        return total - remain ;
    }

    int8_t AssetReader::peek() {
        assert(aAsset);
        uint8_t b ;
        auto c = AAsset_read(aAsset,&b, sizeof(b));
        if(c > 0){
            mPosition += c ;
            return b ;
        }
        return  -1 ;
    }

    size_t AssetReader::read(uint8_t *buffer, size_t start, size_t count) {
        assert(aAsset);
        assert(buffer);
        auto c =  AAsset_read(aAsset,buffer+start,count);
        if( c > 0){
            mPosition += c ;
            return c ;
        }
        return  -1 ;
    }

    size_t AssetReader::available() {
        assert(aAsset);
        return AAsset_getRemainingLength(aAsset);
    }

    size_t AssetReader::position() {
        return mPosition;
    }

    void AssetReader::reset() {
        assert(aAsset);
        AAsset_seek(aAsset,0,SEEK_SET);
    }

    void AssetReader::close() {
        assert(aAsset);
        AAsset_close(aAsset);
    }

}