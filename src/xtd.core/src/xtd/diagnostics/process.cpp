#include "../../../include/xtd/diagnostics/process.h"
#include "../../../include/xtd/diagnostics/debug.h"
#include "../../../include/xtd/diagnostics/boolean_switch.h"
#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/io/path.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process.h>
#include <xtd/native/process_creation_flags.h>
#include <xtd/native/priority_class.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::diagnostics;

namespace {
  boolean_switch show_debug_process("process", "Shows xtd::diagnostics::process log", "false");
}

// This delehgate will be initialized by __init_process_message_box_message__ in xtd.forns/src/xtd/forms/appllication.cpp file.
// This operation can be done only if xtd.forms lib is present.
//xtd::delegate<void(const xtd::ustring&)> process::message_box_message_;

bool process::error_data_received_event::is_empty() const noexcept {
  return data_received_event_handler::is_empty();
}

data_received_event_handler& process::error_data_received_event::operator+=(const data_received_event_handler& handler) noexcept {
  data_->error_data_received_callback_+=(handler);
  return data_received_event_handler::operator+=(handler);
}

data_received_event_handler& process::error_data_received_event::operator+=(const typename data_received_event_handler::function_t& function) noexcept {
  data_->error_data_received_callback_+=(function);
  return data_received_event_handler::operator+=(function);
}

data_received_event_handler& process::error_data_received_event::operator-=(const data_received_event_handler& handler) noexcept {
  data_->error_data_received_callback_-=(handler);
  return data_received_event_handler::operator-=(handler);
}

data_received_event_handler& process::error_data_received_event::operator-=(const typename data_received_event_handler::function_t& function) noexcept {
  data_->error_data_received_callback_-=(function);
  return data_received_event_handler::operator-=(function);
}

bool process::exit_event::is_empty() const noexcept {
  return event_handler::is_empty();
}

event_handler& process::exit_event::operator+=(const event_handler& handler) noexcept {
  data_->exit_callback_+=(handler);
  return event_handler::operator+=(handler);
}

event_handler& process::exit_event::operator+=(const typename event_handler::function_t& function) noexcept {
  data_->exit_callback_+=(function);
  return event_handler::operator+=(function);
}

event_handler& process::exit_event::operator-=(const event_handler& handler) noexcept {
  data_->exit_callback_-=(handler);
  return event_handler::operator-=(handler);
}

event_handler& process::exit_event::operator-=(const typename event_handler::function_t& function) noexcept {
  data_->exit_callback_-=(function);
  return event_handler::operator-=(function);
}

bool process::output_data_received_event::is_empty() const noexcept {
  return data_received_event_handler::is_empty();
}

data_received_event_handler& process::output_data_received_event::operator+=(const data_received_event_handler& handler) noexcept {
  data_->output_data_received_callback_+=(handler);
  return data_received_event_handler::operator+=(handler);
}

data_received_event_handler& process::output_data_received_event::operator+=(const typename data_received_event_handler::function_t& function) noexcept {
  data_->output_data_received_callback_+=(function);
  return data_received_event_handler::operator+=(function);
}

data_received_event_handler& process::output_data_received_event::operator-=(const data_received_event_handler& handler) noexcept {
  data_->output_data_received_callback_-=(handler);
  return data_received_event_handler::operator-=(handler);
}

data_received_event_handler& process::output_data_received_event::operator-=(const typename data_received_event_handler::function_t& function) noexcept {
  data_->output_data_received_callback_-=(function);
  return data_received_event_handler::operator-=(function);
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
  data_->exception_pointer_ = nullptr;
  return *this;
}

process::~process() {
  if (data_.use_count() == 1 && data_->thread_.joinable()) data_->thread_.detach();
}

int32_t process::base_priority() const {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  static map<process_priority_class, int32_t> base_priorities {{process_priority_class::idle, 4}, {process_priority_class::below_normal, 6}, {process_priority_class::normal, 8}, {process_priority_class::above_normal, 10}, {process_priority_class::high, 13}, {process_priority_class::real_time, 24}};
  return base_priorities[priority_class()];
}

bool process::enable_raising_events() const {
  return data_->enable_raising_events_;
}

