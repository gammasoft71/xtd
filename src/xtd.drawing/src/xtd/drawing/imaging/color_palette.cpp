#include "../../../../include/xtd/drawing/imaging/color_palette.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;

array<color> color_palette::entries() const noexcept {
  return entries_.to_array();
}

int32 color_palette::flags() const noexcept {
  return flags_;
}

bool color_palette::equals(const object& obj) const noexcept {
  return is<color_palette>(obj) && equals(static_cast<const color_palette&>(obj));
}

bool color_palette::equals(const color_palette& other) const noexcept {
  return entries_ == other.entries_ && flags_ == other.flags_;
}

size color_palette::get_hash_code() const noexcept {
  auto result = hash_code {};
  for (const auto& entry : entries_)
    result.add(entry);
  result.add(flags_);
  return result.to_hash_code();
}
