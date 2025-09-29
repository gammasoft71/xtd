#include "../../../include/xtd/collections/specialized/string_dictionary.hpp"
#include "../../../include/xtd/configuration/file_settings.hpp"
#include "../../../include/xtd/diagnostics/console_trace_listener.hpp"
#include "../../../include/xtd/diagnostics/debug.hpp"
#include "../../../include/xtd/diagnostics/debug_break.hpp"
#include "../../../include/xtd/diagnostics/default_trace_listener.hpp"
#include "../../../include/xtd/diagnostics/ostream_trace_listener.hpp"
#include "../../../include/xtd/helpers/throw_helper.hpp"
#include "../../../include/xtd/reflection/assembly.hpp"
#include "../../../include/xtd/call_once.hpp"
#include "../../../include/xtd/lock.hpp"
#include <mutex>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::specialized;
using namespace xtd::diagnostics;
using namespace xtd::helpers;
using namespace xtd::io;
using namespace xtd::reflection;

namespace {
  static const auto empty_diagnostics_content = {
    "# ============================================================================",
    "#  xtd::diagnostics configuration file",
    "#  Define and customize diagnostic listeners and switches",
    "# ============================================================================",
    "",
    "",
    "# --------------------------------------------------------------------------",
    "# Listeners",
    "# --------------------------------------------------------------------------",
    "# Define trace listeners.",
    "# Each entry has the form:",
    "#   name = \"key1=value1;key2=value2;...\"",
    "#",
    "# Available listener types:",
    "#   - type=default   : writes to system debugger/log (default)",
    "#   - type=console   : writes to console output/error",
    "#   - type=file      : writes to a log file",
    "#",
    "# Common options:",
    "#   indent_size=N            : number of spaces for indentation (default=4)",
    "#   trace_option=options     : A combination of : none, logical_operation_stack,",
    "#                              date_time, timestamp, process_id, thread_id,",
    "#                              callstack. ",
    "#                              Options must be separated by a comma (,).",
    "#",
    "# default listener specific options:",
    "#   log=file_path            : add log file path",
    "#",
    "# console listener specific options:",
    "#   error_stream=true/false  : use stderr instead of stdout",
    "#",
    "# file listener specific options:",
    "#   append=true/false        : append to file (default=true)",
    "#   path=file_path           : add log file path",
    "#",
    "# Examples:",
    "# [listeners]",
    "# console_listener = \"type=console;error_stream=true\"",
    "# file_listener = \"type=file;path=app.log;append=true;\"",
    "# default = \"type=default;log=default.log\"",
    "# --------------------------------------------------------------------------",
    "",
    "[listeners]",
    "",
    "# --------------------------------------------------------------------------",
    "# Switches",
    "# --------------------------------------------------------------------------",
    "# Define diagnostics switches.",
    "# Each switch is simply \"name = value\".",
    "#",
    "# Available xtd switch types:",
    "#   BooleanSwitch : true/false",
    "#   SourceSwitch  : off, critical, error, warning, information, verbose,",
    "#                   activity_tracing, all (or numeric levels)",
    "#   TraceSwitch   : off, error, warning, info, verbose (or numeric levels)",
    "#",
    "# Notes: User switch types can also be used.",
    "#",
    "# Examples:",
    "# [switches]",
    "# network_switch = warning",
    "# ui_switch = verbose",
    "# feature_x = true",
    "# --------------------------------------------------------------------------",
    "",
    "[switches]"
  };
}

const std::tuple<const xtd::diagnostics::trace_listener_collection&, const xtd::collections::specialized::string_dictionary&>& __xtd___read_diagnostics_fonfig__() {
  static auto listeners = trace_listener_collection {};
  static auto switches = string_dictionary {};
  call_once_ {
    auto product_name = assembly::get_executing_assembly().product() != string::empty_string ? assembly::get_executing_assembly().product() : path::get_file_name_without_extension(assembly::get_executing_assembly().location());
    auto company_name = assembly::get_executing_assembly().company() != string::empty_string ? assembly::get_executing_assembly().company() : product_name;
    auto file_name = path::combine(environment::get_folder_path(environment::special_folder::application_data), company_name, product_name + ".diagnostics.config");
    if (!file::exists(file_name)) file::write_all_lines(file_name, empty_diagnostics_content);
    else {
      auto file_settings = configuration::file_settings(file_name);
      // listeners
      for (const auto& [key, value] : file_settings.key_values("listeners")) {
        auto key_values = value.split(';', string_split_options::remove_empty_entries);
        auto sub_key_values = string_dictionary {};
        for (const auto& key_value : key_values) {
          auto parts = key_value.split('=');
          if (parts.length() != 2) throw_helper::throws(xtd::helpers::exception_case::format);
          sub_key_values[parts[0].trim()] = parts[1].trim();
        }
        if (!sub_key_values.contains_key("type")) throw_helper::throws(xtd::helpers::exception_case::format);
        auto listener = ptr<trace_listener> {};
        if (sub_key_values["type"] == "default")
          listener = new_ptr<default_trace_listener>(sub_key_values.contains_key("log") ? sub_key_values["log"] : "");
        else if (sub_key_values["type"] == "console")
          listener = new_ptr<console_trace_listener>(sub_key_values.contains_key("error_stream") ? as<bool>(sub_key_values["error_stream"]) : false);
        else if (sub_key_values["type"] == "file" && sub_key_values.contains_key("path"))
          listener = new_ptr<ostream_trace_listener>((sub_key_values.contains_key("append") ? as<bool>(sub_key_values["append"]) : false) ? file::append_text(sub_key_values["path"]) : file::write_text(sub_key_values["path"]));
        else throw_helper::throws(xtd::helpers::exception_case::format);
        listener->name(key);
        listeners.add(listener);
      }

      // switches
      for (const auto& [key, value] : file_settings.key_values("switches"))
        switches[key] = value;
    }
    
    if (!listeners.count()) listeners.add(xtd::new_sptr<default_trace_listener>());
  };
  static auto result = std::tuple<const trace_listener_collection&, const string_dictionary&> {listeners, switches};
  return result;
}

