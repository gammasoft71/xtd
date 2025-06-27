# delegate_begin_invoke2

Shows how to use [xtd::delegate::begin_invoke](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1delegate_3_01result__t_07arguments__t_8_8_8_08_4.html#a6fc96ea5d31c803e8e057eadd50d1a51), [xtd::delegate::end_invoke](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1delegate_3_01result__t_07arguments__t_8_8_8_08_4.html#aa5fa52aef651d08fef6ac3fad70dcd9d) and [xtd::delegate::invoke](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1delegate_3_01result__t_07arguments__t_8_8_8_08_4.html#a39bfec9ec7906ba41149be12fe24f36e) methods.

## Sources

[src/delegate_begin_invoke2.cpp](src/delegate_begin_invoke2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
(main) thread id = 1
(invoker) thread id = 1, value = 42
(invoker) thread id = 2, value = 24
```
