# Menus and Toolbars

A menu is one of the most visible parts of the GUI application. 
It is a group of commands located in various menus. 
While in console applications you had to remember all those arcane commands, here we have most of the commands grouped into logical parts. 
There are accepted standards that further reduce the amount of time spending to learn a new application. 
To implement a [menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html#a9b34052d185a980f1fa5b9d2929f241c) in xtd we need to have two classes: a [xtd::forms::main_menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1main__menu.html), and a [xtd::forms::menu_item](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1menu__item.html).

## In This Section

* [Simple menu example](#simple-menu-example)

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
  menu_item file_menu_item {"&File", {file_exit_menu_item}};
  main_menu main_menu1 {file_menu_item};
};

auto main() -> int {
  application::run(form1 {});
}
```

```c++
menu_item file_exit_menu_item {"&Quit", {*this, &form1::on_exit}, shortcut::alt_f4};
```

We create an `exit` menu item with the menu item text as the first parameter. 
The second parameter is the event handler associated with the menu item.
The third parameter is the shortcut key for calling the menu item from the keyboard.
The `&` character creates an accelerator key. The character that follows the `&` is underlined.

```c++
menu_item file_menu_item {"&File", {file_exit_menu_item}};
```

We create the submenu item in the file with the menu item text as the first parameter.
The second parameter is a vector of menu items. In this case, it contains only the exit menu item. 

```c++
main_menu main_menu1 {file_menu_item};
```

Finally, we create the main menu, which will be placed in the form's menu bar. 
It contains the list of submenus, in this case the file submenu.

![Screenshot](/pictures/examples/tutorial/simple_menu.png)

*Figure: Simple menu example*

## See also

* [eBook](/docs/documentation/eBook)
