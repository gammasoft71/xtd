#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/edit_styles.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/text_box.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/pens.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/text_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

text_box::text_box() {
  control_appearance(forms::control_appearance::system);
}

text_box& text_box::character_casing(xtd::forms::character_casing value) {
  if (character_casing_ != value) {
    character_casing_ = value;
    post_recreate_handle();
  }
  return *this;
}

text_box& text_box::password_char(char32_t value) {
  if (password_char_ != value) {
    password_char_ = value;
    post_recreate_handle();
  }
  return *this;
}

size_t text_box::selection_length() const {
  if (is_handle_created()) const_cast<text_box*>(this)->text_box_base::selection_length(native::text_box::selection_length(handle()));
  return text_box_base::selection_length();
}

size_t text_box::selection_start() const {
  if (is_handle_created()) const_cast<text_box*>(this)->text_box_base::selection_start(native::text_box::selection_start(handle()));
  return text_box_base::selection_start();
}

const ustring& text_box::text() const {
  if (!use_system_password_char_ && password_char_) return control::text();
  return text_box_base::text();
}

control& text_box::text(const ustring& text) {
  if (control::text() != text) {
    set_text(text);
    if (!use_system_password_char_ && password_char_) {
      if (is_handle_created()) native::text_box::text(handle(), "");
      for (size_t count = 0; count < text.size(); count++)
        if (is_handle_created()) native::text_box::append(handle(), xtd::ustring::format("{}", password_char_));
    } else {
      switch (character_casing_) {
        case xtd::forms::character_casing::normal: set_text(text); break;
        case xtd::forms::character_casing::upper: set_text(text.to_upper()); break;
        case xtd::forms::character_casing::lower: set_text(text.to_lower()); break;
        default: break;
      }
      if (is_handle_created()) native::text_box::text(handle(), control::text());
    }
    on_text_changed(event_args::empty);
  }
  return *this;
}

text_box& text_box::use_system_password_char(bool value) {
  if (use_system_password_char_ != value) {
    use_system_password_char_ = value;
    post_recreate_handle();
  }
  return *this;
}

drawing::color text_box::default_back_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().text_box();
}

drawing::color text_box::default_fore_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().text_box_text();
}

forms::create_params text_box::create_params() const {
  forms::create_params create_params = text_box_base::create_params();
  
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

drawing::size text_box::measure_control() const {
  return drawing::size(client_size().width(), static_cast<int32_t>(font().get_height()) + 2 + (border_style() == border_style::none ? 0 : 4));
}

void text_box::append_text(const xtd::ustring& value) {
  if (is_handle_created()) native::text_box::append(handle(), value);
}

void text_box::select(size_t start, size_t length) {
  text_box_base::select(start, length);
  if (is_handle_created()) native::text_box::select(handle(), selection_start(), selection_length());
}

void text_box::on_handle_created(const event_args& e) {
  text_box_base::on_handle_created(e);
  /*
  switch (character_casing_) {
    case xtd::forms::character_casing::upper: set_text(text().to_upper()); break;
    case xtd::forms::character_casing::lower: set_text(text().to_lower()); break;
    default: break;
  }*/
  
  if (!use_system_password_char_ && password_char_) {
    auto text = this->text();
    native::text_box::text(handle(), "");
    for (size_t count = 0; count < text.size(); count++)
      native::text_box::append(handle(), xtd::ustring::format("{}", password_char_));
  } else {
    switch (character_casing_) {
      case xtd::forms::character_casing::upper: set_text(text().to_upper()); break;
      case xtd::forms::character_casing::lower: set_text(text().to_lower()); break;
      default: break;
    }
    native::text_box::text(handle(), text());
  }
}

void text_box::on_text_changed(const event_args& e) {
  if (!use_system_password_char_ && password_char_)
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
  if (use_system_password_char_ || password_char_ == 0)
    control::wnd_proc(message);
  else {
    if (message.msg() == WM_KEYDOWN) {
      key_event_args key_event_args(static_cast<keys>(message.wparam()));
      on_key_down(key_event_args);
      message.result(key_event_args.suppress_key_press());
    } else if (message.msg() == WM_CHAR && std::iscntrl(static_cast<int32_t>(message.wparam())) == 0) {
      key_press_event_args key_event_args(static_cast<int32_t>(message.wparam()));
      set_text(control::text() + xtd::ustring::format("{}", key_event_args.key_char()));
      native::text_box::append(handle(), xtd::ustring::format("{}", password_char_));
      message.result(true);
    } else if (message.msg() == WM_KEYUP) {
      key_event_args key_event_args(static_cast<keys>(message.wparam()));
      on_key_up(key_event_args);
      message.result(key_event_args.suppress_key_press());
    }
  }
}

void text_box::wm_set_text(message& message) {
  if (!use_system_password_char_ && password_char_)
    on_text_changed(event_args::empty);
  else {
    def_wnd_proc(message);
    if (control::text() != convert_string::to_string(reinterpret_cast<const wchar_t*>(message.lparam()))) {
      set_text(convert_string::to_string(reinterpret_cast<const wchar_t*>(message.lparam())));
      on_text_changed(event_args::empty);
    }
  }
}
