#include "../../../include/xtd/forms/list_control.h"

using namespace xtd;
using namespace xtd::forms;

list_control::list_control() {
  //back_color_ = default_back_color();
  //fore_color_ = default_fore_color();
}

list_control& list_control::value_member(const std::string &value_member) {
  if (this->value_member_ != value_member) {
    this->value_member_ = value_member;
    this->on_value_member_changed(event_args::empty);
  }
  return *this;
}
