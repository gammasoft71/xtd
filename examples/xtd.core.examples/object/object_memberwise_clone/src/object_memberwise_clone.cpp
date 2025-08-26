#include <xtd/xtd>

class id_info : public object {
public:
  int id_number = 0;
  
  explicit id_info(int id_number) : id_number {id_number} {}
};

class person : public object {
public:
  int age = 0;
  ptr<string> name = new_ptr<string>();
  ptr<::id_info> id_info = new_ptr<::id_info>(0);
  
  uptr<person> shallow_copy() {
    return memberwise_clone<person>();
  }
  
  uptr<person> deep_copy() {
    auto other = memberwise_clone<person>();
    other->id_info = new_ptr<::id_info>(this->id_info->id_number);
    other->name = new_ptr<string>(*name);
    return other;
  }
};

void display_values(const person p) {
  console::write_line("      name: {0:s}, age: {1:d}", *p.name, p.age);
  console::write_line("      value: {0:d}", p.id_info->id_number);
}

auto main() -> int {
  // Create an instance of person and assign values to its fields.
  auto p1 = new_uptr<person>();
  p1->age = 42;
  *p1->name = "Sam";
  *p1->id_info = id_info {6565};
  
  // Perform a shallow copy of p1 and assign it to p2.
  auto p2 = p1->shallow_copy();
  
  // Display values of p1, p2
  console::write_line("Original values of p1 and p2:");
  console::write_line("   p1 instance values: ");
  display_values(*p1);
  console::write_line("   p2 instance values:");
  display_values(*p2);

  // Change the value of p1 properties and display the values of p1 and p2.
  p1->age = 32;
  *p1->name = "Frank";
  p1->id_info->id_number = 7878;
  console::write_line("\nValues of p1 and p2 after changes to p1:");
  console::write_line("   p1 instance values: ");
  display_values(*p1);
  console::write_line("   p2 instance values:");
  display_values(*p2);

  // Make a deep copy of p1 and assign it to p3.
  auto p3 = p1->deep_copy();
  // Change the members of the p1 class to new values to show the deep copy.
  *p1->name = "George";
  p1->age = 39;
  p1->id_info->id_number = 8641;
  console::write_line("\nValues of p1 and p3 after changes to p1:");
  console::write_line("   p1 instance values: ");
  display_values(*p1);
  console::write_line("   p3 instance values:");
  display_values(*p3);
}

// This code produces the following output :
//
// Original values of p1 and p2:
//    p1 instance values:
//       name: Sam, age: 42
//       value: 6565
//    p2 instance values:
//       name: Sam, age: 42
//       value: 6565
//
// Values of p1 and p2 after changes to p1:
//    p1 instance values:
//       name: Frank, age: 32
//       value: 7878
//    p2 instance values:
//       name: Frank, age: 42
//       value: 7878
//
// Values of p1 and p3 after changes to p1:
//    p1 instance values:
//       name: George, age: 39
//       value: 8641
//    p3 instance values:
//       name: Frank, age: 32
//       value: 7878
