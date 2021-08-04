#include <cstring>
#include "../../include/xtd/bit_converter.h"
#include "../../include/xtd/argument_out_of_range_exception.h"

using namespace std;
using namespace xtd;

namespace {
  static const int32_t __xtd_endian__ = 1;
}

const bool bit_converter::is_little_endian = *(char*)&__xtd_endian__ == 1;

int64_t bit_converter::double_to_int64_bits(double value) {
  int64_t result = 0;
  memcpy(&result, &value, sizeof(value));
  return result;
}

vector<uint8_t> bit_converter::get_bytes(bool value) {
  return {static_cast<uint8_t>(value)};
}

vector<uint8_t> bit_converter::get_bytes(char value) {
  return bit_converter::get_bytes(((uint32_t)value));
}

vector<uint8_t> bit_converter::get_bytes(char16_t value) {
  return bit_converter::get_bytes(((uint32_t)value));
}

vector<uint8_t> bit_converter::get_bytes(char32_t value) {
  return bit_converter::get_bytes(((uint32_t)value));
}

vector<uint8_t> bit_converter::get_bytes(wchar_t value) {
  return bit_converter::get_bytes(((uint32_t)value));
}

vector<uint8_t> bit_converter::get_bytes(double value) {
  return bit_converter::get_bytes(double_to_int64_bits(value));
}

vector<uint8_t> bit_converter::get_bytes(int16_t value) {
  return bit_converter::get_bytes(uint16_t(value));
}

vector<uint8_t> bit_converter::get_bytes(int32_t value) {
  return bit_converter::get_bytes(uint32_t(value));
}

vector<uint8_t> bit_converter::get_bytes(int64_t value) {
  return bit_converter::get_bytes(uint64_t(value));
}

vector<uint8_t> bit_converter::get_bytes(float value) {
  return bit_converter::get_bytes(single_to_int32_bits(value));
}

vector<uint8_t> bit_converter::get_bytes(uint16_t value) {
  return {uint8_t(value & 0x00FF), uint8_t((value & 0xFF00) >> 8)};
}

vector<uint8_t> bit_converter::get_bytes(uint32_t value) {
  return {uint8_t(value & 0x000000FF), uint8_t((value & 0x0000FF00) >> 8), uint8_t((value & 0x00FF0000) >> 16), uint8_t((value & 0xFF000000) >> 24)};
}

vector<uint8_t> bit_converter::get_bytes(uint64_t value) {
  return {uint8_t(value & 0x00000000000000FF), uint8_t((value & 0x000000000000FF00) >> 8), uint8_t((value & 0x0000000000FF0000) >> 16), uint8_t((value & 0x00000000FF000000) >> 24), uint8_t((value & 0x000000FF00000000) >> 32), uint8_t((value & 0x0000FF0000000000) >> 40), uint8_t((value & 0x00FF000000000000) >> 48), uint8_t((value & 0xFF00000000000000) >> 56)};
}

vector<uint8_t> bit_converter::get_bytes(llong value) {
  return bit_converter::get_bytes(uint64_t(value));
}

vector<uint8_t> bit_converter::get_bytes(ullong value) {
  return bit_converter::get_bytes(uint64_t(value));
}

float bit_converter::int32_bits_to_single(int32_t value) {
  float result = 0;
  memcpy(&result, &value, sizeof(value));
  return result;
}

double bit_converter::int64_bits_to_double(int64_t value) {
  double result = 0;
  memcpy(&result, &value, sizeof(value));
  return result;
}

int32_t bit_converter::single_to_int32_bits(float value) {
  int32_t result = 0;
  memcpy(&result, &value, sizeof(value));
  return result;
}

bool bit_converter::to_boolean(const vector<uint8_t>& value, size_t start_index) {
  return static_cast<bool>(value.at(start_index));
}

char32_t bit_converter::to_char(const vector<uint8_t>& value, size_t start_index) {
  return static_cast<char32_t>(to_uint32(value, start_index));
}

double bit_converter::to_double(const vector<uint8_t>& value, size_t start_index) {
  return int64_bits_to_double(to_int64(value, start_index));
}

int16_t bit_converter::to_int16(const vector<uint8_t>& value, size_t start_index) {
  return int16_t(to_uint16(value, start_index));
}

int32_t bit_converter::to_int32(const vector<uint8_t>& value, size_t start_index) {
  return static_cast<int32_t>(to_uint32(value, start_index));
}

int64_t bit_converter::to_int64(const vector<uint8_t>& value, size_t start_index) {
  return static_cast<int64_t>(to_uint64(value, start_index));
}

float bit_converter::to_single(const vector<uint8_t>& value, size_t start_index) {
  return int32_bits_to_single(to_int32(value, start_index));
}

uint16_t bit_converter::to_uint16(const vector<uint8_t>& value, size_t start_index) {
  return static_cast<uint16_t>(value.at(start_index)) + (static_cast<uint16_t>(value.at(start_index + 1)) << 8);
}

uint32_t bit_converter::to_uint32(const vector<uint8_t>& value, size_t start_index) {
  return static_cast<uint32_t>(value.at(start_index)) + (static_cast<uint32_t>(value.at(start_index + 1)) << 8) + (static_cast<uint32_t>(value.at(start_index + 2)) << 16) + (static_cast<uint32_t>(value.at(start_index + 3)) << 24);
}

uint64_t bit_converter::to_uint64(const vector<uint8_t>& value, size_t start_index) {
  return static_cast<uint64_t>(value.at(start_index)) + (static_cast<uint64_t>(value.at(start_index + 1)) << 8) + (static_cast<uint64_t>(value.at(start_index + 2)) << 16) + (static_cast<uint64_t>(value.at(start_index + 3)) << 24) + (static_cast<uint64_t>(value.at(start_index + 4)) << 32) + (static_cast<uint64_t>(value.at(start_index + 5)) << 40) + (static_cast<uint64_t>(value.at(start_index + 6)) << 48) + (static_cast<uint64_t>(value.at(start_index + 7)) << 56);
}

ustring bit_converter::to_string(const vector<uint8_t>& value) {
  return to_string(value, 0, value.size());
}

ustring bit_converter::to_string(const vector<uint8_t>& value, size_t start_index) {
  return to_string(value, start_index, value.size() - start_index);
}

ustring bit_converter::to_string(const vector<uint8_t>& value, size_t start_index, size_t length) {
  if (value.size() == 0 && start_index == 0 && length == 0) return "";
  if (start_index >= value.size()) throw xtd::argument_out_of_range_exception(current_stack_frame_);
  if (start_index + length > value.size()) throw argument_out_of_range_exception(current_stack_frame_);

  ustring str;
  for (size_t index = start_index; index < start_index + length; index++) {
    str += ustring::format("{:X2}", value[index]);
    str += index < (start_index + length - 1) ? "-" : "";
  }
  return str;
}
