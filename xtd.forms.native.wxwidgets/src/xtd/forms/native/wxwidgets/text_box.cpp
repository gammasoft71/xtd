#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/text_box.hpp>
#include "control_handler.hpp"
#include <wx/button.h>
#include <wx/textctrl.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_text_box : public control_handler {
  public:
    wx_text_box(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style) {
      this->control_handler::create<wxTextCtrl>(parent, wxID_ANY, title, pos, size, style);
    }
  };
}

intptr_t text_box::create(const forms::create_params& create_params) {
  return (intptr_t) new wx_text_box(reinterpret_cast<control_handler*>(create_params.parent())->control(), create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::to_wx_style(create_params.style(), create_params.ex_style()));
}

color text_box::default_back_color() {
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
  return system_colors::window;
#else
  static color default_color;
  if (default_color == color::empty) {
    native::application::initialize_application();
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
    wxTextCtrl* text_box = new wxTextCtrl(frame, wxID_ANY, "");
    wxColour colour = text_box->GetBackgroundColour();
#if defined (__APPLE__)
    default_color = color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#else
    default_color = color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
#endif
    delete text_box;
    delete frame;
  }
  return default_color;
#endif
}

color text_box::default_fore_color() {
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
  return system_colors::window_text;
#else
  static color default_color;
  if (default_color == color::empty) {
    native::application::initialize_application();
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
    wxButton* text_box = new wxButton(frame, wxID_ANY, "");
    wxColour colour = text_box->GetForegroundColour();
#if defined (__APPLE__)
    default_color = color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#else
    default_color = color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
#endif
    delete text_box;
    delete frame;
  }
  return default_color;
#endif
}

string text_box::text(intptr_t control) {
  if (control == 0) return {};
  return static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue().ToStdString();
}

void text_box::text(intptr_t control, const string& text) {
  if (control == 0) return;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(text);
  //send_message(control, control, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString().c_str()));
}
