#include <xtd/console>
#include <xtd/iclonable>

using namespace xtd;

class foo : public object, public iclonable {
public:
  explicit foo(int value) : value_ {value} {}

  uptr<object> clone() const override {return new_uptr<foo>(value_);}

  ustring to_string() const noexcept override {return ustring::format("{}", value_);}

private:
  int value_ = 0;
};

auto main() -> int {
  auto f1 = foo {42};
  console::write_line("f1 {{type = {}, value = {}}}", typeof_(f1), f1);

  auto f2 = f1.clone();
  console::write_line("f2 {{type = {}, value = {}}}", typeof_(f2), *f2);

  auto f3 = as<foo>(f1.clone());
  console::write_line("f3 {{type = {}, value = {}}}", typeof_(f3), *f3);
}

// This code produces the following output :
//
// f1 {type = foo, value = 42}
// f2 {type = std::unique_ptr<xtd::object, std::default_delete<xtd::object>>, value = 42}
// f3 {type = std::unique_ptr<foo, std::default_delete<foo>>, value = 42}

