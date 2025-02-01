/// @file
/// @brief Contains xtd::converter alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "delegate.hpp"
#include "int32.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a method that converts an object from one type to another type.
  /// ```cpp
  /// template<class output_t, class input_t>
  /// using converter = xtd::delegate<output_t(input_t input)>;
  /// ```
  /// @tparam input_t The type of object that is to be converted. This type parameter is contravariant. That is, you can use either the type you specified or any type that is less derived.
  /// @tparam output_t he type the input object is to be converted to. This type parameter is covariant. That is, you can use either the type you specified or any type that is more derived.
  /// @param input The object to convert.
  /// @return The `output_t` that represents the converted `input_t`.
  /// @par Header
  /// ```cpp
  /// #include <xtd/converter>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system delegates
  /// @remarks This delegate is used by the xtd::array::convert_all method of the xtd::array class and the xtd::collections::generic::list::convert_all method of the xtd::collections::generic::list <type_t> class to convert each element of the collection from one type to another.
  /// @par Examples
  /// The following example defines a method named `point_f_to_point` that converts a xtd::drawing::point_f structure to a xtd::drawing::point structure. The example then creates a xtd::collections::generic::list <type_t> of xtd::drawing::point_f structures, creates a xtd::converter <point_f, point> delegate to represent the `point_f_to_point` method, and passes the delegate to the xtd::collections::generic::list::convert_all method. The xtd::collections::generic::list::convert_all method passes each element of the input list to the `point_f_to_point` method and puts the converted elements into a new list of Point structures. Both lists are displayed.
  /// @include generic_list_convert_all.cpp
  template<class output_t, class input_t>
  using converter = xtd::delegate<output_t(input_t input)>;
}
