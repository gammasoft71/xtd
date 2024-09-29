#include "../../include/xtd/call_once.h"
#include "../../include/xtd/console.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/exception.h"
#include "../../include/xtd/h_result.h"
#include "../../include/xtd/h_result_category.h"
#include "../../include/xtd/diagnostics/stack_trace.h"
#include "../../include/xtd/io/path.h"
#include "../../include/xtd/reflection/assembly.h"

using namespace xtd;

bool exception::enable_stack_trace_ = true;

struct exception::data {
  data(const std::optional<string>& message, uptr<exception>&& inner_exception, const diagnostics::stack_frame& stack_frame) : message {message}, inner_exception {std::move(inner_exception)}, stack_frame {stack_frame} {}
  data(const std::optional<string>& message, const string& help_link, const diagnostics::stack_frame& stack_frame) : message {message}, help_link {help_link}, stack_frame {stack_frame} {}
  data(const std::optional<string>& message, const std::error_code& error, const string& help_link, const diagnostics::stack_frame& stack_frame) : message {message}, error {error}, help_link {help_link}, stack_frame {stack_frame} {}
  mutable xtd::string name;
  std::optional<string> message;
  uptr<exception> inner_exception;
  exception_ref inner_exception_deprecated;
  std::error_code error = h_result::make_error_code(h_result::COR_E_EXCEPTION);
  string help_link;
  string source = io::path::get_file_name(reflection::assembly::get_executing_assembly().location());
  diagnostics::stack_frame stack_frame;
  sptr<xtd::diagnostics::stack_trace> stack_trace;
};

exception::exception(const xtd::diagnostics::stack_frame& stack_frame) : exception(std::nullopt, nullptr, stack_frame, true) {
}

exception::exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : exception(message, nullptr, stack_frame, true) {
}

exception::exception(const std::optional<xtd::string>& message, uptr<xtd::exception>&& inner_exception, const xtd::diagnostics::stack_frame& stack_frame, bool) : data_ {new_ptr<data>(message, std::move(inner_exception), stack_frame)} {
  if (enable_stack_trace_) data_->stack_trace = xtd::new_sptr<xtd::diagnostics::stack_trace>(0, true);
}

const xtd::string& exception::file_path() const noexcept {
  return get_last_stack_frame().get_file_name();
}

const xtd::string& exception::help_link() const noexcept {
  return data_->help_link;
}

void exception::help_link(const xtd::string& value) noexcept {
  if (data_->help_link == value) return;
  data_->help_link = value;
}

int32 exception::h_result() const noexcept {
  if (data_->error.category() != h_result::h_result_category()) return h_result::COR_E_EXCEPTION;
  return data_->error.value();
}

void exception::h_result(int32 value) noexcept {
  if (data_->error.value() == value && data_->error.category() == h_result::h_result_category()) return;
  data_->error = make_error_code(value);
}

bool exception::enable_stack_trace() noexcept {
  return enable_stack_trace_;
}

void exception::enable_stack_trace(bool enable) noexcept {
  enable_stack_trace_ = enable;
}

const std::error_code& exception::error_code() const noexcept {
  return data_->error;
}

void exception::error_code(const std::error_code& value) noexcept {
  if (data_->error == value) return;
  data_->error = value;
}

exception::exception_ref exception::inner_exception() const noexcept {
  return data_->inner_exception_deprecated;
}

xtd::size exception::line_number() const noexcept {
  return get_last_stack_frame().get_file_line_number();
}

const xtd::string& exception::member_name() const noexcept {
  return get_last_stack_frame().get_method();
}

const xtd::string& exception::message() const noexcept {
  static thread_local auto message = string::empty_string;
  message = data_->message.value_or(string {data_->error.message()});
  return message;
}

const xtd::string& exception::name() const noexcept {
  return get_name();
}

const xtd::string& exception::source() const noexcept {
  return data_->source;
}

void exception::source(const xtd::string& value) noexcept {
  if (data_->source == value) return;
  data_->source = value;
}

xtd::string exception::stack_trace() const noexcept {
  return stack_trace_to_string();
}

const xtd::diagnostics::stack_frame& exception::get_last_stack_frame() const noexcept {
  return data_->stack_frame;
}

string exception::to_string() const noexcept {
  if (message().empty() && stack_trace().empty()) return get_name();
  if (message().empty()) return xtd::string::format("{}\n{}", get_name(), stack_trace());
  if (stack_trace().empty()) return xtd::string::format("{} : {}", get_name(), message());
  return xtd::string::format("{} : {}\n{}", get_name(), message(), stack_trace());
}

const char* exception::what() const noexcept {
  return message().empty() ? get_name().c_str() : message().c_str();
}

string exception::stack_trace_to_string() const noexcept {
  if (!data_->stack_trace) return data_->stack_frame.to_string();
  
  auto skip_frames = data_->stack_trace->frame_count();
  for (auto index = 0_z; index < data_->stack_trace->frame_count(); ++index)
    if (data_->stack_trace->get_frame(index).get_method().starts_with(get_name()))
      skip_frames = index;
  return data_->stack_trace->to_string(skip_frames + 1, data_->stack_frame);
}

const xtd::string& exception::get_name() const noexcept {
  call_once_ {
    environment::__signal_catcher_check__();
  };
  return (data_->name = get_type().full_name());
}
