#include "../../../include/xtd/forms/command_link_button.h"
#include "../../../include/xtd/forms/form.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/command_link_button>
#include <xtd/forms/native/button_styles>
#include <xtd/forms/native/control>
#include <xtd/forms/native/window_definitions>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/size_f>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

struct command_link_button::data {
  tuple<ustring, ustring> texts;
  ustring text;
};

command_link_button::command_link_button() : data_ {make_shared<data>()} {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  text_align(content_alignment::middle_left);
  set_style(control_styles::standard_click | control_styles::standard_double_click, false);
}

forms::auto_size_mode command_link_button::auto_size_mode() const noexcept {
  return get_auto_size_mode();
}

command_link_button& command_link_button::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

ustring& command_link_button::main_text() const noexcept {
  return get<0>(data_->texts);
}

command_link_button& command_link_button::main_text(const ustring& value) {
  return texts({value, get<1>(data_->texts)});
}

ustring& command_link_button::supplementary_text() const noexcept {
  return get<1>(data_->texts);
}

command_link_button& command_link_button::supplementary_text(const ustring& value) {
  return texts({get<0>(data_->texts), value});
}

ustring& command_link_button::text() const noexcept {
  return data_->text;
}

control& command_link_button::text(const ustring& value) {
  auto separator_index = value.find_first_of("\n");
  if (separator_index == ustring::npos) return texts({value, ustring::empty_string});
  return texts({value.remove(separator_index), value.substring(separator_index + 1)});
}

tuple<ustring, ustring> command_link_button::texts() const noexcept {
  return data_->texts;
}

command_link_button& command_link_button::texts(const tuple<ustring, ustring>& texts) {
  if (data_->texts == texts) return *this;
  data_->texts = texts;
  data_->text = ustring::format("{}{}{}", get<0>(texts), environment::new_line(), get<1>(texts));
  if (is_handle_created()) native::command_link_button::texts(handle(), data_->texts);
  on_text_changed(event_args::empty);
  return *this;
}

command_link_button command_link_button::create() {
  return command_link_button {};
}

command_link_button command_link_button::create(const ustring& text) {
  auto result = command_link_button {};
  result.text(text);
  return result;
}

command_link_button command_link_button::create(const ustring& text, const point& location) {
  auto result = command_link_button {};
  result.text(text);
  result.location(location);
  return result;
}

command_link_button command_link_button::create(const ustring& text, const point& location, const drawing::size& size) {
  auto result = command_link_button {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

command_link_button command_link_button::create(const ustring& text, const point& location, const drawing::size& size, const ustring& name) {
  auto result = command_link_button {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

command_link_button command_link_button::create(const tuple<ustring, ustring>& texts) {
  auto result = command_link_button {};
  result.texts(texts);
  return result;
}

command_link_button command_link_button::create(const tuple<ustring, ustring>& texts, const point& location) {
  auto result = command_link_button {};
  result.texts(texts);
  result.location(location);
  return result;
}

command_link_button command_link_button::create(const tuple<ustring, ustring>& texts, const point& location, const drawing::size& size) {
  auto result = command_link_button {};
  result.texts(texts);
  result.location(location);
  result.size(size);
  return result;
}

command_link_button command_link_button::create(const tuple<ustring, ustring>& texts, const point& location, const drawing::size& size, const ustring& name) {
  auto result = command_link_button {};
  result.texts(texts);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

command_link_button command_link_button::create(const control& parent) {
  auto result = command_link_button {};
  result.parent(parent);
  return result;
}

command_link_button command_link_button::create(const control& parent, const ustring& text) {
  auto result = command_link_button {};
  result.parent(parent);
  result.text(text);
  return result;
}

command_link_button command_link_button::create(const control& parent, const ustring& text, const point& location) {
  auto result = command_link_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

command_link_button command_link_button::create(const control& parent, const ustring& text, const point& location, const drawing::size& size) {
  auto result = command_link_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

command_link_button command_link_button::create(const control& parent, const ustring& text, const point& location, const drawing::size& size, const ustring& name) {
  auto result = command_link_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

command_link_button command_link_button::create(const control& parent, const tuple<ustring, ustring>& texts) {
  auto result = command_link_button {};
  result.parent(parent);
  result.texts(texts);
  return result;
}

command_link_button command_link_button::create(const control& parent, const tuple<ustring, ustring>& texts, const point& location) {
  auto result = command_link_button {};
  result.parent(parent);
  result.texts(texts);
  result.location(location);
  return result;
}

command_link_button command_link_button::create(const control& parent, const tuple<ustring, ustring>& texts, const point& location, const drawing::size& size) {
  auto result = command_link_button {};
  result.parent(parent);
  result.texts(texts);
  result.location(location);
  result.size(size);
  return result;
}

command_link_button command_link_button::create(const control& parent, const tuple<ustring, ustring>& texts, const point& location, const drawing::size& size, const ustring& name) {
  auto result = command_link_button {};
  result.parent(parent);
  result.texts(texts);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

control& command_link_button::texts(const ustring& text, const ustring& supplementary_text) {
  return texts({text, supplementary_text});
}

void command_link_button::set_texts(const ustring& text, const ustring& supplementary_text) {
  texts({text, supplementary_text});
}

forms::create_params command_link_button::create_params() const noexcept {
  auto create_params = button_base::create_params();
  create_params.class_name("commandlinkbutton");
  create_params.style(create_params.style() | BS_COMMANDLINK);
  return create_params;
}

void command_link_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  native::command_link_button::texts(handle(), data_->texts);
  if (image() != image::empty || (image_list().images().size() && image_index() > -1)) {
    if (flat_style() == flat_style::system) {
      native::command_link_button::image(handle(), image() != image::empty ? image() : image_list().images()[image_index()]);
      native::command_link_button::image_align(handle(), static_cast<uint32>(image_align()));
    }
    if (image_align() != content_alignment::middle_center) native::control::text(handle(), text());
    native::control::location(handle(), location());
    native::control::size(handle(), size());
  }
}

drawing::size command_link_button::measure_control() const noexcept {
  auto size = drawing::size::ceiling(screen::create_graphics().measure_string(data_->text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces))) + drawing::size(31, 1);
  if (size.height() < default_size().height()) size.height(default_size().height());
  return size;
}
