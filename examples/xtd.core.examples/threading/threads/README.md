# threads

Demonstrates how to use [xtd::threading::thread](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread.html) class.

## Sources

* [src/threads.cpp](src/threads.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
main_thread.handle = 8555549440
main_thread.managed_thread_id = 1
main_thread.name = main_thread
main_thread.priority = normal
main_thread.thread_state = running
main_thread.thread_id = 8555549440

xtd_thread.handle = 6173618176
xtd_thread.managed_thread_id = 2
xtd_thread.name = xtd_thread
xtd_thread.priority = highest
xtd_thread.thread_state = running
xtd_thread.thread_id = 6173618176

xtd_jthread.handle = 6173618176
xtd_jthread.managed_thread_id = 3
xtd_jthread.name = xtd_jthread
xtd_jthread.priority = highest
xtd_jthread.thread_state = running
xtd_jthread.thread_id = 6173618176

background_thread.handle = 6173618176
background_thread.managed_thread_id = 4
background_thread.name = background_thread
background_thread.priority = normal
background_thread.thread_state = background
background_thread.thread_id = 6173618176

std_thread.handle = 6174191616
std_thread.managed_thread_id = 0
std_thread.name = std_thread
std_thread.priority = below_normal
std_thread.thread_state = background
std_thread.thread_id = 6174191616

std_jthread.handle = 6174732288
std_jthread.managed_thread_id = 0
std_jthread.name = std_jthread
std_jthread.priority = below_normal
std_jthread.thread_state = background
std_jthread.thread_id = 6174732288

detached_thread.handle = 6174191616
detached_thread.managed_thread_id = 0
detached_thread.name = detached_thread
detached_thread.priority = normal
detached_thread.thread_state = background
detached_thread.thread_id = 6174191616

```
