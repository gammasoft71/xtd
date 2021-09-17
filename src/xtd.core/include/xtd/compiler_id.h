/// @file
/// @brief Contains xtd::compiler_id enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the compiler, supported by an assembly.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see compileer
  enum class compiler_id {
    /// @brief The compiler is unknown.
    unknown = -1,
    /// @brief The compiler is Microsoft Visual Studio.
    microsoft_visual_studio,
    /// @brief The compiler is clang.
    clang,
    /// @brief The compiler is gcc.
    gcc,
  };

  inline std::ostream& operator<<(std::ostream& os, compiler_id value) {return os << to_string(value, {{compiler_id::unknown, "unknown"}, {compiler_id::microsoft_visual_studio, "microsoft_visual_studio"}, {compiler_id::clang, "clang"}, {compiler_id::gcc, "gcc"}});}
  inline std::wostream& operator<<(std::wostream& os, compiler_id value) {return os << to_string(value, {{compiler_id::unknown, L"unknown"}, {compiler_id::microsoft_visual_studio, L"microsoft_visual_studio"}, {compiler_id::clang, L"clang"}, {compiler_id::gcc, L"gcc"}});}
}
