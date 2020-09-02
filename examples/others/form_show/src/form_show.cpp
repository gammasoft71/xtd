#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace example {
  class form1 : public form {
  public:
    form1() {
      client_size({320, 425});
      controls().push_back_range({button_modal, button_top_most, button_modeless, button_normal});
      padding(5);
      text("Form show example");

      button_normal.dock(xtd::forms::dock_style::top);
      button_normal.height(100);
      button_normal.text("Show normal");
      button_normal.click += [&] {
        auto dialog = control::create<form>("dialog show normal", {}, {250, 100});
        dialog->show();
        dialogs.push_back(std::move(dialog));
      };
      
      button_modeless.dock(xtd::forms::dock_style::top);
      button_modeless.height(100);
      button_modeless.text("Show modeless");
      button_modeless.click += [&] {
        auto dialog = control::create<form>("dialog show modeless", {}, {250, 100});
        dialog->owner(*this);
        dialog->show();
        dialogs.push_back(std::move(dialog));
      };
      
      button_top_most.dock(xtd::forms::dock_style::top);
      button_top_most.height(100);
      button_top_most.text("Show top most");
      button_top_most.click += [&] {
        auto dialog = control::create<form>("dialog top most", {}, {250, 100});
        dialog->top_most(true);
        dialog->show();
        dialogs.push_back(std::move(dialog));
      };

      button_modal.dock(xtd::forms::dock_style::fill);
      button_modal.text("Show modal");
      button_modal.click += [&] {
        auto dialog = control::create<form>("dialog show modal", {}, {250, 100});
        dialog->show_dialog(*this);
      };
    }
    
    static void main() {
      application::run(form1());
    }
    
  private:
    button button_normal;
    button button_modeless;
    button button_top_most;
    button button_modal;
    vector<shared_ptr<form>> dialogs;
  };
}

startup_(example::form1);
