//
// Created by Justin on 2023/5/16.
//

#ifndef APNGDRAWABLE_LOG_H
#define APNGDRAWABLE_LOG_H

#pragma once

#ifdef BUILD_DEBUG

#include<android/log.h>
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, "apng-drawable", __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , "apng-drawable", __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , "apng-drawable", __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , "apng-drawable", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , "apng-drawable", __VA_ARGS__)

#else

#define LOGV(...)
#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)

#endif

#endif //APNGDRAWABLE_LOG_H


