#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/form.hpp>
#include <xtd/forms/native/screen.hpp>
#include "fl_form.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void form::activate(intptr_t form) {
  if (form == 0) return;
  Fl::first_window(static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control()));
}

void form::close(intptr_t form) {
  if (form == 0) return;
  reinterpret_cast<control_handler*>(form)->control()->hide();
}

void form::full_screen(intptr_t form, bool full_screen) {
  if (form == 0) return;
  if (full_screen)
    static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->fullscreen();
  else
    static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->fullscreen_off();
}

bool form::maximize(intptr_t form) {
  if (form == 0) return false;
  xtd::drawing::size form_size = control::size(form);
  xtd::drawing::size screen_size = screen::working_area(screen::from_handle(form)).size();
  return form_size.width() == screen_size.width() && form_size.height() == screen_size.height();
}

void form::maximize(intptr_t form, bool maximize) {
  if (form == 0) return;
  static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->size(screen::working_area(screen::from_handle(form)).size().width(), screen::working_area(screen::from_handle(form)).size().height());
}

bool form::minimize(intptr_t form) {
  if (form == 0) return false;
  
  return !static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->shown();
}

void form::minimize(intptr_t form, bool minimize) {
  if (form == 0) return;
  if (minimize)
    static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->iconize();
  else
    static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->show();
}

void form::default_control(intptr_t form, intptr_t default_control) {
}

void form::restore(intptr_t form) {
  if (form == 0) return;
  static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->fullscreen_off();
  static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->show();
}

int32_t form::show_dialog(intptr_t form) {
  if (form == 0) return 0;
  static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->set_modal();
  static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->show();
  while (static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->visible())
    Fl::wait();
  return reinterpret_cast<Fl_Form*>(form)->dialog_result_;
}

void form::end_dialog(intptr_t form, int32_t result) {
  if (form == 0) return;
  reinterpret_cast<Fl_Form*>(form)->dialog_result_ = result;
  static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->set_non_modal();
  static_cast<Fl_Window*>(reinterpret_cast<control_handler*>(form)->control())->hide();
}
