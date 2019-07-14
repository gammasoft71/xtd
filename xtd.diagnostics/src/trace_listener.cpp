#include "../include/xtd/diagnostics/trace_listener.hpp"

xtd::diagnostics::trace_listener::trace_listener(const std::string& name) {
  this->data_->name_ = name;
}

void xtd::diagnostics::trace_listener::trace_listener::close() {
  this->flush();
}

void xtd::diagnostics::trace_listener::trace_listener::flush() {
}
