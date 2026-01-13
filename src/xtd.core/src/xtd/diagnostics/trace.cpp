#include "../../../include/xtd/collections/specialized/string_dictionary.hpp"
#include "../../../include/xtd/diagnostics/trace.hpp"
#include "../../../include/xtd/diagnostics/debugger.hpp"
#include "../../../include/xtd/diagnostics/default_trace_listener.hpp"
#include "../../../include/xtd/reflection/assembly.hpp"
#include "../../../include/xtd/call_once.hpp"
#include "../../../include/xtd/lock.hpp"
#include <mutex>

using namespace xtd;
using namespace xtd::collections::specialized;
using namespace xtd::diagnostics;
using namespace xtd::reflection;

extern std::recursive_mutex __debug_mutex__;
extern trace_listener_collection __listeners__;
struct __xtd__diagnostics_config__ final {
  const trace_listener_collection& listeners;
  const string_dictionary& switches;
};
auto __xtd___read_diagnostics_config__() -> const __xtd__diagnostics_config__&;

trace_listener_collection& trace::listeners_ = __listeners__;

auto trace::auto_flush() noexcept -> bool {
  return auto_flush_;
}

auto trace::auto_flush(bool auto_flush) noexcept -> void {
  auto_flush_ = auto_flush;
}

auto trace::indent_level() noexcept -> uint32 {
  return indent_level_;
}

auto trace::indent_level(uint32 indent_level) noexcept -> void {
  indent_level_ = indent_level;
}

auto trace::indent_size() noexcept -> uint32 {
  return indent_size_;
}

auto trace::indent_size(uint32 indent_size) noexcept -> void {
  indent_size_ = indent_size;
}

auto trace::listeners() -> trace_listener_collection& {
  if (listeners_.count()) return listeners_;
  call_once_ {
    const auto& [listeners, switches] = __xtd___read_diagnostics_config__();
    listeners_ = listeners;
  };
  return listeners_;
}

auto trace::listeners(const trace_listener_collection& listeners) -> void {
  listeners_ = listeners;
}

auto trace::show_assert_dialog() noexcept -> bool {
  return debug::internal_show_assert_dialog();
}

auto trace::show_assert_dialog(bool show_assert_dialog) noexcept -> void {
  for (auto listener : listeners())
    if (is<default_trace_listener>(listener))
      as<default_trace_listener>(listener)->assert_ui_enabled(show_assert_dialog);
}

auto trace::use_global_lock() noexcept -> bool {
  return use_global_lock_;
}

auto trace::use_global_lock(bool use_global_lock) noexcept -> void {
  use_global_lock_ = use_global_lock;
}

auto trace::cassert(bool condition, const stack_frame& frame) -> void {
  if (__should_aborted__(frame, condition, string::empty_string)) __xtd_debugbreak();
}

auto trace::cassert(bool condition, const string& message, const stack_frame& frame) -> void {
  if (__should_aborted__(frame, condition, message)) __xtd_debugbreak();
}

auto trace::cassert(bool condition, const string& message, const string& detail_message, const stack_frame& frame) -> void {
  if (__should_aborted__(frame, condition, message, detail_message)) __xtd_debugbreak();
}

auto trace::indent() noexcept -> void {
  indent_level(indent_level() + 1);
}

auto trace::unindent() noexcept -> void {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}

auto trace::fail__(const string& message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      auto lock = std::lock_guard<std::recursive_mutex> {__debug_mutex__};
      listener->fail(message);
    } else
      listener->fail(message);
  }
  if (auto_flush_) flush();
}

auto trace::fail__(const string& message, const string& detail_message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      auto lock = std::lock_guard<std::recursive_mutex> {__debug_mutex__};
      listener->fail(message, detail_message);
    } else
      listener->fail(message, detail_message);
  }
  if (auto_flush_) flush();
}

auto trace::flush_() -> void {
  for (auto listener : listeners())
    listener->flush();
}

auto trace::trace_event_(trace_event_type trace_event_type, const string& message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      auto lock = std::lock_guard<std::recursive_mutex> {__debug_mutex__};
      listener->trace_event(trace_event_cache(), assembly::get_executing_assembly().name_or_file_name(), trace_event_type, 0, message);
    } else
      listener->trace_event(trace_event_cache(), assembly::get_executing_assembly().name_or_file_name(), trace_event_type, 0, message);
  }
  if (auto_flush_) flush();
}

auto trace::write_(const string& message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      auto lock = std::lock_guard<std::recursive_mutex> {__debug_mutex__};
      listener->write(message);
    } else
      listener->write(message);
  }
  if (auto_flush_) flush();
}

auto trace::write_(const string& message, const string& category) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      auto lock = std::lock_guard<std::recursive_mutex> {__debug_mutex__};
      listener->write(message, category);
    } else
      listener->write(message, category);
  }
  if (auto_flush_) flush();
}

auto trace::write_line_(const string& message) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      auto lock = std::lock_guard<std::recursive_mutex> {__debug_mutex__};
      listener->write_line(message);
    } else
      listener->write_line(message);
  }
  if (auto_flush_) flush();
}

auto trace::write_line_(const string& message, const string& category) -> void {
  for (auto listener : listeners()) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      auto lock = std::lock_guard<std::recursive_mutex> {__debug_mutex__};
      listener->write_line(message, category);
    } else
      listener->write_line(message, category);
  }
  if (auto_flush_) flush();
}
