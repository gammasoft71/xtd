#include <filesystem>
#include <xtd/xtd>

using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    if (environment::os_version().is_windows_platform()) file::write_all_text(temp_directory_path()/"say.cmd", "@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say_.vbs\n@echo Speaker.Speak %* >> %TEMP%\\say_.vbs\n@%TEMP%\\say_.vbs");
    else if (environment::os_version().is_macos_platform()) file::write_all_text(temp_directory_path()/"say.cmd", "say $*");
    else file::write_all_text(temp_directory_path()/"say.cmd", "spd-say $*");
    permissions(temp_directory_path()/"say.cmd", perms::owner_all);
    
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += [&] {
      process::start(process_start_info((temp_directory_path()/"say.cmd").string(), "\"Hello, World!\"").use_shell_execute(false).create_no_window(true));
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
