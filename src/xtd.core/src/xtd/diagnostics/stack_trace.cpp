#include "../../../include/xtd/environment"
#include "../../../include/xtd/typeof"
#include "../../../include/xtd/diagnostics/stack_trace"

using namespace xtd;
using namespace xtd::diagnostics;

stack_trace::stack_trace() {
  frames_ = stack_frame::get_stack_frames("", METHODS_TO_SKIP + 1, false);
}

stack_trace::stack_trace(bool need_file_info) {
  frames_ = stack_frame::get_stack_frames("", METHODS_TO_SKIP + 1, need_file_info);
}

stack_trace::stack_trace(const stack_frame& frame) {
  frames_.push_back(frame);
}

stack_trace::stack_trace(const ustring& str, size_t skip_frames, bool need_file_info) {
  frames_ = stack_frame::get_stack_frames(str, skip_frames + METHODS_TO_SKIP + 1, need_file_info);
}

stack_trace::stack_trace(size_t skip_frames) {
  frames_ = stack_frame::get_stack_frames("", skip_frames + METHODS_TO_SKIP + 1, false);
}

stack_trace::stack_trace(size_t skip_frames, bool need_file_info) {
  frames_ = stack_frame::get_stack_frames("", skip_frames + METHODS_TO_SKIP + 1, need_file_info);
}

stack_trace::stack_trace(const std::exception& exception) {
  frames_ = stack_frame::get_stack_frames(typeof_(exception).full_name(), METHODS_TO_SKIP + 1, false);
}

stack_trace::stack_trace(const std::exception& exception, bool need_file_info) {
  frames_ = stack_frame::get_stack_frames(typeof_(exception).full_name(), METHODS_TO_SKIP + 1, need_file_info);
}

stack_trace::stack_trace(const std::exception& exception, size_t skip_frames) {
  frames_ = stack_frame::get_stack_frames(typeof_(exception).full_name(), skip_frames + METHODS_TO_SKIP + 1, false);
}

stack_trace::stack_trace(const std::exception& exception, size_t skip_frames, bool need_file_info) {
  frames_ = stack_frame::get_stack_frames(typeof_(exception).full_name(), skip_frames + METHODS_TO_SKIP + 1, need_file_info);
}

size_t stack_trace::frame_count() const noexcept {
  return frames_.size();
}

const xtd::diagnostics::stack_frame& stack_trace::get_frame(size_t index) noexcept {
  static auto empty_stack_frame = xtd::diagnostics::stack_frame::empty();
  if (frames_.size() == 0) return empty_stack_frame;
  if (index > frames_.size() - 1) index = frames_.size() - 1;
  return frames_[index];
}

const stack_trace::stack_frame_collection& stack_trace::get_frames() const noexcept {
  return frames_;
}

ustring stack_trace::to_string() const noexcept {
  return to_string(0);
}

ustring stack_trace::to_string(size_t skip_frames, const stack_frame& stack_frame) const noexcept {
  auto str = ustring::empty_string;
  for (auto index = skip_frames; index < frames_.size(); ++index) {
    if (index > skip_frames) str += xtd::environment::new_line();
    str += "   at " + frames_[index].get_method();
    if (index == skip_frames && stack_frame != stack_frame::empty()) str += ustring::format(" {}in {}:line {}", frames_[index].get_offset() != stack_frame::OFFSET_UNKNOWN ? ustring::format("[0x{:X8}] ", frames_[index].get_offset()) : "", stack_frame.get_file_name(), stack_frame.get_file_line_number());
    else if (!frames_[index].get_file_name().empty()) str += ustring::format(" {}in {}:line {}", frames_[index].get_offset() != stack_frame::OFFSET_UNKNOWN ? ustring::format("[0x{:X8}] ", frames_[index].get_offset()) : "", frames_[index].get_file_name(), frames_[index].get_file_line_number());
  }
  return str;
}
