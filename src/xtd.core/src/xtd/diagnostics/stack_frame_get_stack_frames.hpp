#include "../../../include/xtd/diagnostics/stack_frame.hpp"
#include "../../../include/xtd/collections/generic/list.hpp"
#include "../../../include/xtd/string.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__

inline auto xtd::diagnostics::stack_frame::get_stack_frames(const xtd::string& str, xtd::size skip_frames, bool need_file_info) noexcept {
  auto call_stack = xtd::native::stack_trace::get_frames(skip_frames, need_file_info);
  auto skip_frames_before_str = xtd::size {0};
  if (!xtd::string::is_empty(str)) {
    skip_frames_before_str = call_stack.size();
    for (auto index = xtd::size {0}; index < call_stack.size(); ++index) {
      auto [file, line, column, method, offset] = call_stack[index];
      if (string {method}.starts_with(str)) {
        skip_frames_before_str = index;
        break;
      }
    }
  }
  
  auto frames_to_skip = {
    "decltype",
    "int xtd::startup::internal_safe_run",
    "int xtd::startup::safe_run",
    "long std::_",
    "std::_",
    "std::invoke",
    "void std::_",
    "xtd::delegate<",
    "xtd::startup::internal_safe_run",
    "xtd::startup::run",
    "xtd::startup::safe_run",
  };
  
  auto stack_frames = xtd::collections::generic::list<stack_frame> {};
  if (call_stack.size() == 0) return stack_frames;
  for (auto index = skip_frames_before_str; index < call_stack.size(); ++index) {
    auto [file, line, column, method, offset] = call_stack[index];
    auto skip = false;
    for (auto starting_str : frames_to_skip)
      if (string {method}.starts_with(starting_str)) skip = true;
    if (skip) continue;
    stack_frames.add(stack_frame(need_file_info ? file : "", need_file_info ? line : 0, method, need_file_info ? column : 0, offset));
  }
  return stack_frames;
}
