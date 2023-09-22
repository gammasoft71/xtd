#include <xtd/io/file>
#include <xtd/io/file_info>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    try {
      // original_file and file_to_replace must contain the path to files that already exist in the
      // file system. backup_of_file_to_replace is created during the execution of the Replace method.
      
      auto original_file = "test.txt"_s;
      auto file_to_replace = "test2.txt"_s;
      auto backup_of_file_to_replace = "test2.txt.bak"_s;
      
      if (file::exists(original_file) && file::exists(file_to_replace)) {
        console::write_line("Move the contents of " + original_file + " into " + file_to_replace + ", delete " + original_file + ", and create a backup of " + file_to_replace + ".");
        
        // Replace the file.
        replace_file(original_file, file_to_replace, backup_of_file_to_replace);
        
        console::write_line("Done");
      } else
        console::write_line("Either the file {0} or {1} doesn't exist.", original_file, file_to_replace);
    } catch (const system_exception& e) {
      console::write_line(e.message());
    }
    
    console::read_key();
  }
  
  // Move a file into another file, delete the original, and create a backup of the replaced file.
  static void replace_file(const ustring& file_to_move_and_delete, const ustring& file_to_replace, const ustring& backup_of_file_to_replace) {
    // Create a new file_info object.
    auto f_info = file_info {file_to_move_and_delete};
    
    // replace the file.
    f_info.replace(file_to_replace, backup_of_file_to_replace);
  }
};

startup_(program::main);

// This code produces the following output :
//
// Move the contents of test.txt into test2.txt, delete test.txt, and create a backup of test2.txt.
// Done
