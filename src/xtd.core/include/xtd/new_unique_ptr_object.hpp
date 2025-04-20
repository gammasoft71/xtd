/// @file
/// @brief Contains xtd::new_unique_ptr_object method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "unique_ptr_object.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief xtd::new_unique_ptr_object operator creates a xtd::unique_ptr_object object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_unique_ptr_object with xtd::version class
  /// @code
  /// unique_ptr_object<xtd::version> version = new_unique_ptr_object<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_unique_ptr_object(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_unique_ptr_object is equivalent to [std::make_shared](https://en.cppreference.com/w/cpp/memory/unique_ptr/make_shared) with xtd::unique_ptr_object instead [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr).
  template<class type_t, class ...args_t>
  unique_ptr_object<type_t> new_unique_ptr_object(args_t&& ... args) {return unique_ptr_object<type_t> {new type_t(std::forward<args_t>(args)...)};}

  /// @brief xtd::new_unique_ptr_object operator creates a xtd::unique_ptr_object object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_unique_ptr_object with xtd::version class
  /// @code
  /// unique_ptr_object<xtd::version> version = new_unique_ptr_object<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_unique_ptr_object(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_unique_ptr_object is equivalent to [std::make_shared](https://en.cppreference.com/w/cpp/memory/unique_ptr/make_shared) with xtd::unique_ptr_object instead [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr).
  template<class type_t>
  unique_ptr_object<type_t> new_unique_ptr_object(const type_t& arg) {return unique_ptr_object<type_t> {new type_t(arg)};}
  
  /// @brief xtd::new_unique_ptr_object operator creates a xtd::unique_ptr_object object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_unique_ptr_object with xtd::version class
  /// @code
  /// unique_ptr_object<xtd::version> version = new_unique_ptr_object<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_unique_ptr_object(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_unique_ptr_object is equivalent to [std::make_shared](https://en.cppreference.com/w/cpp/memory/unique_ptr/make_shared) with xtd::unique_ptr_object instead [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr).
  template<class type_t>
  unique_ptr_object<type_t> new_unique_ptr_object() {return unique_ptr_object<type_t>(new type_t);}
}
