---
sidebar_class_name: hidden
sidebar_position: 999
---

# Threads synchronisation

How to simple synchronize some threads.

## Modern C++ code

```cpp
#include <array>
#include <mutex>
#include <print>
#include <thread>

using namespace std;

auto main() ->int {
  auto unsafe_value = 0;
  auto safe_value = 0;

  auto threads = array<thread, 10> {};
  for (auto& t : threads)
    t = thread([&]() {
      static auto inc_mutex = mutex();
      for (auto index = 0; index < 1000; ++index) {
        ++unsafe_value;
        {
          auto lock = lock_guard<mutex>(inc_mutex);
          ++safe_value;
        }
        this_thread::yield();
      }
    });
  
  for (auto& t : threads)
    t.join();
  println("unsafe_value = {}", unsafe_value);
  println("safe_value = {}", safe_value);
}
```

## xtd code

The following code lock on safe_value value reference : 

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto unsafe_value = 0;
  auto safe_value = 0;

  auto threads = fixed_array<thread, 10> {};
  for (auto& t : threads)
    t = thread::start_new([&]() {
      for (auto index = 0; index < 1000; ++index) {
        ++unsafe_value;
        lock_(safe_value)
          ++safe_value;
        thread::yield();
      }
    });

  for (auto& t : threads)
    t.join();
  println("unsafe_value = {}", unsafe_value);
  println("safe_value = {}", safe_value);
}
```

The following code lock on "increment lock" value reference : 

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto unsafe_value = 0;
  auto safe_value = 0;

  auto threads = fixed_array<thread, 10> {};
  for (auto& t : threads)
    t = thread::start_new([&]() {
      for (auto index = 0; index < 1000; ++index) {
        ++unsafe_value;
        lock_("increment lock")
          ++safe_value;
        thread::yield();
      }
    });

  for (auto& t : threads)
    t.join();
  println("unsafe_value = {}", unsafe_value);
  println("safe_value = {}", safe_value);
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
* See [main function and startup_ keyword](docs/documentation/Guides/xtd.core/Entry%20point/main_and_startup) to go further.

## See also

* [Tips & Triks](/docs/documentation/tips_and_tricks)
* [Documentation](/docs/documentation)
