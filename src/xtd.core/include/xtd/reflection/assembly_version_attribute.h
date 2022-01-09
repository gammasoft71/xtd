/// @file
/// @brief Contains xtd::reflection::assembly_version_attribute attribute.
#pragma once

#include "../attribute.h"

/// @cond
/// Internal used only
#if !defined(__XTD_ASSEMBLY_VERSION__)
#  define __XTD_ASSEMBLY_VERSION__ "1.0.0"
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class assembly_version_attribute final : public xtd::attribute {
    public:
      explicit assembly_version_attribute(const ustring& version);
      
      /// @cond
      /// Internal used only
      assembly_version_attribute(const ustring& version, const object& executing_assembly);
      /// @endcond
      
      const ustring& version() const {return version_;}
      
    protected:
      std::shared_ptr<object> get_type_id() const override;
      
    private:
      ustring version_;
    };
  }
}

/// @cond
std::shared_ptr<xtd::reflection::assembly_version_attribute>& __assembly_version_attribute__();
/// @endcond

#define assembly_version_(version) \
  xtd::reflection::assembly_version_attribute __assembly_version_attribute {xtd::ustring(version) == "" || xtd::ustring(version) == "*" ? __XTD_ASSEMBLY_VERSION__ : version, xtd::object()}

