#include <stdexcept>
#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/picture_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_picture_box.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void picture_box::image(intptr_t control, const drawing::image& image) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  wxSize current_size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  static_cast<wxStaticBitmapBase*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmap(wxBitmap(*reinterpret_cast<wxImage*>(image.handle())));
  if (reinterpret_cast<wx_picture_box*>(control)->auto_size) {
    if (current_size.GetWidth() < reinterpret_cast<control_handler*>(control)->control()->GetSize().GetWidth())
      current_size.SetWidth(reinterpret_cast<control_handler*>(control)->control()->GetSize().GetWidth());
    if (current_size.GetHeight() < reinterpret_cast<control_handler*>(control)->control()->GetSize().GetHeight())
      current_size.SetHeight(reinterpret_cast<control_handler*>(control)->control()->GetSize().GetHeight());
  }
  reinterpret_cast<control_handler*>(control)->control()->SetSize(current_size);
}

void picture_box::reset(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  static_cast<wxStaticBitmapBase*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmap(wxNullBitmap);
}
