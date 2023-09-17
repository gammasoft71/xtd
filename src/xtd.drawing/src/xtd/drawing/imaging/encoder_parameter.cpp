#include "../../../../include/xtd/drawing/imaging/encoder_parameter.h"
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/as.h>
#include <xtd/bit_converter.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;

namespace {
  template<typename type_t>
  void add_bytes(vector<xtd::byte>& bytes, type_t value) {
    auto value_bytes = bit_converter::get_bytes(value);
    bytes.insert(bytes.end(), value_bytes.begin(), value_bytes.end());
  }
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, xtd::byte value) : encoder_(encoder), number_of_values_(1), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte) {
  add_bytes(value_, value);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, int16 value) : encoder_(encoder), number_of_values_(1), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_short) {
  if (value < 0) throw argument_out_of_range_exception {csf_};
  add_bytes(value_, value);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, int64 value) : encoder_(encoder), number_of_values_(1), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_long) {
  if (value < 0) throw argument_out_of_range_exception {csf_};
  add_bytes(value_, as<int32>(value));
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, const xtd::ustring& value) : encoder_(encoder), number_of_values_(value.size()), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_ascii) {
  for (auto v : value)
    add_bytes(value_, v);
}

encoder_parameter::encoder_parameter(const imaging::encoder& encoder, xtd::byte value, bool undefined) : encoder_(encoder), number_of_values_(1), type_(undefined ? xtd::drawing::imaging::encoder_parameter_value_type::value_type_undefined :  xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte) {
  add_bytes(value_, value);
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<xtd::byte> value) : encoder_(encoder), number_of_values_(value.size()), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte) {
  for (auto v : value)
    add_bytes(value_, v);
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int16> value) : encoder_(encoder), number_of_values_(value.size()), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_short) {
  for (auto v : value) {
    if (v < 0) throw argument_out_of_range_exception {csf_};
    add_bytes(value_, v);
  }
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int32> value) : encoder_(encoder), number_of_values_(value.size()), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_long) {
  for (auto v : value) {
    if (v < 0) throw argument_out_of_range_exception {csf_};
    add_bytes(value_, v);
  }
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int64> value) : encoder_(encoder), number_of_values_(value.size()), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_long) {
  for (auto v : value) {
    if (v < 0) throw argument_out_of_range_exception {csf_};
    add_bytes(value_, as<int32>(v));
  }
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<xtd::byte> value, bool undefined) : encoder_(encoder), number_of_values_(value.size()), type_(undefined ? xtd::drawing::imaging::encoder_parameter_value_type::value_type_undefined :  xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte) {
  for (auto v : value)
    add_bytes(value_, v);
}


encoder_parameter::encoder_parameter(const imaging::encoder& encoder, int32 numerator, int32 denominator) : encoder_(encoder), number_of_values_(1), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_rational) {
  if (numerator < 0 || denominator < 0) throw argument_out_of_range_exception {csf_};
  add_bytes(value_, numerator);
  add_bytes(value_, denominator);
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, int32 numerator1, int32 denominator1, int32 numerator2, int32 denominator2) : encoder_(encoder), number_of_values_(1), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_rational_range) {
  if (numerator1 < 0 || denominator1 < 0 || numerator2 < 0 || denominator2 < 0) throw argument_out_of_range_exception {csf_};
  add_bytes(value_, numerator1);
  add_bytes(value_, denominator1);
  add_bytes(value_, numerator2);
  add_bytes(value_, denominator2);
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int32> numerator, std::vector<int32> denominator) : encoder_(encoder), number_of_values_(numerator.size()), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_rational_range) {
  if (numerator.size() != denominator.size()) throw argument_out_of_range_exception {csf_};
  for (auto index = 0_sz; index < numerator.size(); ++index) {
    if (numerator[index] < 0 || denominator[index] < 0) throw argument_out_of_range_exception {csf_};
    add_bytes(value_, numerator[index]);
    add_bytes(value_, denominator[index]);
  }
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int64> rangebegin, std::vector<int64> rangeend) : encoder_(encoder), number_of_values_(rangebegin.size()), type_(xtd::drawing::imaging::encoder_parameter_value_type::value_type_long_range) {
  if (rangebegin.size() != rangeend.size()) throw argument_out_of_range_exception {csf_};
  for (auto index = 0_sz; index < rangebegin.size(); ++index) {
    if (rangebegin[index] < 0 || rangeend[index] < 0) throw argument_out_of_range_exception {csf_};
    add_bytes(value_, as<int32>(rangebegin[index]));
    add_bytes(value_, as<int32>(rangeend[index]));
  }
}

encoder_parameter::encoder_parameter(const xtd::drawing::imaging::encoder& encoder, int32 number_values, xtd::drawing::imaging::encoder_parameter_value_type type, const std::vector<xtd::byte>& value) : encoder_(encoder), number_of_values_(number_values), type_(type), value_(value) {
}

const xtd::drawing::imaging::encoder& encoder_parameter::encoder() const noexcept {
  return encoder_;
}

size_t encoder_parameter::number_of_values() const noexcept {
  return number_of_values_;
}

xtd::drawing::imaging::encoder_parameter_value_type encoder_parameter::value_type() const noexcept {
  return type_;
}

const std::vector<xtd::byte>& encoder_parameter::value() const noexcept {
  return value_;
}

bool encoder_parameter::equals(const encoder_parameter& value) const noexcept {
  return encoder_ == value.encoder_ && type_ == value.type_ && value_ == value.value_;
}
