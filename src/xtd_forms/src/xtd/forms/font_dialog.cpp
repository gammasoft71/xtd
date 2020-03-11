#include <xtd/forms/native/font_dialog.h>
#include "../../../include/xtd/forms/font_dialog.h"

using namespace xtd;
using namespace xtd::forms;

void font_dialog::reset() {
  this->color_ = drawing::system_colors::control_text();
  this->font_ = drawing::system_fonts::default_font();
  this->max_size_ = 0;
  this->min_size_ = 0;
  this->options_ = CF_TTONLY;
  this->show_color_ = false;
}

void font_dialog::on_apply(const event_args &e) {
  this->apply(*this, e);
}

bool font_dialog::run_dialog(intptr_t owner) {
  return native::font_dialog::run_dialog(owner, this->font_, this->color_, this->options_, this->min_size_, this->max_size_, this->show_color_);
}
