# mixing_std_and_xtd_threads

Shows how to use and mixing [xtd::threading::thread](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread.html) and [std::thread](https://en.cppreference.com/w/cpp/thread/thread) classes.

## Sources

[src/mixing_std_and_xtd_threads.cpp](src/mixing_std_and_xtd_threads.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
threads {
  thread={name=main, managed_thread_id=1, priority=normal, thread_id=0x20245e080, state=running}
  thread={name=xtd_thread_3, managed_thread_id=3, priority=normal, thread_id=0x16ff9f000, state=background}
  thread={name=std_thread_2, managed_thread_id=0, priority=highest, thread_id=0x16ff13000, state=background}
  thread={name=std_thread_4, managed_thread_id=0, priority=highest, thread_id=0x16ff13000, state=background}
  thread={name=xtd_thread_1, managed_thread_id=2, priority=below_normal, thread_id=0x16fe87000, state=running}
}
```
