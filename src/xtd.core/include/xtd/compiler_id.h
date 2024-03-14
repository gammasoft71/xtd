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
    /// @brief The compiler is Visual Studio.
    visual_studio = 0,
    /// @brief The compiler is Microsoft Visual Studio.
    /// @deprecated Replaced by xtd::compiler_id::visual_studio - Will be removed in version 0.4.0
    microsoft_visual_studio [[deprecated("Replaced by xtd::compiler_id::visual_studio - Will be removed in version 0.4.0")]] = visual_studio,
    /// @brief The compiler is clang.
    clang = 1,
    /// @brief The compiler is gcc.
    gcc = 2,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::compiler_id> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::compiler_id> {{xtd::compiler_id::unknown, "unknown"}, {xtd::compiler_id::visual_studio, "visual_studio"}, {xtd::compiler_id::clang, "clang"}, {xtd::compiler_id::gcc, "gcc"}};}
};
/// @endcond
