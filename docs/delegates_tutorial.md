| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Delegates

## In This Section

* [Overview](#overview)
* [Difference betwwen xtd::delegate and std::function](#difference-betwwen-xtddelegate-and-stdfunction)
* [Delegates Overview](#delegates-overview)
* [Using Delegates](#using-delegates)
* [Delegates with Named methods](#delegates-with-named-methods)
* [Delegates with Lambda expression](#delegates-with-lambda-expressions)

## Overview

A [xtd::delegate](../src/xtd.core/include/xtd/delegate.h) is a type that represents references to methods with a particular parameter list and return type. When you instantiate a delegate, you can associate its instance with any method with a compatible signature and return type. You can invoke (or call) the method through the delegate instance.

Delegates are used to pass methods as arguments to other methods. Event handlers are nothing more than methods that are invoked through delegates. You create a custom method, and a class such as a windows control can call your method when a certain event occurs. The following example shows a delegate declaration:

```c++
using perform_calculation = xtd::delegate<int(int x, int y)>;
```

Any method from any accessible class or struct that matches the delegate type can be assigned to the delegate. The method can be either static or an instance method. This flexibility means you can programmatically change method calls, or plug new code into existing classes.

### Notes
* In the context of method overloading, the signature of a method does not include the return value. But in the context of delegates, the signature does include the return value. In other words, a method must have the same return type as the delegate.

This ability to refer to a method as a parameter makes delegates ideal for defining callback methods. You can write a method that compares two objects in your application. That method can be used in a delegate for a sort algorithm. Because the comparison code is separate from the library, the sort method can be more general.

## Difference betwwen xtd::delegate and std::function

Unlike std::functional xtd::delegate can be chained together; for example, multiple methods can be called on a single event.

A xtd::delegate is a collection of std::function.

## Delegates Overview

Delegates have the following properties:
* Delegates are similar to C++ function pointers, but delegates like std::function are fully object-oriented, and unlike C++ pointers to member functions, delegates encapsulate both an object instance and a method.
* Delegates allow methods to be passed as parameters.
* Delegates can be used to define callback methods.
* Unlike std::function, delegates can be chained together; for example, multiple methods can be called on a single event.
* Methods don't have to match the delegate type exactly. For more information, see [Using Variance in Delegates](delegates_covariance_tutorial.md).
* Lambda expressions are a more concise way of writing inline code blocks. Lambda expressions (in certain contexts) are compiled to delegate types. For more information about lambda expressions, see [Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda).

## Using Delegates

A [xtd::delegate](../src/xtd.core/include/xtd/delegate.h) is a type that safely encapsulates a method, similar to a function pointer in C and C++. Unlike C function pointers, delegates are object-oriented, type safe, and secure. The type of a delegate is defined by the name of the delegate. The following example declares a delegate named **del** that can encapsulate a method that takes a [xtd::ustring](../src/xtd.core/include/xtd/ustring.h) as an argument and returns void:

```c++
using del = xtd::delegate<void(const xtd::ustring& message)>;
```

A delegate object is normally constructed by providing the name of the method the delegate will wrap, or with a lambda expression. Once a delegate is instantiated, a method call made to the delegate will be passed by the delegate to that method. The parameters passed to the delegate by the caller are passed to the method, and the return value, if any, from the method is returned to the caller by the delegate. This is known as invoking the delegate. An instantiated delegate can be invoked as if it were the wrapped method itself. For example:

```c++
// Create a method for a delegate.
void delegate_method(const xtd::ustring& message) {
  console::write_line(message);
}
```

```c++
// Instantiate the delegate.
del handler = {delegate_method};

// Call the delegate.
handler("Hello World");
```

or

```c++
// Instantiate the delegate.
del handler = del(delegate_method);

// Call the delegate.
handler("Hello World");
```

Because the instantiated [xtd::delegate](../src/xtd.core/include/xtd/delegate.h) is an object, it can be passed as a parameter, or assigned to a property. This allows a method to accept a delegate as a parameter, and call the delegate at some later time. This is known as an asynchronous callback, and is a common method of notifying a caller when a long process has completed. When a delegate is used in this fashion, the code using the delegate does not need any knowledge of the implementation of the method being used. The functionality is similar to the encapsulation interfaces provide.

Another common use of callbacks is defining a custom comparison method and passing that delegate to a sort method. It allows the caller's code to become part of the sort algorithm. The following example method uses the **del** type as a parameter:

```c++
void method_with_callback(int param1, int param2, del callback) {
  callback("The number is: " +  to_string(param1 + param2));
}
```

You can then pass the delegate created above to that method:

```c++
method_with_callback(1, 2, handler);
```

and receive the following output to the console:

```
The number is: 3
```

Using the delegate as an abstraction, **method_with_callback** does not need to call the console directly—it does not have to be designed with a console in mind. What **method_with_callback** does is simply prepare a string and pass the string to another method. This is especially powerful since a delegated method can use any number of parameters.
When a [xtd::delegate](../src/xtd.core/include/xtd/delegate.h) is constructed to wrap an instance method, the delegate references both the instance and the method. A delegate has no knowledge of the instance type aside from the method it wraps, so a delegate can refer to any type of object as long as there is a method on that object that matches the delegate signature. When a delegate is constructed to wrap a static method, it only references the method. Consider the following declarations:

```c++
class method_class {
public:
    void method1(const xtd::ustring& message) { }
    void method2(const xtd::ustring& message) { }
}
```

Along with the static **delegate_method** shown previously, we now have three methods that can be wrapped by a **del** instance.

A delegate can call more than one method when invoked. This is referred to as multicasting. To add an extra method to the delegate's list of methods—the invocation list—simply requires adding two delegates using the addition or addition assignment operators ('+' or '+='). For example:

```c++
method_class obj;
del d1 = {obj, &method_class::method1};
del d2 = {obj, &method_class::method2};
del d3 = {delegate_method};

//Both types of assignment are valid.
del all_methods_delegate = d1 + d2;
all_methods_delegate += d3;
```

At this point **all_methods_delegate** contains three methods in its invocation list—**method1**, **method2**, and **delegate_method**.
The original three delegates, **d1**, **d2**, and **d3**, remain unchanged. When **all_methods_delegate** is invoked, all three methods are called in order. If the delegate uses reference parameters, the reference is passed sequentially to each of the three methods in turn, and any changes by one method are visible to the next method. When any of the methods throws an exception that is not caught within the method, that exception is passed to the caller of the delegate and no subsequent methods in the invocation list are called. If the delegate has a return value and/or out parameters, it returns the return value and parameters of the last method invoked. 
To remove a method from the invocation list, use the subtraction or subtraction assignment operators (- or -=). For example:

```c++
//remove Method1
all_methods_delegate -= d1;

// copy all_methods_delegate while removing d2
del one_method_delegate = all_methods_delegate - d2;
```

Because [xtd::delegate](../src/xtd.core/include/xtd/delegate.h) types is a class, the methods and properties defined by that class can be called on the delegate. 
For example, to find the number of methods in a delegate's invocation list, you may write:

```c++
size_t invocation_count = d1.size();
```

Multicast delegates are used extensively in event handling. [xtd::event](../src/xtd.core/include/xtd/event.h) source objects send event notifications to recipient objects that have registered to receive that event. To register for an event, the recipient creates a method designed to handle the event, then creates a delegate for that method and passes the delegate to the event source. The source calls the delegate when the event occurs. The delegate then calls the event handling method on the recipient, delivering the event data. The delegate type for a given event is defined by the event source. For more, see [events](events_tutorial.md).

Comparing delegates of two different types assigned at compile-time will result in a compilation error. If the delegate instances are statically of the type [xtd::delegate](../src/xtd.core/include/xtd/delegate.h), then the comparison is allowed, but will return false at run time. For example:

```c++
template<typename result_t, typename... arguments_t>
void method(delegate1 d, delegate2 e, xtd::delegate<result_t(arguments_t...)> f) {
  // Compile-time error.
  //console::write_line(d == e);
  
  // OK at compile-time. False if the run-time type of f
  // is not the same as that of d.
  console::write_line(d == f);
}
```

## Delegates with Named methods

A [xtd::delegate](../src/xtd.core/include/xtd/delegate.h) can be associated with a named method. When you instantiate a delegate by using a named method, the method is passed as a parameter, for example:

```c++
// Declare a delegate.
using del = xtd::delegate<void(int x)>;

// Define a named method.
void doW_work(int k) { /* ... */ }

// Instantiate the delegate using the method as a parameter.
del d = {obj, &objectt_class::do_work};
```

This is called using a named method. Delegates constructed with a named method can encapsulate either a static method or an instance method. However, in a situation where creating a new method is unwanted overhead, C++ and xtd enable you to instantiate a delegate and immediately specify a code block that the delegate will process when it is called. The block can contain either a [lambda expression](#lambda-expression).

### Remarks

* The method that you pass as a delegate parameter must have the same signature as the delegate declaration.
* A delegate instance may encapsulate either static or instance method.
* Although the delegate can use an reference parameter (not const reference), we do not recommend its use with multicast event delegates because you cannot know which delegate will be called.

### Example 1

TThe following is a simple example of declaring and using a delegate. Notice that both the delegate, **del**, and the associated method, **multiply_numbers**, have the same signature

```c++
#include <xtd/xtd>

using namespace xtd;

// Declare a delegate
using del = delegate<void(int i, double j)>;

class math_class {
public:
  static void main() {
    math_class m;
    
    // Delegate instantiation using "MultiplyNumbers"
    del d = {m, &math_class::multiply_numbers};
    
    // Invoke the delegate object.
    console::write_line("Invoking the delegate using 'multiply_numbers':");
    for (int i = 1; i <= 5; i++) {
      d(i, 2);
    }
    console::write_line();
  }
  
  // Declare the associated method.
  void multiply_numbers(int m, double n) {
    console::write("{} ", m * n);
  }
};

startup_(math_class);

/* Output:
 Invoking the delegate using 'multiply_numbers':
 2 4 6 8 10
 */
```

### Example 2

In the following example, one delegate is mapped to both static and instance methods and returns specific information from each.

```c++
#include <xtd/xtd>

using namespace xtd;

using del = delegate<void()>;

class sample_class {
public:
  void instance_method() {
    console::write_line("A message from the instance method.");
  }
  
  static void static_method() {
    console::write_line("A message from the static method.");
  }
};

class test_sample_class {
public:
  static void main() {
    sample_class sc;
    
    // Map the delegate to the instance method:
    del d = {sc, &sample_class::instance_method};
    d();
    
    // Map to the static method:
    d = sample_class::static_method;
    d();
  }
};

startup_(test_sample_class);

/* Output:
 A message from the instance method.
 A message from the static method.
 */
```

## Delegates with Lambda expressions

The "\*[]()\*" operator creates a [lambda expression](https://en.cppreference.com/w/cpp/language/lambda) that can be converted to a [xtd::delegate](../src/xtd.core/include/xtd/delegate.h) type:

```c++
xtd::func<int, int, int> sum([] (int a, int b) { return a + b; });
xtd::console::write_line(sum(3, 4));  // output: 7
```

When you use the "\*[]()\*" operator, you might omit the parameter list. If you do that, the created anonymous method can be converted to a delegate type with any list of parameters, as the following example shows:

```c++
xtd::action<> greet([] { xtd::console::write_line("Hello!"); });
greet();

xtd::action<int, double> introduce([] { xtd::console::write_line("This is world!"); });
introduce(42, 2.7);

// Output:
// Hello!
// This is world!
```

This functionality of lambda expression is supported by [xtd::delegate](../src/xtd.core/include/xtd/delegate.h) but not by std::function.

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
