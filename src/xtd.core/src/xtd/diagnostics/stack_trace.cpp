#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/diagnostics/stack_trace.h"
#include <call_stack.h>

using namespace xtd;
using namespace xtd::diagnostics;

stack_trace::stack_trace(const stack_frame& frame) {
  frames_.push_back(frame);
}

stack_trace::stack_trace(const std::string& str, size_t skip_frames, bool need_file_info) {
  frames_ = stack_frame::get_stack_frames(str, skip_frames + METHODS_TO_SKIP + 1, need_file_info);
}

std::string stack_trace::to_string(size_t skip_frames, const caller_info& info) const {
  std::string str;
  for (size_t index = skip_frames; index < frames_.size(); ++index) {
    if (index > skip_frames) str += xtd::environment::new_line();
    str += "   at " + frames_[index].get_method();
    if (index == skip_frames && info != caller_info::empty()) str += xtd::strings::format(" [0x{:X8}] in {}:line {}", frames_[index].get_offset(), info.file_path(), info.line_number());
    else if (!frames_[index].get_file_name().empty()) str += xtd::strings::format(" [0x{:X8}] in {}:line {}", frames_[index].get_offset(), frames_[index].get_file_name(), frames_[index].get_file_line_number());
  }
  return str;
}
