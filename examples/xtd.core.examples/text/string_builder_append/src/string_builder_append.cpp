#include <xtd/text/string_builder>
#include <xtd/console>
#include <xtd/istringable>

using namespace xtd;

class dog : public istringable {
private:
  string dog_breed;
  string dog_name;
  
public:
  dog(const string& name, const string& breed) : dog_breed(breed), dog_name(name) {}
  
  const string& breed() const noexcept {return dog_breed;}
  const string& name() const noexcept {return dog_name;}
  
  string to_string() const noexcept override {return dog_name;}
};

auto main() -> int {
  auto dog1 = dog {"Mocka", "American Shepherd"};
  auto sb = xtd::text::string_builder {};
  sb.append(dog1).append(", breed: ").append(dog1.breed());
  console::write_line(sb);
}

// This code produces the following output :
//
// Mocka, breed: American Shepherd
