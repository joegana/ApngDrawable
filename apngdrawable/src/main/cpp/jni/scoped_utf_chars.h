//
// Created by Justin on 2023/5/25.
//

#ifndef APNGDRAWABLE_SCOPED_UTF_CHARS_H
#define APNGDRAWABLE_SCOPED_UTF_CHARS_H

#pragma once

#include <stddef.h>
#include <string.h>
#include <jni.h>

#include "nativehelper_utils.h"

// A smart pointer that provides read-only access to a Java string's UTF chars.
// Unlike GetStringUTFChars, we throw NullPointerException rather than abort if
// passed a null jstring, and c_str will return nullptr.
// This makes the correct idiom very simple:
//
//   ScopedUtfChars name(env, java_name);
//   if (name.c_str() == nullptr) {
//     return nullptr;
//   }
class ScopedUtfChars {
public:
    ScopedUtfChars(JNIEnv* env, jstring s) : env_(env), string_(s) {
        if (s == nullptr) {
            utf_chars_ = nullptr;
            jniThrowNullPointerException(env);
        } else {
            utf_chars_ = env->GetStringUTFChars(s, nullptr);
        }
    }

    ScopedUtfChars(ScopedUtfChars&& rhs) noexcept :
            env_(rhs.env_), string_(rhs.string_), utf_chars_(rhs.utf_chars_) {
        rhs.env_ = nullptr;
        rhs.string_ = nullptr;
        rhs.utf_chars_ = nullptr;
    }

    ~ScopedUtfChars() {
        if (utf_chars_) {
            env_->ReleaseStringUTFChars(string_, utf_chars_);
        }
    }

    ScopedUtfChars& operator=(ScopedUtfChars&& rhs) noexcept {
        if (this != &rhs) {
            // Delete the currently owned UTF chars.
            this->~ScopedUtfChars();

            // Move the rhs ScopedUtfChars and zero it out.
            env_ = rhs.env_;
            string_ = rhs.string_;
            utf_chars_ = rhs.utf_chars_;
            rhs.env_ = nullptr;
            rhs.string_ = nullptr;
            rhs.utf_chars_ = nullptr;
        }
        return *this;
    }

    const char* c_str() const {
        return utf_chars_;
    }

    size_t size() const {
        return strlen(utf_chars_);
    }

    const char& operator[](size_t n) const {
        return utf_chars_[n];
    }

private:
    JNIEnv* env_;
    jstring string_;
    const char* utf_chars_;

    DISALLOW_COPY_AND_ASSIGN(ScopedUtfChars);
};

#endif //APNGDRAWABLE_SCOPED_UTF_CHARS_H
