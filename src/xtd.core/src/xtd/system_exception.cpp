#include "../../include/xtd/call_once.h"
#include "../../include/xtd/console.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/system_exception.h"
#include "../../include/xtd/diagnostics/stack_trace.h"

using namespace xtd;

bool system_exception::enable_stack_trace_ = true;

const xtd::string& system_exception::file_path() const noexcept {
  return information_.get_file_name();
}

const xtd::string& system_exception::help_link() const noexcept {
  return help_link_;
}

bool system_exception::enable_stack_trace() noexcept {
  return enable_stack_trace_;
}

void system_exception::enable_stack_trace(bool enable) noexcept {
  enable_stack_trace_ = enable;
}

std::error_code system_exception::error_code() const noexcept {
  return error_;
}

system_exception::exception_ref system_exception::inner_exception() const noexcept {
  return inner_exception_;
}

xtd::size system_exception::line_number() const noexcept {
  return information_.get_file_line_number();
}

const xtd::string& system_exception::member_name() const noexcept {
  return information_.get_method();
}

const xtd::string& system_exception::message() const noexcept {
  return message_;
}

const xtd::string& system_exception::name() const noexcept {
  call_once_ {
    environment::__signal_catcher_check__();
  };
  return (name_ = get_type().full_name());
}

xtd::string system_exception::stack_trace() const noexcept {
  return stack_trace_to_string();
}

string system_exception::to_string() const noexcept {
  if (message().empty() && stack_trace().empty()) return name();
  if (message().empty()) return xtd::string::format("{}\n{}", name(), stack_trace());
  if (stack_trace().empty()) return xtd::string::format("{} : {}", name(), message());
  return xtd::string::format("{} : {}\n{}", name(), message(), stack_trace());
}

const char* system_exception::what() const noexcept {
  return message().empty() ? name().c_str() : message().c_str();
}

string system_exception::stack_trace_to_string() const noexcept {
  if (!stack_trace_) return information_.to_string();
  
  auto skip_frames = stack_trace_->frame_count();
  for (auto index = 0_z; index < stack_trace_->frame_count(); ++index)
    if (stack_trace_->get_frame(index).get_method().starts_with(name()))
      skip_frames = index;
  return stack_trace_->to_string(skip_frames + 1, information_);
}

system_exception::system_exception(const string& message, const std::exception* inner_exception, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& information) : message_(message), error_(error), help_link_(help_link), information_(information) {
  if (inner_exception) inner_exception_ = *inner_exception;
  if (enable_stack_trace_) stack_trace_ = xtd::new_sptr<xtd::diagnostics::stack_trace>(0, true);
  //if (!stack_trace_.size()) stack_trace_.push_back(information_.to_string());
}

const char* system_exception::default_message() const noexcept {
  return "System error."_t;
}