process& process::enable_raising_events(bool value) {
  data_->enable_raising_events_ = value;
  return *this;
}

int32_t process::exit_code() const {
  if (!data_->handle_.has_value() || !has_exited()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return data_->exit_code_.value();
}

process::time_point process::exit_time() const {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return data_->exit_time_;
}

intptr_t process::handle() const {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return data_->handle_.value();
}

bool process::has_exited() const {
  if (!data_->handle_.has_value() || !data_->exit_code_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return data_->exit_code_.has_value();
}

int32_t process::id() const {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return data_->id_;
}

ustring process::machine_name() const {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return data_->machine_name_;
}

process_priority_class process::priority_class() const {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return data_->priority_class_;
}

process& process::priority_class(process_priority_class value) {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  data_->priority_class_ = value;
  static map<process_priority_class, int32_t> priorities {{process_priority_class::idle, IDLE_PRIORITY_CLASS}, {process_priority_class::below_normal, BELOW_NORMAL_PRIORITY_CLASS}, {process_priority_class::normal, NORMAL_PRIORITY_CLASS}, {process_priority_class::above_normal, ABOVE_NORMAL_PRIORITY_CLASS}, {process_priority_class::high, HIGH_PRIORITY_CLASS}, {process_priority_class::real_time, REALTIME_PRIORITY_CLASS}};
  auto it = priorities.find(value);
  if (it == priorities.end()) throw argument_exception(current_stack_frame_);
  if (native::process::priority_class(data_->handle_.value(), it->second) == false) throw invalid_operation_exception(current_stack_frame_);
  return *this;
}

ustring process::process_name() const {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return path::get_file_name_without_extension(data_->start_info_.file_name());
}

std::istream& process::standard_error() {
  if (!data_->handle_.has_value() || data_->standard_error_ == nullptr || !data_->start_info_.redirect_standard_error() || data_->start_info_.use_shell_execute())
    throw invalid_operation_exception(current_stack_frame_);
  return *data_->standard_error_;
}

std::ostream& process::standard_input() {
  if (!data_->handle_.has_value() || data_->standard_input_ == nullptr || !data_->start_info_.redirect_standard_input() || data_->start_info_.use_shell_execute())
    throw invalid_operation_exception(current_stack_frame_);
  return *data_->standard_input_;
}

std::istream& process::standard_output() {
  if (!data_->handle_.has_value() || data_->standard_output_ == nullptr || !data_->start_info_.redirect_standard_output() || data_->start_info_.use_shell_execute())
    throw invalid_operation_exception(current_stack_frame_);
  return *data_->standard_output_;
}

const process_start_info& process::start_info() const {
  return data_->start_info_;
}

process_start_info& process::start_info() {
  return data_->start_info_;
}

process& process::start_info(const process_start_info& value) {
  data_->start_info_ = value;
  return *this;
}

process::time_point process::start_time() const {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  return data_->start_time_;
}

void process::close() {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  if (data_.use_count() == 1 && data_->thread_.joinable()) {
    data_->thread_.detach();
    data_->handle_.reset();
  }
}

void process::kill() {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  native::process::kill(data_->handle_.value());
  debug::write_line_if(show_debug_process.enabled(), ustring::format("process::kill [handle={}, killed]", data_->handle_));
}

bool process::start() {
  //if (data_->handle_.has_value() && !data_->exit_code_.has_value()) return false;
  if (data_->thread_.joinable()) return false;
  bool allow_to_continue = false;
  data_->thread_ = thread([](class process process, bool& allow_to_continue) {
    try {
      process.data_->handle_.reset();
      process.data_->exit_code_.reset();
      process.data_->start_time_ = system_clock::now();
      int32_t process_creation_flags = 0;
      if (process.start_info().create_no_window()) process_creation_flags |= CREATE_NO_WINDOW;
      int32_t process_window_style = 0;
      
      if (process.start_info().use_shell_execute()) {
        process.data_->handle_ = native::process::shell_execute(process.start_info().verb(), process.start_info().file_name(), process.start_info().arguments(), process.start_info().working_directory(), process_window_style);
      } else {
        auto [handle, id, standard_input, standard_output, standard_error] = native::process::start(process.start_info().file_name(), process.start_info().arguments(), process.start_info().working_directory(), process_window_style, process_creation_flags, make_tuple(process.data_->start_info_.redirect_standard_input(), process.data_->start_info_.redirect_standard_output(), process.data_->start_info_.redirect_standard_error()));
        process.data_->handle_ = handle;
        process.data_->id_ = id;
        process.data_->machine_name_ = ".";
        process.data_->standard_input_ = move(standard_input);
        process.data_->standard_output_ = move(standard_output);
        process.data_->standard_error_ = move(standard_error);
      }
      if (process.data_->handle_ == 0) throw invalid_operation_exception("The system cannot find the file specified", current_stack_frame_);
      allow_to_continue = true;
      debug::write_line_if(show_debug_process.enabled(), ustring::format("process::start [handle={}, command_line={}, start_time={:u}.{:D6}, started]", process.data_->handle_, ustring::format("{}{}", process.start_info().file_name(), process.start_info().arguments() == "" ? "" : ustring::format(" {}", process.start_info().arguments())), process.data_->start_time_, (std::chrono::duration_cast<std::chrono::microseconds>(process.data_->start_time_.time_since_epoch())).count() % 1000000));
      int32_t exit_code = 0;
      process.data_->exit_code_ =  native::process::wait(process.data_->handle_.value(), exit_code) ? exit_code : -1;
      process.data_->exit_time_ = system_clock::now();
      debug::write_line_if(show_debug_process.enabled(), ustring::format("process::start [handle={}, exit_time={:u}.{:D6}, exit_code={}, exited]", process.data_->handle_, process.data_->exit_time_, (std::chrono::duration_cast<std::chrono::microseconds>(process.data_->exit_time_.time_since_epoch())).count() % 1000000, process.data_->exit_code_));
      if (!process.data_->exit_code_.has_value() || process.data_->exit_code_ == -1 || process.data_->exit_code_ == 0x00ffffff) throw invalid_operation_exception("The system cannot find the file specified", current_stack_frame_);
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

process process::start(const ustring& file_name) {
  return start(process_start_info(file_name));
}

process process::start(const ustring& file_name, const ustring& arguments) {
  return start(process_start_info(file_name, arguments));
}

process& process::wait_for_exit() {
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  debug::write_line_if(show_debug_process.enabled(), ustring::format("process::wait_for_exit [handle={}, wait...]", data_->handle_));
  if (data_->thread_.joinable()) data_->thread_.join();
  close();
  debug::write_line_if(show_debug_process.enabled(), ustring::format("process::wait_for_exit [handle={}, exit_code={}, ...exit]", data_->handle_, data_->exit_code_));
  if (data_->exception_pointer_) {
    if (data_->start_info_.use_shell_execute() && data_->start_info_.error_dialog())  message_box_message_(data_->start_info_.file_name());
    std::exception_ptr exception_pointer = data_->exception_pointer_;
    data_->exception_pointer_ = nullptr;
    rethrow_exception(exception_pointer);
  }
  
  return *this;
}

process& process::wait_for_exit(int32_t milliseconds) {
  /// @todo create a timeout...
  /// @see https://stackoverflow.com/questions/9948420/timeout-for-thread-join
  if (!data_->handle_.has_value()) throw xtd::invalid_operation_exception(current_stack_frame_);
  debug::write_line_if(show_debug_process.enabled(), ustring::format("process::wait_for_exit [handle={}, wait...]", data_->handle_));
  if (data_->thread_.joinable()) data_->thread_.join();
  close();
  debug::write_line_if(show_debug_process.enabled(), ustring::format("process::wait_for_exit [handle={}, exit_code={}, ...exit]", data_->handle_, data_->exit_code_));
  if (data_->exception_pointer_) {
    if (data_->start_info_.use_shell_execute() && data_->start_info_.error_dialog())  message_box_message_(data_->start_info_.file_name());
    std::exception_ptr exception_pointer = data_->exception_pointer_;
    data_->exception_pointer_ = nullptr;
    rethrow_exception(exception_pointer);
  }
  
  return *this;
}

void process::on_exited() {
  if (data_->enable_raising_events_) data_->exit_callback_(*this, event_args::empty);
}
