#pragma once
#include <xtd/point.h>
#include <xtd/size.h>
#include <cstdint>

namespace native {
  class form_api {
  public:
    static intptr_t create(const xtd::drawing::size& size);
    static void initialize_application();
  };
}
