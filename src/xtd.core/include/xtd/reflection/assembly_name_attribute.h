/// @file
/// @brief Contains xtd::reflection::assembly_name_attribute attribute.
#pragma once
#include "../attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Specifies a name for an assembly.
    /// @code
    /// class core_export_ assembly_name_attribute final : public xtd::attribute
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::attribute → xtd::reflection::assembly_name_attribute
    /// @par Header
    /// @code #include <xtd/reflection/assembly_name_attribute> @endcode
    /// @par Namespace
    /// xtd::reflection
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ assembly_name_attribute final : public xtd::attribute {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::reflection::assembly_name_attribute class.
      /// @param name The name information.
      explicit assembly_name_attribute(const ustring& name);
      
      /// @cond
      /// Internal used only
      assembly_name_attribute(const ustring& name, const object& executing_assembly);
      /// @endcond
      
      /// @{
      /// @brief Gets name information.
      /// @return A string containing the name information.
      const ustring& name() const noexcept;
      /// @}
      
    protected:
      std::shared_ptr<object> get_type_id() const noexcept override;
      
    private:
      ustring name_;
    };
  }
}

/// @cond
std::shared_ptr<xtd::reflection::assembly_name_attribute>& __assembly_name_attribute__();
/// @endcond

/// @brief Sets the assembly name information. Must be called once in your application.
/// @remarks Use this keyword if you create create assembly informations manually.
/// @remarks Use CMake assembly macro if you want create assembly informations with CMake scripts.
/// @param version The version information.
/// @par Header
/// @code #include <xtd/reflection/assembly_name_attribute> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// The following example shows how to use assembly information manually.
/// @include application_with_manual_assembly_info.cpp
/// @include assembly_info.cpp
#define assembly_name_(name) \
  xtd::reflection::assembly_name_attribute __assembly_name_attribute {name, xtd::object()}

