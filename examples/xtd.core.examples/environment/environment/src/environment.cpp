#include <xtd/xtd>

using namespace xtd;

namespace environment_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      ustring str;
      ustring nl = environment::new_line();
      //
      console::write_line();
      console::write_line("-- environment members --");
      
      //  Invoke this sample with an arbitrary set of command line arguments.
      console::write_line("command_line: {}", environment::command_line());
      
      auto arguments = environment::get_command_line_args();
      console::write_line("get_command_line_args: {}", ustring::join(", ", arguments));
      
      //  <-- Keep this information secure! -->
      console::write_line("current_directory: {}", environment::current_directory());
      
      console::write_line("exit_code: {}", environment::exit_code());
      
      console::write_line("has_shutdown_started: {}", environment::has_shutdown_started());
      
      //  <-- Keep this information secure! -->
      console::write_line("machine_name: {}", environment::machine_name());
      
      console::write_line("new_line: {0}  first line{0}  second line{0}  third line", environment::new_line());
      
      console::write_line("os_version: {}", environment::os_version());
      
      console::write_line("stack_trace: '{}'", environment::stack_trace());
      
      //  <-- Keep this information secure! -->
      console::write_line("system_directory: {}", environment::system_directory());
      
      console::write_line("tick_count: {}", environment::tick_count());
      
      //  <-- Keep this information secure! -->
      console::write_line("user_domain_name: {}", environment::user_domain_name());
      
      console::write_line("user_interactive: {}", environment::user_interactive());
      
      //  <-- Keep this information secure! -->
      console::write_line("user_name: {}", environment::user_name());
      
      console::write_line("version: {}", environment::version());
      
      console::write_line("working_set: {}", environment::working_set());
      
      //  No example for Exit(exitCode) because doing so would terminate this example.
      
      //  <-- Keep this information secure! -->
      ustring query = ustring::format("My home folder is %{}% and user is %{}%", environment::os_version().is_windows_platform() ? "HOMEPATH" : "HOME", environment::os_version().is_windows_platform() ? "USERNAME" : "USER");
      str = environment::expand_environment_variables(query);
      console::write_line("expand_environment_variables: {}  {}",  nl, str);
      
      console::write_line("get_environment_variable: {}  My temporary directory is {}.", nl,  environment::get_environment_variable(environment::os_version().is_windows_platform() ? "TEMP" : "TMPDIR"));
      
      console::write_line("get_environment_variables: ");
      auto environment_variables = environment::get_environment_variables();
      for (auto de : environment_variables)
        console::write_line(" {} = {1}", de.first, de.second);
        
      console::write_line("get_folder_path: {}", environment::get_folder_path(environment::special_folder::system));
      
      auto drives = environment::get_logical_drives();
      console::write_line("GetLogicalDrives: {}", ustring::join(", ", drives));
    }
  };
}

startup_(environment_example::program);

// This example produces results similar to the following:
// (Any result that is lengthy or reveals information that should remain
// secure has been omitted and marked "!---OMITTED---!".)
//
// -- environment members --
// command_line: !---OMITTED---!/environment ARBITRARY TEXT
// get_command_line_args: !---OMITTED---!/environment, ARBITRARY, TEXT
// current_directory: !---OMITTED---!/environment/environment/Debug
// exit_code: 0
// has_shutdown_started: false
// machine_name: !---OMITTED---!
// new_line:
// first line
// second line
// third line
// os_version: macOS 12.6.0
// stack_trace: '   at xtd::environment::stack_trace()
//    at environment_example::program::main()
//    at main::startup::run(void (*)(), int, char**)'
// system_directory: /System
// tick_count: 3.01:15:01:827000000
// user_domain_name: !---OMITTED---!
// user_interactive: true
// user_name: !---OMITTED---!
// version: 0.2.0
// working_set: 0
// expand_environment_variables:
// My home folder is /Users/!---OMITTED---! and user is !---OMITTED---!
// get_environment_variable:
// My temporary directory is /var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T/.
// get_environment_variables:
// !---OMITTED---!
// get_folder_path: /System
// GetLogicalDrives: /, /dev, /System/Volumes/Hardware, /System/Volumes/Update, /System/Volumes/Preboot, /System/Volumes/xarts, /System/Volumes/VM, /System/Volumes/Data, /System/Volumes/iSCPreboot, /System/Volumes/Data/home, /Volumes/Data
