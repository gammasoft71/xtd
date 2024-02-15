# Form

## In This Section

* [Overview](#overview)
  * [Show](#show)
  * [Start position](#start-position)
  * [Window state](#window-state)
* [Form](#form)
* [MDI and child](#mdi-and-child)
* [dialog](#dialog)

## Overview

The forms are what we call top level controls.

There are three types of forms:
* form
* MDI and child
* dialog

### Show

These forms can be displayed in different ways:
* Show normal : shows [xtd::forms::form](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form.h) normally.
* Show modeless : shows modeless dialog on a [xtd::forms::form](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form.h) (specified by handle from [xtd::forms::iw32_window](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/iw32_window.h)) or on application.
* Show top most : shows top most form on application.
* Show modal : shows modal dialog on a form (specified by handle from [xtd::forms::iw32_window](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/iw32_window.h)) or on application.
* Show sheet : Shows sheet dialog on a form (specified by handle from [xtd::forms::iw32_window](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/iw32_window.h)).
* Show sheet modal : Shows sheet modal dialog on a form (specified by handle from [xtd::forms::iw32_window](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/iw32_window.h)).

#### Remarks

Sheet is a special dialog mode on macOS :
* TThe dialog is shown centered on form (if form is specifed) without title.
* The method is not blocking and you must retrieve the result of the dialog at the closing event.
* On other platforms than macOS, is a normal dialog, but you must also retrieve the result of the dialog on the close event but the method is blocking (this can be changed in the future). 

#### Example

The following example demonstates the different ways to display a [xtd::forms::form](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form.h).

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
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
      button_normal.click += [&] {
        auto dialog = make_unique<form>();
        dialog->text("dialog show normal");
        dialog->size({250, 100});
        dialog->show();
        dialogs.push_back(std::move(dialog));
      };
      
      button_modeless.text("Show modeless");
      button_modeless.click += [&] {
        auto dialog = make_unique<form>();
        dialog->text("dialog show modeless");
        dialog->size({250, 100});
        dialog->owner(*this).show();
        dialogs.push_back(std::move(dialog));
      };
      
      button_top_most.text("Show top most");
      button_top_most.click += [&] {
        auto dialog = make_unique<form>();
        dialog->text("dialog top most");
        dialog->size({250, 100});
        dialog->top_most(true).show();
        dialogs.push_back(std::move(dialog));
      };
      
      button_modal.text("Show modal");
      button_modal.click += [&] {
        auto dialog = form::create("dialog show modal", size {250, 100});
        dialog.show_dialog(*this);
      };
      
      button_sheet.text("Show sheet");
      button_sheet.click += [&] {
        auto dialog = make_unique<form>();
        dialog->text("dialog show sheet");
        dialog->size({250, 100});
        dialog->key_up += [&](object & control, key_event_args & e) {
          if (e.key_code() == keys::escape) as<form&>(control).close();
        };
        dialog->show_sheet(*this);
        dialogs.push_back(std::move(dialog));
      };
      
      button_sheet_modal.text("Show sheet modal");
      button_sheet_modal.click += [&] {
        auto dialog = form::create("dialog show sheet modal", size {250, 100});
        dialog.key_up += [&](object & control, key_event_args & e) {
          if (e.key_code() == keys::escape) as<form&>(control).close();
        };
        dialog.show_sheet_dialog(*this);
      };
    }
    
    static auto main() {
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
```

### Start position

A form can be shown with different start positions:
* [xtd::forms::form_start_postion::manual](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_start_postion.h) : The position of the form is determined by the Location property.
* [xtd::forms::form_start_postion::center_screen](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_start_postion.h) : The form is centered on the current display, and has the dimensions specified in the form's size.
* [xtd::forms::form_start_postion::windows_default_location](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_start_postion.h) : The form is positioned at the Windows default location and has the dimensions specified in the form's size.
* [xtd::forms::form_start_postion::windows_default_bounds](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_start_postion.h) : The form is positioned at the Windows default location and has the bounds determined by Windows default.
* [xtd::forms::form_start_postion::center_parent](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_start_postion.h) : The form is centered within the bounds of its parent form.

### Window state

A form can be shown with different states:
* [xtd::forms::form_window_state::normal](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_window_state.h) : A default sized window.
* [xtd::forms::form_window_state::minimized](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_window_state.h) : A minimized window.
* [xtd::forms::form_window_state::maximized](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_window_state.h) : A maximized window.
* [xtd::forms::form_window_state::full_screen](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form_window_state.h) : A full screen window.

#### Examples

The folloing example demonstates the different ways to display a [xtd::forms::form](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form.h).

```cpp
#define TRACE
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    *this << button_full_screen << button_maximize << button_minimize << button_normal;
    text("Window state example");
    resize += [&] {
      button_full_screen.enabled(window_state() != form_window_state::full_screen && window_state() != form_window_state::maximized);
      button_maximize.enabled(window_state() != form_window_state::maximized && window_state() != form_window_state::full_screen);
      button_normal.enabled(window_state() != form_window_state::normal);
      button_minimize.enabled(window_state() != form_window_state::minimized && window_state() != form_window_state::full_screen);

      ctrace << ustring::format("resize: {}, {}", size(), window_state()) << std::endl;
    };
    client_size({410, 200});
    window_state(form_window_state::maximized);
    
    button_full_screen.location({10, 10});
    button_full_screen.text("Full screen");
    button_full_screen.width(90);
    button_full_screen.click += [&] {
      window_state(form_window_state::full_screen);
    };

    button_maximize.location({110, 10});
    button_maximize.text("Maximize");
    button_maximize.width(90);
    button_maximize.click += [&] {
      window_state(form_window_state::maximized);
    };
    
    button_normal.location({210, 10});
    button_normal.text("Normal");
    button_normal.width(90);
    button_normal.click += [&] {
      window_state(form_window_state::normal);
    };

    button_minimize.location({310, 10});
    button_minimize.text("Minimize");
    button_minimize.width(90);
    button_minimize.click += [&] {
      window_state(form_window_state::minimized);
    };
  }
  
private:
  button button_full_screen;
  button button_maximize;
  button button_normal;
  button button_minimize;
};

auto main()->int {
  application::run(form1());
}
```

## Form

The [xtd::forms::form](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form.h) represents a window or dialog box that makes up an application's user interface.

## MDI and child

Not yet implemented.

## Dialog

A dialog does not have a defined type, it is a [xtd::forms::form](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form.h).

The only difference is that a dialog cannot have a menu, a toolbar or a status bar.

If any of the above elements are accidentally present, an [xtd::invalid_operation_exception](https://github.com/gammasoft71/xtd/blob/master/src/xtd.core/include/xtd/invalid_operation_exception.h) will be generated during the dialog show.

### Examples

The following example demontrates how to create your own dialog :

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class user_input_dialog : public form {
public:
  user_input_dialog() {
    accept_button(button_ok);
    cancel_button(button_cancel);
    client_size({200, 80});
    form_border_style(forms::form_border_style::fixed_dialog);
    minimize_box(false);
    maximize_box(false);
    show_icon(false);
    start_position(form_start_position::center_parent);
    text("User input dialog");
    controls().push_back_range({input, button_ok, button_cancel});

    input.location({10, 10});
    input.width(180);

    button_cancel.dialog_result(forms::dialog_result::cancel);
    button_cancel.location({10, 50});
    button_cancel.text("Cancel");
    button_cancel.width(85);

    button_ok.dialog_result(forms::dialog_result::ok);
    button_ok.location({105, 50});
    button_ok.text("OK");
    button_ok.width(85);

    active_control(input);
  }
  
  virtual ustring input_text() const {return input.text();}
  virtual user_input_dialog& input_text(const ustring& input_text) {
    input.text(input_text);
    return *this;
  }

private:
  text_box input;
  button button_cancel;
  button button_ok;
};

class form1 : public form {
public:
  form1() {
    controls().push_back_range({button_dialog, input_text});
    size({800, 450});
    text("User dialog exemple");
    
    input_text.auto_size(true);
    input_text.location({10, 50});
    input_text.text("User input text");
    
    button_dialog.location({10, 10});
    button_dialog.text("Dialog...");
    button_dialog.click += [&] {
      dialog.input_text(input_text.text());
      if (dialog.show_dialog(*this) == forms::dialog_result::ok)
        input_text.text(dialog.input_text());
    };
  }
  
private:
  user_input_dialog dialog;
  button button_dialog;
  label input_text;
};

auto main()->int {
  application::run(form1());
}
```

## See also

* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)
