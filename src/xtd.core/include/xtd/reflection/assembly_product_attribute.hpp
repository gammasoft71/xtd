/// @file
/// @brief Contains xtd::reflection::assembly_product_attribute attribute.
#pragma once
#include "../attribute.hpp"
#include "../iequatable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Defines a product name custom attribute for an assembly manifest.
    /// ```cpp
    /// class assembly_product_attribute final : public xtd::attribute, public xtd::iequatable<xtd::reflection::assembly_product_attribute>;
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::attribute → xtd::reflection::assembly_product_attribute
    /// @par Header
    /// ```cpp
    /// #include <xtd/reflection/assembly_product_attribute>
    /// ```
    /// @par Namespace
    /// xtd::reflection
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class assembly_product_attribute final : public xtd::attribute, public xtd::iequatable<xtd::reflection::assembly_product_attribute> {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::reflection::assembly_product_attribute class.
      /// @param product The product information.
      explicit assembly_product_attribute(const string& product);
      /// @}
      
      /// @cond
      /// Internal used only
      assembly_product_attribute(const string& product, const object& executing_assembly);
      /// @endcond
      
      /// @{
      /// @brief Gets product information.
      /// @return A string containing the product information.
      const string& product() const noexcept;
      /// @}

      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const object& obj) const noexcept override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const assembly_product_attribute& other) const noexcept override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      xtd::size get_hash_code() const noexcept override;
      /// @}

    protected:
      xtd::sptr<object> get_type_id() const noexcept override;
      
    private:
      string product_;
    };
  }
}

/// @cond
xtd::sptr<xtd::reflection::assembly_product_attribute>& __assembly_product_attribute__();
/// @endcond

/// @brief Sets the assembly product information. Must be called once in your application.
/// @remarks Use this keyword if you create create assembly informations manually.
/// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
/// @param version The version information.
/// @par Header
/// ```cpp
/// #include <xtd/reflection/assembly_product_attribute>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// The following example shows how to use assembly information manually.
/// @include application_with_manual_assembly_info.cpp
/// @include assembly_info.cpp
#define assembly_product_(product) \
  xtd::reflection::assembly_product_attribute __assembly_product_attribute {product, xtd::object()}
