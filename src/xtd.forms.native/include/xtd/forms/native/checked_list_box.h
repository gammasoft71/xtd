#pragma once
#include "../create_params.h"
#include <vector>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ checked_list_box final static_ {
      public:
        static void begin_update(intptr_t control);
        static void check_state(intptr_t control, size_t index, int check_state);
        static int check_state(intptr_t control, size_t index);
        static void delete_item(intptr_t control, size_t index);
        static void end_update(intptr_t control);
        static void insert_item(intptr_t control, size_t index, const std::string& value, bool checked);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static std::vector<size_t> selected_indices(intptr_t control);
        static void update_item(intptr_t control, size_t index, const std::string& value, bool checked);
      };
    }
  }
}
