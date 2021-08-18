| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

The guidelines in this chapter lay out a simple method for using case that, when applied consistently, make identifiers for types, members, and parameters easy to read.
 
# Capitalisation Rules for Identifiers
​
​As ​ISO Standard, use lower case only and digits, separate words with underscores. Do not use capitilise to differentiate words, or for that matter, anywhere in identifiers

```c++
​​property_descriptor
html_tag
```

**√ DO** To differenciate members form accessors or metods, end members by _.


```c++
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

```c++
io_stream
```

* **Naming** :

```c++
namespace xtd {
  class thread {
    ...
  };
}
```

* **Type** :

```c++
namespace system {
  class thread {
    ...
  };
}
```

* **Interface** :

```c++
class ienumerable {
  ...
};
```

* **Method** :

```c++
class control {
public:
  virtual std::string to_string() const;
};
```

* **Event** :

```c++
class list_control : control {
public:
  event<list_control, event_handler<control&>> selected_index_changed;
};
```

* **Field** :

```c++
struct unsigned_integer {
  static constexpr unsigned int min = 0;
};
```

* **Enum Value** :

```c++
enum class values {
  append,
  ...
};
```

* **Parameters** :

```c++
class convert {
public:
  static int to_int32(const std::string& value);
};
```

* **Members** : end by _

```c++
struct unsigned_integer {
  ...
private:
  uint32_t value_;
};
 
struct date_time {
  ...
private:
  int64_t value_;
  date_time_kind kind_;
  ...
};
```

# Compound Words and Common Terms
​
Most compound terms are treated as single words .
 
**X DO NOT** separate each word in so-called closed-form compound words.
​
These are compound words written as a single word, such as endpoint. For the purpose of casing guidelines, treat a closed-form compound word as a single word. Use a current dictionary to determine if a compound word is written in closed form. ​​

| separate_word | Not          |
|---------------|--------------|
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

# Case Sensitivity
​
C++ are case-sensitivity.
 
# See also
​
* [Naming Guidelines](naming_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
