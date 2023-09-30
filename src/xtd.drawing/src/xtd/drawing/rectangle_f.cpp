#include "../../../include/xtd/drawing/rectangle_f.h"
#include <xtd/math>
#include <xtd/ustring>

using namespace xtd::drawing;

const rectangle_f rectangle_f::empty;

rectangle_f::rectangle_f(float x, float y, float width, float height) noexcept  : x_(x), y_(y), width_(width), height_(height) {
}

rectangle_f::rectangle_f(const point_f& location, const size_f& size) noexcept  : rectangle_f(location.x(), location.y(), size.width(), size.height()) {
}

float rectangle_f::bottom() const noexcept {
  return y_ + height_;
}

float rectangle_f::height() const noexcept {
  return height_;
}

void rectangle_f::height(float height) noexcept {
  height_ = height;
}

bool rectangle_f::is_empty() const noexcept {
  return *this == rectangle_f::empty;
}

float rectangle_f::left() const noexcept {
  return x_;
}

point_f rectangle_f::location() const noexcept {
  return {x_, y_};
}

void rectangle_f::location(const point_f& location) {
  x_ = location.x();
  y_ = location.y();
}

float rectangle_f::right() const noexcept {
  return x_ + width_;
}

size_f rectangle_f::size() const noexcept {
  return {width_, height_};
}

void rectangle_f::size(const size_f& size) noexcept {
  width_ = size.width();
  height_ = size.height();
}

float rectangle_f::top() const noexcept {
  return y_;
}

float rectangle_f::width() const noexcept {
  return width_;
}

void rectangle_f::width(float width) noexcept {
  width_ = width;
}

float rectangle_f::x() const noexcept {
  return x_;
}

void rectangle_f::x(float x) noexcept {
  x_ = x;
}

float rectangle_f::y() const noexcept {
  return y_;
}

void rectangle_f::y(float y) noexcept {
  y_ = y;
}

void rectangle_f::add(const drawing::size_f& sz) noexcept {
  add(sz.width(), sz.height());
}

void rectangle_f::add(float width, float height) noexcept {
  width_ += width;
  height_ += height;
}

rectangle_f rectangle_f::add(const rectangle_f& rect, float x, float y) noexcept {
  auto result = rect;
  result.add(x, y);
  return result;
}

rectangle_f rectangle_f::add(const rectangle_f& rect, const size_f& sz) noexcept {
  return add(rect, sz.width(), sz.height());
}

bool rectangle_f::contains(const point_f& pt) const noexcept {
  return contains(pt.x(), pt.y());
}

bool rectangle_f::contains(const rectangle_f& rect) const noexcept {
  return x_ <= rect.x_ && (rect.x_ + rect.width_) <= (x_ + width_) && y_ <= rect.y_ && (rect.y_ + rect.height_) <= (y_ + height_);
}

bool rectangle_f::contains(float x, float y) const noexcept {
  return x_ <= x && x < x_ + width_ && y_ <= y && y < y_ + height_;
}

bool rectangle_f::equals(const rectangle_f& value) const noexcept {
  return x_ == value.x_ && y_ == value.y_ && width_ == value.width_ && height_ == value.height_;
}

rectangle_f rectangle_f::from_ltrb(float left, float top, float right, float bottom) noexcept {
  return rectangle_f(left, top, right - left, bottom - top);
}

void rectangle_f::inflate(const drawing::size_f& sz) noexcept {
  inflate(sz.width(), sz.height());
}

void rectangle_f::inflate(float width, float height) noexcept {
  x_ -= width;
  y_ -= height;
  width_ += 2 * width;
  height_ +=  2 * height;
}

rectangle_f rectangle_f::inflate(const rectangle_f& rect, const drawing::size_f& sz) noexcept {
  return inflate(rect, sz.width(), sz.height());
}

rectangle_f rectangle_f::inflate(const rectangle_f& rect, float width, float height) noexcept {
  auto result = rect;
  result.inflate(width, height);
  return result;
}

bool rectangle_f::intersects_with(const rectangle_f& rect) const noexcept {
  return (rect.x_ < x_ + width_) && (x_ < (rect.x_ + rect.width_)) && (rect.y_ < y_ + height_) && (y_ < rect.y_ + rect.height_);
}

rectangle_f rectangle_f::make_intersect(const rectangle_f& a, const rectangle_f& b) noexcept {
  auto result = a;
  result.make_intersect(b);
  return result;
}

void rectangle_f::make_intersect(const rectangle_f& rect) noexcept {
  auto x1 = math::max(x_, rect.x_);
  auto x2 = math::min(x_ + width_, rect.x_ + rect.width_);
  auto y1 = math::max(y_, rect.y_);
  auto y2 = math::min(y_ + height_, rect.y_ + rect.height_);
  
  if (x2 < x1 || y2 < y1) x_ = y_ = width_ = height_ = 0;
  else {
    x_ = x1;
    y_ = y1;
    width_ = x2 - x1;
    height_ = y2 - y1;
  }
}

rectangle_f rectangle_f::make_union(const rectangle_f& a, const rectangle_f& b) noexcept {
  auto result = a;
  result.make_union(b);
  return result;
}

void rectangle_f::make_union(const rectangle_f& rect) noexcept {
  auto x1 = math::min(x_, rect.x_);
  auto x2 = math::max(x_ + width_, rect.x_ + rect.width_);
  auto y1 = math::min(y_, rect.y_);
  auto y2 = math::max(y_ + height_, rect.y_ + rect.height_);
  
  x_ = x1;
  y_ = y1;
  width_ = x2 - x1;
  height_ = y2 - y1;
}

void rectangle_f::offset(const point_f& pos) noexcept {
  offset(pos.x(), pos.y());
}

void rectangle_f::offset(float x, float y) noexcept {
  x_ += x;
  y_ += y;
}

rectangle_f rectangle_f::offset(const rectangle_f& rect, const point_f& pos) noexcept {
  return offset(rect, pos.x(), pos.y());
}

rectangle_f rectangle_f::offset(const rectangle_f& rect, float x, float y) noexcept {
  auto result = rect;
  result.offset(x, y);
  return result;
}

xtd::ustring rectangle_f::to_string() const noexcept {
  return ustring::format("{{x={}, y={}, width={}, heght={}}}", x(), y(), width(), height());
}
