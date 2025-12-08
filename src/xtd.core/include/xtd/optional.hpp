/// @file
/// @brief Contains xtd::optional type.
#pragma once
/// @cond
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
/// @endcond

#include <optional>
#include "generic_stream_output.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the optional alias on [std::optional](https://en.cppreference.com/w/cpp/utility/optional).
  /// @par Header
  /// ```cpp
  /// #include <xtd/optional>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  template<class type_t>
  using optional = std::optional<type_t>;
}
