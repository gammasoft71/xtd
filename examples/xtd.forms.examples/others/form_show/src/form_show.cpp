#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace example {
  class form1 : public form {
  public:
    form1() {
      client_size({320, 610});
      controls().push_back(layout_panel);
      padding(5);
      text("Form show example");

      layout_panel.dock(dock_style::fill);
      layout_panel.controls().push_back_range({button_normal, button_modeless, button_top_most, button_modal, button_sheet, button_sheet_modal});

      button_normal.text("Show normal");
      button_normal.click += [&] {
        auto dialog = control::create<form>("dialog show normal", {}, {250, 100});
        dialog->show();
        dialogs.push_back(move(dialog));
      };
      
      button_modeless.text("Show modeless");
      button_modeless.click += [&] {
        auto dialog = control::create<form>("dialog show modeless", {}, {250, 100});
        dialog->owner(*this).show();
        dialogs.push_back(move(dialog));
      };
      
      button_top_most.text("Show top most");
      button_top_most.click += [&] {
        auto dialog = control::create<form>("dialog top most", {}, {250, 100});
        dialog->top_most(true).show();
        dialogs.push_back(move(dialog));
      };

      button_modal.text("Show modal");
      button_modal.click += [&] {
        auto dialog = control::create<form>("dialog show modal", {}, {250, 100});
        dialog->show_dialog(*this);
      };

      button_sheet.text("Show sheet");
      button_sheet.click += [&] {
        auto dialog = control::create<form>("dialog show sheet", {}, {250, 100});
        dialog->key_up += [&](control& control, key_event_args& e) {
          if (e.key_code() == keys::escape) static_cast<form&>(control).close();
        };
        dialog->show_sheet(*this);
        dialogs.push_back(move(dialog));
      };

      button_sheet_modal.text("Show sheet modal");
      button_sheet_modal.click += [&] {
        auto dialog = control::create<form>("dialog show sheet modal", {}, {250, 100});
        dialog->key_up += [&](control& control, key_event_args& e) {
          if (e.key_code() == keys::escape) static_cast<form&>(control).close();
        };
        dialog->show_sheet_dialog(*this);
      };
    }
    
    static void main() {
      application::run(form1());
    }
    
  private:
    vertical_layout_panel layout_panel;
    button button_normal;
    button button_modeless;
    button button_top_most;
    button button_modal;
    button button_sheet;
    button button_sheet_modal;
    vector<shared_ptr<form>> dialogs;
  };
}

startup_(example::form1);
