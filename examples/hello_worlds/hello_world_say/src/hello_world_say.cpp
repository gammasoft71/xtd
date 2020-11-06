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
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += [&] {
      process::start(process_start_info().file_name("say").arguments("\"Hello world\"").window_style(process_window_style::hidden)).wait_for_exit();
    };
  }
  
private:
  button button1;
};

int main() {
  if (environment::os_version().is_windows_platform()) {
    file::write_all_lines("say.bat", {
      "@echo off",
      "echo Dim Speak >> %TEMP%\\speak.vbs",
      "echo Set Speak=CreateObject(\"sapi.spvoice\") >> %TEMP%\\speak.vbs",
      "echo Speak.Speak %* >> %TEMP%\\speak.vbs",
      "%TEMP%\\speak.vbs",
      "del %TEMP%\\speak.vbs"
    });
  } else if (environment::os_version().is_linux_platform()) {
    file::write_all_lines("say", {
      "#!/bin/bash",
      "echo $* | espeak"
    });
    permissions("say", perms::owner_all);
  }
  
  application::run(form1());
}
