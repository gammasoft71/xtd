#pragma once
#include <xtd/point.hpp>
#include <xtd/size.hpp>
#include <cstdint>

namespace native {
  class form_api {
  public:
    static intptr_t create(const xtd::drawing::size& size);
    static void initialize_application();
    static intptr_t send_message(intptr_t handle, int msg, intptr_t wparam, intptr_t lparam);
  };
}
