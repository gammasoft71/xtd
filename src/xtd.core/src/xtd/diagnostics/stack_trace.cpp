#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/diagnostics/stack_trace.h"
#include <call_stack.h>

using namespace xtd;
using namespace xtd::diagnostics;

stack_trace::stack_trace(const std::string& str, size_t skip_frames, bool need_file_info) {
  data_->handle_ = reinterpret_cast<intptr_t>(new stacktrace::call_stack(3));
  get_frames(str, skip_frames, need_file_info);
}

stack_trace::~stack_trace() {
  if (data_.use_count() == 1) delete reinterpret_cast<stacktrace::call_stack*>(data_->handle_);
}

std::string stack_trace::to_string(size_t skip_frames, const caller_info& info) const {
  std::string str;
  for (size_t index = skip_frames; index < data_->frames_.size(); ++index) {
    if (index > skip_frames) str += xtd::environment::new_line();
    str += "   at " + data_->frames_[index].get_method();
    if (index == skip_frames && info != caller_info::empty()) str += xtd::strings::format(" [0x{:X8}] in {}:line {}", data_->frames_[index].get_offset(), info.file_path(), info.line_number());
    else if (!data_->frames_[index].get_file_name().empty()) str += xtd::strings::format(" [0x{:X8}] in {}:line {}", data_->frames_[index].get_offset(), data_->frames_[index].get_file_name(), data_->frames_[index].get_file_line_number());
  }
  return str;
}

void stack_trace::get_frames(const std::string& str, size_t skip_frames, bool need_file_info) {
  size_t skip_frames_before_str = 0;
  if (!str.empty()) {
    skip_frames_before_str = reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack.size();
    for (size_t index = 0; index < reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack.size(); ++index) {
      if (xtd::strings::starts_with(reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack[index].function, str)) {
        skip_frames_before_str = index;
        break;
      }
    }
  }

  if (reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack.size() > 0) {
    for (size_t index = 0; index < reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack.size() - 1; ++index) {
      if (index > skip_frames_before_str + skip_frames) {
        if (need_file_info) data_->frames_.push_back({reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack[index].file, reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack[index].line, reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack[index].column, reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack[index].function, reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack[index].offset});
        else data_->frames_.push_back({reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack[index].function, reinterpret_cast<stacktrace::call_stack*>(data_->handle_)->stack[index].offset});
      }
    }
  }
}

