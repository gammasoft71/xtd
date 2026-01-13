#include "../../../include/xtd/collections/specialized/string_dictionary.hpp"
#include "../../../include/xtd/diagnostics/debug.hpp"
#include "../../../include/xtd/diagnostics/debug_break.hpp"
#include "../../../include/xtd/diagnostics/default_trace_listener.hpp"
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
using namespace xtd::reflection;

auto __debug_mutex__ = std::recursive_mutex {};
auto __listeners__ = trace_listener_collection {};
struct __xtd__diagnostics_config__ final {
  const trace_listener_collection& listeners;
  const string_dictionary& switches;
};
const __xtd__diagnostics_config__& __xtd___read_diagnostics_config__();

trace_listener_collection& debug::listeners_ = __listeners__;

auto debug::auto_flush() noexcept -> bool {
  return auto_flush_;
}

auto debug::auto_flush(bool auto_flush) noexcept -> void {
  auto_flush_ = auto_flush;
}

auto debug::indent_level() noexcept -> uint32 {
  return indent_level_;
}

auto debug::indent_level(uint32 indent_level) noexcept -> void {
  indent_level_ = indent_level;
}

auto debug::indent_size() noexcept -> uint32 {
  return indent_size_;
}

auto debug::indent_size(uint32 indent_size) noexcept -> void {
  indent_size_ = indent_size;
}

auto debug::listeners() -> trace_listener_collection& {
  if (listeners_.count()) return listeners_;
  call_once_ {
    const auto& [listeners, switches] = __xtd___read_diagnostics_config__();
    listeners_ = listeners;
  };
  return listeners_;
}

auto debug::listeners(const trace_listener_collection& listeners) -> void {
  listeners_ = listeners;
}

auto debug::show_assert_dialog() noexcept -> bool {
  return internal_show_assert_dialog();
}

auto debug::show_assert_dialog(bool show_assert_dialog) noexcept -> void {
  for (auto listener : listeners())
    if (is<default_trace_listener>(listener))
      as<default_trace_listener>(listener)->assert_ui_enabled(show_assert_dialog);
}

auto debug::use_global_lock() noexcept -> bool {
  return use_global_lock_;
}

auto debug::use_global_lock(bool use_global_lock) noexcept -> void {
  use_global_lock_ = use_global_lock;
}

auto debug::cassert(bool condition, const xtd::diagnostics::stack_frame& stack_frame) -> void {
  if (__should_aborted__(stack_frame, condition, string::empty_string)) debug_break_();
}

auto debug::cassert(bool condition, const string& message, const xtd::diagnostics::stack_frame& stack_frame) -> void {
  if (__should_aborted__(stack_frame, condition, message)) debug_break_();
}

auto debug::cassert(bool condition, const string& message, const string& detail_message, const xtd::diagnostics::stack_frame& stack_frame) -> void {
  if (__should_aborted__(stack_frame, condition, message, detail_message)) debug_break_();
}

auto debug::indent() noexcept -> void {
  indent_level(indent_level() + 1);
}

auto debug::unindent() noexcept -> void {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}

auto debug::fail__(const string& message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->fail(message);
    } else
      listener->fail(message);
  }
  if (auto_flush_) flush();
}

auto debug::fail__(const string& message, const string& detail_message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->fail(message, detail_message);
    } else
      listener->fail(message, detail_message);
  }
  if (auto_flush_) flush();
}

auto debug::flush_() -> void {
  for (auto listener : listeners())
    listener->flush();
}

auto debug::trace_event_(trace_event_type trace_event_type, const string& message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->trace_event(trace_event_cache(), assembly::get_executing_assembly().name_or_file_name(), trace_event_type, 0, message);
    } else
      listener->trace_event(trace_event_cache(), assembly::get_executing_assembly().name_or_file_name(), trace_event_type, 0, message);
  }
  if (auto_flush_) flush();
}

auto debug::write_(const string& message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->write(message);
    } else
      listener->write(message);
  }
  if (auto_flush_) flush();
}

auto debug::write_(const string& message, const string& category) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->write(message, category);
    } else
      listener->write(message, category);
  }
  if (auto_flush_) flush();
}

auto debug::write_line_(const string& message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->write_line(message);
    } else
      listener->write_line(message);
  }
  if (auto_flush_) flush();
}

auto debug::write_line_(const string& message, const string& category) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->write_line(message, category);
    } else
      listener->write_line(message, category);
  }
  if (auto_flush_) flush();
}

auto debug::assert_dialog(bool condition, const string& message, const string& detail_message, const stack_frame& stack_frame) -> assert_dialog_result {
  if (condition == true) return assert_dialog_result::ignore;
  write_line("---- DEBUG ASSERTION FAILED ----");
  write_line("---- Assert Short Message----");
  write_line(message);
  write_line("---- Assert Long Message----");
  write_line(detail_message);
  write_line(stack_trace(stack_frame).to_string());
  write_line("");
  return internal_show_assert_dialog() ? static_cast<assert_dialog_result>(native::debugger::show_assert_dialog(string::format("{}\n{}\n{}", message, detail_message, stack_trace(stack_frame)), assert_dialog_caption())) : assert_dialog_result::retry;
}

auto debug::assert_dialog_caption() -> string  {
  return "Assertion Failed: Abort=Quit, Retry=Debug, Ignore=Continue";
}

auto debug::internal_show_assert_dialog() noexcept -> bool {
  for (auto listener : listeners())
    if (is<default_trace_listener>(listener) && as<default_trace_listener>(listener)->assert_ui_enabled())
      return true;
  return false;
}
