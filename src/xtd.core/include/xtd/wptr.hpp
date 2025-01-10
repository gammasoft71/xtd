/// @file
/// @brief Contains xtd::wptr type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief The xtd::uptr object is a weak pointer.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  template<class type_t>
  using wptr = std::weak_ptr<type_t>;
  /// @}
}
