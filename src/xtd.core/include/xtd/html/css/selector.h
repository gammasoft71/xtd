#pragma once
#include <map>
#include "property.h"

namespace xtd {
  namespace html {
    namespace css {
      /// @cond
      class parser;
      /// @endcond
      
      class selector {
      public:
        explicit selector(const std::string& name) : name_(name) {}
        
        /// @cond
        selector() = default;
        selector(const selector&) = default;
        selector& operator=(const selector&) = default;
        /// @endcond
        
        const std::string& name() const {return name_;}
        const std::map<std::string, property>& properties() const {return properties_;}
        
      private:
        friend class parser;
        std::string name_;
        std::map<std::string, property> properties_;
      };
    }
  }
}
