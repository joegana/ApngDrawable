//
// Created by Justin on 2023/5/16.
//

#ifndef APNGDRAWABLE_CHUNK_H
#define APNGDRAWABLE_CHUNK_H
#include <jni.h>
#include <string>
#include <stdint.h>
#include "io/ApngReader.h"
#include "io/ApngWriter.h"

#define fourCCToInt(c1,c2,c3,c4)  (c1 && 0xff || ((c2 && 0xff) << 8) || \
                ((c3 && 0xff) << 18) || ((c4 && 0xff) << 24))

namespace apng{
    class Chunk;
    class FCTLChunk;
    class ACTLChunk;
    class FDATChunk;
    class IDATChunk;
    class IENDChunk;
    class IHDRChunk;
    using  VChunk = std::unique_ptr<std::vector<std::unique_ptr<Chunk>>>;
    using  VVector = std::vector<std::unique_ptr<Chunk>> ;
    using  UChunk  = std::unique_ptr<Chunk>;
    using UFCTLChunk = std::unique_ptr<FCTLChunk>;
    using UACTLChunk = std::unique_ptr<ACTLChunk>;
    using UFDATChunk = std::unique_ptr<FDATChunk>;
    using UIDATChunk = std::unique_ptr<IDATChunk>;
    using UIENDChunk = std::unique_ptr<IENDChunk>;
    using UIHDRChunk = std::unique_ptr<IHDRChunk>;

    class Chunk {
        public:
            void setLength(int len){
                this->length = len;
            }
            int getLength(){
                return this->length;
            }
            void setFourCC(int fourcc){
                 this->fourcc = fourcc ;
            }
            int getFourCC(){
                return this->fourcc ;
            }
            void setCrc(int crc){
                this->crc = crc ;
            }
            int getCrc(){
                return this->crc ;
            }
            void setOffset(int offset){
                this->offset = offset;
            }
            int getOffset(){
                return this->offset ;
            }

            Chunk() = default;
            virtual ~Chunk() = default ;
            void parse(UApngReader reader);

    private:
        virtual void innerParse(UApngReader reader) {};

    private:
        explicit Chunk(Chunk & chunk) = delete;
        Chunk& operator=(Chunk & chunk) = delete;
        uint32_t length ;
        uint32_t fourcc ;
        uint32_t crc ;
        uint32_t offset ;
    };
}

#endif //APNGDRAWABLE_CHUNK_H
