#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/progress_dialog.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/progress_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/progress_dialog_flags>
#include <memory>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct progress_dialog::data {
  xtd::forms::dialog_appearance dialog_appearance = xtd::forms::dialog_appearance::system;
  intptr handle = 0;
  std::vector<xtd::ustring> informations;
  size_t marquee_animation_speed = 100;
  int32 maximum = 100;
  xtd::ustring message;
  int32 minimum = 0;
  bool native = false;
  size_t options = PROGDLG_NORMAL | PROGDLG_NOCANCEL | PROGDLG_NOSKIP;
  const iwin32_window* owner = nullptr;
  int32 step = 10;
  xtd::ustring text;
  int32 value = 0;
};

progress_dialog::progress_dialog() : data_(std::make_shared<data>()) {
  data_->dialog_appearance = application::system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

progress_dialog::~progress_dialog() {
  hide();
}

bool progress_dialog::cancelled() const {
  if (!data_->handle) return true;
  return native::progress_dialog::cancelled(data_->handle);
}

xtd::forms::dialog_appearance progress_dialog::dialog_appearance() const noexcept {
  return data_->dialog_appearance;
}

progress_dialog& progress_dialog::dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) {
  if (data_->dialog_appearance == dialog_appearance) return *this;
  data_->dialog_appearance = dialog_appearance;
  recreate_dialog();
  return *this;
}

const std::vector<xtd::ustring>& progress_dialog::informations() const noexcept {
  return data_->informations;
}

progress_dialog& progress_dialog::informations(const std::vector<xtd::ustring>& informations) {
  if (data_->informations == informations) return *this;
  data_->informations = informations;
  if (data_->handle) native::progress_dialog::informations(data_->handle, data_->informations);
  return *this;
}

bool progress_dialog::marquee() const noexcept {
  return get_option(PROGDLG_MARQUEEPROGRESS);
}

progress_dialog& progress_dialog::marquee(bool marquee) {
  if (get_option(PROGDLG_MARQUEEPROGRESS) == marquee) return *this;
  set_option(PROGDLG_MARQUEEPROGRESS, marquee);
  recreate_dialog();
  return *this;
}

size_t progress_dialog::marquee_animation_speed() const noexcept {
  return data_->marquee_animation_speed;
}

progress_dialog& progress_dialog::marquee_animation_speed(size_t marquee_animation_speed) {
  if (data_->marquee_animation_speed == marquee_animation_speed) return *this;
  data_->marquee_animation_speed = marquee_animation_speed;
  native::progress_dialog::marquee(data_->handle, get_option(PROGDLG_MARQUEEPROGRESS), data_->marquee_animation_speed);
  return *this;
}

int32 progress_dialog::maximum() const noexcept {
  return data_->maximum;
}

progress_dialog& progress_dialog::maximum(int32 maximum) {
  if (data_->maximum == maximum) return *this;
  data_->maximum = maximum;
  native::progress_dialog::maximum(data_->handle, data_->maximum);
  if (data_->minimum > maximum) minimum(maximum);
  if (data_->value > maximum) value(maximum);
  return *this;
}

const xtd::ustring& progress_dialog::message() const noexcept {
  return data_->message;
}

progress_dialog& progress_dialog::message(const xtd::ustring& message) {
  if (data_->message == message) return *this;
  data_->message = message;
  if (data_->handle) native::progress_dialog::message(data_->handle, data_->message);
  return *this;
}

int32 progress_dialog::minimum() const noexcept {
  return data_->minimum;
}

progress_dialog& progress_dialog::minimum(int32 minimum) {
  if (data_->minimum == minimum) return *this;
  data_->minimum = minimum;
  native::progress_dialog::minimum(data_->handle, data_->minimum);
  if (data_->maximum < minimum) maximum(minimum);
  if (data_->value < minimum) value(minimum);
  return *this;
}

void progress_dialog::resume() {
  if (!data_->handle) return;
  native::progress_dialog::resume(data_->handle);
}

bool progress_dialog::show_cancel_button() const noexcept {
  return !get_option(PROGDLG_NOCANCEL);
}

progress_dialog& progress_dialog::show_cancel_button(bool show_cancel_button) {
  if (!get_option(PROGDLG_NOCANCEL) == show_cancel_button) return *this;
  set_option(PROGDLG_NOCANCEL, !show_cancel_button);
  recreate_dialog();
  return *this;
}

bool progress_dialog::show_elapsed_time() const noexcept {
  return !get_option(PROGDLG_ELAPSEDTIME);
}

progress_dialog& progress_dialog::show_elapsed_time(bool show_elapsed_time) {
  if (get_option(PROGDLG_ELAPSEDTIME) == show_elapsed_time) return *this;
  set_option(PROGDLG_ELAPSEDTIME, show_elapsed_time);
  recreate_dialog();
  return *this;
}

