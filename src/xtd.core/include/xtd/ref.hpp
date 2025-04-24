/// @file
/// @brief Contains xtd::ref type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "reference_wrapper_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief The xtd::ref object is a reference wrapper.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// This example shows to use xtd::ref with xtd::version class
  /// @code
  /// version ver = version {1, 2, 3};
  /// ref<version> ver_ref = create_ref(ver);
  ///
  /// console::write_line("version = {}", ver_ref.to_string());
  /// @endcode
  template<class type_t>
  using ref = xtd::reference_wrapper_object<type_t>;
  /// @}
}
