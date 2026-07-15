# Benchmark xtd vs stdexec

# xtd

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto cpt = 0;
  auto chrono = diagnostics::stopwatch::start_new();
  parallel::invoke(array<action<>> {100'000, [&] {interlocked::increment(cpt);}});
  println("cpt = {}, duration = {} ms", cpt, chrono.elapsed().milliseconds());
}

// This code produces the following output :
//
// cpt = 100000, duration = 101 ms
// cpt = 100000, duration = 37 ms
// cpt = 100000, duration = 67 ms
// cpt = 100000, duration = 87 ms
// cpt = 100000, duration = 22 ms
// cpt = 100000, duration = 109 ms
```

# execstd

```cpp
#include <stdexec/execution.hpp>
#include <exec/static_thread_pool.hpp>
#include <exec/async_scope.hpp>
#include <atomic>
#include <chrono>
#include <print>
#include <vector>

auto main() -> int {
  auto cpt = std::atomic<std::int32_t> {0};
  auto chrono = std::chrono::high_resolution_clock::now();
  exec::static_thread_pool pool(200);
  exec::async_scope scope;
  for (std::size_t i = 0; i < 100'000; ++i)
    scope.spawn(stdexec::schedule(pool.get_scheduler()) | stdexec::then([&] {++cpt;}));
  stdexec::sync_wait(scope.on_empty());
  std::println("cpt = {}, duration = {} ms", std::int32_t(cpt), std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - chrono).count());
}

// This code produces the following output :
//
// cpt = 100000, duration = 89 ms
// cpt = 100000, duration = 128 ms
// cpt = 100000, duration = 93 ms
// cpt = 100000, duration = 114 ms
// cpt = 100000, duration = 85 ms
// cpt = 100000, duration = 276 ms
```
