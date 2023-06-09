//
// Created by Justin on 2023/5/25.
//

#ifndef APNGDRAWABLE_SCOPED_PRIMITIVE_ARRAY_H
#define APNGDRAWABLE_SCOPED_PRIMITIVE_ARRAY_H

#pragma once

#include <stddef.h>

#include <jni.h>

#include "nativehelper_utils.h"

#ifdef POINTER_TYPE
#error POINTER_TYPE is defined.
#else
#define POINTER_TYPE(T) T*  /* NOLINT */
#endif

#ifdef REFERENCE_TYPE
#error REFERENCE_TYPE is defined.
#else
#define REFERENCE_TYPE(T) T&  /* NOLINT */
#endif

// ScopedBooleanArrayRO, ScopedByteArrayRO, ScopedCharArrayRO, ScopedDoubleArrayRO,
// ScopedFloatArrayRO, ScopedIntArrayRO, ScopedLongArrayRO, and ScopedShortArrayRO provide
// convenient read-only access to Java arrays from JNI code. This is cheaper than read-write
// access and should be used by default.
#define INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(PRIMITIVE_TYPE, NAME) \
    class Scoped ## NAME ## ArrayRO { \
    public: \
        explicit Scoped ## NAME ## ArrayRO(JNIEnv* env) \
        : mEnv(env), mJavaArray(nullptr), mRawArray(nullptr), mSize(0) {} \
        Scoped ## NAME ## ArrayRO(JNIEnv* env, PRIMITIVE_TYPE ## Array javaArray) \
        : mEnv(env) { \
            if (javaArray == nullptr) { \
                mJavaArray = nullptr; \
                mSize = 0; \
                mRawArray = nullptr; \
                jniThrowNullPointerException(mEnv); \
            } else { \
                reset(javaArray); \
            } \
        } \
        ~Scoped ## NAME ## ArrayRO() { \
            if (mRawArray != nullptr && mRawArray != mBuffer) { \
                mEnv->Release ## NAME ## ArrayElements(mJavaArray, mRawArray, JNI_ABORT); \
            } \
        } \
        void reset(PRIMITIVE_TYPE ## Array javaArray) { \
            mJavaArray = javaArray; \
            mSize = mEnv->GetArrayLength(mJavaArray); \
            if (mSize <= buffer_size) { \
                mEnv->Get ## NAME ## ArrayRegion(mJavaArray, 0, mSize, mBuffer); \
                mRawArray = mBuffer; \
            } else { \
                mRawArray = mEnv->Get ## NAME ## ArrayElements(mJavaArray, nullptr); \
            } \
        } \
        const PRIMITIVE_TYPE* get() const { return mRawArray; } \
        PRIMITIVE_TYPE ## Array getJavaArray() const { return mJavaArray; } \
        const PRIMITIVE_TYPE& operator[](size_t n) const { return mRawArray[n]; } \
        size_t size() const { return mSize; } \
    private: \
        static const jsize buffer_size = 1024; \
        JNIEnv* const mEnv; \
        PRIMITIVE_TYPE ## Array mJavaArray; \
        POINTER_TYPE(PRIMITIVE_TYPE) mRawArray; \
        jsize mSize; \
        PRIMITIVE_TYPE mBuffer[buffer_size]; \
        DISALLOW_COPY_AND_ASSIGN(Scoped ## NAME ## ArrayRO); \
    }

INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(jboolean, Boolean);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(jbyte, Byte);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(jchar, Char);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(jdouble, Double);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(jfloat, Float);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(jint, Int);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(jlong, Long);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO(jshort, Short);

#undef INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RO

// ScopedBooleanArrayRW, ScopedByteArrayRW, ScopedCharArrayRW, ScopedDoubleArrayRW,
// ScopedFloatArrayRW, ScopedIntArrayRW, ScopedLongArrayRW, and ScopedShortArrayRW provide
// convenient read-write access to Java arrays from JNI code. These are more expensive,
// since they entail a copy back onto the Java heap, and should only be used when necessary.
#define INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(PRIMITIVE_TYPE, NAME) \
    class Scoped ## NAME ## ArrayRW { \
    public: \
        explicit Scoped ## NAME ## ArrayRW(JNIEnv* env) \
        : mEnv(env), mJavaArray(nullptr), mRawArray(nullptr) {} \
        Scoped ## NAME ## ArrayRW(JNIEnv* env, PRIMITIVE_TYPE ## Array javaArray) \
        : mEnv(env), mJavaArray(javaArray), mRawArray(nullptr) { \
            if (mJavaArray == nullptr) { \
                jniThrowNullPointerException(mEnv); \
            } else { \
                mRawArray = mEnv->Get ## NAME ## ArrayElements(mJavaArray, nullptr); \
            } \
        } \
        ~Scoped ## NAME ## ArrayRW() { \
            if (mRawArray) { \
                mEnv->Release ## NAME ## ArrayElements(mJavaArray, mRawArray, 0); \
            } \
        } \
        void reset(PRIMITIVE_TYPE ## Array javaArray) { \
            mJavaArray = javaArray; \
            mRawArray = mEnv->Get ## NAME ## ArrayElements(mJavaArray, nullptr); \
        } \
        const PRIMITIVE_TYPE* get() const { return mRawArray; } \
        PRIMITIVE_TYPE ## Array getJavaArray() const { return mJavaArray; } \
        const PRIMITIVE_TYPE& operator[](size_t n) const { return mRawArray[n]; } \
        POINTER_TYPE(PRIMITIVE_TYPE) get() { return mRawArray; }  \
        REFERENCE_TYPE(PRIMITIVE_TYPE) operator[](size_t n) { return mRawArray[n]; } \
        size_t size() const { return mEnv->GetArrayLength(mJavaArray); } \
    private: \
        JNIEnv* const mEnv; \
        PRIMITIVE_TYPE ## Array mJavaArray; \
        POINTER_TYPE(PRIMITIVE_TYPE) mRawArray; \
        DISALLOW_COPY_AND_ASSIGN(Scoped ## NAME ## ArrayRW); \
    }

INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(jboolean, Boolean);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(jbyte, Byte);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(jchar, Char);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(jdouble, Double);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(jfloat, Float);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(jint, Int);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(jlong, Long);
INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW(jshort, Short);

#undef INSTANTIATE_SCOPED_PRIMITIVE_ARRAY_RW
#undef POINTER_TYPE
#undef REFERENCE_TYPE

#endif //APNGDRAWABLE_SCOPED_PRIMITIVE_ARRAY_H
