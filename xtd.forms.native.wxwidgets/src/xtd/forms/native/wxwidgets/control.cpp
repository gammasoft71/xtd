#include <map>
#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/control.hpp>
#include "wx_button.hpp"
#include "wx_check_box.hpp"
#include "wx_control.hpp"
#include "wx_form.hpp"
#include "wx_group_box.hpp"
#include "wx_label.hpp"
#include "wx_list_box.hpp"
#include "wx_panel.hpp"
#include "wx_radio_button.hpp"
#include "wx_text_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

color control::back_color(intptr_t control) {
  if (control == 0) return color::empty;
  wxColour colour = reinterpret_cast<control_handler*>(control)->control()->GetBackgroundColour();
#if defined (__APPLE__)
  return color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#endif
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void control::back_color(intptr_t control, const color& color) {
  if (control == 0) return;
#if defined (__APPLE__)
  if (color.handle())
    reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(reinterpret_cast<WX_NSColor>(color.handle())));
  else
    reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#else
  reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#endif
}

intptr_t control::create(const forms::create_params& create_params) {
  application::initialize_application(); // Must be first
  if (create_params.class_name() == "BUTTON") return reinterpret_cast<intptr_t>(new wx_button(create_params));
  if (create_params.class_name() == "CHECKBOX") return reinterpret_cast<intptr_t>(new wx_check_box(create_params));
  if (create_params.class_name() == "FORM") return reinterpret_cast<intptr_t>(new wx_form(create_params));
  if (create_params.class_name() == "GROUPBOX") return reinterpret_cast<intptr_t>(new wx_group_box(create_params));
  if (create_params.class_name() == "STATIC") return reinterpret_cast<intptr_t>(new wx_label(create_params));
  if (create_params.class_name() == "LISTBOX") return reinterpret_cast<intptr_t>(new wx_list_box(create_params));
  if (create_params.class_name() == "PANEL") return reinterpret_cast<intptr_t>(new wx_panel(create_params));
  if (create_params.class_name() == "RADIOBUTTON") return reinterpret_cast<intptr_t>(new wx_radio_button(create_params));
  if (create_params.class_name() == "EDIT") return reinterpret_cast<intptr_t>(new wx_text_box(create_params));
  return reinterpret_cast<intptr_t>(new wx_control(create_params));
}

intptr_t control::def_wnd_proc(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle) {
  switch (msg) {
    case WM_GETTEXTLENGTH: return (reinterpret_cast<control_handler*>(hwnd))->control()->GetLabel().ToStdString().size(); break;
    case WM_GETTEXT: return strlen(strncpy(reinterpret_cast<char*>(lparam), reinterpret_cast<control_handler*>(hwnd)->control()->GetLabel().ToStdString().c_str(), wparam)); break;
  }
  if (handle != 0) return reinterpret_cast<control_handler*>(control)->call_def_wnd_proc(hwnd, msg, wparam, lparam, presult, handle);
  return 0;
}

color control::default_back_color() {
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
  return system_colors::control;
#else
  static color default_color;
  if (default_color == color::empty) {
    native::application::initialize_application();
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
    wxButton* button = new wxButton(frame, wxID_ANY, "");
    wxColour colour = button->GetBackgroundColour();
#if defined (__APPLE__)
    default_color = color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#else
    default_color = color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
#endif
    delete button;
    delete frame;
  }
  return default_color;
#endif
}

color control::default_fore_color() {
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
  return system_colors::control_text;
#else
  static color default_color;
  if (default_color == color::empty) {
    native::application::initialize_application();
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
    wxButton* button = new wxButton(frame, wxID_ANY, "");
    wxColour colour = button->GetForegroundColour();
#if defined (__APPLE__)
    default_color = color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#else
    default_color = color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
#endif
    delete button;
    delete frame;
  }
  return default_color;
#endif
}

void control::destroy(intptr_t control) {
  if (control == 0) return;
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Destroy();
  erase(control);
}

void control::erase(intptr_t control) {
  if (control == 0) return;
  delete reinterpret_cast<class control_handler*>(control);
}

drawing::size control::client_size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::client_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetClientSize(size.width(), size.height());
}

bool control::enabled(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsEnabled();
}

void control::enabled(intptr_t control, bool enabled) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Enable(enabled);
}

color control::fore_color(intptr_t control) {
  if (control == 0) return color::empty;
  wxColour colour = reinterpret_cast<control_handler*>(control)->control()->GetForegroundColour();
#if defined (__APPLE__)
  return color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#endif
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void control::fore_color(intptr_t control, const color& color) {
  if (control == 0) return;
#if defined (__APPLE__)
  if (color.handle())
    reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(reinterpret_cast<WX_NSColor>(color.handle())));
  else
    reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#else
  reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#endif
}

intptr_t control::handle(intptr_t control) {
  if (control == 0) return 0;
  return reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetHandle());
}

point control::location(intptr_t control) {
  if (control == 0) return {};
  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  return {location.x, location.y};
}

void control::location(intptr_t control, const point& location) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetPosition({location.x(), location.y()});
}

intptr_t control::parent(intptr_t control) {
  return reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetParent());
}

void control::parent(intptr_t control, intptr_t parent) {
  reinterpret_cast<control_handler*>(control)->control()->Reparent(reinterpret_cast<control_handler*>(parent)->control());
}

drawing::size control::size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetSize(size.width(), size.height());
}

string control::text(intptr_t control) {
  if (control == 0) return {};
  //return reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString();
  intptr_t result = send_message(control, control, WM_GETTEXTLENGTH, 0, 0);
  string text(result, 0);
  result = send_message(control, control, WM_GETTEXT, result + 1, reinterpret_cast<intptr_t>(text.data()));
  return text;
}

void control::text(intptr_t control, const string& text) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetLabel(text);
  send_message(control, control, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString().c_str()));
}

bool control::visible(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsShown();
}

void control::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Show(visible);
}

void control::refresh(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Refresh();
}


void control::register_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->wnd_proc += wnd_proc;
}

void control::unregister_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->wnd_proc -= wnd_proc;
}

intptr_t control::send_message(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
  if (hwnd == 0) return -1;
  return reinterpret_cast<control_handler*>(control)->send_message(hwnd, msg, wparam, lparam, 0);
}
