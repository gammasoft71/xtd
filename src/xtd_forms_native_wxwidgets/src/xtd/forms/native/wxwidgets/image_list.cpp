#include <xtd/forms/native/image_list.hpp>
#include <wx/imaglist.h>

using namespace xtd;
using namespace xtd::forms::native;

intptr_t image_list::create(const drawing::size &image_size) {
  return reinterpret_cast<intptr_t>(new wxImageList(image_size.width(), image_size.height()));
}

void image_list::delete_item(intptr_t image_list, size_t pos) {
  if (image_list == 0) return;

}

void image_list::destroy(intptr_t image_list) {
  if (image_list == 0) return;
  delete reinterpret_cast<wxImageList*>(image_list);
}

void image_list::insert_item(intptr_t image_list, size_t pos, const drawing::image& image) {
  if (image_list == 0) return;

}
