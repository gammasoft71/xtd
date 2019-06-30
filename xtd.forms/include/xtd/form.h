#pragma once
#include "control.h"

namespace xtd {
  namespace forms {
    class form : public control {
    public:
      form();
      
      void create_handle() override;
    };
  }
}
