/// @file
/// @brief Contains xtd::create_reference_wrapper_object method.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "reference_wrapper_object.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief xtd::create_reference_wrapper_object operator. This operator creates a xtd::reference_wrapper_object object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::create_reference_wrapper_object with xtd::version class
  /// @code
  /// version ver = version {1, 2, 3};
  /// reference_wrapper_object<version> ver_ref = create_reference_wrapper_object(ver);
  ///
  /// console::write_line("version = {}", ver_ref.to_string());
  /// @endcode
  /// @remarks The xtd::create_reference_wrapper_object is equivalent to [std::ref](https://en.cppreference.com/w/cpp/utility/functional/ref).
  template<typename type_t>
  [[nodiscard]] auto create_reference_wrapper_object(type_t& arg) noexcept -> reference_wrapper_object<type_t> {return reference_wrapper_object<type_t> {arg};}
  /// @brief xtd::create_reference_wrapper_object operator. This operator creates a xtd::reference_wrapper_object object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::create_reference_wrapper_object with xtd::version class
  /// @code
  /// version ver = version {1, 2, 3};
  /// reference_wrapper_object<version> ver_ref = create_reference_wrapper_object(ver);
  ///
  /// console::write_line("version = {}", ver_ref.to_string());
  /// @endcode
  /// @remarks The xtd::create_reference_wrapper_object is equivalent to [std::ref](https://en.cppreference.com/w/cpp/utility/functional/ref).
  template<typename type_t>
  [[nodiscard]] auto create_reference_wrapper_object(reference_wrapper_object<type_t> arg) noexcept -> reference_wrapper_object<type_t> {return arg;}
}
