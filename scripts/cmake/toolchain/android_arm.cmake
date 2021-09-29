cmake_minimum_required (VERSION 3.2)

# Standard settings
set(CMAKE_LIBRARY_ARCHITECTURE "arm") 
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)
set(UNIX True)
set(ANDROID True)

#set toolchain components
set(CMAKE_C_COMPILER /Developer/android-toolchain-arm64-api24/bin/aarch64-linux-android-clang)
set(CMAKE_CXX_COMPILER /Developer/android-toolchain-arm64-api24/bin/aarch64-linux-android-clang++)

add_definitions(-DANDROID)
add_definitions(-D__SYMBIAN32__ -D__EABI__)
