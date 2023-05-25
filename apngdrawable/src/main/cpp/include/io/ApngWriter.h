//
// Created by Justin on 2023/5/16.
//

#ifndef APNGDRAWABLE_APNGWRITER_H
#define APNGDRAWABLE_APNGWRITER_H
#include <io/Writer.h>
#include <io/Reader.h>
namespace apng{
    class ApngWriter final: public Writer{
        public:
            void reset(size_t size) override  ;
            void putByte(uint8_t b) override  ;
            void putBytes(const uint8_t* bytes,size_t count) override;
            size_t position() override ;
            void skip(size_t length)override ;
            uint8_t * toByteArray() override ;
            void close() override ;

            void putInt(size_t val);
            void putFourCC(size_t val);

    private:
            uint8_t * fbuf;
            size_t size ;
            size_t pos;
    };
}

#endif //APNGDRAWABLE_APNGWRITER_H
