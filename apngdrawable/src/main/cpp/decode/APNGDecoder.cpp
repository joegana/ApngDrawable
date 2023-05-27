//
// Created by Justin on 2023/5/22.
//

#include "decode/APNGDecoder.h"

namespace apng{
    APNGDecoder::APNGDecoder(UApngReader&& reader) {
        this->apngReader = std::move(reader);
        this->snapShot = std::make_unique<SnapShot>();
        this->frames = std::make_unique<VUApngFrame>();
        this->loopCount = 1 ;
    }

    void APNGDecoder::release() {
        this->snapShot.reset();
        this->apngReader->close();
    }

    size_t APNGDecoder::getLoopCount() const{
        return this->loopCount;
    }

    UApngReader APNGDecoder::getReader() {
        return std::move(this->apngReader);
    }

    UARect APNGDecoder::read(UApngReader reader) {
        auto chunks = APNGParser::parse(std::move(reader));
        VVector otherChunks;
        bool actl = false ;
        uint8_t ihdrData[5];
        size_t fwidth = 0,fheight = 0;
        UApngFrame lastFrame ;
        for(auto & chunk :*chunks.get()){
            size_t fourCC =  chunk->getFourCC();
            if(fourCC == ACTLChunk::ID){
                this->loopCount = dynamic_cast<ACTLChunk*>(chunk.get())->getNumFrames();
                actl = true ;
            }else if(fourCC == FCTLChunk::ID){
                auto frame = std::make_unique<APNGFrame>(
                        std::move(reader),
                        std::move(reinterpret_cast<UFCTLChunk&>(chunk)));
                for(auto &ot:otherChunks){
                    frame->addPrefixChunk(std::move(ot));
                }
                frame->setIHDRData(ihdrData,sizeof(ihdrData));
                this->frames->push_back(std::move(frame));
                lastFrame = std::move(frame);
            }else if(fourCC == FDATChunk::ID){
                if(lastFrame){
                    lastFrame->addImageChunk(std::move(chunk));
                }
            }else if(fourCC == IDATChunk::ID){
                if(!actl){
                    LOGI("Not apng picture, finish decode!");
                    auto frame = std::make_unique<StillFrame>(std::move(reader));
                    frame->setFrameHeight(fheight);
                    frame->setFrameWidth(fwidth);
                    this->frames->push_back(std::move(frame));
                    loopCount = 1;
                    break;
                }
                if(lastFrame){
                    lastFrame->addImageChunk(std::move(chunk));
                }
            }else if(fourCC == IHDRChunk::ID){
                auto ihdr = dynamic_cast<IHDRChunk*>(chunk.get());
                fwidth = ihdr->getWidth();
                fheight = ihdr->getHeight();
                memcpy(ihdr->getIHDRData(),ihdrData, sizeof(ihdrData));
            }else if(fourCC != IENDChunk::ID){
                otherChunks.push_back(std::move(chunk));
            }
        }
        return std::make_unique<ARect>(ARect{0,0,
                                             static_cast<int32_t>(fwidth),
                                             static_cast<int32_t>(fheight)});
    }

    void APNGDecoder::start() {

    }

    void APNGDecoder::stop() {
        this->release();
    }

    bool APNGDecoder::isRunning() {
        return false;
    }

    void APNGDecoder::setSurface(ASurfaceTexture * texture) {
        if(texture){
            this->surface = texture;
        }
    }

    void APNGDecoder::renderFrame(UApngFrame frame) {

    }

}

