#include <xtd/xtd>

using namespace xtd;

namespace examples {
  // The following class represents simple functionality of the trapezoid.
  class math_trapezoid_sample : public object {
  public:
    // The main entry point for the application.
    static void main() {
      math_trapezoid_sample trpz(20.0, 10.0, 8.0, 6.0);
      console::write_line("The trapezoid's bases are 20.0 and 10.0, the trapezoid's legs are 8.0 and 6.0");
      double h = trpz.get_height();
      console::write_line("trapezoid height is: {0}", h);
      double dx_r = trpz.get_left_base_radian_angle();
      console::write_line("trapezoid left base angle is: {0} Radians", dx_r);
      double dy_r = trpz.get_right_base_radian_angle();
      console::write_line("trapezoid right base angle is: {0} Radians", dy_r);
      double dx_d = trpz.get_left_base_degree_angle();
      console::write_line("trapezoid left base angle is: {0} Degrees", dx_d);
      double dy_d = trpz.get_right_base_degree_angle();
      console::write_line("trapezoid left base angle is: {0} Degrees", dy_d);
    }
    
    math_trapezoid_sample(double long_base, double short_base, double left_leg, double right_leg) {
      long_base_ = math::abs(long_base);
      short_base_ = math::abs(short_base);
      left_leg_ = math::abs(left_leg);
      right_leg_ = math::abs(right_leg);
    }
    
    double get_height() {
      double x = get_right_small_base();
      return math::sqrt(math::pow(right_leg_, 2.0) - math::pow(x, 2.0));
    }
    
    double get_square() {
      return get_height() * long_base_ / 2.0;
    }
    
    double get_left_base_radian_angle() {
      double sin_x = get_height() / left_leg_;
      return math::round(math::asin(sin_x), 2);
    }
    
    double get_right_base_radian_angle() {
      double x = get_right_small_base();
      double cos_x = (math::pow(right_leg_, 2.0) + math::pow(x, 2.0) - math::pow(get_height(), 2.0)) / (2 * x * right_leg_);
      return math::round(math::acos(cos_x), 2);
    }
    
    double get_left_base_degree_angle() {
      double x = math::radians_to_degrees(get_left_base_radian_angle());
      return math::round(x, 2);
    }
    
    double get_right_base_degree_angle() {
      double x = math::radians_to_degrees(get_right_base_radian_angle());
      return math::round(x, 2);
    }
    
  private:
    double long_base_;
    double short_base_;
    double left_leg_;
    double right_leg_;
    
    double get_right_small_base() {
      return (math::pow(right_leg_, 2.0) - math::pow(left_leg_, 2.0) + math::pow(long_base_, 2.0) + math::pow(short_base_, 2.0) - 2 * short_base_ * long_base_) / (2 * (long_base_ - short_base_));
    }
  };
}

startup_(examples::math_trapezoid_sample);

// This code produces the following output:
//
// The trapezoid's bases are 20.0 and 10.0, the trapezoid's legs are 8.0 and 6.0
// trapezoid height is: 4.8
// trapezoid left base angle is: 0.64 Radians
// trapezoid right base angle is: 0.93 Radians
// trapezoid left base angle is: 36.67 Degrees
// trapezoid left base angle is: 53.29 Degrees
