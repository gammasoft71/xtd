/// @file
/// @brief Contains xtd::html::css::selector class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "property_map.h"

namespace xtd {
  namespace html {
    namespace css {
      class selector {
      public:
        explicit selector(const std::string& name) : name_(name) {}
        
        /// @cond
        selector() = default;
        selector(const selector&) = default;
        selector& operator=(const selector&) = default;
        /// @endcond
        
        const std::string& name() const {return name_;}
        void name(const std::string& name) {name_ = name;}

        const xtd::html::css::property_map& properties() const {return properties_;}
        void properties(const xtd::html::css::property_map& properties) {properties_ = properties;}
        xtd::html::css::property_map& properties() {return properties_;}

      private:
        std::string name_;
        xtd::html::css::property_map properties_;
      };
    }
  }
}
