#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/bit_converter.h"
#include "../../../include/xtd/unauthorized_access_exception.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/binary_writer.h"

using namespace std;
using namespace xtd;
using namespace xtd::io;

binary_writer::binary_writer(const ustring& path) : stream_(new ofstream(path, ios::out | ios::binary | ios_base::trunc)), delete_when_destroy_(true) {
  if (path.index_of_any(path::get_invalid_path_chars()) != string::npos) throw argument_exception {csf_};
  if (path.empty() || path.trim(' ').empty()) throw argument_exception {csf_};
  if (!file::exists(path)) throw file_not_found_exception {csf_};
  if ((file::get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw unauthorized_access_exception {csf_};
  if (!dynamic_cast<ofstream*>(stream_)->is_open() || !stream_->good()) throw io_exception {csf_};
}

binary_writer::binary_writer(ostream& stream) : stream_(&stream) {
  if (!stream_->good()) throw io_exception {csf_};
  stream_->flush();
}

binary_writer::~binary_writer() {
  if (delete_when_destroy_ && stream_) {
    flush();
    if (stream_ && dynamic_cast<ofstream*>(stream_)) static_cast<ofstream*>(stream_)->close();
    delete stream_;
  }
}

optional<reference_wrapper<ostream>> binary_writer::base_stream() const {
  return stream_ ? optional<reference_wrapper<ostream>>(*stream_) : optional<reference_wrapper<ostream>>();
}

void binary_writer::close() {
  flush();
  if (stream_ && dynamic_cast<ofstream*>(stream_)) static_cast<ofstream*>(stream_)->close();
  if (delete_when_destroy_) delete stream_;
  stream_ = nullptr;
}

void binary_writer::flush() {
  if (stream_) stream_->flush();
}

size_t binary_writer::seek(size_t offset, std::ios::seekdir origin) {
  if (!stream_) throw io_exception {csf_};
  stream_->seekp(offset, origin);
  return static_cast<size_t>(stream_->tellp());
}

void binary_writer::write(bool value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(xtd::byte value) {
  if (!stream_) throw io_exception {csf_};
  stream_->put(static_cast<char>(value));
}

void binary_writer::write(char value) {
  if (!stream_) throw io_exception {csf_};
  stream_->put(value);
}

void binary_writer::write(const std::vector<xtd::byte>& buffer) {
  write(buffer, 0, buffer.size());
}

void binary_writer::write(const std::vector<xtd::byte>& buffer, size_t index, size_t count) {
  if (!stream_) throw io_exception {csf_};
  if (index + count > buffer.size()) throw argument_exception {csf_};
  for (size_t i = index; i < (index + count); ++i)
    write(buffer[i]);
}

void binary_writer::write(const std::vector<char>& buffer) {
  write(buffer, 0, buffer.size());
}

void binary_writer::write(const std::vector<char>& buffer, size_t index, size_t count) {
  if (!stream_) throw io_exception {csf_};
  if (index + count > buffer.size()) throw argument_exception {csf_};
  for (size_t i = index; i < (index + count); ++i)
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
  if (!stream_) throw io_exception {csf_};
  stream_->put(static_cast<char>(value));
}

void binary_writer::write(float value) {
  write(bit_converter::get_bytes(value));
}

void binary_writer::write(const ustring& value) {
  write(static_cast<int32>(value.size()));
  for (auto c : value)
    write(c);
}

void binary_writer::write(const string& value) {
  write(ustring(value));
}

#if defined(__cpp_lib_char8_t)
void binary_writer::write(const std::u8string& value) {
  write(ustring(value));
}
#endif

void binary_writer::write(const std::u16string& value) {
  write(ustring(value));
}

void binary_writer::write(const std::u32string& value) {
  write(ustring(value));
}

void binary_writer::write(const std::wstring& value) {
  write(ustring(value));
}

void binary_writer::write(const char* value) {
  write(ustring(value));
}

#if defined(__cpp_lib_char8_t)
void binary_writer::write(const char8* value) {
  write(ustring(value));
}
#endif

void binary_writer::write(const char16* value) {
  write(ustring(value));
}

void binary_writer::write(const char32* value) {
  write(ustring(value));
}

void binary_writer::write(const wchar* value) {
  write(ustring(value));
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
