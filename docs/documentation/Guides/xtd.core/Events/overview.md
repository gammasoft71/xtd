# Handle and raise events

The xtd Framework events are based on the delegate model. 
The delegate model follows the [observer design pattern](/docs/documentation/Guides/xtd.core/Events/observer_design_pattern), which allows a subscriber to register with and receive notifications from a provider. 
An event sender sends a notification that an event has occurred, and an event receiver receives that notification and defines a response to it.
This article describes the main components of the delegate model, how to consume events in applications, and how to implement events in your code.

## Events

An event is a message sent by an object to signal the occurrence of an action. 
The action may be caused by user interaction, such as clicking a button, or may result from other program logic, such as changing the value of a property.
The object that triggers the event is called the event sender. 
The event sender does not know which object or method will receive (process) the events it raises. 
The event is usually a member of the event sender; for example, the [click](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html) event is a member of the [xtd::forms::control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html) class, and the [progress_changed event](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html) is a member of the class that implements the [xtd::forms::background_worker](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1background__worker.html) class.

To define an event, you use the [xtd::event](/docs/documentation/Guides/xtd.core/Types%20overview/events) class in your [event](/docs/documentation/Guides/xtd.core/Types%20overview/events) class signature, and you specify the delegate type for the event. 
Delegates are described in the next section.

In general, to trigger an event, you add a method marked as ```protected``` and ```virtual```. Name this method ```on_event_name```; for example, ```on_data_received```. 
The method must take a parameter that specifies an event data object, which is an object of type [xtd::event_ags](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1event__args.html) or a derived type. You provide this method to allow derived classes to override the event trigger logic. 
A derived class must always call the ```on_``` event_name method of the base class to ensure that the registered delegates receive the event.

The following example shows how to declare an event named ```threshold_reached```. The event is associated with the [xtd::event_handler](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga0b1801aa17fa22ddacfdcccd7b25316b) delegate and triggered by a method called ```on_threshold_reached```.

```cpp
class counter {
public: 
  xtd::event<counter, xtd::event_handler> threshold_reached;

protected:
  virtual void on_threshold_reached(const xtd::event_args& e) {
    xtd::event_handler handler = threshold_reached;
    if (!handler.is_empty() handler.invoke(*this, e);
  }

  // provide remaining implementation for the class
};
```

## Delegates

A delegate is a type that contains a reference to a method. 
A delegate is declared with a signature that indicates the return type and parameters of the methods it references, and it can only contain references to methods that match its signature. 
A delegate is therefore equivalent to a type-safe function pointer or a callback. 
A delegate declaration is sufficient to define a class of delegates.

Delegates have many uses in the xtd Framework. 
In the context of events, a delegate is an intermediary (or pointer-like mechanism) between the event source and the code that handles the event. 
You associate a delegate with an event by including the delegate type in the event declaration, as shown in the example in the previous section. 
For more information on delegates, see the [xtd::delegate](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1delegate_3_01result__t_07arguments__t_8_8_8_08_4.html) class.

xtd provides the [xtd::event_handler](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga0b1801aa17fa22ddacfdcccd7b25316b) and [xtd::generic_event_handler<event_args_t>](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga531b610b74cb14c6047fb0843ab686b4) delegates to support most event scenarios. 
Use the xtd::event_handler delegate for all events that do not contain event data. 
Use the [xtd::generic_event_handler<event_args_t>](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga531b610b74cb14c6047fb0843ab686b4) delegate for events that contain event data. 
These delegates have no return type value and take two parameters (one xtd::object for the event source, and one object for the event data).

Delegates are multicast, which means that they can contain references to more than one event handling method. 
For more details, see the [xtd::delegate](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1delegate_3_01result__t_07arguments__t_8_8_8_08_4.html) reference page. 
Delegates provide flexibility and fine-grained control in event processing. 
A delegate acts as an event dispatcher for the class that raises the event by maintaining a list of registered event handlers for the event.

