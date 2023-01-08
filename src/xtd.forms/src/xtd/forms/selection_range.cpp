#include "../../../include/xtd/forms/selection_range.h"

using namespace xtd;
using namespace xtd::forms;

selection_range::selection_range(date_time start, date_time end) : start_(start), end_(end) {
  if (start_ > end_) start_ = end_;
}

date_time selection_range::end() const noexcept {
  return end_;
}

void selection_range::end(date_time value) {
  end_ = value;
}

date_time selection_range::start() const noexcept {
  return start_;
}

void selection_range::start(date_time value) {
  start_ = value;
}
