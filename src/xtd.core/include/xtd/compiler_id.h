/// @file
/// @brief Contains xtd::compiler_id enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the compiler, supported by an assembly.
  /// @par Header
  /// @code #include <xtd/compiler_id> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see compiler
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
}

/// @cond
template<> struct xtd::enum_register<xtd::compiler_id> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::compiler_id> {{xtd::compiler_id::unknown, "unknown"}, {xtd::compiler_id::microsoft_visual_studio, "microsoft_visual_studio"}, {xtd::compiler_id::clang, "clang"}, {xtd::compiler_id::gcc, "gcc"}};}
};
/// @endcond
