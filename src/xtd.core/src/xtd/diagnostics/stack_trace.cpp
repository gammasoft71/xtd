#include "stack_frame_get_stack_frames.hpp"
#include "../../../include/xtd/array.hpp"
#include "../../../include/xtd/environment.hpp"
#include "../../../include/xtd/typeof.hpp"
#include "../../../include/xtd/diagnostics/stack_trace.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

struct stack_trace::data {
  stack_frame_collection frames;
  bool need_file_info = false;
};

stack_trace::stack_trace(const stack_frame& current_frame) : data_{new_ptr<data>()} {
  data_->frames = stack_frame::get_stack_frames(string::empty_string, METHODS_TO_SKIP + 1, false).to_array();
  if (!data_->frames.length()) data_->frames = {current_frame};
}

stack_trace::stack_trace(bool need_file_info, const stack_frame& current_frame) : data_{new_ptr<data>()} {
  data_->frames = stack_frame::get_stack_frames(string::empty_string, METHODS_TO_SKIP + 1, need_file_info).to_array();
  data_->need_file_info = need_file_info;
  if (!data_->frames.length()) data_->frames = {current_frame};
}

stack_trace::stack_trace(const string& str, size_t skip_frames, bool need_file_info) : data_{new_ptr<data>()} {
  data_->frames = stack_frame::get_stack_frames(str, skip_frames + METHODS_TO_SKIP + 1, need_file_info).to_array();
  data_->need_file_info = need_file_info;
}

stack_trace::stack_trace(size_t skip_frames) : data_{new_ptr<data>()} {
  data_->frames = stack_frame::get_stack_frames(string::empty_string, skip_frames + METHODS_TO_SKIP + 1, false).to_array();
}

stack_trace::stack_trace(size_t skip_frames, bool need_file_info) : data_{new_ptr<data>()} {
  data_->frames = stack_frame::get_stack_frames(string::empty_string, skip_frames + METHODS_TO_SKIP + 1, need_file_info).to_array();
  data_->need_file_info = need_file_info;
}

stack_trace::stack_trace(const std::exception& exception) : data_{new_ptr<data>()} {
  data_->frames = stack_frame::get_stack_frames(typeof_(exception).full_name(), METHODS_TO_SKIP + 1, false).to_array();
}

stack_trace::stack_trace(const std::exception& exception, bool need_file_info) : data_{new_ptr<data>()} {
  data_->frames = stack_frame::get_stack_frames(typeof_(exception).full_name(), METHODS_TO_SKIP + 1, need_file_info).to_array();
  data_->need_file_info = need_file_info;
}

stack_trace::stack_trace(const std::exception& exception, size_t skip_frames) : data_{new_ptr<data>()} {
  data_->frames = stack_frame::get_stack_frames(typeof_(exception).full_name(), skip_frames + METHODS_TO_SKIP + 1, false).to_array();
}

stack_trace::stack_trace(const std::exception& exception, size_t skip_frames, bool need_file_info) {
  data_->frames = stack_frame::get_stack_frames(typeof_(exception).full_name(), skip_frames + METHODS_TO_SKIP + 1, need_file_info).to_array();
  data_->need_file_info = need_file_info;
}

size_t stack_trace::frame_count() const noexcept {
  return data_->frames.length();
}

const xtd::diagnostics::stack_frame& stack_trace::get_frame(size_t index) noexcept {
  static auto empty_stack_frame = stack_frame {null};
  if (data_->frames.length() == 0) return empty_stack_frame;
  if (index > data_->frames.length() - 1) index = data_->frames.length() - 1;
  return data_->frames[index];
}

const stack_trace::stack_frame_collection& stack_trace::get_frames() const noexcept {
  return data_->frames;
}

string stack_trace::to_string() const noexcept {
  return to_string(0);
}

stack_trace stack_trace::from_stack_frame(const stack_frame& frame) {
  return stack_trace {frame, true};
}

stack_trace::stack_trace(const xtd::diagnostics::stack_frame& frame, bool empty) : data_{new_ptr<data>()} {
  data_->frames = stack_frame_collection {frame};
}

string stack_trace::to_string(size_t skip_frames) const noexcept {
  auto str = string::empty_string;
  for (auto index = skip_frames; index < data_->frames.length(); ++index) {
    if (index > skip_frames) str += xtd::environment::new_line();
    str += "   at " + data_->frames[index].get_method();
    if (data_->need_file_info && !xtd::string::is_empty(data_->frames[index].get_file_name())) str += string::format(" in {}:line {}", data_->frames[index].get_file_name(), data_->frames[index].get_file_line_number());
  }
  str += environment::new_line();
  return str;
}
