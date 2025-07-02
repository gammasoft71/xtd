/// @file
/// @brief Contains xtd::attribute class.
#pragma once
#include "guid.hpp"
#include "object.hpp"
#include "string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the base class for custom attributes.
  /// ```cpp
  /// class attribute : public xtd::object
  /// ```
  /// @par Inheritance
  /// xtd::object → xtd::attribute
  /// @par Header
  /// ```cpp
  /// #include <xtd/attribute>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class attribute : public xtd::object {
  public:
    /// @cond
    attribute(const attribute&) = default;
    attribute(attribute&&) = default;
    attribute& operator =(const attribute&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief When implemented in a derived class, gets a unique identifier for this attribute.
    /// @remarks As implemented, this identifier is merely the Type of the attribute. However, it is intended that the unique identifier be used to identify two attributes of the same type.
    xtd::sptr<object> type_id() const noexcept;
    /// @}
    
  protected:
    /// @name Protected constructors
    
    /// @{
    /// @brief Initializes a new instance of the attribute class.
    /// @remarks This constructor is only called by classes that derive from attribute.
    attribute() = default;
    /// @}
    
    /// @name Protected Methods
    
    /// @{
    /// @brief When implemented in a derived class, gets a unique identifier for this attribute.
    /// @remarks As implemented, this identifier is merely the Type of the attribute. However, it is intended that the unique identifier be used to identify two attributes of the same type.
    virtual xtd::sptr<object> get_type_id() const noexcept = 0;
    /// @}
  };
}
