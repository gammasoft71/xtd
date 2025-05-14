# Capitalisation Conventions 

The guidelines in this chapter lay out a simple method for using case that, when applied consistently, make identifiers for types, members, and parameters easy to read.
 
## Capitalisation Rules for Identifiers
​
​As required by the ISO standard, use only lower case letters and numbers, separating words with underscores. Do not use capital letters to differentiate words, nor anywhere in identifiers. There is only one appropriate way to name identifiers:

[snake_casing](https://en.wikipedia.org/wiki/Snake_case)

```cpp
​​property_descriptor
html_tag
```

**✔️ DO** To differentiate members form accessors or methods, end members by _.


```cpp
namespace xtd {
  class my_class {
  public:
    int value() const {return value_;}
  
  private:
    int value_ = 42;
  };
}
```

A special case is made for two-letter acronyms in which both letters are not separed, as shown in the following identifier:

```cpp
io_stream
```

* **Naming** :

```cpp
namespace xtd {
  class thread {
    ...
  };
}
```

* **Type** :

```cpp
namespace xtd {
  class thread {
    ...
  };
}
```

* **Interface** :

```cpp
class ienumerable interface_ {
  ...
};
```

* **Method** :

```cpp
class control {
public:
  virtual std::string to_string() const;
};
```

* **Event** :

```cpp
class list_control : control {
public:
  event<list_control, event_handler> selected_index_changed;
};
```

* **Field** :

```cpp
struct unsigned_integer {
  static constexpr unsigned int min = 0;
};
```

* **Enum Value** :

```cpp
enum class values {
  append,
  ...
};
```

* **Parameters** :

```cpp
class convert {
public:
  static int to_int32(const std::string& value);
};
```

* **Members** : end by _

```cpp
struct unsigned_integer {
  ...
private:
  unsignecd int value_;
};
 
struct date_time {
  ...
private:
  long long value_;
  date_time_kind kind_;
  ...
};
```

## Compound Words and Common Terms
​
Most compound terms are treated as single words .
 
**❌ DO NOT** separate each word in so-called closed-form compound words.
​
These are compound words written as a single word, such as endpoint. For the purpose of casing guidelines, treat a closed-form compound word as a single word. Use a current dictionary to determine if a compound word is written in closed form. ​​

| separate_word | Not          |
| ------------- | ------------ |
| bit_flag      | bitflag      |
| callback      | call_back    |
| canceled      | cancelled    |
| do_not        | don't        |
| email         | e-mail       |
| endpoint      | end-point    |
| file_name     | filename     |
| gridline      | grid_line    |
| hashtable     | hash_table   |
| id            | ID           |
| indexes       | indices      |
| log_off       | log_out      |
| Log_on        | log_in       |
| metadata      | meta_data    |
| multipanel    | multi_panel  |
| multiview     | multi_view   |
| namespace     | name_space   |
| ok            | OK           |
| pi            | PI           |
| placeholder   | place_holder |
| sing_in       | sign_on      |
| sign_out      | sign_off     |
| user_name     | username     |
| white_space   | whitespace   |
| writable      | writeable    |

## Case Sensitivity
​
C++ are case-sensitivity.
 
## See also
​
* [Naming Guidelines](/docs/documentation/Design%20Guidelines/Naming%20Guidelines)
* [Design Guidelines](/docs/documentation/Design%20Guidelines)
* [Documentation](/docs/documentation)
