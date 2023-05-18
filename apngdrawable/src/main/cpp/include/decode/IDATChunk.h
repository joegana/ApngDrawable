//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_IDATCHUNK_H
#define APNGDRAWABLE_IDATCHUNK_H
#include "Chunk.h"

namespace apng {
    class IDATChunk: public Chunk{
         public:
            static const size_t ID = fourCCToInt('I','D','A','T');
         protected:
            virtual void innerParse(ApngReader * reader);
    };
}


#endif //APNGDRAWABLE_IDATCHUNK_H