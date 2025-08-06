# Very simple threads synchronisation (🟡 Intermediate)

Simplify synchronization with [lock_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gacd9906b29d877eb1eb0a8c7bc4ab774a) in xtd.

## Modern C++ code

```cpp
#include <array>
#include <mutex>
#include <print>
#include <thread>

auto main() ->int {
  auto unsafe_value = 0;
  auto safe_value = 0;

  auto threads = std::array<std::thread, 10> {};
  for (auto& t : threads)
    t = std::thread([&]() {
      static auto inc_mutex = std::mutex {};
      for (auto index = 0; index < 1000; ++index) {
        ++unsafe_value;
        {
          auto lock = std::lock_guard<std::mutex>(inc_mutex);
          ++safe_value;
        }
        std::this_thread::yield();
      }
    });
  
  for (auto& t : threads)
    t.join();
  
  std::println("unsafe_value = {}", unsafe_value);
  std::println("safe_value = {}", safe_value);
}
```

*	Requires an external std::mutex
*	Verbose and syntactically heavy with lock_guard
*	Limited flexibility (can only lock on std::mutex)

## xtd code

### The following code lock on safe_value value reference : 

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
        lock_(safe_value) {
          ++safe_value;
        }
        thread::yield();
      }
    });

  for (auto& t : threads)
    t.join();
    
  println("unsafe_value = {}", unsafe_value);
  println("safe_value = {}", safe_value);
}
```

*	No need for a std::mutex
*	We focus on what we want to protect, not how to do it
*	The code is closer to the developer's real intention

### The following code lock on "increment lock" value reference : 

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
        lock_("increment lock") {
          ++safe_value;
        }
        thread::yield();
      }
    });

  for (auto& t : threads)
    t.join();
    
  println("unsafe_value = {}", unsafe_value);
  println("safe_value = {}", safe_value);
}
```

*	Useful when you want a named critical area (for example shared between modules)
*	A very difficult case to reproduce properly with std::mutex, or even impossible without a complex global map
*	Immediately readable, which helps maintain and understand multi-threaded code
* In xtd, [xtd::fixed_array](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1fixed__array.html) replaces std::array to stay consistent with the framework style.


With [lock_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gacd9906b29d877eb1eb0a8c7bc4ab774a), you write what you want to do, not how the system should manage it. 
The lock becomes a hidden implementation detail.

## Conclusion

In a single line, [lock_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gacd9906b29d877eb1eb0a8c7bc4ab774a) encapsulates all the synchronization logic. 
No need to manage mutex, no need to clutter your code. 
And since it is based on [xtd::threading::monitor](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1monitor.html), it offers you a re-entrant, elegant, and easy-to-use synchronization.

```cpp
lock_("mylock") {
  // first level
  lock_("mylock") {
    // second level (re-entrant)
  }
}
```

Multi-threading has never been so readable in C++.

> **Pro tip**
> [lock_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__keywords.html#gacd9906b29d877eb1eb0a8c7bc4ab774a) works with any referenceable object or string. You can synchronize on this, global variables, or even temporary objects — just be sure they live long enough to avoid undefined behavior.

See [xtd::threading](https://gammasoft71.github.io/xtd/reference_guides/latest/group__threading.html) for more information on the different thread synchronization objects in xtd.

## See also

* [Tips & Triks](/docs/documentation/tips_and_tricks)
* [Documentation](/docs/documentation)
