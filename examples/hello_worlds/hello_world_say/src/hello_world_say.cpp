#include <xtd/xtd.forms>

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
  if (environment::os_version().is_windows_platform()) file::write_all_text("say.bat", "@echo off\necho Dim Speak >> %TEMP%\\speak.vbs\necho Set Speak=CreateObject(\"sapi.spvoice\") >> %TEMP%\\speak.vbs\necho Speak.Speak %*>> %TEMP%\\speak.vbs\n%TEMP%\\speak.vbs\ndel %TEMP%\\speak.vbs");
  application::run(form1());
}
