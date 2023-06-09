//
// Created by Justin on 2023/5/16.
//

#ifndef APNGDRAWABLE_FDATCHUNK_H
#define APNGDRAWABLE_FDATCHUNK_H
#include "Chunk.h"

namespace apng {
    class FDATChunk :public Chunk{
        public:
            static const size_t ID  = fourCCToInt('f','d','a','T');
            void setSequenceNumber(size_t no){
                this->sequence_number = no ;
            }
            size_t getSequenceNumber(){
                return this->sequence_number;
            }

        public:
            FDATChunk(){};

         protected:
             virtual void innerParse(UApngReader reader);
        private:
            FDATChunk(FDATChunk & chunk) = delete;
            size_t sequence_number ;

    };
}


#endif //APNGDRAWABLE_FDATCHUNK_H
