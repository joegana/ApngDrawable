package com.justin.apngdrawable

import android.content.Context
import android.content.res.AssetManager
import android.graphics.Bitmap
import android.graphics.Canvas
import android.graphics.ColorFilter
import android.graphics.Paint
import android.graphics.PixelFormat
import android.graphics.drawable.Animatable2
import android.graphics.drawable.Drawable

class ApngDrawable : Drawable,Animatable2 {
    /**
     * 解码之后的图片
     */
    private var mBitmap:Bitmap? = null
    private var mPaint:Paint = Paint(Paint.FILTER_BITMAP_FLAG or Paint.DITHER_FLAG)
    private var mContext:Context
    private var assetPath:String
    private var mDecodePtr:Long = 0

    constructor(context: Context, path:String){
        mContext = context
        assetPath = path
        mDecodePtr = nativeInit(context.assets,assetPath)
    }

    override fun draw(canvas: Canvas) {
    }

    override fun setAlpha(alpha: Int) {
        mPaint.alpha = alpha
        invalidateSelf()
    }

    override fun setColorFilter(colorFilter: ColorFilter?) {
        colorFilter?.apply {
            mPaint.colorFilter = colorFilter;
        }
    }

    override fun getOpacity(): Int {
        return PixelFormat.TRANSLUCENT
    }

    override fun start() {
        if(mDecodePtr == 0L){
            mDecodePtr =  nativeInit(mContext.assets,assetPath)
        }
        start(mDecodePtr)
    }

    override fun stop() {
        stop(mDecodePtr)
        mDecodePtr = 0
    }

    override fun isRunning(): Boolean {
        return isRunning(mDecodePtr);
    }

    override fun registerAnimationCallback(callback: Animatable2.AnimationCallback) {

    }

    override fun unregisterAnimationCallback(callback: Animatable2.AnimationCallback): Boolean {
        return false;
    }

    override fun clearAnimationCallbacks() {

    }

    /**
     * native 层ApngDecode初始化
     */
    private external fun nativeInit(am: AssetManager,name:String):Long
    private external fun stop(decodePtr:Long)
    private external fun start(decodePtr:Long)
    private external fun isRunning(decodePtr:Long):Boolean
}