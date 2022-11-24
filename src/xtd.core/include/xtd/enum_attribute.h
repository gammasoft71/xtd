/// @file
/// @brief Contains xtd::enum_attribute enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the enum attribute.
  /// @code
  /// enum class enum_attribute
  /// @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The xtd::enum_attribute is used with the xtd::enum_set_attribute struct.
  /// @remarks For more information about enumeration, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/enum_class.md">enum class</a> guide.
  enum class enum_attribute {
    /// @brief Enum standard attribute.
    standard,
    /// @brief Enum flags attribute.
    flags
  };
}

// This file is included before enum definition so the enum_register is in the enum.h file.
