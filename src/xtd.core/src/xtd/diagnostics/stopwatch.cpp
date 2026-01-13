#include "../../../include/xtd/diagnostics/stopwatch.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

using stopwatch_clock_t = std::chrono::steady_clock;

auto stopwatch::frequency() noexcept -> int64 {
  return std::nano::den;
}

auto stopwatch::is_high_resolution() noexcept -> bool {
  return true;
}

auto stopwatch::elapsed() const noexcept -> time_span {
  return time_span::from_nanoseconds(std::chrono::nanoseconds {elapsed_nanoseconds()});
}

auto stopwatch::elapsed_milliseconds() const noexcept -> int64 {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::nanoseconds {elapsed_nanoseconds()}).count();
}

auto stopwatch::elapsed_nanoseconds() const noexcept -> int64 {
  if (running_) return get_timestamp_nanoseconds() - start_;
  return stop_ - start_;
}

auto stopwatch::elapsed_ticks() const noexcept -> int64 {
  return elapsed().ticks();
}

auto stopwatch::is_running() const noexcept -> bool {
  return running_;
}

auto stopwatch::get_timestamp() noexcept -> std::chrono::nanoseconds {
  return std::chrono::nanoseconds(stopwatch_clock_t::now().time_since_epoch());
}

auto stopwatch::get_timestamp_milliseconds() noexcept -> int64 {
  return std::chrono::duration_cast<std::chrono::milliseconds>(get_timestamp()).count();
}

auto stopwatch::get_timestamp_nanoseconds() noexcept -> int64 {
  return get_timestamp().count();
}

auto stopwatch::get_timestamp_ticks() noexcept -> int64 {
  return std::chrono::duration_cast<xtd::ticks>(get_timestamp()).count();
}

auto stopwatch::reset() noexcept -> void {
  start_ = stop_ = 0;
  running_ = false;
}

auto stopwatch::restart() noexcept -> void {
  reset();
  start();
}

auto stopwatch::start() noexcept -> void {
  if (running_) return;
  start_ = get_timestamp_nanoseconds() - (stop_ - start_);
  running_ = true;
}

auto stopwatch::start_new() noexcept -> stopwatch {
  return stopwatch(true);
}

auto stopwatch::stop() noexcept -> void {
  if (!running_) return;
  stop_ = get_timestamp_nanoseconds();
  running_ = false;
}

stopwatch::stopwatch(bool start) {
  if (start) this->start();
}
