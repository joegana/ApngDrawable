//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_READER_H
#define APNGDRAWABLE_READER_H
#include <jni.h>
#include <stdint.h>
#include <memory>
#include <string>
#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>
#include <cassert>
#include <cstdio>
#include <cmath>
#include "Log.h"

namespace apng{
    class Reader {
        public:
            virtual size_t skip(size_t total);
            virtual int8_t peek();
            virtual void reset();
            virtual size_t position();
            virtual size_t read(uint8_t * buffer,size_t start,size_t count);
            virtual size_t available();
            virtual void close();
    };

}


#endif //APNGDRAWABLE_READER_H
