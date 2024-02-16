#include "../../../include/xtd/forms/command_link_button.h"
#include "../../../include/xtd/forms/form.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/command_link_button>
#include <xtd/forms/native/button_styles>
#include <xtd/forms/native/control>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages>

using namespace std;
using namespace xtd;
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

xtd::ustring& command_link_button::text() const noexcept {
  return data_->text;
}

xtd::forms::control& command_link_button::text(const xtd::ustring& value) {
  data_->text = value;
  auto text1 = value;
  auto text2 = ustring::empty_string;
  auto index = text1.find_first_of("\n");
  if (index != ustring::npos) {
    text2 = text1.substring(index+1);
    text1 = text1.remove(index);
  }
  data_->texts = make_tuple(text1, text2);

  return *this;
}

std::tuple<xtd::ustring, xtd::ustring> command_link_button::texts() const noexcept {
  return data_->texts;
}

control& command_link_button::texts(const tuple<ustring, ustring>& texts) {
  data_->texts = texts;
  data_->text = ustring::format("{}{}{}", get<0>(texts), environment::new_line(), get<1>(texts));
  return *this;
}

command_link_button command_link_button::create() {
  return command_link_button {};
}

command_link_button command_link_button::create(const xtd::ustring& text) {
  auto result = command_link_button {};
  result.text(text);
  return result;
}

command_link_button command_link_button::create(const xtd::ustring& text, const drawing::point& location) {
  auto result = command_link_button {};
  result.text(text);
  result.location(location);
  return result;
}

command_link_button command_link_button::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
  auto result = command_link_button {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

command_link_button command_link_button::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = command_link_button {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

command_link_button command_link_button::create(const std::tuple<xtd::ustring, xtd::ustring>& texts) {
  auto result = command_link_button {};
  result.texts(texts);
  return result;
}

command_link_button command_link_button::create(const std::tuple<xtd::ustring, xtd::ustring>& texts, const drawing::point& location) {
  auto result = command_link_button {};
  result.texts(texts);
  result.location(location);
  return result;
}

command_link_button command_link_button::create(const std::tuple<xtd::ustring, xtd::ustring>& texts, const drawing::point& location, const drawing::size& size) {
  auto result = command_link_button {};
  result.texts(texts);
  result.location(location);
  result.size(size);
  return result;
}

command_link_button command_link_button::create(const std::tuple<xtd::ustring, xtd::ustring>& texts, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
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

command_link_button command_link_button::create(const control& parent, const xtd::ustring& text) {
  auto result = command_link_button {};
  result.parent(parent);
  result.text(text);
  return result;
}

command_link_button command_link_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location) {
  auto result = command_link_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

command_link_button command_link_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
  auto result = command_link_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

command_link_button command_link_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = command_link_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

command_link_button command_link_button::create(const control& parent, const std::tuple<xtd::ustring, xtd::ustring>& texts) {
  auto result = command_link_button {};
  result.parent(parent);
  result.texts(texts);
  return result;
}

command_link_button command_link_button::create(const control& parent, const std::tuple<xtd::ustring, xtd::ustring>& texts, const drawing::point& location) {
  auto result = command_link_button {};
  result.parent(parent);
  result.texts(texts);
  result.location(location);
  return result;
}

command_link_button command_link_button::create(const control& parent, const std::tuple<xtd::ustring, xtd::ustring>& texts, const drawing::point& location, const drawing::size& size) {
  auto result = command_link_button {};
  result.parent(parent);
  result.texts(texts);
  result.location(location);
  result.size(size);
  return result;
}

command_link_button command_link_button::create(const control& parent, const std::tuple<xtd::ustring, xtd::ustring>& texts, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = command_link_button {};
  result.parent(parent);
  result.texts(texts);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
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
  if (image() != drawing::image::empty || (image_list().images().size() && image_index() > -1)) {
    if (flat_style() == flat_style::system) {
      native::command_link_button::image(handle(), image() != drawing::image::empty ? image() : image_list().images()[image_index()]);
      native::command_link_button::image_align(handle(), static_cast<uint32>(image_align()));
    }
    if (image_align() != content_alignment::middle_center) native::control::text(handle(), text());
    native::control::location(handle(), location());
    native::control::size(handle(), size());
  }
}

drawing::size command_link_button::measure_control() const noexcept {
  auto size = button_base::measure_control();
  if (size.height() < default_size().height()) size.height(default_size().height());
  return size;
}