bool progress_dialog::show_estimated_time() const noexcept {
  return !get_option(PROGDLG_ESTIMATEDTIME);
}

progress_dialog& progress_dialog::show_estimated_time(bool show_estimated_time) {
  if (get_option(PROGDLG_ESTIMATEDTIME) == show_estimated_time) return *this;
  set_option(PROGDLG_ESTIMATEDTIME, show_estimated_time);
  recreate_dialog();
  return *this;
}

bool progress_dialog::show_remaining_time() const noexcept {
  return !get_option(PROGDLG_AUTOTIME);
}

progress_dialog& progress_dialog::show_remaining_time(bool show_remaining_time) {
  if (get_option(PROGDLG_AUTOTIME) == show_remaining_time) return *this;
  set_option(PROGDLG_AUTOTIME, show_remaining_time);
  recreate_dialog();
  return *this;
}

bool progress_dialog::show_skip_button() const noexcept {
  return !get_option(PROGDLG_NOSKIP);
}

progress_dialog& progress_dialog::show_skip_button(bool show_skip_button) {
  if (!get_option(PROGDLG_NOSKIP) == show_skip_button) return *this;
  set_option(PROGDLG_NOSKIP, !show_skip_button);
  recreate_dialog();
  return *this;
}

bool progress_dialog::skipped() const {
  if (!data_->handle) return false;
  return native::progress_dialog::skipped(data_->handle);
}

int32 progress_dialog::step() const noexcept {
  return data_->step;
}

progress_dialog& progress_dialog::step(int32 step) {
  data_->step = step;
  return *this;
}

const xtd::ustring& progress_dialog::text() const noexcept {
  return data_->text;
}

progress_dialog& progress_dialog::text(const xtd::ustring& text) {
  if (data_->text == text) return *this;
  data_->text = text;
  recreate_dialog();
  return *this;
}

int32 progress_dialog::value() const noexcept {
  return data_->value;
}

progress_dialog& progress_dialog::value(int32 value) {
  if (data_->value == value) return *this;
  if (value > data_->maximum) data_->value = data_->maximum;
  else if (value < data_->minimum) data_->value = data_->minimum;
  else data_->value = value;
  native::progress_dialog::value(data_->handle, data_->value);
  return *this;
}

void progress_dialog::hide() {
  if (!data_->handle) return;
  if (data_->native) native::progress_dialog::destroy(data_->handle);
  data_->native = false;
  data_->handle = 0;
}

void progress_dialog::increment(int32 increment) {
  value(data_->value + increment);
}

void progress_dialog::perform_step() {
  increment(step());
}

void progress_dialog::reset() noexcept {
  data_->dialog_appearance = application::system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->informations.clear();
  data_->marquee_animation_speed = 100;
  data_->maximum = 100;
  data_->message = "";
  data_->minimum = 0;
  data_->options = PROGDLG_NORMAL | PROGDLG_NOCANCEL | PROGDLG_NOSKIP;
  data_->step = 10;
  data_->text = "";
  data_->value = 0;
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
  /// @todo Delete the following comment when the standard dialog is ready.
  data_->native = true; //data_->dialog_appearance == xtd::forms::dialog_appearance::system;
  if (data_->native) data_->handle = native::progress_dialog::create(0, data_->text, data_->message, data_->informations, data_->marquee_animation_speed, data_->minimum, data_->maximum, data_->value, data_->options);
  native::progress_dialog::show(data_->handle);
}

void progress_dialog::show(const iwin32_window& owner) {
  /// @todo Delete the following comment when the standard dialog is ready.
  data_->native = true; //data_->dialog_appearance == xtd::forms::dialog_appearance::system;
  if (data_->native) data_->handle = native::progress_dialog::create(owner.handle(), data_->text, data_->message, data_->informations, data_->marquee_animation_speed, data_->minimum, data_->maximum, data_->value, data_->options);
  native::progress_dialog::show(data_->handle);
}

void progress_dialog::show_sheet(const iwin32_window& owner) {
  /// @todo Delete the following comment when the standard dialog is ready.
  data_->native = true; //data_->dialog_appearance == xtd::forms::dialog_appearance::system;
  if (data_->native) data_->handle = native::progress_dialog::create(owner.handle(), data_->text, data_->message, data_->informations, data_->marquee_animation_speed, data_->minimum, data_->maximum, data_->value, data_->options);
  native::progress_dialog::show_sheet(data_->handle);
}

bool progress_dialog::get_option(size_t flag) const noexcept {
  return (data_->options & flag) == flag;
}

void progress_dialog::set_option(size_t flag, bool value) {
  data_->options = value ? data_->options | flag : data_->options & ~flag;
}

void progress_dialog::recreate_dialog() {
  if (!data_->handle) return;
  hide();
  if (data_->owner) show(*data_->owner);
  else show();
}
