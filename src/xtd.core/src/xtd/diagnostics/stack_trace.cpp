#include "../include/xtd/diagnostics/stack_trace.h"
#include <call_stack.h>

using namespace xtd;
using namespace xtd::diagnostics;

stack_trace::stack_trace(const std::string& str, size_t skip_frames, bool need_file_info) : handle_(reinterpret_cast<intptr_t>(new stacktrace::call_stack(2))) {
  get_frames(str, skip_frames, need_file_info);

}

stack_trace::~stack_trace() {
  delete reinterpret_cast<stacktrace::call_stack*>(handle_);
}

void stack_trace::get_frames(const std::string& str, size_t skip_frames, bool need_file_info) {
  auto skip_frames_before_str = 0U;
  if (!str.empty()) {
    for (auto index = 0U; index < reinterpret_cast<stacktrace::call_stack*>(handle_)->stack.size(); ++index)
      if (xtd::strings::starts_with(reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].function, str))
        skip_frames_before_str = index;
  }

  for (auto index = 0U; index < reinterpret_cast<stacktrace::call_stack*>(handle_)->stack.size(); ++index)
    if (index >= skip_frames_before_str + skip_frames) {
      if (need_file_info) frames_.push_back({reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].file, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].line, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].column, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].function, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].offset});
      else frames_.push_back({reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].function, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].offset});
   }
}
