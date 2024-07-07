#include <xtd/xtd>

using namespace xtd;

namespace examples {
  namespace object_test {
    class object1 : public object {
    };
  }
}

auto main() -> int {
  sptr<object> obj1 = new_sptr<examples::object_test::object1>();
  console::write_line(obj1->to_string());

  sptr<object> obj2 = new_sptr<date_time>(1971, 1, 5, 23, 5, 0);
  console::write_line(obj2->to_string());

  sptr<object> obj3 = new_sptr<boolean_object>();
  console::write_line(obj3->to_string());
}

// This code produces the following output:
//
// examples::object_test::object1
// Tue Jan  5 23:05:00 1971
// false
