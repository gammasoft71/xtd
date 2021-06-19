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
extern char** __diagnostics_argv;

void __assert__(bool condition);

trace_listener_collection& debug::listeners_ = __listeners__;
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

void debug::assert_(bool condition, const std::string& message) {
  native::debug::assert_message_box(condition, message);
  if (!condition) fail(message);
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
