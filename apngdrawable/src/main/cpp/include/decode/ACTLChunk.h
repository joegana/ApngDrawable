//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_ACTLCHUNK_H
#define APNGDRAWABLE_ACTLCHUNK_H
#include "Chunk.h"

namespace apng{
    class ACTLChunk: public Chunk{
    public:
        ACTLChunk(){};

        static const int ID = fourCCToInt('a', 'c', 'T', 'L');
        void setNumFrames(size_t n){
            this->num_frames = n ;
        }
        size_t getNumFrames(){
            return this->num_frames ;
        }
        void setNumPlays(size_t n){
            this->num_plays = n ;
        }
        size_t getNumPlays(){
            return this->num_plays;
        }
    protected:
        virtual void innerParse(UApngReader reader) override;
    private:
        ACTLChunk(ACTLChunk & chunk) = delete;
        uint32_t num_frames;
        uint32_t num_plays;
    };

}



#endif //APNGDRAWABLE_ACTLCHUNK_H
