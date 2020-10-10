#include <xtd/forms/native/application.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/form.h>
#include <xtd/forms/native/screen.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_form.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_menu.h"
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

void form::icon(intptr_t form, intptr_t icon) {
  if (form == 0) return;
  if (!icon) static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->SetIcon(wxIcon());
  else static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->SetIcon(reinterpret_cast<wxIconBundle*>(icon)->GetIcon());
}

bool form::maximize(intptr_t form) {
  if (form == 0) return false;
#if defined(__WXGTK__)
    xtd::drawing::size form_size = control::size(form);
    xtd::drawing::size screen_size = screen::working_area(screen::from_handle(form)).size();
    return form_size.width() == screen_size.width() && form_size.height() == screen_size.height();
#else
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->IsMaximized();
#endif
}

void form::maximize(intptr_t form, bool maximize) {
  if (form == 0) return;
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->Maximize(maximize);
}

void form::menu(intptr_t form, intptr_t menu) {
  if (form == 0) return;

#if defined(__APPLE__)
  if (menu != 0) {
    if (reinterpret_cast<wxMenuBar*>(menu)->FindMenu("Window") == wxNOT_FOUND) reinterpret_cast<wxMenuBar*>(menu)->Append(new wxMenu(), "&Window");
    if (reinterpret_cast<wxMenuBar*>(menu)->FindMenu("Help") == wxNOT_FOUND) reinterpret_cast<wxMenuBar*>(menu)->Append(new wxMenu(), "&Help");
  }
#endif

  //if (menu != 0 && !dynamic_cast<wxFrame*>(reinterpret_cast<control_handler*>(form)->control())) throw std::invalid_argument("dialog can't have menu");
  if (!dynamic_cast<wxFrame*>(reinterpret_cast<control_handler*>(form)->control())) {
    if (menu != 0) throw std::invalid_argument("dialog can't have menu");
    return;
  }
  static_cast<wxFrame*>(reinterpret_cast<control_handler*>(form)->control())->SetMenuBar(menu != 0 ? reinterpret_cast<wx_menu_bar*>(menu) : wx_menu_bar::create_default_menu_bar());
}

bool form::minimize(intptr_t form) {
  if (form == 0) return false;
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->IsIconized();
}

void form::minimize(intptr_t form, bool minimize) {
  if (form == 0) return;
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->Iconize(minimize);
}

void form::restore(intptr_t form) {
  if (form == 0) return;
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->ShowFullScreen(false);
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->Restore();
#if defined(__WXGTK__)
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->Maximize(false);
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(form)->control())->Iconize(false);
#endif
}

int32_t form::show_dialog(intptr_t form) {
  if (form == 0) return 0;
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(form)->control())) throw std::invalid_argument("show_dialog work only dialog");
  auto dialog = static_cast<wxDialog*>(reinterpret_cast<control_handler*>(form)->control());

  if (!dialog->GetParent()) return dialog->ShowModal();
  int32_t result = wxID_ANY;
  dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [&, dialog](wxWindowModalDialogEvent& event) {
    result = event.GetReturnCode();
  });
  dialog->ShowWindowModal();
  while (result == wxID_ANY)
    wxYield();
  return result;
}

void form::show_dialog_sheet(intptr_t form) {
  if (form == 0) return;
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(form)->control())) throw std::invalid_argument("show_dialog work only dialog");
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(form)->control())->ShowWindowModal();
}

void form::end_dialog(intptr_t form, int32_t result) {
  if (form == 0) return;
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(form)->control())) throw std::invalid_argument("end_dialog work only dialog");
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(form)->control())->EndModal(result);
}

void form::virtual_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  
  reinterpret_cast<control_handler*>(control)->main_control()->SetVirtualSize(wxSize(size.width(), size.height()));
  if (dynamic_cast<wxMainPanel*>(reinterpret_cast<control_handler*>(control)->main_control())) static_cast<wxMainPanel*>(reinterpret_cast<control_handler*>(control)->main_control())->SetScrollRate(10, 10);
}
