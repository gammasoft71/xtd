/// @file
/// @brief Contains xtd::compiler_id enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

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
    msvc,
    /// @brief The compiler is clang.
    clang,
    /// @brief The compiler is gcc.
    gcc,
    /// @brief The compiler is Apple clang.
    apple_clang,
    /// @brief The compiler is Microsoft Visual Studio.
    /// @deprecated Replaced by xtd::compiler_id::msvc - Will be removed in version 0.4.0
    microsoft_visual_studio [[deprecated("Replaced by xtd::compiler_id::msvc - Will be removed in version 0.4.0")]] = msvc,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::compiler_id> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::compiler_id> {{xtd::compiler_id::unknown, "unknown"}, {xtd::compiler_id::msvc, "msvc"}, {xtd::compiler_id::clang, "clang"}, {xtd::compiler_id::gcc, "gcc"}, {xtd::compiler_id::apple_clang, "apple_clang"}};}
};
/// @endcond
