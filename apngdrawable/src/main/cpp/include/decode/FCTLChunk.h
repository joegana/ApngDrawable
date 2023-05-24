//
// Created by admin on 2023/5/16.
//

#ifndef APNGDRAWABLE_FCTLCHUNK_H
#define APNGDRAWABLE_FCTLCHUNK_H
#include "Chunk.h"

namespace apng {
    class FCTLChunk :public Chunk {
        public:
            static const size_t ID = fourCCToInt('f','c','T','L');
            /**
             * No disposal is done on this frame before rendering the next;
             * the contents of the output buffer are left as is.
             */
            static const size_t APNG_DISPOSE_OP_NON = 0;

            /**
             * The frame's region of the output buffer is to be cleared to fully
             * transparent black before rendering the next frame.
             */
            static const size_t APNG_DISPOSE_OP_BACKGROUND = 1;

            /**
             * The frame's region of the output buffer is to be reverted to
             * the previous contents before rendering the next frame.
             */
            static const size_t APNG_DISPOSE_OP_PREVIOUS = 2;

            /**
             * blend_op<code> specifies whether the frame is to be alpha blended
             * into the current output buffer content,
             * or whether it should completely replace its region in the output buffer.
             */
            /**
             * All color components of the frame, including alpha, overwrite the current
             * contents of the frame's output buffer region.
             */
            static const size_t APNG_BLEND_OP_SOURCE = 0;

            /**
             * The frame should be composited onto the output buffer based on its alpha,
             * using a simple OVER operation as described in the Alpha Channel Processing
             * section of the Extensions
             * to the PNG Specification, Version 1.2.0. Note that the second variation
             * of the sample code is applicable.
             */
            static const size_t APNG_BLEND_OP_OVER = 1;

            void setSequenceNumber(size_t seq_no){
                this->sequence_number = seq_no;
            }
            size_t getSequenceNumber(){
                return this->sequence_number;
            }

            void setWidth(size_t w){
                this->width = w ;
            }
            size_t getWidth(){
                return this->width;
            }

            void setHeight(size_t h){
                this->height = h;
            }
            size_t getHeight(){
                return this->height;
            }

            void setXOffset(size_t x_offset){
                this->x_offset = x_offset;
            }
            size_t getXOffset(){
                return this->x_offset;
            }

            void setYOffset(size_t x_offset){
                this->y_offset = x_offset;
            }
            size_t getYOffset(){
                return this->y_offset;
            }

            void setDelayNum(uint16_t delay_num){
                this->delay_num = delay_num;
            }
            uint16_t getDelayNum(){
                return this->delay_num;
            }

            void setDelayDen(uint16_t delay_den){
                this->delay_den = delay_den;
            }
            uint16_t getDelayDen(){
                return this->delay_den;
            }

            void setDisposeOp(uint8_t dispose_op){
                this->dispose_op = dispose_op;
            }
            uint8_t  getDisposeOp(){
                return this->dispose_op;
            }

            void setBlendOp(uint8_t blend_op){
                this->blend_op = blend_op;
            }
            uint8_t getBlendOp(){
                return this->blend_op ;
            }

    public:
        FCTLChunk(){};

    protected:
        virtual void innerParse(UApngReader reader) override;

    private:
           FCTLChunk(FCTLChunk & chunk) = delete;
            // anim no
            size_t sequence_number;

            // Width of the following frame.
            size_t width;

            //Height of the following frame.
            size_t height;

            // X position at which to render the following frame.
            size_t x_offset;
            // Y position at which to render the following frame.
            size_t y_offset;

            // Frame delay fraction numerator.
            uint16_t delay_num;
            //Frame delay fraction denominator.
            uint16_t delay_den;

            /**
             * Type of frame area disposal to be done after rendering this frame.
             * dispose_op specifies how the output buffer should be changed at the end
             * of the delay (before rendering the next frame).
             * If the first 'fcTL' chunk uses a dispose_op of APNG_DISPOSE_OP_PREVIOUS
             * it should be treated as APNG_DISPOSE_OP_BACKGROUND.
             */
            uint8_t dispose_op;
            // Type of frame area rendering for this frame.
            uint8_t blend_op;
    };
}


#endif //APNGDRAWABLE_FCTLCHUNK_H
