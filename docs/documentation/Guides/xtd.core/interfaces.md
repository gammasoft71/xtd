# Interfaces

## Overview

AnAn interface defines a contract. A class or structure that implements an interface must respect its contract. An interface can inherit from several basic interfaces, and a class or structure can implement several interfaces.
Interfaces must contain pure virtual methods (or properties). The interface itself does not provide an implementation for the members it declares. The interface simply specifies the members that must be provided by the classes or structures that implement the interface.

## Interface declarations

```cpp
class icontrol interface_ {
  public:
    point location() const = 0;
    icontrol& location(const& value) = 0;

    void paint) = 0;
};
```

```cpp
class icontrol : public interface {
  public:
    point location() const = 0;
    icontrol& location(const& value) = 0;

    void paint) = 0;
};
```


```cpp
class icontrol interface_ {
  public:
    void paint) = 0;
};

class itext_box : public icontrol {
  public:
    void set_text(const ustring& text) = 0;
};

class ilist_box : public icontrol {
  public:
    void set_items(const vectorw<ustring>& items) = 0;
};

class icombo_box : public itext_box, public ilst_box {
};

```



## iequatable

Coming soon...

## icomparable

Coming soon...

## iasync_result

Coming soon...

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
