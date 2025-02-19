#include "../../../../include/xtd/drawing/imaging/frame_dimension.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;

frame_dimension::frame_dimension(const xtd::guid& guid) noexcept : guid_(guid) {
}

const class guid& frame_dimension::guid() const noexcept {
  return guid_;
}

frame_dimension frame_dimension::page() noexcept {
  return frame_dimension(xtd::guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483"));
}

frame_dimension frame_dimension::resolution() noexcept {
  return frame_dimension(xtd::guid("84236f7b-3bd3-428f-8dab-4ea1439ca315"));
}

frame_dimension frame_dimension::time() noexcept {
  return frame_dimension(xtd::guid("6aedbd6d-3fb5-418a-83a6-7f45229dc872"));
}

bool frame_dimension::equals(const object& obj) const noexcept {
  return is<frame_dimension>(obj) && equals(static_cast<const frame_dimension&>(obj));
}

bool frame_dimension::equals(const frame_dimension& other) const noexcept {
  return guid_ == other.guid_;
}

size frame_dimension::get_hash_code() const noexcept {
  return hash_code::combine(guid_);
}
