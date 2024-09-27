/// @file
/// @brief Contains xtd::new_uptr method.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "uptr.h"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief xtd::new_uptr operator. This operator creates a xtd::uptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_uptr with xtd::version class
  /// @code
  /// uptr<xtd::version> version = new_uptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_uptr is equivalent to [std::make_unique](https://en.cppreference.com/w/cpp/memory/xtd::uptr/make_unique).
  template<typename type_t, typename ...args_t>
  uptr<type_t> new_uptr(args_t&& ... args) {return uptr<type_t> {new type_t(std::forward<args_t>(args)...)};}
  
  /// @cond
  template<typename type_t>
  uptr<type_t> new_uptr(const type_t& arg) {return uptr<type_t> {new type_t(arg)};}
  
  template<typename type_t>
  uptr<type_t> new_uptr() {return uptr<type_t>(new type_t);}
  /// @endcond
}
