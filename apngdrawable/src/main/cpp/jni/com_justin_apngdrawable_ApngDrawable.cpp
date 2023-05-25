//
// Created by admin on 2023/5/25.
//
#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include "scoped_utf_chars.h"
#include "decode/APNGDecoder.h"
#include "io/AssetReader.h"
#include "io/ApngReader.h"

extern "C"{

    JNIEXPORT jlong JNICALL
    Java_com_justin_apngdrawable_ApngDrawable_nativeInit(JNIEnv *env, jobject thiz, jobject am,
                                                         jstring name) {
        AAssetManager * amPtr = AAssetManager_fromJava(env,am);
        ScopedUtfChars cName = ScopedUtfChars(env,name);
        if(cName.c_str() == nullptr){
            return NULL;
        }
        AAsset * apng = AAssetManager_open(amPtr,cName.c_str(),0);
        if(!apng){
            return NULL;
        }

        auto reader = std::make_unique<apng::AssetReader>(apng);
        auto apngReader = std::make_unique<apng::ApngReader>(std::move(reader));
        auto decoder = new apng::APNGDecoder(std::move(apngReader));
        return reinterpret_cast<jlong>(decoder);
    }

    JNIEXPORT void JNICALL
    Java_com_justin_apngdrawable_ApngDrawable_stop(JNIEnv *env, jobject thiz, jlong decode_ptr) {
        auto decoder = reinterpret_cast<apng::APNGDecoder *>(decode_ptr);
        if(decoder){
            decoder->stop();
            delete decoder;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_justin_apngdrawable_ApngDrawable_start(JNIEnv *env, jobject thiz, jlong decode_ptr) {
        auto decoder = reinterpret_cast<apng::APNGDecoder *>(decode_ptr);
        if(decoder){
            decoder->start();
        }
    }

    JNIEXPORT jboolean JNICALL
    Java_com_justin_apngdrawable_ApngDrawable_isRunning(JNIEnv *env, jobject thiz, jlong decode_ptr) {
        auto decoder = reinterpret_cast<apng::APNGDecoder *>(decode_ptr);
        if(decoder){
            return decoder->isRunning();
        }
        return  false ;
    }
}

