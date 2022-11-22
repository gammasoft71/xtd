#include <xtd/as.h>
#include <xtd/math.h>
#include "../../../include/xtd/drawing/rectangle.h"

using namespace xtd;
using namespace xtd::drawing;

const rectangle rectangle::empty;

rectangle::rectangle(int32_t x, int32_t y, int32_t width, int32_t height) noexcept : x_(x), y_(y), width_(width), height_(height) {
}

rectangle::rectangle(const point& location, const drawing::size& size) noexcept : rectangle(location.x(), location.y(), size.width(), size.height()) {
}

rectangle::operator rectangle_f() const noexcept {
  return rectangle_f(as<float>(x_), as<float>(y_), as<float>(width_), as<float>(height_));
}

int32_t rectangle::bottom() const noexcept {
  return y_ + height_;
}

int32_t rectangle::height() const noexcept {
  return height_;
}

void rectangle::height(int32_t value) noexcept {
  height_ = value;
}

bool rectangle::is_empty() const noexcept {
  return *this == rectangle::empty;
}

int32_t rectangle::left() const noexcept {
  return x_;
}

point rectangle::location() const noexcept {
  return {x_, y_};
}

void rectangle::location(const point& value) noexcept {
  x_ = value.x();
  y_ = value.y();
}

int32_t rectangle::right() const noexcept {
  return x_ + width_;
}

drawing::size rectangle::size() const noexcept {
  return {width_, height_};
}

void rectangle::size(const xtd::drawing::size& value) noexcept {
  width_ = value.width();
  height_ = value.height();
}

int32_t rectangle::top() const noexcept {
  return y_;
}

int32_t rectangle::width() const noexcept {
  return width_;
}

void rectangle::width(int32_t value) noexcept {
  width_ = value;
}

int32_t rectangle::x() const noexcept {
  return x_;
}

void rectangle::x(int32_t value) noexcept {
  x_ = value;
}

int32_t rectangle::y() const noexcept {
  return y_;
}

void rectangle::y(int32_t value) noexcept {
  y_ = value;
}

void rectangle::add(const drawing::size& sz) noexcept {
  add(sz.width(), sz.height());
}

void rectangle::add(int width, int height) noexcept {
  width_ += width;
  height_ += height;
}

rectangle rectangle::add(const rectangle& rect, int x, int y) noexcept {
  auto result = rect;
  result.add(x, y);
  return result;
}

rectangle rectangle::add(const rectangle& rect, const drawing::size& sz) noexcept {
  return add(rect, sz.width(), sz.height());
}

rectangle rectangle::ceiling(const rectangle_f& rect) noexcept {
  return rectangle(as<int32_t>(math::ceiling(rect.x())), as<int32_t>(math::ceiling(rect.y())), as<int32_t>(math::ceiling(rect.width())), as<int32_t>(math::ceiling(rect.height())));
}

bool rectangle::contains(const point& pt) const noexcept {
  return contains(pt.x(), pt.y());
}

bool rectangle::contains(const rectangle& rect) const noexcept {
  return x_ <= rect.x_ && (rect.x_ + rect.width_) <= (x_ + width_) && y_ <= rect.y_ && (rect.y_ + rect.height_) <= (y_ + height_);
}

bool rectangle::contains(int32_t x, int32_t y) const noexcept {
  return x_ <= x && x < x_ + width_ && y_ <= y && y < y_ + height_;
}

rectangle rectangle::from_ltrb(int32_t left, int32_t top, int32_t right, int32_t bottom) noexcept {
  return rectangle(left, top, right - left, bottom - top);
}

void rectangle::inflate(const drawing::size& sz) noexcept {
  inflate(sz.width(), sz.height());
}

void rectangle::inflate(int width, int height) noexcept {
  x_ -= width;
  y_ -= height;
  width_ += 2 * width;
  height_ +=  2 * height;
}

rectangle rectangle::inflate(const rectangle& rect, int x, int y) noexcept {
  auto result = rect;
  result.inflate(x, y);
  return result;
}

rectangle rectangle::inflate(const rectangle& rect, const drawing::size& sz) noexcept {
  return inflate(rect, sz.width(), sz.height());
}

bool rectangle::intersects_with(const rectangle& rect) const noexcept {
  return (rect.x_ < x_ + width_) && (x_ < (rect.x_ + rect.width_)) && (rect.y_ < y_ + height_) && (y_ < rect.y_ + rect.height_);
}

rectangle rectangle::make_intersect(const rectangle& a, const rectangle& b) noexcept {
  auto result = a;
  result.make_intersect(b);
  return result;
}

void rectangle::make_intersect(const rectangle& rect) noexcept {
  auto x1 = std::max(x_, rect.x_);
  auto x2 = std::min(x_ + width_, rect.x_ + rect.width_);
  auto y1 = std::max(y_, rect.y_);
  auto y2 = std::min(y_ + height_, rect.y_ + rect.height_);
  
  if (x2 < x1 || y2 < y1) x_ = y_ = width_ = height_ = 0;
  else {
    x_ = x1;
    y_ = y1;
    width_ = x2 - x1;
    height_ = y2 - y1;
  }
}

rectangle rectangle::make_union(const rectangle& a, const rectangle& b) noexcept {
  auto result = a;
  result.make_union(b);
  return result;
}

void rectangle::make_union(const rectangle& rect) noexcept {
  auto x1 = std::min(x_, rect.x_);
  auto x2 = std::max(x_ + width_, rect.x_ + rect.width_);
  auto y1 = std::min(y_, rect.y_);
  auto y2 = std::max(y_ + height_, rect.y_ + rect.height_);
  
  x_ = x1;
  y_ = y1;
  width_ = x2 - x1;
  height_ = y2 - y1;
}

void rectangle::offset(const point& pos) noexcept {
  offset(pos.x(), pos.y());
}

void rectangle::offset(int32_t x, int32_t y) noexcept {
  x_ += x;
  y_ += y;
}

rectangle rectangle::offset(const rectangle& rect, const point& pos) noexcept {
  return offset(rect, pos.x(), pos.y());
}

rectangle rectangle::offset(const rectangle& rect, int x, int y) noexcept {
  auto result = rect;
  result.offset(x, y);
  return result;
}

rectangle rectangle::round(const rectangle_f& rect) noexcept {
  return rectangle(as<int32_t>(math::round(rect.x())), as<int32_t>(math::round(rect.y())), as<int32_t>(math::round(rect.width())), as<int32_t>(math::round(rect.height())));
}

rectangle rectangle::truncate(const rectangle_f& rect) noexcept {
  return rectangle(as<int32_t>(math::truncate(rect.x())), as<int32_t>(math::truncate(rect.y())), as<int32_t>(math::truncate(rect.width())), as<int32_t>(math::truncate(rect.height())));
}

xtd::ustring rectangle::to_string() const noexcept {
  return ustring::format("{{x={}, y={}, width={}, heght={}}}", x(), y(), width(), height());
}

bool rectangle::operator ==(const rectangle& value) const noexcept {
  return x_ == value.x_ && y_ == value.y_ && width_ == value.width_ && height_ == value.height_;
}

bool rectangle::operator !=(const rectangle& value) const noexcept {
  return !operator ==(value);
}
