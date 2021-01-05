#pragma once
#include <map>
#include "property.h"

namespace xtd {
  namespace html {
    namespace css {
      class selector {
      public:
        using properties_t = std::map<std::string, property>;
        explicit selector(const std::string& name) : name_(name) {}
        
        /// @cond
        selector() = default;
        selector(const selector&) = default;
        selector& operator=(const selector&) = default;
        /// @endcond
        
        const std::string& name() const {return name_;}
        void name(const std::string& name) {name_ = name;}
        const properties_t& properties() const {return properties_;}
        properties_t& properties() {return properties_;}

      private:
        std::string name_;
        properties_t properties_;
      };
    }
  }
}
