/// @file
/// @brief Contains xtd::reflection::assembly_guid_attribute attribute.
#pragma once
#include "../attribute"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Specifies the guid of the assembly being attributed.
    /// @code
    /// class core_export_ assembly_guid_attribute final : public xtd::attribute
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::attribute → xtd::reflection::assembly_guid_attribute
    /// @par Header
    /// @code #include <xtd/reflection/assembly_guid_attribute> @endcode
    /// @par Namespace
    /// xtd::reflection
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ assembly_guid_attribute final : public xtd::attribute {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::reflection::assembly_guid_attribute class.
      /// @param guid The guid information.
      explicit assembly_guid_attribute(const ustring& guid);
      /// @}
      
      /// @cond
      /// Internal used only
      assembly_guid_attribute(const ustring& guid, const object& executing_assembly);
      /// @endcond
      
      /// @{
      /// @brief Gets guid information.
      /// @return A string containing the guid information.
      const ustring& guid() const noexcept;
      /// @}
      
    protected:
      std::shared_ptr<object> get_type_id() const noexcept override;
      
    private:
      ustring guid_;
    };
  }
}

/// @cond
std::shared_ptr<xtd::reflection::assembly_guid_attribute>& __assembly_guid_attribute__();
/// @endcond

/// @brief Sets the assembly guid information. Must be called once in your application.
/// @remarks Use this keyword if you create create assembly informations manually.
/// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
/// @param version The version information.
/// @par Header
/// @code #include <xtd/reflection/assembly_guid_attribute> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// The following example shows how to use assembly information manually.
/// @include application_with_manual_assembly_info.cpp
/// @include assembly_info.cpp
#define assembly_guid_(guid) \
  xtd::reflection::assembly_guid_attribute __assembly_guid_attribute {guid, xtd::object()}
