#include <xtd/xtd>

using namespace xtd;

class foo : public object, public iequatable<foo> {
public:
  explicit foo(int id, const ustring& name) : id_ {id}, name_ {name} {}

  int id() const noexcept {return id_;}
  const ustring& name() const noexcept {return name_;}
  
  // Overriding the equals method from object
  bool equals(const object& other) const noexcept override {return is<foo>(other) ? equals(as<foo>(other)) : object::equals(other);}
  
  // Implementing the equals method from iequatable<type_t>
  bool equals(const foo& other) const noexcept override {return id_ == other.id_ && name_ == other.name_;}

  // Overriding the get_hash_code method from object
  size_t get_hash_code() const noexcept override {return hash_code::combine(id_, name_);}
    
  // Overriding the ToString method for better readability
  ustring to_string() const noexcept override {return ustring::format("foo: id = {}, name = {}", id_, name_);}
  
private:
  int id_ = 0;
  ustring name_;
};

auto main() -> int {
  auto foo1 = foo {1, "Example" };
  auto foo2 = foo { 1, "Example" };
  auto foo3 = foo { 2, "Different" };
  
  console::write_line("foo1 equals foo2: {}", foo1.equals(foo2)); // true
  console::write_line("foo1 equals foo3: {}", foo1.equals(foo3)); // false
  
  // Using equals method through the object class
  console::write_line("foo1 equals foo2 (object): {}", foo1.equals(as<object>(foo2))); // true
  console::write_line("foo1 equals foo3 (object): {}", foo1.equals(as<object>(foo3))); // false
  
  // Using get_hash_code
  console::write_line("foo1 hash code: {}", foo1.get_hash_code());
  console::write_line("foo2 hash code: {}", foo2.get_hash_code());
  console::write_line("foo3 hash code: {}", foo3.get_hash_code());
  
  // Using == and != operators
  console::write_line("foo1 == foo2: {}", foo1 == foo2); // true
  console::write_line("foo1 != foo3: {}", foo1 != foo3); // true

  // Using to_string method
  console::write_line(foo1.to_string());
  console::write_line(foo2.to_string());
  console::write_line(foo3.to_string());
}

// This code produces the following output:
//
// foo1 equals foo2: true
// foo1 equals foo3: false
// foo1 equals foo2 (object): true
// foo1 equals foo3 (object): false
// foo1 hash code: 9105846386475545849
// foo2 hash code: 9105846386475545849
// foo3 hash code: 4537660354082115200
// foo1 == foo2: true
// foo1 != foo3: true
// foo: id = 1, name = Example
// foo: id = 1, name = Example
// foo: id = 2, name = Different
