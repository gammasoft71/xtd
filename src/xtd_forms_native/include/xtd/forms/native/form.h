#pragma once
#include "../create_params.h"
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class form static_ {
      public:
        static void activate(intptr_t form);
        static void close(intptr_t form);
        static void full_screen(intptr_t form, bool full_screen);
        static void icon(intptr_t form, intptr_t icon);
        static bool maximize(intptr_t form);
        static void maximize(intptr_t form, bool maximize);
        static bool minimize(intptr_t form);
        static void minimize(intptr_t form, bool minimize);
        static void menu(intptr_t form, intptr_t menu);
        static void restore(intptr_t form);
        static int32_t show_dialog(intptr_t form);
        static void show_dialog_sheet(intptr_t form);
        static void end_dialog(intptr_t form, int32_t result);
        static void virtual_size(intptr_t control, const drawing::size& size);
      };
    }
  }
}
