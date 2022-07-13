 [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Controls management

* Objects that inherit [xtd::forms::control](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1control.html) are not copyable.
* No object of the [xtd.forms](https://codedocs.xyz/gammasoft71/xtd/group__xtd__forms.html) library manages controls for you. 
  
  You are responsible for their creation and destruction. 
  The objects of the [xtd.forms](https://codedocs.xyz/gammasoft71/xtd/group__xtd__forms.html) library only contain references to controls.

* The [xtd.forms](https://codedocs.xyz/gammasoft71/xtd/group__xtd__forms.html) library does not manage memory for you.
  
  Each control manages its own resources on the [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming idiom. And it does not manage your objects.

For example a form that contains a reference to a label, the label will never be destroyed when the form is destroyed.
The form will only delete the reference on the label and it also remove the resource handle. 
So it is you who will have to delete the label instance. The [xtd.forms](https://codedocs.xyz/gammasoft71/xtd/group__xtd__forms.html) library will never assume what you would like to do next with your control.

## Copy of control

Because of the [events](https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_events.md), the controls cannot be copied.

Imagine a control that responds to a [click](https://codedocs.xyz/gammasoft71/xtd/group__events.html#ga651752ad0a3ec381983aa0b367291a68) event like this:

```c++
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

```c++
#include <xtd/xtd>

class my_control : public xtd::forms::control {
public:
  my_control() {
    click += {*this, &my_control::on_control_click};
  }

  my_control(const my_control&) = default;
  my_control& operator=(const my_control&) = default;
    
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

What would happen when you go to [click](https://codedocs.xyz/gammasoft71/xtd/group__events.html#ga651752ad0a3ec381983aa0b367291a68) on the control?

my_control1::on_control_click would be called and my_control2::on_control_click would not be called. It seems to work.
Yes, but if you delete my_control1 after making the assignment to my_control2. No object will be called when you click.

So in this case it would be enough to say that in the copy constructor, the [click](https://codedocs.xyz/gammasoft71/xtd/group__events.html#ga651752ad0a3ec381983aa0b367291a68) event should also be implemented like this:

```c++
  my_control(const my_control& other) {
    *this = other;
    click += {*this, &my_control::on_control_click};    
  }

  my_control& operator=(const my_control&) {
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

## Create and destroy a control

When you create a label and add it to the main window as in the example below :

```c++
#include <xtd/xtd>

int main() {
  xtd::forms::label my_label;
  my_label.text("Hello, World!");

  xtd::forms::form main_form;
  main_form.controls().push_back(my_label);
  
  xtd::forms::application::run(main_form);
}
```

You must keep the instance my_label a live until the main_form is alive.

Indeed, my_label will be destroyed after main_form when the main function is finished.

### The following code is wrong :

```c++
#include <xtd/xtd>

void add_label(xtd::forms::form& f) {
  xtd::forms::label my_label;
  my_label.text("Hello, World!");

  f.controls().push_back(my_label);
}

int main() {
  xtd::forms::form main_form;
  add_label(main_form);
  
  xtd::forms::application::run(main_form);
}
```

Indeed, you create my_label in the add_label method and when the method ends, my_label is deleted. But my_form contains a reference to the child control my_label.
So the main_form will try to handle a deleted child. THERE MAY BE MEMORY CORRUPTION.

### You should have written this instead:

```c++
#include <xtd/xtd>

std::unique_ptr<xtd::forms::label> add_label(xtd::forms::form& f) {
  auto my_label = std::make_unique<xtd::forms::label>();
  my_label->text("Hello, World!");

  f.controls().push_back(*my_label);
  return my_label;
}

int main() {
  xtd::forms::form main_form;
  auto my_label = add_label(main_form);
  
  xtd::forms::application::run(main_form);
}
```

Always keep in mind which controls are used by which control.

### Best (easy) way

An easy way to do this is OO programming. Just create a class that contains its child controls. 
This way as soon as the class is destroyed, its child controls will be destroyed too. 

Like in the following example:

```c++
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

int main() {
  xtd::forms::application::run(main_form());
}
```

In addition, you will respect the [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming idiom.

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.
