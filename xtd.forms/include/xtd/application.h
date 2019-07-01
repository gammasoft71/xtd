#pragma once
#include "form.h"

namespace xtd {
  namespace forms {
    class application {
    public:
      static void do_events();
      
      static void exit();
      
      static void run();

      static void run(const form& form);
      
    private:
      application() = default;
      static const form* main_form;
    };
  }
}
