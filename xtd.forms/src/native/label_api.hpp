#pragma once
#include <xtd/size.hpp>
#include <cstdint>

namespace native {
  class label_api {
  public:
    static intptr_t create(intptr_t parent, const xtd::drawing::size& size);
  };
}
