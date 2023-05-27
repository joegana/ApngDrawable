//
// Created by admin on 2023/5/24.
//

#ifndef APNGDRAWABLE_CRC32_H
#define APNGDRAWABLE_CRC32_H
#pragma once
#include<stdint.h>
#include<zlib.h>
namespace apng{
    /**
     * 计算buf[offset .... offset+len]的CRC32值
     * @param buf
     * @param offset
     * @param len
     * @return
     */
     inline size_t getCrc32(uint8_t* buf,size_t offset,size_t len){
        size_t crc = crc32(0, buf + offset, len);
        return crc;
    }
}

#endif //APNGDRAWABLE_CRC32_H
