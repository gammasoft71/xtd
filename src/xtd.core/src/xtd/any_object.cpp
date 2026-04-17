#include "../../include/xtd/any_object.hpp"
#include "../../include/xtd/globalization/culture_info.hpp"

using namespace xtd;

bool any_object::has_value() const noexcept {return value_ != null;}

const object& any_object::value() const {
  if (value_ == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return *value_;
}

int32 any_object::compare_to(const any_object& other) const noexcept {
  if (!has_value() && other.has_value()) return -1;
  if (has_value() && !other.has_value()) return 1;
  return xtd::collections::generic::helpers::comparer<ptr<object>> {}(value_, other.value_);
}

bool any_object::equals(const object& other) const noexcept {
  return dynamic_cast<const any_object*>(&other) && equals(static_cast<const any_object&>(other));
}

bool any_object::equals(const any_object& other) const noexcept {
  if (!has_value() && !other.has_value()) return true;
  if (has_value() != other.has_value()) return false;
  return value_->equals(*other.value_);
}

xtd::usize any_object::get_hash_code() const noexcept {
  return has_value() ? value_->get_hash_code() : 0;
}

string any_object::to_string() const noexcept {
  return has_value() ? value_->to_string() : "(null)";
}

void any_object::reset() noexcept {
  value_.reset();}

any_object& any_object::operator =(any_object&& other) noexcept {
  value_ = std::move(other.value_);
  return *this;
};

//ptr<object> any_object::boxing_ptr(const object& value) noexcept {return new value;}
ptr<object> any_object::boxing_ptr(const char* value) noexcept {
  return new_ptr<string>(value);
}

ptr<object> any_object::boxing_ptr(const char8* value) noexcept {return  new_ptr<string>(value);
}

ptr<object> any_object::boxing_ptr(const char16* value) noexcept {
  return new_ptr<string>(value);
}

ptr<object> any_object::boxing_ptr(const char32* value) noexcept {
  return new_ptr<string>(value);
}

ptr<object> any_object::boxing_ptr(const wchar* value) noexcept {
  return new_ptr<string>(value);
}

ptr<object> any_object::boxing_ptr(const char& value) noexcept {
  return new_ptr<char_object>(value);
}

ptr<object> any_object::boxing_ptr(const char8& value) noexcept {
  return new_ptr<char8_object>(value);
}

ptr<object> any_object::boxing_ptr(const char16& value) noexcept {
  return new_ptr<char16_object>(value);
}

ptr<object> any_object::boxing_ptr(const char32& value) noexcept {
  return new_ptr<char32_object>(value);
}

ptr<object> any_object::boxing_ptr(const wchar& value) noexcept {
  return new_ptr<wchar_object>(value);
}

ptr<object> any_object::boxing_ptr(char& value) noexcept {
  return new_ptr<char_object>(value);
}

ptr<object> any_object::boxing_ptr(char8& value) noexcept {
  return new_ptr<char8_object>(value);
}

ptr<object> any_object::boxing_ptr(char16& value) noexcept {
  return new_ptr<char16_object>(value);
}

ptr<object> any_object::boxing_ptr(char32& value) noexcept {
  return new_ptr<char32_object>(value);
}

ptr<object> any_object::boxing_ptr(wchar& value) noexcept {
  return new_ptr<wchar_object>(value);
}

ptr<object> any_object::boxing_ptr(const xtd::byte& value) noexcept {
  return new_ptr<byte_object>(value);
}

ptr<object> any_object::boxing_ptr(const int16& value) noexcept {
  return new_ptr<int16_object>(value);
}

ptr<object> any_object::boxing_ptr(const int32& value) noexcept {
  return new_ptr<int32_object>(value);
}

ptr<object> any_object::boxing_ptr(const int64& value) noexcept {
  return new_ptr<int64_object>(value);
}

ptr<object> any_object::boxing_ptr(const slong& value) noexcept {
  return new_ptr<slong_object>(value);
}

ptr<object> any_object::boxing_ptr(const sbyte& value) noexcept {
  return new_ptr<sbyte_object>(value);
}

ptr<object> any_object::boxing_ptr(const uint16& value) noexcept {
  return new_ptr<uint16_object>(value);
}

ptr<object> any_object::boxing_ptr(const uint32& value) noexcept {
  return new_ptr<uint32_object>(value);
}

ptr<object> any_object::boxing_ptr(const uint64& value) noexcept {
  return new_ptr<uint64_object>(value);
}

ptr<object> any_object::boxing_ptr(const xtd::ulong& value) noexcept {
  return new_ptr<ulong_object>(value);
}

ptr<object> any_object::boxing_ptr(xtd::byte& value) noexcept {
  return new_ptr<byte_object>(value);
}

ptr<object> any_object::boxing_ptr(int16& value) noexcept {
  return new_ptr<int16_object>(value);
}

ptr<object> any_object::boxing_ptr(int32& value) noexcept {
  return new_ptr<int32_object>(value);
}

ptr<object> any_object::boxing_ptr(int64& value) noexcept {
  return new_ptr<int64_object>(value);
}

ptr<object> any_object::boxing_ptr(slong& value) noexcept {
  return new_ptr<slong_object>(value);
}

ptr<object> any_object::boxing_ptr(sbyte& value) noexcept {
  return new_ptr<sbyte_object>(value);
}

ptr<object> any_object::boxing_ptr(uint16& value) noexcept {
  return new_ptr<uint16_object>(value);
}

ptr<object> any_object::boxing_ptr(uint32& value) noexcept {
  return new_ptr<uint32_object>(value);
}

ptr<object> any_object::boxing_ptr(uint64& value) noexcept {
  return new_ptr<uint64_object>(value);
}

ptr<object> any_object::boxing_ptr(xtd::ulong& value) noexcept {
  return new_ptr<ulong_object>(value);
}

ptr<object> any_object::boxing_ptr(const float& value) noexcept {
  return new_ptr<single_object>(value);
}

ptr<object> any_object::boxing_ptr(const double& value) noexcept {
  return new_ptr<double_object>(value);
}

ptr<object> any_object::boxing_ptr(const decimal& value) noexcept {
  return new_ptr<decimal_object>(value);
}

ptr<object> any_object::boxing_ptr(float& value) noexcept {
  return new_ptr<single_object>(value);
}

ptr<object> any_object::boxing_ptr(double& value) noexcept {
  return new_ptr<double_object>(value);
}

ptr<object> any_object::boxing_ptr(decimal& value) noexcept {
  return new_ptr<decimal_object>(value);
}

ptr<object> any_object::boxing_ptr(std::nullptr_t value) noexcept {
  return ptr<object> {};
}
