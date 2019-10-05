#pragma once
#include <cstdint>
#include <xtd/ustring.hpp>
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class tab_control {
      public:
        tab_control() = delete;
        static void add_item(intptr_t control, intptr_t page, const ustring& text);
        static void instert_item(intptr_t control, size_t index, intptr_t page, const ustring& text);
        static void delete_item(intptr_t control, size_t index);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
      };
    }
  }
}
