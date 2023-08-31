#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/text_box>
#include <xtd/startup>

using namespace xtd::forms;

class form1 : public form {
public:
  static auto main() {
    application::run(form1 {});
  }
  
  form1() {
    text("Form with CMake assembly info");
    controls().push_back_range({company, product, version, company_name, product_name, product_version});
    client_size({350, 105});
    
    company.auto_size(true);
    company.text("Company name");
    company.location({10, 10});
    company.text_align(content_alignment::middle_left);
    
    product.auto_size(true);
    product.text("Product name");
    product.location({10, 40});
    product.text_align(content_alignment::middle_left);
    
    version.auto_size(true);
    version.text("Product version");
    version.location({10, 70});
    version.text_align(content_alignment::middle_left);
    
    company_name.text(application::company_name());
    company_name.read_only(true);
    company_name.location({120, 10});
    company_name.width(220);
    
    product_name.text(application::product_name());
    product_name.read_only(true);
    product_name.location({120, 40});
    product_name.width(220);
    
    product_version.text(application::product_version());
    product_version.read_only(true);
    product_version.location({120, 70});
    product_version.width(220);
  }
  
private:
  label company;
  label product;
  label version;
  
  text_box company_name;
  text_box product_name;
  text_box product_version;
};

startup_(form1::main);
