#include <cassert>
void __assert__(bool condition) {assert(condition);}

#include "../../../include/xtd/diagnostics/trace.h"
#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#include "../../../include/xtd/environment.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

trace_listener_collection __listeners__ {std::make_shared<xtd::diagnostics::default_trace_listener>()};

trace_listener_collection& trace::listeners_ = __listeners__;
mutex trace::global_lock_;
string trace::source_name_ = environment::get_command_line_args().size() == 0 ? "(unknown)" : environment::get_command_line_args()[0];

bool trace::auto_flush() {
  return auto_flush_;
}

void trace::auto_flush(bool auto_flush) {
  auto_flush_ = auto_flush;
}

uint32_t trace::indent_level() {
  return indent_level_;
}

void trace::indent_level(uint32_t indent_level) {
  indent_level_ = indent_level;
}

uint32_t trace::indent_size() {
  return indent_size_;
}

void trace::indent_size(uint32_t indent_size) {
  indent_size_ = indent_size;
}

trace_listener_collection& trace::listeners() {
  return listeners_;
}

void trace::listeners(const trace_listener_collection& listeners) {
  listeners_ = listeners;
}

bool trace::use_global_lock() {
  return use_global_lock_;
}

void trace::use_global_lock(bool use_global_lock) {
  use_global_lock_ = use_global_lock;
}

void trace::indent() {
  indent_level(indent_level() + 1);
}

void trace::trace_error(const std::string& message) {
  trace_event(trace_event_type::error, message);
}

void trace::trace_warning(const std::string& message) {
  trace_event(trace_event_type::warning, message);
}

void trace::unindent() {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}
