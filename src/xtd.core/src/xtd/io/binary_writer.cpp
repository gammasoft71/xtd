#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/bit_converter.hpp"
#include "../../../include/xtd/unauthorized_access_exception.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/file_not_found_exception.hpp"
#include "../../../include/xtd/io/file.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/io/binary_writer.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::io;

binary_writer::binary_writer(const string& path) : stream_(new std::ofstream(path, std::ios::out | std::ios::binary | std::ios_base::trunc)), delete_when_destroy_(true) {
  if (path.index_of_any(path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (path.empty() || path.trim(' ').empty()) throw_helper::throws(exception_case::argument);
  if (!file::exists(path)) throw_helper::throws(exception_case::file_not_found);
  if ((file::get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw_helper::throws(exception_case::unauthorized_access);
  if (!dynamic_cast<std::ofstream*>(stream_)->is_open() || !stream_->good()) throw_helper::throws(exception_case::io);
}

binary_writer::binary_writer(std::ostream& stream) : stream_(&stream) {
  if (!stream_->good()) throw_helper::throws(exception_case::io);
  stream_->flush();
}

binary_writer::~binary_writer() {
  if (delete_when_destroy_ && stream_) {
    flush();
    if (stream_ && dynamic_cast<std::ofstream*>(stream_)) static_cast<std::ofstream*>(stream_)->close();
    delete stream_;
  }
}

std::optional<std::reference_wrapper<std::ostream>> binary_writer::base_stream() const {
  return stream_ ? std::optional<std::reference_wrapper<std::ostream>>(*stream_) : std::optional<std::reference_wrapper<std::ostream>>();
}

void binary_writer::close() {
  flush();
  if (stream_ && dynamic_cast<std::ofstream*>(stream_)) static_cast<std::ofstream*>(stream_)->close();
  if (delete_when_destroy_) delete stream_;
  stream_ = nullptr;
}

void binary_writer::flush() {
  if (stream_) stream_->flush();
}

size_t binary_writer::seek(size_t offset, std::ios::seekdir origin) {
  if (!stream_) throw_helper::throws(exception_case::io);
  stream_->seekp(offset, origin);
  return static_cast<size_t>(stream_->tellp());
}

void binary_writer::write(bool value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

void binary_writer::write(xtd::byte value) {
  if (!stream_) throw_helper::throws(exception_case::io);
  stream_->put(static_cast<char>(value));
}

void binary_writer::write(char value) {
  if (!stream_) throw_helper::throws(exception_case::io);
  stream_->put(value);
}

void binary_writer::write(const read_only_span<xtd::byte>& buffer) {
  for (const auto& b : buffer)
    write(b);
}

void binary_writer::write(const array<xtd::byte>& buffer, size_t index, size_t count) {
  if (!stream_) throw_helper::throws(exception_case::io);
  if (index + count > buffer.size()) throw_helper::throws(exception_case::argument);
  for (auto i = index; i < (index + count); ++i)
    write(buffer[i]);
}

void binary_writer::write(const read_only_span<char>& buffer) {
  for (const auto& b : buffer)
    write(b);
}

void binary_writer::write(const array<char>& buffer, size_t index, size_t count) {
  if (!stream_) throw_helper::throws(exception_case::io);
  if (index + count > buffer.size()) throw_helper::throws(exception_case::argument);
  for (auto i = index; i < (index + count); ++i)
    write(buffer[i]);
}

void binary_writer::write(double value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

void binary_writer::write(int16 value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

void binary_writer::write(int32 value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

void binary_writer::write(int64 value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

void binary_writer::write(sbyte value) {
  if (!stream_) throw_helper::throws(exception_case::io);
  stream_->put(static_cast<char>(value));
}

void binary_writer::write(float value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

void binary_writer::write(const string& value) {
  write_7bit_encoded_int(static_cast<int32>(value.size()));
  for (auto c : value)
    write(c);
}

void binary_writer::write(const std::string& value) {
  write(string(value));
}

#if defined(__xtd__cpp_lib_char8_t)
void binary_writer::write(const std::u8string& value) {
  write(string(value));
}
#endif

void binary_writer::write(const std::u16string& value) {
  write(string(value));
}

void binary_writer::write(const std::u32string& value) {
  write(string(value));
}

void binary_writer::write(const std::wstring& value) {
  write(string(value));
}

void binary_writer::write(const char* value) {
  write(string(value));
}

#if defined(__xtd__cpp_lib_char8_t)
void binary_writer::write(const char8* value) {
  write(string(value));
}
#endif

void binary_writer::write(const char16* value) {
  write(string(value));
}

void binary_writer::write(const char32* value) {
  write(string(value));
}

void binary_writer::write(const wchar* value) {
  write(string(value));
}

void binary_writer::write(uint16 value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

void binary_writer::write(uint32 value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

void binary_writer::write(uint64 value) {
  write(read_only_span<byte> {bit_converter::get_bytes(value)});
}

// From https://github.com/dotnet/runtime/blob/1d1bf92fcf43aa6981804dc53c5174445069c9e4/src/libraries/System.Private.CoreLib/src/System/IO/BinaryWriter.cs
void binary_writer::write_7bit_encoded_int(int32 value) {
  auto u_value = static_cast<uint32>(value);
  
  while (u_value > 0x7Fu) {
    write(static_cast<byte>(u_value | ~0x7Fu));
    u_value >>= 7;
  }
  
  write(static_cast<byte>(u_value));
}
