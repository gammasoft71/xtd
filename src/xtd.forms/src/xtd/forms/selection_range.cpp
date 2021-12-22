#include "../../../include/xtd/forms/selection_range.h"

using namespace xtd;
using namespace xtd::forms;

selection_range::selection_range(date_time start, date_time end) : start_(start), end_(end) {
}

date_time selection_range::end() const {
  return end_;
}

void selection_range::end(date_time value) {
  end_ = value;
}

date_time selection_range::start() const {
  return start_;
}

void selection_range::start(date_time value) {
  start_ = value;
}
