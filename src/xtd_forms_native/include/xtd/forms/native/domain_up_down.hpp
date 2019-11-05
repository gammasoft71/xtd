#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class domain_up_down {
      public:
        domain_up_down() = delete;
        static void delete_item(intptr_t control, size_t pos);
        static void insert_item(intptr_t control, size_t pos, const ustring& value);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
      };
    }
  }
}
