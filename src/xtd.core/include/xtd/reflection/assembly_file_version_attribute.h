/// @file
/// @brief Contains xtd::reflection::assembly_file_version_attribute attribute.
#pragma once

#include "../attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class assembly_file_version_attribute final : public xtd::attribute {
    public:
      explicit assembly_file_version_attribute(const ustring& version);
      
      /// @cond
      /// Internal used only
      assembly_file_version_attribute(const ustring& version, const object& executing_assembly);
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
std::shared_ptr<xtd::reflection::assembly_file_version_attribute>& __assembly_file_version_attribute__();
/// @endcond

#define assembly_file_version_(version) \
  xtd::reflection::assembly_file_version_attribute __assembly_file_version_attribute {version, xtd::object()}

