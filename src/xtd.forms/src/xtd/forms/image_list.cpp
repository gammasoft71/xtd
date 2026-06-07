#include "../../../include/xtd/forms/image_list.hpp"
#include <xtd/drawing/bitmap>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/image_list>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_out_of_range_exception>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::helpers;

struct image_list::data {
  intptr handle = 0;
  size image_size {16, 16};
  image_collection images;
  any_object tag;
};

image_list image_list::empty;

image_list::image_list() : data_(xtd::new_sptr<data>()) {
  data_->handle = native::image_list::create(data_->image_size);
  data_->images.item_added += [&](xtd::usize pos, image & item) {
    if (data_->image_size != item.size()) item = bitmap(item, data_->image_size);
    native::image_list::insert_item(data_->handle, pos, item);
  };
  
  data_->images.item_removed += [&](xtd::usize pos, const image & item) {
    native::image_list::delete_item(data_->handle, pos);
  };
  
  data_->images.item_updated += [&](xtd::usize pos, image & item) {
    if (data_->image_size != item.size()) item = bitmap(item, data_->image_size);
    native::image_list::update_item(data_->handle, pos, item);
  };
}

image_list::~image_list() {
  if (data_.use_count() == 1) {
    images().clear();
    native::image_list::destroy(data_->handle);
  }
}

auto image_list::handle() const noexcept -> intptr {
  return data_->handle;
}

auto image_list::handle_created() const noexcept -> bool {
  return data_->handle != 0;
}

auto image_list::images() -> image_collection& {
  return data_->images;
}

auto image_list::images() const noexcept -> const image_collection& {
  return data_->images;
}

auto image_list::image_size() const noexcept -> size {
  return data_->image_size;
}

auto image_list::image_size(const size& value) -> image_list& {
  if (value.width < 16 || value.width > 256 || value.height < 16 || value.height > 256) throw_helper::throws(exception_case::argument_out_of_range, "The values for width and height must be between 16 and 256.");
  if (data_->image_size == value) return *this;
  data_->image_size = value;
  images().clear();
  native::image_list::destroy(data_->handle);
  data_->handle = native::image_list::create(data_->image_size);
  return *this;
}

auto image_list::tag() const noexcept -> const any_object& {
  return data_->tag;
}

auto image_list::tag(const any_object& tag) -> image_list& {
  data_->tag = tag;
  return *this;
}

auto image_list::equals(const object& obj) const noexcept -> bool {
  return is<image_list>(obj) && equals(static_cast<const image_list&>(obj));
}

auto image_list::equals(const image_list& other) const noexcept -> bool {
  return data_->image_size == other.data_->image_size && data_->images == other.data_->images;
}

auto image_list::get_hash_code() const noexcept -> usize {
  auto result = hash_code {};
  result.add(data_->handle);
  result.add(data_->image_size);
  for (const auto& image : data_->images)
    result.add(image);
  return result.to_hash_code();
}
