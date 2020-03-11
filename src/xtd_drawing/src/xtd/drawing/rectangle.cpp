#include <cmath>
#include "../../../include/xtd/drawing/rectangle.h"

using namespace xtd::drawing;

const rectangle rectangle::empty;

rectangle rectangle::make_intersect(const rectangle& a, const rectangle& b) {
  int x1 = std::max(a.x(), b.x());
  int x2 = std::min(a.x() + a.width(), b.x() + b.width());
  int y1 = std::max(a.y(), b.y());
  int y2 = std::min(a.y() + a.height(), b.y() + b.height());
  
  if (x2 >= x1 && y2 >= y1) return rectangle(x1, y1, x2 - x1, y2 - y1);
  return rectangle::empty;
}

rectangle rectangle::make_union(const rectangle& a, const rectangle& b) {
  int32_t x1 = std::min(a.x(), b.x());
  int32_t x2 = std::max(a.x() + a.width(), b.x() + b.width());
  int32_t y1 = std::min(a.y(), b.y());
  int32_t y2 = std::max(a.y() + a.height(), b.y() + b.height());
  
  return rectangle(x1, y1, x2 - x1, y2 - y1);
}
