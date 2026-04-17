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

auto binary_reader::base_stream() const -> std::optional<ref<std::istream>> {
  return stream_ ? std::optional<ref<std::istream>>(*stream_) : std::nullopt;
}

auto binary_reader::end_of_stream() const -> bool {
  return peek_char() == EOF;
}

auto binary_reader::close() -> void {
  if (stream_ && dynamic_cast<std::ifstream*>(stream_)) static_cast<std::ifstream*>(stream_)->close();
  if (delete_when_destroy_) delete stream_;
  stream_ = nullptr;
}

auto binary_reader::peek_char() const -> int32 {
  if (!stream_) return EOF;
  int32 value = stream_->peek();
  return value;
}

auto binary_reader::pop() -> std::streampos {
  if (!pos_stack_.empty()) {
    stream_->seekg(pos_stack_.top(), std::ios_base::beg);
    pos_stack_.pop();
  }
  return stream_->tellg();
}

auto binary_reader::push(std::streampos pos) -> void {
  pos_stack_.push(pos == 0 ? stream_->tellg() : pos);
}

auto binary_reader::read() -> int32 {
  if (!stream_) return EOF;
  auto value = stream_->get();
  return value;
}

auto binary_reader::read(array<xtd::byte>& buffer, usize index, usize count) -> usize {
  if (index + count > buffer.length()) throw_helper::throws(exception_case::argument);
  for (auto i = 0_z; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<xtd::byte>(current);
  }
  return count;
}

auto binary_reader::read(array<char>& buffer, usize index, usize count) -> usize {
  if (index + count > buffer.length()) throw_helper::throws(exception_case::argument);
  for (auto i = 0_z; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<char>(current);
  }
  return count;
}

auto binary_reader::read_boolean() -> bool {
  return bit_converter::to_boolean(read_bytes(sizeof(bool)), 0);
}

auto binary_reader::read_byte() -> xtd::byte {
  return read_bytes(sizeof(xtd::byte))[0];
}

auto binary_reader::read_bytes(usize count) -> array<xtd::byte> {
  auto result = array<xtd::byte>(count);
  if (read(result, 0, count) != count)
    throw_helper::throws(exception_case::end_of_stream);
  return result;
}

auto binary_reader::read_char() -> char {
  return read_bytes(sizeof(char))[0];
}

auto binary_reader::read_chars(usize count) -> array<char> {
  auto result = array<char>(count);
  if (read(result, 0, count) != count)
    throw_helper::throws(exception_case::end_of_stream);
  return result;
}

auto binary_reader::read_double() -> double {
  return bit_converter::to_double(read_bytes(sizeof(double)), 0);
}

auto binary_reader::read_int16() -> int16 {
  return bit_converter::to_int16(read_bytes(sizeof(int16)), 0);
}

auto binary_reader::read_int32() -> int32 {
  return bit_converter::to_int32(read_bytes(sizeof(int32)), 0);
}

auto binary_reader::read_int64() -> int64 {
  return bit_converter::to_int64(read_bytes(sizeof(int64)), 0);
}

auto binary_reader::read_sbyte() -> sbyte {
  return read_bytes(sizeof(sbyte))[0];
}

auto binary_reader::read_single() -> float {
  return bit_converter::to_single(read_bytes(sizeof(float)), 0);
}

auto binary_reader::read_size() -> usize {
  return bit_converter::to_size(read_bytes(sizeof(usize)), 0);
}

auto binary_reader::read_string() -> string {
  auto length = read_7bit_encoded_int();
  if (length == 0) return {};
  return string(read_chars(length).data(), static_cast<usize>(length));
}

auto binary_reader::read_uint16() -> uint16 {
  return bit_converter::to_uint16(read_bytes(sizeof(uint16)), 0);
}

auto binary_reader::read_uint32() -> uint32 {
  return bit_converter::to_uint32(read_bytes(sizeof(uint32)), 0);
}

auto binary_reader::read_uint64() -> uint64 {
  return bit_converter::to_uint64(read_bytes(sizeof(uint64)), 0);
}

auto binary_reader::rewind() -> void{
  stream_->seekg(0, std::ios_base::beg);
}

auto binary_reader::seek(std::streamoff pos, std::ios_base::seekdir dir) -> void {
  stream_->seekg(pos, dir);
}

auto binary_reader::tell() -> std::streampos {
  return stream_->tellg();
}

// From : https://github.com/dotnet/runtime/blob/1d1bf92fcf43aa6981804dc53c5174445069c9e4/src/libraries/System.Private.CoreLib/src/System/IO/BinaryReader.cs
auto binary_reader::read_7bit_encoded_int() -> int32 {
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
