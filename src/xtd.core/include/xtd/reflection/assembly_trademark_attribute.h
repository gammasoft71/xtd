/// @file
/// @brief Contains xtd::reflection::assembly_trademark_attribute attribute.
#pragma once

#include "../attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class assembly_trademark_attribute final : public xtd::attribute {
    public:
      explicit assembly_trademark_attribute(const ustring& trademark);
      
      /// @cond
      /// Internal used only
      assembly_trademark_attribute(const ustring& trademark, const object& executing_assembly);
      /// @endcond
      
      const ustring& trademark() const {return trademark_;}
      
    protected:
      std::shared_ptr<object> get_type_id() const override;
      
    private:
      ustring trademark_;
    };
  }
}

/// @cond
std::shared_ptr<xtd::reflection::assembly_trademark_attribute>& __assembly_trademark_attribute__();
/// @endcond

#define assembly_trademark_(trademark) \
  xtd::reflection::assembly_trademark_attribute __assembly_trademark_attribute {trademark, xtd::object()}
