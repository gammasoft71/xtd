#include <xtd/io/file_info>
#include <xtd/io/path>
#include <xtd/console>
#include <xtd/startup>
#include <xtd/using>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    auto path = path::get_temp_file_name();
    file_info fi1(path);
    
    // Create a file to write to.
    
    using_(auto sw = fi1.create_text()) {
      sw.write_line("Hello");
      sw.write_line("And");
      sw.write_line("Welcome");
    }
    
    // Open the file to read from.
    using_(auto sr = fi1.open_text()) {
      while (!sr.end_of_stream())
        console::write_line(sr.read_line());
    }
    
    try {
      auto path2 = path::get_temp_file_name();
      file_info fi2(path2);
      
      // Ensure that the target does not exist.
      fi2.remove();
      
      // Copy the file.
      fi1.copy_to(path2);
      console::write_line("{} was copied to {}.", path, path2);
      
      // Delete the newly created file.
      fi2.remove();
      console::write_line("{} was successfully deleted.", path2);
    } catch (const system_exception& e) {
      console::write_line("The process failed: {}", e.to_string());
    }
  }
};

startup_(program);

// This code produces the following output :
// Hello
// And
// Welcome
// /var/folders/d5/k7mxnq214dxf3jbvvvhpbfqh0000gn/T/tmp99dcece9.tmp was copied to /var/folders/d5/k7mxnq214dxf3jbvvvhpbfqh0000gn/T/tmp235be07d.tmp.
// /var/folders/d5/k7mxnq214dxf3jbvvvhpbfqh0000gn/T/tmp235be07d.tmp was successfully deleted.
