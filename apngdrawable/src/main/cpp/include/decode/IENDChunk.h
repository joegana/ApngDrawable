//
// Created by Justin on 2023/5/16.
//

#ifndef APNGDRAWABLE_IENDCHUNK_H
#define APNGDRAWABLE_IENDCHUNK_H
#include "Chunk.h"
namespace apng {
    class IENDChunk :public Chunk{
    public:
        static const size_t ID = fourCCToInt('I','E','N','D');
    public:
        IENDChunk(){};
    protected:
        virtual void innerParse(UApngReader reader) {}
    private:
        IENDChunk(IENDChunk & chunk) = delete;
    };
}


#endif //APNGDRAWABLE_IENDCHUNK_H
