/// @file
/// @brief Contains xtd::uptr type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief The xtd::uptr object is a unique pointer.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// This example shows to use xtd::uptr with xtd::version class
  /// @code
  /// uptr<xtd::version> version = newu_uptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  template<class type_t>
  using uptr = std::unique_ptr<type_t>;
  /// @}
}
