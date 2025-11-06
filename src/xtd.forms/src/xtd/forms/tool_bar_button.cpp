#include "../../../include/xtd/forms/tool_bar_button.hpp"
#include "../../../include/xtd/forms/tool_bar.hpp"
#include "tool_bar_button_data.hpp"

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

tool_bar_button::tool_bar_button() : data_(xtd::new_sptr<data>()) {
}

tool_bar_button::tool_bar_button(const string& text) : data_(xtd::new_sptr<data>()) {
  data_->text = text;
}

std::optional<control_ref> tool_bar_button::control() const noexcept {
  return data_->control ? std::optional<control_ref>(*data_->control) : std::nullopt;
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

std::optional<xtd::ref<xtd::forms::context_menu>> tool_bar_button::drop_down_menu() const noexcept {
  return data_->drop_down_menu ? std::optional<xtd::ref<xtd::forms::context_menu>>(*data_->drop_down_menu) : std::nullopt;
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
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().count() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

size_t tool_bar_button::image_index() const noexcept {
  return data_->image_index;
}

tool_bar_button& tool_bar_button::image_index(size_t value) {
  if (data_->image_index == value) return *this;
  data_->image_index = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().count() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

const string& tool_bar_button::name() const noexcept {
  return data_->name;
}

tool_bar_button& tool_bar_button::name(const xtd::string& value) {
  data_->name = value;
  return *this;
}

std::optional<xtd::ref<tool_bar>> tool_bar_button::parent() const noexcept {
  return data_->parent ? std::optional<xtd::ref<tool_bar>>(*data_->parent) : std::nullopt;
}

bool tool_bar_button::pushed() const noexcept {
  return data_->pushed;
}

tool_bar_button& tool_bar_button::pushed(bool value) {
  if (data_->pushed == value) return *this;
  data_->pushed = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().count() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

xtd::forms::tool_bar_button_style tool_bar_button::style() const noexcept {
  return data_->style;
}

tool_bar_button& tool_bar_button::style(xtd::forms::tool_bar_button_style value) {
  if (data_->style == value) return *this;
  data_->style = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().count() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

const xtd::drawing::rectangle& tool_bar_button::rectangle() const noexcept {
  return data_->rectangle;
}

const any_object& tool_bar_button::tag() const noexcept {
  return data_->tag;
}

tool_bar_button& tool_bar_button::tag(const any_object& value) {
  data_->tag = value;
  return *this;
}

const string& tool_bar_button::text() const noexcept {
  return data_->text;
}

tool_bar_button& tool_bar_button::text(const xtd::string& value) {
  if (data_->text == value) return *this;
  data_->text = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().count() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

const string& tool_bar_button::tool_tip_text() const noexcept {
  return data_->tool_tip_text;
}

tool_bar_button& tool_bar_button::tool_tip_text(const xtd::string& value) {
  if (data_->tool_tip_text == value) return *this;
  data_->tool_tip_text = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().count() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

bool tool_bar_button::visible() const noexcept {
  return data_->visible;
}

tool_bar_button& tool_bar_button::visible(bool value) {
  if (data_->visible == value) return *this;
  data_->visible = value;
  if (data_->parent) data_->parent->update_toolbar_button_control(data_->handle, data_->text, data_->tool_tip_text, data_->image_index  < data_->parent->image_list().images().count() ? data_->parent->image_list().images()[data_->image_index] : xtd::drawing::image::empty, data_->pushed, data_->enabled, data_->visible);
  return *this;
}

tool_bar_button tool_bar_button::create_control(const xtd::string& text, const xtd::forms::control& control) {
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

tool_bar_button tool_bar_button::create_drop_down_button(const xtd::string& text, const xtd::forms::context_menu& drop_down_menu) {
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

tool_bar_button tool_bar_button::create_drop_down_button(const xtd::string& text, size_t image_index, const xtd::forms::context_menu& drop_down_menu) {
  auto result = tool_bar_button {};
  result.drop_down_menu(drop_down_menu);
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::drop_down_button);
  result.text(text);
  return result;
}

tool_bar_button tool_bar_button::create_push_button(const xtd::string& text) {
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

tool_bar_button tool_bar_button::create_push_button(const xtd::string& text, size_t image_index) {
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

tool_bar_button tool_bar_button::create_toggle_button(const xtd::string& text) {
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

tool_bar_button tool_bar_button::create_toggle_button(const xtd::string& text, size_t image_index) {
  auto result = tool_bar_button {};
  result.image_index(image_index);
  result.style(xtd::forms::tool_bar_button_style::toggle_button);
  result.text(text);
  return result;
}

bool tool_bar_button::equals(const object& obj) const noexcept {
  return is<tool_bar_button>(obj) && equals(static_cast<const tool_bar_button&>(obj));
}

bool tool_bar_button::equals(const tool_bar_button& other) const noexcept {
  return data_ == other.data_;
}

xtd::size tool_bar_button::get_hash_code() const noexcept {
  return hash_code::combine(data_);
}

xtd::string tool_bar_button::to_string() const noexcept {
  if (!xtd::string::is_empty(data_->text)) return string::format("{}, style: {}, text: {}", get_type().full_name(), data_->style, data_->text);
  if (!xtd::string::is_empty(data_->name)) return string::format("{}, style: {}, name: {}", get_type().full_name(), data_->style, data_->name);
  return string::format("{}, style: {}", get_type().full_name(), data_->style);
}

xtd::uptr<xtd::object> tool_bar_button::clone() const {
  auto result = xtd::new_uptr<tool_bar_button>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).chars().c_str());
  return result;
}
