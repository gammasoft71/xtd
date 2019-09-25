#include "../../../include/xtd/forms/list_control.hpp"

using namespace xtd;
using namespace xtd::forms;

list_control& list_control::value_member(const std::string &value_member) {
  if (this->value_member_ != value_member) {
    this->value_member_ = value_member;
    this->on_value_member_changed(event_args::empty);
  }
  return *this;
}
