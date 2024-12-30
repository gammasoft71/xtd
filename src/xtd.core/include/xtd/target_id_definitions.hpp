/// @file
/// @brief Contains target id definitions.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

/// @cond
// The following constants are defined in the file xtd_command.cmake.
// If the target project is not built with cmake, each constant will be defined as follows:
// | Constant                              | Value | Description                        |
// | ------------------------------------- | ----- | ---------------------------------- |
// | __XTD_TARGET_ID_UNKNOWN__             | 0     | The target is unknown.             |
// | __XTD_TARGET_ID_CONSOLE_APPLICATION__ | 1     | The target is console application. |
// | __XTD_TARGET_ID_GUI_APPLICATION__     | 2     | The target is gui application.     |
// | __XTD_TARGET_ID_TEST_APPLICATION__    | 3     | The target is test application.    |
// | __XTD_TARGET_ID_INTERFACE_LIBRARY__   | 4     | The target is interface library.   |
// | __XTD_TARGET_ID_MODULE_LIBRARY__      | 5     | The target is module library.      |
// | __XTD_TARGET_ID_SHARED_LIBRARY__      | 6     | The target is shared library.      |
// | __XTD_TARGET_ID_STATIC_LIBRARY__      | 7     | The target is static library.      |
// | __XTD_TARGET_ID_CUSTOM_TARGET__       | 8     | The target is custom target.       |
//
// Remarks
// if __XTD_CURRENT_TARGET_ID__ id not defined. It will be defined as __XTD_TARGET_ID_UNKNOWN__.

#define __XTD_TARGET_ID_UNKNOWN__ 0
#define __XTD_TARGET_ID_CONSOLE_APPLICATION__ 1
#define __XTD_TARGET_ID_GUI_APPLICATION__ 2
#define __XTD_TARGET_ID_TEST_APPLICATION__ 3
#define __XTD_TARGET_ID_INTERFACE_LIBRARY__ 4
#define __XTD_TARGET_ID_MODULE_LIBRARY__ 5
#define __XTD_TARGET_ID_SHARED_LIBRARY__ 6
#define __XTD_TARGET_ID_STATIC_LIBRARY__ 7
#define __XTD_TARGET_ID_CUSTOM_TARGET__ 8

#if !defined(__XTD_CURRENT_TARGET_ID__)
#define __XTD_CURRENT_TARGET_ID__ __XTD_TARGET_ID_UNKNOWN__
#endif
/// @endcond
