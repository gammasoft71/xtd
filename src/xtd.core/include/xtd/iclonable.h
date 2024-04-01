/// @file
/// @brief Contains xtd::iclonable interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "interface.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename type_t>
  /// @brief Supports cloning, which creates a new instance of a class with the same value as an existing instance.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core interfaces
  /// @remarks The xtd::iclonable interface enables you to provide a customized implementation that creates a copy of an existing object. The xtd::iclonable interface contains one member, the xtd::iclonable::clone method, which is intended to provide cloning support beyond that supplied by xtd::object::memberwise_clone. For more information about cloning, deep versus shallow copies, and examples, see the xtd::object::memberwise_clone method.
  /// @par Notes to Implementers
  /// The xtd::iclonable interface simply requires that your implementation of the xtd::iclonable::clone() method return a copy of the current object instance. It does not specify whether the cloning operation performs a deep copy, a shallow copy, or something in between. Nor does it require all property values of the original instance to be copied to the new instance. For example, the xtd::iclonable::clone() method performs a shallow copy of all properties; it always sets this property value to false in the cloned object. Because callers of xtd::iclonable::clone() cannot depend on the method performing a predictable cloning operation, we recommend that xtd::iclonable not be implemented in public APIs.
  class iclonable interface_ {
  public:
    /// @name Public Methods
    
    /// @{
    /// @brief Creates a new object that is a copy of the current instance.
    /// @return A new object that is a copy of this instance.
    /// @remarks The resulting clone must be of the same type as, or compatible with, the original instance.
    /// @remarks An implementation of xtd::iclonable::clone can perform either a deep copy or a shallow copy. In a deep copy, all objects are duplicated; in a shallow copy, only the top-level objects are duplicated and the lower levels contain references. Because callers of xtd::iclonable::clone cannot depend on the method performing a predictable cloning operation, we recommend that xtd::iclonable not be implemented in public APIs.
    /// @remarks See xtd::object::memberwise_clone for more information on cloning, deep versus shallow copies, and examples.
    virtual std::unique_ptr<xtd::object> clone() const noexcept = 0;
    /// @}
  };
}
