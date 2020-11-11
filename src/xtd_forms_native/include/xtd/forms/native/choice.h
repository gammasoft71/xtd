#pragma once
#include "../create_params.h"
#include <vector>
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class choice static_ {
      public:
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
