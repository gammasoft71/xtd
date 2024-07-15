#include <xtd/xtd>

using namespace xtd;

class user : public object, public iequatable<user> {
public:
  explicit user(int id, const ustring& name) : id_ {id}, name_ {name} {}

  int id() const noexcept {return id_;}
  const ustring& name() const noexcept {return name_;}
  
  // Overriding the equals method from object
  bool equals(const object& other) const noexcept override {return is<user>(other) && equals(as<user>(other));}
  
  // Implementing the equals method from iequatable<type_t>
  bool equals(const user& other) const noexcept override {return id_ == other.id_ && name_ == other.name_;}

  // Overriding the get_hash_code method from object
  size_t get_hash_code() const noexcept override {return hash_code::combine(id_, name_);}
    
  // Overriding the ToString method for better readability
  ustring to_string() const noexcept override {return ustring::format("user: id = {}, name = {}", id_, name_);}
  
private:
  int id_ = 0;
  ustring name_;
};

auto main() -> int {
  auto user1 = user {1, "Example"};
  auto user2 = user {1, "Example"};
  auto user3 = user {2, "Different"};
  
  console::write_line("user1 equals user2: {}", user1.equals(user2)); // true
  console::write_line("user1 equals user3: {}", user1.equals(user3)); // false
  
  // Using equals method through the object class
  console::write_line("user1 equals user2 (object): {}", user1.equals(as<object>(user2))); // true
  console::write_line("user1 equals user3 (object): {}", user1.equals(as<object>(user3))); // false
  
  // Using get_hash_code
  console::write_line("user1 hash code: {}", user1.get_hash_code());
  console::write_line("user2 hash code: {}", user2.get_hash_code());
  console::write_line("user3 hash code: {}", user3.get_hash_code());
  
  // Using == and != operators
  console::write_line("user1 == user2: {}", user1 == user2); // true
  console::write_line("user1 != user3: {}", user1 != user3); // true

  // Using to_string method
  console::write_line(user1.to_string());
  console::write_line(user2.to_string());
  console::write_line(user3.to_string());
}

// This code produces the following output:
//
// user1 equals user2: true
// user1 equals user3: false
// user1 equals user2 (object): true
// user1 equals user3 (object): false
// user1 hash code: 9105846386475545849
// user2 hash code: 9105846386475545849
// user3 hash code: 4537660354082115200
// user1 == user2: true
// user1 != user3: true
// user: id = 1, name = Example
// user: id = 1, name = Example
// user: id = 2, name = Different
