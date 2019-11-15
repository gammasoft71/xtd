#include <xtd/forms/native/image_list.hpp>
#include <xtd/drawing/bitmap.hpp>
#include "../../../include/xtd/forms/image_list.hpp"

using namespace xtd;
using namespace xtd::forms;

image_list::image_list() {
  images_.item_added += [&](size_t pos, drawing::image& item) {
    if (handle_ == 0) native::image_list::create(image_size_);
    if (image_size_ != item.size()) item = drawing::bitmap(item, image_size_);
    native::image_list::insert_item(handle_, pos, item);
  };
  
  images_.item_erased += [&](size_t pos, const drawing::image& item) {
    native::image_list::delete_item(handle_, pos);
  };
  
  images_.item_updated += [&](size_t pos, drawing::image& item) {
    native::image_list::delete_item(handle_, pos);
    if (image_size_ != item.size()) item = drawing::bitmap(item, image_size_);
    native::image_list::insert_item(handle_, pos, item);
  };
}

image_list::~image_list() {
  if (handle_) native::image_list::destroy(handle_);
}

void image_list::image_size(const drawing::size& value) {
  if (image_size_ != value) {
    if (handle_) native::image_list::destroy(handle_);
    handle_ = 0;
    image_size_ = value;
  }
}
