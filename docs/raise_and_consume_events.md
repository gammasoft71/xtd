| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Raise and consume events

The examples in this topic show how to work with events. 
They include examples of the [xtd::event_handler](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga0b1801aa17fa22ddacfdcccd7b25316b) delegate, the [xtd::generic_event_handler<event_args_t>](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga531b610b74cb14c6047fb0843ab686b4) delegate, and a custom delegate, to illustrate events with and without data.

The examples use concepts described in the [events](handle_and_raise_events.md) article.

## Example 1

The first example shows how to raise and consume an event that doesn't have data. 
It contains a class named ```counter``` that has an event named ```threshold_reached```. 
This event is raised when a counter value equals or exceeds a threshold value. 
The [xtd::event_handler](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga0b1801aa17fa22ddacfdcccd7b25316b) delegate is associated with the event, because no event data is provided.

```cpp
#include <xtd/xtd>

using namespace xtd;

namespace console_application1 {
  class counter : public object {
  private:
    int threshold;
    int total;
    
  public:
    counter(int passed_threshold) {
      threshold = passed_threshold;
    }
    
    void add(int x) {
      total += x;
      if (total >= threshold) {
        if (!threshold_reached.is_empty()) threshold_reached.invoke(*this, event_args::empty);
      }
    }
    
    event<counter, event_handler> threshold_reached;
  };

  class program {
  public:
    static auto main(const std::vector<ustring>& args) {
      counter c(xtd::random().next(10));
      c.threshold_reached += c_threshold_reached;
      
      console::write_line("press 'a' key to increase total");
      while (console::read_key(true).key_char() == 'a') {
        console::write_line("adding one");
        c.add(1);
      }
    }
    
    static void c_threshold_reached(object& sender, const event_args& e) {
      console::write_line("The threshold was reached.");
      environment::exit(0);
    }
  };
}

startup_(console_application1::program);
```

## Example 2

The next example shows how to raise and consume an event that provides data. 
The [xtd::generic_event_handler<event_args_t>](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga531b610b74cb14c6047fb0843ab686b4) delegate is associated with the event, and an instance of a custom event data object is provided.

```cpp
#include <xtd/xtd>

using namespace xtd;

namespace console_application1 {
  class threshold_reached_event_args : public xtd::event_args {
  public:
    int threshold() const {return threshold_;}
    void threshold(int value) {threshold_ = value;}
    
    const date_time& time_reached() const {return time_reached_;}
    void time_reached(const datte_time& value) {time_reached_ = value;}
    
  private:
    int threshold_ = 0;
    date_time time_reached_;
  };

  class counter : public object {
  private:
    int threshold;
    int total;
    
  public:
    counter(int passed_threshold) {
      threshold = passed_threshold;
    }
    
    void add(int x) {
      total += x;
      if (total >= threshold) {
        threshold_reached_event_args args;
        args.threshold(threshold);
        args.time_reached(date_time::now());
        on_threshold_reached(args);
      }
    }
    
  protected:
    virtual void on_threshold_reached(const threshold_reached_event_args& e) {
      generic_event_handler<const threshold_reached_event_args&> handler = threshold_reached;
      if (!handler.is_empty()) {
        handler(*this, e);
      }
    }
    
  public:
    event<counter, generic_event_handler<const threshold_reached_event_args&>> threshold_reached;
  };

  class program {
  public:
    static auto main(const std::vector<ustring>& args) {
      counter c(xtd::random().next(10));
      c.threshold_reached += c_threshold_reached;
      
      console::write_line("press 'a' key to increase total");
      while (console::read_key(true).key_char() == 'a') {
        console::write_line("adding one");
        c.add(1);
      }
    }
    
    static void c_threshold_reached(object& sender, const threshold_reached_event_args& e) {
      console::write_line("The threshold of {0} was reached at {1}.", e.threshold(),  e.time_reached());
      environment::exit(0);
    }
  };
}

startup_(console_application1::program);
```

## Example 3

The next example shows how to declare a delegate for an event. 
The delegate is named ```threshold_reached_event_handler```. 
This is just an illustration. Typically, you do not have to declare a delegate for an event, because you can use either the [xtd::event_handler](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga0b1801aa17fa22ddacfdcccd7b25316b) or the [xtd::generic_event_handler<event_args_t>](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga531b610b74cb14c6047fb0843ab686b4) delegate. 
You should declare a delegate only in rare scenarios, such as making your class available to legacy code that cannot use generics.

```cpp
#include <xtd/xtd>

using namespace xtd;

namespace console_application1 {
  class threshold_reached_event_args : public xtd::event_args {
  public:
    int threshold() const {return threshold_;}
    void threshold(int value) {threshold_ = value;}
    
    const date_time& time_reached() const {return time_reached_;}
    void time_reached(coonst date_time& value) {time_reached_ = value;}
    
  private:
    int threshold_ = 0;
    date_time time_reached_;
  };
  
  using threshold_reached_event_handler = delegate<void(object&, const threshold_reached_event_args&)>;

  class counter : public object {
  private:
    int threshold;
    int total;
    
  public:
    counter(int passed_threshold) {
      threshold = passed_threshold;
    }
    
    void add(int x) {
      total += x;
      if (total >= threshold) {
        threshold_reached_event_args args;
        args.threshold(threshold);
        args.time_reached(date_time::now());
        on_threshold_reached(args);
      }
    }
    
  protected:
    virtual void on_threshold_reached(const threshold_reached_event_args& e) {
      generic_event_handler<const threshold_reached_event_args&> handler = threshold_reached;
      if (!handler.is_empty()) {
        handler(*this, e);
      }
    }
    
  public:
    threshold_reached_event_handler threshold_reached;
  };

  class program {
  public:
    static auto main(const std::vector<ustring>& args) {
      counter c(xtd::random().next(10));
      c.threshold_reached += c_threshold_reached;
      
      console::write_line("press 'a' key to increase total");
      while (console::read_key(true).key_char() == 'a') {
        console::write_line("adding one");
        c.add(1);
      }
    }
    
    static void c_threshold_reached(object& sender, const threshold_reached_event_args& e) {
      console::write_line("The threshold of {0} was reached at {1}.", e.threshold(),  e.time_reached());
      environment::exit(0);
    }
  };
}

startup_(console_application1::program);
```

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
