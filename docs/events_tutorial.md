| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Events

## In This Section

* [Overview](#overview)
* [How to subscribe to and unsubscribe from events](#how-to-subscribe-to-and-unsubscribe-from-events)
  * [To subscribe to events programmatically](#to-subscribe-to-events-programmatically)
  * [To subscribe to events by using a lambda expression](#to-subscribe-to-events-by-using-a-lambda-expression)
  * [Unsubscribing](#uunsubscribing)
  * [To unsubscribe from an event](#to-unsubscribe-from-an-event)
* [How to publish events that conform to xtd Guidelines](#how-to-publish-events-that-conform-to-xtd-guidelines)
  * [Publish events based on the event_handler pattern](#publish-events-based-on-the-event_handler-pattern)
* [Example](#example)

## Overview

[Events](../src/xtd.core/include/xtd/event.h) enable a class or object to notify other classes or objects when something of interest occurs. The class that sends (or raises) the event is called the publisher and the classes that receive (or handle) the event are called subscribers.
In a typical xtd Windows Forms application, you subscribe to events raised by controls such as buttons and list boxes. For more information, see [How to subscribe to and unsubscribe from events](#how-to-subscribe-to-and-unsubscribe-from-events).

Events have the following properties:
* The publisher determines when an event is raised; the subscribers determine what action is taken in response to the event.
* An event can have multiple subscribers. A subscriber can handle multiple events from multiple publishers.
* Events that have no subscribers are never raised.
* Events are typically used to signal user actions such as button clicks or menu selections in graphical user interfaces.
* When an event has multiple subscribers, the event handlers are invoked synchronously when an event is raised.
* In the xtd framework, events are based on the [xtd::event_handler](../src/xtd.core/include/xtd/event_handler.h) [delegate and the xtd::event_args](../src/xtd.core/include/xtd/event_args.h) base class.

## How to subscribe to and unsubscribe from events

### To subscribe to events programmatically

1. Define an event handler method whose signature matches the delegate signature for the event. For example, if the event is based on the [xtd::event_handler](../src/xtd.core/include/xtd/event_handler.h) delegate type, the following code represents the method stub:

```c++
void handle_custom_event(object& sender, custom_event_args& e) {  
   // Do something useful here.  
}  
```

2. Use the addition assignment operator *+=* to attach an event handler to the event. In the following example, assume that an object named *publisher* has an event named *raise_custom_event*. Note that the *subscriber* class needs a reference to the *publisher* class in order to subscribe to its events

```c++
publisher.raise_custom_event += {*this, &subscriber::handle_custom_event};
```

or 

```c++
publisher.raise_custom_event += custom_event_handler(*this, &my_class::handle_custom_event);
```

### To subscribe to events by using a lambda expression

If you don't have to unsubscribe from an event later, you can use the addition assignment operator *+=* to attach a [lambda expression](#lambda-expression) as an event handler. In the following example, assume that an object named *publisher* has an event named *raise_custom_event and that a *custom_event_args* class has also been defined to carry some kind of specialized event information. Note that the *subscriber* class needs a reference to *publisher* in order to subscribe to its events.

```c++
publisher.raise_custom_event += [](object& sender, custom_event_args& e) {  
  xtd::ustring s = sender.to_string() + " " + e.to_string();  
  console::write_line(s);  
};
```

You cannot easily unsubscribe from an event if you used a [lambda expression](#lambda-expression) to subscribe to it. To unsubscribe in this scenario, go back to the code where you subscribe to the event, store the anonymous function in a delegate variable, and then add the delegate to the event. We recommend that you don't use [lambda expression](#lambda-expression) to subscribe to events if you have to unsubscribe from the event at some later point in your code. For more information about anonymous functions, see [lambda expression](#lambda-expression).

### Unsubscribing

To prevent your event handler from being invoked when the event is raised, unsubscribe from the event. In order to prevent crash, you should unsubscribe from events before you destroy a subscriber object. Until you unsubscribe from an event, the multicast delegate that underlies the event in the publishing object has a reference to the delegate that encapsulates the subscriber's event handler.

### To unsubscribe from an event

Use the subtraction assignment operator *-=* to unsubscribe from an event:

```c++
publisher.raise_custom_event -= {*this, &subscriber::handle_custom_event};
```

or

```c++
publisher.raise_custom_event -= custom_event_handler(*this, &subscriber::handle_custom_event);
```

When all subscribers have unsubscribed from an event, the event instance in the publisher class is set to empty.

## How to publish events that conform to xtd Guidelines

The following procedure demonstrates how to add events that follow the standard xtd pattern to your classes and structs. All events in the xtd framework are based on the [xtd::event_handler](../src/xtd.core/include/xtd/event_handler.h) delegate, which is defined as follows:

```c++
template<typename event_args_t = const xtd::event_args&>
using generic_event_handler = xtd::delegate<void(xtd::object& sender, event_args_t e)>;
```

and

```c++
using event_handler = xtd::generic_event_handler<>;
```

Although events in classes that you define can be based on any valid delegate type, even delegates that return a value, it is generally recommended that you base your events on the xtd pattern by using [xtd::event_handler](../src/xtd.core/include/xtd/event_handler.h), as shown in the following example.
The name event_handler can lead to a bit of confusion as it doesn't actually handle the event. The [xtd::event_handler](../src/xtd.core/include/xtd/event_handler.h), and generic [xtd::generic_event_handler<event_args_t>](../src/xtd.core/include/xtd/event_handler.h) are delegate types. A method or lambda expression whose signature matches the delegate definition is the event handler and will be invoked when the event is raised.

### Publish events based on the event_handler pattern

1. (Skip this step and go to Step 3a if you do not have to send custom data with your event.) Declare the class for your custom data at a scope that is visible to both your publisher and subscriber classes. Then add the required members to hold your custom event data. In this example, a simple string is returned.

```c++
class custom_event_args : xtd::event_args {
public:
  custom_event_args() = default;
  custom_event_args(const xtd::ustring& message) : message_(message) {}
  
  xtd::ustring message() const noexcept {return message_;}
  
private:
  xtd::ustring message_;
};
```

2. (Skip this step if you are using the generic version generic_event_handler<event_args_t>.) Declare a delegate in your publishing class. Give it a name that ends with event_handler. The second parameter specifies your custom event_args type.

```c++
using custom_event_handler = xtd::delegate<void(xtd::object& sender, custom_event_args& args)>;
```

3. Declare the event in your publishing class by using one of the following steps.

  a. If you have no custom event_args class, your event type will be the non-generic event_handler delegate. You do not have to declare the delegate because it is already declared in the xtd namespace that is included when you create your xtd project. Add the following code to your publisher class.

  ```c++
  xtd::event<publisher, xtd::event_handler> raise_custom_event;
  ```
  
  where *publisher* is the class name that contains the raise_custom_event event.

  b. If you are using the non-generic version of event_handler and you have a custom class derived from event_args, declare your event inside your publishing class and use your delegate from step 2 as the type.

  ```c++
  xtd::event<publisher, custom_event_handler> raise_custom_event;
  ```
  
  Where *publisher* is the class name that contains the raise_custom_event event.

  c. If you are using the generic version, you do not need a custom delegate. Instead, in your publishing class, you specify your event type as generic_event_handler<custom_event_args>, substituting the name of your own class between the angle brackets.

  ```c++
  xtd::event<publisher, generic_event_handler<custom_event_args&>> raise_custom_event;
  ```
  
  Where *publisher* is the class name that contains the raise_custom_event event.

## Example

The following example demonstrates the previous steps by using a custom event_args class and genric_event_handler<event_args_t> as the event type.

```c++
#include <xtd/xtd>

using namespace xtd;

// Define a class to hold custom event info
class custom_event_args : xtd::event_args {
public:
  custom_event_args() = default;
  custom_event_args(const xtd::ustring& message) : message_(message) {}
  
  xtd::ustring message() const noexcept {return message_;}
  void message(const xtd::ustring& value) noexcept {message_ = value;}

private:
  xtd::ustring message_;
};

// Class that publishes an event
class publisher : public object {
public:
  // Declare the event using EventHandler<T>
  event<publisher, generic_event_handler<custom_event_args&>> raise_custom_event;
  
  void do_something() {
    // Write some code that does something useful here
    // then raise the event. You can also raise an event
    // before you execute a block of code.
    custom_event_args event_args("Event triggered");
    on_raise_custom_event(event_args);
  }

protected:
  // Wrap event invocations inside a protected virtual method
  // to allow derived classes to override the event invocation behavior
  virtual void on_raise_custom_event(custom_event_args& e) {
    // Make a temporary copy of the event to avoid possibility of
    // a race condition if the last subscriber unsubscribes
    // immediately after the empty check and before the event is raised.
    event<publisher, generic_event_handler<custom_event_args&>> raise_event = raise_custom_event;
    
    // Event will be null if there are no subscribers
    if (!raise_event.is_empty()) {
      // Format the string to send inside the CustomEventArgs parameter
      e.message(ustring::format("{} at {}", e.message(), std::chrono::system_clock::now()));
      
      // Call to raise the event.
      raise_event(*this, e);
    }
  }
};

//Class that subscribes to an event
class subscriber : public object {
public:
  subscriber(ustring id, publisher& pub) : id_(id) {
    // Subscribe to the event
    pub.raise_custom_event += {*this, &subscriber::handle_custom_event};
  }
  
  // Define what actions to take when the event is raised.
  void handle_custom_event(object& sender, custom_event_args& e) {
    console::write_line(ustring::format("{} received this message: {}", id_, e.message()));
  }

private:
  ustring id_;
};

class program {
public:
  static void main() {
    publisher pub;
    subscriber sub1("sub1", pub);
    subscriber sub2("sub2", pub);
    
    // Call the method that raises the event.
    pub.do_something();
  }
};

startup_(program);
```

## See also

* [Tutorials](tutoruals.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
