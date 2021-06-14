#include <filesystem>
#include <xtd/xtd.core>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/priority_class.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

class xtd_core_manual_test {
public:
  static void main() {
    try {
      using_(process process) {
        process.start_info().file_name("ls");
        process.start_info().use_shell_execute(true);
        process.start_info().verb("");
        process.start_info().arguments("-lia");
        //process.start_info().redirect_standard_output(true);
        process.start();
        //console::write(stream_reader(process.standard_output()).read_to_end());
        process.wait_for_exit();
      }
    } catch(const invalid_operation_exception& e) {
      console::write_line(e.message());
    }
    
    /*
    auto target_directory = temp_directory_path()/"xtd.core.manual_tests";
    create_directory(target_directory);
    file::write_all_text(target_directory/"echo_out.cmd", "echo \"$*\"");
    permissions(target_directory/"echo_out.cmd", perms::owner_all);
    file::write_all_text(target_directory/"echo_err.cmd", ">&2 echo \"$*\"");
    permissions(target_directory/"echo_err.cmd", perms::owner_all);

    try {
      using_(process process) {
        process.start_info().file_name(target_directory/"echo_err.cmd");
        process.start_info().use_shell_execute(false);
        process.start_info().arguments("Hello_world");
        //process.start_info().redirect_standard_output(true);
        process.start_info().redirect_standard_error(true);
        process.start();
        //console::write(stream_reader(process.standard_output()).read_to_end());
        process.wait_for_exit();
      }
    } catch(const invalid_operation_exception& e) {
      console::write_line(e.message());
    }
     */

    /*
    if (environment::os_version().is_windows_platform()) file::write_all_text(target_directory/"wait.cmd", "@echo \"Wait %* milliseconds...\"\n@sleepfor %*");
    else file::write_all_text(target_directory/"wait.cmd", "echo \"Wait $* milliseconds...\"\nsleepfor $*");
    permissions(target_directory/"wait.cmd", perms::owner_all);

    try {
      using_(process process) {
        process.start_info().file_name(target_directory/"wait.cmd");
        process.start_info().use_shell_execute(false);
        process.start_info().arguments("1000");
        process.start();
        process.wait_for_exit();
        process.start_info().arguments("2000");
        process.start();
        //process.wait_for_exit();
        process.start_info().arguments("3000");
        process.start();
        process.wait_for_exit();
      }
    } catch(const invalid_operation_exception& e) {
      console::write_line(e.message());
    }
     */
  }
};

startup_(xtd_core_manual_test);
