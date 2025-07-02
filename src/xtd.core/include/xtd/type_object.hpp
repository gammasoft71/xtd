/// @file
/// @brief Contains xtd::type_object class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "iequatable.hpp"
#include "object.hpp"
#include "type.hpp"
#include "string.hpp"

/// @cond
namespace xtd {
  class type_object;
  
  namespace __s__ {
    template<class type_t> xtd::type_object __typeof_() noexcept;
    template<class type_t> xtd::type_object __typeof_(const type_t& value) noexcept;
    xtd::type_object __typeof_(const xtd::type& value) noexcept;
  }
}
/// @endcond


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Represents type declarations: class types, interface types, array types, value types, enumeration types, type parameters, generic type definitions, and open or closed constructed generic types.
  /// @par Header
  /// ```cpp
  /// #include <xtd/type_object>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  class type_object : public object, public xtd::iequatable<type_object> {
  public:
    /// @cond
    type_object(const type_object&) noexcept = default;
    type_object& operator=(const type_object&) noexcept;
    /// @endcond
    
    /// @par Public Properties
    /// @{
    /// @brief Gets the fully qualified name of the type_object, including the namespace of the type_object.
    /// @return The fully qualified name of the type_object, including the namespace of the type_object.
    /// @remarks For example, the fully qualified name of the xtd::string type is xtd::string.
    xtd::string full_name() const noexcept;
    
    /// @brief Gets the name of the type_object.
    /// @return The name of the type_object.
    /// @remarks For example, the name of the xtd::string type is string.
    xtd::string name() const noexcept;
    
    /// @brief Gets the namespace of the type_object.
    /// @return The namespace of the type_object.
    /// @remarks For example, the namespace of the xtd::string type is xtd::
    xtd::string namespace_() const noexcept;
    /// @}
    
    /// @par Public Methods
    /// @{
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const object& obj) const noexcept override;
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param type The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const type_object& type) const noexcept override;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    xtd::size get_hash_code() const noexcept override;
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    xtd::string to_string() const noexcept override;
    /// @}
    
  private:
    template<class type_t>
    friend type_object xtd::__s__::__typeof_() noexcept;
    template<class type_t>
    friend type_object xtd::__s__::__typeof_(const type_t& value) noexcept;
    friend type_object xtd::__s__::__typeof_(const xtd::type& value) noexcept;
    friend class xtd::object;
    
    type_object() noexcept;
    type_object(const xtd::type& type) noexcept;
    
    const xtd::type& type_;
  };
  /// @}
}
