#include "../../../include/xtd/io/memory_stream.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/math.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"

using namespace xtd;
using namespace xtd::io;

template<class stream_t = std::nullptr_t>
struct save_position {
  save_position(const stream_t& stream);
};

template<>
struct save_position<std::istream> {
  save_position(const std::istream& input_stream) : input_stream_{input_stream}, current_input_pos_ {const_cast<std::istream&>(input_stream_).tellg()} {}
  ~save_position() {const_cast<std::istream&>(input_stream_).seekg(current_input_pos_, std::ios_base::beg);}
  
private:
  const std::istream& input_stream_;
  std::streampos current_input_pos_;
};

template<>
struct save_position<std::ostream> {
  save_position(const std::ostream& output_stream) : output_stream_{output_stream}, current_output_pos_ {const_cast<std::ostream&>(output_stream_).tellp()} {}
  ~save_position() {const_cast<std::ostream&>(output_stream_).seekp(current_output_pos_, std::ios_base::beg);}
  
private:
  const std::ostream& output_stream_;
  std::streampos current_output_pos_;
};

template<>
struct save_position<std::iostream> {
  save_position(const std::iostream& stream) : stream_{stream}, current_input_pos_ {const_cast<std::iostream&>(stream_).tellg()}, current_output_pos_ {const_cast<std::iostream&>(stream_).tellp()} {}
  ~save_position() {
    const_cast<std::iostream&>(stream_).seekg(current_input_pos_, std::ios_base::beg);
    const_cast<std::iostream&>(stream_).seekp(current_output_pos_, std::ios_base::beg);
  }

private:
  const std::iostream& stream_;
  std::streampos current_input_pos_;
  std::streampos current_output_pos_;
};

template<class stream_t = std::nullptr_t>
size get_length(const stream_t& stream) noexcept;

template<>
size get_length<std::istream>(const std::istream& stream) noexcept {
  auto save_pos = save_position<std::istream> {stream};
  auto& stream_ = const_cast<std::istream&>(stream);
  stream_.seekg(0, std::ios_base::end);
  auto length = stream_.tellg();
  return length == std::streampos {-1} ? std::streampos {0} : length;
}

template<>
size get_length<std::ostream>(const std::ostream& stream) noexcept {
  auto save_pos = save_position<std::ostream> {stream};
  auto& stream_ = const_cast<std::ostream&>(stream);
  stream_.seekp(0, std::ios_base::end);
  auto length = stream_.tellp();
  return length == std::streampos {-1} ? std::streampos {0} : length;
}

template<>
size get_length<std::iostream>(const std::iostream& stream) noexcept {
  auto save_pos = save_position<std::iostream> {stream};
  auto& stream_ = const_cast<std::iostream&>(stream);
  stream_.seekg(0, std::ios_base::end);
  stream_.seekp(0, std::ios_base::end);
  auto output_length = stream_.tellg();
  auto input_length = stream_.tellp();

  return math::min(output_length == std::streampos {-1} ? std::streampos {0} : output_length, input_length == std::streampos {-1} ? std::streampos {0} : output_length);
}

template<class stream_t = std::nullptr_t>
size get_position(const stream_t& stream) noexcept;

template<>
size get_position<std::istream>(const std::istream& stream) noexcept {
  auto position = const_cast<std::istream&>(stream).tellg();
  return position == std::streampos {-1} ? std::streampos {0} : position;
}

template<>
size get_position<std::ostream>(const std::ostream& stream) noexcept {
  auto position = const_cast<std::ostream&>(stream).tellp();
  return position == std::streampos {-1} ? std::streampos {0} : position;
}

template<>
size get_position<std::iostream>(const std::iostream& stream) noexcept {
  auto output_position = const_cast<std::iostream&>(stream).tellg();
  auto input_position = const_cast<std::iostream&>(stream).tellp();
  return math::min(output_position == std::streampos {-1} ? std::streampos {0} : output_position, input_position == std::streampos {-1} ? std::streampos {0} : input_position);
}

template<class stream_t = std::nullptr_t>
size set_length(stream_t& stream, size value);

template<>
size set_length<std::istream>(std::istream& stream, size value) {
  if (value == get_length(stream)) return get_length(stream);
  if (value > get_length(stream)) throw invalid_operation_exception {};

  auto save_pos = save_position<std::istream> {stream};
  stream.seekg(value, std::ios_base::end);

  auto default_value = char {};
  for (auto index = 0_z; index < value; ++index)
    stream.read(&default_value, 1_z);
  return get_length(stream);
}

template<>
size set_length<std::ostream>(std::ostream& stream, size value) {
  if (value == get_length(stream)) return get_length(stream);
  if (value < get_length(stream)) throw invalid_operation_exception {};

  auto save_pos = save_position<std::ostream> {stream};
  if (value > get_length(stream)) stream.seekp(0, std::ios_base::end);
  else stream.seekp(value, std::ios_base::beg);
  auto default_value = char {};
  for (auto index = get_position(stream); index < value; ++index)
    stream.write(&default_value, 1_z);
  return get_length(stream);
}

