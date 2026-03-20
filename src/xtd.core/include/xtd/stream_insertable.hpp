/// @file
/// @brief Contains xtd::stream_insertable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "is_stream_insertable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Concept stream_insertable.
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
  /// The following code shows how to use xtd::stream_insertable conceps
  /// @include stream_insertable.cpp
  template<typename value_t>
  concept stream_insertable = xtd::is_stream_insertable_v<value_t>;
}
