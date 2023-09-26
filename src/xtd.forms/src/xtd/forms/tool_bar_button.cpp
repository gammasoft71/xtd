#include "../../../include/xtd/forms/tool_bar_button"
#include "../../../include/xtd/forms/tool_bar"
#include "tool_bar_button_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

tool_bar_button::tool_bar_button() : data_(std::make_shared<data>()) {
}

tool_bar_button::tool_bar_button(const ustring& text) : data_(std::make_shared<data>()) {
  data_->text = text;
}

optional<reference_wrapper<forms::control>> tool_bar_button::control() const noexcept {
  return data_->control ? optional<reference_wrapper<forms::control>>(*data_->control) : nullopt;
}

tool_bar_button& tool_bar_button::control(const xtd::forms::control& value) {
  if (data_->control && data_->control == &value) return *this;
  data_->control = const_cast<xtd::forms::control*>(&value);
  if (data_->parent) data_->parent->post_recreate_handle();
  return *this;
}

tool_bar_button& tool_bar_button::control(std::nullptr_t value) {
  if (!data_->control) return *this;
  data_->control = nullptr;
  if (data_->parent) data_->parent->post_recreate_handle();
  return *this;
}

std::optional<std::reference_wrapper<xtd::forms::context_menu>> tool_bar_button::drop_down_menu() const noexcept {
  return data_->drop_down_menu ? std::optional<std::reference_wrapper<xtd::forms::context_menu>>(*data_->drop_down_menu) : std::optional<std::reference_wrapper<xtd::forms::context_menu>>();
}

tool_bar_button& tool_bar_button::drop_down_menu(const xtd::forms::context_menu& value) {
  if (data_->drop_down_menu.has_value() && data_->drop_down_menu.value() == value) return *this;
  data_->drop_down_menu = const_cast<xtd::forms::context_menu&>(value);
  if (data_->parent) data_->parent->post_recreate_handle();
  return *this;
}

tool_bar_button& tool_bar_button::drop_down_menu(std::nullptr_t value) {
  if (!data_->drop_down_menu.has_value()) return *this;
  data_->drop_down_menu.reset();
  if (data_->parent) data_->parent->post_recreate_handle();
  return *this;
}

bool tool_bar_button::enabled() const noexcept {
  return data_->enabled;
}

tool_bar_button& tool_bar_button::enabled(bool value) {
  if (data_->enabled == value) return *this;
  data_->enabled = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

size_t tool_bar_button::image_index() const noexcept {
  return data_->image_index;
}

tool_bar_button& tool_bar_button::image_index(size_t value) {
  if (data_->image_index == value) return *this;
  data_->image_index = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

const ustring& tool_bar_button::name() const noexcept {
  return data_->name;
}

tool_bar_button& tool_bar_button::name(const xtd::ustring& value) {
  data_->name = value;
  return *this;
}

optional<reference_wrapper<tool_bar>> tool_bar_button::parent() const noexcept {
  return data_->parent ? optional<reference_wrapper<tool_bar>>(*data_->parent) : nullopt;
}

bool tool_bar_button::pushed() const noexcept {
  return data_->pushed;
}

tool_bar_button& tool_bar_button::pushed(bool value) {
  if (data_->pushed == value) return *this;
  data_->pushed = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

xtd::forms::tool_bar_button_style tool_bar_button::style() const noexcept {
  return data_->style;
}

tool_bar_button& tool_bar_button::style(xtd::forms::tool_bar_button_style value) {
  if (data_->style == value) return *this;
  data_->style = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

const xtd::drawing::rectangle& tool_bar_button::rectangle() const noexcept {
  return data_->rectangle;
}

std::any tool_bar_button::tag() const noexcept {
  return data_->tag;
}

tool_bar_button& tool_bar_button::tag(std::any value) {
  data_->tag = value;
  return *this;
}

const ustring& tool_bar_button::text() const noexcept {
  return data_->text;
}

tool_bar_button& tool_bar_button::text(const xtd::ustring& value) {
  if (data_->text == value) return *this;
  data_->text = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

const ustring& tool_bar_button::tool_tip_text() const noexcept {
  return data_->tool_tip_text;
}

tool_bar_button& tool_bar_button::tool_tip_text(const xtd::ustring& value) {
  if (data_->tool_tip_text == value) return *this;
  data_->tool_tip_text = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

bool tool_bar_button::visible() const noexcept {
  return data_->visible;
}

tool_bar_button& tool_bar_button::visible(bool value) {
  if (data_->visible == value) return *this;
  data_->visible = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().size() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

tool_bar_button tool_bar_button::create_control(const xtd::ustring& text, const xtd::forms::control& control) {
  auto result = tool_bar_button {};
  result.control(control);
  result.style(xtd::forms::tool_bar_button_style::control);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_control(const xtd::forms::control& control) {
  auto result = tool_bar_button {};
  result.control(control);
  result.style(xtd::forms::tool_bar_button_style::control);
  return result;
}

tool_bar_button tool_bar_button::create_drop_down_button(const xtd::ustring& text, const xtd::forms::context_menu& drop_down_menu) {
  auto result = tool_bar_button {};
  result.drop_down_menu(drop_down_menu);
  result.style(xtd::forms::tool_bar_button_style::drop_down_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_drop_down_button(size_t image_index, const xtd::forms::context_menu& drop_down_menu) {
  auto result = tool_bar_button {};
  result.drop_down_menu(drop_down_menu);
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::drop_down_button);
  return result;
}

tool_bar_button tool_bar_button::create_drop_down_button(const xtd::ustring& text, size_t image_index, const xtd::forms::context_menu& drop_down_menu) {
  auto result = tool_bar_button {};
  result.drop_down_menu(drop_down_menu);
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::drop_down_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_push_button(const xtd::ustring& text) {
  auto result = tool_bar_button {};
  result.style(xtd::forms::tool_bar_button_style::push_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_push_button(size_t image_index) {
  auto result = tool_bar_button {};
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::push_button);
  return result;
}

tool_bar_button tool_bar_button::create_push_button(const xtd::ustring& text, size_t image_index) {
  auto result = tool_bar_button {};
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::push_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_separator() {
  auto result = tool_bar_button {};
  result.style(xtd::forms::tool_bar_button_style::separator);
  return result;
}

tool_bar_button tool_bar_button::create_stretchable_separator() {
  auto result = tool_bar_button {};
  result.style(xtd::forms::tool_bar_button_style::stretchable_separator);
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(const xtd::ustring& text) {
  auto result = tool_bar_button {};
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(size_t image_index) {
  auto result = tool_bar_button {};
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  return result;
}

tool_bar_button tool_bar_button::create_toggle_button(const xtd::ustring& text, size_t image_index) {
  auto result = tool_bar_button {};
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  result.text(text);
  return result;
}

bool tool_bar_button::equals(const tool_bar_button& other) const noexcept {
  return data_ == other.data_;
}

xtd::ustring tool_bar_button::to_string() const noexcept {
  if (!data_->text.empty()) return ustring::format("{}, style: {}, text: {}", get_type().full_name(), data_->style, data_->text);
  if (!data_->name.empty()) return ustring::format("{}, style: {}, name: {}", get_type().full_name(), data_->style, data_->name);
  return ustring::format("{}, style: {}", get_type().full_name(), data_->style);
}
