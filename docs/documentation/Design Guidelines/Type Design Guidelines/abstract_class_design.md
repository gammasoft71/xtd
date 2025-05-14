# Abstract Class Design

**❌ DO NOT** define public or protected internal constructors in abstract types.

Constructors should be public only if users will need to create instances of the type. Because you cannot create instances of an abstract type, an abstract type with a public constructor is incorrectly designed and misleading to the users.

**✔️ DO** define a protected or an internal constructor in abstract classes.

A protected constructor is more common and simply allows the base class to do its own initialization when subtypes are created.

An internal constructor can be used to limit concrete implementations of the abstract class to the assembly defining the class.

**✔️ DO** provide at least one concrete type that inherits from each abstract class that you ship.

Doing this helps to validate the design of the abstract class. For example, xtd::io::stream_reader is an implementation of the xtd::IO::text_reader abstract class.

```cpp
namespace xtd {
  namespace io {
    class text_reader {
    public:
      virtual int read() = 0;
      ...
    };
    
    class stream_reader : public text_reader {
    public:
      int read() override {
        ...
      }
      
      ...
    };
  }
}
```

# See also
​
* [Type Design Guidelines](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines)
* [Design Guidelines](/docs/documentation/Design%20Guidelines)
* [Documentation](/docs/documentation)
