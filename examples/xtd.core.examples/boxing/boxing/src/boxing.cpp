#include <xtd/xtd>

// This class is not realistic, it is just to illustrate the example.
class setup_serializer : public object {
public:
  using pair_collection = list<collections::specialized::string_key_value_pair>;
  
  setup_serializer() = default;
  
  // The add_key_value method has an xtd::object as the second parameter to force
  // the application to use the boxing method for native and non-native setup parameters.
  auto add_key_value(const string& key, const object& value) -> void {
    key_values_.add({key, value.to_string()});
  }
  
  auto title(const string& title) -> void {title_ = title;}
  
  auto to_string() const noexcept -> string override {
    auto result = string::format("[{}]{}{}", title_, environment::new_line());
    for (const auto& [key, value] : key_values_)
      result += string::format("{}={}{}", key, value, environment::new_line());
    return result;
  }
  
private:
  pair_collection key_values_;
  string title_;
};

auto main() -> int {
  struct setup {
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    string text;
    xtd::version version;
  };
  
  auto my_application_setup = setup {10, 10, 300, 300, "My application", {1, 2, 3}};
  
  auto serializer = setup_serializer {};
  serializer.title("My application setup");
  serializer.add_key_value("x", boxing(my_application_setup.x));
  serializer.add_key_value("y", boxing(my_application_setup.y));
  serializer.add_key_value("width", boxing(my_application_setup.width));
  serializer.add_key_value("height", boxing(my_application_setup.height));
  serializer.add_key_value("text", boxing(my_application_setup.text));
  serializer.add_key_value("version", boxing(my_application_setup.version));
  
  console::write_line("result :{0}{0}{1}", environment::new_line(), serializer);
}

// This code produces the following output :
//
// result :
//
// [My application setup]
// x=10
// y=10
// width=300
// height=300
// text=My application
// version=1.2.3
//
