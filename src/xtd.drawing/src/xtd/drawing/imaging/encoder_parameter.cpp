#include "../../../../include/xtd/drawing/imaging/encoder_parameter.hpp"
#include <xtd/argument_out_of_range_exception>
#include <xtd/as>
#include <xtd/bit_converter>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::helpers;

namespace {
  template<class type_t>
  void add_bytes(list<byte>& bytes, type_t value) {
    auto value_bytes = bit_converter::get_bytes(value);
    bytes.insert_range(bytes.count(), value_bytes);
  }
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, byte value) : encoder_(encoder), number_of_values_(1), type_(encoder_parameter_value_type::value_type_byte) {
  add_bytes(value_, value);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, int16 value) : encoder_(encoder), number_of_values_(1), type_(encoder_parameter_value_type::value_type_short) {
  if (value < 0) throw_helper::throws(exception_case::argument_out_of_range);
  add_bytes(value_, value);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, int64 value) : encoder_(encoder), number_of_values_(1), type_(encoder_parameter_value_type::value_type_long) {
  if (value < 0) throw_helper::throws(exception_case::argument_out_of_range);
  add_bytes(value_, as<int32>(value));
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, const string& value) : encoder_(encoder), number_of_values_(value.length()), type_(encoder_parameter_value_type::value_type_ascii) {
  for (auto v : value)
    add_bytes(value_, v);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, byte value, bool undefined) : encoder_(encoder), number_of_values_(1), type_(undefined ? encoder_parameter_value_type::value_type_undefined :  encoder_parameter_value_type::value_type_byte) {
  add_bytes(value_, value);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, array<byte> value) : encoder_(encoder), number_of_values_(value.length()), type_(encoder_parameter_value_type::value_type_byte) {
  for (auto v : value)
    add_bytes(value_, v);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, array<int16> value) : encoder_(encoder), number_of_values_(value.length()), type_(encoder_parameter_value_type::value_type_short) {
  for (auto v : value) {
    if (v < 0) throw_helper::throws(exception_case::argument_out_of_range);
    add_bytes(value_, v);
  }
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, array<int32> value) : encoder_(encoder), number_of_values_(value.length()), type_(encoder_parameter_value_type::value_type_long) {
  for (auto v : value) {
    if (v < 0) throw_helper::throws(exception_case::argument_out_of_range);
    add_bytes(value_, v);
  }
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, array<int64> value) : encoder_(encoder), number_of_values_(value.length()), type_(encoder_parameter_value_type::value_type_long) {
  for (auto v : value) {
    if (v < 0) throw_helper::throws(exception_case::argument_out_of_range);
    add_bytes(value_, as<int32>(v));
  }
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, array<byte> value, bool undefined) : encoder_(encoder), number_of_values_(value.length()), type_(undefined ? encoder_parameter_value_type::value_type_undefined :  encoder_parameter_value_type::value_type_byte) {
  for (auto v : value)
    add_bytes(value_, v);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, int32 numerator, int32 denominator) : encoder_(encoder), number_of_values_(1), type_(encoder_parameter_value_type::value_type_rational) {
  if (numerator < 0 || denominator < 0) throw_helper::throws(exception_case::argument_out_of_range);
  add_bytes(value_, numerator);
  add_bytes(value_, denominator);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, int32 numerator1, int32 denominator1, int32 numerator2, int32 denominator2) : encoder_(encoder), number_of_values_(1), type_(encoder_parameter_value_type::value_type_rational_range) {
  if (numerator1 < 0 || denominator1 < 0 || numerator2 < 0 || denominator2 < 0) throw_helper::throws(exception_case::argument_out_of_range);
  add_bytes(value_, numerator1);
  add_bytes(value_, denominator1);
  add_bytes(value_, numerator2);
  add_bytes(value_, denominator2);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, array<int32> numerator, array<int32> denominator) : encoder_(encoder), number_of_values_(numerator.length()), type_(encoder_parameter_value_type::value_type_rational_range) {
  if (numerator.length() != denominator.length()) throw_helper::throws(exception_case::argument_out_of_range);
  for (auto index = 0_z; index < numerator.length(); ++index) {
    if (numerator[index] < 0 || denominator[index] < 0) throw_helper::throws(exception_case::argument_out_of_range);
    add_bytes(value_, numerator[index]);
    add_bytes(value_, denominator[index]);
  }
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, array<int64> rangebegin, array<int64> rangeend) : encoder_(encoder), number_of_values_(rangebegin.length()), type_(encoder_parameter_value_type::value_type_long_range) {
  if (rangebegin.length() != rangeend.length()) throw_helper::throws(exception_case::argument_out_of_range);
  for (auto index = 0_z; index < rangebegin.length(); ++index) {
    if (rangebegin[index] < 0 || rangeend[index] < 0) throw_helper::throws(exception_case::argument_out_of_range);
    add_bytes(value_, as<int32>(rangebegin[index]));
    add_bytes(value_, as<int32>(rangeend[index]));
  }
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, int32 number_of_values, encoder_parameter_value_type type, const array<byte>& value) : encoder_(encoder), number_of_values_(number_of_values), type_(type), value_(value) {
}

const imaging::encoder& encoder_parameter::encoder() const noexcept {
  return encoder_;
}

size encoder_parameter::number_of_values() const noexcept {
  return number_of_values_;
}

encoder_parameter_value_type encoder_parameter::type() const noexcept {
  return type_;
}

encoder_parameter_value_type encoder_parameter::value_type() const noexcept {
  return type_;
}

const list<byte>& encoder_parameter::value() const noexcept {
  return value_;
}

bool encoder_parameter::equals(const object& obj) const noexcept {
  return is<encoder_parameter>(obj) && equals(static_cast<const encoder_parameter&>(obj));
}

bool encoder_parameter::equals(const encoder_parameter& other) const noexcept {
  return encoder_ == other.encoder_ && number_of_values_ == other.number_of_values_ && type_ == other.type_ && value_ == other.value_;
}

size encoder_parameter::get_hash_code() const noexcept {
  auto result = hash_code {};
  result.add(encoder_);
  result.add(number_of_values_);
  result.add(type_);
  for (auto b : value_)
    result.add(b);
  return result.to_hash_code();
}
