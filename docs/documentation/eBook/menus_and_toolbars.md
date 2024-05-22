# Menus and Toolbars

A menu is one of the most visible parts of the GUI application. 
It is a group of commands located in various menus. 
While in console applications you had to remember all those arcane commands, here we have most of the commands grouped into logical parts. 
There are accepted standards that further reduce the amount of time spending to learn a new application. 
To implement a [menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html#a9b34052d185a980f1fa5b9d2929f241c) in xtd we need to have two classes: a [xtd::forms::main_menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1main__menu.html), and a [xtd::forms::menu_item](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1menu__item.html).

## In This Section

* [Simple menu example](simple-menu-example)

## Simple menu example

Creating a [menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html#a9b34052d185a980f1fa5b9d2929f241c) in xtd is very simple.

```c++
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 final : public form {
public:
  form1() {
    menu(main_menu1);
    size({200, 180});
    start_position(form_start_position::center_screen);
    text("Simple menu");
  }

private:
  auto on_exit(object& sender, const event_args& e) noexcept -> void {
    close();
  }
  
  menu_item file_exit_menu_item {"&Quit", {*this, &form1::on_exit}, shortcut::alt_f4};
  menu_item file_menu_item {"File", {file_exit_menu_item}};
  main_menu main_menu1 {file_menu_item};
};

auto main() -> int {
  application::run(form1 {});
}
```

## See also

* [eBook](/docs/documentation/eBook)
