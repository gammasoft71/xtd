#include "../../../include/xtd/diagnostics/debug.h"
#include "../../../include/xtd/diagnostics/debug_break.h"
#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/literals.h"
#include "../../../include/xtd/lock.h"
#include <mutex>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

extern char** __diagnostics_argv;
auto __debug_mutex__ = recursive_mutex {};
auto __listeners__ = trace_listener_collection {make_shared<default_trace_listener>()};
auto __debug_use_debug_global_lock__ = true;

trace_listener_collection& debug::listeners_ = __listeners__;
ustring debug::source_name_ = environment::get_command_line_args().size() == 0 ? "(unknown)" : environment::get_command_line_args()[0];

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

trace_listener_collection& debug::listeners() noexcept {
  return listeners_;
}

void debug::listeners(const trace_listener_collection& listeners) noexcept {
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

void debug::cassert(bool condition) {
  if (__should_aborted__(condition, ustring::empty_string, csf_)) debug_break_();
}

void debug::cassert(bool condition, const ustring& message) {
  if (__should_aborted__(condition, message, csf_)) debug_break_();
}

void debug::cassert(bool condition, const ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(condition, message, stack_frame)) debug_break_();
}

void debug::cassert(bool condition, const ustring& message, const ustring& detail_message) {
  if (__should_aborted__(condition, message, detail_message, csf_)) debug_break_();
}

void debug::cassert(bool condition, const ustring& message, const ustring& detail_message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(condition, message, detail_message, stack_frame)) debug_break_();
}

void debug::cassert(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {
  if (__should_aborted__(condition, ustring::empty_string, stack_frame)) debug_break_();
}

void debug::indent() noexcept {
  indent_level(indent_level() + 1);
}

void debug::unindent() noexcept {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}

void debug::fail__(const ustring& message) {
  for (auto listener : listeners_) {
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

void debug::fail__(const ustring& message, const ustring& detail_message) {
  for (auto listener : listeners_) {
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
  for (auto listener : listeners_)
    listener->flush();
}

void debug::trace_event_(trace_event_type trace_event_type, const ustring& message) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && __debug_use_debug_global_lock__) {
      std::lock_guard<std::recursive_mutex> lock {__debug_mutex__};
      listener->trace_event(trace_event_cache(), source_name_, trace_event_type, 0, message);
    } else
      listener->trace_event(trace_event_cache(), source_name_, trace_event_type, 0, message);
  }
  if (auto_flush_) flush();
}

void debug::write_(const ustring& message) {
  for (auto listener : listeners_) {
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

void debug::write_(const ustring& message, const ustring& category) {
  for (auto listener : listeners_) {
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

void debug::write_line_(const ustring& message) {
  for (auto listener : listeners_) {
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

void debug::write_line_(const ustring& message, const ustring& category) {
  for (auto listener : listeners_) {
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

xtd::diagnostics::assert_dialog_result debug::assert_dialog(bool condition, const ustring& message, const ustring& detail_message, const stack_frame& stack_frame) {
  if (condition == true) return assert_dialog_result::ignore;
  write_line("---- DEBUG ASSERTION FAILED ----");
  write_line("---- Assert Short Message----");
  write_line(message);
  write_line("---- Assert Long Message----");
  write_line(detail_message);
  write_line(stack_trace(stack_frame).to_string());
  write_line("");
  return internal_show_assert_dialog() ? static_cast<xtd::diagnostics::assert_dialog_result>(native::debugger::show_assert_dialog(ustring::format("{}\n{}\n{}", message, detail_message, stack_trace(stack_frame)), assert_dialog_caption())) : assert_dialog_result::retry;
}

xtd::ustring debug::assert_dialog_caption() {
  return "Assertion Failed: Abort=Quit, Retry=Debug, Ignore=Continue"_t;
}

bool debug::internal_show_assert_dialog() noexcept {
  for (auto listener : listeners())
    if (is<default_trace_listener>(listener) && as<default_trace_listener>(listener)->assert_ui_enabled())
      return true;
  return false;;
}
