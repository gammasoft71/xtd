#include <map>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/form.hpp>
#include "wx_form.hpp"
#include <wx/apptrait.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void form::activate(intptr_t form) {
  reinterpret_cast<wx_form*>(form)->control()->Raise();
}

void form::close(intptr_t form) {
  reinterpret_cast<wx_form*>(form)->control()->Close();
}

int32_t form::show_dialog(intptr_t form) {
  return static_cast<wxDialog*>(reinterpret_cast<wx_form*>(form)->control())->ShowModal();
}

void form::end_dialog(intptr_t form, int32_t result) {
  static_cast<wxDialog*>(reinterpret_cast<wx_form*>(form)->control())->EndModal(result);
}
