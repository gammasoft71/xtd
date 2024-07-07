#include <xtd/console>

using namespace xtd;

// The Point class is derived from System.Object.
class point : public object {
public:
  int x, y;
  
  point(int x, int y) : x {x}, y {y} {}
  
  bool equals(const object& obj) const noexcept override {
    // If this and obj do not refer to the same type, then they are not equal.
    if (obj.get_type() != get_type()) return false;
    
    // Return true if  x and y fields match.
    auto& other = static_cast<const point&>(obj);
    return x == other.x && y == other.y;
  }
  
  // Return the XOR of the x and y fields.
  size_t get_hash_code() const noexcept override {
    return x ^ y;
  }
  
  // Return the point's value as a string.
  ustring to_string() const noexcept override {
    return ustring::format("({}, {})", x, y);
  }
  
  // Return a copy of this point object by making a simple field copy.
  std::unique_ptr<point> copy() const {
    return memberwise_clone<point>();
  }
};

auto main() -> int {
  // Construct a Point object.
  auto p1 = point {1, 2};
  
  // Make another Point object that is a copy of the first.
  auto p2 = p1.copy();
  
  // Make another variable that references the first point object.
  auto& p3 = p1;
  
  // The line below displays false because p1 and p2 refer to two different objects.
  console::write_line(object::reference_equals(p1, *p2));
  
  // The line below displays true because p1 and p2 refer to two different objects that have the same value.
  console::write_line(object::equals(p1, *p2));
  
  // The line below displays true because p1 and p3 refer to one object.
  console::write_line(object::reference_equals(p1, p3));
  
  // The line below displays: p1's value is: (1, 2)
  console::write_line("p1's value is: {}", p1.to_string());
}

// This code produces the following output:
//
// false
// true
// true
// p1's value is: (1, 2)
