#include <xtd/drawing/native/system_fonts.hpp>
#include "../../../../../include/xtd/drawing/native/fl_font.hpp"

using namespace xtd::drawing::native;

intptr_t system_fonts::caption_font() {
  return reinterpret_cast<intptr_t>(new class fl_font(FL_HELVETICA, FL_NORMAL_SIZE));
}

intptr_t system_fonts::default_font() {
  return reinterpret_cast<intptr_t>(new class fl_font(FL_HELVETICA, FL_NORMAL_SIZE));
}

intptr_t system_fonts::dialog_font() {
  return reinterpret_cast<intptr_t>(new class fl_font(FL_HELVETICA, FL_NORMAL_SIZE));
}

intptr_t system_fonts::icon_title_font() {
  return reinterpret_cast<intptr_t>(new class fl_font(FL_HELVETICA, FL_NORMAL_SIZE));
}

intptr_t system_fonts::menu_font() {
  return reinterpret_cast<intptr_t>(new class fl_font(FL_HELVETICA, FL_NORMAL_SIZE));
}

intptr_t system_fonts::message_box_font() {
  return reinterpret_cast<intptr_t>(new class fl_font(FL_HELVETICA, FL_NORMAL_SIZE));
}

intptr_t system_fonts::small_caption_font() {
  return reinterpret_cast<intptr_t>(new class fl_font(FL_HELVETICA, FL_NORMAL_SIZE));
}

intptr_t system_fonts::status_font() {
  return reinterpret_cast<intptr_t>(new class fl_font(FL_HELVETICA, FL_NORMAL_SIZE));
}
