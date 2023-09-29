#include "../../../include/xtd/diagnostics/stopwatch.h"

using namespace xtd;
using namespace xtd::diagnostics;

using stopwatch_clock_t = std::chrono::steady_clock;

int64 stopwatch::frequency() noexcept {
  return std::nano::den;
}

bool stopwatch::is_high_resolution() noexcept {
  return true;
}

time_span stopwatch::elapsed() const noexcept {
  return time_span::from_nanoseconds(std::chrono::nanoseconds {elapsed_nanoseconds()});
}

int64 stopwatch::elapsed_milliseconds() const noexcept {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::nanoseconds {elapsed_nanoseconds()}).count();
}

int64 stopwatch::elapsed_nanoseconds() const noexcept {
  if (running_) return get_timestamp_nanoseconds() - start_;
  return stop_ - start_;
}

int64 stopwatch::elapsed_ticks() const noexcept {
  return elapsed().ticks();
}

bool stopwatch::is_running() const noexcept {
  return running_;
}

std::chrono::nanoseconds stopwatch::get_timestamp() noexcept {
  return std::chrono::nanoseconds(stopwatch_clock_t::now().time_since_epoch());
}

int64 stopwatch::get_timestamp_milliseconds() noexcept {
  return std::chrono::duration_cast<std::chrono::milliseconds>(get_timestamp()).count();
}

int64 stopwatch::get_timestamp_nanoseconds() noexcept {
  return get_timestamp().count();
}

int64 stopwatch::get_timestamp_ticks() noexcept {
  return std::chrono::duration_cast<xtd::ticks>(get_timestamp()).count();
}

void stopwatch::reset() noexcept {
  start_ = stop_ = 0;
  running_ = false;
}

void stopwatch::restart() noexcept {
  reset();
  start();
}

void stopwatch::start() noexcept {
  if (running_) return;
  start_ = get_timestamp_nanoseconds() - (stop_ - start_);
  running_ = true;
}

stopwatch stopwatch::start_new() noexcept {
  return stopwatch(true);
}

void stopwatch::stop() noexcept {
  if (!running_) return;
  stop_ = get_timestamp_nanoseconds();
  running_ = false;
}

stopwatch::stopwatch(bool start) {
  if (start) this->start();
}
