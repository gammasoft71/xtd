/// @file
/// @brief Contains xtd::enum_type enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief the enum type.
  /// @code
  /// enum class enum_type
  /// @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The xtd::enum_typ is used with the xts::enum_register class.
  enum class enum_type {
    /// @brief Enum standard
    standard,
    /// @brief Enum with flags
    flags
  };
}

// This file is included before enum definition so the enum_register is in the enum.h file.
