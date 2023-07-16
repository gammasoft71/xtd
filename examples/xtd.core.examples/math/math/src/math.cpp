#include <xtd/console>
#include <xtd/math>
#include <xtd/startup>

using namespace xtd;

namespace math_example {
  // The following class represents simple functionality of the trapezoid.
  class math_trapezoid_sample {
  public:
    // The main entry point for the application.
    static auto main() {
      auto trpz = math_trapezoid_sample {20.0, 10.0, 8.0, 6.0};
      console::write_line("The trapezoid's bases are 20.0 and 10.0, the trapezoid's legs are 8.0 and 6.0");
      auto h = trpz.get_height();
      console::write_line("trapezoid height is: {0}", h);
      auto dx_r = trpz.get_left_base_radian_angle();
      console::write_line("trapezoid left base angle is: {0} Radians", dx_r);
      auto dy_r = trpz.get_right_base_radian_angle();
      console::write_line("trapezoid right base angle is: {0} Radians", dy_r);
      auto dx_d = trpz.get_left_base_degree_angle();
      console::write_line("trapezoid left base angle is: {0} Degrees", dx_d);
      auto dy_d = trpz.get_right_base_degree_angle();
      console::write_line("trapezoid left base angle is: {0} Degrees", dy_d);
    }
    
    math_trapezoid_sample(auto long_base, auto short_base, auto left_leg, auto right_leg) {
      long_base_ = math::abs(long_base);
      short_base_ = math::abs(short_base);
      left_leg_ = math::abs(left_leg);
      right_leg_ = math::abs(right_leg);
    }
    
    auto get_height()->double {
      auto x = get_right_small_base();
      return math::sqrt(math::pow(right_leg_, 2.0) - math::pow(x, 2.0));
    }
    
    auto get_square()->double {
      return get_height() * long_base_ / 2.0;
    }
    
    auto get_left_base_radian_angle()->double {
      auto sin_x = get_height() / left_leg_;
      return math::round(math::asin(sin_x), 2);
    }
    
    auto get_right_base_radian_angle()->double {
      auto x = get_right_small_base();
      auto cos_x = (math::pow(right_leg_, 2.0) + math::pow(x, 2.0) - math::pow(get_height(), 2.0)) / (2 * x * right_leg_);
      return math::round(math::acos(cos_x), 2);
    }
    
    auto get_left_base_degree_angle()->double {
      auto x = math::radians_to_degrees(get_left_base_radian_angle());
      return math::round(x, 2);
    }
    
    auto get_right_base_degree_angle()->double {
      auto x = math::radians_to_degrees(get_right_base_radian_angle());
      return math::round(x, 2);
    }
    
  private:
    auto get_right_small_base()->double {
      return (math::pow(right_leg_, 2.0) - math::pow(left_leg_, 2.0) + math::pow(long_base_, 2.0) + math::pow(short_base_, 2.0) - 2 * short_base_ * long_base_) / (2 * (long_base_ - short_base_));
    }

    double long_base_ = .0;
    double short_base_ = .0;
    double left_leg_ = .0;
    double right_leg_ = .0;
  };
}

startup_(math_example::math_trapezoid_sample);

// This code produces the following output:
//
// The trapezoid's bases are 20.0 and 10.0, the trapezoid's legs are 8.0 and 6.0
// trapezoid height is: 4.8
// trapezoid left base angle is: 0.64 Radians
// trapezoid right base angle is: 0.93 Radians
// trapezoid left base angle is: 36.67 Degrees
// trapezoid left base angle is: 53.29 Degrees
