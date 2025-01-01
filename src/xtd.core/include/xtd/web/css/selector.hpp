/// @file
/// @brief Contains xtd::web::css::selector class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "property_map.hpp"
#include "../../object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      class selector : public object {
      public:
        /// @name Public Constructors
        
        /// @{
        explicit selector(const xtd::string& name) : name_(name) {}
        /// @}
        
        /// @cond
        selector() = default;
        selector(const selector&) = default;
        selector& operator =(const selector&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        const xtd::string& name() const noexcept {return name_;}
        void name(const xtd::string& name) noexcept {name_ = name;}
        
        const xtd::web::css::property_map& properties() const noexcept {return properties_;}
        void properties(const xtd::web::css::property_map& properties) noexcept {properties_ = properties;}
        xtd::web::css::property_map& properties() noexcept {return properties_;}
        /// @}
        
      private:
        xtd::string name_;
        xtd::web::css::property_map properties_;
      };
    }
  }
}