extern char** __diagnostics_argv;
auto __debug_mutex__ = std::recursive_mutex {};
auto __listeners__ = trace_listener_collection {};
auto __debug_use_debug_global_lock__ = true;

trace_listener_collection& debug::listeners_ = __listeners__;

bool debug::auto_flush() noexcept {
  return auto_flush_;
}

void debug::auto_flush(bool auto_flush) noexcept {
  auto_flush_ = auto_flush;
}

uint32 debug::indent_level() noexcept {
  return indent_level_;
}

void debug::indent_level(uint32 indent_level) noexcept {
  indent_level_ = indent_level;
}

uint32 debug::indent_size() noexcept {
  return indent_size_;
}

void debug::indent_size(uint32 indent_size) noexcept {
  indent_size_ = indent_size;
}

trace_listener_collection& debug::listeners() {
  if (listeners_.count()) return listeners_;
  call_once_ {
    const auto& [listeners, switches] = __xtd___read_diagnostics_fonfig__();
    listeners_ = listeners;
  };
  return listeners_;
}

void debug::listeners(const trace_listener_collection& listeners) {
  listeners_ = listeners;
}

bool debug::show_assert_dialog() noexcept {
  return internal_show_assert_dialog();
}

void debug::show_assert_dialog(bool show_assert_dialog) noexcept {
  for (auto listener : listeners())
    if (is<default_trace_listener>(listener))
      as<default_trace_listener>(listener)->assert_ui_enabled(show_assert_dialog);
}

bool debug::use_global_lock() noexcept {
  return __debug_use_debug_global_lock__;
}

void debug::use_global_lock(bool use_global_lock) noexcept {
  __debug_use_debug_global_lock__ = use_global_lock;
}

void debug::cassert(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(stack_frame, condition, string::empty_string)) debug_break_();
}

void debug::cassert(bool condition, const string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(stack_frame, condition, message)) debug_break_();
}

void debug::cassert(bool condition, const string& message, const string& detail_message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(stack_frame, condition, message, detail_message)) debug_break_();
}

void debug::indent() noexcept {
  indent_level(indent_level() + 1);
}

void debug::unindent() noexcept {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}

void debug::fail__(const string& message) {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && __debug_use_debug_global_lock__) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->fail(message);
    } else
      listener->fail(message);
  }
  if (auto_flush_) flush();
}

void debug::fail__(const string& message, const string& detail_message) {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && __debug_use_debug_global_lock__) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->fail(message, detail_message);
    } else
      listener->fail(message, detail_message);
  }
  if (auto_flush_) flush();
}

void debug::flush_() {
  for (auto listener : listeners())
    listener->flush();
}

void debug::trace_event_(trace_event_type trace_event_type, const string& message) {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && __debug_use_debug_global_lock__) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->trace_event(trace_event_cache(), assembly::get_executing_assembly().name_or_file_name(), trace_event_type, 0, message);
    } else
      listener->trace_event(trace_event_cache(), assembly::get_executing_assembly().name_or_file_name(), trace_event_type, 0, message);
  }
  if (auto_flush_) flush();
}

void debug::write_(const string& message) {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && __debug_use_debug_global_lock__) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->write(message);
    } else
      listener->write(message);
  }
  if (auto_flush_) flush();
}

void debug::write_(const string& message, const string& category) {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && __debug_use_debug_global_lock__) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->write(message, category);
    } else
      listener->write(message, category);
  }
  if (auto_flush_) flush();
}

void debug::write_line_(const string& message) {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && __debug_use_debug_global_lock__) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->write_line(message);
    } else
      listener->write_line(message);
  }
  if (auto_flush_) flush();
}

void debug::write_line_(const string& message, const string& category) {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && __debug_use_debug_global_lock__) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->write_line(message, category);
    } else
      listener->write_line(message, category);
  }
  if (auto_flush_) flush();
}

xtd::diagnostics::assert_dialog_result debug::assert_dialog(bool condition, const string& message, const string& detail_message, const stack_frame& stack_frame) {
  if (condition == true) return assert_dialog_result::ignore;
  write_line("---- DEBUG ASSERTION FAILED ----");
  write_line("---- Assert Short Message----");
  write_line(message);
  write_line("---- Assert Long Message----");
  write_line(detail_message);
  write_line(stack_trace(stack_frame).to_string());
  write_line("");
  return internal_show_assert_dialog() ? static_cast<xtd::diagnostics::assert_dialog_result>(native::debugger::show_assert_dialog(string::format("{}\n{}\n{}", message, detail_message, stack_trace(stack_frame)), assert_dialog_caption())) : assert_dialog_result::retry;
}

xtd::string debug::assert_dialog_caption() {
  return "Assertion Failed: Abort=Quit, Retry=Debug, Ignore=Continue"_t;
}

bool debug::internal_show_assert_dialog() noexcept {
  for (auto listener : listeners())
    if (is<default_trace_listener>(listener) && as<default_trace_listener>(listener)->assert_ui_enabled())
      return true;
  return false;
}
