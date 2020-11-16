#include "../include/xtd/system_exception.h"
#include "../include/xtd/diagnostics/stack_trace.h"

using namespace xtd;

bool system_exception::enable_stack_trace_ = true;

system_exception::system_exception(const std::string& message, const std::exception* inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& information) : message_(message), error_(error), help_link_(help_link), information_(information) {
  if (inner_exception) inner_exception_ = *inner_exception;
  if (enable_stack_trace_) stack_trace_ = xtd::strings::split(xtd::diagnostics::stack_trace(*this, 4, true).to_string(), {'\n'});
  if (!stack_trace_.size()) stack_trace_.push_back(information_.to_trace());
}

std::string system_exception::to_string() const noexcept {
  if (message().empty() && stack_trace().empty()) return name();
  if (message().empty()) return xtd::strings::format("{}\n{}", name(), stack_trace());
  if (stack_trace().empty()) return xtd::strings::format("{} : {}", name(), message());
  return xtd::strings::format("{} : {}\n{}", name(), message(), stack_trace());
}
