/// @file
/// @brief Contains xtd::reflection::assembly_title_attribute attribute.
#pragma once
#include "../attribute.hpp"
#include "../iequatable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Specifies a title for an assembly.
    /// ```cpp
    /// class core_export_ assembly_title_attribute final : public xtd::attribute, public xtd::iequatable<xtd::reflection::assembly_title_attribute>;
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::attribute → xtd::reflection::assembly_title_attribute
    /// @par Header
    /// ```cpp
    /// #include <xtd/reflection/assembly_title_attribute>
    /// ```
    /// @par Namespace
    /// xtd::reflection
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ assembly_title_attribute final : public xtd::attribute, public xtd::iequatable<xtd::reflection::assembly_title_attribute> {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::reflection::assembly_title_attribute class.
      /// @param title The title information.
      explicit assembly_title_attribute(const string& title);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets title information.
      /// @return A string containing the title information.
      [[nodiscard]] auto title() const noexcept -> const xtd::string&;
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
      [[nodiscard]] auto equals(const assembly_title_attribute& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates the assembly title information. Must be called once in your application.
      /// @remarks Use this keyword if you create create assembly informations manually.
      /// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
      /// @param title The title information.
      /// @par Examples
      /// The following example shows how to use assembly information manually.
      /// @include application_with_manual_assembly_info.cpp
      /// @include assembly_info.cpp
      static auto create(const string& title) -> assembly_title_attribute;
      /// @}
      
    protected:
      [[nodiscard]] auto get_type_id() const noexcept -> xtd::sptr<xtd::object> override;
      
    private:
      string title_;
    };
  }
}

/// @cond
auto __assembly_title_attribute__() -> xtd::sptr<xtd::reflection::assembly_title_attribute>&;
/// @endcond

/// @brief Creates the assembly title information. Must be called once in your application.
/// @remarks Use this keyword if you create create assembly informations manually.
/// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
/// @param title The title information.
/// @par Header
/// ```cpp
/// #include <xtd/reflection/assembly_title_attribute>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// The following example shows how to use assembly information manually.
/// @include application_with_manual_assembly_info.cpp
/// @include assembly_info.cpp
#define assembly_title_(title) \
  auto __assembly_title_attribute = xtd::reflection::assembly_title_attribute::create(title)

