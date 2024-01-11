# file_info2

Show how to use [xtd::io::file_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__info.html) class.

## Sources

[src/file_info2.cpp](src/file_info2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
full_name = //var/folders/d5/k7mxnq214dxf3jbvvvhpbfqh0000gn/T/test_file.txt
  attributes = normal
  creation_time = Fri Oct 22 22:05:37 2021
  exists = true
  extension = .txt
  last_access_time = Fri Oct 22 22:05:37 2021
  last_write_time = Fri Oct 22 22:05:37 2021
  length = 13
  name = test_file.txt
  to_string = /var/folders/d5/k7mxnq214dxf3jbvvvhpbfqh0000gn/T/test_file.txt
```

