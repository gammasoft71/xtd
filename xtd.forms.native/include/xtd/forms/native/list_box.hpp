#pragma once
#include "../create_params.hpp"
#include <vector>

namespace xtd {
  namespace forms {
    namespace native {
      class list_box {
      public:
        list_box() = delete;
        static drawing::color default_back_color();
        static drawing::color default_fore_color();
        static void delete_item(intptr_t control, size_t index);
        static size_t insert_item(intptr_t control, size_t index, const std::string& item);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static std::vector<size_t> selected_indices(intptr_t control);
      };
    }
  }
}
