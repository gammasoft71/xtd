#include "../../../include/xtd/forms/image_list"
#include <xtd/drawing/bitmap>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/image_list>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_out_of_range_exception>

using namespace xtd;
using namespace xtd::forms;

struct image_list::data {
  intptr handle_ = 0;
  drawing::size image_size_ {16, 16};
  image_collection images_;
  std::any tag_;
};

image_list image_list::empty;

image_list::image_list() : data_(std::make_shared<data>()) {
  data_->handle_ = native::image_list::create(data_->image_size_);
  data_->images_.item_added += [&](size_t pos, drawing::image & item) {
    if (data_->image_size_ != item.size()) item = drawing::bitmap(item, data_->image_size_);
    native::image_list::insert_item(data_->handle_, pos, item);
  };
  
  data_->images_.item_removed += [&](size_t pos, const drawing::image & item) {
    native::image_list::delete_item(data_->handle_, pos);
  };
  
  data_->images_.item_updated += [&](size_t pos, drawing::image & item) {
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

intptr image_list::handle() const noexcept {
  return data_->handle_;
}

bool image_list::handle_created() const noexcept {
  return data_->handle_ != 0;
}

image_list::image_collection& image_list::images() {
  return data_->images_;
}

const image_list::image_collection& image_list::images() const noexcept {
  return data_->images_;
}

const drawing::size image_list::image_size() const noexcept {
  return data_->image_size_;
}

const image_list& image_list::image_size(const drawing::size& value) {
  if (value.width() < 16 || value.width() > 256 || value.height() < 16 || value.height() > 256) throw argument_out_of_range_exception("The values for width and height must be between 16 and 256."_t, csf_);
  if (data_->image_size_ == value) return *this;
  data_->image_size_ = value;
  images().clear();
  native::image_list::destroy(data_->handle_);
  data_->handle_ = native::image_list::create(data_->image_size_);
  return *this;
}

std::any image_list::tag() const noexcept {
  return data_->tag_;
}

image_list& image_list::tag(const std::any& tag) {
  data_->tag_ = tag;
  return *this;
}

bool image_list::equals(const image_list& value) const noexcept {
  return data_->images_ == value.data_->images_;
}
