#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace manual_test {
  class form1 : public form {
  public:
    form1() {
      text("Manual test");
      controls().push_back_range({text_box1, text_box2, button1});

      text_box1.location({20, 20});
      
      text_box2.location({20, 60});
      text_box2.got_focus += [] {
        cdebug << "got focus" << endl;
      };
      text_box2.lost_focus += [] {
        cdebug << "lost focus" << endl;
      };

      button1.location({20, 100});
      button1.click += [this] {
        active_control(text_box2);
      };
      
      active_control(text_box2);
    }
    
  private:
    text_box text_box1;
    text_box text_box2;
    button button1;
  };
}

int main() {
  application::run(manual_test::form1());
}
