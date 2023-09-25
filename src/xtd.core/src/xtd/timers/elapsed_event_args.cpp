#include "../../../include/xtd/timers/elapsed_event_args"

using namespace xtd;
using namespace xtd::timers;

elapsed_event_args::elapsed_event_args(const xtd::date_time& signal_time) : signal_time_(signal_time) {
}

const xtd::date_time& elapsed_event_args::signal_time() const noexcept {
  return signal_time_;
}
