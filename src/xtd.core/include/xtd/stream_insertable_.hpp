/// @file
/// @brief Contains xtd::stream_insertable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/stream_insertable> or <xtd/stream_insertable.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the stream insertable concept.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::stream_insertable;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/stream_insertable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @return `true` if value_t has stream insertion operator `<<` specialization.
  /// @par Examples
  /// The following code shows how to use xtd::stream_insertable concept
  /// @include stream_insertable.cpp
  template<typename value_t>
  struct stream_insertable;
}
