#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"
#include <xtd/forms/native/button>
#include <xtd/forms/native/content_alignment.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/cdebug>

using namespace xtd;
using namespace xtd::forms::native;

void button::image(intptr control, const drawing::image& image) {
  if (control == 0 || image.handle() == 0 || reinterpret_cast<wx_button*>(control)->owner_draw_) return;
  static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapLabel(wxBitmap(*reinterpret_cast<wxImage*>(image.handle())));
}

void button::image_align(intptr control, uint32 align) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  switch (align) {
    case CA_TOPLEFT: static_cast<wxButton*>(reinterpret_cast<wx_button*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_TOPCENTER: static_cast<wxButton*>(reinterpret_cast<wx_button*>(control)->control())->SetBitmapPosition(wxTOP); break;
    case CA_TOPRIGHT: static_cast<wxButton*>(reinterpret_cast<wx_button*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
    case CA_MIDDLELEFT: static_cast<wxButton*>(reinterpret_cast<wx_button*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_MIDDLECENTER: break;
    case CA_MIDDLERIGHT: static_cast<wxButton*>(reinterpret_cast<wx_button*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
    case CA_BOTTOMLEFT: static_cast<wxButton*>(reinterpret_cast<wx_button*>(control)->control())->SetBitmapPosition(wxDirection::wxLEFT); break;
    case CA_BOTTOMCENTER: static_cast<wxButton*>(reinterpret_cast<wx_button*>(control)->control())->SetBitmapPosition(wxBOTTOM); break;
    case CA_BOTTOMRIGHT: static_cast<wxButton*>(reinterpret_cast<wx_button*>(control)->control())->SetBitmapPosition(wxDirection::wxRIGHT); break;
  }
}

void button::set_default_button(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetDefault();
}
