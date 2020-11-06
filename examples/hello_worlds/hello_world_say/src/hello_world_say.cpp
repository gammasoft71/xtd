#include <filesystem>
#include <xtd/xtd.forms>

using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    if (environment::os_version().is_windows_platform())
      file::write_all_lines(temp_directory_path()/"say.cmd", {
        "@echo off",
        "echo Dim Speak >> %TEMP%\\speak.vbs",
        "echo Set Speak=CreateObject(\"sapi.spvoice\") >> %TEMP%\\speak.vbs",
        "echo Speak.Speak %* >> %TEMP%\\speak.vbs",
        "%TEMP%\\speak.vbs",
        "del %TEMP%\\speak.vbs"
      });
    else if (environment::os_version().is_linux_platform())
      file::write_all_lines(temp_directory_path()/"say.cmd", {
        "#!/bin/bash",
        "spd-say \"$*\""
      });
    else if (environment::os_version().is_macos_platform())
      file::write_all_lines(temp_directory_path()/"say.cmd", {
        "#!/bin/bash",
        "say \"$*\""
      });
    permissions(temp_directory_path()/"say.cmd", perms::owner_all);
    
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += [&] {
      process::start(process_start_info().file_name(temp_directory_path()/"say.cmd").arguments("\"Hello, World!\"").window_style(process_window_style::hidden));
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
