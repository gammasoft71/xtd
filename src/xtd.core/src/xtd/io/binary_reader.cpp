#include "../../../include/xtd/io/binary_reader.hpp"
#include "../../../include/xtd/io/end_of_stream_exception.hpp"
#include "../../../include/xtd/io/file.hpp"
#include "../../../include/xtd/io/file_not_found_exception.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/bit_converter.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::io;

binary_reader::binary_reader(const string& path) : stream_(new std::ifstream(path, std::ios::binary)), delete_when_destroy_(true) {
  if (path.trim(' ').length() == 0 || path.index_of_any(io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (!file::exists(path)) throw_helper::throws(exception_case::file_not_found);
}

binary_reader::binary_reader(std::istream& stream) : stream_(&stream) {
}

binary_reader::~binary_reader() {
  if (delete_when_destroy_ && stream_) {
    if (dynamic_cast<std::ifstream*>(stream_)) static_cast<std::ifstream*>(stream_)->close();
    delete stream_;
  }
}

std::optional<ref<std::istream>> binary_reader::base_stream() const {
  return stream_ ? std::optional<ref<std::istream>>(*stream_) : std::nullopt;
}

bool binary_reader::end_of_stream() const {
  return peek_char() == EOF;
}

void binary_reader::close() {
  if (stream_ && dynamic_cast<std::ifstream*>(stream_)) static_cast<std::ifstream*>(stream_)->close();
  if (delete_when_destroy_) delete stream_;
  stream_ = nullptr;
}

int32 binary_reader::peek_char() const {
  if (!stream_) return EOF;
  int32 value = stream_->peek();
  return value;
}

std::streampos binary_reader::pop() {
  if (!pos_stack_.empty()) {
    stream_->seekg(pos_stack_.top(), std::ios_base::beg);
    pos_stack_.pop();
  }
  return stream_->tellg();
}

void binary_reader::push(std::streampos pos) {
  pos_stack_.push(pos == 0 ? stream_->tellg() : pos);
}

int32 binary_reader::read() {
  if (!stream_) return EOF;
  auto value = stream_->get();
  return value;
}

size_t binary_reader::read(array<xtd::byte>& buffer, size_t index, size_t count) {
  if (index + count > buffer.size()) throw_helper::throws(exception_case::argument);
  for (auto i = 0_z; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<xtd::byte>(current);
  }
  return count;
}

size_t binary_reader::read(array<char>& buffer, size_t index, size_t count) {
  if (index + count > buffer.size()) throw_helper::throws(exception_case::argument);
  for (auto i = 0_z; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<char>(current);
  }
  return count;
}

bool binary_reader::read_boolean() {
  return bit_converter::to_boolean(read_bytes(sizeof(bool)), 0);
}

xtd::byte binary_reader::read_byte() {
  return read_bytes(sizeof(xtd::byte))[0];
}

array<xtd::byte> binary_reader::read_bytes(size_t count) {
  auto result = array<xtd::byte>(count);
  if (read(result, 0, count) != count)
    throw_helper::throws(exception_case::end_of_stream);
  return result;
}

char binary_reader::read_char() {
  return read_bytes(sizeof(char))[0];
}

array<char> binary_reader::read_chars(size_t count) {
  auto result = array<char>(count);
  if (read(result, 0, count) != count)
    throw_helper::throws(exception_case::end_of_stream);
  return result;
}

double binary_reader::read_double() {
  return bit_converter::to_double(read_bytes(sizeof(double)), 0);
}

int16 binary_reader::read_int16() {
  return bit_converter::to_int16(read_bytes(sizeof(int16)), 0);
}

int32 binary_reader::read_int32() {
  return bit_converter::to_int32(read_bytes(sizeof(int32)), 0);
}

int64 binary_reader::read_int64() {
  return bit_converter::to_int64(read_bytes(sizeof(int64)), 0);
}

sbyte binary_reader::read_sbyte() {
  return read_bytes(sizeof(sbyte))[0];
}

float binary_reader::read_single() {
  return bit_converter::to_single(read_bytes(sizeof(float)), 0);
}

size binary_reader::read_size() {
  return bit_converter::to_size(read_bytes(sizeof(size)), 0);
}

string binary_reader::read_string() {
  auto length = read_7bit_encoded_int();
  if (length == 0) return {};
  return string(read_chars(length).data(), static_cast<size_t>(length));
}

uint16 binary_reader::read_uint16() {
  return bit_converter::to_uint16(read_bytes(sizeof(uint16)), 0);
}

uint32 binary_reader::read_uint32() {
  return bit_converter::to_uint32(read_bytes(sizeof(uint32)), 0);
}

uint64 binary_reader::read_uint64() {
  return bit_converter::to_uint64(read_bytes(sizeof(uint64)), 0);
}

void binary_reader::rewind() {
  stream_->seekg(0, std::ios_base::beg);
}

void binary_reader::seekg(std::streamoff pos, std::ios_base::seekdir dir) {
  stream_->seekg(pos, dir);
}

std::streampos binary_reader::tellg() {
  return stream_->tellg();
}

// From : https://github.com/dotnet/runtime/blob/1d1bf92fcf43aa6981804dc53c5174445069c9e4/src/libraries/System.Private.CoreLib/src/System/IO/BinaryReader.cs
int32 binary_reader::read_7bit_encoded_int() {
  auto result = 0_u32;
  auto byte_read_just_now = 0_u8;
  
  const auto max_bytes_without_overflow = 4;
  for (auto shift = 0; shift < max_bytes_without_overflow * 7; shift += 7) {
    byte_read_just_now = read_byte();
    result |= (byte_read_just_now & 0x7Fu) << shift;
    if (byte_read_just_now <= 0x7Fu) return static_cast<int32>(result);
  }
  
  byte_read_just_now = read_byte();
  if (byte_read_just_now > 0b1111u) throw_helper::throws(exception_case::format);
  
  result |= static_cast<uint32>(byte_read_just_now) << (max_bytes_without_overflow * 7);
  return static_cast<int32>(result);
}
