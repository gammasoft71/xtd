/// @file
/// @brief Contains xtd::iprogress interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "interface.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename type_t>
  /// @brief Defines a provider for progress updates.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core interfaces
  /// @tparam type_t The type of progress update value. This type parameter is contravariant. That is, you can use either the type you specified or any type that is less derived
  class iprogress interface_ {
  public:
    /// @name Methods
    
    /// @{
    /// @brief Reports a progress update.
    /// @param value The value of the updated progress.
    virtual void report(const type_t& value) noexcept = 0;
    /// @}
  };
}
