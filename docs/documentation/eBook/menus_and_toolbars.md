# Menus and Toolbars

A menu is one of the most visible parts of the GUI application. 
It is a group of commands located in various menus. 
While in console applications you had to remember all those arcane commands, here we have most of the commands grouped into logical parts. 
There are accepted standards that further reduce the amount of time spending to learn a new application. 
To implement a [menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html#a9b34052d185a980f1fa5b9d2929f241c) in xtd we need to have two classes: a [xtd::forms::main_menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1main__menu.html), and a [xtd::forms::menu_item](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1menu__item.html).

## In This Section

* [Simple menu example](#simple-menu-example)
* [Submenus](#submenus)
* [Toolbars](#toolbars)
  * [A simple toolbar](#a-simple-toolbar)
  * [Toolbars](#toolbars)

## Simple menu example

Creating a [menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html#a9b34052d185a980f1fa5b9d2929f241c) in xtd is very simple.

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 final : public form {
public:
  form1() {
    center_to_screen();
    menu(main_menu1);
    size({200, 180});
    text("Simple menu");
  }

private:
  auto on_exit(object& sender, const event_args& e) noexcept -> void {
    close();
  }
  
  menu_item file_exit_menu_item {"&Quit", {*this, &form1::on_exit}, shortcut::ctrl_q};
  menu_item file_menu_item {"&File", {file_exit_menu_item}};
  main_menu main_menu1 {{file_menu_item}};
};

auto main() -> int {
  application::run(form1 {});
}
```

```cpp
menu_item file_exit_menu_item {"&Quit", {*this, &form1::on_exit}, shortcut::ctrl_q};
```

We create an `exit` menu item with the menu item text as the first parameter. 
The second parameter is the event handler associated with the menu item.
The third parameter is the shortcut key for calling the menu item from the keyboard.
The `&` character creates an accelerator key. The character that follows the `&` is underlined.

```cpp
menu_item file_menu_item {"&File", {file_exit_menu_item}};
```

We create the submenu item in the file with the menu item text as the first parameter.
The second parameter is a vector of menu items. In this case, it contains only the `exit` menu item. 

```cpp
main_menu main_menu1 {file_menu_item};
```

Finally, we create the main menu, which will be placed in the form's menu bar. 
It contains the list of submenus, in this case the `file` submenu.

![Screenshot](/pictures/examples/tutorial/simple_menu.png)

*Figure: Simple menu example*

## Submenus

Each menu can also have a submenu. 
This way we can group similar commands into groups. 
For example we can place commands that hide or show various toolbars like personal bar, address bar, status bar, or navigation bar into a submenu called toolbars. 
Within a menu, we can separate commands with a separator. 
It is a simple line. It is common practice to separate commands like new, open, save from commands like print, print preview with a single separator. 
In our example we see, how we can create submenus and menu separators.

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 final : public form {
public:
  form1() {
    center_to_screen();
    menu(main_menu1);
    size({200, 180});
    text("Submenu");
  }

private:
  auto on_exit(object& sender, const event_args& e) noexcept -> void {
    close();
  }
  
  menu_item file_new_menu_item {"&New"};
  menu_item file_open_menu_item {"Open"};
  menu_item file_save_menu_item {"&Save"};
  menu_item file_separator1_menu_item {"-"};
  menu_item file_import_newsfeed_menu_item {"Import newsfeed list..."};
  menu_item file_import_bookmarks_menu_item {"Import bookmarks..."};
  menu_item file_import_mails_menu_item {"Import mails..."};
  menu_item file_import_menu_item {"Import", {file_import_newsfeed_menu_item, file_import_bookmarks_menu_item, file_import_mails_menu_item}};
  menu_item file_separator2_menu_item {"-"};
  menu_item file_exit_menu_item {"&Quit", {*this, &form1::on_exit}, shortcut::ctrl_q};
  menu_item file_menu_item {"&File", {file_new_menu_item, file_open_menu_item, file_save_menu_item, file_separator1_menu_item, file_import_menu_item, file_separator2_menu_item, file_exit_menu_item}};
  main_menu main_menu1 {{file_menu_item}};
};

auto main() -> int {
  application::run(form1 {});
}
```
We created one submenu in a file menu. It is an import submenu, which can be seen in Opera web browser.

```cpp
menu_item file_separator1_menu_item {"-"};
```
A menu separator line is created calling it with "-" as text.

```cpp
  menu_item file_import_newsfeed_menu_item {"Import newsfeed list..."};
  menu_item file_import_bookmarks_menu_item {"Import bookmarks..."};
  menu_item file_import_mails_menu_item {"Import mails..."};
  menu_item file_import_menu_item {"Import", {file_import_newsfeed_menu_item, file_import_bookmarks_menu_item, file_import_mails_menu_item}};
```

A submenu is created in the same way as a normal menu. Items are added as a second parameter as a menu_item vector.

![Screenshot](/pictures/examples/tutorial/submenu.png)

*Figure: Submenu*

## Toolbars

Menus group all commands that we can use in an application. Toolbars provide a quick access to the most frequently used commands.

```cpp
xtd::forms::tool_bar xtd::forms::tool_bar::create(...);
````

To create a system toolbar, we call the [xtd::forms::form::tool_bar](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html#a2745bb47e63653ddccb5893db2cf2e39) method of the [xtd::forms::form](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1form.html) control.

### A simple toolbar

Our first example will create a simple toolbar.

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 final : public form {
public:
  form1() {
    center_to_screen();
    text("Toolbar");
    tool_bar(tool_bar1);

    tool_bar1.button_click += {*this, &form1::on_tool_bar_button_click};
  }

private:
  auto on_tool_bar_button_click(object& sender, const tool_bar_button_click_event_args& e) noexcept -> void {
    if (e.button() == exit_tool_bar_button) close();
  }
  
  tool_bar_button exit_tool_bar_button = tool_bar_button::create_push_button(0);
  forms::tool_bar tool_bar1 = forms::tool_bar::create(*this, {tool_bar_images::file_exit()}, {exit_tool_bar_button});
};

auto main() -> int {
  application::run(form1 {});
}
```

In our example, we create a toolbar and one tool button. Clicking on the toolbar button will terminate the application.

```cpp
tool_bar_button exit_tool_bar_button = tool_bar_button::create_push_button(0);
```

We create a toolbar button.

```cpp
forms::tool_bar tool_bar1 = forms::tool_bar::create(*this, {tool_bar_images::file_exit()}, {exit_tool_bar_button});
````

We create a toolbar and adding `exit` toolbar button.

```cpp
tool_bar(tool_bar1);
```

We add the toolbar we've created as the form's system toolbar.

![Screenshot](/pictures/examples/tutorial/toolbar.png)

*Figure: Toolbar*

### Toolbars

If we want to have more than one toolbar, only one of the toolbars can be associated as the form's system toolbar. The other toolbars will be secondary toolbars that can be placed at the top, bottom, left or right of the form using the [xtd::forms::tool_bar::dock](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tool__bar.html#af25fbe68eefb148e22e3d26173a33e73) property.

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 final : public form {
public:
  form1() {
    center_to_screen();
    text("Toolbar");
    tool_bar(tool_bar1);

    tool_bar1.button_click += {*this, &form1::on_tool_bar_button_click};
    tool_bar2.button_click += {*this, &form1::on_tool_bar_button_click};
  }

private:
  auto on_tool_bar_button_click(object& sender, const tool_bar_button_click_event_args& e) noexcept -> void {
    if (e.button() == exit_tool_bar_button) close();
  }
  
  tool_bar_button exit_tool_bar_button = tool_bar_button::create_push_button(0);
  forms::tool_bar tool_bar1 = forms::tool_bar::create(*this, {tool_bar_images::file_exit()}, {exit_tool_bar_button});
  tool_bar_button new_tool_bar_button = tool_bar_button::create_push_button(0);
  tool_bar_button open_tool_bar_button = tool_bar_button::create_push_button(1);
  tool_bar_button save_tool_bar_button = tool_bar_button::create_push_button(2);
  forms::tool_bar tool_bar2 = forms::tool_bar::create(*this, {tool_bar_images::file_new(), tool_bar_images::file_open(), tool_bar_images::file_save()}, {new_tool_bar_button, open_tool_bar_button, save_tool_bar_button});
};

auto main() -> int {
  application::run(form1 {});
}
````

![Screenshot](/pictures/examples/tutorial/toolbars.png)

*Figure: Toolbars*

## See also

* [eBook](/docs/documentation/eBook)
