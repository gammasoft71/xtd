# Interfaces

## Overview

AnAn interface defines a contract. A class or structure that implements an interface must respect its contract. An interface can inherit from several basic interfaces, and a class or structure can implement several interfaces.
Interfaces must contain pure virtual methods (or properties). The interface itself does not provide an implementation for the members it declares. The interface simply specifies the members that must be provided by the classes or structures that implement the interface.

## Interface declarations

The following example shows how to declare an interface using the [interface_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#ga64c32b24bd922fc8189a487213592ccf) keyword.

```cpp
class icontrol interface_ {
public:
  virtual point location() const = 0;
  virtual icontrol& location(const& value) = 0;

  virtual void paint) = 0;
};
```

The following example shows how to declare an interface using the [interface](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1interface.html) class.

```cpp
class icontrol : public interface {
public:
  virtual point location() const = 0;
  virtual icontrol& location(const& value) = 0;

  virtual void paint) = 0;
};
```

## Interface implementations

Interfaces may be implemented by classes and structs. To indicate that a class or struct directly implements an interface, the interface is included in the base class list of the class or struct.

```cpp
class icloneable interface_ {
public:
  virtual std::shared_ptr<object> clone() = 0;
};

class icomparable interface_ {
public:
  virtual int compare_to(const object& other);
};

class list_entry : public icloneable, public icomparable {
public:
  std::shared_ptr<object> clone() override {...}    
  int compare_to(const object& other) override {...}
};
```

A class or struct that directly implements an interface also implicitly implements all of the interface’s base interfaces. This is true even if the class or struct doesn’t explicitly list all base interfaces in the base class list.

```cpp
class icontrol interface_ {
public:
  virtual void paint) = 0;
};

class itext_box : public icontrol {
public:
  virtual void set_text(const ustring& text) = 0;
};

class text_box : public itextBox {
public: 
  void Paint() override {...}
  void SetText(string text) override {...}
};
```

Here, class text_box implements both icontrol and itext_box.

For multiple-inheritance interfaces, ambiguities can occur when two or more unrelated base interfaces declare members with the same name or signature. Explicit casts can be used to resolve the ambiguities.

```cpp
struct ilist interface_ {
  virtual size_t count() const = 0;
  virtual void count(size_t) = 0;
};

struct icounter interface_ {
  virtual size_t count() const = 0;
  virtual void count(size_t) = 0;
};

struct ilist_counter : public ilist, public icounter {
  
};

struct s : public ilist_counter {
  void test(ilist_counter& x) {
    x.count();    // Error
    x.count(1);   // Error
    x.ilist::count(); // Ok, invokes ilist::count method
    x.icounter::count(1); // Ok, invokes ilist::count method
  }
};

```

The first two instructions cause compile-time errors because the search for the `count` member in `ilist_counter` is ambiguous. As the example illustrates, the ambiguity is resolved by casting `x` into the appropriate basic interface type. Such castings have no runtime cost - they simply involve considering the instance as a less derived type at compile time.

## iequatable

The [xtd::iequatable<type_t>](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1iequatable.html) interface class implement the [==](https://en.cppreference.com/w/cpp/language/operator_precedence) and [!=](https://en.cppreference.com/w/cpp/language/operator_precedence) operators and used the `virtual bool equals(const type_t&) const noexcept;` method.
You must just overload this method for used your own implementation.

The `point` class show how to used `equals` method :

```cpp
class point : public xtd::object, public xtd::iequatable<point> {
  //...
  
public:
  bool equals(const point& value) const noexcept override {
    return x_ == value.x_ && y_ == value.y_;
  }
  ​
  //...
  
private:
  int x_ = 0;
  int y_ = 0;
};

//...

static ustring form1::check_points(const point& p1, const point& p2) {
  if (p1 == p2) eturn "Equals";
  return "Not equals";
}
```

## icomparable

The [xtd::icomparable<type_t>](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1icomparable.html) interface implement the [<](https://en.cppreference.com/w/cpp/language/operator_precedence), [<=](https://en.cppreference.com/w/cpp/language/operator_precedence), [>](https://en.cppreference.com/w/cpp/language/operator_precedence) and [>=](https://en.cppreference.com/w/cpp/language/operator_precedence) operators. and used the `virtual int compare_to(const type_t&) const noexcept;` method.
You must just overload this method for used your own implementation.

The `time_span` class show how to used `compare_to` method:

```cpp
class time_span : public xtd::object, public xtd::icomparable<time_span> {
  //...
  
public:
  int compare_to(const time_span& value) const noexcept override {
    return value_ < value.value_ ? -1 : value_ > value.value_ ? 1 : 0;
  }
  ​
  //...
  
private:
  int64 value_ = 0;
};

//...

time_span test::get_max_duration(const std::vector<time_span>& durations) const noexcept {
  time_span result;
  for (const auto& duration : durations)
    if (duration > result) result = duration;
  return result;
}
```

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
