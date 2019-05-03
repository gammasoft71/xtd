#include <xtd/environment>
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;
  cout << "command line = " << environment::command_line() << environment::new_line;
  cout << "Current directory = " << environment::current_directory() << environment::new_line;
  cout << "Current thread id = " << environment::current_thread_id() << environment::new_line;
  cout << "Machine name = " << environment::machine_name() << environment::new_line;
  cout << "Os version = " << environment::os_version() << environment::new_line;
  cout << "Processor count = " << environment::processor_count() << environment::new_line;
  cout << "System page size = " << environment::system_page_size() << environment::new_line;
  cout << "System directory = " << environment::system_directory() << environment::new_line;
  cout << "User domain name = " << environment::user_domain_name() << environment::new_line;
  cout << "User name = " << environment::user_name() << environment::new_line;
  cout << "Tick count = " << environment::tick_count() << environment::new_line;
  environment::exit(42);
}

// This code produces the following output with colors:
//
// Hello, World!
