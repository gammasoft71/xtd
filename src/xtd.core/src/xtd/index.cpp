#include "../../include/xtd/index.hpp"
#include "../../include/xtd/string.hpp"
#include "../../include/xtd/usize_object.hpp"
#include "../../include/xtd/helpers/throw_helper.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::collections::generic::helpers;

auto index::equals(const object& obj) const noexcept -> bool {
  return is<index>(obj) && equals(static_cast<const index&>(obj));
}

auto index::equals(const index& value) const noexcept -> bool {
  return equator<value_type> {}(__v__, value.__v__);
}

auto index::get_hash_code() const noexcept -> usize {
  return hash_code::combine(__v__);
}

auto index::get_offset(value_type length) const noexcept -> usize {
  return is_from_end() ? length - value() : value();
}

auto index::to_string() const noexcept -> string {
  return is_from_end() ? string::format("~{}", ~__v__) : string::format("{}", __v__);
}

auto index::operator ++() noexcept -> index& {
  ++__v__;
  return *this;
}

auto index::operator --() noexcept -> index& {
  --__v__;
  return *this;
}

auto index::operator ++(int) noexcept -> index
{return index {__v__++};
}
auto index::operator --(int) noexcept -> index {
  return index {__v__--};
}

auto index::parse(const string& value) -> index {
  auto result = index {};
  if (!try_parse(value, result)) throw_helper::throws(exception_case::format);
  return result;
}

auto index::try_parse(const string& value, index& result) noexcept -> bool {
  auto from_end = value.length() >= 1 && value.starts_with("~");
  auto usize_result = usize {};
  if (!usize_object::try_parse(from_end ? value.substring(1) : value, usize_result)) return false;
  result = index {usize_result, from_end};
  return true;
}
