#include "../../../include/xtd/diagnostics/trace_source.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

trace_source::trace_source(const string& name) : name_(name) {
}

trace_source::trace_source::trace_source(const string& name, xtd::diagnostics::source_levels default_levels) : name_(name), switch_levels_(default_levels) {
  source_switch_.level(switch_levels_);
}

xtd::diagnostics::trace_listener_collection& trace_source::listeners() noexcept {
  return listeners_;
}

void trace_source::listeners(const xtd::diagnostics::trace_listener_collection& listeners) noexcept {
  listeners_ = listeners;
}

const string& trace_source::name() const noexcept {
  return name_;
}

const xtd::diagnostics::source_switch& trace_source::source_switch() const noexcept {
  return source_switch_;
}

void trace_source::source_switch(const xtd::diagnostics::source_switch& source_switch) noexcept {
  source_switch_ = source_switch;
}

void trace_source::close() {
  for (auto listener : listeners_)
    listener->close();
}

void trace_source::flush() {
  for (auto listener : listeners_)
    listener->flush();
}

void trace_source::trace_information(const string& message) {
  trace_event(trace_event_type::information, 0, message);
}
