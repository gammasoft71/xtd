#include "../../include/xtd/signal_cancel_event_args"

using namespace xtd;

signal_cancel_event_args::signal_cancel_event_args(xtd::signal signal) : signal_(signal) {
}

bool signal_cancel_event_args::cancel() const noexcept {
  return cancel_;
}

void signal_cancel_event_args::cancel(bool cancel) {
  cancel_ = cancel;
}

xtd::signal signal_cancel_event_args::signal() const noexcept {
  return signal_;
}
