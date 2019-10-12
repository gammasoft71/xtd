#include <map>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/form.hpp>
#include "wx_form.hpp"
#include <wx/apptrait.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void form::activate(intptr_t form) {
  if (form == 0) return;
  reinterpret_cast<control_handler*>(form)->control()->Raise();
}

void form::close(intptr_t form) {
  if (form == 0) return;
  reinterpret_cast<control_handler*>(form)->control()->Close();
}

void form::full_screen(intptr_t form, bool full_screen) {
  if (form == 0) return;
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->ShowFullScreen(full_screen);
}

bool form::maximize(intptr_t form) {
  if (form == 0) return false;
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->IsMaximized();
}

void form::maximize(intptr_t form, bool maximize) {
  if (form == 0) return;
    static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->Maximize(maximize);
}

bool form::minimize(intptr_t form) {
  if (form == 0) return false;
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->IsIconized();
}

void form::minimize(intptr_t form, bool minimize) {
  if (form == 0) return;
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->Iconize(minimize);
}

void form::default_control(intptr_t form, intptr_t default_control) {
  if (form == 0 || default_control == 0) return;
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->SetDefaultItem(reinterpret_cast<control_handler*>(default_control)->control());
}

int32_t form::show_dialog(intptr_t form) {
  if (form == 0) return 0;
  return static_cast<wxDialog*>(reinterpret_cast<control_handler*>(form)->control())->ShowModal();
}

void form::end_dialog(intptr_t form, int32_t result) {
  if (form == 0) return;
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(form)->control())->EndModal(result);
}
