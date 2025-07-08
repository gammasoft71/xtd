---
sidebar_position: 1
---

# Command line arguments

Here is a new example illustrating a practical trick with xtd: how to retrieve command line settings in a simple and elegant way.

## Modern C++ code

```cpp
#include <print>
#include <vector>

auto main(int argc, const char * argv[]) -> int {
  for (auto arg : std::vector(argv, argv + argc))
    std::println("{}", arg);
}
```

## Code with xtd

```cpp
#include <xtd/xtd>

auto main() -> int {
  for (auto arg : environment::get_command_line_args())
    println(arg);
}
```

## Use

If we launch the application with the following arguments:

```sh
./my_app one two "three four" five
```

The result will be:

```
/!---OMITTED---!/my_app
one
two
three four
five
```

## Remarks

* xtd allows you to retrieve the arguments passed to the application without the need to go through `int argc, const char* argv[]`. 
  This greatly simplifies the structure of the hand.
* The first argument returned is always the way to the executable.

## See also

* [Triks & Tips](/docs/documentation/tricks_and_tips)
* [Documentation](/docs/documentation)
