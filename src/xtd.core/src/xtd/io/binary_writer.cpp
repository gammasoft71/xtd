#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/bit_converter.h"
#include "../../../include/xtd/unauthorized_access_exception.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/binary_writer.h"

using namespace xtd;
using namespace xtd::io;

binary_writer::binary_writer(const string& path) : stream_(new std::ofstream(path, std::ios::out | std::ios::binary | std::ios_base::trunc)), delete_when_destroy_(true) {
  if (path.index_of_any(path::get_invalid_path_chars()) != string::npos) throw argument_exception {};
  if (path.empty() || path.trim(' ').empty()) throw argument_exception {};
  if (!file::exists(path)) throw file_not_found_exception {};
  if ((file::get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw unauthorized_access_exception {};
  if (!dynamic_cast<std::ofstream*>(stream_)->is_open() || !stream_->good()) throw io_exception {};
}

binary_writer::binary_writer(std::ostream& stream) : stream_(&stream) {
  if (!stream_->good()) throw io_exception {};
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
  if (!stream_) throw io_exception {};
  stream_->seekp(offset, origin);
  return static_cast<size_t>(stream_->tellp());
}

void binary_writer::write(bool value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(xtd::byte value) {
  if (!stream_) throw io_exception {};
  stream_->put(static_cast<char>(value));
}

void binary_writer::write(char value) {
  if (!stream_) throw io_exception {};
  stream_->put(value);
}

void binary_writer::write(const std::vector<xtd::byte>& buffer) {
  write(buffer, 0, buffer.size());
}

void binary_writer::write(const std::vector<xtd::byte>& buffer, size_t index, size_t count) {
  if (!stream_) throw io_exception {};
  if (index + count > buffer.size()) throw argument_exception {};
  for (auto i = index; i < (index + count); ++i)
    write(buffer[i]);
}

void binary_writer::write(const std::vector<char>& buffer) {
  write(buffer, 0, buffer.size());
}

void binary_writer::write(const std::vector<char>& buffer, size_t index, size_t count) {
  if (!stream_) throw io_exception {};
  if (index + count > buffer.size()) throw argument_exception {};
  for (auto i = index; i < (index + count); ++i)
    write(buffer[i]);
}

void binary_writer::write(double value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(int16 value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(int32 value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(int64 value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(sbyte value) {
  if (!stream_) throw io_exception {};
  stream_->put(static_cast<char>(value));
}

void binary_writer::write(float value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(const string& value) {
  write(static_cast<int32>(value.size()));
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
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(uint32 value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(uint64 value) {
  write(bit_converter::get_bytes(value));
}
