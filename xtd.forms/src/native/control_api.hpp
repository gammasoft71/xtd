#pragma once
#include <xtd/point.hpp>
#include <xtd/size.hpp>
#include <cstdint>
#include <string>

namespace native {
  class control_api {
  public:
    static intptr_t create(intptr_t parent, const xtd::drawing::size& size);
    static xtd::drawing::point location(intptr_t control);
    static void location(intptr_t control, const xtd::drawing::point& location);
    static xtd::drawing::size size(intptr_t control);
    static void size(intptr_t control, const xtd::drawing::size& size);
    static std::string text(intptr_t control);
    static void text(intptr_t control, const std::string& text);
    static bool visible(intptr_t control);
    static void visible(intptr_t control, bool visible);
  };
}
