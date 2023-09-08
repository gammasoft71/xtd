# lock_guard

Shows how to use [xtd::threading::lock_guard](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1lock__guard.html) class.

## Sources

[src/lock_guard.cpp](src/lock_guard.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Mean for task  4: 498.90 (N=10000)
Mean for task  2: 499.92 (N=10000)
Mean for task  7: 503.12 (N=10000)
Mean for task  5: 499.41 (N=10000)
Mean for task  3: 498.58 (N=10000)
Mean for task  8: 496.71 (N=10000)
Mean for task 10: 501.49 (N=10000)
Mean for task  6: 498.84 (N=10000)
Mean for task  9: 502.72 (N=10000)
Mean for task 11: 498.69 (N=10000)

Mean for all tasks: 499.84 (N=100000)
```
