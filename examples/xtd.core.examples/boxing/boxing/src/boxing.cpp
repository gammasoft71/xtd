#include <xtd/collections/specialized/string_pair>
#include <xtd/boxing>
#include <xtd/console>
#include <xtd/environment>
#include <vector>

using namespace xtd;
using namespace xtd::collections::specialized;

// This class is not realistic, it is just to illustrate the example.
class setup_serializer : public object {
public:
  using pair_collection = std::vector<string_pair>;
  
  setup_serializer() = default;
  
  // The add_key_value method has an xtd::object as the second parameter to force
  // the application to use the boxing method for native and non-native setup parameters.
  void add_key_value(const ustring& key, const object& value) {
    key_values_.push_back({key, value.to_string()});
  }
  
  void title(const ustring& title) {title_ = title;}
  
  ustring to_string() const noexcept override {
    auto result = ustring::format("[{}]{}{}", title_, environment::new_line());
    for (const auto& [key, value] : key_values_)
      result += ustring::format("{}={}{}", key, value, environment::new_line());
    return result;
  }
  
private:
  pair_collection key_values_;
  ustring title_;
};

struct setup {
  int x = 0;
  int y = 0;
  int width = 0;
  int height = 0;
  ustring text;
  xtd::version version;
};

auto main() -> int {
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

// This code produces the following output:
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
