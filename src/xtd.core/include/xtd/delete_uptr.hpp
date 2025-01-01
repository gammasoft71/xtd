/// @file
/// @brief Contains xtd::delete_uptr method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "null.hpp"
#include "uptr.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief xtd::delete_uptr operator delete a xtd::uptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::delete_ptr with xtd::version class
  /// @code
  /// uptr<xtd::version> version = new_uptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  /// @remarks This operator does not have to be called because when an xtd::uptr object leaves the scope, its value is automatically reset.
  /// @remarks Use it when you want to reset the xtd::ptr object at a specific time.
  template<typename type_t>
  void delete_uptr(uptr<type_t>& ptr) {ptr = null;}
}
