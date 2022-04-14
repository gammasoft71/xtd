#include "../../../include/xtd/forms/tool_bar_button.h"
#include "../../../include/xtd/forms/tool_bar.h"

using namespace xtd;
using namespace xtd::forms;

tool_bar_button::tool_bar_button(const ustring& text) : text_(text) {
}

tool_bar_button::tool_bar_button(const ustring& text, const event_handler& on_click) : text_(text) {
  click += on_click;
}

tool_bar_button::tool_bar_button(size_t image_index) : image_index_(image_index) {
}

tool_bar_button::tool_bar_button(size_t image_index, const event_handler& on_click) : image_index_(image_index) {
  click += on_click;
}

tool_bar_button::tool_bar_button(const ustring& text, size_t image_index) : text_(text), image_index_(image_index) {
}

tool_bar_button::tool_bar_button(const ustring& text, size_t image_index, const event_handler& on_click) : text_(text), image_index_(image_index) {
  click += on_click;
}

bool tool_bar_button::enabled() const {
  return enabled_;
}

tool_bar_button& tool_bar_button::enabled(bool value) {
  if (enabled_ != value) {
    enabled_ = value;
    if (parent) parent->recreate_handle();
  }
  return *this;
}

const ustring& tool_bar_button::text() const {
  return text_;
}

tool_bar_button& tool_bar_button::text(const xtd::ustring& value) {
  if (text_ != value) {
    text_ = value;
    if (parent) parent->recreate_handle();
  }
  return *this;
}

size_t tool_bar_button::image_index() const {
  return image_index_;
}

tool_bar_button& tool_bar_button::image_index(size_t value) {
  if (image_index_ != value) {
    image_index_ = value;
    if (parent) parent->recreate_handle();
  }
  return *this;
}

void tool_bar_button::perform_click() {
  on_click(xtd::event_args::empty);
}

void tool_bar_button::on_click(const xtd::event_args& e) {
  click(*this, e);
}
