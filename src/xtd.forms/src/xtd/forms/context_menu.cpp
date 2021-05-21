#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/context_menu.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/context_menu.h"

using namespace xtd;
using namespace xtd::forms;

context_menu::context_menu() {
  data_->handle_ = create_menu_handle();
}

context_menu::~context_menu() {
  if (data_.use_count() == 1) destroy_menu_handle(data_->handle_);
}

intptr_t context_menu::create_menu_handle() {
  return native::context_menu::create();
}

void context_menu::destroy_menu_handle(intptr_t handle) {
  return native::context_menu::destroy(handle);
}
