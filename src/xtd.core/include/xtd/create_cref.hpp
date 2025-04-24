/// @file
/// @brief Contains xtd::create_cref method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "ref.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief xtd::new_uptr operator. This operator creates a xtd::ref object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_uptr with xtd::version class
  /// @code
  /// version ver = version {1, 2, 3};
  /// ref<const version> ver_ref = create_cref(ver);
  ///
  /// console::write_line("version = {}", ver_ref.to_string());
  /// @endcode
  /// @remarks The xtd::new_uptr is equivalent to [std::cref](https://en.cppreference.com/w/cpp/utility/functional/ref).
  template<class type_t>
  ref<const type_t> create_cref(const type_t& arg) noexcept {return ref<const type_t> {arg};}
  /// @brief xtd::new_uptr operator. This operator creates a xtd::ref object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_uptr with xtd::version class
  /// @code
  /// version ver = version {1, 2, 3};
  /// ref<const version> ver_ref = create_cref(ver);
  ///
  /// console::write_line("version = {}", ver_ref.to_string());
  /// @endcode
  /// @remarks The xtd::new_uptr is equivalent to [std::cref](https://en.cppreference.com/w/cpp/utility/functional/ref).
  template<class type_t>
  ref<const type_t> create_ref(ref<type_t> arg) noexcept {return arg;}
}
