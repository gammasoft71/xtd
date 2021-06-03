#include "../../../include/xtd/diagnostics/process.h"
#include "../../../include/xtd/diagnostics/debug.h"
#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::diagnostics;

namespace {
  const bool debug_process = false;
}

process::process() {
  exited.set_data(data_.get());
}

process& process::operator=(const process& value) {
  if (data_.use_count() == 1 && data_->thread_.joinable()) data_->thread_.detach();
  auto exit_callback = data_->exit_callback_;
  data_ = value.data_;
  exited.set_data(data_.get());
  data_->exit_callback_ += exit_callback;
  return *this;
}

process::~process() {
  if (data_.use_count() == 1 && data_->thread_.joinable()) data_->thread_.detach();
}

int32_t process::exit_code() const {
  return data_->exit_code_;
}

std::chrono::system_clock::time_point process::exit_time() const {
  return data_->exit_time_;
}

intptr_t process::handle() const {return data_->handle_;}

std::string process::machine_name() const {
  if (data_->handle_ == 0) throw xtd::invalid_operation_exception(caller_info_);
  return ".";
}

process_start_info process::start_info() const {return data_->start_info_;}
process& process::start_info(process_start_info value) {
  data_->start_info_ = value;
  return *this;
}

std::chrono::system_clock::time_point process::start_time() const {
  return data_->start_time_;
}

process&  process::kill() {
  native::process::kill(data_->handle_);
  debug::write_line_if(debug_process, strings::format("process::kill [handle={}, killed]", data_->handle_));
  return *this;
}

process process::start(const process_start_info &start_info) {
  process process;
  process.start_info(start_info);
  bool thread_started = false;

  process.data_->thread_ = thread([&](class process process) {
    thread_started = true;
    process.data_->start_time_ = system_clock::now();
    std::string shell_execute = "";
    if (process.start_info().use_shell_execute()) {
      if (environment::os_version().is_windows_platform()) shell_execute = "explorer ";
      else if (environment::os_version().is_macos_platform()) shell_execute = "open ";
      else if (environment::os_version().is_linux_platform()) shell_execute = "xdg-open ";
    }
    auto command_line_ = strings::format("{}{}{}", shell_execute, process.start_info().file_name(), process.start_info().arguments() == "" ? "" : strings::format(" {}", process.start_info().arguments()));
    process.data_->handle_ = native::process::create(command_line_);
    debug::write_line_if(debug_process, strings::format("process::start [handle={}, start_time={:u}.{:D6}, started]", process.data_->handle_, process.data_->start_time_, (std::chrono::duration_cast<std::chrono::microseconds>(process.data_->start_time_.time_since_epoch())).count() % 1000000));
    native::process::wait(process.data_->handle_, process.data_->exit_code_);
    process.data_->exit_time_ = system_clock::now();
    debug::write_line_if(debug_process, strings::format("process::start [handle={}, exit_time={:u}.{:D6}, exited]", process.data_->handle_, process.data_->exit_time_, (std::chrono::duration_cast<std::chrono::microseconds>(process.data_->exit_time_.time_since_epoch())).count() % 1000000));
    process.on_exited();
  }, process);
  while(!thread_started) this_thread::yield();
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
  if (data_->thread_.joinable()) data_->thread_.join();
  else native::process::wait(data_->handle_, data_->exit_code_);
  debug::write_line_if(debug_process, strings::format("process::wait_for_exit [handle={}, exit_code={}, ...exit]", data_->handle_, data_->exit_code_));
  return *this;
}

void process::on_exited() {
  data_->exit_callback_(*this, event_args::empty);
}
