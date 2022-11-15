/// @file
/// @brief Contains xtd::architecture_id enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the processor architecture, supported by an assembly.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see operating_system
  enum class architecture_id {
    /// @brief The processor architecture is unknown.
    unknown = -1,
    /// @brief The processor architecture is x86 (Intel or amd).
    x86,
    /// @brief The processor architecture is ARM.
    arm,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::architecture_id> {
  void operator()(xtd::enum_collection<xtd::architecture_id>& values, xtd::enum_attribute& attribute) {values = {{xtd::architecture_id::unknown, "unknown"}, {xtd::architecture_id::x86, "x86"}, {xtd::architecture_id::arm, "arm"}};}
};
/// @endcond
