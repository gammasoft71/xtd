#include "../../../include/xtd/forms/image_list.hpp"
#include <xtd/drawing/bitmap>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/image_list>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_out_of_range_exception>

using namespace xtd;
using namespace xtd::forms;

struct image_list::data {
  intptr handle = 0;
  drawing::size image_size {16, 16};
  image_collection images;
  std::any tag;
};

image_list image_list::empty;

image_list::image_list() : data_(xtd::new_sptr<data>()) {
  data_->handle = native::image_list::create(data_->image_size);
  data_->images.item_added += [&](size_t pos, drawing::image & item) {
    if (data_->image_size != item.size()) item = drawing::bitmap(item, data_->image_size);
    native::image_list::insert_item(data_->handle, pos, item);
  };
  
  data_->images.item_removed += [&](size_t pos, const drawing::image & item) {
    native::image_list::delete_item(data_->handle, pos);
  };
  
  data_->images.item_updated += [&](size_t pos, drawing::image & item) {
    if (data_->image_size != item.size()) item = drawing::bitmap(item, data_->image_size);
    native::image_list::update_item(data_->handle, pos, item);
  };
}

image_list::~image_list() {
  if (data_.use_count() == 1) {
    images().clear();
    native::image_list::destroy(data_->handle);
  }
}

intptr image_list::handle() const noexcept {
  return data_->handle;
}

bool image_list::handle_created() const noexcept {
  return data_->handle != 0;
}

image_list::image_collection& image_list::images() {
  return data_->images;
}

const image_list::image_collection& image_list::images() const noexcept {
  return data_->images;
}

const drawing::size image_list::image_size() const noexcept {
  return data_->image_size;
}

const image_list& image_list::image_size(const drawing::size& value) {
  if (value.width < 16 || value.width > 256 || value.height < 16 || value.height > 256) throw argument_out_of_range_exception("The values for width and height must be between 16 and 256."_t);
  if (data_->image_size == value) return *this;
  data_->image_size = value;
  images().clear();
  native::image_list::destroy(data_->handle);
  data_->handle = native::image_list::create(data_->image_size);
  return *this;
}

std::any image_list::tag() const noexcept {
  return data_->tag;
}

image_list& image_list::tag(const std::any& tag) {
  data_->tag = tag;
  return *this;
}

bool image_list::equals(const object& obj) const noexcept {
  return is<image_list>(obj) && equals(static_cast<const image_list&>(obj));
}

bool image_list::equals(const image_list& other) const noexcept {
  return data_->image_size == other.data_->image_size && data_->images == other.data_->images;
}

xtd::size image_list::get_hash_code() const noexcept {
  auto result = hash_code {};
  result.add(data_->handle);
  result.add(data_->image_size);
  for (const auto& image : data_->images)
    result.add(image);
  return result.to_hash_code();
}
