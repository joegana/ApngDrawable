//
// Created by Justin on 2023/5/25.
//

#ifndef APNGDRAWABLE_NATIVEHELPER_UTILS_H
#define APNGDRAWABLE_NATIVEHELPER_UTILS_H

#pragma once

#include <jni.h>

#if defined(__cplusplus)

#if !defined(DISALLOW_COPY_AND_ASSIGN)
// DISALLOW_COPY_AND_ASSIGN disallows the copy and operator= functions. It goes in the private:
// declarations in a class.
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) = delete;  \
  void operator=(const TypeName&) = delete
#endif  // !defined(DISALLOW_COPY_AND_ASSIGN)

// This seems a header-only include. Provide NPE throwing.
static inline int jniThrowNullPointerException(JNIEnv* env) {
    if (env->ExceptionCheck()) {
        // Drop any pending exception.
        env->ExceptionClear();
    }

    jclass e_class = env->FindClass("java/lang/NullPointerException");
    if (e_class == nullptr) {
        return -1;
    }

    if (env->ThrowNew(e_class, nullptr) != JNI_OK) {
        env->DeleteLocalRef(e_class);
        return -1;
    }

    env->DeleteLocalRef(e_class);
    return 0;
}

#endif  // defined(__cplusplus)


#endif //APNGDRAWABLE_NATIVEHELPER_UTILS_H
