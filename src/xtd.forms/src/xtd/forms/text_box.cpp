#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/text_box.h>
#include <xtd/forms/native/text_box_styles.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/text_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

text_box::text_box() {
  //this->back_color_ = this->default_back_color();
  //this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();
}

text_box& text_box::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

text_box& text_box::character_casing(xtd::forms::character_casing value) {
  if (this->character_casing_ != value) {
    this->character_casing_ = value;
    recreate_handle();
  }
  return *this;
}

text_box& text_box::multiline(bool value) {
  if (this->multiline_ != value) {
    this->multiline_ = value;
    recreate_handle();
  }
  return *this;
}

text_box& text_box::password_char(char32_t value) {
  if (this->password_char_ != value) {
    this->password_char_ = value;
    recreate_handle();
  }
  return *this;
}

size_t text_box::selection_length() const {
  selection_length_ = native::text_box::selection_length(handle());
  return text_box_base::selection_length();
}

size_t text_box::selection_start() const {
  selection_start_ = native::text_box::selection_start(handle());
  return text_box_base::selection_start();
}

const std::string& text_box::text() const {
  if (!use_system_password_char_ && password_char_) return text_;
  return text_box_base::text();
}

control& text_box::text(const std::string& text) {
  if (this->text_ != text) {
    text_ = text;
    if (!use_system_password_char_ && password_char_) {
      native::text_box::text(handle(), "");
      for (size_t count = 0; count < text.size(); count++)
        native::text_box::append(handle(), xtd::strings::format("{}", password_char_));
    } else {
      switch (character_casing_) {
        case xtd::forms::character_casing::normal: text_ = text; break;
        case xtd::forms::character_casing::upper: text_ = xtd::strings::to_upper(text); break;
        case xtd::forms::character_casing::lower: text_ = xtd::strings::to_lower(text); break;
        default: break;
      }
      native::text_box::text(handle(), text_.c_str());
    }
    on_text_changed(event_args::empty);
  }
  return *this;
}

text_box& text_box::use_system_password_char(bool value) {
  if (use_system_password_char_ != value) {
    use_system_password_char_ = value;
    recreate_handle();
  }
  return *this;
}

forms::create_params text_box::create_params() const {
  forms::create_params create_params = this->text_box_base::create_params();
  
  create_params.class_name("textbox");
  
  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);

  if (accepts_return_) create_params.style(create_params.style() | ES_WANTRETURN);
  if (accepts_tab_) create_params.style(create_params.style() | ES_WANTTAB);
  if (multiline_) create_params.style(create_params.style() | ES_MULTILINE);
  if (use_system_password_char_) create_params.style(create_params.style() | ES_PASSWORD);
  if (read_only_) create_params.style(create_params.style() | ES_READONLY);
  if (!word_wrap_) create_params.style(create_params.style() | ES_AUTOHSCROLL);
  if (character_casing_ == xtd::forms::character_casing::upper) create_params.style(create_params.style() | ES_UPPERCASE);
  if (character_casing_ == xtd::forms::character_casing::lower) create_params.style(create_params.style() | ES_LOWERCASE);

  return create_params;
}

drawing::size text_box::measure_control() const {
  return drawing::size(this->client_size_.width(), static_cast<int32_t>(this->font().get_height()) + 2 + (this->border_style_ == border_style::none ? 0 : 4));
}

void text_box::append_text(const std::string& value) {
  native::text_box::append(handle_, value);
}

void text_box::select(size_t start, size_t length) {
  text_box_base::select(start, length);  
  native::text_box::select(handle_, selection_start_, selection_length_);
}

void text_box::on_handle_created(const event_args& e) {
  text_box_base::on_handle_created(e);
  /*
  switch (character_casing_) {
    case xtd::forms::character_casing::upper: text_ = xtd::strings::to_upper(this->text_); break;
    case xtd::forms::character_casing::lower: text_ = xtd::strings::to_lower(this->text_); break;
    default: break;
  }*/

  if (!use_system_password_char_ && password_char_) {
    auto text = text_;
    native::text_box::text(handle(), "");
    for (size_t count = 0; count < text.size(); count++)
      native::text_box::append(handle(), xtd::strings::format("{}", password_char_));
  } else {
    switch (character_casing_) {
      case xtd::forms::character_casing::upper: text_ = xtd::strings::to_upper(text_); break;
      case xtd::forms::character_casing::lower: text_ = xtd::strings::to_lower(text_); break;
      default: break;
    }
    native::text_box::text(handle(), text_.c_str());
  }
}

void text_box::on_text_changed(const event_args& e) {
  if (!use_system_password_char_ && password_char_) {
    control::on_text_changed(e);
  } else {
  }
  text_box_base::on_text_changed(e);
}

void text_box::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_KEYDOWN: wm_key_char(message); break;
    case WM_CHAR: wm_key_char(message); break;
    case WM_KEYUP: wm_key_char(message); break;
    case WM_SETTEXT: wm_set_text(message); break;
    default: control::wnd_proc(message);
  }
}

void text_box::wm_key_char(message &message) {
  if (use_system_password_char_ || password_char_ == 0)
    control::wnd_proc(message);
  else {
    if (message.msg() == WM_KEYDOWN) {
      key_event_args key_event_args(static_cast<keys>(message.wparam()));
      on_key_down(key_event_args);
      message.result(key_event_args.suppress_key_press());
    } else if (message.msg() == WM_CHAR) {
      key_press_event_args key_event_args(static_cast<int32_t>(message.wparam()));
      text_ += xtd::strings::format("{}",key_event_args.key_char());
      native::text_box::append(handle(), xtd::strings::format("{}", password_char_));
      message.result(true);
    } else if (message.msg() == WM_KEYUP) {
      key_event_args key_event_args(static_cast<keys>(message.wparam()));
      on_key_up(key_event_args);
      message.result(key_event_args.suppress_key_press());
    }
  }
}

void text_box::wm_set_text(message &message) {
  if (!use_system_password_char_ && password_char_) {
    on_text_changed(event_args::empty);
  } else {
    def_wnd_proc(message);
    if (text_ != reinterpret_cast<const char*>(message.lparam())) {
      text_ = reinterpret_cast<const char*>(message.lparam());
      on_text_changed(event_args::empty);
    }
  }
}
