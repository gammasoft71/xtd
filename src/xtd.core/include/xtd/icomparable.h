/// @file
/// @brief Contains xtd::icomparable interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "interface.h"
#include "types.h"
#include "comparison_operators.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines a generalized comparison method that a value type or class implements to create a type-specific comparison method.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core interfaces
  /// @par Examples
  /// The following example shows how to use xtd::icomparable interface.
  /// @include icomparable.cpp
  template <typename type_t>
  class icomparable : public interface, public comparison_operators<type_t, icomparable<type_t>> {
  public:
    /// @name Public Methods
    
    /// @{
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// | ----------------- | ---------------------------------- |
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    virtual int32 compare_to(const type_t& obj) const noexcept = 0;
    /// @}
  };
}
