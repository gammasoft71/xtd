# thread_pool

Shows how to use [xtd::threading::thread_pool](https:gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread_pool.html) class.

## Sources

[src/thread_pool.cpp](src/thread_pool.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
08:45:24.070 Creating timer.

08:45:25.076 Checking status  1.
08:45:25.333 Checking status  2.
08:45:25.591 Checking status  3.
08:45:25.847 Checking status  4.
08:45:26.101 Checking status  5.
08:45:26.365 Checking status  6.
08:45:26.611 Checking status  7.
08:45:26.864 Checking status  8.
08:45:27.118 Checking status  9.
08:45:27.375 Checking status 10.

Changing period to .5 seconds.

08:45:27.885 Checking status  1.
08:45:28.389 Checking status  2.
08:45:28.897 Checking status  3.
08:45:29.402 Checking status  4.
08:45:29.913 Checking status  5.
08:45:30.414 Checking status  6.
08:45:30.922 Checking status  7.
08:45:31.428 Checking status  8.
08:45:31.934 Checking status  9.
08:45:32.445 Checking status 10.

Destroying timer.
```
