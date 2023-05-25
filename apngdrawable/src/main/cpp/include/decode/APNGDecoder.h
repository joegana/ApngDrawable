//
// Created by Justin on 2023/5/22.
//

#ifndef APNGDRAWABLE_APNGDECODER_H
#define APNGDRAWABLE_APNGDECODER_H
#include <android/rect.h>
#include <android/surface_texture.h>
#include <android/bitmap.h>
#include "io/ApngWriter.h"
#include "APNGFrame.h"
#include "StillFrame.h"
#include "APNGParser.h"
namespace apng{
    using UARect = std::unique_ptr<ARect>;
    class APNGDecoder {
        public:
            APNGDecoder(UApngReader reader);
            void setSurface(ASurfaceTexture * texture);
            UApngReader getReader();
            size_t getLoopCount() const;
            void release();
            UARect read(UApngReader reader);
            void renderFrame(UApngFrame frame);

       protected:

        class SnapShot{
            public:
                SnapShot(){}
                ~SnapShot(){
                    if(tPixels){
                        delete[] tPixels;
                        tPixels = nullptr;
                    }
                }
            private:
                SnapShot(SnapShot & shot) = delete;
                SnapShot& operator=(SnapShot & shot) = delete;
                uint8_t  dispose_op;
                ARect dstRect;
                uint8_t * tPixels;
                size_t tPixelsSize;;
        };

        private:
            ASurfaceTexture * surface;
            UApngReader apngReader;
            UVApngFrame frames;
            size_t loopCount;
            std::unique_ptr<SnapShot> snapShot;
        };
}



#endif //APNGDRAWABLE_APNGDECODER_H
