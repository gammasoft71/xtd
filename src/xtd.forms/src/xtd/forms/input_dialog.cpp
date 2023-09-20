#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/input_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/button.h"
#include "../../../include/xtd/forms/system_texts.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/input_dialog.h"
#include "../../../include/xtd/forms/text_box.h"
#include "xtd_forms_common_dialog_closed_caller.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
  class input_dialog_standard : public form {
  public:
    input_dialog_standard(const xtd::ustring& text, const xtd::ustring& message, const xtd::ustring& value, xtd::forms::character_casing character_casing, bool multiline, bool use_system_password_char, bool word_wrap) {
      auto offset_multiline = multiline ? 100 : 0;
      
      icon(xtd::drawing::icon::empty);
      accept_button(ok_button_);
      cancel_button(cancel_button_);
      client_size({330, 115 + offset_multiline});
      controls().push_back_range({input_panel_, cancel_button_, ok_button_});
      maximize_box(false);
      minimize_box(false);
      show_icon(false);
      this->text(text);
      
      if (xtd::environment::os_version().is_windows_platform()) {
        input_panel_.back_color(application::style_sheet().system_colors().window());
        input_text_box_.back_color(application::style_sheet().system_colors().text_box());
      }
      input_panel_.bounds({0, 0, 330, 115 - 42 + offset_multiline});
      input_panel_.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      input_panel_.controls().push_back_range({message_label_, input_text_box_});
      
      message_label_.bounds({10, 10, 310, 23});
      message_label_.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right);
      message_label_.text(message);
      
      input_text_box_.bounds({10, 35, 310, 23 + offset_multiline});
      input_text_box_.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      input_text_box_.character_casing(character_casing);
      input_text_box_.multiline(multiline);
      input_text_box_.text(value);
      input_text_box_.use_system_password_char(use_system_password_char);
      input_text_box_.word_wrap(word_wrap);
      
      cancel_button_.dialog_result(forms::dialog_result::cancel);
      cancel_button_.text(system_texts::cancel());
      cancel_button_.location({xtd::environment::os_version().is_windows_platform() ? 245 : 160, 81 + offset_multiline});
      cancel_button_.anchor(anchor_styles::right | anchor_styles::bottom);
      
      ok_button_.dialog_result(forms::dialog_result::ok);
      ok_button_.text(system_texts::ok());
      ok_button_.location({xtd::environment::os_version().is_windows_platform() ? 160 : 245, 81 + offset_multiline});
      ok_button_.anchor(anchor_styles::right | anchor_styles::bottom);
      
      //active_control(input_text_box_);
      input_text_box_.focus();
    }
    
    ustring value() const {return input_text_box_.text();}
    
    forms::dialog_result show_dialog() override {
      start_position(form_start_position::center_screen);
      return form::show_dialog();
    }
    
    bool run_dialog(intptr owner) {
      if (!owner)
        start_position(form_start_position::center_screen);
      else {
        this->owner(control::from_handle(owner).value());
        start_position(form_start_position::center_parent);
      }
      if (owner) return form::show_dialog(control::from_handle(owner).value()) == dialog_result::ok;
      return form::show_dialog() == dialog_result::ok;
    }
    
    void run_sheet(intptr owner) {
      if (!owner)
        run_dialog(owner);
      else {
        start_position(form_start_position::center_parent);
        form::show_sheet(control::from_handle(owner).value());
      }
    }
    
  private:
    panel input_panel_;
    panel button_panel_;
    label message_label_;
    text_box input_text_box_;
    button cancel_button_;
    button ok_button_;
  };
}

struct input_dialog::data {
  xtd::forms::character_casing character_casing = xtd::forms::character_casing::normal;
  xtd::forms::dialog_appearance dialog_appearance = xtd::forms::dialog_appearance::standard;
  bool multiline = false;
  xtd::ustring message;
  xtd::ustring text;
  bool use_system_password_char = false;
  xtd::ustring value;
  bool word_wrap = true;
};

