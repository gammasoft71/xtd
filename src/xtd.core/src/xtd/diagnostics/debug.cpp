#include "../../../include/xtd/diagnostics/debug.h"
#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#include "../../../include/xtd/environment.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

extern trace_listener_collection __listeners__;
extern bool __show_assert_dialog__;
extern char** __diagnostics_argv;

trace_listener_collection& debug::listeners_ = __listeners__;
bool& debug::show_assert_dialog_ = __show_assert_dialog__;
mutex debug::global_lock_;
string debug::source_name_ = environment::get_command_line_args().size() == 0 ? "(unknown)" : environment::get_command_line_args()[0];

bool debug::auto_flush() {
  return auto_flush_;
}

void debug::auto_flush(bool auto_flush) {
  auto_flush_ = auto_flush;
}

uint32_t debug::indent_level() {
  return indent_level_;
}

void debug::indent_level(uint32_t indent_level) {
  indent_level_ = indent_level;
}

uint32_t debug::indent_size() {
  return indent_size_;
}

void debug::indent_size(uint32_t indent_size) {
  indent_size_ = indent_size;
}

trace_listener_collection& debug::listeners() {
  return listeners_;
}

void debug::listeners(const trace_listener_collection& listeners) {
  listeners_ = listeners;
}

bool debug::show_assert_dialog() {
  return show_assert_dialog_;
}

void debug::show_assert_dialog(bool show_assert_dialog) {
  show_assert_dialog_ = show_assert_dialog;
}

bool debug::use_global_lock() {
  return use_global_lock_;
}

void debug::use_global_lock(bool use_global_lock) {
  use_global_lock_ = use_global_lock;
}

void debug::indent() {
  indent_level(indent_level() + 1);
}

void debug::unindent() {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}

void debug::fail_(const std::string& message) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::mutex> lock(global_lock_);
      listener->fail(message);
    } else {
      listener->fail(message);
    }
  }
  if (auto_flush_) flush();
}

void debug::fail_(const std::string& message, const std::string& detail_message) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::mutex> lock(global_lock_);
      listener->fail(message, detail_message);
    } else {
      listener->fail(message, detail_message);
    }
  }
  if (auto_flush_) flush();
}

void debug::flush_() {
  for (auto listener : listeners_)
    listener->flush();
}

void debug::trace_event_(trace_event_type trace_event_type, const std::string& message) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::mutex> lock(global_lock_);
      listener->trace_event(trace_event_cache(), source_name_, trace_event_type, 0, message);
    } else {
      listener->trace_event(trace_event_cache(), source_name_, trace_event_type, 0, message);
    }
  }
  if (auto_flush_) flush();
}

void debug::write_(const std::string& message) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::mutex> lock(global_lock_);
      listener->write(message);
    } else {
      listener->write(message);
    }
  }
  if (auto_flush_) flush();
}

void debug::write_(const std::string& message, const std::string& category) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::mutex> lock(global_lock_);
      listener->write(message, category);
    } else {
      listener->write(message, category);
    }
  }
  if (auto_flush_) flush();
}

void debug::write_line_(const std::string& message) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::mutex> lock(global_lock_);
      listener->write_line(message);
    } else {
      listener->write_line(message);
    }
  }
  if (auto_flush_) flush();
}

void debug::write_line_(const std::string& message, const std::string& category) {
  for (auto listener : listeners_) {
    if (listener->indent_level() != indent_level_) listener->indent_level(indent_level_);
    if (listener->indent_size() != indent_size_) listener->indent_size(indent_size_);
    if (!listener->is_thread_safe() && use_global_lock_) {
      std::lock_guard<std::mutex> lock(global_lock_);
      listener->write_line(message, category);
    } else {
      listener->write_line(message, category);
    }
  }
  if (auto_flush_) flush();
}

xtd::diagnostics::assert_dialog_result debug::assert_dialog(bool condition, const std::string& message, const stack_frame& stack_frrame) {
  if (condition == true ) return assert_dialog_result::ignore;
  write_line("---- DEBUG ASSERTION FAILED ----");
  write_line("---- Assert Short Message----");
  write_line(message);
  write_line("---- Assert Long Message----");
  write_line("");
  write_line(stack_trace(stack_frrame).to_string());
  write_line("");
  return show_assert_dialog_ ? static_cast<xtd::diagnostics::assert_dialog_result>(native::debug::show_assert_dialog(strings::format("{}\n\n{}", message, stack_trace(stack_frrame)), "Assertion Failed: Abort=Quit, Retry=Debug, Ignore=Continue")) : assert_dialog_result::retry;
}
