#include "../../../include/xtd/forms/component.hpp"
#include <xtd/new_sptr>

using namespace xtd;
using namespace xtd::forms;

struct component::data {
  bool can_raise_event = true;
  bool design_mode = false;
};

component::component() : data_(xtd::new_sptr<data>()) {
}

bool component::can_raise_events() const noexcept {
  return data_->can_raise_event;
}

bool component::design_mode() const noexcept {
  return data_->design_mode;
}
