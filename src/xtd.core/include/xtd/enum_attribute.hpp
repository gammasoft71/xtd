/// @file
/// @brief Contains xtd::enum_attribute enum class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the enum attribute.
  /// ```cpp
  /// enum class enum_attribute
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/enum_attribute>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The xtd::enum_attribute is used with the xtd::enum_set_attribute struct.
  /// @remarks For more information about enumeration, see [enum class](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/enum_class) guide.
  enum class enum_attribute {
    /// @brief Enum standard attribute. The default value.
    standard,
    /// @brief Enum flags attribute.
    flags
  };
}

// This file is included before enum definition so the enum_register is in the enum.h file.
