#pragma once
#include <cstdint>
#include <string>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ settings final static_ {
      public:
        static intptr_t create(const std::string& product_name, const std::string& company_name);
        static void destroy(intptr_t config);
        static void reset(intptr_t config);
        static std::string read(intptr_t config, const std::string& key, const std::string& default_value);
        static void save(intptr_t config);
        static void write(intptr_t config, const std::string& key, const std::string& value);
      };
    }
  }
}