For scenarios where the xtd::event_handler and [xtd::generic_event_handler<event_args_t>](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga531b610b74cb14c6047fb0843ab686b4) delegates do not work, you can define a delegate. Scenarios that require a delegate to be defined are very rare, such as when you have to work with code that does not recognize generics. 
You mark a delegate with the [xtd::delegate](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1delegate_3_01result__t_07arguments__t_8_8_8_08_4.html) [xtd::delegate](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1delegate_3_01result__t_07arguments__t_8_8_8_08_4.html) class in the declaration. 
The following example shows how to declare a delegate named ```threshold_reached_event_handler```.

```cpp
public:
  using threshold_reached_event_handler = xtd::delegate<void(object& sender, const threshold_reached_event_args& e);
```

## Event data

The data associated with an event can be provided by an event data class. 
xtd provides many event data classes that you can use in your applications. 
For example, the [xtd::forms::dialog_closed_event_args](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1common__dialog.html) class is the event data class for the [xtd::forms::common_dialog.dialog_closed](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga58c4d7337fff19cd20dabbd50c24298c) event. xtd follows a naming pattern of ending all event data classes with _event_args. 
You determine the event data class associated with an event by examining the event's delegate. 
For example, the [dialog_closed_event_handler](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga93712f46c124e6ca40b40a2d9e14fc60) delegate includes the [dialog_closed_event_args](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1dialog__closed__event__args.html) class as one of its parameters.

The [xtd::event_args](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1event__args.htmlhttps://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1event__args.html) class is the base type for all event data classes. 
[xtd:event_args](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1event__args.html) is also the class you use when an event is not associated with any data.
When you create an event that is only intended to inform other classes that something has happened and does not need to pass any data, include the xtd:event_args class as the second parameter in the delegate. 
You can pass the value [xtd::event_args::empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1event__args.html) when no data is provided. 
The [xtd::event_handler](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga0b1801aa17fa22ddacfdcccd7b25316b) delegate includes the [xtd:event_args](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1event__args.html) class as a parameter.

When you want to create a custom event data class, create a class that derives from [xtd:event_args](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1event__args.html), and then provide all the members needed to pass the event-related data.
In general, you should use the same naming scheme as xtd and end the name of your event data class with ```_event_args```.

The following example shows an event data class named ```threshold_reached_event_args```*.
It contains properties specific to the triggered event.

```cpp
class threshold_reached_event_args : public xtd::event_args {
public: 
  int threshold() const {return threshold_;}
  void threshold(int value) {threshold_ = value;}
    
  const xtd::date_time& time_reached() const {return time_reached_;}
  void time_reached(const xtd::date_time& value) {time_reached_ = value;}
    
private:
  int threshold_ = 0;
  xtd::date_time time_reached_;
};
```

## Event handlers

To respond to an event, you define an event handling method in the event receiver. 
This method must match the delegate signature of the event you are handling. 
In the event handler, you perform the required actions when the event is triggered, such as collecting user input after the user clicks a button. 
To receive notifications when the event occurs, your event handler method must subscribe to the event.

The following example shows an event handling method named ```c_threshold_reached``` that matches the signature of the [xtd::event_handler](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga0b1801aa17fa22ddacfdcccd7b25316b) delegate.
The method subscribes to the ```threshold_reached``` event.

```cpp
class program {
  static auto main() {
    counter c;
    c.threshold_reached += c_threshold_reached;

    // provide remaining implementation for the class
  }

  static void c_threshold_reached(xtd::object& sender, const xtd::event_ergs& e) {
    console::write_line("The threshold was reached.");
  }
};

startup_(program);
```

## Static and dynamic event handlers

xtd allows subscribers to subscribe to event notifications statically or dynamically. 
Static event handlers are in effect for the lifetime of the class whose events they handle. 
Dynamic event handlers are explicitly turned on and off during program execution, usually in response to conditional program logic. 
For example, they can be used if event notifications are only needed under certain conditions or if an application provides multiple event handlers and the runtime conditions define which one to use. 
The example in the previous section shows how to dynamically add an event handler. 
For more information, see [Events](/docs/documentation/Guides/xtd.core/Types%20overview/events).

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)
