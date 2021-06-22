#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/diagnostics/stack_trace.h"
#include <call_stack.h>

using namespace xtd;
using namespace xtd::diagnostics;

stack_trace::stack_trace() : stack_trace("", METHODS_TO_SKIP, false) {
}

stack_trace::stack_trace(bool need_file_info) : stack_trace("", METHODS_TO_SKIP, need_file_info) {
}

stack_trace::stack_trace(const stack_frame& frame) {
  frames_.push_back(frame);
}

stack_trace::stack_trace(const std::string& str, size_t skip_frames, bool need_file_info) {
  frames_ = stack_frame::get_stack_frames(str, skip_frames + METHODS_TO_SKIP + 1, need_file_info);
}

stack_trace::stack_trace(size_t skip_frames) : stack_trace("", skip_frames, false) {
}

stack_trace::stack_trace(size_t skip_frames, bool need_file_info) : stack_trace("", skip_frames, need_file_info) {
}

stack_trace::stack_trace(const std::exception& exception) : stack_trace(xtd::strings::full_class_name(exception), METHODS_TO_SKIP, false) {
}

stack_trace::stack_trace(const std::exception& exception, bool need_file_info) : stack_trace(xtd::strings::full_class_name(exception), METHODS_TO_SKIP, need_file_info) {
}

stack_trace::stack_trace(const std::exception& exception, size_t skip_frames) : stack_trace(xtd::strings::full_class_name(exception), skip_frames, false) {
}

stack_trace::stack_trace(const std::exception& exception, size_t skip_frames, bool need_file_info) : stack_trace(xtd::strings::full_class_name(exception), skip_frames, need_file_info) {
}

size_t stack_trace::frame_count() const {
  return frames_.size();
}

const xtd::diagnostics::stack_frame& stack_trace::get_frame(size_t index) {
  return frames_[index];
}

const stack_trace::stack_frame_collection& stack_trace::get_frames() const {
  return frames_;
}

std::string stack_trace::to_string() const {
  return to_string(0);
}

std::string stack_trace::to_string(size_t skip_frames, const stack_frame& stack_frame) const {
  std::string str;
  for (size_t index = skip_frames; index < frames_.size(); ++index) {
    if (index > skip_frames) str += xtd::environment::new_line();
    str += "   at " + frames_[index].get_method();
    if (index == skip_frames && stack_frame != stack_frame::empty()) str += xtd::strings::format(" {}in {}:line {}", frames_[index].get_offset() != stack_frame::OFFSET_UNKNOWN ? strings::format("[0x{:X8}] ", frames_[index].get_offset()) : "", stack_frame.get_file_name(), stack_frame.get_file_line_number());
    else if (!frames_[index].get_file_name().empty()) str += xtd::strings::format(" {}in {}:line {}", frames_[index].get_offset() != stack_frame::OFFSET_UNKNOWN ? strings::format("[0x{:X8}] ", frames_[index].get_offset()) : "", frames_[index].get_file_name(), frames_[index].get_file_line_number());
  }
  return str;
}
