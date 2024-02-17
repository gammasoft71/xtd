/// @file
/// @brief Contains xtd::target_id enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

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

#if !defined(__XTD_TARGET_ID_UNKNOWN__)
#define __XTD_TARGET_ID_UNKNOWN__ 0
#endif

#if !defined(__XTD_TARGET_ID_CONSOLE_APPLICATION__)
#define __XTD_TARGET_ID_CONSOLE_APPLICATION__ 1
#endif

#if !defined(__XTD_TARGET_ID_GUI_APPLICATION__)
#define __XTD_TARGET_ID_GUI_APPLICATION__ 2
#endif

#if !defined(__XTD_TARGET_ID_TEST_APPLICATION__)
#define __XTD_TARGET_ID_TEST_APPLICATION__ 3
#endif

#if !defined(__XTD_TARGET_ID_INTERFACE_LIBRARY__)
#define __XTD_TARGET_ID_INTERFACE_LIBRARY__ 4
#endif

#if !defined(__XTD_TARGET_ID_MODULE_LIBRARY__)
#define __XTD_TARGET_ID_MODULE_LIBRARY__ 5
#endif

#if !defined(__XTD_TARGET_ID_SHARED_LIBRARY__)
#define __XTD_TARGET_ID_SHARED_LIBRARY__ 6
#endif

#if !defined(__XTD_TARGET_ID_STATIC_LIBRARY__)
#define __XTD_TARGET_ID_STATIC_LIBRARY__ 7
#endif

#if !defined(__XTD_TARGET_ID_CUSTOM_TARGET__)
#define __XTD_TARGET_ID_CUSTOM_TARGET__ 8
#endif

#if !defined(__XTD_CURRENT_TARGET_ID__)
#define __XTD_CURRENT_TARGET_ID__ __XTD_TARGET_ID_UNKNOWN__
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the target, supported by an assembly.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::target_type
  enum class target_id {
    /// @brief The target is unknown.
    unknown = __XTD_TARGET_ID_UNKNOWN__,
    /// @brief The target is console application.
    console_application = __XTD_TARGET_ID_CONSOLE_APPLICATION__,
    /// @brief The target is gui application.
    gui_application = __XTD_TARGET_ID_GUI_APPLICATION__,
    /// @brief The target is test application.
    test_application = __XTD_TARGET_ID_TEST_APPLICATION__,
    /// @brief The target is interface library.
    interface_library = __XTD_TARGET_ID_INTERFACE_LIBRARY__,
    /// @brief The target is module library.
    module_library = __XTD_TARGET_ID_MODULE_LIBRARY__,
    /// @brief The target is shared library.
    shared_library = __XTD_TARGET_ID_SHARED_LIBRARY__,
    /// @brief The target is static library.
    static_library = __XTD_TARGET_ID_STATIC_LIBRARY__,
    /// @brief The target is custom target.
    custom_target = __XTD_TARGET_ID_CUSTOM_TARGET__,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::target_id> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::target_id> {{xtd::target_id::unknown, "unknown"}, {xtd::target_id::console_application, "console_application"}, {xtd::target_id::gui_application, "gui_application"}, {xtd::target_id::test_application, "test_application"}, {xtd::target_id::interface_library, "interface_library"}, {xtd::target_id::module_library, "module_library"}, {xtd::target_id::shared_library, "shared_library"}, {xtd::target_id::static_library, "static_library"}, {xtd::target_id::custom_target, "custom_target"}};}
};
/// @endcond
