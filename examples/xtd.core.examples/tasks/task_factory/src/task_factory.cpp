#include <xtd/xtd>

class example {
public:
  static auto main() async_ {
    auto tasks = array<task<>>(2);
    auto files = array<string> {};
    auto dirs = array<string> {};
    auto docs_directory = environment::get_folder_path(environment::special_folder::my_documents);
    
    tasks[0] = task<>::factory().start_new([&] {files = directory::get_files(docs_directory);});
    tasks[1] = task<>::factory().start_new([&] {dirs = directory::get_directories(docs_directory);});
    
    co_await task<>::factory().continue_when_all(tasks, [&] {
      console::write_line("{} contains: ", docs_directory);
      console::write_line("   {} subdirectories", dirs.length());
      console::write_line("   {} files", files.length());
    });
  }
};

startup_(example::main);

// This code produces the following output :
//
// /Users/<username> contains:
//    63 subdirectories
//    24 files
