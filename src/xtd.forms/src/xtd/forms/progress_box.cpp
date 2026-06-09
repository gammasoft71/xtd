#include "../../../include/xtd/forms/progress_box.hpp"

using namespace xtd;
using namespace xtd::forms;

xtd::uptr<progress_dialog> progress_box::dialog_;

auto progress_box::cancelled() -> bool {
  return dialog_ && dialog_->cancelled();
}

auto progress_box::skipped() -> bool {
  return dialog_ && dialog_->skipped();
}

auto progress_box::minimum() -> int32 {
  return dialog_ ? dialog_->minimum() : 0;
}

auto progress_box::maximum() -> int32 {
  return dialog_ ? dialog_->maximum() : 100;
}

auto progress_box::hide() -> void {
  dialog_.reset();
}

auto progress_box::show(const xtd::string& title) -> void {
  show_progress_box(nullptr, progress_box_options::none, title);
}

auto progress_box::show(const xtd::string& title, progress_box_options options) -> void {
  show_progress_box(nullptr, options, title);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message) -> void {
  show_progress_box(nullptr, progress_box_options::none, title, message);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, progress_box_options options) -> void {
  show_progress_box(nullptr, options, title, message);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value) -> void {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, progress_box_options options) -> void {
  show_progress_box(nullptr, options, title, message, initial_value);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum) -> void {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, progress_box_options options) -> void {
  show_progress_box(nullptr, options, title, message, initial_value, minimum);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum) -> void {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, progress_box_options options) -> void {
  show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed) -> void {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed, progress_box_options options) -> void {
  show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed, const array<xtd::string>& informations) -> void {
  show_progress_box(nullptr, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations);
}

auto progress_box::show(const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed, const array<xtd::string>& informations, progress_box_options options) -> void {
  show_progress_box(nullptr, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title) -> void {
  show_progress_box(&owner, progress_box_options::none, title);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, progress_box_options options) -> void {
  show_progress_box(&owner, options, title);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message) -> void {
  show_progress_box(&owner, progress_box_options::none, title, message);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, progress_box_options options) -> void {
  show_progress_box(&owner, options, title, message);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value) -> void {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, progress_box_options options) -> void {
  show_progress_box(&owner, options, title, message, initial_value);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum) -> void {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, progress_box_options options) -> void {
  show_progress_box(&owner, options, title, message, initial_value, minimum);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum) -> void {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, progress_box_options options) -> void {
  show_progress_box(&owner, options, title, message, initial_value, minimum, maximum);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed) -> void {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed, progress_box_options options) -> void {
  show_progress_box(&owner, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed, const array<xtd::string>& informations) -> void {
  show_progress_box(&owner, progress_box_options::none, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations);
}

auto progress_box::show(const iwin32_window& owner, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed, const array<xtd::string>& informations, progress_box_options options) -> void {
  show_progress_box(&owner, options, title, message, initial_value, minimum, maximum, marquee, marquee_animation_speed, informations);
}

auto progress_box::update(progress_box_options options) -> void {
  if (dialog_) dialog_->show_cancel_button((options & progress_box_options::show_cancel_button) == progress_box_options::show_cancel_button).show_skip_button((options & progress_box_options::show_skip_button) == progress_box_options::show_skip_button).show_elapsed_time((options & progress_box_options::show_elapsed_time) == progress_box_options::show_elapsed_time).show_estimated_time((options & progress_box_options::show_estimated_time) == progress_box_options::show_estimated_time).show_remaining_time((options & progress_box_options::show_remaining_time) == progress_box_options::show_remaining_time);
}

auto progress_box::update(int32 value) -> void {
  if (dialog_) dialog_->value(value);
}

auto progress_box::update(int32 value, const xtd::string& title) -> void {
  if (dialog_) dialog_->value(value).text(title);
}

auto progress_box::update(int32 value, const xtd::string& title, const xtd::string& message) -> void {
  if (dialog_) dialog_->value(value).text(title).message(message);
}

auto progress_box::update(int32 value, const xtd::string& title, const xtd::string& message, int32 minimum) -> void {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum);
}

auto progress_box::update(int32 value, const xtd::string& title, const xtd::string& message, int32 minimum, int32 maximum) -> void {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum);
}

auto progress_box::update(int32 value, const xtd::string& title, const xtd::string& message, int32 minimum, int32 maximum, bool marquee) -> void {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee);
}

auto progress_box::update(int32 value, const xtd::string& title, const xtd::string& message, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed) -> void {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee).marquee_animation_speed(marquee_animation_speed);
}

auto progress_box::update(int32 value, const xtd::string& title, const xtd::string& message, int32 minimum, int32 maximum, bool marquee, usize marquee_animation_speed, const array<xtd::string>& informations) -> void {
  if (dialog_) dialog_->value(value).text(title).message(message).minimum(minimum).maximum(maximum).marquee(marquee).marquee_animation_speed(marquee_animation_speed).informations(informations);
}

auto progress_box::show_progress_box(const iwin32_window* owner, progress_box_options options, const xtd::string& title, const xtd::string& message, int32 initial_value, int32 minimum, int32 maximum, bool marquee, xtd::usize marquee_animation_speed, const array<xtd::string>& informations) -> void {
  if (dialog_) return;
  dialog_ = xtd::new_uptr<progress_dialog>();
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
