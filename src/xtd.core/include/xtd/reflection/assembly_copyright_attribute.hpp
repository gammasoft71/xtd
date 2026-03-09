/// @file
/// @brief Contains xtd::reflection::assembly_copyright_attribute attribute.
#pragma once
#include "../attribute.hpp"
#include "../iequatable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Defines a copyright custom attribute for an assembly manifest.
    /// ```cpp
    /// class core_export_ assembly_copyright_attribute final : public xtd::attribut : public xtd::attribute, public xtd::iequatable<xtd::reflection::assembly_copyright_attribute>;
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::attribute → xtd::reflection::assembly_copyright_attribute
    /// @par Header
    /// ```cpp
    /// #include <xtd/reflection/assembly_copyright_attribute>
    /// ```
    /// @par Namespace
    /// xtd::reflection
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ assembly_copyright_attribute final : public xtd::attribute, public xtd::iequatable<xtd::reflection::assembly_copyright_attribute> {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::reflection::assembly_copyright_attribute class.
      /// @param copyright The copyright information.
      explicit assembly_copyright_attribute(const xtd::string& copyright);
      /// @}
            
      /// @name Public Properties
      
      /// @{
      /// @brief Gets copyright information.
      /// @return A xtd::string containing the copyright information.
      [[nodiscard]] auto copyright() const noexcept -> const xtd::string&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const assembly_copyright_attribute& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::size override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates the assembly copoyright information. Must be called once in your application.
      /// @remarks Use this keyword if you create create assembly informations manually.
      /// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
      /// @param copyright The copyright information.
      /// @par Examples
      /// The following example shows how to use assembly information manually.
      /// @include application_with_manual_assembly_info.cpp
      /// @include assembly_info.cpp
      static auto create(const xtd::string& copyright) -> assembly_copyright_attribute;
      /// @}
      
    protected:
      [[nodiscard]] auto get_type_id() const noexcept -> xtd::sptr<xtd::object> override;
      
    private:
      xtd::string copyright_;
    };
  }
}

/// @cond
auto __assembly_copyright_attribute__() -> xtd::sptr<xtd::reflection::assembly_copyright_attribute>&;
/// @endcond

/// @brief Creates the assembly copoyright information. Must be called once in your application.
/// @remarks Use this keyword if you create create assembly informations manually.
/// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
/// @param copyright The copyright information.
/// @par Header
/// ```cpp
/// #include <xtd/reflection/assembly_copyright_attribute>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// The following example shows how to use assembly information manually.
/// @include application_with_manual_assembly_info.cpp
/// @include assembly_info.cpp
#define assembly_copyright_(copyright) \
  auto __assembly_copyright_attribute = xtd::reflection::assembly_copyright_attribute::create(copyright)
