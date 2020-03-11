#pragma once
#include "../create_params.hpp"
#include <vector>
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class checked_list_box static_ {
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
