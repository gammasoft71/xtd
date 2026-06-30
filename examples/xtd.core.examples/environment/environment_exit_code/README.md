# environment_exit_code

Shows how to use [xtd::environment::exit_code](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html#a592bc11cb5dce688a9e40aa6f866d496) method.

## Sources

* [src/environment_exit_code.cpp](src/environment_exit_code.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
>environment_exit_code
>Program ended with exit code: 89

>environment_exit_code xtd
>Program ended with exit code: 22

>environment_exit_code 2147483648
>Program ended with exit code: 34

>environment_exit_code 2142
Result: 4284
>Program ended with exit code: 0
```
