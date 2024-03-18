#include "../../../include/xtd/diagnostics/stack_frame.h"
#include "../../../include/xtd/literals.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__

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

stack_frame::stack_frame(const ustring& file_name, uint32 line_number) : file_name_(file_name), file_line_number_(line_number) {
}

stack_frame::stack_frame(const ustring& file_name, uint32 line_number, const ustring& method_name) : file_name_(file_name), file_line_number_(line_number), method_name_(method_name) {
}

stack_frame::stack_frame(const ustring& file_name, uint32 line_number, const ustring& method_name, uint32 column_number) : file_name_(file_name), file_line_number_(line_number), method_name_(method_name), file_column_number_(column_number) {
}

stack_frame::stack_frame(const ustring& file_name, uint32 line_number, uint32 column_number) : file_name_(file_name), file_line_number_(line_number), file_column_number_(column_number) {
}

stack_frame::stack_frame(const ustring& file_name, uint32 line_number, const ustring& method_name, uint32 column_number, uint32 offset) : file_name_(file_name), file_line_number_(line_number), method_name_(method_name), file_column_number_(column_number), offset_(offset) {
}

stack_frame stack_frame::empty() noexcept {
  return {"", 0, "", 0, OFFSET_UNKNOWN};
}

bool stack_frame::equals(const stack_frame& sf) const noexcept {
  return file_name_ == sf.file_name_ && file_line_number_ == sf.file_line_number_ && method_name_ == sf.method_name_ && file_column_number_ == sf.file_column_number_ && offset_ == sf.offset_;
}

uint32 stack_frame::get_file_column_number() const noexcept {
  return file_column_number_;
}

uint32 stack_frame::get_file_line_number() const noexcept {
  return file_line_number_;
}

const ustring& stack_frame::get_file_name() const noexcept {
  return file_name_;
}

const ustring& stack_frame::get_method() const noexcept {
  return method_name_;
}

uint32 stack_frame::get_offset() const noexcept {
  return offset_;
}

ustring stack_frame::to_string() const noexcept {
  if (*this == empty()) return "";
  return ustring::format("{} at offset {} in file:line:column {}:{}:{}", method_name_.empty() ? "<unknown method>" : method_name_, offset_ == OFFSET_UNKNOWN || file_name_.empty() ? "<unknown offset>" : std::to_string(offset_), file_name_.empty() ? "<filename unknown>" : file_name_, file_line_number_, file_column_number_);
}

std::vector<stack_frame> stack_frame::get_stack_frames(const ustring& str, size_t skip_frames, bool need_file_info) noexcept {
  auto call_stack = native::stack_trace::get_frames(2);
  auto skip_frames_before_str = 0_z;
  if (!str.empty()) {
    skip_frames_before_str = call_stack.size();
    for (auto index = 0_z; index < call_stack.size(); ++index) {
      auto [file, line, column, function, offset] = call_stack[index];
      if (ustring {function}.starts_with(str)) {
        skip_frames_before_str = index;
        break;
      }
    }
  }
  
  auto stack_frames = std::vector<stack_frame> {};
  if (call_stack.size() == 0) return stack_frames;
  for (auto index = skip_frames_before_str + skip_frames; index < call_stack.size(); ++index) {
    auto [file, line, column, function, offset] = call_stack[index];
    auto skip = false;
    for (auto starting_str : {"__startup__::run", "decltype", "std::_", "std::invoke", "void std::_", "long std::_", "xtd::delegate<"})
      if (ustring(function).starts_with(starting_str)) skip = true;
    if (skip) continue;
    stack_frames.emplace_back(stack_frame(need_file_info ? file : "", need_file_info ? static_cast<uint32>(line) : 0, function, need_file_info ? static_cast<uint32>(column) : 0, static_cast<uint32>(offset)));
  }
  return stack_frames;
}
