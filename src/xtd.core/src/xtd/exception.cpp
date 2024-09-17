#include "../../include/xtd/call_once.h"
#include "../../include/xtd/console.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/exception.h"
#include "../../include/xtd/diagnostics/stack_trace.h"

using namespace xtd;

bool exception::enable_stack_trace_ = true;

struct exception::data {
  data(const string& message, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& information) : message {message}, error {error}, help_link {help_link}, information {information} {}
  mutable xtd::string name;
  xtd::string message;
  exception_ref inner_exception;
  std::error_code error;
  xtd::string help_link;
  xtd::diagnostics::stack_frame information;
  xtd::sptr<xtd::diagnostics::stack_trace> stack_trace;
};

exception::exception(const xtd::diagnostics::stack_frame& information) : exception(default_message(), nullptr, std::error_code(), xtd::string::empty_string, information) {
}

exception::exception(const xtd::string& message, const xtd::diagnostics::stack_frame& information) : exception(message, nullptr, std::error_code(), xtd::string::empty_string, information) {
}

exception::exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& information) : exception(message, nullptr, error, xtd::string::empty_string, information) {
}

exception::exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& information) : exception(message, nullptr, std::error_code(), help_link, information) {
}

exception::exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& information) : exception(message, nullptr, error, help_link, information) {
}

exception::exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& information) : exception(default_message(), &inner_exception, std::error_code(), xtd::string::empty_string, information) {
}

exception::exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& information) : exception(message, &inner_exception, std::error_code(), xtd::string::empty_string, information) {
}

exception::exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& information) : exception(message, &inner_exception, error, xtd::string::empty_string, information) {
}

exception::exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& information) : exception(message, &inner_exception, std::error_code(), help_link, information) {
}

exception::exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& information) : exception(message, &inner_exception, error, help_link, information) {
}

exception::exception(const string& message, const std::exception* inner_exception, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& information) : data_ {new_ptr<data>(message, error, help_link, information)} {
  if (inner_exception) data_->inner_exception = *inner_exception;
  if (enable_stack_trace_) data_->stack_trace = xtd::new_sptr<xtd::diagnostics::stack_trace>(0, true);
  //if (!data_->stack_trace.size()) data_->stack_trace.push_back(data_->information.to_string());
}

const xtd::string& exception::file_path() const noexcept {
  return data_->information.get_file_name();
}

const xtd::string& exception::help_link() const noexcept {
  return data_->help_link;
}

bool exception::enable_stack_trace() noexcept {
  return enable_stack_trace_;
}

void exception::enable_stack_trace(bool enable) noexcept {
  enable_stack_trace_ = enable;
}

std::error_code exception::error_code() const noexcept {
  return data_->error;
}

exception::exception_ref exception::inner_exception() const noexcept {
  return data_->inner_exception;
}

xtd::size exception::line_number() const noexcept {
  return data_->information.get_file_line_number();
}

const xtd::string& exception::member_name() const noexcept {
  return data_->information.get_method();
}

const xtd::string& exception::message() const noexcept {
  return data_->message;
}

const xtd::string& exception::name() const noexcept {
  call_once_ {
    environment::__signal_catcher_check__();
  };
  return (data_->name = get_type().full_name());
}

xtd::string exception::stack_trace() const noexcept {
  return stack_trace_to_string();
}

string exception::to_string() const noexcept {
  if (message().empty() && stack_trace().empty()) return name();
  if (message().empty()) return xtd::string::format("{}\n{}", name(), stack_trace());
  if (stack_trace().empty()) return xtd::string::format("{} : {}", name(), message());
  return xtd::string::format("{} : {}\n{}", name(), message(), stack_trace());
}

const char* exception::what() const noexcept {
  return message().empty() ? name().c_str() : message().c_str();
}

string exception::stack_trace_to_string() const noexcept {
  if (!data_->stack_trace) return data_->information.to_string();
  
  auto skip_frames = data_->stack_trace->frame_count();
  for (auto index = 0_z; index < data_->stack_trace->frame_count(); ++index)
    if (data_->stack_trace->get_frame(index).get_method().starts_with(name()))
      skip_frames = index;
  return data_->stack_trace->to_string(skip_frames + 1, data_->information);
}

const char* exception::default_message() const noexcept {
  return "System error."_t;
}
