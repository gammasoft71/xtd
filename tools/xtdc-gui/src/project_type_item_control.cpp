#include "project_type_item_control.h"
#include "project_type_items_control.h"

using namespace xtd;
using namespace xtd::forms;
using namespace xtdc_gui;

void project_type_item_control::on_double_click(const event_args& e) {
  user_control::on_double_click(e);
  if (parent().has_value()) dynamic_cast<project_type_items_control&>(parent().value().get()).perform_double_click();
}
