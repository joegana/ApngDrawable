//
// Created by admin on 2023/5/18.
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
    class Writer {
        public:
            virtual void reset(size_t size) = 0 ;
            virtual void putByte(uint8_t b) = 0 ;
            virtual void putBytes(const uint8_t* buf,size_t count);
            virtual size_t position() = 0 ;
            virtual void skip(size_t length) = 0;
            virtual uint8_t * toByteArray() = 0;
            virtual void close();
    };
}
#endif //APNGDRAWABLE_WRITER_H
