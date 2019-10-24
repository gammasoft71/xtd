#include <xtd/xtd.forms>
#include <FL/Fl.H>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Manual test");
    
    progress1.parent(*this);
    progress1.location({50, 50});
    progress1.width(200);
    progress1.style(progress_bar_style::marquee);
  }
  
private:
  progress_bar progress1;
};

int main() {
  application::run(form1());
}
