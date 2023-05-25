//
// Created by Justin on 2023/5/18.
//

#ifndef APNGDRAWABLE_WRITER_H
#define APNGDRAWABLE_WRITER_H
#include <jni.h>
#include <stdint.h>
#include <memory>
#include <string>
#include <cassert>
#include <cstdio>
#include <cmath>
#include "Log.h"
namespace apng{
    class Writer;
    class ApngWriter;
    using  UApngWriter = std::unique_ptr<ApngWriter>;
    using  UWriter = std::unique_ptr<Writer>;
    class Writer {
        public:
            virtual void reset(size_t size) = 0 ;
            virtual void putByte(uint8_t b) = 0 ;
            virtual void putBytes(const uint8_t* buf,size_t count) = 0;
            virtual size_t position() = 0 ;
            virtual void skip(size_t length) = 0;
            virtual uint8_t * toByteArray() = 0;
            virtual void close() = 0 ;
    };
}
#endif //APNGDRAWABLE_WRITER_H
