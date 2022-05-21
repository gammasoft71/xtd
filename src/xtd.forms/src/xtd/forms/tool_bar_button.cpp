#include "../../../include/xtd/forms/tool_bar_button.h"
#include "../../../include/xtd/forms/tool_bar.h"

using namespace xtd;
using namespace xtd::forms;

tool_bar_button::tool_bar_button(const ustring& text) noexcept {
  data_->text = text;
}

std::optional<std::reference_wrapper<xtd::forms::control>> tool_bar_button::control() const {
  return data_->control ? std::optional<std::reference_wrapper<xtd::forms::control>>(*data_->control) : std::optional<std::reference_wrapper<xtd::forms::control>>();
}

tool_bar_button& tool_bar_button::control(const xtd::forms::control& value) {
  if (!data_->control || data_->control != &value) {
    data_->control = const_cast<xtd::forms::control*>(&value);
    if (data_->parent) data_->parent->post_recreate_handle();
  }
  return *this;
}

tool_bar_button& tool_bar_button::control(std::nullptr_t value) {
  if (data_->control) {
    data_->control = nullptr;
    if (data_->parent) data_->parent->post_recreate_handle();
  }
  return *this;
}

bool tool_bar_button::enabled() const {
  return data_->enabled;
}

tool_bar_button& tool_bar_button::enabled(bool value) {
  if (data_->enabled != value) {
    data_->enabled = value;
    if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  }
  return *this;
}

size_t tool_bar_button::image_index() const {
  return data_->image_index;
}

tool_bar_button& tool_bar_button::image_index(size_t value) {
  if (data_->image_index != value) {
    data_->image_index = value;
    if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  }
  return *this;
}

bool tool_bar_button::pushed() const {
  return data_->pushed;
}

tool_bar_button& tool_bar_button::pushed(bool value) {
  if (data_->pushed != value) {
    data_->pushed = value;
    if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  }
  return *this;
}

xtd::forms::tool_bar_button_style tool_bar_button::style() const {
  return data_->style;
}

tool_bar_button& tool_bar_button::style(xtd::forms::tool_bar_button_style value) {
  if (data_->style != value) {
    data_->style = value;
    if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  }
  return *this;
}

const ustring& tool_bar_button::text() const {
  return data_->text;
}

tool_bar_button& tool_bar_button::text(const xtd::ustring& value) {
  if (data_->text != value) {
    data_->text = value;
    if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  }
  return *this;
}

bool tool_bar_button::visible() const {
  return data_->visible;
}

tool_bar_button& tool_bar_button::visible(bool value) {
  if (data_->visible != value) {
    data_->visible = value;
    if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  }
  return *this;
}

tool_bar_button tool_bar_button::create_control(const xtd::ustring& text, const xtd::forms::control& control) {
  tool_bar_button result;
  result.control(control);
  result.style(xtd::forms::tool_bar_button_style::control);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_control(const xtd::forms::control& control) {
  tool_bar_button result;
  result.control(control);
  result.style(xtd::forms::tool_bar_button_style::control);
  return result;
}

tool_bar_button tool_bar_button::create_push_button(const xtd::ustring& text) {
  tool_bar_button result;
  result.style(xtd::forms::tool_bar_button_style::push_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_push_button(const xtd::ustring& text, const xtd::event_handler& on_click) {
  tool_bar_button result;
  result.style(xtd::forms::tool_bar_button_style::push_button);
  result.text(text);
  result.click += on_click;
  return result;
}

tool_bar_button tool_bar_button::create_push_button(size_t image_index) {
  tool_bar_button result;
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::push_button);
  return result;
}

tool_bar_button tool_bar_button::create_push_button(size_t image_index, const xtd::event_handler& on_click) {
  tool_bar_button result;
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::push_button);
  result.click += on_click;
  return result;
}

tool_bar_button tool_bar_button::create_push_button(const xtd::ustring& text, size_t image_index) {
  tool_bar_button result;
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::push_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_push_button(const xtd::ustring& text, size_t image_index, const xtd::event_handler& on_click) {
  tool_bar_button result;
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::push_button);
  result.text(text);
  result.click += on_click;
  return result;
}

tool_bar_button tool_bar_button::create_separator() {
  tool_bar_button result;
  result.style(xtd::forms::tool_bar_button_style::separator);
  return result;
}

tool_bar_button tool_bar_button::create_stretchable_separator() {
  tool_bar_button result;
  result.style(xtd::forms::tool_bar_button_style::stretchable_separator);
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(const xtd::ustring& text) {
  tool_bar_button result;
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(const xtd::ustring& text, const xtd::event_handler& on_click) {
  tool_bar_button result;
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  result.text(text);
  result.click += on_click;
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(size_t image_index) {
  tool_bar_button result;
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(size_t image_index, const xtd::event_handler& on_click) {
  tool_bar_button result;
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  result.click += on_click;
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(const xtd::ustring& text, size_t image_index) {
  tool_bar_button result;
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(const xtd::ustring& text, size_t image_index, const xtd::event_handler& on_click) {
  tool_bar_button result;
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  result.text(text);
  result.click += on_click;
  return result;
}

void tool_bar_button::perform_click() {
  on_click(xtd::event_args::empty);
}

void tool_bar_button::on_click(const xtd::event_args& e) {
  click(*this, e);
}
