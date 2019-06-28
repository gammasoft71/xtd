#pragma once
#include "native/form_api.h"
#include "control.h"

namespace xtd {
  namespace forms {
    class form : public control {
    public:
      form() {
        native::form_api::initialize_application(); // Must be first
        create_control();
      }
      
      void create_handle() override {this->handle_ = native::form_api::create();}
      
      void show() const {native::control_api::visible(this->handle_, true);}
    };
  }
}
