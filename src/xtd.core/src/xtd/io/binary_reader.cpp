#include "../../../include/xtd/io/binary_reader.h"
#include "../../../include/xtd/io/end_of_stream_exception.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/bit_converter.h"

using namespace std;
using namespace xtd;
using namespace xtd::io;

binary_reader::binary_reader(const ustring& path) : stream_(new ifstream(path, ios::binary)), delete_when_destroy_(true) {
  if (path.trim(' ').length() == 0 || path.index_of_any(io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception {csf_};
  if (!file::exists(path)) throw file_not_found_exception {csf_};
}

binary_reader::binary_reader(istream& stream) : stream_(&stream) {
}

binary_reader::~binary_reader() {
  if (delete_when_destroy_ && stream_) {
    if (dynamic_cast<ifstream*>(stream_)) static_cast<ifstream*>(stream_)->close();
    delete stream_;
  }
}

optional<reference_wrapper<istream>> binary_reader::base_stream() const {
  return stream_ ? optional<reference_wrapper<istream>>(*stream_) : optional<reference_wrapper<istream>>();
}

bool binary_reader::end_of_stream() const {
  return peek_char() == EOF;
}

void binary_reader::close() {
  if (stream_ && dynamic_cast<ifstream*>(stream_)) static_cast<ifstream*>(stream_)->close();
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

size_t binary_reader::read(std::vector<xtd::byte>& buffer, size_t index, size_t count) {
  if (index + count > buffer.size()) throw argument_exception {csf_};
  for (auto i = 0_sz; i < count; i++) {
    auto current = read();
    if (current == EOF) return i;
    buffer[index + i] = static_cast<xtd::byte>(current);
  }
  return count;
}

size_t binary_reader::read(std::vector<char>& buffer, size_t index, size_t count) {
  if (index + count > buffer.size()) throw argument_exception {csf_};
  for (auto i = 0_sz; i < count; i++) {
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

std::vector<xtd::byte> binary_reader::read_bytes(size_t count) {
  auto result = vector<xtd::byte>(count);
  if (read(result, 0, count) != count)
    throw end_of_stream_exception {csf_};
  return result;
}

char binary_reader::read_char() {
  return read_bytes(sizeof(char))[0];
}

std::vector<char> binary_reader::read_chars(size_t count) {
  auto result = vector<char>(count);
  if (read(result, 0, count) != count)
    throw end_of_stream_exception {csf_};
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
  return bit_converter::to_int16(read_bytes(sizeof(int64)), 0);
}

sbyte binary_reader::read_sbyte() {
  return read_bytes(sizeof(sbyte))[0];
}

float binary_reader::read_single() {
  return bit_converter::to_single(read_bytes(sizeof(float)), 0);
}

ustring binary_reader::read_string() {
  auto length = read_int32();
  return ustring(read_chars(length).data(), static_cast<size_t>(length));
}

uint16 binary_reader::read_uint16() {
  return bit_converter::to_int16(read_bytes(sizeof(int16)), 0);
}

uint32 binary_reader::read_uint32() {
  return bit_converter::to_int32(read_bytes(sizeof(int32)), 0);
}

uint64 binary_reader::read_uint64() {
  return bit_converter::to_int16(read_bytes(sizeof(int64)), 0);
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