template<>
size set_length<std::iostream>(std::iostream& stream, size value) {
  auto length = get_length(stream);
  if (value == length) return get_length(stream);
  auto save_pos = save_position<std::iostream> {stream};
  if (value < length) {
    stream.seekg(value, std::ios_base::beg);
    
    auto default_value = char {};
    auto diff = length - value;
    for (auto index = 0_z; index < diff; ++index)
      stream.get(default_value);
    return value;
  }
  
  stream.seekp(length, std::ios_base::beg);
  auto default_value = char {};
  for (auto index = 0_z; index < value; ++index)
    stream.write(&default_value, 1_z);
  return length + value;
}

template<class stream_t = std::nullptr_t>
size set_position(stream_t& stream, size value);

template<>
size set_position<std::istream>(std::istream& stream, size value) {
  if (value > get_length(stream)) stream.seekg(0, std::ios_base::end);
  else stream.seekg(value, std::ios_base::beg);
  return get_position(stream);
}

template<>
size set_position<std::ostream>(std::ostream& stream, size value) {
  if (value > get_length(stream)) stream.seekp(0, std::ios_base::end);
  else stream.seekp(value, std::ios_base::beg);
  return get_position(stream);
}

template<>
size set_position<std::iostream>(std::iostream& stream, size value) {
  if (value > get_length(stream)) stream.seekg(0, std::ios_base::end);
  else stream.seekg(value, std::ios_base::beg);
  if (value > get_length(stream)) stream.seekp(0, std::ios_base::end);
  else stream.seekp(value, std::ios_base::beg);
  return get_position(stream);
}

memory_stream::memory_stream() {
}

memory_stream::memory_stream(size capacity) {
  this->capacity(capacity);
}

bool memory_stream::can_read() const noexcept {
  return true;
}

bool memory_stream::can_seek() const noexcept {
  return true;
}

bool memory_stream::can_write() const noexcept {
  return true;
}

size memory_stream::capacity() const noexcept {
  auto current_pos = rdbuf()->pubseekoff(0, std::ios::cur, std::ios::out);
  auto result = rdbuf()->pubseekoff(0, std::ios::end, std::ios::out);
  rdbuf()->pubseekpos(current_pos, std::ios::out);
  return result;
}

memory_stream& memory_stream::capacity(size value) {
  throw not_implemented_exception {};
  return *this;
}

size memory_stream::length() const noexcept {
  return get_length<std::iostream>(*this);
}

size memory_stream::position() const noexcept {
  return get_position<std::iostream>(*this);
}

memory_stream& memory_stream::position(size value) {
  set_position<std::iostream>(*this, value);
  return *this;
}

void memory_stream::copy_to(std::ostream& destination, xtd::size buffer_size) const {
  auto save_pos = save_position<std::iostream> {*this};
  auto not_const_this = const_cast<memory_stream*>(this);
  not_const_this->position(0);

  auto buffer = array<byte>(math::min(buffer_size, get_length(destination)));
  auto size = not_const_this->read(buffer);
  
  destination.write(reinterpret_cast<const char*>(buffer.data()), size);
}

const memory_stream::memory_buffer& memory_stream::get_buffer() const {
  return *rdbuf();
}

size memory_stream::read(array<byte>& buffer) {
  return read(buffer, 0_z, buffer.size());
}

size memory_stream::read(array<byte>& buffer, size offset, size count) {
  if (count == 0_z) return 0_z;
  if (offset >= buffer.size() || offset + count > buffer.size()) throw argument_out_of_range_exception {};
  auto size_to_copy = math::min(count, length());
  if (!size_to_copy) return 0_z;
  const_cast<memory_stream*>(this)->readsome(reinterpret_cast<char*>(buffer.data() + offset), size_to_copy);
  position(size_to_copy);
  return size_to_copy;
}

int32 memory_stream::read_byte() {
  auto value = 0_u8;
  if (readsome(reinterpret_cast<char*>(&value), 1) != 1) return -1;
  //position(position() + 1);
  return static_cast<int32>(value);
}

size memory_stream::seek(std::streamoff offset, seek_origin loc) {
  seekg(offset, as<std::ios_base::seekdir>(loc));
  return position();
}

void memory_stream::set_length(size value) {
  ::set_length<std::iostream>(*this, value);
}

array<byte> memory_stream::to_array() const {
  auto save_pos = save_position<std::iostream> {*this};
  auto not_const_this = const_cast<memory_stream*>(this);
  not_const_this->position(0);

  auto result = array<byte>(length());
  not_const_this->readsome(reinterpret_cast<char*>(result.data()), length());
  return result;
}

void memory_stream::write(const array<byte>& bytes) {
  write(bytes, 0_z, bytes.size());
}

void memory_stream::write(const array<byte>& bytes, size offset, size count) {
  if (offset >= bytes.size() || offset + count > bytes.size()) throw argument_out_of_range_exception {};
  for (auto index = offset; index < count; ++index)
    write_byte(bytes[index]);
}

void memory_stream::write_byte(byte value) {
  write(reinterpret_cast<const char*>(&value), 1);
  position(position() + 1);
}

void memory_stream::write_to(std::ostream& stream) const {
  if (!stream.good()) throw object_closed_exception {};
  for (auto index = 0_z; index < length(); ++index) {
    auto value = char {};
    const_cast<memory_stream*>(this)->readsome(&value, 1);
    stream.write(&value, 1);
  }
}
