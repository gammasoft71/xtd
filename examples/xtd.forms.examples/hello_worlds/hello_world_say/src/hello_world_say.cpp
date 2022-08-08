#include <xtd/xtd>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    if (environment::os_version().is_windows()) file::write_all_text(say_cmd_file, "@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say_.vbs\n@echo Speaker.Speak \"%*\" >> %TEMP%\\say_.vbs\n@%TEMP%\\say_.vbs");
    else if (environment::os_version().is_macos()) file::write_all_text(say_cmd_file, "say \"$*\"");
    else file::write_all_text(say_cmd_file, "spd-say \"$*\"");
    file::set_permissions(say_cmd_file, file_permissions::owner_all);
    
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += [&] {
      process::start(process_start_info(say_cmd_file, "Hello, World!").use_shell_execute(false).create_no_window(true));
    };
  }
  
private:
  ustring say_cmd_file = io::path::combine(io::path::get_temp_path(), "say.cmd");
  button button1;
};

int main() {
  application::run(form1 {});
}
