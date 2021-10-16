# iOS build

To building a remote trget iOS, we need to use a toolchain CMake.

## CMake Toolchain

The toolchain for iOS is generate from project : https://github.com/leetal/ios-cmake

[xtd io toolchain](../../scripts/cmake/toolchain/ios.cmake)

## Commands to generate xtd

* For an iOS with the arm64 architecture.

```shell
mkdir build-ios && cd buidl_ios
cmake .. -DCMAKE_TOOLCHAIN_FILE=../scripts/cmake/toolchain/ios.cmake -DPLATFORM=OS64 -DXTD_BUILD_LIBRARIES_XTD_DRAWING=OFF -DXTD_BUILD_LIBRARIES_XTD_FORMS=OFF -DXTD_BUILD_TOOL_GUIDGEN_COMMAND_LINE=OFF -DXTD_BUILD_TOOL_GUIDGEN_GUI=OFF -DXTD_BUILD_TOOL_SLEEPFOR_COMMAND_LINE=OFF -DXTD_BUILD_TOOL_SLEEPFOR_COMMAND_LINE=OFF -DXTD_BUILD_TOOL_XTDC_GUI=OFF
```

* For a FAT-libraries for the given platform (OS64, TVOS and WATCHOS)

```shell
mkdir build-ios && cd buidl_ios
cmake .. -DCMAKE_TOOLCHAIN_FILE=../scripts/cmake/toolchain/ios.cmake -DPLATFORM=OS64 -DXTD_BUILD_LIBRARIES_XTD_DRAWING=OFF -DXTD_BUILD_LIBRARIES_XTD_FORMS=OFF -DXTD_BUILD_TOOL_GUIDGEN_COMMAND_LINE=OFF -DXTD_BUILD_TOOL_GUIDGEN_GUI=OFF -DXTD_BUILD_TOOL_SLEEPFOR_COMMAND_LINE=OFF -DXTD_BUILD_TOOL_SLEEPFOR_COMMAND_LINE=OFF -DXTD_BUILD_TOOL_XTDC_GUI=OFF
```

### Note : The options called *COMBINED (OS64COMBINED, TVOSCOMBINED and WATCHOSCOMBINED) will build complete FAT-libraries for the given platform. These FAT-libraries include slices for both device and simulator, making the distribution and usage of the library much more simple!

