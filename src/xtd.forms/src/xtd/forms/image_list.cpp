#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/image_list.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/drawing/bitmap.h>
#include "../../../include/xtd/forms/image_list.h"

using namespace xtd;
using namespace xtd::forms;

image_list image_list::empty;

image_list::image_list() {
  data_->handle_ = native::image_list::create(data_->image_size_);
  data_->images_.item_added += [&](size_t pos, drawing::image& item) {
    if (data_->image_size_ != item.size()) item = drawing::bitmap(item, data_->image_size_);
    native::image_list::insert_item(data_->handle_, pos, item);
  };
  
  data_->images_.item_erased += [&](size_t pos, const drawing::image& item) {
    native::image_list::delete_item(data_->handle_, pos);
  };
  
  data_->images_.item_updated += [&](size_t pos, drawing::image& item) {
    if (data_->image_size_ != item.size()) item = drawing::bitmap(item, data_->image_size_);
    native::image_list::update_item(data_->handle_, pos, item);
  };
}

image_list::~image_list() {
  if (data_.use_count() == 1) {
    images().clear();
    native::image_list::destroy(data_->handle_);
  }
}

const image_list& image_list::image_size(const drawing::size& value) {
  if (value.width() < 16 || value.width() > 256 || value.height() < 16 || value.height() > 256) throw argument_out_of_range_exception("The values for width and height must be between 16 and 256."_t, caller_info_);
  if (data_->image_size_ != value) {
    data_->image_size_ = value;
    images().clear();
    native::image_list::destroy(data_->handle_);
    data_->handle_ = native::image_list::create(data_->image_size_);
  }
  return *this;
}
