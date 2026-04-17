/// @file
/// @brief Contains xtd::reflection::assembly_configuration_attribute attribute.
#pragma once
#include "../attribute.hpp"
#include "../iequatable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Specifies the build configuration, such as retail or debug, for an assembly.
    /// ```cpp
    /// class core_export_ assembly_configuration_attribute final : public xtd::attribute, public xtd::iequatable<xtd::reflection::assembly_configuration_attribute>;
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::attribute → xtd::reflection::assembly_configuration_attribute
    /// @par Header
    /// ```cpp
    /// #include <xtd/reflection/assembly_configuration_attribute>
    /// ```
    /// @par Namespace
    /// xtd::reflection
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ assembly_configuration_attribute final : public xtd::attribute, public xtd::iequatable<xtd::reflection::assembly_configuration_attribute> {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xttd::reflection::assembly_configuration_attribute class.
      /// @param configuration The assembly configuration.
      explicit assembly_configuration_attribute(const xtd::string& configuration);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets assembly configuration information.
      /// @return A string containing the assembly configuration information.
      [[nodiscard]] auto configuration() const noexcept -> const xtd::string&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const assembly_configuration_attribute& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates the assembly configuration information. Must be called once in your application.
      /// @remarks Use this keyword if you create create assembly informations manually.
      /// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
      /// @param configuration The configuration information.
      /// @par Examples
      /// The following example shows how to use assembly information manually.
      /// @include application_with_manual_assembly_info.cpp
      /// @include assembly_info.cpp
      static auto create(const xtd::string& configuration) -> assembly_configuration_attribute;
      /// @}
      
    protected:
      [[nodiscard]] auto get_type_id() const noexcept -> xtd::sptr<xtd::object> override;
      
    private:
      xtd::string configuration_;
    };
  }
}

/// @cond
auto __assembly_configuration_attribute__() -> xtd::sptr<xtd::reflection::assembly_configuration_attribute>&;
/// @endcond

/// @brief Creates the assembly configuration information. Must be called once in your application.
/// @remarks Use this keyword if you create create assembly informations manually.
/// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
/// @param configuration The configuration information.
/// @par Header
/// ```cpp
/// #include <xtd/reflection/assembly_configuration_attribute>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// The following example shows how to use assembly information manually.
/// @include application_with_manual_assembly_info.cpp
/// @include assembly_info.cpp
#define assembly_configuration_(configuration) \
  auto __assembly_configuration_attribute = xtd::reflection::assembly_configuration_attribute::create(configuration)

