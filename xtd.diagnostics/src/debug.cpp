#include <cassert>

void __assert__(bool condition) {
  assert(condition);
}

#include "../include/xtd/diagnostics/debug.hpp"
#include "../include/xtd/diagnostics/default_trace_listener.hpp"

xtd::diagnostics::trace_listener_collection __listeners__ {std::make_shared<xtd::diagnostics::default_trace_listener>()};

bool xtd::diagnostics::debug::auto_flush_ = false;
unsigned int xtd::diagnostics::debug::indent_level_ = 0;
unsigned int xtd::diagnostics::debug::indent_size_ = 4;
xtd::diagnostics::trace_listener_collection& xtd::diagnostics::debug::listeners_ = __listeners__;
bool xtd::diagnostics::debug::use_global_lock_ = true;
std::mutex xtd::diagnostics::debug::global_lock_;
