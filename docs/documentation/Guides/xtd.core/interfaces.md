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

Here, class TextBox implements both IControl and ITextBox.

## iequatable

Coming soon...

## icomparable

Coming soon...

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
