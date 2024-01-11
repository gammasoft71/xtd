# environment_cancel_signal

Shows how to use [xtd::environment::cancel_signal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html#a5eecf5ff0c77fe58bf24407004e0956a) event.

## Sources

[src/environment_cancel_signal.cpp](src/environment_cancel_signal.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Select a key :
  a : Generate abort signal
  c : (or ctrl-c) Generate interrupt signal
  e : (or Escape) Exit example
  f : Generate floating point exception signal
  h : Display this help
  i : Generate illegal instruction signal
  t : Generate software termination signal
  u : Update cancel signal status
  v : Generate segmentation violation signal
The signal will be cancelled!
```
