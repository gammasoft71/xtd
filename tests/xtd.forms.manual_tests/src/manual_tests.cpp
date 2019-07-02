#include <iostream>
#include <xtd/forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {    
    this->client_size_changed += [&](const control& sender, const xtd::event_args& e) {
      std::cout << "client_size_changed " << this->client_size() << std::endl;
    };
    
    this->location_changed += [&](const control& sender, const xtd::event_args& e) {
      std::cout << "location_changed " << this->location() << std::endl;
    };
    
    this->size_changed += [&](const control& sender, const xtd::event_args& e) {
      std::cout << "size_changed " << this->size() << std::endl;
    };

    this->text("form1");
    this->location({100, 100});
    this->size({300, 300});

    ctl.parent(*this);
    ctl.size({100, 100});
  }
  
private:
  control ctl;
};

// The main entry point for the application.
int main() {
  application_informations::company_name("gammasoft71");
  application_informations::product_name("manual_tests");
  application_informations::product_version("1.0.0");
  application::run(form1());
}
