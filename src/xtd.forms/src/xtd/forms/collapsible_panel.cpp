#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/collapsible_panel>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/collapsible_panel.hpp"
#include <xtd/optional>

using namespace xtd;
using namespace xtd::forms;

struct collapsible_panel::data {
  forms::border_sides border_sides = forms::border_sides::all;
  std::optional<forms::border_style> border_style;
  bool expanded = false;
};

collapsible_panel::collapsible_panel() : data_(xtd::new_sptr<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  set_can_focus(false);
  set_style(control_styles::selectable | control_styles::all_painting_in_wm_paint, false);
  set_style(control_styles::supports_transparent_back_color, true);
  set_state(state::tab_stop, false);
}

bool collapsible_panel::auto_size() const noexcept {
  return true;
}


forms::border_sides collapsible_panel::border_sides() const noexcept {
  return data_->border_sides;
}

collapsible_panel& collapsible_panel::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides == border_sides) return *this;
  data_->border_sides = border_sides;
  if (control_appearance() == forms::control_appearance::standard) invalidate();
  return *this;
}

forms::border_style collapsible_panel::border_style() const noexcept {
  return data_->border_style.value_or(forms::border_style::none);
}

collapsible_panel& collapsible_panel::border_style(forms::border_style border_style) {
  if (this->border_style() == border_style) return *this;
  data_->border_style = border_style;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

collapsible_panel& collapsible_panel::border_style(std::nullptr_t) {
  if (!data_->border_style) return *this;
  data_->border_style.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

bool collapsible_panel::expanded() const noexcept {
  return data_->expanded;
}

collapsible_panel& collapsible_panel::expanded(bool expanded) {
  if (data_->expanded == expanded) return *this;
  data_->expanded = expanded;
  if (is_handle_created()) native::collapsible_panel::expanded(handle(), data_->expanded);
  on_expanded_changed(event_args::empty);
  return *this;
}

const xtd::drawing::size& collapsible_panel::client_size() const noexcept {
  return control::client_size();
}

xtd::drawing::size collapsible_panel::size() const noexcept {
  return control::size();
}

void collapsible_panel::collapse() {
  expanded(false);
}

collapsible_panel collapsible_panel::create() {
  return collapsible_panel {};
}

collapsible_panel collapsible_panel::create(const drawing::point& location) {
  auto result = collapsible_panel {};
  result.location(location);
  return result;
}

collapsible_panel collapsible_panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = collapsible_panel {};
  result.location(location);
  result.size(size);
  return result;
}

collapsible_panel collapsible_panel::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = collapsible_panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

collapsible_panel collapsible_panel::create(const xtd::string& text) {
  auto result = collapsible_panel {};
  result.text(text);
  return result;
}

collapsible_panel collapsible_panel::create(const xtd::string& text, const drawing::point& location) {
  auto result = collapsible_panel {};
  result.text(text);
  result.location(location);
  return result;
}

collapsible_panel collapsible_panel::create(const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = collapsible_panel {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

collapsible_panel collapsible_panel::create(const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = collapsible_panel {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

collapsible_panel collapsible_panel::create(const xtd::string& text, bool expanded) {
  auto result = collapsible_panel {};
  result.text(text);
  result.expanded(expanded);
  return result;
}

collapsible_panel collapsible_panel::create(const xtd::string& text, bool expanded, const drawing::point& location) {
  auto result = collapsible_panel {};
  result.text(text);
  result.expanded(expanded);
  result.location(location);
  return result;
}

collapsible_panel collapsible_panel::create(const xtd::string& text, bool expanded, const drawing::point& location, const drawing::size& size) {
  auto result = collapsible_panel {};
  result.text(text);
  result.expanded(expanded);
  result.location(location);
  result.size(size);
  return result;
}

collapsible_panel collapsible_panel::create(const xtd::string& text, bool expanded, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = collapsible_panel {};
  result.text(text);
  result.expanded(expanded);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent) {
  auto result = collapsible_panel {};
  result.parent(parent);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const drawing::point& location) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const xtd::string& text) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.text(text);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const xtd::string& text, const drawing::point& location) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const xtd::string& text, bool expanded) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.text(text);
  result.expanded(expanded);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const xtd::string& text, bool expanded, const drawing::point& location) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.text(text);
  result.expanded(expanded);
  result.location(location);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const xtd::string& text, bool expanded, const drawing::point& location, const drawing::size& size) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.text(text);
  result.expanded(expanded);
  result.location(location);
  result.size(size);
  return result;
}

collapsible_panel collapsible_panel::create(const control& parent, const xtd::string& text, bool expanded, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = collapsible_panel {};
  result.parent(parent);
  result.text(text);
  result.expanded(expanded);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void collapsible_panel::expand() {
  expanded(true);
}

forms::create_params collapsible_panel::create_params() const noexcept {
  auto create_params = control::create_params();
  
  create_params.class_name("collapsiblepanel");
  
  if (control_appearance() == forms::control_appearance::system) {
    if (border_style() == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (border_style() != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  }
  
  return create_params;
}

xtd::uptr<xtd::object> collapsible_panel::clone() const {
  auto result = xtd::new_uptr<collapsible_panel>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()));
  return result;
}

drawing::size collapsible_panel::measure_control() const noexcept {
  auto bounds = drawing::rectangle {};
  for (auto item : controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}

void collapsible_panel::on_control_added(const control_event_args& e) {
  control::on_control_added(e);
  if (expanded()) {
    expanded(false);
    expanded(true);
  }
}

void collapsible_panel::on_control_removed(const control_event_args& e) {
  control::on_control_removed(e);
  /*
  if (expanded()) {
    expanded(false);
    expanded(true);
  }
   */
}

void collapsible_panel::on_expanded_changed(const xtd::event_args& e) {
  if (parent().has_value()) parent().value().get().perform_layout();
  expanded_changed(*this, e);
}

void collapsible_panel::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  size(native::control::size(handle()));
}

void collapsible_panel::wnd_proc(message& message) {
  switch (message.msg) {
    case  WM_COMMAND: wm_command_control(message); break;
    default: control::wnd_proc(message);
  }
}

void collapsible_panel::wm_command_control(message& message) {
  data_->expanded = native::collapsible_panel::expanded(handle());
  size(native::control::size(handle()));
  on_expanded_changed(event_args::empty);
}

control& collapsible_panel::auto_size(bool auto_size) {
  return control::auto_size(auto_size);
}

control& collapsible_panel::client_size(const xtd::drawing::size& client_size) {
  return control::size(client_size);
}

control& collapsible_panel::size(const xtd::drawing::size& size) {
  return control::size(size);
}
