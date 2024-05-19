| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Application overview

An xtd GUI application must use the [xtd::forms::application](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html) class to run process event loop.

The following code shows the minimum required to run a GUI application.
The application will exit automatically when the form is closed.

```cpp
#include <xtd/xtd>

auto main() -> int {
  xtd::forms::application::run(xtd::forms::form {});
}
```

## Application

The [xtd::forms::application](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html) class provides static methods and properties to manage an application, such as methods to start and stop an application, to process Windows messages, and methods to get information about an application.
The [xtd::forms::application](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html) class is a static class and cannot be inherited.

### Start process event loop

The following methods are used to start process event loop:
* [xtd::forms::application::run(const xtd::forms::form& main_form)](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#ad9f33fc4a9bfe8735d80ebabdeb7f3f2) begins running a standard application message loop on the current thread, and makes the specified form visible. This is the most method used. If you don't know which method to use then use this one.
* [xtd::forms::application::run(xtd::forms::application_context& context)](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#ab79aa8eba69cde497bae6657cb11eab8) begins running a standard application message loop on the current thread, with an application_context. The message loop runs until [xtd::forms::application::exit](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a1f7d29b0aeda0c96f5acc4e38ad5902a) or [xtd::forms::application::exit_thread](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a7cd6fe69c23173cb2dabae8f6c7a1690) is called or the [xtd::forms::application_context::thread_exit](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga3dc1fee2312e39f7032b071ed5ee0f54) event is raised on the context object.
* [xtd::forms::application::run()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a4ee49410f3156fd66b61c2567a59388e) begins running a standard application message loop on the current thread, without a form. If you use this method you have to stop the application yourself with the method [xtd::forms::application::exit()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a1f7d29b0aeda0c96f5acc4e38ad5902a) or [xtd::forms:application::exit_thread()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a7cd6fe69c23173cb2dabae8f6c7a1690) when for example the last window is closed. Because there is no main window that when closed stops the application.

The following code shows the use of the [application::run()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a4ee49410f3156fd66b61c2567a59388e) method without parameter. 
Unlike the method with the specified form parameter, the message loop application will not stop when you close the window.
You have to call the method [applicati::exit](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a1f7d29b0aeda0c96f5acc4e38ad5902a) or [application::exit_thread](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a7cd6fe69c23173cb2dabae8f6c7a1690) explicitly.

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

auto main() -> int {
  form form1;
  form1.show();
  form1.form_closed += [] {
    // If you comment the following line the application will not exit when you close the form.
    application::exit();
  };
  
  application::run();
}
```

### Stop process event loop and exit

The following methods are used to stop process event loop and exit:
* [xtd::forms::application::exit()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a1f7d29b0aeda0c96f5acc4e38ad5902a) informs all message pumps that they must terminate, and then closes all application windows after the messages have been processed.
* [xtd::forms::application::exit(xtd::forms::cancel_event_args& e)](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a5b1b744a6bc8e74c2a80cf0564b370cd) informs all message pumps that they must terminate, and then closes all application windows after the messages have been processed.
* [xtd::forms::application::exit_thread()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a7cd6fe69c23173cb2dabae8f6c7a1690) exits the message loop on the current thread and closes all windows on the thread.

### Settings

The application class contains some global settings that must be called before executing the event loop.

* [xtd::forms::application::disable_font_size_correction()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#abf17d1d7052d313ff8137035f8a0d276) disables font size correction for the application.
* [xtd::forms::application::enable_button_images()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#ad32eba2a91a9e25f66e4cb1f718c8973) enables button images for the application (has effect on linux only).
* [xtd::forms::application::enable_dark_mode()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a055e78c3b5097f08a108c0730360e3b8) enables dark mode for the application.
* [xtd::forms::application::enable_light_mode()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#ac6f2defe8e2722b0fb450f5ae6a2f28d) enables light mode for the application.
* [xtd::forms::application::enable_menu_images()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a38695ee0d586fd727abfb42995f6d9cb) enables menu images for the application (has effect on linux only).
* [xtd::forms::application::enable_system_controls()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a28ad4db693e3bf228e5f0902fdf5882a) enables system control for the application.
* [xtd::forms::application::enable_system_font_size()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a7d71d75530eaadb67edc3be36c57ca61) enables system font size for the application.
* [xtd::forms::application::enable_visual_styles()](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a6af4447091dec74038a54c6b9f5f8760) enables visual styles for the application.

## Application context

[xtd::forms::application_context](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application__context.html) class specifies the contextual information about an application thread.

The [xtd::forms::application_context](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application__context.html#ac5474112ff9d1805a8eff90a069c2ca1) contains or not the main form. You can set or change a main form in runtime with the [xtd::forms::application_context::main_form](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application__context.html#a0c2eeef4bb20a6c077a925896a9024e4) property.

The following code shows how to create an [application_context](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application__context.html#ac5474112ff9d1805a8eff90a069c2ca1), set a form as [main_form](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application__context.html#a0c2eeef4bb20a6c077a925896a9024e4) and call [appplication::run](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#ab79aa8eba69cde497bae6657cb11eab8) with it.

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

auto main() -> int {
  form form1;
  form1.text("form 1;");
  form1.show();

  form form2;
  form2.text("form 2");

  application_context context;
  context.main_form(form2);
  
  application::run(context);
}
```

`form 2` is the main window. If you close `form 1`, the application continues to run and `form 2` remains visible. 
On the other hand, if you close `form2`, the application is exited and `form 1` is closed.
Note that you can change the main form at any time while the application is running 

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
