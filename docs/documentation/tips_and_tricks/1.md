# Command line arguments (🟢 Beginner)

Here is a new example illustrating a practical trick with xtd: how to retrieve command line arguments in a simple and elegant way.

## Modern C++ code

```cpp
#include <print>
#include <vector>

auto main(int argc, const char * argv[]) -> int {
  for (auto arg : std::vector(argv, argv + argc))
    std::println("{}", arg);
}
```

## xtd code

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
* The first argument returned is always the executable file with path.
* See [main function and startup_ keyword](/docs/documentation/guides/xtd.core/entry_point/main_and_startup) to go further.

## See also

* [Tips & Tricks](/docs/documentation/tips_and_tricks)
* [Documentation](/docs/documentation)
