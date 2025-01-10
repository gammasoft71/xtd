/// @file
/// @brief Contains xtd::sptr type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief The xtd::sptr object is a shared pointer.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// This example shows to use xtd::sptr with xtd::version class
  /// @code
  /// sptr<xtd::version> version = new_sptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  template<class type_t>
  using sptr = std::shared_ptr<type_t>;
  /// @}
}
