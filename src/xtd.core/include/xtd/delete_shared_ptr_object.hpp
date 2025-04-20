/// @file
/// @brief Contains xtd::delete_shared_ptr_object method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "null.hpp"
#include "shared_ptr_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief xtd::delete_shared_ptr_object operator delete a xtd::shared_ptr_object or xtd::ptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::delete_ptr with xtd::version class
  /// @code
  /// shared_ptr_object<xtd::version> version = new_shared_ptr_object<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_shared_ptr_object(version); // Not mandatory.
  /// @endcode
  /// @remarks This operator does not have to be called because when an xtd::shared_ptr_object object leaves the scope, its value is automatically reset.
  /// @remarks Use it when you want to reset the xtd::shared_ptr_object object at a specific time.
  template<class type_t>
  void delete_shared_ptr_object(shared_ptr_object<type_t>& ptr) {ptr = null;}
}
