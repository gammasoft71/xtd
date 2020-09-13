#include "../../../include/xtd/drawing/rectangle_f.h"

using namespace xtd::drawing;

const rectangle_f rectangle_f::empty;

rectangle_f rectangle_f::make_intersect(const rectangle_f& a, const rectangle_f& b) {
  float x1 = std::max(a.x(), b.x());
  float x2 = std::min(a.x() + a.width(), b.x() + b.width());
  float y1 = std::max(a.y(), b.y());
  float y2 = std::min(a.y() + a.height(), b.y() + b.height());
  
  if (x2 >= x1 && y2 >= y1) return rectangle_f(x1, y1, x2 - x1, y2 - y1);
  return rectangle_f::empty;
}

rectangle_f rectangle_f::make_union(const rectangle_f& a, const rectangle_f& b) {
  float x1 = std::min(a.x(), b.x());
  float x2 = std::max(a.x() + a.width(), b.x() + b.width());
  float y1 = std::min(a.y(), b.y());
  float y2 = std::max(a.y() + a.height(), b.y() + b.height());
  
  return rectangle_f(x1, y1, x2 - x1, y2 - y1);
}
