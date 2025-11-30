#include "../../../include/xtd/io/memory_stream.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/math.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"
#include "../../../include/xtd/not_supported_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::io;

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
  return data_->writable;
}

size memory_stream::capacity() const {
  if (data_->static_buffer) data_->static_buffer->length();
  return data_->dynamic_buffer.capacity();
}

void memory_stream::capacity(size value) {
  if (data_->static_buffer) throw_helper::throws(exception_case::not_supported);
  if (value != data_->dynamic_buffer.capacity()) data_->dynamic_buffer.capacity(value);
}

size memory_stream::length() const {
  if (data_->static_buffer) return data_->static_buffer->size();
  return data_->dynamic_buffer.count();
}

size memory_stream::position() const {
  return data_->position;
}

void memory_stream::position(size value) {
  if (value == data_->position) return;
  data_->position = value;
  seek(data_->position, seek_origin::begin);
}

void memory_stream::flush() {
}

size memory_stream::read(array<byte>& buffer, size offset, size count) {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  
  if (count == 0_z) return 0_z;
  if (offset >= buffer.length() || offset + count > buffer.length()) throw_helper::throws(exception_case::argument_out_of_range);
  if (data_->static_buffer && (data_->position + count > capacity())) throw_helper::throws(exception_case::not_supported);
  
  auto read_count = math::min(length() - data_->position, count);
  if (!read_count) return 0_z;
  for (auto index = read_count; index > 0; --index)
    buffer[offset++] = abstract_read_byte_unchecked();
  return read_count;
}

size memory_stream::seek(std::streamoff offset, seek_origin loc) {
  return position();
}

void memory_stream::set_length(size value) {
  if (data_->static_buffer) throw_helper::throws(exception_case::not_supported);
  data_->dynamic_buffer.items().resize(value);
}

array<byte> memory_stream::to_array() const {
  return data_->static_buffer ? *data_->static_buffer : data_->dynamic_buffer.to_array();
}

void memory_stream::write(const array<byte>& buffer, size offset, size count) {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_write()) throw_helper::throws(exception_case::not_supported);
  
  if (count == 0_z) return;
  if (offset >= buffer.length() || offset + count > buffer.length()) throw_helper::throws(exception_case::argument_out_of_range);
  if (data_->static_buffer && data_->position + count > capacity()) throw_helper::throws(exception_case::not_supported);
  
  if (length() < position()) {
    auto fill_count = position() - length();
    data_->position = 0;
    for (auto index = 0_z; index < fill_count; ++index)
      abstract_write_byte_unchecked({});
  }
  
  for (auto index = count; index > 0; --index)
    abstract_write_byte_unchecked(buffer[offset++]);
}

void memory_stream::write_to(std::ostream& stream) {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  
  auto current_postion = position();
  position(0_z);
  copy_to(stream);
  position(current_postion);
}

xtd::byte memory_stream::abstract_read_byte_unchecked() {
  if (data_->static_buffer) return (*data_->static_buffer)[data_->position++];
  return data_->dynamic_buffer[data_->position++];
}

void memory_stream::abstract_write_byte_unchecked(xtd::byte b) {
  if (data_->static_buffer)(*data_->static_buffer)[data_->position] = b;
  else if (data_->position < data_->dynamic_buffer.count()) data_->dynamic_buffer[data_->position] = b;
  else data_->dynamic_buffer.add(b);
  data_->position += 1;
}
