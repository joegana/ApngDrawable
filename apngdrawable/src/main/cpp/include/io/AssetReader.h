//
// Created by admin on 2023/5/17.
//

#ifndef APNGDRAWABLE_ASSETREADER_H
#define APNGDRAWABLE_ASSETREADER_H
#include "Reader.h"
namespace apng{

    class AssetReader final:public Reader{
    public:
        AssetReader(AAsset * aAsset){
            this->aAsset = aAsset;
            LOGI("AssetReader %p",this->aAsset);
        }
         size_t skip(size_t total)  override ;
         int8_t peek() override ;
         void reset() override  ;
         size_t position() override ;
         size_t read(uint8_t * buffer,size_t start,size_t count) override ;
         size_t available() override ;
         void close() override ;
    private:
        std::string name ;
        size_t mPosition = 0 ;
        AAsset * aAsset;
    };
}
#endif //APNGDRAWABLE_ASSETREADER_H
