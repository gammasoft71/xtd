#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    auto names = list<string> {};
    names.add("Bruce");
    names.add("Alfred");
    names.add("Tim");
    names.add("Richard");

    names.for_each(action<const string&> {print});
    
    names.for_each(action<const string&> {[](const string& name) {
      console::write_line(name);
    }});
  }
  
private:
  static void print(const string& s) {
    console::write_line(s);
  }
};

startup_(example::main);

// This code produces the following output :
//
// Bruce
// Alfred
// Tim
// Richard
// Bruce
// Alfred
// Tim
// Richard
