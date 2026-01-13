#include "../../../include/xtd/diagnostics/trace_source.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

trace_source::trace_source(const string& name) : name_(name) {
}

trace_source::trace_source::trace_source(const string& name, xtd::diagnostics::source_levels default_levels) : name_(name), switch_levels_(default_levels) {
  source_switch_.level(switch_levels_);
}

auto trace_source::listeners() noexcept -> trace_listener_collection& {
  return listeners_;
}

auto trace_source::listeners(const trace_listener_collection& listeners) noexcept -> void {
  listeners_ = listeners;
}

auto trace_source::name() const noexcept -> const string& {
  return name_;
}

auto trace_source::source_switch() const noexcept -> const class source_switch& {
  return source_switch_;
}

auto trace_source::source_switch(const class source_switch& source_switch) noexcept -> void {
  source_switch_ = source_switch;
}

auto trace_source::close() -> void {
  for (auto listener : listeners_)
    listener->close();
}

auto trace_source::flush() -> void {
  for (auto listener : listeners_)
    listener->flush();
}

auto trace_source::trace_information(const string& message) -> void {
  trace_event(trace_event_type::information, 0, message);
}
