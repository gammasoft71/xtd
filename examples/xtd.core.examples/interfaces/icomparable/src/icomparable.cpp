#include <xtd/console>
#include <xtd/icomparable>

using namespace xtd;

class foo : public icomparable<foo> {
public:
  explicit foo(int value) : value_ {value} {}

  int compare_to(const foo& value) const noexcept override {return value_ < value.value_ ? -1 : (value_ > value.value_) ? 1 : 0;}
  
private:
  int value_ = 0;
};

auto main() -> int {
  console::write_line("foo {{42}}.compare_to(foo {{42}}) = {}", foo {42}.compare_to(foo {42}));
  console::write_line("foo {{42}}.compare_to(foo {{41}}) = {}", foo {42}.compare_to(foo {41}));
  console::write_line("foo {{42}}.compare_to(foo {{43}}) = {}", foo {42}.compare_to(foo {43}));
  console::write_line();

  console::write_line("foo {{42}} <= foo {{42}} = {}", foo {42} <= foo {42});
  console::write_line("foo {{42}} <= foo {{41}} = {}", foo {42} <= foo {41});
  console::write_line("foo {{42}} <= foo {{43}} = {}", foo {42} <= foo {43});
  console::write_line();

  console::write_line("foo {{42}} < foo {{42}} = {}", foo {42} < foo {42});
  console::write_line("foo {{42}} < foo {{41}} = {}", foo {42} < foo {41});
  console::write_line("foo {{42}} < foo {{43}} = {}", foo {42} < foo {43});
  console::write_line();

  console::write_line("foo {{42}} >= foo {{42}} = {}", foo {42} >= foo {42});
  console::write_line("foo {{42}} >= foo {{41}} = {}", foo {42} >= foo {41});
  console::write_line("foo {{42}} >= foo {{43}} = {}", foo {42} >= foo {43});
  console::write_line();

  console::write_line("foo {{42}} > foo {{42}} = {}", foo {42} > foo {42});
  console::write_line("foo {{42}} > foo {{41}} = {}", foo {42} > foo {41});
  console::write_line("foo {{42}} > foo {{43}} = {}", foo {42} > foo {43});
}

// This code produces the following output :
//
// ffoo {42}.compare_to(foo {42}) = 0
// foo {42}.compare_to(foo {41}) = 1
// foo {42}.compare_to(foo {43}) = -1
//
// foo {42} <= foo {42} = true
// foo {42} <= foo {41} = false
// foo {42} <= foo {43} = true
//
// foo {42} < foo {42} = false
// foo {42} < foo {41} = false
// foo {42} < foo {43} = true
//
// foo {42} >= foo {42} = true
// foo {42} >= foo {41} = true
// foo {42} >= foo {43} = false
//
// foo {42} > foo {42} = false
// foo {42} > foo {41} = true
// foo {42} > foo {43} = false
