//
// Created by admin on 2023/5/24.
//

#ifndef APNGDRAWABLE_CRC32_H
#define APNGDRAWABLE_CRC32_H
#include<stdint.h>
#include<zlib.h>
namespace apng{
    size_t getCrc32(uint8_t* buf,size_t len){
        unsigned long crc = crc32(0L, nullptr, 0);
        crc = crc32(crc, buf, len);
        return crc;
    }
}

#endif //APNGDRAWABLE_CRC32_H
