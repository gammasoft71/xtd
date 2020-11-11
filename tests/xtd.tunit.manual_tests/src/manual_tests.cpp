#include <xtd/xtd.tunit>

using namespace xtd::tunit;

enum class day {
  sunday,
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday
};

std::ostream& operator<<(std::ostream& os, const day& d) {
  switch (d) {
    case day::sunday: os << "sunday"; break;
    case day::monday: os << "monday"; break;
    case day::tuesday: os << "tuesday"; break;
    case day::wednesday: os << "wednesday"; break;
    case day::thursday: os << "thursday"; break;
    case day::friday: os << "friday"; break;
    case day::saturday: os << "saturday"; break;
  }
  return os;
}

class foo {
public:
  foo() {}
  explicit foo(int value) : value_(value) {}

  int value() const {return this->value_;}
  
  bool operator==(const foo& f) const {return this->value_ == f.value_;}
  bool operator!=(const foo& f) const {return !this->operator==(f);}
  
private:
  int value_ = 0;
};

//std::ostream& operator<<(std::ostream& os, const foo& f) {return os << f.value();}

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case1) {
      day d = day::monday;
      assert::are_equal(day::sunday, d);
    }

    void test_method_(test_case2) {
      foo f1(42);
      foo f2(24);
      assert::are_equal(f2, f1);
    }
  };
}

int main() {
  return console_unit_test().run();
}
