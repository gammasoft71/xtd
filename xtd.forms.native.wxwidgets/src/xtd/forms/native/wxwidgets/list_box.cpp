#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/list_box.hpp>
#include <xtd/forms/native/window_list_box.hpp>
#include "control_handler.hpp"
#include <wx/listbox.h>

using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  class wx_list_box : public control_handler {
  public:
    wx_list_box(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
      this->control_handler::create<wxListBox>(parent, id, pos, size, 0, nullptr, style);
    }
  };
}

intptr_t list_box::create(intptr_t parent, const size& size, int32_t styles) {
  if (parent == 0) throw std::invalid_argument("parent can't be null");
  long style = wxLB_SINGLE;
  if ((styles & LBS_EXTENDEDSEL) == LBS_EXTENDEDSEL) style |= wxLB_EXTENDED;
  else if ((styles & LBS_MULTIPLESEL) == LBS_MULTIPLESEL) style |= wxLB_MULTIPLE;
  if ((styles & LBS_SORT) == LBS_SORT) style |= wxLB_SORT;
  return (intptr_t) new wx_list_box(reinterpret_cast<control_handler*>(parent)->control(), wxID_ANY, wxDefaultPosition, wxSize(size.width(), size.height()), style);
}

color list_box::default_back_color() {
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
  return system_colors::window;
#else
  static color default_color;
  if (default_color == color::empty) {
    native::application::initialize_application();
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
    wxListBox* list_box = new wxListBox(frame, wxID_ANY, "");
    wxColour colour = list_box->GetBackgroundColour();
#if defined (__APPLE__)
    default_color = color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#else
    default_color = color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
#endif
    delete list_box;
    delete frame;
  }
  return default_color;
#endif
}

color list_box::default_fore_color() {
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
  return system_colors::window_text;
#else
  static color default_color;
  if (default_color == color::empty) {
    native::application::initialize_application();
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
    wxListBox* list_box = new wxListBox(frame, wxID_ANY, "");
    wxColour colour = list_box->GetForegroundColour();
#if defined (__APPLE__)
    default_color = color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#else
    default_color = color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
#endif
    delete list_box;
    delete frame;
  }
  return default_color;
#endif
}

void list_box::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Delete(index);
}

void list_box::insert_item(intptr_t control, size_t index, const std::string& item) {
  if (control == 0) return;
  if (!static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->IsSorted())
    static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert(item, index);
  else
    static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Append(item);
}

size_t list_box::selected_index(intptr_t control) {
  if (control == 0) return -1;
  return static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void list_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(index);
}
