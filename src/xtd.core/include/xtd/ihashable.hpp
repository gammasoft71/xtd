/// @file
/// @brief Contains xtd::ihashable interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "interface.hpp"
#include "size.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines a generalized method that a value type or class implements to create a type-specific method for determining equality of instances.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core interfaces
  /// @remarks This interface is implemented by types whose values can be hashed (for example, the numeric and string classes). A value type or class implements the `get_hash_code` method to create a type-specific method suitable for determining the hash code of the instance.
  /// @remarks The xtd::ihashable interface defines the xtd::ihashable::get_hash_code method, which determines the hash code of the instance.
  /// @par Examples
  /// The following example shows how to use xtd::ihashable interface.
  /// @include ihashable.cpp
  class ihashable : public interface {
  public:
    /// @name Public Methods
    
    /// @{
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    virtual xtd::size get_hash_code() const noexcept = 0;
    /// @}
  };
}
