#pragma once
#include <xtd/point.hpp>
#include <xtd/size.hpp>
#include <cstdint>

namespace native {
  class form_api {
  public:
    static intptr_t create(const xtd::drawing::size& size);
    static void initialize_application();
  };
}
