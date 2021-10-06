| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Exceptions and Performance

One common concern related to exceptions is that if exceptions are used for code that routinely fails, the performance of the implementation will be unacceptable. This is a valid concern. When a member throws an exception, its performance can be orders of magnitude slower. However, it is possible to achieve good performance while strictly adhering to the exception guidelines that disallow using error codes. Two patterns described in this section suggest ways to do this.

**❌ DO NOT** use error codes because of concerns that exceptions might affect performance negatively.

To improve performance, it is possible to use either the *Tester-Doer* Pattern or the *Try-Parse* Pattern, described in the next two sections.

# Tester-Doer Pattern

Sometimes performance of an exception-throwing member can be improved by breaking the member into two. Let’s look at the at method of the std::vector<type_t> interface.

```c++
std::vector<int> numbers = ...
auto val = numbers.at(9);
```

The method at throws if the collection is size < 10. This can be a performance problem in scenarios where the method call is expected to fail often. One of the ways to mitigate the problem is to test whether the vector size is >= 10 before trying to get a value.

```c++
std::vector<int> numbers = ...
...
if (numbers.size() >= 10) {
  auto val = numbers.at(9);
}
```

The member used to test a condition, which in our example is the property size, is referred to as the tester. The member used to perform a potentially throwing operation, the at method in our example, is referred to as the doer.

**✔️ CONSIDER** the Tester-Doer Pattern for members that might throw exceptions in common scenarios to avoid performance problems related to exceptions.

# Try-parse Pattern

For extremely performance-sensitive APIs, an even faster pattern than the *Tester-Doer* Pattern described in the previous section should be used. The pattern calls for adjusting the member name to make a well-defined test case a part of the member semantics. For example, xtd::date_time defines a parse method that throws an exception if parsing of a string fails. It also defines a corresponding try_parse method that attempts to parse, but returns false if parsing is unsuccessful and returns the result of a successful parsing using an ref parameter.

```c++
struct date_time : public object {
  public:
  static date_time parse(const string& date_time) {
    ...
  }
  
  static bool try_parse(const string& dateTime, date_time& result) {
    ...
  }
};
```

When using this pattern, it is important to define the try functionality in strict terms. If the member fails for any reason other than the well-defined try, the member must still throw a corresponding exception.

**✔️ CONSIDER** the *Try-Parse* Pattern for members that might throw exceptions in common scenarios to avoid performance problems related to exceptions.

**✔️ DO** use the prefix "try_" and boolean return type for methods implementing this pattern.

**✔️ DO** provide an exception-throwing member for each member using the *Try-Parse* Pattern.

# See also
​
* [Design Guidelines for Exception](design_guidelines_for_exception.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
