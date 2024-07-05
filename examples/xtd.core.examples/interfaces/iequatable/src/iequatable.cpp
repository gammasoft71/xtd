#include <xtd/console>
#include <xtd/iequatable>

using namespace xtd;

class foo : public iequatable<foo> {
public:
  explicit foo(int value) : value_ {value} {}

  bool equals(const foo& value) const noexcept override {return value_ == value.value_;}
  
private:
  int value_ = 0;
};

auto main() -> int {
  console::write_line("foo {{42}}.equals(foo {{42}}) = {}", foo {42}.equals(foo {42}));
  console::write_line("foo {{42}}.equals(foo {{84}}) = {}", foo {42}.equals(foo {84}));
  console::write_line();
  
  console::write_line("!foo {{42}}.equals(foo {{42}}) = {}", !foo {42}.equals(foo {42}));
  console::write_line("!foo {{42}}.equals(foo {{84}}) = {}", !foo {42}.equals(foo {84}));
  console::write_line();
  
  console::write_line("foo {{42}} == foo {{42}} = {}", foo {42} == foo {42});
  console::write_line("foo {{42}} == foo {{84}} = {}", foo {42} == foo {84});
  console::write_line();
  
  console::write_line("foo {{42}} != foo {{42}} = {}", foo {42} != foo {42});
  console::write_line("foo {{42}} != foo {{84}} = {}", foo {42} != foo {84});
}

// This code produces the following output :
//
// foo {42}.equals(foo {42}) = true
// foo {42}.equals(foo {84}) = false

// !foo {42}.equals(foo {42}) = false
// !foo {42}.equals(foo {84}) = true

// foo {42} == foo {42} = true
// foo {42} == foo {84} = false

// foo {42} != foo {42} = false
// foo {42} != foo {84} = true
