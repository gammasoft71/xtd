#include <xtd/forms/native/input_dialog.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/button.h"
#include "../../../include/xtd/forms/texts.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/input_dialog.h"
#include "../../../include/xtd/forms/text_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct __xtd_forms_input_dialog_closed_caller__ {
  __xtd_forms_input_dialog_closed_caller__(xtd::forms::input_dialog* input_dialog) : input_dialog_(input_dialog) {}
  void on_input_closed(int32_t result, const std::string& value) {
    input_dialog_->input_dialog::on_input_dialog_closed(input_dialog_closed_event_args(static_cast<dialog_result>(result), value));
    delete this;
  }
private:
  xtd::forms::input_dialog* input_dialog_ = nullptr;
};

namespace {
  class input_dialog_standard : public form {
  public:
    input_dialog_standard(const std::string& text, const std::string& message, const std::string& value, xtd::forms::character_casing character_casing, bool multiline, bool use_system_password_char) {
      auto offset_multiline = multiline ? 100 : 0;
      
      accept_button(ok_button_);
      cancel_button(cancel_button_);
      client_size({330, 115 + offset_multiline});
      controls().push_back_range({message_label_, input_text_box_, cancel_button_, ok_button_});
      maximize_box(false);
      minimize_box(false);
      this->text(text);
      
      message_label_.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);
      message_label_.bounds({10, 10, 310, 23});
      message_label_.text(message);

      input_text_box_.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right|anchor_styles::bottom);
      input_text_box_.bounds({10, 35, 310, 23 + offset_multiline});
      input_text_box_.character_casing(character_casing);
      input_text_box_.multiline(multiline);
      input_text_box_.text(value);
      input_text_box_.use_system_password_char(use_system_password_char);

      cancel_button_.anchor(anchor_styles::right|anchor_styles::bottom);
      cancel_button_.dialog_result(forms::dialog_result::cancel);
      cancel_button_.text(texts::cancel);
      cancel_button_.location({160, 75 + offset_multiline});

      ok_button_.anchor(anchor_styles::right|anchor_styles::bottom);
      ok_button_.dialog_result(forms::dialog_result::ok);
      ok_button_.text(texts::ok);
      ok_button_.location({245, 75 + offset_multiline});
    
      //active_control(input_text_box_);
      input_text_box_.focus();
    }
    
    std::string value() const {return input_text_box_.text();}

    forms::dialog_result show_dialog() override {
      start_position(form_start_position::center_screen);
      return form::show_dialog();
    }
    
    forms::dialog_result show_dialog(const iwin32_window& owner) override {
      this->owner(dynamic_cast<const control&>(owner));
      start_position(form_start_position::center_parent);
      return form::show_dialog(owner);
    }
    
    void show_sheet(const iwin32_window& owner) override {
      start_position(form_start_position::center_parent);
      form::show_sheet(owner);
    }

  private:
    label message_label_;
    text_box input_text_box_;
    button cancel_button_;
    button ok_button_;
  };
}

void input_dialog::reset() {
  character_casing_ = xtd::forms::character_casing::normal;
  dialog_style_ = xtd::forms::dialog_style::standard;
  message_ = "";
  multiline_ = false;
  text_ = "";
  use_system_password_char_ = false;
  value_ = "";
}

dialog_result input_dialog::show_dialog() {
  switch (character_casing_) {
    case xtd::forms::character_casing::upper: value_ = xtd::strings::to_upper(value_); break;
    case xtd::forms::character_casing::lower: value_ = xtd::strings::to_lower(value_); break;
    default: break;
  }
  if (dialog_style_ == xtd::forms::dialog_style::standard) {
    input_dialog_standard dialog(text_, message_, value_, character_casing_, multiline_, use_system_password_char_);
    auto result = dialog.show_dialog();
    if (result == dialog_result::ok) value_ = dialog.value();
    on_input_dialog_closed(input_dialog_closed_event_args(result, value_));
    return result;
  }
  application::raise_enter_thread_modal(event_args::empty);
  auto result = static_cast<dialog_result>(native::input_dialog::show_dialog(0, text_, message_, value_, static_cast<int32_t>(character_casing_), multiline_, use_system_password_char_));
  on_input_dialog_closed(input_dialog_closed_event_args(result, value_));
  return result;
}

dialog_result input_dialog::show_dialog(const iwin32_window& owner) {
  if (dialog_style_ == xtd::forms::dialog_style::standard) {
    input_dialog_standard dialog(text_, message_, value_, character_casing_, multiline_, use_system_password_char_);
    auto result = dialog.show_dialog(owner);
    if (result == dialog_result::ok) value_ = dialog.value();
    on_input_dialog_closed(input_dialog_closed_event_args(result, value_));
    return result;
  }
  application::raise_enter_thread_modal(event_args::empty);
  auto result = static_cast<dialog_result>(native::input_dialog::show_dialog(owner.handle(), text_, message_, value_, static_cast<int32_t>(character_casing_), multiline_, use_system_password_char_));
  on_input_dialog_closed(input_dialog_closed_event_args(result, value_));
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

void input_dialog::show_sheet(const iwin32_window& owner) {
  if (dialog_style_ == xtd::forms::dialog_style::standard) {
    input_dialog_standard* dialog = new input_dialog_standard(text_, message_, value_, character_casing_, multiline_, use_system_password_char_);
    dialog->show_sheet(owner);
    dialog->form_closed += [&](control& sender, const form_closed_event_args& e) {
      if (static_cast<input_dialog_standard*>(&sender)->dialog_result() == dialog_result::ok) value_ = static_cast<input_dialog_standard*>(&sender)->value();
      on_input_dialog_closed(input_dialog_closed_event_args(static_cast<input_dialog_standard*>(&sender)->dialog_result(), value_));
      delete static_cast<input_dialog_standard*>(&sender);
    };
    return ;
  }
  application::raise_enter_thread_modal(event_args::empty);
  native::input_dialog::show_sheet({*new __xtd_forms_input_dialog_closed_caller__(this), &__xtd_forms_input_dialog_closed_caller__::on_input_closed}, owner.handle(), text_, message_, value_, static_cast<int32_t>(character_casing_), multiline_, use_system_password_char_);
  application::raise_leave_thread_modal(event_args::empty);
}

dialog_result input_dialog::show_sheet_dialog(const iwin32_window& owner) {
  if (dialog_style_ == xtd::forms::dialog_style::standard) {
    input_dialog_standard dialog(text_, message_, value_, character_casing_, multiline_, use_system_password_char_);
    auto result = dialog.show_sheet_dialog(owner);
    if (result == dialog_result::ok) value_ = dialog.value();
    on_input_dialog_closed(input_dialog_closed_event_args(result, value_));
    return result;
  }
  application::raise_enter_thread_modal(event_args::empty);
  auto result = static_cast<dialog_result>(native::input_dialog::show_sheet_dialog(owner.handle(), text_, message_, value_, static_cast<int32_t>(character_casing_), multiline_, use_system_password_char_));
  on_input_dialog_closed(input_dialog_closed_event_args(result, value_));
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}
