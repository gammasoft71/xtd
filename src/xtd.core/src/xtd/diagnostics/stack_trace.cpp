#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/diagnostics/stack_trace.h"
#include <call_stack.h>

using namespace xtd;
using namespace xtd::diagnostics;

stack_trace::stack_trace(const std::string& str, size_t skip_frames, bool need_file_info) : handle_(reinterpret_cast<intptr_t>(new stacktrace::call_stack(3))) {
  get_frames(str, skip_frames, need_file_info);

}

stack_trace::~stack_trace() {
  delete reinterpret_cast<stacktrace::call_stack*>(handle_);
}

std::string stack_trace::to_string() const {
  std::string str;
  bool first = true;
  for (auto frame : frames_) {
    if (!first) str += xtd::environment::new_line();
    str += "   at " + frame.method_name();
    if (!frame.file_path().empty()) str += xtd::strings::format(" [0x{:X8}] in {}:line {}", frame.offset(), frame.file_path(), frame.file_line());
    first = false;
  }
  return str;
}

void stack_trace::get_frames(const std::string& str, size_t skip_frames, bool need_file_info) {
  size_t skip_frames_before_str = 0;
  if (!str.empty()) {
    skip_frames_before_str = reinterpret_cast<stacktrace::call_stack*>(handle_)->stack.size();
    for (size_t index = 0; index < reinterpret_cast<stacktrace::call_stack*>(handle_)->stack.size(); ++index) {
      if (xtd::strings::starts_with(reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].function, str)) {
        skip_frames_before_str = index;
        break;
      }
    }
  }

  if (reinterpret_cast<stacktrace::call_stack*>(handle_)->stack.size() > 0) {
    for (size_t index = 0; index < reinterpret_cast<stacktrace::call_stack*>(handle_)->stack.size() - 1; ++index) {
      if (index > skip_frames_before_str + skip_frames) {
        if (need_file_info) frames_.push_back({reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].file, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].line, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].column, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].function, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].offset});
        else frames_.push_back({reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].function, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].offset});
      }
    }
  }
}

