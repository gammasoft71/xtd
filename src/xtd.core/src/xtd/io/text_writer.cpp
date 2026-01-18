#include "../../../include/xtd/io/text_writer.hpp"
#include <mutex>

std::recursive_mutex __synchronized_text_writer_mutex__;

using namespace xtd::io;

auto text_writer::new_line() const noexcept -> const xtd::string& {
  return new_line_;
}

auto text_writer::new_line(const xtd::string& new_line) noexcept -> void {
  new_line_ = new_line;
}

auto text_writer::null() noexcept -> null_text_writer& {
  static auto null_text_writer = io::null_text_writer {};
  return null_text_writer;
}

auto text_writer::close() -> void {
}

auto text_writer::flush() -> void {
}

auto text_writer::synchronised(text_writer& writer) noexcept -> synchronized_text_writer {
  return synchronized_text_writer(writer);
}

auto text_writer::write(const xtd::string& value) -> void {
}

auto text_writer::write(bool value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(double value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(float value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(sbyte value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(int16 value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(int32 value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(int64 value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(xtd::byte value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(uint16 value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(uint32 value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write(uint64 value) -> void {
  write(xtd::string::format("{}", value));
}

auto text_writer::write_line() -> void {write(new_line_);}

auto text_writer::write_line(const xtd::string& value) -> void {
  write(value);
  write_line();
}

auto text_writer::write_line(bool value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(double value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(float value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(sbyte value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(int16 value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(int32 value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(int64 value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(xtd::byte value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(uint16 value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(uint32 value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto text_writer::write_line(uint64 value) -> void {
  write_line(xtd::string::format("{}", value));
}

auto null_text_writer::write(const xtd::string&) -> void {
}

auto synchronized_text_writer::write(const xtd::string& value) -> void {
  auto lock = std::lock_guard<std::recursive_mutex> {__synchronized_text_writer_mutex__};
  writer_.write(value);
}

synchronized_text_writer::synchronized_text_writer(xtd::io::text_writer& writer) : writer_(writer) {
}
