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
    class Reader;
    class ApngReader;
    using  UApngReader = std::unique_ptr<ApngReader>;
    using  UReader = std::unique_ptr<Reader>;
    class Reader {
        public:
            Reader(){};
            virtual size_t skip(size_t total) = 0;
            virtual int8_t peek() = 0;
            virtual void reset() =  0;
            virtual size_t position() = 0;
            virtual size_t read(uint8_t * buffer,size_t start,size_t count) {
                return 0 ;
            };
            virtual size_t available() = 0 ;
            virtual void close() {};
            virtual ~Reader() {
                close();
            }

    private:
        Reader(Reader & reader) = delete ;
        Reader& operator=(Reader & reader) = delete ;

    };

}


#endif //APNGDRAWABLE_READER_H
