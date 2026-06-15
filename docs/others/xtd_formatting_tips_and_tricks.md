# XTD Formatting Tips & Tricks

## Overview

This guide compares formatting capabilities across XTD, std::format, Qt,
wxWidgets, and fmtlib. It highlights XTD's unique simplicity and
flexibility for custom types.

## Summary Table

  Feature                     XTD          std::format   Qt             wxWidgets   fmtlib
  --------------------------- ------------ ------------- -------------- ----------- ----------
  {} formatting               ✔            ✔             ❌             ❌          ✔
  Custom type support         ✔ Easy       ✔ Hard        ✔ via QDebug   ❌          ✔ Medium
  Culture support             ✔ Complete   ❌ Limited    ❌             ❌          ❌
  Console/debug integration   ✔ Unified    ❌            ✔ QDebug       ✔ wxLog     ❌
  API coherence               ⭐⭐⭐⭐⭐   ⭐⭐          ⭐⭐⭐⭐       ⭐          ⭐⭐⭐⭐

## XTD Formatting Levels

### 1. Using `operator<<`

``` cpp
struct foo1 {
  string name;
  int number;
  friend std::ostream& operator<<(std::ostream& os, const foo1& v) {
    return os << string::format("{{name = {}, number = {}}}", v.name, v.number);
  }
};
```

### 2. Using `xtd::to_string` Specialization

``` cpp
template<>
string xtd::to_string(const foo2& v, const string&, const std::locale&) {
  return string::format("{{name = {}, number = {}}}", v.name, v.number);
}
```

### 3. Using `istringable`

``` cpp
struct foo3 : istringable {
  string name;
  int number;
  string to_string() const override {
    return string::format("{{name = {}, number = {}}}", name, number);
  }
};
```

### 4. Using `iformatable`

``` cpp
struct foo6 : iformatable {
  string name;
  int number;
  string to_string(const string& fmt, const culture_info&) const override {
    if (fmt == "n") return name;
    if (fmt == "d") return string::format("{}", number);
    return string::format("{{name = {}, number = {}}}", name, number);
  }
};
```

## Comparison Snippets

### Qt Example

``` cpp
#include <QDebug>

struct foo {
  QString name;
  int number;
};

QDebug operator<<(QDebug dbg, const foo& f) {
  dbg.nospace() << "{name=" << f.name << ", number=" << f.number << "}";
  return dbg.maybeSpace();
}

// Usage:
qDebug() << foo{"test", 42};
```

### wxWidgets Example

``` cpp
#include <wx/wx.h>

struct foo {
  wxString name;
  int number;
};

wxString to_wx_string(const foo& value) {
  return wxString::Format("{name=%s, number=%d}", value.name, value.number);
}

// Usage:
wxLogMessage("foo = %s", to_wx_string(foo{"wx", 12}));
```

## Conclusion

XTD delivers the most flexible, modern, and developer-friendly
formatting system available in C++. Multiple extension paths, cultural
formatting, and unified console/debug APIs make it uniquely powerful and
pleasant to use.
