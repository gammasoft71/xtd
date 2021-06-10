#include "../../../include/xtd/diagnostics/process.h"
#include "../../../include/xtd/diagnostics/debug.h"
#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include <xtd/native/process_creation_flags.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::diagnostics;

namespace {
  const bool debug_process = false;
}

//xtd::delegate<void(const std::string&)> process::message_box_message_;

process::process() {
  exited.set_data(data_.get());
}

process& process::operator=(const process& value) {
  if (data_.use_count() == 1 && data_->thread_.joinable()) data_->thread_.detach();
  auto exit_callback = data_->exit_callback_;
  data_ = value.data_;
  exited.set_data(data_.get());
  data_->exit_callback_ += exit_callback;
  data_->exception_pointer_ = nullptr;
  return *this;
}

process::~process() {
  if (data_.use_count() == 1 && data_->thread_.joinable()) data_->thread_.detach();
}

int32_t process::exit_code() const {
  if (!has_exited()) throw xtd::invalid_operation_exception(caller_info_);
  return data_->exit_code_.value();
}

std::chrono::system_clock::time_point process::exit_time() const {
  return data_->exit_time_;
}

intptr_t process::handle() const {return data_->handle_;}

bool process::has_exited() const {
  if (data_->handle_ == 0 && !data_->exit_code_.has_value()) throw xtd::invalid_operation_exception(caller_info_);
  return data_->exit_code_.has_value();
}

std::string process::machine_name() const {
  if (data_->handle_ == 0) throw xtd::invalid_operation_exception(caller_info_);
  return ".";
}

std::istream& process::standard_error() {
  if (data_->standard_error_ == nullptr || !data_->start_info_.redirect_standard_error() || data_->start_info_.use_shell_execute())
    throw invalid_operation_exception(caller_info_);
  return *data_->standard_error_;
}

std::ostream& process::standard_input() {
  if (data_->standard_input_ == nullptr || !data_->start_info_.redirect_standard_input() || data_->start_info_.use_shell_execute())
    throw invalid_operation_exception(caller_info_);
  return *data_->standard_input_;
}

std::istream& process::standard_output() {
  if (data_->standard_output_ == nullptr || !data_->start_info_.redirect_standard_output() || data_->start_info_.use_shell_execute())
    throw invalid_operation_exception(caller_info_);
  return *data_->standard_output_;
}

const process_start_info& process::start_info() const {return data_->start_info_;}
process_start_info& process::start_info() {return data_->start_info_;}
process& process::start_info(const process_start_info& value) {
  data_->start_info_ = value;
  return *this;
}

std::chrono::system_clock::time_point process::start_time() const {
  return data_->start_time_;
}

process&  process::kill() {
  if (data_->handle_ == 0) throw xtd::invalid_operation_exception(caller_info_);
  native::process::kill(data_->handle_);
  debug::write_line_if(debug_process, strings::format("process::kill [handle={}, killed]", data_->handle_));
  return *this;
}

bool process::start() {
  if (data_->thread_.joinable()) return false;
  bool allow_to_continue = false;
  data_->thread_ = thread([](class process process, bool& allow_to_continue) {
    try {
      process.data_->exit_code_.reset();
      process.data_->start_time_ = system_clock::now();
      int32_t process_creation_flags = 0;
      if (process.start_info().create_no_window()) process_creation_flags |= CREATE_NO_WINDOW;
      int32_t process_window_style = 0;
      
      if (process.start_info().use_shell_execute()) {
        process.data_->handle_ = native::process::shell_execute(process.start_info().file_name(), process.start_info().arguments(), process.start_info().working_directory(), process_window_style);
      } else {
        auto [handle, standard_input, standard_output, standard_error] = native::process::create(process.start_info().file_name(), process.start_info().arguments(), process.start_info().working_directory(), process_creation_flags, process_window_style, make_tuple(process.data_->start_info_.redirect_standard_input(), process.data_->start_info_.redirect_standard_output(), process.data_->start_info_.redirect_standard_error()));
        process.data_->handle_ = handle;
        process.data_->standard_input_ = move(standard_input);
        process.data_->standard_output_ = move(standard_output);
        process.data_->standard_error_ = move(standard_error);
      }
      if (process.data_->handle_ == 0) throw invalid_operation_exception("The system cannot find the file specified", caller_info_);
      allow_to_continue = true;
      debug::write_line_if(debug_process, strings::format("process::start [handle={}, command_line={}, start_time={:u}.{:D6}, started]", process.data_->handle_, strings::format("{}{}", process.start_info().file_name(), process.start_info().arguments() == "" ? "" : strings::format(" {}", process.start_info().arguments())), process.data_->start_time_, (std::chrono::duration_cast<std::chrono::microseconds>(process.data_->start_time_.time_since_epoch())).count() % 1000000));
      int32_t exit_code = 0;
      if (!process.data_->start_info_.use_shell_execute() && native::process::wait(process.data_->handle_, exit_code)) process.data_->exit_code_ = exit_code;
      process.data_->exit_time_ = system_clock::now();
      debug::write_line_if(debug_process, strings::format("process::start [handle={}, exit_time={:u}.{:D6}, exit_code={}, exited]", process.data_->handle_, process.data_->exit_time_, (std::chrono::duration_cast<std::chrono::microseconds>(process.data_->exit_time_.time_since_epoch())).count() % 1000000, process.data_->exit_code_));
      if (exit_code == -1 || exit_code == 0x00ffffff) throw invalid_operation_exception("The system cannot find the file specified", caller_info_);
      process.on_exited();
    } catch(...) {
      process.data_->exception_pointer_ = std::current_exception();
      allow_to_continue = true;
    }
  }, *this, std::ref(allow_to_continue));
  while(!allow_to_continue) this_thread::yield();
  if (data_->exception_pointer_) {
    if (data_->start_info_.use_shell_execute() && data_->start_info_.error_dialog())  message_box_message_(data_->start_info_.file_name());
    std::exception_ptr exception_pointer = data_->exception_pointer_;
    data_->exception_pointer_ = nullptr;
    rethrow_exception(exception_pointer);
  }
  return true;
}

process process::start(const process_start_info &start_info) {
  process process;
  process.start_info(start_info);
  process.start();
  return process;
}

process process::start(const std::string& file_name) {
  return start(process_start_info(file_name));
}

process process::start(const std::string& file_name, const std::string& arguments) {
  return start(process_start_info(file_name, arguments));
}

process& process::wait_for_exit() {
  debug::write_line_if(debug_process, strings::format("process::wait_for_exit [handle={}, wait...]", data_->handle_));
  int32_t exit_code = 0;
  if (data_->thread_.joinable()) data_->thread_.join();
  else if (!data_->start_info_.use_shell_execute() && native::process::wait(data_->handle_, exit_code)) data_->exit_code_ = exit_code;
  debug::write_line_if(debug_process, strings::format("process::wait_for_exit [handle={}, exit_code={}, ...exit]", data_->handle_, data_->exit_code_));
  if (data_->exception_pointer_) {
    if (data_->start_info_.use_shell_execute() && data_->start_info_.error_dialog())  message_box_message_(data_->start_info_.file_name());
    std::exception_ptr exception_pointer = data_->exception_pointer_;
    data_->exception_pointer_ = nullptr;
    rethrow_exception(exception_pointer);
  }
  
  return *this;
}

void process::on_exited() {
  data_->exit_callback_(*this, event_args::empty);
}
