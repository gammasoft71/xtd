#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form_test : public form {
public:
  form_test() {
    this->text("xtd.forms.manual_tests");
    
    this->progress1.parent(*this);
    this->progress1.style(progress_bar_style::marquee);
    this->progress1.location({10, 30});
    this->progress1.size({200, 23});
    this->progress1.value(50);
    cdebug << format("pb = {}", this->progress1) << endl;
  }
  
private:
  progress_bar progress1;
};

int main() {
  application::run(form_test());
}
