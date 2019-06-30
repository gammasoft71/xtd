#pragma once
#include <cstdint>

namespace native {
  class form_api {
  public:
    static intptr_t create();
    static void initialize_application();
  };
}
