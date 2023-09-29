/// @file
/// @brief Contains xtd::target_id enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

/// @cond
// The following constants are defined in the file xtd_command.cmake.
// If the target project is not built with cmake, each constant must be defined by the build tool like this:
// | Constant                              | Value |
// | ------------------------------------- | ----- |
// | __XTD_TARGET_ID_UNKNOWN__             | 0     |
// | __XTD_TARGET_ID_CONSOLE_APPLICATION__ | 1     |
// | __XTD_TARGET_ID_GUI_APPLICATION__     | 2     |
// | __XTD_TARGET_ID_TEST_APPLICATION__    | 3     |
// | __XTD_TARGET_ID_INTERFACE_LIBRARY__   | 4     |
// | __XTD_TARGET_ID_MODULE_LIBRARY__      | 5     |
// | __XTD_TARGET_ID_SHARED_LIBRARY__      | 6     |
// | __XTD_TARGET_ID_STATIC_LIBRARY__      | 7     |
// | __XTD_TARGET_ID_CUSTOM_TARGET__       | 8     |
#if !defined(__XTD_CURRENT_TARGET_ID__) || !defined(__XTD_TARGET_ID_UNKNOWN__) || !defined(__XTD_TARGET_ID_CONSOLE_APPLICATION__) || !defined(__XTD_TARGET_ID_GUI_APPLICATION__) || !defined(__XTD_TARGET_ID_TEST_APPLICATION__) || !defined(__XTD_TARGET_ID_INTERFACE_LIBRARY__) || !defined(__XTD_TARGET_ID_MODULE_LIBRARY__) || !defined(__XTD_TARGET_ID_SHARED_LIBRARY__) || !defined(__XTD_TARGET_ID_STATIC_LIBRARY__) || !defined(__XTD_TARGET_ID_CUSTOM_TARGET__)
#error "Some variables (like __XTD_TARGET_ID__) are not defined. This is probably because you are not using CMake to generate your project. See the following link for more information: https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.cmake/Overview..."
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
