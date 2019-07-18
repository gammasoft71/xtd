#pragma once
#include <xtd/size.hpp>
#include <cstdint>

namespace native {
  class text_box_api {
  public:
    static intptr_t create(intptr_t parent, const xtd::drawing::size& size);
    static std::string text(intptr_t control);
    static void text(intptr_t control, const std::string& text);
  };
}
