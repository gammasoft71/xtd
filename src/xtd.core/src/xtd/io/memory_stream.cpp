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

auto memory_stream::can_read() const noexcept -> bool {
  return true;
}

auto memory_stream::can_seek() const noexcept -> bool {
  return true;
}

auto memory_stream::can_write() const noexcept -> bool {
  return data_->writable;
}

auto memory_stream::capacity() const -> size {
  if (data_->static_buffer) return data_->static_buffer->length();
  return data_->dynamic_buffer.capacity();
}

auto memory_stream::capacity(size value) -> void {
  if (data_->static_buffer) throw_helper::throws(exception_case::not_supported);
  if (value != data_->dynamic_buffer.capacity()) data_->dynamic_buffer.capacity(value);
}

auto memory_stream::length() const -> size {
  if (data_->static_buffer) return data_->static_buffer->size();
  return data_->dynamic_buffer.count();
}

auto memory_stream::position() const -> size {
  return data_->position;
}

auto memory_stream::position(size value) -> void {
  if (value == data_->position) return;
  seek(value, seek_origin::begin);
}

auto memory_stream::flush() -> void {
}

auto memory_stream::read(array<byte>& buffer, size offset, size count) -> size {
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

auto memory_stream::seek(std::streamoff offset, seek_origin loc) -> size {
  if (!enum_object<>::is_defined(loc)) throw_helper::throws(exception_case::argument);
  switch(loc) {
    case seek_origin::begin: data_->position = offset; break;
    case seek_origin::current: data_->position += offset; break;
    case seek_origin::end: data_->position = length() + offset; break;
  }
  if (data_->position > length()) throw_helper::throws(exception_case::argument_out_of_range);
  return position();
}

auto memory_stream::set_length(size value) -> void {
  if (data_->static_buffer) throw_helper::throws(exception_case::not_supported);
  data_->dynamic_buffer.items().resize(value);
}

auto memory_stream::to_array() const -> array<byte> {
  return data_->static_buffer ? *data_->static_buffer : data_->dynamic_buffer.to_array();
}

auto memory_stream::write(const array<byte>& buffer, size offset, size count) -> void {
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

auto memory_stream::write_to(std::ostream& stream) -> void {
  if (is_closed()) throw_helper::throws(exception_case::object_closed);
  if (!can_read()) throw_helper::throws(exception_case::not_supported);
  
  auto current_postion = position();
  position(0_z);
  copy_to(stream);
  position(current_postion);
}

auto memory_stream::abstract_read_byte_unchecked() -> xtd::byte {
  if (data_->static_buffer) return (*data_->static_buffer)[data_->position++];
  return data_->dynamic_buffer[data_->position++];
}

auto memory_stream::abstract_write_byte_unchecked(xtd::byte b) -> void {
  if (data_->static_buffer)(*data_->static_buffer)[data_->position] = b;
  else if (data_->position < data_->dynamic_buffer.count()) data_->dynamic_buffer[data_->position] = b;
  else data_->dynamic_buffer.add(b);
  data_->position += 1;
}
