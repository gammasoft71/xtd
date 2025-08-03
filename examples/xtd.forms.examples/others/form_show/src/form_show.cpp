#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/vertical_layout_panel>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::collections::generic;
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
      layout_panel.control_layout_style(button_normal, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_modeless, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_top_most, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_modal, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_sheet, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_sheet_modal, {size_type::auto_size, true});
      
      button_normal.text("Show normal");
      button_normal.click += delegate_ {
        auto dialog = new_ptr<form>();
        dialog->text("dialog show normal");
        dialog->size({250, 100});
        dialog->show();
        dialogs.push_back(dialog);
      };
      
      button_modeless.text("Show modeless");
      button_modeless.click += delegate_ {
        auto dialog = new_ptr<form>();
        dialog->text("dialog show modeless");
        dialog->size({250, 100});
        dialog->owner(*this).show();
        dialogs.push_back(dialog);
      };
      
      button_top_most.text("Show top most");
      button_top_most.click += delegate_ {
        auto dialog = new_ptr<form>();
        dialog->text("dialog top most");
        dialog->size({250, 100});
        dialog->top_most(true).show();
        dialogs.push_back(dialog);
      };
      
      button_modal.text("Show modal");
      button_modal.click += delegate_ {
        auto dialog = form::create("dialog show modal", drawing::size {250, 100});
        dialog.show_dialog(*this);
      };
      
      button_sheet.text("Show sheet");
      button_sheet.click += delegate_ {
        auto dialog = new_ptr<form>();
        dialog->form_border_style(form_border_style::fixed_3d);
        dialog->text("dialog show sheet").size({250, 100});
        dialog->key_up += delegate_(object & control, key_event_args & e) {
          if (e.key_code() == keys::escape) as<form&>(control).close();
        };
        dialog->show_sheet(*this);
        dialogs.push_back(dialog);
      };
      
      button_sheet_modal.text("Show sheet modal");
      button_sheet_modal.click += delegate_ {
        auto dialog = form::create("dialog show sheet modal", drawing::size {250, 100});
        dialog.form_border_style(form_border_style::fixed_3d);
        dialog.key_up += delegate_(object & control, key_event_args & e) {
          if (e.key_code() == keys::escape) as<form&>(control).close();
        };
        dialog.show_sheet_dialog(*this);
      };
    }
    
    static auto main() {
      application::run(form1 {});
    }
    
  private:
    vertical_layout_panel layout_panel;
    button button_normal;
    button button_modeless;
    button button_top_most;
    button button_modal;
    button button_sheet;
    button button_sheet_modal;
    list<ptr<form>> dialogs;
  };
}

startup_(example::form1::main);
