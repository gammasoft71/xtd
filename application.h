#pragma once
#include "native/application_api.h"
#include "form.h"

namespace xtd {
  namespace forms {
    class application {
    public:
      static void exit() {native::application_api::exit();}
      
      static void run() {
        native::application_api::run();
      }

      static void run(const form& form) {
        native::application_api::main_form(form.handle());
        run();
      }
      
    private:
      application() = default;
      static const form* main_form;
    };
  }
}
