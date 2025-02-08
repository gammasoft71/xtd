#include "../../../../include/xtd/drawing/imaging/property_item.hpp"

using namespace xtd;
using namespace xtd::drawing::imaging;

int32 property_item::id() const noexcept {
  return id_;
}

void property_item::id(int32 value) noexcept {
  id_ = value;
}

size property_item::len() const noexcept {
  return value_.length();
}

int16 property_item::type() const noexcept {
  return type_;
}

void property_item::type(int16 value) noexcept {
  type_ = value;
}

const array<byte>& property_item::value() const noexcept {
  return value_;
}

array<byte>& property_item::value() noexcept {
  return value_;
}

void property_item::value(const array<byte>& value) noexcept {
  value_ = value;
}

bool property_item::equals(const object& obj) const noexcept {
  return is<property_item>(obj) && equals(static_cast<const property_item&>(obj));
}

bool property_item::equals(const property_item& other) const noexcept {
  return id_ == other.id_ && type_ == other.type_ && value_ != other.value_;
}

size property_item::get_hash_code() const noexcept {
  auto result = hash_code {};
  result.add(id_);
  result.add(type_);
  for (auto b : value_)
    result.add(b);
  return result.to_hash_code();
}
