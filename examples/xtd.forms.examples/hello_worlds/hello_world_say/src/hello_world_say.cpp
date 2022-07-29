#include <xtd/xtd>

using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    if (environment::os_version().is_windows()) file::write_all_text(io::path::combine(io::path::get_temp_path(), "say.cmd"), "@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say_.vbs\n@echo Speaker.Speak %* >> %TEMP%\\say_.vbs\n@%TEMP%\\say_.vbs");
    else if (environment::os_version().is_macos()) file::write_all_text(io::path::combine(io::path::get_temp_path(), "say.cmd"), "say $*");
    else file::write_all_text(io::path::combine(io::path::get_temp_path(), "say.cmd"), "spd-say $*");
    file::set_permissions(io::path::combine(io::path::get_temp_path(), "say.cmd"), file_permissions::owner_all);
    
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += [&] {
      process::start(process_start_info((temp_directory_path() / "say.cmd").string(), "\"Hello, World!\"").use_shell_execute(false).create_no_window(true));
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
