#include <xtd/xtd>

using namespace xtd::globalization;

class form1 : public form {
public:
  form1() {
    text("Translator example"_t);
    client_size({500, 300});
    controls().add_range({open_button, close_button, text_label});
    
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

auto main() -> int {
  //culture_info::current_culture(culture_info {"ar-MA"});
  //culture_info::current_culture(culture_info {"es-ES"});
  culture_info::current_culture(culture_info {"fr-FR"});
  //culture_info::current_culture(culture_info {"ru-RU"});
  application::run(form1 {});
}
