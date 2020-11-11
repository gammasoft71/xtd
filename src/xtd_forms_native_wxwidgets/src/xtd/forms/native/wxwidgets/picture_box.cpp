#include <stdexcept>
#include <xtd/forms/native/picture_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_picture_box.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void picture_box::clear(intptr_t control) {
  if (!control) return;
  static_cast<wxStaticBitmapBase*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmap(wxNullBitmap);
}

void picture_box::image(intptr_t control, const drawing::image& image) {
  if (!control) return;
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
