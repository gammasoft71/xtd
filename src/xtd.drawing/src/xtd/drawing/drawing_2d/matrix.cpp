#include "../../../../include/xtd/drawing/drawing_2d/matrix"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/matrix>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/as>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

struct matrix::data {
  intptr handle = 0;
};

matrix::matrix() : matrix(1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f) {
}

matrix::matrix(float m11, float m12, float m21, float m22, float dx, float dy) : data_(std::make_shared<data>()) {
  data_->handle = native::matrix::create(m11, m12, m21, m22, dx, dy);
}

matrix::matrix(const rectangle& rect, const vector<point>& plgpts) : data_(std::make_shared<data>()) {
  if (plgpts.size() != 3) throw argument_exception {csf_};
  init_from_rect_3points(rectangle_f(rect), point_f(plgpts[0]), point_f(plgpts[1]), point_f(plgpts[2]));
}

matrix::matrix(const rectangle_f& rect, const vector<point_f>& plgpts) : data_(std::make_shared<data>()) {
  if (plgpts.size() != 3) throw argument_exception {csf_};
  init_from_rect_3points(rect, plgpts[0], plgpts[1], plgpts[2]);
}

matrix::matrix(intptr handle) : data_(std::make_shared<data>()) {
  data_->handle = handle;
}

matrix::~matrix() {
  if (data_.use_count() == 1 && data_->handle != 0) {
    native::matrix::destroy(data_->handle);
    data_->handle = 0;
  }
}

std::vector<float> matrix::elements() const {
  return native::matrix::elenents(handle());
}

intptr matrix::handle() const noexcept {
  return data_->handle;
}

bool matrix::is_identity() const {
  return native::matrix::is_identity(handle());
}

bool matrix::is_invertible() const {
  return native::matrix::is_invertible(handle());
}

float matrix::offset_x() const {
  return native::matrix::offset_x(handle());
}

float matrix::offset_y() const {
  return native::matrix::offset_y(handle());
}

bool matrix::equals(const matrix& value) const noexcept {
  return data_ == value.data_;
}

void matrix::invert() {
  native::matrix::invert(handle());
}

void matrix::multiply(const xtd::drawing::drawing_2d::matrix& matrix) {
  multiply(matrix, xtd::drawing::drawing_2d::matrix_order::prepend);
}

void matrix::multiply(const xtd::drawing::drawing_2d::matrix& matrix, xtd::drawing::drawing_2d::matrix_order order) {
  native::matrix::multiply(handle(), matrix.handle(), static_cast<int32>(order));
}

void matrix::reset() {
  native::matrix::reset(handle());
}

void matrix::rotate(float angle) {
  rotate(angle, xtd::drawing::drawing_2d::matrix_order::prepend);
}

void matrix::rotate(float angle, xtd::drawing::drawing_2d::matrix_order order) {
  native::matrix::rotate(handle(), angle, static_cast<int32>(order));
}

void matrix::rotate_at(float angle, const point_f& point) {
  rotate_at(angle, point, xtd::drawing::drawing_2d::matrix_order::prepend);
}

void matrix::rotate_at(float angle, const point_f& point, xtd::drawing::drawing_2d::matrix_order order) {
  native::matrix::rotate_at(handle(), angle, point.x(), point.y(), static_cast<int32>(order));
}

void matrix::scale(float scale_x, float scale_y) {
  scale(scale_x, scale_y, matrix_order::prepend);
}

void matrix::scale(float scale_x, float scale_y, xtd::drawing::drawing_2d::matrix_order order) {
  native::matrix::scale(handle(), scale_x, scale_y, static_cast<int32>(order));
}

void matrix::shear(float scale_x, float scale_y) {
  shear(scale_x, scale_y, xtd::drawing::drawing_2d::matrix_order::prepend);
}

void matrix::shear(float scale_x, float scale_y, xtd::drawing::drawing_2d::matrix_order order) {
  native::matrix::shear(handle(), scale_x, scale_y, static_cast<int32>(order));
}

void matrix::transform_points(std::vector<xtd::drawing::point>& points) {
  for (auto& point : points) {
    auto tx = point.x(), ty = point.y();
    native::matrix::transform_point(handle(), tx, ty);
    point.x(tx);
    point.y(ty);
  }
}

void matrix::transform_points(std::vector<xtd::drawing::point_f>& points) {
  for (auto& point : points) {
    auto tx = point.x(), ty = point.y();
    native::matrix::transform_point(handle(), tx, ty);
    point.x(tx);
    point.y(ty);
  }
}

void matrix::transform_vectors(std::vector<xtd::drawing::point>& points) {
  auto tr_points = vector<pair<int32, int32>> {};
  for_each(points.begin(), points.end(), [&](auto point) {tr_points.emplace_back(point.x(), point.y());});
  native::matrix::transform_vectors(handle(), tr_points);
  points.clear();
  for_each(tr_points.begin(), tr_points.end(), [&](const pair<int32, int32>& point) {points.push_back(xtd::drawing::point(point.first, point.second));});
}

void matrix::transform_vectors(std::vector<xtd::drawing::point_f>& points) {
  auto tr_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto point) {tr_points.emplace_back(point.x(), point.y());});
  native::matrix::transform_vectors(handle(), tr_points);
  points.clear();
  for_each(tr_points.begin(), tr_points.end(), [&](const pair<float, float>&  point) {points.push_back(xtd::drawing::point_f(point.first, point.second));});
}

void matrix::translate(float offset_x, float offset_y) {
  translate(offset_x, offset_y, xtd::drawing::drawing_2d::matrix_order::prepend);
}

void matrix::translate(float offset_x, float offset_y, xtd::drawing::drawing_2d::matrix_order order) {
  native::matrix::translate(handle(), offset_x, offset_y, static_cast<int32>(order));
}

void matrix::vector_transform_points(std::vector<xtd::drawing::point>& points) {
  auto tr_points = vector<pair<int32, int32>> {};
  for_each(points.begin(), points.end(), [&](auto point) {tr_points.emplace_back(point.x(), point.y());});
  native::matrix::vector_transform_points(handle(), tr_points);
  points.clear();
  for_each(tr_points.begin(), tr_points.end(), [&](const pair<int32, int32>& point) {points.push_back(xtd::drawing::point(point.first, point.second));});
}

xtd::ustring matrix::to_string() const noexcept {
  return get_type().full_name();
}

void matrix::init_from_rect_3points(const rectangle_f& rect, const point_f pt1, const point_f pt2, const point_f pt3) {
  auto m11 = (pt2.x() - pt1.x()) / rect.width();
  auto m12 = (pt2.y() - pt1.y()) / rect.width();
  auto m21 = (pt3.x() - pt1.x()) / rect.height();
  auto m22 = (pt3.y() - pt1.y()) / rect.height();
  
  data_->handle = native::matrix::create(m11, m12, m21, m22, pt1.x(), pt1.y());
  native::matrix::translate(handle(), -rect.x(), -rect.y(), as<int32>(matrix_order::prepend));
}
