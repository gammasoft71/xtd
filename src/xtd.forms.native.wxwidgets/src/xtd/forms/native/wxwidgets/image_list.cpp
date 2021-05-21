#include <list>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/image_list.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/imaglist.h>

using namespace xtd;
using namespace xtd::forms::native;

intptr_t image_list::create(const drawing::size &image_size) {
  return reinterpret_cast<intptr_t>(new wxImageList(image_size.width(), image_size.height()));
}

void image_list::delete_item(intptr_t image_list, size_t pos) {
  if (image_list == 0) return;
  reinterpret_cast<wxImageList*>(image_list)->Remove(static_cast<int32_t>(pos));
}

void image_list::destroy(intptr_t image_list) {
  if (image_list == 0) return;
  delete reinterpret_cast<wxImageList*>(image_list);
}

void image_list::insert_item(intptr_t image_list, size_t pos, const drawing::image& image) {
  if (image_list == 0) return;
  if (pos == static_cast<size_t>(reinterpret_cast<wxImageList*>(image_list)->GetImageCount()))
    reinterpret_cast<wxImageList*>(image_list)->Add(*reinterpret_cast<wxImage*>(image.handle()));
  else {
    std::list<wxBitmap> bitmaps;
    for (size_t index = static_cast<size_t>(reinterpret_cast<wxImageList*>(image_list)->GetImageCount()) - 1; index > pos; index--) {
      bitmaps.push_front(reinterpret_cast<wxImageList*>(image_list)->GetBitmap(index));
      reinterpret_cast<wxImageList*>(image_list)->Remove(index);
    }

    for (auto& bitmap : bitmaps) {
      reinterpret_cast<wxImageList*>(image_list)->Add(bitmap);
    }
  }
}

void image_list::update_item(intptr_t image_list, size_t pos, const drawing::image& image) {
  if (image_list == 0) return;
  reinterpret_cast<wxImageList*>(image_list)->Replace(static_cast<int32_t>(pos), wxBitmap(*reinterpret_cast<wxImage*>(image.handle())));
}
