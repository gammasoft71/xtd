#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/text_box.h"
#include <xtd/drawing/pens>
#include <xtd/drawing/system_colors>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/edit_styles>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/text_box>
#include <xtd/forms/native/toolkit>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/convert_string>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

struct text_box::data {
  xtd::ustring placeholder_text = xtd::ustring::empty_string;
  bool accepts_return = false;
  xtd::forms::character_casing character_casing = xtd::forms::character_casing::normal;
  char32 password_char = 0;
  bool use_system_password_char = false;
};

text_box::text_box() : data_(std::make_shared<data>()) {
  control_appearance(forms::control_appearance::system);
}

bool text_box::accepts_return() const noexcept {
  return data_->accepts_return;
}

text_box& text_box::accepts_return(bool value) {
  if (data_->accepts_return == value) return *this;
  data_->accepts_return = value;
  post_recreate_handle();
  on_accepts_return_changed(event_args::empty);
  return *this;
}

xtd::forms::character_casing text_box::character_casing() const noexcept {
  return data_->character_casing;
}

text_box& text_box::character_casing(xtd::forms::character_casing value) {
  if (data_->character_casing == value) return *this;
  data_->character_casing = value;
  post_recreate_handle();
  return *this;
}

char32 text_box::password_char() const noexcept {
  return data_->password_char;
}

text_box& text_box::password_char(char32 value) {
  if (data_->password_char == value) return *this;
  data_->password_char = value;
  post_recreate_handle();
  return *this;
}

const xtd::ustring& text_box::placeholder_text() const noexcept {
  return data_->placeholder_text;
}

text_box& text_box::placeholder_text(const xtd::ustring& value) {
  if (data_->placeholder_text == value) return *this;
  data_->placeholder_text = value;
  if (is_handle_created())
    native::text_box::placeholder_text(handle(), data_->placeholder_text);
  return *this;
}

size_t text_box::selection_length() const noexcept {
  if (is_handle_created()) const_cast<text_box*>(this)->text_box_base::selection_length(native::text_box::selection_length(handle()));
  return text_box_base::selection_length();
}

size_t text_box::selection_start() const noexcept {
  if (is_handle_created()) const_cast<text_box*>(this)->text_box_base::selection_start(native::text_box::selection_start(handle()));
  return text_box_base::selection_start();
}

const ustring& text_box::text() const noexcept {
  if (!data_->use_system_password_char && data_->password_char) return control::text();
  return text_box_base::text();
}

control& text_box::text(const ustring& text) {
  if (control::text() == text) return *this;
  set_text(text);
  if (!data_->use_system_password_char && data_->password_char) {
    if (is_handle_created()) native::text_box::text(handle(), "");
    for (size_t count = 0; count < text.size(); count++)
      if (is_handle_created()) native::text_box::append(handle(), xtd::ustring::format("{}", data_->password_char));
  } else {
    switch (data_->character_casing) {
      case xtd::forms::character_casing::normal: set_text(text); break;
      case xtd::forms::character_casing::upper: set_text(text.to_upper()); break;
      case xtd::forms::character_casing::lower: set_text(text.to_lower()); break;
      default: break;
    }
    if (is_handle_created()) native::text_box::text(handle(), control::text());
  }
  on_text_changed(event_args::empty);
  return *this;
}

bool text_box::use_system_password_char() const noexcept {
  return data_->use_system_password_char;
}

text_box& text_box::use_system_password_char(bool value) {
  if (data_->use_system_password_char == value) return *this;
  data_->use_system_password_char = value;
  post_recreate_handle();
  return *this;
}

drawing::color text_box::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().text_box();
}

drawing::color text_box::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().text_box_text();
}

