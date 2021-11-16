| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# How to make thread-safe calls to controls (xtd.forms)

## In This Section

* [Overview](#overview)
* [Unsafe cross-thread calls](#unsafe-cross-thread-calls)

## Overview

Multithreading can improve the performance of xtd.forms applications, but access to xtd.forms controls is not inherently thread-safe.
Multithreading can expose your code to serious and complex bugs.
Two or more threads manipulating a control can force the control into an inconsistent state and lead to race conditions, deadlocks, freezes, or stalls.
If you implement multithreading in your application, be sure to call cross-threaded controls in a safe manner.

There are two ways to safely call an xtd.forms control from a thread that did not create the control.
Use the xtd::windows::forms::control::invoke method to call a delegate created in the main thread, which in turn calls the control.
You can also implement an xtd::forms::background_worker, which uses an event-driven model to separate the work done in the background thread from the communication of results.

## Unsafe cross-thread calls

It's unsafe to call a control directly from a thread that didn't create it.
The following code snippet illustrates an unsafe call to the xtd::forms::text_box control.
The Button1_Click event handler creates a new write_text_unsafe thread, which sets the main thread's xtd::forms::text_box::text property directly.

```c++
void button1_click(object& sender, const event_args& e) {
  thread thread1(delegate<void()>(*this, &main_form::write_text_unsafe));
  thread1.detach();
}

void write_text_unsafe() {
  text_box1.text("This text was set unsafely.");
}
```

The Visual Studio debugger detects these unsafe thread calls by throwing an xtd::invalid_operation_exception with the following message: "Cross-thread operation not valid.
Control accessed from a thread other than the one where it was created.
The xtd::invalid_operation_exception always occurs for unsafe cross-threaded calls during Visual Studio debugging, and can occur at application runtime.
You need to resolve this issue, but you can disable the exception by setting the xtd::forms::control::check_for_illegal_cross_thread_calls property to false.

### Warning

Be careful, some OS don't support cross-thread UI operations!**

## Safe cross-thread calls

The following code examples demonstrate two ways to safely call a xtd.forms control from a thread that didn't create it:
1. The xtd::forms::control::invoke method, which calls a delegate from the main thread to call the control.
2. A xtd::forms::background_worker component, which offers an event-driven model.

In both examples, the background thread sleeps for one second to simulate work being done in that thread.

### Example: Use the Invoke method

The following example demonstrates a pattern for ensuring thread-safe calls to a xtd.forms control. It queries the xtd::forms::control::invoke_required property, which compares the control's creating thread ID to the calling thread ID. If they're different, you should call the xtd::forms::control::invoke method.
The *write_text_safe* enables setting the xtd::forms::text_box control's xtd::forms::control::text property to a new value. The method queries xtd::forms::control::invoke_required. If xtd::forms::control::invoke_required returns true, *write_text_safe* recursively calls itself, passing the method as a delegate to the xtd::forms::control::invoke method. If xtd::forms::control::invoke_required returns false, *write_text_safe* sets the xtd::forms::text_box::text directly. The *button1_click* event handler creates the new thread and runs the *write_text_safe* method.

```c++
void button1_click(object& sender, const event_args& e) {
  thread thread1(delegate<void()>(*this, &main_form::write_text_safe));
  thread1.detach();
}

void write_text_safe() {
  if (control::invoke_required())
    control::invoke({*this, &main_form::write_text_safe});
  else
    text_box1.text("This text was set safely.");
}
```

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
