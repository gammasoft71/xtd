#include "../../../include/xtd/diagnostics/ostream_trace_listener.hpp"

using namespace xtd::diagnostics;

ostream_trace_listener::ostream_trace_listener(const std::ostream& ostream) {
  this->ostream(ostream);
}

ostream_trace_listener::~ostream_trace_listener() {
  flush();
}

auto ostream_trace_listener::ostream() const -> const std::ostream& {
  return ostream_;
}

auto ostream_trace_listener::ostream(const std::ostream& ostream) -> void {
  ostream_.rdbuf(ostream.rdbuf());
}

auto ostream_trace_listener::close() -> void {
}

auto ostream_trace_listener::flush_() -> void {
  if (ostream_.good()) ostream_ << std::flush;
}

auto ostream_trace_listener::write_(const string& message) -> void {
  if (need_indent()) write_indent();
  if (ostream_.good()) ostream_ << message;
}

auto ostream_trace_listener::write_line_(const string& message) -> void {
  write(message + "\n");
  need_indent(true);
}
