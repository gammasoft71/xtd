/// @file
/// @brief Contains xtd::web::css::selector class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
        selector(selector&&) = default;
        selector& operator =(selector&&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto name() const noexcept -> const xtd::string& {return name_;}
        auto name(const xtd::string& name) noexcept -> void {name_ = name;}
        
        [[nodiscard]] auto properties() const noexcept -> const xtd::web::css::property_map& {return properties_;}
        [[nodiscard]] auto properties() noexcept -> xtd::web::css::property_map& {return properties_;}
        auto properties(const xtd::web::css::property_map& properties) noexcept -> void {properties_ = properties;}
        /// @}
        
      private:
        xtd::string name_;
        xtd::web::css::property_map properties_;
      };
    }
  }
}
