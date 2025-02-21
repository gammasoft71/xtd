#include "../../../include/xtd/drawing/rectangle.hpp"
#include <xtd/as>
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;

const rectangle rectangle::empty;

rectangle::rectangle(int32 x, int32 y, int32 width, int32 height) noexcept : x(x), y(y), width(width), height(height) {
}

rectangle::rectangle(const point& location, const drawing::size& size) noexcept : rectangle(location.x, location.y, size.width, size.height) {
}

rectangle::operator rectangle_f() const noexcept {
  return rectangle_f(as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

int32 rectangle::bottom() const noexcept {
  return y + height;
}

point rectangle::center() const noexcept {
  return {x + width / 2, y + height / 2};
}

bool rectangle::is_empty() const noexcept {
  return *this == rectangle::empty;
}

int32 rectangle::left() const noexcept {
  return x;
}

point rectangle::location() const noexcept {
  return {x, y};
}

void rectangle::location(const point& value) noexcept {
  x = value.x;
  y = value.y;
}

int32 rectangle::right() const noexcept {
  return x + width;
}

drawing::size rectangle::size() const noexcept {
  return {width, height};
}

void rectangle::size(const xtd::drawing::size& value) noexcept {
  width = value.width;
  height = value.height;
}

int32 rectangle::top() const noexcept {
  return y;
}

void rectangle::add(const drawing::size& sz) noexcept {
  add(sz.width, sz.height);
}

void rectangle::add(int32 width, int32 height) noexcept {
  this->width += width;
  this->height += height;
}

bool rectangle::contains(const point& pt) const noexcept {
  return contains(pt.x, pt.y);
}

bool rectangle::contains(const rectangle& rect) const noexcept {
  return x <= rect.x && (rect.x + rect.width) <= (x + width) && y <= rect.y && (rect.y + rect.height) <= (y + height);
}

bool rectangle::contains(int32 x, int32 y) const noexcept {
  return this->x <= x && x < this->x + width && this->y <= y && y < this->y + height;
}

bool rectangle::equals(const object& obj) const noexcept {
  return is<rectangle>(obj) && equals(static_cast<const rectangle&>(obj));
}

bool rectangle::equals(const rectangle& other) const noexcept {
  return x == other.x && y == other.y && width == other.width && height == other.height;
}

xtd::size rectangle::get_hash_code() const noexcept {
  return hash_code::combine(x, y, width, height);
}

void rectangle::inflate(const drawing::size& sz) noexcept {
  inflate(sz.width, sz.height);
}

void rectangle::inflate(int32 width, int32 height) noexcept {
  x -= width;
  y -= height;
  this->width += 2 * width;
  this->height += 2 * height;
}

bool rectangle::intersects_with(const rectangle& rect) const noexcept {
  return (rect.x < x + width) && (x < (rect.x + rect.width)) && (rect.y < y + height) && (y < rect.y + rect.height);
}

void rectangle::make_intersect(const rectangle& rect) noexcept {
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

void rectangle::make_union(const rectangle& rect) noexcept {
  auto x1 = math::min(x, rect.x);
  auto x2 = math::max(x + width, rect.x + rect.width);
  auto y1 = math::min(y, rect.y);
  auto y2 = math::max(y + height, rect.y + rect.height);
  
  x = x1;
  y = y1;
  width = x2 - x1;
  height = y2 - y1;
}

void rectangle::offset(const point& pos) noexcept {
  offset(pos.x, pos.y);
}

void rectangle::offset(int32 dx, int32 dy) noexcept {
  x += dx;
  y += dy;
}

xtd::string rectangle::to_string() const noexcept {
  return string::format("{{x={}, y={}, width={}, heght={}}}", x, y, width, height);
}

rectangle rectangle::add(const rectangle& rect, int32 x, int32 y) noexcept {
  auto result = rect;
  result.add(x, y);
  return result;
}

rectangle rectangle::add(const rectangle& rect, const drawing::size& sz) noexcept {
  return add(rect, sz.width, sz.height);
}

rectangle rectangle::ceiling(const rectangle_f& rect) noexcept {
  return rectangle(as<int32>(math::ceiling(rect.x)), as<int32>(math::ceiling(rect.y)), as<int32>(math::ceiling(rect.width)), as<int32>(math::ceiling(rect.height)));
}

rectangle rectangle::from_ltrb(int32 left, int32 top, int32 right, int32 bottom) noexcept {
  return rectangle(left, top, right - left, bottom - top);
}

rectangle rectangle::inflate(const rectangle& rect, int32 x, int32 y) noexcept {
  auto result = rect;
  result.inflate(x, y);
  return result;
}

rectangle rectangle::inflate(const rectangle& rect, const drawing::size& sz) noexcept {
  return inflate(rect, sz.width, sz.height);
}

rectangle rectangle::make_intersect(const rectangle& a, const rectangle& b) noexcept {
  auto result = a;
  result.make_intersect(b);
  return result;
}

rectangle rectangle::make_union(const rectangle& a, const rectangle& b) noexcept {
  auto result = a;
  result.make_union(b);
  return result;
}

rectangle rectangle::offset(const rectangle& rect, const point& pos) noexcept {
  return offset(rect, pos.x, pos.y);
}

rectangle rectangle::offset(const rectangle& rect, int32 x, int32 y) noexcept {
  auto result = rect;
  result.offset(x, y);
  return result;
}

rectangle rectangle::round(const rectangle_f& rect) noexcept {
  return rectangle(as<int32>(math::round(rect.x)), as<int32>(math::round(rect.y)), as<int32>(math::round(rect.width)), as<int32>(math::round(rect.height)));
}

rectangle rectangle::truncate(const rectangle_f& rect) noexcept {
  return rectangle(as<int32>(math::truncate(rect.x)), as<int32>(math::truncate(rect.y)), as<int32>(math::truncate(rect.width)), as<int32>(math::truncate(rect.height)));
}
