| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Delegates and lambdas

Delegates define a type that specifies a particular method signature. 
A method (instance, functor, static) that satisfies this signature can be assigned to a variable of this type and then called directly (with the appropriate arguments) or passed as an argument to another method and then called.

The following example demonstrates the use of delegates with instance method.

```cpp
#include <xtd/xtd>

using namespace xtd;

class stringer {
public:
  ustring reverse_string(const ustring& s) {
    ustring result = s;
    std::reverse(result.begin(), result.end());
    return result;
  }
};

class program {
public:
  using reverse = delegate<ustring(const ustring& s)>;
  
  static auto main(const std::vector<ustring>& args) {
    stringer s;
    reverse rev(s, &stringer::reverse_string);
    
    console::write_line(rev("a string"));
  }
};

startup_(program);
```


The following example demonstrates the use of delegates with functor.

```cpp
#include <xtd/xtd>

using namespace xtd;

struct string_reverser {
  ustring operator ()(const ustring& s) {
    ustring result = s;
    std::reverse(result.begin(), result.end());
    return result;
  }
};

class program {
public:
  using reverse = delegate<ustring(const ustring& s)>;
  
  static auto main(const std::vector<ustring>& args) {
    string_reverser sr;
    reverse rev(sr);
    
    console::write_line(rev("a string"));
  }
};

startup_(program);
```

The following example demonstrates the use of delegates with static method.


```cpp
#include <xtd/xtd>

using namespace xtd;

class program {
public:
  using reverse = delegate<ustring(const ustring& s)>;
  
  static ustring reverse_string(const ustring& s) {
    ustring result = s;
    std::reverse(result.begin(), result.end());
    return result;
  }
  
  static auto main(const std::vector<ustring>& args) {
    reverse rev(reverse_string);
    
    console::write_line(rev("a string"));
  }
};

startup_(program);
```

* The ```using reverse = delegate<ustring(const ustring& s)>;``` line creates a delegate type of a certain signature, in this case a method that takes a string parameter and then returns a string parameter.
* The ```static ustring reverse_string(const ustring& s)``` method, which has the exact same signature as the defined delegate type, implements the delegate.
* The ```reverse rev(reverse_string);``` line shows that you can assign a method to a variable of the corresponding delegate type.
* The ```console::write_line(rev("a string"));``` line demonstrates how to use a variable of a delegate type to invoke the delegate.

In order to streamline the development process, xtd includes a set of delegate types that programmers can reuse and not have to create new types. 
These types are ```xtd::func<>```, ```xtd::action<>``` and ```xtd::predicate<>```, and they can be used without having to define new delegate types. 
There are some differences between the three types that have to do with the way they were intended to be used:

* ```xtd::action<>``` is used when there is a need to perform an action using the arguments of the delegate. The method it encapsulates does not return a value.
* ```xtd::func<>``` is used usually when you have a transformation on hand, that is, you need to transform the arguments of the delegate into a different result. Projections are a good example. The method it encapsulates returns a specified value.
* ```xtd::predicate<>``` is used when you need to determine if the argument satisfies the condition of the delegate. It can also be written as a ```xtd::func<bool, type_t>```, which means the method returns a boolean value.

We can now take our example above and rewrite it using the ```xtd::func<>``` delegate instead of a custom type.
The program will continue running exactly the same.

```cpp
#include <xtd/xtd>

using namespace xtd;

class program {
public:
  static ustring reverse_string(const ustring& s) {
    ustring result = s;
    std::reverse(result.begin(), result.end());
    return result;
  }
  
  static auto main(const std::vector<ustring>& args) {
    func<ustring, const ustring&> rev(reverse_string);
    
    console::write_line(rev("a string"));
  }
};

startup_(program);
```

For this simple example, having a method defined outside of the ```main``` method seems a bit superfluous. c++11 introduced the concept of [lambda expressions](https://en.cppreference.com/w/cpp/language/lambda), which let you create "inline" methods without having to specify any additional type or method.

We can now take our example above and rewrite it using a lambda expression.
The program will continue running exactly the same.

```cpp
#include <xtd/xtd>

using namespace xtd;

class program {
public:
  static auto main(const std::vector<ustring>& args) {
    func<ustring, const ustring&> rev([](auto s) {
      ustring result = s;
      std::reverse(result.begin(), result.end());
      return result;
    });
    
    console::write_line(rev("a string"));
  }
};

startup_(program);
```

As you can see, the delegate body is just a set of expressions, like any other delegate. 
But instead of making it a separate definition, we introduced it ad hoc in the creation of ```func<ustring, const ustring&> rev```.

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
