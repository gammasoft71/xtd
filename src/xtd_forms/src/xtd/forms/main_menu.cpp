#include <xtd/forms/native/main_menu.hpp>
#include "../../../include/xtd/forms/main_menu.hpp"

using namespace xtd;
using namespace xtd::forms;

main_menu::main_menu() {
  data_->handle_ = create_menu_handle();
}

main_menu::~main_menu() {
  if (data_.use_count() == 1) destroy_menu_handle(data_->handle_);
}

intptr_t main_menu::create_menu_handle() {
  return native::main_menu::create();
}

void main_menu::destroy_menu_handle(intptr_t handle) {
  return native::main_menu::destroy(handle);
}
