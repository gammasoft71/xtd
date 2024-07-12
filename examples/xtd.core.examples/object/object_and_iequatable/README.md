# object_and_iequatable

Shows hows how to use [xtd::object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html) and [xtd::iequatable](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1iequatable.html).

## Sources

[src/object_and_iequatable.cpp](src/object_and_iequatable.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
user1 equals user2: true
user1 equals user3: false
user1 equals user2 (object): true
user1 equals user3 (object): false
user1 hash code: 9105846386475545849
user2 hash code: 9105846386475545849
user3 hash code: 4537660354082115200
user1 == user2: true
user1 != user3: true
user: id = 1, name = Example
user: id = 1, name = Example
user: id = 2, name = Different
```
