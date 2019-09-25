#pragma once
#include "../create_params.hpp"
#include <vector>

namespace xtd {
  namespace forms {
    namespace native {
      class checked_list_box {
      public:
        checked_list_box() = delete;
        static void checked(intptr_t control, size_t index, bool checked);
        static void delete_item(intptr_t control, size_t index);
        static void insert_item(intptr_t control, size_t index, const std::string& value, bool checked);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static std::vector<size_t> selected_indices(intptr_t control);
      };
    }
  }
}
