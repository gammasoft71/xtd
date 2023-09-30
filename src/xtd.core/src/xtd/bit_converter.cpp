#include "../../include/xtd/bit_converter.h"
#include "../../include/xtd/argument_out_of_range_exception.h"
#include <cstring>

using namespace std;
using namespace xtd;

int64 bit_converter::double_to_int64_bits(double value) noexcept {
  auto result = 0_s64;
  memcpy(&result, &value, sizeof(value));
  return result;
}

vector<xtd::byte> bit_converter::get_bytes(bool value) noexcept {
  return {static_cast<xtd::byte>(value)};
}

vector<xtd::byte> bit_converter::get_bytes(char value) noexcept {
  return bit_converter::get_bytes(((uint32)value));
}

vector<xtd::byte> bit_converter::get_bytes(char16 value) noexcept {
  return bit_converter::get_bytes(((uint32)value));
}

vector<xtd::byte> bit_converter::get_bytes(char32 value) noexcept {
  return bit_converter::get_bytes(((uint32)value));
}

vector<xtd::byte> bit_converter::get_bytes(wchar value) noexcept {
  return bit_converter::get_bytes(((uint32)value));
}

vector<xtd::byte> bit_converter::get_bytes(double value) noexcept {
  return bit_converter::get_bytes(double_to_int64_bits(value));
}

vector<xtd::byte> bit_converter::get_bytes(sbyte value) noexcept {
  return bit_converter::get_bytes(xtd::byte(value));
}

vector<xtd::byte> bit_converter::get_bytes(int16 value) noexcept {
  return bit_converter::get_bytes(uint16(value));
}

vector<xtd::byte> bit_converter::get_bytes(int32 value) noexcept {
  return bit_converter::get_bytes(uint32(value));
}

vector<xtd::byte> bit_converter::get_bytes(int64 value) noexcept {
  return bit_converter::get_bytes(uint64(value));
}

vector<xtd::byte> bit_converter::get_bytes(float value) noexcept {
  return bit_converter::get_bytes(single_to_int32_bits(value));
}

vector<xtd::byte> bit_converter::get_bytes(xtd::byte value) noexcept {
  return {value};
}

vector<xtd::byte> bit_converter::get_bytes(uint16 value) noexcept {
  if (is_little_endian) return {xtd::byte(value & 0x00FF), xtd::byte((value & 0xFF00) >> 8)};
  return {xtd::byte((value & 0xFF00) >> 8), xtd::byte(value & 0x00FF)};
}

vector<xtd::byte> bit_converter::get_bytes(uint32 value) noexcept {
  if (is_little_endian) return {xtd::byte(value & 0x000000FF), xtd::byte((value & 0x0000FF00) >> 8), xtd::byte((value & 0x00FF0000) >> 16), xtd::byte((value & 0xFF000000) >> 24)};
  return {xtd::byte((value & 0xFF000000) >> 24), xtd::byte((value & 0x00FF0000) >> 16), xtd::byte((value & 0x0000FF00) >> 8), xtd::byte(value & 0x000000FF)};
}

vector<xtd::byte> bit_converter::get_bytes(uint64 value) noexcept {
  if (is_little_endian) return {xtd::byte(value & 0x00000000000000FF), xtd::byte((value & 0x000000000000FF00) >> 8), xtd::byte((value & 0x0000000000FF0000) >> 16), xtd::byte((value & 0x00000000FF000000) >> 24), xtd::byte((value & 0x000000FF00000000) >> 32), xtd::byte((value & 0x0000FF0000000000) >> 40), xtd::byte((value & 0x00FF000000000000) >> 48), xtd::byte((value & 0xFF00000000000000) >> 56)};
  return {xtd::byte((value & 0xFF00000000000000) >> 56), xtd::byte((value & 0x00FF000000000000) >> 48), xtd::byte((value & 0x0000FF0000000000) >> 40), xtd::byte((value & 0x000000FF00000000) >> 32), xtd::byte((value & 0x00000000FF000000) >> 24), xtd::byte((value & 0x0000000000FF0000) >> 16), xtd::byte((value & 0x000000000000FF00) >> 8), xtd::byte(value & 0x00000000000000FF)};
}

