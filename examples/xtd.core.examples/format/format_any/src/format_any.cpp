#include <xtd/xtd>

class character {
public:
  character(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}
  
  string to_string() const noexcept {return name_ + " (" + rank_ + ")";}
   
private:
  string name_;
  string rank_;
};

auto main() -> int {
  auto value = std::make_any<int>(42);
  console::out << string::format("{}", value) << environment::new_line;
  
  value = std::make_any<string>("Star Trek: The Next Generation");
  console::out << string::format("{}", value) << environment::new_line;
  
  value = std::make_any<character>("Jean-Luc Picard", "Captain");
  console::out << "Before register_any_stringer : " << string::format("{}", value) << environment::new_line;
  
  register_any_stringer<character>([](auto value) {return value.to_string();});
  console::out << "After register_any_stringer : " << string::format("{}", value) << environment::new_line;
  
  unregister_any_stringer<character>();
  console::out << "After unregister_any_stringer : " << string::format("{}", value) << environment::new_line;
}

// This code produces the following output :
//
// 42
// Star Trek: The Next Generation
// Before register_any_stringer : (unregistered)
// After register_any_stringer : Jean-Luc Picard (Captain)
// After unregister_any_stringer : (unregistered)

