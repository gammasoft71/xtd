/// @file
/// @brief Contains xtd::web::css::selector class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "property_map"
#include "../../object"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      class selector : public object {
      public:
        /// @name Constructors
        
        /// @{
        explicit selector(const xtd::ustring& name) : name_(name) {}
        /// @}
        
        /// @cond
        selector() = default;
        selector(const selector&) = default;
        selector& operator =(const selector&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        const xtd::ustring& name() const noexcept {return name_;}
        void name(const xtd::ustring& name) noexcept {name_ = name;}
        
        const xtd::web::css::property_map& properties() const noexcept {return properties_;}
        void properties(const xtd::web::css::property_map& properties) noexcept {properties_ = properties;}
        xtd::web::css::property_map& properties() noexcept {return properties_;}
        /// @}
        
      private:
        xtd::ustring name_;
        xtd::web::css::property_map properties_;
      };
    }
  }
}
