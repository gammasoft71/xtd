#include "../../../include/xtd/diagnostics/process.hpp"
#include "../../../include/xtd/diagnostics/debug.hpp"
#include "../../../include/xtd/diagnostics/boolean_switch.hpp"
#include "../../../include/xtd/environment.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/threading/thread.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/process>
#include <xtd/native/process_creation_flags>
#include <xtd/native/priority_class>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::io;
using namespace xtd::diagnostics;
using namespace xtd::helpers;
using namespace xtd::threading;

namespace {
  boolean_switch& show_debug_process() {
    static boolean_switch sw("process", "Shows xtd::diagnostics::process log", "false");
    return sw;
  }
}

struct process::data {
  xtd::diagnostics::process_start_info start_info;
  std::optional<intptr> handle = 0;
  int32 id = 0;
  string machine_name;
  xtd::diagnostics::process_priority_class priority_class = xtd::diagnostics::process_priority_class::normal;
  xtd::uptr<std::ostream> standard_input;
  xtd::uptr<std::istream> standard_output;
  xtd::uptr<std::istream> standard_error;
  class thread thread;
  xtd::date_time start_time;
  xtd::date_time exit_time;
  bool enable_raising_events = false;
  bool allow_to_continue = false;
  std::optional<int32> exit_code;
  event_handler exit_callback;
  data_received_event_handler error_data_received_callback;
  data_received_event_handler output_data_received_callback;
  std::exception_ptr exception_pointer;
};

// This delegate will be initialized by __init_process_message_box_message__ in xtd.forms/src/xtd/forms/application.cpp file.
// This operation can be done only if xtd.forms lib is present.
//xtd::delegate<void(const xtd::string&)> process::message_box_message_;

bool process::error_data_received_event::is_empty() const noexcept {
  return data_received_event_handler::is_empty();
}

data_received_event_handler& process::error_data_received_event::operator +=(const data_received_event_handler& handler) noexcept {
  data_->error_data_received_callback += (handler);
  return data_received_event_handler::operator +=(handler);
}

data_received_event_handler& process::error_data_received_event::operator +=(const typename data_received_event_handler::function_t& function) noexcept {
  data_->error_data_received_callback += (function);
  return data_received_event_handler::operator +=(function);
}

data_received_event_handler& process::error_data_received_event::operator -=(const data_received_event_handler& handler) noexcept {
  data_->error_data_received_callback -= (handler);
  return data_received_event_handler::operator -=(handler);
}

data_received_event_handler& process::error_data_received_event::operator -=(const typename data_received_event_handler::function_t& function) noexcept {
  data_->error_data_received_callback -= (function);
  return data_received_event_handler::operator -=(function);
}

data_received_event_handler& process::error_data_received_event::error_data_received_callback() noexcept {
  return data_->error_data_received_callback;
}

bool process::exit_event::is_empty() const noexcept {
  return event_handler::is_empty();
}

event_handler& process::exit_event::operator +=(const event_handler& handler) noexcept {
  data_->exit_callback += (handler);
  return event_handler::operator +=(handler);
}

event_handler& process::exit_event::operator +=(const typename event_handler::function_t& function) noexcept {
  data_->exit_callback += (function);
  return event_handler::operator +=(function);
}

event_handler& process::exit_event::operator -=(const event_handler& handler) noexcept {
  data_->exit_callback -= (handler);
  return event_handler::operator -=(handler);
}

event_handler& process::exit_event::operator -=(const typename event_handler::function_t& function) noexcept {
  data_->exit_callback -= (function);
  return event_handler::operator -=(function);
}

event_handler& process::exit_event::exit_callback() noexcept {
  return data_->exit_callback;
}

bool process::output_data_received_event::is_empty() const noexcept {
  return data_received_event_handler::is_empty();
}

data_received_event_handler& process::output_data_received_event::operator +=(const data_received_event_handler& handler) noexcept {
  data_->output_data_received_callback += (handler);
  return data_received_event_handler::operator +=(handler);
}

data_received_event_handler& process::output_data_received_event::operator +=(const typename data_received_event_handler::function_t& function) noexcept {
  data_->output_data_received_callback += (function);
  return data_received_event_handler::operator +=(function);
}

data_received_event_handler& process::output_data_received_event::operator -=(const data_received_event_handler& handler) noexcept {
  data_->output_data_received_callback -= (handler);
  return data_received_event_handler::operator -=(handler);
}

data_received_event_handler& process::output_data_received_event::operator -=(const typename data_received_event_handler::function_t& function) noexcept {
  data_->output_data_received_callback -= (function);
  return data_received_event_handler::operator -=(function);
}

data_received_event_handler& process::output_data_received_event::output_data_received_callback() noexcept {
  return data_->output_data_received_callback;
}

process::process() : data_(xtd::new_sptr<data>()) {
  exited.set_data(data_.get());
}

