#include <xtd/as>
#include <xtd/console>
#include <xtd/iprogress>
#include <xtd/math>

using namespace xtd;

class generic_progress {
public:
  generic_progress() = default;
  generic_progress(int val, int min = 0, int max = 100, const ustring& msg = "") : message_(msg) {
    minimum(min);
    maximum(max);
    value(val);
  }
  
  int maximum() const noexcept {return maximum_;}
  generic_progress& maximum(int maximum) noexcept {
    maximum_ = maximum;
    minimum_ = math::min(minimum(), maximum);
    value_ = math::min(value(), maximum);
    return *this;
  }
  
  int minimum() const noexcept {return minimum_;}
  generic_progress& minimum(int minimum) noexcept {
    minimum_ = minimum;
    maximum_ = math::max(maximum(), minimum);
    value_ = math::max(value(), minimum);
    return *this;
  }
  
  const ustring& message() const noexcept {return message_;}
  generic_progress& message(const ustring& message) noexcept {
    message_ = message;
    return *this;
  }
  
  float percent() const noexcept {return maximum_ - minimum_ ? as<float>(value() - minimum()) / (maximum() - minimum()) : 1;}
  
  generic_progress& increment(int increment) noexcept {
    value(value() + increment);
    return *this;
  }
  
  generic_progress& perform_step() noexcept {return increment(step());}
  generic_progress& perform_step(const ustring& message) noexcept {
    message_ = message;
    return perform_step();
  }
  
  int value() const noexcept {return value_;}
  generic_progress& value(int value) noexcept {
    value_ = math::clamp(value, minimum(), maximum());
    return *this;
  }
  
  int step() const noexcept {return step_;}
  generic_progress& step(int step) noexcept {
    step_ = step;
    return *this;
  }
  
private:
  int minimum_ = 0;
  int maximum_ = 100;
  int step_ = 1;
  int value_ = 0;
  ustring message_;
};

class print_generic_progress : public iprogress<generic_progress> {
public:
  print_generic_progress() = default;
  
  void report(const generic_progress& value) noexcept override {
    console::write_line("completion={,3}%, message=\"{}\"", as<int>(value.percent() * 100), value.message());
  }
};

auto main() -> int {
  console::write_line("Started");
  
  auto print_progress = print_generic_progress {};
  auto progress = generic_progress {0, 0, 5, "Initialized"};
  print_progress.report(progress);
  
  // Open device....
  print_progress.report(progress.perform_step("Device opened"));
  // Update 1 device....
  print_progress.report(progress.perform_step("Device updated 1"));
  // Update 2 device....
  print_progress.report(progress.perform_step("Device updated 2"));
  // Update 3 device....
  print_progress.report(progress.perform_step("Device updated 3"));
  // Close device....
  print_progress.report(progress.perform_step("Device closed"));
  
  console::write_line("Ended");
}

// The example displays output similar to the following:
//
// Started
// completion=  0%, message="Initialized"
// completion= 20%, message="Device opened"
// completion= 40%, message="Device updated 1"
// completion= 60%, message="Device updated 2"
// completion= 80%, message="Device updated 3"
// completion=100%, message="Device closed"
// Ended
