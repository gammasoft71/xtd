/// @file
/// @brief Contains xtd::reflection::assembly_file_version_attribute attribute.
#pragma once
#include "../attribute.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Instructs a compiler to use a specific version number for the Win32 file version resource. The Win32 file version is not required to be the same as the assembly's version number.
    /// ```cpp
    /// class core_export_ assembly_file_version_attribute final : public xtd::attribute
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::attribute → xtd::reflection::assembly_file_version_attribute
    /// @par Header
    /// ```cpp
    /// #include <xtd/reflection/assembly_file_version_attribute>
    /// ```
    /// @par Namespace
    /// xtd::reflection
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class assembly_file_version_attribute final : public xtd::attribute {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::reflection::assembly_file_version_attribute class.
      /// @param version The file version information.
      explicit core_export_ assembly_file_version_attribute(const string& version);
      /// @}
      
      /// @cond
      /// Internal used only
      assembly_file_version_attribute(const string& version, const object& executing_assembly);
      /// @endcond
      
      /// @{
      /// @brief Gets version information.
      /// @return A string containing the version information.
      const string& version() const noexcept;
      /// @}
      
    protected:
      xtd::sptr<object> get_type_id() const noexcept override;
      
    private:
      string version_;
    };
  }
}

/// @cond
xtd::sptr<xtd::reflection::assembly_file_version_attribute>& __assembly_file_version_attribute__();
/// @endcond

/// @brief Sets the assembly file version information. Must be called once in your application.
/// @remarks Use this keyword if you create create assembly informations manually.
/// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
/// @param version The version information.
/// @par Header
/// ```cpp
/// #include <xtd/reflection/assembly_file_version_attribute>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// The following example shows how to use assembly information manually.
/// @include application_with_manual_assembly_info.cpp
/// @include assembly_info.cpp
#define assembly_file_version_(version) \
  xtd::reflection::assembly_file_version_attribute __assembly_file_version_attribute {version, xtd::object()}

