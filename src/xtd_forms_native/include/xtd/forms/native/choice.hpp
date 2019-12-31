#pragma once
#include "../create_params.hpp"
#include <vector>

namespace xtd {
  namespace forms {
    namespace native {
      class choice {
      public:
        choice() = delete;
        static void begin_update(intptr_t control);
        static void delete_item(intptr_t control, size_t index);
        static void end_update(intptr_t control);
        static void insert_item(intptr_t control, size_t index, const std::string& value);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static void update_item(intptr_t image_list, size_t pos, const std::string& value);
      };
    }
  }
}
