#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Switch button example");
    
    paint += [](control& sender, paint_event_args& e) {
      e.graphics().fill_rectangle(solid_brush(color::spring_green), 50, 50, 101, 101);
      e.graphics().fill_ellipse(solid_brush(color::dark_blue), 50, 50, 101, 101);
    };

    /*
    switch_button1.parent(*this);
    switch_button1.location({10, 10});
    //switch_button1.width(100);
    switch_button1.rounded(true);
     */
  }
  
private:
  switch_button switch_button1;
};

int main() {
  application::run(form1());
}
