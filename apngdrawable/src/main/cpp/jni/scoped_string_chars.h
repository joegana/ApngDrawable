//
// Created by admin on 2023/5/25.
//

#ifndef APNGDRAWABLE_SCOPED_STRING_CHARS_H
#define APNGDRAWABLE_SCOPED_STRING_CHARS_H

#pragma once
#include <stddef.h>
#include <jni.h>

#include "nativehelper_utils.h"

// A smart pointer that provides access to a jchar* given a JNI jstring.
// Unlike GetStringChars, we throw NullPointerException rather than abort if
// passed a null jstring, and get will return nullptr.
// This makes the correct idiom very simple:
//
//   ScopedStringChars name(env, java_name);
//   if (name.get() == nullptr) {
//     return nullptr;
//   }
class ScopedStringChars {
public:
    ScopedStringChars(JNIEnv* env, jstring s) : env_(env), string_(s), size_(0) {
        if (s == nullptr) {
            chars_ = nullptr;
            jniThrowNullPointerException(env);
        } else {
            chars_ = env->GetStringChars(string_, nullptr);
            if (chars_ != nullptr) {
                size_ = env->GetStringLength(string_);
            }
        }
    }

    ~ScopedStringChars() {
        if (chars_ != nullptr) {
            env_->ReleaseStringChars(string_, chars_);
        }
    }

    const jchar* get() const {
        return chars_;
    }

    size_t size() const {
        return size_;
    }

    const jchar& operator[](size_t n) const {
        return chars_[n];
    }

private:
    JNIEnv* const env_;
    const jstring string_;
    const jchar* chars_;
    size_t size_;

    DISALLOW_COPY_AND_ASSIGN(ScopedStringChars);
};

#endif //APNGDRAWABLE_SCOPED_STRING_CHARS_H
