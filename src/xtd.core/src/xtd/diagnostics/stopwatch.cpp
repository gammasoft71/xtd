#include "../../../include/xtd/diagnostics/stopwatch.h"

using namespace xtd;
using namespace xtd::diagnostics;

int64_t stopwatch::frequency() {
  return std::nano::den;
}

bool stopwatch::is_high_resolution() {
  return true;
}

std::chrono::nanoseconds stopwatch::elapsed() const {
  return std::chrono::nanoseconds(elapsed_nanoseconds());
}

int64_t stopwatch::elapsed_milliseconds() const {
  return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed()).count();
}

int64_t stopwatch::elapsed_nanoseconds() const {
  if (running_) return get_timestamp() - start_;
  return stop_ - start_;
}

int64_t stopwatch::elapsed_ticks() const {
  return std::chrono::duration_cast<ticks>(elapsed()).count();
}

bool stopwatch::is_running() const {
  return running_;
}

int64_t stopwatch::get_timestamp() {
  return std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

void stopwatch::reset() {
  start_ = stop_ = 0;
  running_ = false;
}

void stopwatch::restart() {
  reset();
  start();
}

void stopwatch::start() {
  if (running_) return;
  start_ = get_timestamp() - (stop_ - start_);
  running_ = true;
}

stopwatch stopwatch::start_new() {
  return stopwatch(true);
}

void stopwatch::stop() {
  if (!running_) return;
  stop_ = get_timestamp();
  running_ = false;
}

stopwatch::stopwatch(bool start) {
  if (start) this->start();
}
