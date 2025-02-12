#include "../../../include/xtd/forms/selection_range.hpp"

using namespace xtd;
using namespace xtd::forms;

selection_range::selection_range(date_time start, date_time end) : end {end}, start {start} {
  if (this->start > this->end) this->start = this->end;
}

string selection_range::to_string() const noexcept {
  return string::format("selection_range: start: {0:d} {0:t}, end: {1:d} {1:t}", start, end);
}
