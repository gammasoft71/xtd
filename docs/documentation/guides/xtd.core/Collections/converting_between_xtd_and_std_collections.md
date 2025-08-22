# Converting between xtd and std collections

## In this article

* [Collections](#collections)
  * [Sequence collections](#sequence-collections)
  * [Associative collections](#associative-collections)
  * [Unordered associative collections](#unordered-associative-collections)
  * [Collections adaptors](#container-adaptors)
  * [Collections with events](#collections-with-events)
  * [Specialized collections](#specialized-collections)
  * [Thread-safe collections](#thread-safe-collections)
* [Choose a collection](#choose-a-collection)
* [Algorithmic complexity of collections](#algorithmic-complexity-of-collections)


In many cases, you may want to exchange data between xtd::collections::generic containers and their standard C++ (std) equivalents.
While both libraries provide similar abstractions, their types are distinct and sometimes require explicit conversion.

This guide presents the different ways to convert collections in both directions.

## Example

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto l = list<string> {"one", "two", "three", "four", "five"};
  println("l  = {}", l);
  
  auto v = std::vector<std::string> {"one", "two", "three", "four", "five"};
  println("v  = {}", v);
  
  println();
  
  // xtd::collections::generic::list<xtd::string> -> std::vector<xtd::string>
  auto v1 = std::vector<string>(l); // direct construction
  println("v1 = {}", v1);
  
  // xtd::collections::generic::list<xtd::string> -> std::vector<std::string>
  auto v2 = std::vector<std::string>(l.cast<std::string>()); // explicit cast
  println("v2 = {}", v2);

  // xtd::collections::generic::list<xtd::string> -> std::vector<std::string>
  auto v3 = std::vector<std::string>(l.size());
  std::transform(l.begin(), l.end(), v3.begin(), [](const auto& s) {return s;}); // manual transform
  println("v3 = {}", v3);
    
  // Move xtd::collections::generic::list<xtd::string> -> std::vector<xtd::string>
  auto v4 = std::vector<string>(std::move(l.items())); // using underlying collection
  println("v4 = {}", v4);

  println();
  
  // std::vector<std::string> -> xtd::collections::generic::list<std::string>
  auto l1 = list<std::string>(v); // direct construction
  println("l1 = {}", l1);
  
  // std::vector<std::string> -> xtd::collections::generic::list<xtd::string>
  auto l2 = list<string>(from(v).cast<string>()); // explicit cast using xtd::linq extension
  println("l2 = {}", l2);
  
  // std::vector<std::string> -> xtd::collections::generic::list<xtd::string>
  auto l3 = list<string>(v.size());
  std::transform(v.begin(), v.end(), l3.begin(), [](const auto& s) {return s;}); // manual transform
  println("l3 = {}", l3);
  
  // Move std::vector<std::string> -> xtd::collections::generic::list<std::string>
  auto l4 = list<std::string>(std::move(v));
  println("l4 = {}", l4);
    
  println();

  println("l  = {}", l);
  println("v  = {}", v);
}
```

**Output:**

```
l  = [one, two, three, four, five]
v  = [one, two, three, four, five]

v1 = [one, two, three, four, five]
v2 = [one, two, three, four, five]
v3 = [one, two, three, four, five]
v4 = [one, two, three, four, five]

l1 = [one, two, three, four, five]
l2 = [one, two, three, four, five]
l3 = [one, two, three, four, five]
l4 = [one, two, three, four, five]

l  = []
v  = []
```

## Conversion strategies

### 1.	Direct construction

If the element type is compatible (xtd::string to xtd::string, or std::string to std::string), you can directly construct a std::vector from a xtd::list (or the other way around).

```cpp
auto v = std::vector<string>(l);
auto l = list<std::string>(v);
```

# See also
​
* [Guides](/docs/documentation/guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/collections/)
