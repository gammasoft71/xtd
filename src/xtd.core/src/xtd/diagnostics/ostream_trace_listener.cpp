#include "../../../include/xtd/diagnostics/ostream_trace_listener.h"

using namespace std;
using namespace xtd::diagnostics;

ostream_trace_listener::ostream_trace_listener(const std::ostream& ostream) {
  this->ostream(ostream);
};

ostream_trace_listener::~ostream_trace_listener() {
  flush();
}

const ostream& ostream_trace_listener::ostream() const {
  return ostream_;
}

void ostream_trace_listener::ostream(const std::ostream& ostream) {
  ostream_.rdbuf(ostream.rdbuf());
}

void ostream_trace_listener::close() {
}

void ostream_trace_listener::flush_() {
  if (ostream_.good())
    ostream_ << std::flush;
}

void ostream_trace_listener::write_(const string& message) {
  if (need_indent())
    write_indent();
  if (ostream_.good())
    ostream_ << message;
}

void ostream_trace_listener::write_line_(const string& message) {
  write(message + "\n");
  need_indent(true);
}
