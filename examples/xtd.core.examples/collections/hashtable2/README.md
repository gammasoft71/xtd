# hashtable2

Shows how to use [hashtable](https://gammasoft71.github.io/xtd/reference_guides/latest/group__collections.html#gaf18249e78122f5f0f0f09003cf6abc5c) alias.

## Sources

* [src/hashtable2.cpp](src/hashtable2.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
double    -> 0.42
0.42      -> "double"
12:24:42  -> "time_span"
int       -> 0x002A
string    -> "42"
42        -> "string"
42        -> "int"
time_span -> 42 seconds

Update time_span to 20_h + 10_m + 5_s
[time_span] = 20:10:05
add day_of_week enum with day_of_week::saturday value
[day_of_week] = saturday
```
