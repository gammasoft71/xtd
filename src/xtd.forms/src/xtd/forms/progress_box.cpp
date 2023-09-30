#include "../../../include/xtd/forms/progress_box.h"

using namespace xtd;
using namespace xtd::forms;

std::unique_ptr<progress_dialog> progress_box::dialog_;

bool progress_box::cancelled() {
  return dialog_ && dialog_->cancelled();
}

bool progress_box::skipped() {
  return dialog_ && dialog_->skipped();
}

int32 progress_box::minimum() {
  return dialog_ ? dialog_->minimum() : 0;
}

int32 progress_box::maximum() {
  return dialog_ ? dialog_->maximum() : 100;
}

void progress_box::hide() {
  dialog_.reset();
}

void progress_box::show(const xtd::ustring& title) {
  show_progress_box(nullptr, progress_box_options::none, title);
}

void progress_box::show(const xtd::ustring& title, const progress_box_options options) {
  show_progress_box(nullptr, options, title);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message) {
  show_progress_box(nullptr, progress_box_options::none, title, message);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const progress_box_options options) {
  show_progress_box(nullptr, options, title, message);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value) {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const progress_box_options options) {
  show_progress_box(nullptr, options, title, message, initial_value);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum) {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const progress_box_options options) {
  show_progress_box(nullptr, options, title, message, initial_value, minimum);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum) {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const progress_box_options options) {
  show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed) {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const progress_box_options options) {
  show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations);
}

void progress_box::show(const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations, const progress_box_options options) {
  show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title) {
  show_progress_box(&owner, progress_box_options::none, title);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const progress_box_options options) {
  show_progress_box(&owner, options, title);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message) {
  show_progress_box(&owner, progress_box_options::none, title, message);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const progress_box_options options) {
  show_progress_box(&owner, options, title, message);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value) {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const progress_box_options options) {
  show_progress_box(&owner, options, title, message, initial_value);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum) {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const progress_box_options options) {
  show_progress_box(&owner, options, title, message, initial_value, minimum);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum) {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const progress_box_options options) {
  show_progress_box(&owner, options, title, message, initial_value, minimum, maximum);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed) {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const progress_box_options options) {
  show_progress_box(&owner, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations);
}

void progress_box::show(const iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& message, const int32 initial_value, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations, const progress_box_options options) {
  show_progress_box(&owner, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations);
}

void progress_box::update(const progress_box_options options) {
  if (dialog_) dialog_->show_cancel_button((options & progress_box_options::show_cancel_button) == progress_box_options::show_cancel_button).show_skip_button((options & progress_box_options::show_skip_button) == progress_box_options::show_skip_button).show_elapsed_time((options & progress_box_options::show_elapsed_time) == progress_box_options::show_elapsed_time).show_estimated_time((options & progress_box_options::show_estimated_time) == progress_box_options::show_estimated_time).show_remaining_time((options & progress_box_options::show_remaining_time) == progress_box_options::show_remaining_time);
}

void progress_box::update(const int32 value) {
  if (dialog_) dialog_->value(value);
}

void progress_box::update(const int32 value, const xtd::ustring& title) {
  if (dialog_) dialog_->value(value).text(title);
}

void progress_box::update(const int32 value, const xtd::ustring& title, const xtd::ustring& message) {
  if (dialog_) dialog_->value(value).text(title).message(message);
}

void progress_box::update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum) {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum);
}

void progress_box::update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum, const int32 maximum) {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum);
}

void progress_box::update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum, const int32 maximum, const bool marquee) {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee);
}

void progress_box::update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed) {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee).marquee_animation_speed(marquee_animation_speed);
}

void progress_box::update(const int32 value, const xtd::ustring& title, const xtd::ustring& message, const int32 minimum, const int32 maximum, const bool marquee, const size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee).marquee_animation_speed(marquee_animation_speed).informations(informations);
}

void progress_box::show_progress_box(const iwin32_window* owner, const progress_box_options options, const xtd::ustring& title, const xtd::ustring& message, int32 initial_value, int32 minimum, int32 maximum, const bool marquee, size_t marquee_animation_speed, const std::vector<xtd::ustring>& informations) {
  if (dialog_) return;
  dialog_ = std::make_unique<progress_dialog>();
  dialog_->text(title)
  .value(initial_value)
  .message(message)
  .maximum(maximum)
  .minimum(minimum)
  .marquee(marquee)
  .marquee_animation_speed(marquee_animation_speed)
  .informations(informations)
  .show_cancel_button((options & progress_box_options::show_cancel_button) == progress_box_options::show_cancel_button)
  .show_skip_button((options & progress_box_options::show_skip_button) == progress_box_options::show_skip_button)
  .show_elapsed_time((options & progress_box_options::show_elapsed_time) == progress_box_options::show_elapsed_time)
  .show_estimated_time((options & progress_box_options::show_estimated_time) == progress_box_options::show_estimated_time)
  .show_remaining_time((options & progress_box_options::show_remaining_time) == progress_box_options::show_remaining_time);
  owner ? dialog_->show(*owner) : dialog_->show();
}
