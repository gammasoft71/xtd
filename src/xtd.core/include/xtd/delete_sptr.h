/// @file
/// @brief Contains xtd::delete_sptr method.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "null.h"
#include "sptr.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief xtd::delete_sptr operator delete a xtd::sptr or xtd::ptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::delete_ptr with xtd::version class
  /// @code
  /// ptr<xtd::version> version = new_ptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  /// @remarks This operator does not have to be called because when an xtd::sptr object leaves the scope, its value is automatically reset.
  /// @remarks Use it when you want to reset the xtd::sptr object at a specific time.
  template<typename type_t>
  void delete_sptr(sptr<type_t>& ptr) {ptr = null;}
}
