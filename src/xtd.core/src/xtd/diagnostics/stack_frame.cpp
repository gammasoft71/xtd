#include "stack_frame_get_stack_frames.hpp"
#include "../../../include/xtd/diagnostics/stack_frame.hpp"
#include "../../../include/xtd/environment.hpp"
#include "../../../include/xtd/string.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

struct stack_frame::data {
  data() = default;
  data(const string& file_name, xtd::usize line_number) : file_name {file_name}, file_line_number {line_number} {}
  data(const string& file_name, xtd::usize line_number, const string& method_name) : file_name {file_name}, file_line_number {line_number}, method_name{method_name} {}
  data(const string& file_name, xtd::usize line_number, const string& method_name, xtd::usize column_number) : file_name {file_name}, file_line_number {line_number}, method_name{method_name}, file_column_number {column_number} {}
  data(const string& file_name, xtd::usize line_number, xtd::usize column_number) : file_name {file_name}, file_line_number {line_number}, file_column_number {column_number} {}
  data(const string& file_name, xtd::usize line_number, const string& method_name, xtd::usize column_number, xtd::usize offset) : file_name {file_name}, file_line_number {line_number}, method_name{method_name}, file_column_number {column_number}, offset{offset} {}
  
  xtd::string file_name;
  xtd::usize file_line_number = 0;
  xtd::string method_name;
  xtd::usize file_column_number = 0;
  xtd::usize offset = OFFSET_UNKNOWN;
};

stack_frame::stack_frame() : data_{new_ptr<data>()} {
  auto frames = get_stack_frames("", 0, false);
  if (frames.count()) {
    data_->file_name = frames[0].data_->file_name;
    data_->file_line_number = frames[0].data_->file_line_number;
    data_->file_column_number = frames[0].data_->file_column_number;
    data_->method_name = frames[0].data_->method_name;
    data_->offset = frames[0].data_->offset;
  }
}

stack_frame::stack_frame(xtd::usize skip_frame) : data_{new_ptr<data>()} {
  auto frames = get_stack_frames("", skip_frame, false);
  if (frames.count()) {
    data_->file_name = frames[0].data_->file_name;
    data_->file_line_number = frames[0].data_->file_line_number;
    data_->file_column_number = frames[0].data_->file_column_number;
    data_->method_name = frames[0].data_->method_name;
    data_->offset = frames[0].data_->offset;
  }
}

stack_frame::stack_frame(bool need_file_info) : data_{new_ptr<data>()} {
  auto frames = get_stack_frames("", 0, need_file_info);
  if (frames.count()) {
    data_->file_name = frames[0].data_->file_name;
    data_->file_line_number = frames[0].data_->file_line_number;
    data_->file_column_number = frames[0].data_->file_column_number;
    data_->method_name = frames[0].data_->method_name;
    data_->offset = frames[0].data_->offset;
  }
}

stack_frame::stack_frame(xtd::usize skip_frame, bool need_file_info) : data_{new_ptr<data>()} {
  auto frames = get_stack_frames("", skip_frame, need_file_info);
  if (frames.count()) {
    data_->file_name = frames[0].data_->file_name;
    data_->file_line_number = frames[0].data_->file_line_number;
    data_->file_column_number = frames[0].data_->file_column_number;
    data_->method_name = frames[0].data_->method_name;
    data_->offset = frames[0].data_->offset;
  }
}

stack_frame::stack_frame(const string& file_name, xtd::usize line_number) : data_{new_ptr<data>(file_name, line_number)} {
}

stack_frame::stack_frame(const string& file_name, xtd::usize line_number, const string& method_name) : data_{new_ptr<data>(file_name, line_number, method_name)} {
}

stack_frame::stack_frame(const string& file_name, xtd::usize line_number, const string& method_name, xtd::usize column_number) : data_{new_ptr<data>(file_name, line_number, method_name, column_number)} {
}

stack_frame::stack_frame(const string& file_name, xtd::usize line_number, xtd::usize column_number) : data_{new_ptr<data>(file_name, line_number, column_number)} {
}

stack_frame::stack_frame(const string& file_name, xtd::usize line_number, const string& method_name, xtd::usize column_number, xtd::usize offset) : data_{new_ptr<data>(file_name, line_number, method_name, column_number, offset)} {
}

stack_frame::stack_frame(xtd::null_ptr frame) : stack_frame{string::empty_string, 0, string::empty_string, 0, OFFSET_UNKNOWN} {
}

stack_frame::stack_frame(const xtd::diagnostics::source_location& source_location) : data_{new_ptr<data>(source_location.file_name(), source_location.line(), source_location.function_name(), source_location.column())} {
}

stack_frame::stack_frame(const xtd::diagnostics::source_location& source_location, xtd::usize offset) : data_{new_ptr<data>(source_location.file_name(), source_location.line(), source_location.function_name(), source_location.column(), offset)} {
}

stack_frame stack_frame::empty() noexcept {
  return null;
}

auto stack_frame::equals(const object& obj) const noexcept -> bool {
  return is<stack_frame>(obj) && equals(static_cast<const stack_frame&>(obj));
}

auto stack_frame::equals(const stack_frame& other) const noexcept -> bool {
  return data_->file_name == other.data_->file_name && data_->file_line_number == other.data_->file_line_number && data_->method_name == other.data_->method_name && data_->file_column_number == other.data_->file_column_number && data_->offset == other.data_->offset;
}

auto stack_frame::get_hash_code() const noexcept -> usize {
  return hash_code::combine(data_->file_name, data_->file_line_number, data_->method_name, data_->file_column_number, data_->offset);
}

auto stack_frame::get_file_column_number() const noexcept -> usize {
  return data_->file_column_number;
}

auto stack_frame::get_file_line_number() const noexcept -> usize {
  return data_->file_line_number;
}

auto stack_frame::get_file_name() const noexcept -> const string& {
  return data_->file_name;
}

auto stack_frame::get_method() const noexcept -> const string& {
  return data_->method_name;
}

auto stack_frame::get_native_offset() const noexcept -> usize {
  return native::stack_trace::get_native_offset();
}

auto stack_frame::get_offset() const noexcept -> usize {
  return data_->offset;
}

auto stack_frame::to_string() const noexcept -> string {
  if (*this == empty()) return "";
  return string::format("{} at offset {} in file:line:column {}:{}:{}{}", xtd::string::is_empty(data_->method_name) ? "<unknown method>" : data_->method_name, data_->offset == OFFSET_UNKNOWN ? "<unknown offset>" : std::to_string(data_->offset), xtd::string::is_empty(data_->file_name) ? "<filename unknown>" : data_->file_name, data_->file_line_number, data_->file_column_number, environment::new_line());
}

auto stack_frame::current(const xtd::diagnostics::source_location& value) noexcept -> stack_frame {
  return stack_frame {value};
}