input_dialog::input_dialog() : data_(std::make_shared<data>()) {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

xtd::forms::character_casing input_dialog::character_casing() const noexcept {
  return data_->character_casing;
}

input_dialog& input_dialog::character_casing(xtd::forms::character_casing character_casing) {
  if (data_->character_casing != character_casing) {
    data_->character_casing = character_casing;
    switch (data_->character_casing) {
      case xtd::forms::character_casing::upper: data_->value = data_->value.to_upper(); break;
      case xtd::forms::character_casing::lower: data_->value = data_->value.to_lower(); break;
      default: break;
    }
  }
  return *this;
}

xtd::forms::dialog_appearance input_dialog::dialog_appearance() const noexcept {
  return data_->dialog_appearance;
}

input_dialog& input_dialog::dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) {
  data_->dialog_appearance = dialog_appearance;
  return *this;
}

bool input_dialog::multiline() const noexcept {
  return data_->multiline;
}

input_dialog& input_dialog::multiline(bool multiline) {
  data_->multiline = multiline;
  return *this;
}

xtd::ustring input_dialog::message() const noexcept {
  return data_->message;
}

input_dialog& input_dialog::message(const ustring& message) {
  data_->message = message;
  return *this;
}

xtd::ustring input_dialog::text() const noexcept {
  return data_->text;
}

input_dialog& input_dialog::text(const ustring& text) {
  data_->text = text;
  return *this;
}

bool input_dialog::use_system_password_char() const noexcept {
  return data_->use_system_password_char;
}

input_dialog& input_dialog::use_system_password_char(bool use_system_password_char) {
  data_->use_system_password_char = use_system_password_char;
  return *this;
}

xtd::ustring input_dialog::value() const noexcept {
  return data_->value;
}

input_dialog& input_dialog::value(const xtd::ustring& value) {
  if (value == data_->value) return *this;
  switch (data_->character_casing) {
    case xtd::forms::character_casing::normal: data_->value = value; break;
    case xtd::forms::character_casing::upper: data_->value = value.to_upper(); break;
    case xtd::forms::character_casing::lower: data_->value = value.to_lower(); break;
  }
  return *this;
}

bool input_dialog::word_wrap() const noexcept {
  return data_->word_wrap;
}

input_dialog& input_dialog::word_wrap(bool word_wrap) {
  data_->word_wrap = word_wrap;
  return *this;
}

void input_dialog::reset() noexcept {
  data_->character_casing = xtd::forms::character_casing::normal;
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->message = "";
  data_->multiline = false;
  data_->text = "";
  data_->use_system_password_char = false;
  data_->value = "";
  data_->word_wrap = true;
}

bool input_dialog::run_dialog(intptr owner) {
  switch (data_->character_casing) {
    case xtd::forms::character_casing::upper: data_->value = data_->value.to_upper(); break;
    case xtd::forms::character_casing::lower: data_->value = data_->value.to_lower(); break;
    default: break;
  }
  if (data_->dialog_appearance == xtd::forms::dialog_appearance::standard) {
    auto dialog = input_dialog_standard {data_->text, data_->message, data_->value, data_->character_casing, data_->multiline, data_->use_system_password_char, data_->word_wrap};
    auto result = dialog.run_dialog(owner);
    if (result) data_->value = dialog.value();
    return result;
  }
  application::raise_enter_thread_modal(event_args::empty);
  auto result = native::input_dialog::run_dialog(owner, data_->text, data_->message, data_->value, static_cast<int32>(data_->character_casing), data_->multiline, data_->use_system_password_char, data_->word_wrap);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

void input_dialog::run_sheet(intptr owner) {
  switch (data_->character_casing) {
    case forms::character_casing::upper: data_->value = data_->value.to_upper(); break;
    case forms::character_casing::lower: data_->value = data_->value.to_lower(); break;
    default: break;
  }
  if (!owner)
    run_dialog(owner);
  else {
    if (data_->dialog_appearance == xtd::forms::dialog_appearance::standard) {
      auto dialog = make_shared<input_dialog_standard>(data_->text, data_->message, data_->value, data_->character_casing, data_->multiline, data_->use_system_password_char, data_->word_wrap);
      dialog->form_closed += [&, dialog](object & sender, const form_closed_event_args & e) {
        if (dialog->dialog_result() == dialog_result::ok) data_->value = dialog->value();
        on_dialog_closed(dialog_closed_event_args(dialog->dialog_result()));
      };
      dialog->run_sheet(owner);
      return;
    }
    application::raise_enter_thread_modal(event_args::empty);
    native::input_dialog::run_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, data_->text, data_->message, data_->value, static_cast<int32>(data_->character_casing), data_->multiline, data_->use_system_password_char, data_->word_wrap);
    application::raise_leave_thread_modal(event_args::empty);
  }
}
