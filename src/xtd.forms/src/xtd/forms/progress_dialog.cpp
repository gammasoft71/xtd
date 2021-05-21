#include <memory>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/progress_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/progress_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
}

bool progress_dialog::cancelled() const {
  if (!handle_) return true;
  return native::progress_dialog::cancelled(handle_);
}

bool progress_dialog::skipped() const {
  if (!handle_) return false;
  return native::progress_dialog::skipped(handle_);
}

progress_dialog& progress_dialog::informations(const std::vector<std::string>& informations) {
  if (informations_ != informations) {
    informations_ = informations;
    if (handle_) native::progress_dialog::informations(handle_, informations_);
  }
  return *this;
}

progress_dialog& progress_dialog::marquee(bool marquee) {
  if (get_option(PROGDLG_MARQUEEPROGRESS) != marquee) {
    set_option(PROGDLG_MARQUEEPROGRESS, marquee);
    //native::progress_dialog::marquee(handle_, get_option(PROGDLG_MARQUEEPROGRESS), marquee_animation_speed_);
    recreate_dialog();
  }
  return *this;
}

progress_dialog& progress_dialog::marquee_animation_speed(size_t marquee_animation_speed) {
  if (marquee_animation_speed_ != marquee_animation_speed) {
    marquee_animation_speed_ = marquee_animation_speed;
    native::progress_dialog::marquee(handle_, get_option(PROGDLG_MARQUEEPROGRESS), marquee_animation_speed_);
  }
  return *this;
}

progress_dialog& progress_dialog::maximum(int32_t maximum) {
  if (maximum_ != maximum) {
    maximum_ = maximum;
    native::progress_dialog::maximum(handle_, maximum_);
    if (minimum_ > maximum) minimum(maximum);
    if (value_ > maximum) value(maximum);
  }
  return *this;
}

progress_dialog& progress_dialog::minimum(int32_t minimum) {
  if (minimum_ != minimum) {
    minimum_ = minimum;
    native::progress_dialog::minimum(handle_, minimum_);
    if (maximum_ < minimum) maximum(minimum);
    if (value_ < minimum) value(minimum);
  }
  return *this;
}

progress_dialog& progress_dialog::message(const std::string& message) {
  if (message_ != message) {
    message_ = message;
    if (handle_) native::progress_dialog::message(handle_, message_);
  }
  return *this;
}

void progress_dialog::resume() {
  if (!handle_) return;
  native::progress_dialog::resume(handle_);
}

progress_dialog& progress_dialog::show_cancel_button(bool show_cancel_button) {
  if (!get_option(PROGDLG_NOCANCEL) != show_cancel_button) {
    set_option(PROGDLG_NOCANCEL, !show_cancel_button);
    recreate_dialog();
  }
  return *this;
}

progress_dialog& progress_dialog::show_skip_button(bool show_skip_button) {
  if (!get_option(PROGDLG_NOSKIP) != show_skip_button) {
    set_option(PROGDLG_NOSKIP, !show_skip_button);
    recreate_dialog();
  }
  return *this;
}

progress_dialog& progress_dialog::show_elapsed_time(bool show_elapsed_time) {
  if (get_option(PROGDLG_ELAPSEDTIME) != show_elapsed_time) {
    set_option(PROGDLG_ELAPSEDTIME, show_elapsed_time);
    recreate_dialog();
  }
  return *this;
}

progress_dialog& progress_dialog::show_estimated_time(bool show_estimated_time) {
  if (get_option(PROGDLG_ESTIMATEDTIME) != show_estimated_time) {
    set_option(PROGDLG_ESTIMATEDTIME, show_estimated_time);
    recreate_dialog();
  }
  return *this;
}

progress_dialog& progress_dialog::show_remaining_time(bool show_remaining_time) {
  if (get_option(PROGDLG_AUTOTIME) != show_remaining_time) {
    set_option(PROGDLG_AUTOTIME, show_remaining_time);
    recreate_dialog();
  }
  return *this;
}

progress_dialog& progress_dialog::step(int32_t step) {
  if (step_ != step)
    step_ = step;
  return *this;
}

progress_dialog& progress_dialog::value(int32_t value) {
  if (value_ != value) {
    if (value > maximum_) value_ = maximum_;
    if (value < minimum_) value_ = minimum_;
    else value_ = value;
    native::progress_dialog::value(handle_, value_);
  }
  return *this;
}

void progress_dialog::recreate_dialog() {
  if (handle_) {
    hide();
    if (owner_) show(*owner_);
    else show();
  }
}

void progress_dialog::reset() {
  dialog_style_ = xtd::forms::dialog_style::system;
  std::vector<std::string> informations_;
  marquee_animation_speed_ = 100;
  maximum_ = 100;
  message_ = "";
  minimum_ = 0;
  options_ = PROGDLG_NORMAL|PROGDLG_NOCANCEL|PROGDLG_NOSKIP;
  step_ = 10;
  text_ = "";
  value_ = 0;
  recreate_dialog();
}

void progress_dialog::show_dialog() {
  set_option(PROGDLG_MODAL, true);
  show();
}

void progress_dialog::show_dialog(const iwin32_window& owner) {
  set_option(PROGDLG_MODAL, true);
  show(owner);
}

void progress_dialog::show_sheet_dialog(const iwin32_window& owner) {
  set_option(PROGDLG_MODAL, true);
  show_sheet(owner);
}

void progress_dialog::show() {
  native_ = dialog_style_ == xtd::forms::dialog_style::system;
  if (native_) handle_ = native::progress_dialog::create(0, text_, message_, informations_, marquee_animation_speed_, minimum_, maximum_, value_, options_);
  native::progress_dialog::show(handle_);
}

void progress_dialog::show(const iwin32_window& owner) {
  native_ = dialog_style_ == xtd::forms::dialog_style::system;
  if (native_) handle_ = native::progress_dialog::create(owner.handle(), text_, message_, informations_, marquee_animation_speed_, minimum_, maximum_, value_, options_);
  native::progress_dialog::show(handle_);
}

void progress_dialog::show_sheet(const iwin32_window& owner) {
  native_ = dialog_style_ == xtd::forms::dialog_style::system;
  if (native_) handle_ = native::progress_dialog::create(owner.handle(), text_, message_, informations_, marquee_animation_speed_, minimum_, maximum_, value_, options_);
  native::progress_dialog::show_sheet(handle_);
}

void progress_dialog::hide() {
  if (!handle_) return;
  if (native_) native::progress_dialog::destroy(handle_);
  native_ = false;
  handle_ = 0;
}
