#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace example {
  class form1 : public form {
  public:
    form1() {
      text("Form show");
      client_size({320, 320});
      controls().push_back_range({button_modal, button_modeless, button_normal});
      padding(5);
      
      dialog.client_size({200, 100});
      
      button_normal.height(100);
      button_normal.dock(xtd::forms::dock_style::top);
      button_normal.text("Show normal");
      button_normal.click += [&] {
        dialog.text("dialog show normal");
        dialog.show();
      };
      
      button_modeless.height(100);
      button_modeless.dock(xtd::forms::dock_style::top);
      button_modeless.text("Show modeless");
      button_modeless.click += [&] {
        //dialog.owner = *this;
        dialog.text("dialog show modeless");
        dialog.show();
      };

      button_modal.height(100);
      button_modal.dock(xtd::forms::dock_style::fill);
      button_modal.text("Show modal");
      button_modal.click += [&] {
        dialog.text("dialog show modal");
        dialog.show_dialog(*this);
      };
    }
    
    static void main() {
      application::run(form1());
    }
    
  private:
    button button_normal;
    button button_modeless;
    button button_modal;
    form dialog;
  };
}

startup_(example::form1);
