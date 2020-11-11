#pragma once
#include "interface.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @interface IComparable
  /// @brief Defines a generalized comparison method that a value type or class implements to create a type-specific comparison method.
  /// @par Library
  /// xtd.core
  /// @ingroup SwitchCore
  template <typename type_t>
  class icomparable interface_ {
  public:
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// |-------------------|------------------------------------|
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    virtual int32_t compare_to(const object& obj) const = 0;
    
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// |-------------------|------------------------------------|
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    virtual int32_t compare_to(const type_t& obj) const = 0;
    
    ///@cond
    // Not correct for an interface but necessary for C++ language.
    bool operator<(const type_t& obj) const { return compare_to(obj) < 0; }
    bool operator<=(const type_t& obj) const { return compare_to(obj) <= 0; }
    bool operator>(const type_t& obj) const { return compare_to(obj) > 0; }
    bool operator>=(const type_t& obj) const { return compare_to(obj) >= 0; }
    ///@endcond
  };
}
