/// @file
/// @brief Contains xtd::read_only_span and xtd::span definitions.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include "../dynamic_extent.hpp"
#include "../usize.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a non-owning view over a contiguous sequence of objects.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t, xtd::usize extent = dynamic_extent>
  /// class read_only_span : public xtd::object, public xtd::iequatable<xtd::read_only_span<type_t, extent>>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/read_only_span>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The class template xtd::read_only_span describes an object that can refer to a contiguous sequence of objects with the first element of the sequence at position zero. A read_only_span can either have a static extent, in which case the number of elements in the sequence is known at compile-time and encoded in the type, or a dynamic extent.
  /// @remarks The referenced data can't be modified through a xtd::read_only_span object. To prevent this, use a xtd::only_span`:
  /// ```cpp
  /// int numbers[] = {0, 1, 2};
  /// read_only_span<int> read_only_span_numbers = numbers;
  /// read_only_span_numbers[0] = 42; // ERROR: read_only_span_numbers[0] is read-only
  /// span<int> span_numbers = numbers;
  /// span_numbers[0] = 42; // numbers == {42, 1, 2};
  /// ```
  template<typename type_t, xtd::usize extent = xtd::dynamic_extent>
  class read_only_span;

  /// @brief Represents a non-owning view over a contiguous sequence of objects.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t, xtd::usize extent = dynamic_extent>
  /// class span : public xtd::object, public xtd::iequatable<xtd::span<type_t, extent>>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/span>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The class template xtd::span describes an object that can refer to a contiguous sequence of objects with the first element of the sequence at position zero. A span can either have a static extent, in which case the number of elements in the sequence is known at compile-time and encoded in the type, or a dynamic extent.
  /// @remarks The referenced data can be modified through a xtd::span object. To prevent this, construct a xtd::span over a `const type_t`:
  /// ```cpp
  /// int numbers[] = {0, 1, 2};
  /// span<int> span_numbers = numbers;
  /// span_numbers[0] = 42; // numbers == {42, 1, 2};
  /// span<const int> cspan_numbers = numbers;
  /// cspan_numbers[0] = 0; // ERROR: cspan_numbers[0] is read-only
  /// ```
  ///
  /// @par Examples
  /// Create a span from memory.
  /// @include span_from_memory.cpp
  ///
  /// Create a span over an array.
  /// @include span_over_array.cpp
  template<typename type_t, xtd::usize extent = xtd::dynamic_extent>
  class span;
}
