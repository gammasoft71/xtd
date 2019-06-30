#pragma once
#include <cstdint>
#include <string>

namespace native {
  class control_api {
  public:
    static intptr_t create(intptr_t parent);
    static std::string text(intptr_t control);
    static void text(intptr_t control, const std::string& text);
    static void visible(intptr_t control, bool visible);
  };
}
