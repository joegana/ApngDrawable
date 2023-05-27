cmake_minimum_required(VERSION 3.4.1)

project(apng)

include_directories(include)

file(GLOB_RECURSE  apng_drawable_header
        jni/*.h
        include/*.h
        include/decode/*.h
        include/io/*.h
        include/thread/*.h
        include/thread/*.hpp
        )

file(GLOB_RECURSE  apng_drawable_source
         Decode/*.cpp
         io/*.cpp
         jni/*.cpp
         thread/*.cpp
        )

add_definitions(-DBUILD_DEBUG)

add_library(
        apng-drawable
        SHARED
        ${apng_drawable_header}
        ${apng_drawable_source}
        )

target_link_libraries(apng-drawable
        log
        android
        jnigraphics
        z
        )
