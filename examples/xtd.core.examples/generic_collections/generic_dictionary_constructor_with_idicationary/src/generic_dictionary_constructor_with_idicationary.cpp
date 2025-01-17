#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    // Create a new sorted dictionary of strings, with string keys.
    auto open_with = sorted_dictionary<string, string> {};
    
    // Add some elements to the dictionary.
    open_with.add("txt", "notepad.exe");
    open_with.add("bmp", "paint.exe");
    open_with.add("dib", "paint.exe");
    open_with.add("rtf", "wordpad.exe");
    
    // Create a dictionary of strings with string keys, and
    // initialize it with the contents of the sorted dictionary.
    auto copy = dictionary<string, string>(open_with);
    
    // List the contents of the copy.
    console::write_line();
    for(const key_value_pair<string, string>& kvp : copy)
      console::write_line("key = {0}, value = {1}", kvp.key(), kvp.value());
  }
};

startup_(example::main);

// This code produces the following output :
//
// key = txt, value = notepad.exe
// key = bmp, value = paint.exe
// key = dib, value = paint.exe
// key = rtf, value = wordpad.exe
