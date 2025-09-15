#include "../../../include/xtd/diagnostics/trace.hpp"
#include "../../../include/xtd/diagnostics/debugger.hpp"
#include "../../../include/xtd/diagnostics/default_trace_listener.hpp"
#include "../../../include/xtd/reflection/assembly.hpp"
#include "../../../include/xtd/lock.hpp"
#include <mutex>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::reflection;

extern std::recursive_mutex __debug_mutex__;
extern trace_listener_collection __listeners__;

trace_listener_collection& trace::listeners_ = __listeners__;
string trace::source_name_ = assembly::get_executing_assembly().location();

bool trace::auto_flush() noexcept {
  return auto_flush_;
}

void trace::auto_flush(bool auto_flush) noexcept {
  auto_flush_ = auto_flush;
}

uint32 trace::indent_level() noexcept {
  return indent_level_;
}

void trace::indent_level(uint32 indent_level) noexcept {
  indent_level_ = indent_level;
}

uint32 trace::indent_size() noexcept {
  return indent_size_;
}

void trace::indent_size(uint32 indent_size) noexcept {
  indent_size_ = indent_size;
}

trace_listener_collection& trace::listeners() noexcept {
  return listeners_;
}

void trace::listeners(const trace_listener_collection& listeners) noexcept {
  listeners_ = listeners;
}

bool trace::show_assert_dialog() noexcept {
  return debug::internal_show_assert_dialog();
}

void trace::show_assert_dialog(bool show_assert_dialog) noexcept {
  for (auto listener : listeners())
    if (is<default_trace_listener>(listener))
      as<default_trace_listener>(listener)->assert_ui_enabled(show_assert_dialog);
}

bool trace::use_global_lock() noexcept {
  return use_global_lock_;
}

void trace::use_global_lock(bool use_global_lock) noexcept {
  use_global_lock_ = use_global_lock;
}

void trace::cassert(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(stack_frame, condition, string::empty_string)) __xtd_debugbreak();
}

void trace::cassert(bool condition, const string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(stack_frame, condition, message)) __xtd_debugbreak();
}

void trace::cassert(bool condition, const string& message, const string& detail_message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(stack_frame, condition, message, detail_message)) __xtd_debugbreak();
}

void trace::indent() noexcept {
  indent_level(indent_level() + 1);
}

void trace::unindent() noexcept {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}

void trace::fail__(const string& message) {
  for (auto listener : listeners_) {
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

void trace::fail__(const string& message, const string& detail_message) {
  for (auto listener : listeners_) {
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

void trace::flush_() {
  for (auto listener : listeners_)
    listener->flush();
}

void trace::trace_event_(trace_event_type trace_event_type, const string& message) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      auto lock = std::lock_guard<std::recursive_mutex> {__debug_mutex__};
      listener->trace_event(trace_event_cache(), source_name_, trace_event_type, 0, message);
    } else
      listener->trace_event(trace_event_cache(), source_name_, trace_event_type, 0, message);
  }
  if (auto_flush_) flush();
}

void trace::write_(const string& message) {
  for (auto listener : listeners_) {
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

void trace::write_(const string& message, const string& category) {
  for (auto listener : listeners_) {
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

void trace::write_line_(const string& message) {
  for (auto listener : listeners_) {
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

void trace::write_line_(const string& message, const string& category) {
  for (auto listener : listeners_) {
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
