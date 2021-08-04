#include "../../../include/xtd/diagnostics/stack_frame.h"
#include "../../../include/xtd/strings.h"
#include <call_stack.h>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

stack_frame::stack_frame() {
  auto frames = get_stack_frames("", 0, false);
  if (frames.size()) {
    file_name_ = frames[0].file_name_;
    file_line_number_ = frames[0].file_line_number_;
    file_column_number_ = frames[0].file_column_number_;
    method_name_ = frames[0].method_name_;
    offset_ = frames[0].offset_;
  }
}

stack_frame::stack_frame(size_t skip_frame) {
  auto frames = get_stack_frames("", skip_frame, false);
  if (frames.size()) {
    file_name_ = frames[0].file_name_;
    file_line_number_ = frames[0].file_line_number_;
    file_column_number_ = frames[0].file_column_number_;
    method_name_ = frames[0].method_name_;
    offset_ = frames[0].offset_;
  }
}

stack_frame::stack_frame(bool need_file_info) {
  auto frames = get_stack_frames("", 0, need_file_info);
  if (frames.size()) {
    file_name_ = frames[0].file_name_;
    file_line_number_ = frames[0].file_line_number_;
    file_column_number_ = frames[0].file_column_number_;
    method_name_ = frames[0].method_name_;
    offset_ = frames[0].offset_;
  }
}

stack_frame::stack_frame(size_t skip_frame, bool need_file_info) {
  auto frames = get_stack_frames("", skip_frame, need_file_info);
  if (frames.size()) {
    file_name_ = frames[0].file_name_;
    file_line_number_ = frames[0].file_line_number_;
    file_column_number_ = frames[0].file_column_number_;
    method_name_ = frames[0].method_name_;
    offset_ = frames[0].offset_;
  }
}

stack_frame::stack_frame(const string& file_name, uint32_t line_number) : file_name_(file_name), file_line_number_(line_number) {
}

stack_frame::stack_frame(const string& file_name, uint32_t line_number, const string& method_name) : file_name_(file_name), file_line_number_(line_number), method_name_(method_name) {
}

stack_frame::stack_frame(const string& file_name, uint32_t line_number, const string& method_name, uint32_t column_number) : file_name_(file_name), file_line_number_(line_number), method_name_(method_name), file_column_number_(column_number) {
}

stack_frame::stack_frame(const string& file_name, uint32_t line_number, uint32_t column_number) : file_name_(file_name), file_line_number_(line_number), file_column_number_(column_number) {
}

stack_frame::stack_frame(const string& file_name, uint32_t line_number, const string& method_name, uint32_t column_number, uint32_t offset) : file_name_(file_name), file_line_number_(line_number), method_name_(method_name), file_column_number_(column_number), offset_(offset) {
}

stack_frame stack_frame::empty() noexcept {
  return {"", 0, "", 0, OFFSET_UNKNOWN};
}

uint32_t stack_frame::get_file_column_number() const {
  return file_column_number_;
}

uint32_t stack_frame::get_file_line_number() const {
  return file_line_number_;
}

const string& stack_frame::get_file_name() const {
  return file_name_;
}

const string& stack_frame::get_method() const {
  return method_name_;
}

uint32_t stack_frame::get_offset() const {
  return offset_;
}

ustring stack_frame::to_string() const noexcept {
  if (*this == empty()) return "";
  return ustring::format("{} at offset {} in file:line:column {}:{}:{}", method_name_.empty() ? "<unknown method>" : method_name_, offset_ == OFFSET_UNKNOWN || file_name_.empty() ? "<unknown offset>" : std::to_string(offset_), file_name_.empty() ? "<filename unknown>" : file_name_, file_line_number_, file_column_number_);
}

//friend ostream& operator<<(ostream& os, const stack_frame& stack_frame) noexcept {
//  return os << stack_frame.to_string();
//}

std::vector<stack_frame> stack_frame::get_stack_frames(const std::string& str, size_t skip_frames, bool need_file_info) {
  stacktrace::call_stack call_stack(4);
  size_t skip_frames_before_str = 0;
  if (!str.empty()) {
    skip_frames_before_str = call_stack.stack.size();
    for (size_t index = 0; index < call_stack.stack.size(); ++index) {
      if (xtd::strings::starts_with(call_stack.stack[index].function, str)) {
        skip_frames_before_str = index;
        break;
      }
    }
  }

  std::vector<stack_frame> stack_frames;
  for (size_t index = skip_frames_before_str + skip_frames; index < call_stack.stack.size() - 1; ++index)
    stack_frames.emplace_back(stack_frame(need_file_info ? call_stack.stack[index].file : "", need_file_info ? static_cast<uint32_t>(call_stack.stack[index].line) : 0, call_stack.stack[index].function, need_file_info ? static_cast<uint32_t>(call_stack.stack[index].column) : 0, static_cast<uint32_t>(call_stack.stack[index].offset)));
  return stack_frames;
}
