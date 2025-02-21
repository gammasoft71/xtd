#include "../../../include/xtd/drawing/rectangle_f.hpp"
#include <xtd/math>
#include <xtd/string>

using namespace xtd::drawing;

const rectangle_f rectangle_f::empty;

rectangle_f::rectangle_f(float x, float y, float width, float height) noexcept  : x(x), y(y), width(width), height(height) {
}

rectangle_f::rectangle_f(const point_f& location, const size_f& size) noexcept  : rectangle_f(location.x, location.y, size.width, size.height) {
}

float rectangle_f::bottom() const noexcept {
  return y + height;
}

point_f rectangle_f::center() const noexcept {
  return {x + width / 2, y + height / 2};
}

bool rectangle_f::is_empty() const noexcept {
  return *this == rectangle_f::empty;
}

float rectangle_f::left() const noexcept {
  return x;
}

point_f rectangle_f::location() const noexcept {
  return {x, y};
}

void rectangle_f::location(const point_f& location) {
  x = location.x;
  y = location.y;
}

float rectangle_f::right() const noexcept {
  return x + width;
}

size_f rectangle_f::size() const noexcept {
  return {width, height};
}

void rectangle_f::size(const size_f& size) noexcept {
  width = size.width;
  height = size.height;
}

float rectangle_f::top() const noexcept {
  return y;
}

void rectangle_f::add(const drawing::size_f& sz) noexcept {
  add(sz.width, sz.height);
}

void rectangle_f::add(float width, float height) noexcept {
  this->width += width;
  this->height += height;
}

bool rectangle_f::contains(const point_f& pt) const noexcept {
  return contains(pt.x, pt.y);
}

bool rectangle_f::contains(const rectangle_f& rect) const noexcept {
  return x <= rect.x && (rect.x + rect.width) <= (x + width) && y <= rect.y && (rect.y + rect.height) <= (y + height);
}

bool rectangle_f::contains(float x, float y) const noexcept {
  return this->x <= x && x < this->x + width && this->y <= y && y < this->y + height;
}

bool rectangle_f::equals(const object& obj) const noexcept {
  return is<rectangle_f>(obj) && equals(static_cast<const rectangle_f&>(obj));
}

bool rectangle_f::equals(const rectangle_f& value) const noexcept {
  return x == value.x && y == value.y && width == value.width && height == value.height;
}

xtd::size rectangle_f::get_hash_code() const noexcept {
  return hash_code::combine(x, y, width, height);
}

void rectangle_f::inflate(const drawing::size_f& sz) noexcept {
  inflate(sz.width, sz.height);
}

void rectangle_f::inflate(float width, float height) noexcept {
  x -= width;
  y -= height;
  this->width += 2 * width;
  this->height += 2 * height;
}

bool rectangle_f::intersects_with(const rectangle_f& rect) const noexcept {
  return (rect.x < x + width) && (x < (rect.x + rect.width)) && (rect.y < y + height) && (y < rect.y + rect.height);
}

void rectangle_f::make_intersect(const rectangle_f& rect) noexcept {
  auto x1 = math::max(x, rect.x);
  auto x2 = math::min(x + width, rect.x + rect.width);
  auto y1 = math::max(y, rect.y);
  auto y2 = math::min(y + height, rect.y + rect.height);
  
  if (x2 < x1 || y2 < y1) x = y = width = height = 0;
  else {
    x = x1;
    y = y1;
    width = x2 - x1;
    height = y2 - y1;
  }
}

void rectangle_f::make_union(const rectangle_f& rect) noexcept {
  auto x1 = math::min(x, rect.x);
  auto x2 = math::max(x + width, rect.x + rect.width);
  auto y1 = math::min(y, rect.y);
  auto y2 = math::max(y + height, rect.y + rect.height);
  
  x = x1;
  y = y1;
  width = x2 - x1;
  height = y2 - y1;
}

void rectangle_f::offset(const point_f& pos) noexcept {
  offset(pos.x, pos.y);
}

void rectangle_f::offset(float dx, float dy) noexcept {
  x += dx;
  y += dy;
}

xtd::string rectangle_f::to_string() const noexcept {
  return string::format("{{x={}, y={}, width={}, heght={}}}", x, y, width, height);
}

rectangle_f rectangle_f::add(const rectangle_f& rect, float x, float y) noexcept {
  auto result = rect;
  result.add(x, y);
  return result;
}

rectangle_f rectangle_f::add(const rectangle_f& rect, const size_f& sz) noexcept {
  return add(rect, sz.width, sz.height);
}

rectangle_f rectangle_f::from_ltrb(float left, float top, float right, float bottom) noexcept {
  return rectangle_f(left, top, right - left, bottom - top);
}

rectangle_f rectangle_f::inflate(const rectangle_f& rect, const drawing::size_f& sz) noexcept {
  return inflate(rect, sz.width, sz.height);
}

rectangle_f rectangle_f::inflate(const rectangle_f& rect, float width, float height) noexcept {
  auto result = rect;
  result.inflate(width, height);
  return result;
}

rectangle_f rectangle_f::make_intersect(const rectangle_f& a, const rectangle_f& b) noexcept {
  auto result = a;
  result.make_intersect(b);
  return result;
}

rectangle_f rectangle_f::make_union(const rectangle_f& a, const rectangle_f& b) noexcept {
  auto result = a;
  result.make_union(b);
  return result;
}

rectangle_f rectangle_f::offset(const rectangle_f& rect, const point_f& pos) noexcept {
  return offset(rect, pos.x, pos.y);
}

rectangle_f rectangle_f::offset(const rectangle_f& rect, float x, float y) noexcept {
  auto result = rect;
  result.offset(x, y);
  return result;
}
