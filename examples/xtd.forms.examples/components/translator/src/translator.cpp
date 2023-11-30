#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/message_box>
#include <locale>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Translator example"_t);
    client_size({500, 300});
    controls().push_back_range({open_button, close_button, text_label});
    
    open_button.location({10, 10});
    open_button.text("Open"_t);
    
    close_button.location({100, 10});
    close_button.text("Close"_t);
    
    text_label.location({10, 50});
    text_label.auto_size(true);
    text_label.text("The quick brown fox jumps over the lazy dog."_t);
  }
  
private:
  button open_button;
  button close_button;
  label text_label;
};

auto main()->int {
  try {
    //locale::global(locale {"ar_MA.utf-8"});
    //locale::global(locale {"es_ES.utf-8"});
    //locale::global(locale {"fr_FR.utf-8"});
    locale::global(locale {"ru_RU.utf-8"});
  } catch (const std::exception& e) {
    message_box::show(ustring::format("Make sure specified locale is installed on your system :\n\n{}", e.what()), "Exception");
    return -1;
  }
  application::run(form1 {});
}
