#pragma once
#include "control.h"

namespace xtd {
  namespace forms {
    class form : public control {
    public:
      form();

      xtd::drawing::size default_size() const override {return{300, 300};}

      void create_handle() override;
    };
  }
}
