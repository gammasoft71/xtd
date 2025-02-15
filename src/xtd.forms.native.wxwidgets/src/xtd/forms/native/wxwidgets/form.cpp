#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_form.hpp"
#include <xtd/forms/native/application>
#include <xtd/forms/native/control>
#include <xtd/forms/native/form>
#include <xtd/forms/native/screen>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/diagnostics/debug>
#include <xtd/not_implemented_exception>
#include <xtd/threading/thread>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;
using namespace xtd::helpers;
using namespace xtd::threading;

void __toggle_full_screen_frame__(wxTopLevelWindow* control, bool full_screen);

static void __on_command_menu__(wxCommandEvent& event) {
  if (event.GetId() == wxID_EXIT) {
    for (auto window : wxTopLevelWindows)
      if (!window->Close())
        return;
    wxTheApp->ExitMainLoop();
  } else event.Skip();
}

wxMenuBar* __create_default_menu_bar__() {
  wxMenuBar* default_menu_bar = new wxMenuBar;
  default_menu_bar->Bind(wxEVT_MENU, &__on_command_menu__);
  return default_menu_bar;
}

void form::activate(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Raise();
}

void form::close(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Close();
}

bool form::full_screen(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return false;
  }
  #if defined(__WXOSX__)
  return __toggle_full_screen_frame__(static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()));
  #else
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->IsFullScreen();
  #endif
}

void form::full_screen(intptr control, bool full_screen) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  #if defined(__WXOSX__)
  __toggle_full_screen_frame__(static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()), full_screen);
  #else
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->ShowFullScreen(full_screen, wxFULLSCREEN_NOMENUBAR | wxFULLSCREEN_NOBORDER | wxFULLSCREEN_NOCAPTION);
  #endif
}

void form::icon(intptr control, const xtd::drawing::icon& icon) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  if (icon == drawing::icon::empty) static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetIcon(wxIcon());
  else static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetIcon(reinterpret_cast<wxIconBundle*>(icon.handle())->GetIcon());
}

bool form::maximize(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return false;
  }
  #if defined(__WXGTK__)
  xtd::drawing::size form_size = control::size(control);
  xtd::drawing::size screen_size = screen::working_area(screen::from_handle(control)).size();
  return form_size.width == screen_size.width && form_size.height == screen_size.height;
  #else
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->IsMaximized();
  #endif
}

void form::maximize(intptr control, bool maximize) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->Maximize(maximize);
}

void form::menu(intptr control, intptr menu) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (menu != 0 && !dynamic_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())) throw_helper::throws(exception_case::argument, "dialog can't have menu"_t);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  
  static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetMenuBar(menu != 0 ? reinterpret_cast<wxMenuBar*>(menu) : __create_default_menu_bar__());
}

bool form::minimize(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return false;
  }
  return static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->IsIconized();
}

void form::minimize(intptr control, bool minimize) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->Iconize(minimize);
}

void form::restore(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  full_screen(control, false);
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->Restore();
  #if defined(__WXGTK__)
  maximize(control, false);
  minimize(control, false);
  #endif
}

void form::set_region(intptr control, intptr region) {
  if (!control || !region || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxNonOwnedWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetShape(*reinterpret_cast<wxRegion*>(region));
}

int32 form::show_dialog(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return 0;
  }
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())) throw_helper::throws(exception_case::argument, "show_dialog work only with dialog"_t);
  auto dialog = static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control());
  return dialog->ShowModal();
}

void form::show_sheet(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())) throw_helper::throws(exception_case::argument, "show_sheet work only with dialog"_t);
  #if defined(__WXOSX__)
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())->ShowWindowModal();
  #else
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())->ShowModal();
  #endif
}

int32 form::show_sheet_dialog(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return 0;
  }
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())) throw_helper::throws(exception_case::argument, "show_sheet_dialog work only with dialog"_t);
  auto dialog = static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control());
  #if defined(__WXOSX__)
  if (!dialog->GetParent()) return dialog->ShowModal();
  int32 result = wxID_ANY;
  dialog->ShowWindowModal();
  dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [&](wxWindowModalDialogEvent & event) {
    dialog->Unlink();
    dialog->DeletePendingEvents();
    result = event.GetReturnCode();
    event.Skip(true);
  });
  while (result == wxID_ANY) {
    application::do_events();
    thread::sleep(10_ms);
  }
  return result;
  #else
  return dialog->ShowModal();
  #endif
}

void form::end_dialog(intptr control, int32 result) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  if (!dynamic_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())) throw_helper::throws(exception_case::argument, "end_dialog work only with dialog"_t);
  static_cast<wxDialog*>(reinterpret_cast<control_handler*>(control)->control())->EndModal(result);
}

void form::opacity(intptr control, double opacity) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())->SetTransparent(static_cast<xtd::byte>(255 * opacity));
}

void form::virtual_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  reinterpret_cast<control_handler*>(control)->main_control()->SetVirtualSize(wxSize(size.width, size.height));
  if (dynamic_cast<wxMainPanel*>(reinterpret_cast<control_handler*>(control)->main_control())) static_cast<wxMainPanel*>(reinterpret_cast<control_handler*>(control)->main_control())->SetScrollRate(10, 10);
}
