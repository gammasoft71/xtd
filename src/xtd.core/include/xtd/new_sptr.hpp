/// @file
/// @brief Contains xtd::new_sptr method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "sptr.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief xtd::news_sptr operator creates a xtd::sptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_sptr with xtd::version class
  /// @code
  /// sptr<xtd::version> version = new_sptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_sptr is equivalent to [std::make_shared](https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared).
  template<typename type_t, typename ...args_t>
  sptr<type_t> new_sptr(args_t&& ... args) {return sptr<type_t> {new type_t(std::forward<args_t>(args)...)};}

  /// @cond
  template<typename type_t>
  sptr<type_t> new_sptr(const type_t& arg) {return sptr<type_t> {new type_t(arg)};}
  
  template<typename type_t>
  sptr<type_t> new_sptr() {return sptr<type_t>(new type_t);}
  /// @endcond
}
