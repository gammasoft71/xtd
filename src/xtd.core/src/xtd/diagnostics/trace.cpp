#include "../../../include/xtd/diagnostics/trace.h"
#include "../../../include/xtd/diagnostics/debugger.h"
#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/lock.h"
#include <mutex>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

extern std::recursive_mutex __debug_mutex__;
extern trace_listener_collection __listeners__;
extern bool __show_assert_dialog__;

trace_listener_collection& trace::listeners_ = __listeners__;
bool& trace::show_assert_dialog_ = __show_assert_dialog__;
ustring trace::source_name_ = environment::get_command_line_args().size() == 0 ? "(unknown)" : environment::get_command_line_args()[0];

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
  return show_assert_dialog_;
}

void trace::show_assert_dialog(bool show_assert_dialog) noexcept {
  show_assert_dialog_ = show_assert_dialog;
}

bool trace::use_global_lock() noexcept {
  return use_global_lock_;
}

void trace::use_global_lock(bool use_global_lock) noexcept {
  use_global_lock_ = use_global_lock;
}

void trace::cassert(bool condition) {
  if (__should_aborted__(condition, "", csf_)) __std_abort();
}

void trace::cassert(bool condition, const ustring& message) {
  if (__should_aborted__(condition, message, csf_)) __std_abort();
}

void trace::cassert(bool condition, const ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(condition, message, stack_frame)) __std_abort();
}

void trace::cassert(bool condition, const ustring& message, const ustring& detail_message) {
  if (__should_aborted__(condition, message, detail_message, csf_)) __std_abort();
}

void trace::cassert(bool condition, const ustring& message, const ustring& detail_message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(condition, message, detail_message, stack_frame)) __std_abort();
}

void trace::cassert(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(condition, "", stack_frame)) __std_abort();
}

void trace::indent() noexcept {
  indent_level(indent_level() + 1);
}

void trace::unindent() noexcept {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}

void trace::fail__(const ustring& message) {
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

void trace::fail__(const ustring& message, const ustring& detail_message) {
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

void trace::trace_event_(trace_event_type trace_event_type, const ustring& message) {
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

void trace::write_(const ustring& message) {
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

void trace::write_(const ustring& message, const ustring& category) {
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

void trace::write_line_(const ustring& message) {
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

void trace::write_line_(const ustring& message, const ustring& category) {
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
