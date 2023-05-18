//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_IENDCHUNK_H
#define APNGDRAWABLE_IENDCHUNK_H
#include "Chunk.h"
namespace apng {
    class IENDChunk :public Chunk{
    public:
        static const size_t ID = fourCCToInt('I','E','N','D');
    protected:
        virtual void innerParse(ApngReader * reader);
    };
}


#endif //APNGDRAWABLE_IENDCHUNK_H
