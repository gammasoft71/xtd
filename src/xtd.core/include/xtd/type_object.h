/// @file
/// @brief Contains xtd::type_object class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "iequatable"
#include "object"
#include "ustring"

/// @cond
namespace xtd {
  class type_object;
  
  namespace __s__ {
    template<typename type_t> xtd::type_object __typeof_() noexcept;
    template<typename type_t> xtd::type_object __typeof_(const type_t& value) noexcept;
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
  /// @code #include <xtd/type_object> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  class type_object : public object, public xtd::iequatable<type_object> {
  public:
    /// @cond
    type_object(const type_object&) noexcept = default;
    type_object& operator=(const type_object&) noexcept;
    /// @endcond

    /// @par Properties
    /// @{
    /// @brief Gets the fully qualified name of the type_object, including the namespace of the type_object.
    /// @return The fully qualified name of the type_object, including the namespace of the type_object.
    /// @remarks For example, the fully qualified name of the xtd::ustring type is xtd::ustring.
    xtd::ustring full_name() const noexcept;

    /// @brief Gets the name of the type_object.
    /// @return The name of the type_object.
    /// @remarks For example, the name of the xtd::ustring type is ustring.
    xtd::ustring name() const noexcept;

    /// @brief Gets the namespace of the type_object.
    /// @return The namespace of the type_object.
    /// @remarks For example, the namespace of the xtd::ustring type is xtd::
    xtd::ustring namespace_() const noexcept;
    /// @}
    
    /// @par Methods
    /// @{
    bool equals(const type_object& type) const noexcept override;

    xtd::ustring to_string() const noexcept override;
    /// @}
    
  private:
    template<typename type_t>
    friend type_object xtd::__s__::__typeof_() noexcept;
    template<typename type_t>
    friend type_object xtd::__s__::__typeof_(const type_t& value) noexcept;
    friend type_object xtd::__s__::__typeof_(const xtd::type& value) noexcept;
    friend class xtd::object;

    type_object() noexcept;
    type_object(const xtd::type& type) noexcept;

    const xtd::type& type_;
  };
  /// @}
}