forms::create_params text_box::create_params() const noexcept {
  auto create_params = text_box_base::create_params();
  
  create_params.class_name("textbox");
  
  if (border_style() == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (border_style() != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  if (accepts_return()) create_params.style(create_params.style() | ES_WANTRETURN);
  if (accepts_tab()) create_params.style(create_params.style() | ES_WANTTAB);
  if (multiline()) create_params.style(create_params.style() | ES_MULTILINE);
  if (use_system_password_char()) create_params.style(create_params.style() | ES_PASSWORD);
  if (read_only()) create_params.style(create_params.style() | ES_READONLY);
  if (!word_wrap()) create_params.style(create_params.style() | ES_AUTOHSCROLL);
  if (character_casing() == xtd::forms::character_casing::upper) create_params.style(create_params.style() | ES_UPPERCASE);
  if (character_casing() == xtd::forms::character_casing::lower) create_params.style(create_params.style() | ES_LOWERCASE);
  
  return create_params;
}

drawing::size text_box::measure_control() const noexcept {
  return drawing::size(client_size().width(), static_cast<int32>(font().get_height()) + 2 + (border_style() == border_style::none ? 0 : 4));
}

void text_box::append_text(const xtd::ustring& value) {
  if (is_handle_created()) native::text_box::append(handle(), value);
}

void text_box::select(size_t start, size_t length) {
  text_box_base::select(start, length);
  if (is_handle_created()) native::text_box::select(handle(), selection_start(), selection_length());
}

void text_box::on_accepts_return_changed(const event_args& e) {
  if (can_raise_events()) accepts_return_changed(*this, e);
}

void text_box::on_handle_created(const event_args& e) {
  text_box_base::on_handle_created(e);
  native::text_box::placeholder_text(handle(), data_->placeholder_text);
  /*
  switch (data_->character_casing) {
    case xtd::forms::character_casing::upper: set_text(text().to_upper()); break;
    case xtd::forms::character_casing::lower: set_text(text().to_lower()); break;
    default: break;
  }*/
  
  if (!data_->use_system_password_char && data_->password_char) {
    auto txt = text();
    native::text_box::text(handle(), "");
    for (auto count = 0_sz; count < txt.size(); ++count)
      native::text_box::append(handle(), xtd::ustring::format("{}", data_->password_char));
  } else {
    switch (data_->character_casing) {
      case xtd::forms::character_casing::upper: set_text(text().to_upper()); break;
      case xtd::forms::character_casing::lower: set_text(text().to_lower()); break;
      default: break;
    }
    native::text_box::text(handle(), text());
  }
}

void text_box::on_text_changed(const event_args& e) {
  if (!data_->use_system_password_char && data_->password_char)
    control::on_text_changed(e);
  else {
  }
  text_box_base::on_text_changed(e);
}

void text_box::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_KEYDOWN: wm_key_char(message); break;
    case WM_CHAR: wm_key_char(message); break;
    case WM_KEYUP: wm_key_char(message); break;
    case WM_SETTEXT: wm_set_text(message); break;
    default: control::wnd_proc(message);
  }
}

void text_box::wm_key_char(message& message) {
  if (data_->use_system_password_char || data_->password_char == 0)
    control::wnd_proc(message);
  else {
    if (message.msg() == WM_KEYDOWN) {
      auto key_event_args = forms::key_event_args {static_cast<keys>(message.wparam())};
      on_key_down(key_event_args);
      message.result(key_event_args.suppress_key_press());
    } else if (message.msg() == WM_CHAR && std::iscntrl(static_cast<int32>(message.wparam())) == 0) {
      auto key_event_args = key_press_event_args {static_cast<char32>(message.wparam())};
      set_text(control::text() + xtd::ustring::format("{}", key_event_args.key_char()));
      native::text_box::append(handle(), xtd::ustring::format("{}", data_->password_char));
      message.result(true);
    } else if (message.msg() == WM_KEYUP) {
      auto key_event_args = forms::key_event_args {static_cast<keys>(message.wparam())};
      on_key_up(key_event_args);
      message.result(key_event_args.suppress_key_press());
    }
  }
}

void text_box::wm_set_text(message& message) {
  if (!data_->use_system_password_char && data_->password_char)
    on_text_changed(event_args::empty);
  else {
    def_wnd_proc(message);
    if (control::text() != convert_string::to_string(reinterpret_cast<const wchar*>(message.lparam()))) {
      set_text(convert_string::to_string(reinterpret_cast<const wchar*>(message.lparam())));
      on_text_changed(event_args::empty);
    }
  }
}
