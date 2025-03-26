#include "stack_frame_get_stack_frames.hpp"
#include "../../../include/xtd/diagnostics/stack_frame.hpp"
#include "../../../include/xtd/environment.hpp"
#include "../../../include/xtd/literals.hpp"
#include "../../../include/xtd/string.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

struct stack_frame::data {
  data() = default;
  data(const string& file_name, xtd::size line_number) : file_name {file_name}, file_line_number {line_number} {}
  data(const string& file_name, xtd::size line_number, const string& method_name) : file_name {file_name}, file_line_number {line_number}, method_name{method_name} {}
  data(const string& file_name, xtd::size line_number, const string& method_name, xtd::size column_number) : file_name {file_name}, file_line_number {line_number}, method_name{method_name}, file_column_number {column_number} {}
  data(const string& file_name, xtd::size line_number, xtd::size column_number) : file_name {file_name}, file_line_number {line_number}, file_column_number {column_number} {}
  data(const string& file_name, xtd::size line_number, const string& method_name, xtd::size column_number, xtd::size offset) : file_name {file_name}, file_line_number {line_number}, method_name{method_name}, file_column_number {column_number}, offset{offset} {}
  
  xtd::string file_name;
  xtd::size file_line_number = 0;
  xtd::string method_name;
  xtd::size file_column_number = 0;
  xtd::size offset = OFFSET_UNKNOWN;
};

stack_frame::stack_frame() : data_{new_ptr<data>()} {
  auto frames = get_stack_frames("", 0, false);
  if (frames.size()) {
    data_->file_name = frames[0].data_->file_name;
    data_->file_line_number = frames[0].data_->file_line_number;
    data_->file_column_number = frames[0].data_->file_column_number;
    data_->method_name = frames[0].data_->method_name;
    data_->offset = frames[0].data_->offset;
  }
}

stack_frame::stack_frame(xtd::size skip_frame) : data_{new_ptr<data>()} {
  auto frames = get_stack_frames("", skip_frame, false);
  if (frames.size()) {
    data_->file_name = frames[0].data_->file_name;
    data_->file_line_number = frames[0].data_->file_line_number;
    data_->file_column_number = frames[0].data_->file_column_number;
    data_->method_name = frames[0].data_->method_name;
    data_->offset = frames[0].data_->offset;
  }
}

stack_frame::stack_frame(bool need_file_info) : data_{new_ptr<data>()} {
  auto frames = get_stack_frames("", 0, need_file_info);
  if (frames.size()) {
    data_->file_name = frames[0].data_->file_name;
    data_->file_line_number = frames[0].data_->file_line_number;
    data_->file_column_number = frames[0].data_->file_column_number;
    data_->method_name = frames[0].data_->method_name;
    data_->offset = frames[0].data_->offset;
  }
}

stack_frame::stack_frame(xtd::size skip_frame, bool need_file_info) : data_{new_ptr<data>()} {
  auto frames = get_stack_frames("", skip_frame, need_file_info);
  if (frames.size()) {
    data_->file_name = frames[0].data_->file_name;
    data_->file_line_number = frames[0].data_->file_line_number;
    data_->file_column_number = frames[0].data_->file_column_number;
    data_->method_name = frames[0].data_->method_name;
    data_->offset = frames[0].data_->offset;
  }
}

stack_frame::stack_frame(const string& file_name, xtd::size line_number) : data_{new_ptr<data>(file_name, line_number)} {
}

stack_frame::stack_frame(const string& file_name, xtd::size line_number, const string& method_name) : data_{new_ptr<data>(file_name, line_number, method_name)} {
}

stack_frame::stack_frame(const string& file_name, xtd::size line_number, const string& method_name, xtd::size column_number) : data_{new_ptr<data>(file_name, line_number, method_name, column_number)} {
}

stack_frame::stack_frame(const string& file_name, xtd::size line_number, xtd::size column_number) : data_{new_ptr<data>(file_name, line_number, column_number)} {
}

stack_frame::stack_frame(const string& file_name, xtd::size line_number, const string& method_name, xtd::size column_number, xtd::size offset) : data_{new_ptr<data>(file_name, line_number, method_name, column_number, offset)} {
}

stack_frame::stack_frame(xtd::null_ptr frame) : stack_frame{string::empty_string, 0, string::empty_string, 0, OFFSET_UNKNOWN} {
}

stack_frame::stack_frame(const xtd::diagnostics::source_location& source_location) : data_{new_ptr<data>(source_location.file_name(), source_location.line(), source_location.function_name(), source_location.column())} {
}

stack_frame::stack_frame(const xtd::diagnostics::source_location& source_location, xtd::size offset) : data_{new_ptr<data>(source_location.file_name(), source_location.line(), source_location.function_name(), source_location.column(), offset)} {
}

stack_frame stack_frame::empty() noexcept {
  return null;
}

bool stack_frame::equals(const object& obj) const noexcept {
  return is<stack_frame>(obj) && equals(static_cast<const stack_frame&>(obj));
}

bool stack_frame::equals(const stack_frame& other) const noexcept {
  return data_->file_name == other.data_->file_name && data_->file_line_number == other.data_->file_line_number && data_->method_name == other.data_->method_name && data_->file_column_number == other.data_->file_column_number && data_->offset == other.data_->offset;
}

size stack_frame::get_hash_code() const noexcept {
  return hash_code::combine(data_->file_name, data_->file_line_number, data_->method_name, data_->file_column_number, data_->offset);
}

xtd::size stack_frame::get_file_column_number() const noexcept {
  return data_->file_column_number;
}

xtd::size stack_frame::get_file_line_number() const noexcept {
  return data_->file_line_number;
}

const string& stack_frame::get_file_name() const noexcept {
  return data_->file_name;
}

const string& stack_frame::get_method() const noexcept {
  return data_->method_name;
}

xtd::size stack_frame::get_native_offset() const noexcept {
  return native::stack_trace::get_native_offset();
}

xtd::size stack_frame::get_offset() const noexcept {
  return data_->offset;
}

string stack_frame::to_string() const noexcept {
  if (*this == empty()) return "";
  return string::format("{} at offset {} in file:line:column {}:{}:{}{}", data_->method_name.empty() ? "<unknown method>" : data_->method_name, data_->offset == OFFSET_UNKNOWN ? "<unknown offset>" : std::to_string(data_->offset), data_->file_name.empty() ? "<filename unknown>" : data_->file_name, data_->file_line_number, data_->file_column_number, environment::new_line());
}

stack_frame stack_frame::current(const xtd::diagnostics::source_location& value) noexcept {
  return stack_frame {value};
}