vector<xtd::byte> bit_converter::get_bytes(slong value) noexcept {
  return bit_converter::get_bytes(uint64(value));
}

vector<xtd::byte> bit_converter::get_bytes(xtd::ulong value) noexcept {
  return bit_converter::get_bytes(uint64(value));
}

float bit_converter::int32_bits_to_single(int32 value) noexcept {
  auto result = .0f;
  memcpy(&result, &value, sizeof(value));
  return result;
}

double bit_converter::int64_bits_to_double(int64 value) noexcept {
  auto result = .0;
  memcpy(&result, &value, sizeof(value));
  return result;
}

int32 bit_converter::single_to_int32_bits(float value) noexcept {
  auto result = 0;
  memcpy(&result, &value, sizeof(value));
  return result;
}

bool bit_converter::to_boolean(const vector<xtd::byte>& value, size_t start_index) {
  return static_cast<bool>(value.at(start_index));
}

char32 bit_converter::to_char(const vector<xtd::byte>& value, size_t start_index) {
  return static_cast<char32>(to_uint32(value, start_index));
}

double bit_converter::to_double(const vector<xtd::byte>& value, size_t start_index) {
  return int64_bits_to_double(to_int64(value, start_index));
}

int16 bit_converter::to_int16(const vector<xtd::byte>& value, size_t start_index) {
  return int16(to_uint16(value, start_index));
}

int32 bit_converter::to_int32(const vector<xtd::byte>& value, size_t start_index) {
  return static_cast<int32>(to_uint32(value, start_index));
}

int64 bit_converter::to_int64(const vector<xtd::byte>& value, size_t start_index) {
  return static_cast<int64>(to_uint64(value, start_index));
}

float bit_converter::to_single(const vector<xtd::byte>& value, size_t start_index) {
  return int32_bits_to_single(to_int32(value, start_index));
}

uint16 bit_converter::to_uint16(const vector<xtd::byte>& value, size_t start_index) {
  return static_cast<uint16>(value.at(start_index)) + (static_cast<uint16>(value.at(start_index + 1)) << 8);
}

uint32 bit_converter::to_uint32(const vector<xtd::byte>& value, size_t start_index) {
  return static_cast<uint32>(value.at(start_index)) + (static_cast<uint32>(value.at(start_index + 1)) << 8) + (static_cast<uint32>(value.at(start_index + 2)) << 16) + (static_cast<uint32>(value.at(start_index + 3)) << 24);
}

uint64 bit_converter::to_uint64(const vector<xtd::byte>& value, size_t start_index) {
  return static_cast<uint64>(value.at(start_index)) + (static_cast<uint64>(value.at(start_index + 1)) << 8) + (static_cast<uint64>(value.at(start_index + 2)) << 16) + (static_cast<uint64>(value.at(start_index + 3)) << 24) + (static_cast<uint64>(value.at(start_index + 4)) << 32) + (static_cast<uint64>(value.at(start_index + 5)) << 40) + (static_cast<uint64>(value.at(start_index + 6)) << 48) + (static_cast<uint64>(value.at(start_index + 7)) << 56);
}

ustring bit_converter::to_string(const vector<xtd::byte>& value) {
  return to_string(value, 0, value.size());
}

ustring bit_converter::to_string(const vector<xtd::byte>& value, size_t start_index) {
  return to_string(value, start_index, value.size() - start_index);
}

ustring bit_converter::to_string(const vector<xtd::byte>& value, size_t start_index, size_t length) {
  if (value.size() == 0 && start_index == 0 && length == 0) return "";
  if (start_index >= value.size()) throw xtd::argument_out_of_range_exception {csf_};
  if (start_index + length > value.size()) throw argument_out_of_range_exception {csf_};
  
  ustring str;
  for (auto index = start_index; index < start_index + length; ++index) {
    str += ustring::format("{:X2}", value[index]);
    str += index < (start_index + length - 1) ? "-" : "";
  }
  return str;
}
