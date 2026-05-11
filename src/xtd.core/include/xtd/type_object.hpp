/// @file
/// @brief Contains xtd::type_object class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "iequatable.hpp"
#include "object.hpp"
#include "ptr.hpp"
#include "ref.hpp"
#include "type.hpp"
#include "string.hpp"

/// @cond
namespace xtd {
  class type_object;
  
  template<typename type_t> auto type_of() noexcept -> const xtd::type_object&;
  auto type_of(const auto& value) noexcept -> xtd::type_object;
  auto type_of(const xtd::type& value) noexcept -> xtd::type_object;
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
  class type_object : public xtd::object, public xtd::iequatable<type_object> {
  public:
    /// @par Public Properties
    /// @{
    /// @brief Gets the fully qualified name of the type_object, including the namespace of the type_object.
    /// @return The fully qualified name of the type_object, including the namespace of the type_object.
    /// @remarks For example, the fully qualified name of the xtd::string type is xtd::string.
    [[nodiscard]] auto full_name() const noexcept -> xtd::string;
    
    /// @brief Gets the name of the type_object.
    /// @return The name of the type_object.
    /// @remarks For example, the name of the xtd::string type is string.
    [[nodiscard]] auto name() const noexcept -> xtd::string;
    
    /// @brief Gets the namespace of the type_object.
    /// @return The namespace of the type_object.
    /// @remarks For example, the namespace of the xtd::string type is xtd::
    [[nodiscard]] auto namespace_() const noexcept -> xtd::string;
    /// @}
    
    /// @par Public Methods
    /// @{
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param type The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const type_object& type) const noexcept -> bool override;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
    /// @}
    
  private:
    template<typename type_t>
    friend auto xtd::type_of() noexcept -> const type_object&;
    friend auto xtd::type_of(const auto& value) noexcept -> type_object;
    friend auto xtd::type_of(const xtd::type& value) noexcept -> type_object;
    friend class xtd::object;
    
    type_object() noexcept;
    type_object(const xtd::type& type) noexcept;
    
    xtd::ptr<xtd::ref<const xtd::type>> type_;
  };
  /// @}
}
