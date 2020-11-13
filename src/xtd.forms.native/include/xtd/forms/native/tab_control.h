#pragma once
#include <cstdint>
#include <string>
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class tab_control static_ {
      public:
        static void add_item(intptr_t control, intptr_t page, const std::string& text);
        static void delete_item(intptr_t control, size_t index);
        static void delete_item(intptr_t control, intptr_t page);
        static void image_list(intptr_t control, intptr_t image_list);
        static void insert_item(intptr_t control, size_t index, intptr_t page);
        static void page_image_index(intptr_t control, size_t index, size_t image_index);
        static void page_text(intptr_t control, size_t index, const std::string& text);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static void update_item(intptr_t control, size_t index, intptr_t page);
      };
    }
  }
}