process& process::operator =(const process& value) {
  if (data_.use_count() == 1 && data_->thread.joinable()) data_->thread.detach();
  auto exit_callback = data_->exit_callback;
  data_ = value.data_;
  exited.set_data(data_.get());
  data_->exit_callback += exit_callback;
  data_->exception_pointer = nullptr;
  return *this;
}

process::~process() {
  if (data_.use_count() == 1 && data_->thread.joinable()) data_->thread.detach();
}

int32 process::base_priority() const {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  static auto base_priorities = std::map<process_priority_class, int32> {{process_priority_class::idle, 4}, {process_priority_class::below_normal, 6}, {process_priority_class::normal, 8}, {process_priority_class::above_normal, 10}, {process_priority_class::high, 13}, {process_priority_class::real_time, 24}};
  return base_priorities[priority_class()];
}

bool process::enable_raising_events() const {
  return data_->enable_raising_events;
}

process& process::enable_raising_events(bool value) {
  data_->enable_raising_events = value;
  return *this;
}

int32 process::exit_code() const {
  if (!data_->handle.has_value() || !has_exited()) throw_helper::throws(exception_case::invalid_operation);
  return data_->exit_code.value();
}

date_time process::exit_time() const {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  return data_->exit_time;
}

intptr process::handle() const {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  return data_->handle.value();
}

bool process::has_exited() const {
  if (!data_->handle.has_value() || !data_->exit_code.has_value()) throw_helper::throws(exception_case::invalid_operation);
  return data_->exit_code.has_value();
}

int32 process::id() const {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  return data_->id;
}

string process::machine_name() const {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  return data_->machine_name;
}

process_priority_class process::priority_class() const {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  return data_->priority_class;
}

process& process::priority_class(process_priority_class value) {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  data_->priority_class = value;
  auto priorities = std::map<process_priority_class, int32> {{process_priority_class::idle, IDLE_PRIORITY_CLASS}, {process_priority_class::below_normal, BELOW_NORMAL_PRIORITY_CLASS}, {process_priority_class::normal, NORMAL_PRIORITY_CLASS}, {process_priority_class::above_normal, ABOVE_NORMAL_PRIORITY_CLASS}, {process_priority_class::high, HIGH_PRIORITY_CLASS}, {process_priority_class::real_time, REALTIME_PRIORITY_CLASS}};
  auto it = priorities.find(value);
  if (it == priorities.end()) throw_helper::throws(exception_case::argument);
  if (native::process::priority_class(data_->handle.value(), it->second) == false) throw_helper::throws(exception_case::invalid_operation);
  return *this;
}

string process::process_name() const {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  return path::get_file_name_without_extension(data_->start_info.file_name());
}

std::istream& process::standard_error() {
  if (!data_->handle.has_value() || data_->standard_error == nullptr || !data_->start_info.redirect_standard_error() || data_->start_info.use_shell_execute())
    throw_helper::throws(exception_case::invalid_operation);
  return *data_->standard_error;
}

std::ostream& process::standard_input() {
  if (!data_->handle.has_value() || data_->standard_input == nullptr || !data_->start_info.redirect_standard_input() || data_->start_info.use_shell_execute())
    throw_helper::throws(exception_case::invalid_operation);
  return *data_->standard_input;
}

std::istream& process::standard_output() {
  if (!data_->handle.has_value() || data_->standard_output == nullptr || !data_->start_info.redirect_standard_output() || data_->start_info.use_shell_execute())
    throw_helper::throws(exception_case::invalid_operation);
  return *data_->standard_output;
}

const process_start_info& process::start_info() const {
  return data_->start_info;
}

process_start_info& process::start_info() {
  return data_->start_info;
}

process& process::start_info(const process_start_info& value) {
  data_->start_info = value;
  return *this;
}

date_time process::start_time() const {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  return data_->start_time;
}

void process::close() {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  if (data_.use_count() == 1 && data_->thread.joinable()) {
    data_->thread.detach();
    data_->handle.reset();
  }
}

void process::kill() {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  native::process::kill(data_->handle.value());
  debug::write_line_if(show_debug_process().enabled(), string::format("process::kill [handle={}, killed]", data_->handle));
}

