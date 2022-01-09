/// @file
/// @brief Contains xtd::reflection::assembly_product_attribute attribute.
#pragma once

#include "../attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class assembly_product_attribute final : public xtd::attribute {
    public:
      explicit assembly_product_attribute(const ustring& product);
      
      /// @cond
      /// Internal used only
      assembly_product_attribute(const ustring& product, const object& executing_assembly);
      /// @endcond
      
      const ustring& product() const {return product_;}
      
    protected:
      std::shared_ptr<object> get_type_id() const override;
      
    private:
      ustring product_;
    };
  }
}

/// @cond
std::shared_ptr<xtd::reflection::assembly_product_attribute>& __assembly_product_attribute__();
/// @endcond

#define assembly_product_(product) \
  xtd::reflection::assembly_product_attribute __assembly_product_attribute {product, xtd::object()}
