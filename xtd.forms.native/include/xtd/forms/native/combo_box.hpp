#pragma once
#include "../create_params.hpp"
#include <vector>

namespace xtd {
  namespace forms {
    namespace native {
      class combo_box {
      public:
        combo_box() = delete;
        static void begin_update(intptr_t control);
        static void delete_item(intptr_t control, size_t index);
        static void end_update(intptr_t control);
        static size_t insert_item(intptr_t control, size_t index, const ustring& value);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
      };
    }
  }
}
