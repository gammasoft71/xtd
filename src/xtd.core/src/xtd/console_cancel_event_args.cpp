#include "../../include/xtd/console_cancel_event_args.h"

using namespace xtd;

console_cancel_event_args::console_cancel_event_args(bool cancel, console_special_key special_key) : cancel_(cancel), special_key_(special_key) {
}

bool console_cancel_event_args::cancel() const noexcept {
  return cancel_;
}

void console_cancel_event_args::cancel(bool cancel) {
  cancel_ = cancel;
}

console_special_key console_cancel_event_args::special_key() const noexcept {
  return special_key_;
}
