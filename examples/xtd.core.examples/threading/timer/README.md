# timer

Shows how to use [xtd::threading::timer](https:gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1timer.html) class.

## Sources

[src/timer.cpp](src/timer.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
10:37:37.167 Creating timer.

10:37:38.172 Checking status  1.
10:37:38.426 Checking status  2.
10:37:38.679 Checking status  3.
10:37:38.932 Checking status  4.
10:37:39.185 Checking status  5.
10:37:39.439 Checking status  6.
10:37:39.691 Checking status  7.
10:37:39.946 Checking status  8.
10:37:40.200 Checking status  9.
10:37:40.455 Checking status 10.

Changing period to .5 seconds.

10:37:40.719 Checking status  1.
10:37:41.220 Checking status  2.
10:37:41.725 Checking status  3.
10:37:42.229 Checking status  4.
10:37:42.733 Checking status  5.
10:37:43.235 Checking status  6.
10:37:43.740 Checking status  7.
10:37:44.245 Checking status  8.
10:37:44.746 Checking status  9.
10:37:45.249 Checking status 10.

Destroying timer.
```