bool process::start() {
  //if (data_->handle.has_value() && !data_->exit_code.has_value()) return false;
  if (data_->thread.joinable()) return false;
  data_->thread = thread {parameterized_thread_start {[](xtd::any_object arg) {
    auto process = as<class process>(arg);
    try {
      process.data_->handle.reset();
      process.data_->exit_code.reset();
      process.data_->start_time = date_time::now();
      auto process_creation_flags = 0;
      if (process.start_info().create_no_window()) process_creation_flags |= CREATE_NO_WINDOW;
      auto process_window_style = 0;
      
      if (process.start_info().use_shell_execute())
        process.data_->handle = native::process::shell_execute(process.start_info().verb(), process.start_info().file_name(), process.start_info().arguments(), process.start_info().working_directory(), process_window_style);
      else {
        auto [handle, id, standard_input, standard_output, standard_error] = native::process::start(process.start_info().file_name(), process.start_info().arguments(), process.start_info().working_directory(), process_window_style, process_creation_flags, std::make_tuple(process.data_->start_info.redirect_standard_input(), process.data_->start_info.redirect_standard_output(), process.data_->start_info.redirect_standard_error()));
        process.data_->handle = handle;
        process.data_->id = id;
        process.data_->machine_name = ".";
        process.data_->standard_input = std::move(standard_input);
        process.data_->standard_output = std::move(standard_output);
        process.data_->standard_error = std::move(standard_error);
      }
      if (process.data_->handle == 0) throw_helper::throws(exception_case::invalid_operation, "The system cannot find the file specified");
      process.data_->allow_to_continue = true;
      debug::write_line_if(show_debug_process().enabled(), string::format("process::start [handle={}, command_line={}, start_time={:u}.{:D6}, started]", process.data_->handle, string::format("{}{}", process.start_info().file_name(), process.start_info().arguments() == "" ? "" : string::format(" {}", process.start_info().arguments())), process.data_->start_time, (std::chrono::duration_cast<std::chrono::microseconds>(process.data_->start_time.ticks_duration())).count() % 1000000));
      auto exit_code = 0;
      process.data_->exit_code = native::process::wait(process.data_->handle.value(), exit_code) ? exit_code : -1;
      process.data_->exit_time = date_time::now();
      debug::write_line_if(show_debug_process().enabled(), string::format("process::start [handle={}, exit_time={:u}.{:D6}, exit_code={}, exited]", process.data_->handle, process.data_->exit_time, std::chrono::duration_cast<std::chrono::microseconds>(process.data_->exit_time.ticks_duration()).count() % 1000000, process.data_->exit_code));
      if (!process.data_->exit_code.has_value() || process.data_->exit_code == -1 || process.data_->exit_code == 0x00ffffff) throw_helper::throws(exception_case::invalid_operation, "The system cannot find the file specified");
      process.on_exited();
    } catch (...) {
      process.data_->exception_pointer = std::current_exception();
      process.data_->allow_to_continue = true;
    }
  }}};
  data_->thread.start(*this);
  while (!data_->allow_to_continue) xtd::threading::thread::sleep(100);
  if (!data_->exception_pointer) return true;
  if (data_->start_info.use_shell_execute() && data_->start_info.error_dialog())  message_box_message_(data_->start_info.file_name());
  auto exception_pointer = data_->exception_pointer;
  data_->exception_pointer = nullptr;
  rethrow_exception(exception_pointer);
}

process process::start(const process_start_info& start_info) {
  auto process = diagnostics::process {};
  process.start_info(start_info);
  process.start();
  return process;
}

process process::start(const string& file_name) {
  return start(process_start_info {file_name});
}

process process::start(const string& file_name, const string& arguments) {
  return start(process_start_info {file_name, arguments});
}

process& process::wait_for_exit() {
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  debug::write_line_if(show_debug_process().enabled(), string::format("process::wait_for_exit [handle={}, wait...]", data_->handle));
  if (data_->thread.joinable()) data_->thread.join();
  close();
  debug::write_line_if(show_debug_process().enabled(), string::format("process::wait_for_exit [handle={}, exit_code={}, ...exit]", data_->handle, data_->exit_code));
  if (data_->exception_pointer) {
    if (data_->start_info.use_shell_execute() && data_->start_info.error_dialog())  message_box_message_(data_->start_info.file_name());
    auto exception_pointer = data_->exception_pointer;
    data_->exception_pointer = nullptr;
    rethrow_exception(exception_pointer);
  }
  
  return *this;
}

process& process::wait_for_exit(int32 milliseconds) {
  /// @todo create a timeout...
  /// @see https://stackoverflow.com/questions/9948420/timeout-for-thread-join
  if (!data_->handle.has_value()) throw_helper::throws(exception_case::invalid_operation);
  debug::write_line_if(show_debug_process().enabled(), string::format("process::wait_for_exit [handle={}, wait...]", data_->handle));
  if (data_->thread.joinable()) data_->thread.join();
  close();
  debug::write_line_if(show_debug_process().enabled(), string::format("process::wait_for_exit [handle={}, exit_code={}, ...exit]", data_->handle, data_->exit_code));
  if (data_->exception_pointer) {
    if (data_->start_info.use_shell_execute() && data_->start_info.error_dialog())  message_box_message_(data_->start_info.file_name());
    auto exception_pointer = data_->exception_pointer;
    data_->exception_pointer = nullptr;
    rethrow_exception(exception_pointer);
  }
  
  return *this;
}

void process::on_exited() {
  if (!data_->enable_raising_events) return;
  auto safe_exit_callback = data_->exit_callback;
  if (!safe_exit_callback.is_empty()) safe_exit_callback(*this, event_args::empty);
}
