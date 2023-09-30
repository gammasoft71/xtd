#include "../../../include/xtd/forms/selection_range.h"

using namespace xtd;
using namespace xtd::forms;

selection_range::selection_range(date_time start, date_time end) : start_(start), end_(end) {
  if (start_ > end_) start_ = end_;
}

date_time selection_range::end() const noexcept {
  return end_;
}

selection_range& selection_range::end(date_time value) {
  end_ = value;
  return *this;
}

date_time selection_range::start() const noexcept {
  return start_;
}

selection_range& selection_range::start(date_time value) {
  start_ = value;
  return *this;
}

ustring selection_range::to_string() const noexcept {
  return ustring::format("selection_range: start: {0:d} {0:t}, end: {1:d} {1:t}", start_, end_);
}
