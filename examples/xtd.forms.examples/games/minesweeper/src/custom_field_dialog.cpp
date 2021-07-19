#include <string>
#include "custom_field_dialog.h"
#include "../properties/settings.h"

using namespace minesweeper;
using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

custom_field_dialog::custom_field_dialog() {
  accept_button(ok_button_);
  client_size({250, 170});
  close_box(false);
  control_box(false);
  form_border_style(xtd::forms::form_border_style::none);
  maximize_box(false);
  minimize_box(false);
  start_position(form_start_position::center_parent);
  
  if (properties::settings::default_settings().original_color()) {
    back_color(color::silver);
    fore_color(color::black);
    custom_height_text_box_.back_color(color::white);
    custom_height_text_box_.fore_color(color::black);
    custom_width_text_box_.back_color(color::white);
    custom_width_text_box_.fore_color(color::black);
    custom_mines_text_box_.back_color(color::white);
    custom_mines_text_box_.fore_color(color::black);
  }
  
  message_label_.parent(*this);
  message_label_.top(26);
  message_label_.width(client_size().width());
  message_label_.text_align(content_alignment::middle_center);
  message_label_.text("Custom Field"_t);
  
  custom_height_label_.auto_size(true);
  custom_height_label_.location({20, 67});
  custom_height_label_.parent(*this);
  custom_height_label_.text("Height:"_t);

  custom_height_text_box_.key_press += {*this, &custom_field_dialog::on_text_box_key_press};
  custom_height_text_box_.location({85, 65});
  custom_height_text_box_.parent(*this);
  custom_height_text_box_.text(strings::format("{}", custom_height_));
  custom_height_text_box_.width(50);

  custom_width_label_.auto_size(true);
  custom_width_label_.location({20, 97});
  custom_width_label_.parent(*this);
  custom_width_label_.text("Width:"_t);
  
  custom_width_text_box_.key_press += {*this, &custom_field_dialog::on_text_box_key_press};
  custom_width_text_box_.location({85, 95});
  custom_width_text_box_.parent(*this);
  custom_width_text_box_.text(strings::format("{}", custom_width_));
  custom_width_text_box_.width(50);

  custom_mines_label_.auto_size(true);
  custom_mines_label_.location({20, 127});
  custom_mines_label_.parent(*this);
  custom_mines_label_.text("Mines:"_t);
  
  custom_mines_text_box_.key_press += {*this, &custom_field_dialog::on_text_box_key_press};
  custom_mines_text_box_.location({85, 125});
  custom_mines_text_box_.parent(*this);
  custom_mines_text_box_.text(strings::format("{}", custom_mines_));
  custom_mines_text_box_.width(50);

  ok_button_.parent(*this);
  ok_button_.location({165, 65});
  ok_button_.text(xtd::forms::texts::ok());
  ok_button_.dialog_result(dialog_result::ok);
  ok_button_.click += [&] {
    custom_height(parse<int>(custom_height_text_box_.text()));
    custom_width(parse<int>(custom_width_text_box_.text()));
    custom_mines(parse<int>(custom_mines_text_box_.text()));
  };
  ok_button_.size({60, 80});
}

int custom_field_dialog::custom_heght() const noexcept {
  return custom_height_;
}

void custom_field_dialog::custom_height(int value) noexcept {
  custom_height_ = value;
  if (custom_height_ < minimum_height) custom_height_ = minimum_height;
  else if (custom_height_ > maximum_height) custom_height_ = maximum_height;
  custom_height_text_box_.text(strings::format("{}", custom_height_));
}

int custom_field_dialog::custom_width() const noexcept {
  return custom_width_;
}

void custom_field_dialog::custom_width(int value) noexcept {
  custom_width_ = value;
  if (custom_width_ < minimum_width) custom_width_ = minimum_width;
  else if (custom_width_ > maximum_width) custom_width_ = maximum_width;
  custom_width_text_box_.text(strings::format("{}", custom_width_));
}

int custom_field_dialog::custom_mines() const noexcept {
  return custom_mines_;
}

void custom_field_dialog::custom_mines(int value) noexcept {
  custom_mines_ = value;
  if (custom_mines_ < minimum_mines) custom_mines_ = minimum_mines;
  else if (custom_mines_ > maximum_mines) custom_mines_ = maximum_mines;
  custom_mines_text_box_.text(strings::format("{}", custom_mines_));
}

void custom_field_dialog::on_text_box_key_press(object& sender, xtd::forms::key_press_event_args& e) {
  e.handled(!isdigit(e.key_char()));
}
