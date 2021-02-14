#pragma once
#include "../create_params.h"
#include <vector>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ combo_box final static_ {
      public:
        static void begin_update(intptr_t control);
        static void delete_item(intptr_t control, size_t index);
        static void end_update(intptr_t control);
        static void insert_item(intptr_t control, size_t index, const std::string& value);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static void update_item(intptr_t control, size_t pos, const std::string& value);
      };
    }
  }
}
