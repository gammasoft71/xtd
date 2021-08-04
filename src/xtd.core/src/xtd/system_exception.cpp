#include "../../include/xtd/console.h"
#include "../../include/xtd/strings.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/system_exception.h"
#include "../../include/xtd/diagnostics/stack_trace.h"

using namespace xtd;

bool system_exception::enable_stack_trace_ = true;

system_exception::system_exception(const std::string& message, const std::exception* inner_exception, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& information) : message_(message), error_(error), help_link_(help_link), information_(information) {
  if (inner_exception) inner_exception_ = *inner_exception;
  if (enable_stack_trace_) stack_trace_ = std::make_shared<xtd::diagnostics::stack_trace>(0, true);
  //if (!stack_trace_.size()) stack_trace_.push_back(information_.to_string());
}

ustring system_exception::to_string() const noexcept {
  if (message().empty() && stack_trace().empty()) return name();
  if (message().empty()) return xtd::ustring::format("{}\n{}", name(), stack_trace());
  if (stack_trace().empty()) return xtd::ustring::format("{} : {}", name(), message());
  return xtd::ustring::format("{} : {}\n{}", name(), message(), stack_trace());
}

std::string system_exception::stack_trace_to_string() const noexcept {
  if (!stack_trace_) return information_.to_string();

  size_t skip_frames = stack_trace_->frame_count();
  for (size_t index = 0; index < stack_trace_->frame_count(); ++index)
    if (xtd::strings::starts_with(stack_trace_->get_frame(index).get_method(), name()))
      skip_frames = index;
  return stack_trace_->to_string(skip_frames + 1, information_);
}

const char* system_exception::default_message() const {
  return "System error."_t;
}
