/// @file
/// @brief Contains xtd::reflection::assembly_copyright_attribute attribute.
#pragma once

#include "../attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class assembly_copyright_attribute final : public xtd::attribute {
    public:
      explicit assembly_copyright_attribute(const ustring& copyright);
      
      /// @cond
      /// Internal used only
      assembly_copyright_attribute(const ustring& copyright, const object& executing_assembly);
      /// @endcond
      
      const ustring& copyright() const {return copyright_;}
      
    protected:
      std::shared_ptr<object> get_type_id() const override;
      
    private:
      ustring copyright_;
    };
  }
}

/// @cond
std::shared_ptr<xtd::reflection::assembly_copyright_attribute>& __assembly_copyright_attribute__();
/// @endcond

#define assembly_copyright_(copyright) \
  xtd::reflection::assembly_copyright_attribute __assembly_copyright_attribute {copyright, xtd::object()}


