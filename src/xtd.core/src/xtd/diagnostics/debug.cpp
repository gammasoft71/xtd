#include <cassert>

#include "../../../include/xtd/diagnostics/debug.h"
#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#include "../../../include/xtd/environment.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

extern trace_listener_collection __listeners__;
extern char** __diagnostics_argv;

trace_listener_collection& debug::listeners_ = __listeners__;
mutex debug::global_lock_;
string debug::source_name_ = environment::get_command_line_args().size() == 0 ? "(unknown)" : environment::get_command_line_args()[0];

bool debug::auto_flush() {
  return auto_flush_;
}

void debug::auto_flush(bool auto_flush) {
  auto_flush_ = auto_flush;
}

unsigned int debug::indent_level() {
  return indent_level_;
}

void debug::indent_level(unsigned int indent_level) {
  indent_level_ = indent_level;
}

unsigned int debug::indent_size() {
  return indent_size_;
}

void debug::indent_size(unsigned int indent_size) {
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

void debug::trace_error(const std::string& message) {
  trace_event(trace_event_type::error, message);
}

void debug::trace_information(const std::string& message) {
  trace_event(trace_event_type::information, message);
}

void debug::trace_warning(const std::string& message) {
  trace_event(trace_event_type::warning, message);
}

void debug::unindent() {
  if (indent_level() != 0) indent_level(indent_level() - 1);
}
