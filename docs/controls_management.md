| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Controls management

* Objects that inherit [xtd::forms::control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html) are not copyable.
* No object of the [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) library manages controls for you. 
  
  You are responsible for their creation and destruction. 
  The objects of the [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) library only contain references to controls.

* The [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) library does not manage memory for you.
  
  Each control manages its own resources on the [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming idiom. And it does not manage your objects.

* A control can be created on the stack or dynamically in the heap.
  
  If you know in advance which controls need to be created you can do it on the stack.  On the other hand, if the controls are not known in advance, you will have to create them dynamically with or without a smart pointer.  Control management is up to you, the xtd.forms library doesn't care how you create controls. The xtd library does not contain a smart pointer, the std has what it takes.

For example a form that contains a reference to a label, the label will never be destroyed when the form is destroyed.
The form will only delete the reference on the label and it also remove the resource handle. 
So it is you who will have to delete the label instance. The [xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) library will never assume what you would like to do next with your control.

# Copy of control

Because of the [events](https://github.com/gammasoft71/xtd/blob/master/docs/events.md), the controls cannot be copied.

Imagine a control that responds to a [click](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga651752ad0a3ec381983aa0b367291a68) event like this:

```cpp
#include <xtd/xtd>

class my_control : public xtd::forms::control {
public:
  my_control() {
    click += {*this, &my_control::on_control_click};
  }

  void on_control_click(xtd::object& sender, const xtd::event_args& e) {
    (*internal_counter)++;
  }
  private:
    std::shared_ptr<int> internal_counter = std::make_shared<int>(0);
};

int main () {
  my_control my_control1;
  
  xtd::forms::form main_form;
  main_form.controls().push_back(my_control1);
  
  xtd::forms::application::run(main_form);
}
```

If you could copy my_control1 to my_control2 like this:

```cpp
#include <xtd/xtd>

class my_control : public xtd::forms::control {
public:
  my_control() {
    click += {*this, &my_control::on_control_click};
  }

  my_control(const my_control&) = default;
  my_control& operator =(const my_control&) = default;
    
  void on_control_click(xtd::object& sender, const xtd::event_args& e) {
    (*internal_counter)++;
  }
  private:
    std::shared_ptr<int> internal_counter = std::make_shared<int>(0);
};

int main () {
  my_control my_control1;
  my_control my_control2 = my_control1;
  
  xtd::forms::form main_form;
  main_form.controls().push_back(my_control1);
  
  xtd::forms::application::run(main_form);
}
```

What would happen when you go to [click](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga651752ad0a3ec381983aa0b367291a68) on the control?

my_control1::on_control_click would be called and my_control2::on_control_click would not be called. It seems to work.
Yes, but if you delete my_control1 after making the assignment to my_control2. No object will be called when you click.

So in this case it would be enough to say that in the copy constructor, the [click](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga651752ad0a3ec381983aa0b367291a68) event should also be implemented like this:

```cpp
  my_control(const my_control& other) {
    *this = other;
    click += {*this, &my_control::on_control_click};    
  }

  my_control& operator =(const my_control&) {
    *this = other;
    click += {*this, &my_control::on_control_click};
    return *this;    
  }
```

So my_control2::on_control_click would be called too. But in this case, internal_counter would be incremented by 2.
And this is not what we wanted.

Ok, so let's only use the click event on my_control2 and not on my_control1. That will solve everything. Well NO, because if we delete my_control2 and we decide to keep my_control1.
No more events will be called.

So to conclude. not knowing what the user of the library will want to do. 
The controls can NEVER be copied. And to be more precise a class that contains an event can NEVER be copied.

If you want to have a share (not a copy) of a control, then use [std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr) of the std.
[std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr) is the best way to share a resource. 

# Create and destroy a control

When you create a label and add it to the main window as in the example below :

```cpp
#include <xtd/xtd>

auto main()->int {
  xtd::forms::label my_label;
  my_label.text("Hello, World!");

  xtd::forms::form main_form;
  main_form.controls().push_back(my_label);
  
  xtd::forms::application::run(main_form);
}
```

You must keep the instance my_label a live until the main_form is alive.

Indeed, my_label will be destroyed after main_form when the main function is finished.

## The following code is wrong :

```cpp
#include <xtd/xtd>

void add_label(xtd::forms::form& f) {
  xtd::forms::label my_label;
  my_label.text("Hello, World!");

  f.controls().push_back(my_label);
}

auto main()->int {
  xtd::forms::form main_form;
  add_label(main_form);
  
  xtd::forms::application::run(main_form);
}
```

Indeed, you create my_label in the add_label method and when the method ends, my_label is deleted. when my_label is deleted, it remove automatically the reference on its control parent, in this case main_form. After add_label method ends, main_form does not contains my_label. You can see that it has no memory corruption. It's just like you never added a control to main_form.

## You should have written this instead:

```cpp
#include <xtd/xtd>

auto add_label(xtd::forms::form& f) {
  auto my_label = std::make_unique<xtd::forms::label>();
  my_label->text("Hello, World!");

  f.controls().push_back(*my_label);
  return my_label;
}

auto main()->int {
  xtd::forms::form main_form;
  auto my_label = add_label(main_form);
  
  xtd::forms::application::run(main_form);
}
```

Always keep in mind which controls are used by which control.

## Best (easy) way

An easy way to do this is OO programming. Just create a class that contains its child controls. 
This way as soon as the class is destroyed, its child controls will be destroyed too. 

Like in the following example:

```cpp
#include <xtd/xtd>

class main_form : public xtd::forms::form {
public:
  main_form() {
    controls().push_back(my_label);
    
    my_label.text("Hello, World!");
  }

private:
  xtd::forms::label my_label;
};

auto main()->int {
  xtd::forms::application::run(main_form());
}
```

In addition, you will respect the [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming idiom.

# Close form

Similarly, when you close a form, the child controls will never be destroyed. The form is closed, if it is a modal form (dialog), the result will be returned, but the controls are not destroyed. It is therefore your responsibility to destroy the child control(s) and the form.
So a closed form can be renewed at any time. There is no risk of memory leak or unallocated control when reopening (unless you have decided to do so).

The following example illustrates how closing the form works:

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({320, 325});
    controls().push_back_range({close_button, show_button, hide_button, cancel_close_check_box});
    text("Form shaw and hide example");

    close_button.location({10, 10});
    close_button.size({100, 40});
    close_button.text("Close");
    close_button.click += [&] {
      form2.close();
    };
    
    show_button.location({10, 60});
    show_button.size({100, 40});
    show_button.text("Show");
    show_button.click += [&] {
      form2.show();
    };
    
    hide_button.location({10, 110});
    hide_button.size({100, 40});
    hide_button.text("Hide");
    hide_button.click += [&] {
      form2.hide();
    };
    
    cancel_close_check_box.location({10, 160});
    cancel_close_check_box.size({100, 40});
    cancel_close_check_box.text("cancel close");

    form2.text("Close count = 0");
    form2.form_closing += [&](object& seander, form_closing_event_args& e) {
      e.cancel(cancel_close_check_box.checked());
    };
    form2.form_closed += [&] {
      static auto close_count = 0;
      form2.text(ustring::format("Close count = {}", ++close_count));
    };
  }
  
private:
  button close_button;
  button show_button;
  button hide_button;
  check_box cancel_close_check_box;
  form form2;
};

auto main()->int {
  application::run(form1());
}
```

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
