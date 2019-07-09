#pragma once
#include <xtd/point.hpp>
#include <xtd/size.hpp>
#include <cstdint>

namespace native {
  class button_api {
  public:
    static intptr_t create(intptr_t parent, const xtd::drawing::size& size);
  };
}
