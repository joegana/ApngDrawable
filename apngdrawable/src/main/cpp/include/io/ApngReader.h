//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_APNGREADER_H
#define APNGDRAWABLE_APNGREADER_H

#include "io/Reader.h"
#include "io/AssetReader.h"

namespace apng{
#ifdef __cplusplus
    extern "C" {
#endif
    class ApngReader final: public Reader{
        public:
            ApngReader(AssetReader * reader){
                this->aReader = reader ;
            }
        size_t readInt() ;
        uint16_t readShort();
        size_t readFourCC();
        size_t skip(size_t total) override ;
        int8_t peek() override ;
        void reset() override ;
        size_t position() override ;
        size_t read(uint8_t * buffer,size_t start,size_t count) override ;
        size_t available() override ;
        void close() override ;

        private:
            uint8_t*  ensureBytes();
        private:
             uint8_t* _localBytes;
             AssetReader * aReader ;

    };
#ifdef __cplusplus
    }
#endif
}


#endif //APNGDRAWABLE_APNGREADER_H
